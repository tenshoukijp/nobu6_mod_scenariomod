#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <cassert>
#include "ゲームデータ構造.h"
#include <mmsystem.h>
#include <map>

extern HWND tenshouWND;
extern HMODULE hModuleTSMod;

// ユーザ追加型のDLL。「DLL名とDLLハンドル」のハッシュ。
extern map<string, HMODULE> mapHResistModuleHandle;


using PFNOPENIMAGEDIALOG			= int (WINAPI *)(char *szTargetName, int posX, int posY, int iTime);
PFNOPENIMAGEDIALOG p_OpenImageDialog = NULL;

using PFNSTARTIMAGEDIALOG			= int (WINAPI *)(char *szTargetName, int posX, int posY);
PFNSTARTIMAGEDIALOG p_StartImageDialog = NULL;

using PFNENDIMAGEDIALOG				= int (WINAPI *)();
PFNENDIMAGEDIALOG p_EndImageDialog = NULL;

using PFNOPENRESOURCEIMAGEDIALOG	= int (WINAPI *)(char *szTargetName, HMODULE hModule, int posX, int posY, int iTime);
PFNOPENRESOURCEIMAGEDIALOG p_OpenResourceImageDialog = NULL;

using PFNSTARTRESOURCEIMAGEDIALOG	= int (WINAPI *)(char *szTargetName, HMODULE hModule, int posX, int posY);
PFNSTARTRESOURCEIMAGEDIALOG p_StartResourceImageDialog = NULL;

using PFNENDRESOURCEIMAGEDIALOG		= int (WINAPI *)();
PFNENDRESOURCEIMAGEDIALOG p_EndResourceImageDialog = NULL;

using PFNFUNCNORMALFUKIDASHIMESSAGE = void (WINAPI *)(int iBushouID, char *szMessage);
PFNFUNCNORMALFUKIDASHIMESSAGE p_FuncLeftNormalFukidashiMessage = NULL;
PFNFUNCNORMALFUKIDASHIMESSAGE p_FuncRightNormalFukidashiMessage = NULL;
PFNFUNCNORMALFUKIDASHIMESSAGE p_FuncLeftNormalFukidashiUpdate = NULL;
PFNFUNCNORMALFUKIDASHIMESSAGE p_FuncRightNormalFukidashiUpdate = NULL;

using PFNFUNCNORMALFUKIDASHIDELETE  = void(WINAPI *)();
PFNFUNCNORMALFUKIDASHIDELETE p_FuncLeftNormalFukidashiDelete = NULL;
PFNFUNCNORMALFUKIDASHIDELETE p_FuncRightNormalFukidashiDelete = NULL;

using PFNFUNCSENJOFUKIDADIALOG		= void (WINAPI *)(int iBushouID, char *szMessage);
PFNFUNCSENJOFUKIDADIALOG p_FuncSenjoFukidashiDialog = NULL;

// TSModにしかない動画再生関数のポインタの登録
void _ダイアログ関数登録() {
	// 必要行動値を上書きする。
	p_OpenImageDialog = (PFNOPENIMAGEDIALOG)GetProcAddress( hModuleTSMod, "Extern_OpenImageDialog" );
	p_StartImageDialog = (PFNSTARTIMAGEDIALOG)GetProcAddress( hModuleTSMod, "Extern_StartImageDialog" );
	p_EndImageDialog = (PFNENDIMAGEDIALOG)GetProcAddress( hModuleTSMod, "Extern_EndImageDialog" );
	p_OpenResourceImageDialog = (PFNOPENRESOURCEIMAGEDIALOG)GetProcAddress( hModuleTSMod, "Extern_OpenResourceImageDialog" );
	p_StartResourceImageDialog = (PFNSTARTRESOURCEIMAGEDIALOG)GetProcAddress( hModuleTSMod, "Extern_StartResourceImageDialog" );
	p_EndResourceImageDialog = (PFNENDRESOURCEIMAGEDIALOG)GetProcAddress( hModuleTSMod, "Extern_EndResourceImageDialog" );
	p_FuncLeftNormalFukidashiMessage  = (PFNFUNCNORMALFUKIDASHIMESSAGE)GetProcAddress( hModuleTSMod, "Extern_FuncLeftNormalFukidashiMessage" );
	p_FuncRightNormalFukidashiMessage = (PFNFUNCNORMALFUKIDASHIMESSAGE)GetProcAddress( hModuleTSMod, "Extern_FuncRightNormalFukidashiMessage" );
	p_FuncLeftNormalFukidashiUpdate  = (PFNFUNCNORMALFUKIDASHIMESSAGE)GetProcAddress( hModuleTSMod, "Extern_FuncLeftNormalFukidashiUpdate" );
	p_FuncRightNormalFukidashiUpdate = (PFNFUNCNORMALFUKIDASHIMESSAGE)GetProcAddress( hModuleTSMod, "Extern_FuncRightNormalFukidashiUpdate" );
	p_FuncLeftNormalFukidashiDelete  = (PFNFUNCNORMALFUKIDASHIDELETE)GetProcAddress( hModuleTSMod, "Extern_FuncLeftNormalFukidashiDelete" );
	p_FuncRightNormalFukidashiDelete = (PFNFUNCNORMALFUKIDASHIDELETE)GetProcAddress( hModuleTSMod, "Extern_FuncRightNormalFukidashiDelete" );
	p_FuncSenjoFukidashiDialog = (PFNFUNCSENJOFUKIDADIALOG)GetProcAddress( hModuleTSMod, "Extern_FuncSenjoFukidashiDialog" );
}


BOOL _isDoingDialog = FALSE;

	char _szダイアログ文字列[255] = "";
	char * _pszダイアログ文字列 = _szダイアログ文字列;


/* // フレーム用のダイアログ
0043666B  |> 68 FFFF0000    PUSH    0FFFF
00436670  |. 6A 01          PUSH    1
00436672  |. 68 C0974D00    PUSH    TENSHOU.004D97C0                                  ;  ASCII "上泉信綱隊は
混乱状態から回復しました"
00436677  |. E8 23E30600    CALL    TENSHOU.004A499F
0043667C  |. 83C4 0C        ADD     ESP, 0C
*/


	//---------------------戦闘中などで良くでるフレームダイアログ-------------------------
	int pCallFromFuncInfoFrameDialog = 0x4A499F; // 元々TENSHOU.EXE内にあったCALL先

	void _FuncInfoFrameDialogAsm() {

		__asm {
			// 引数1～3 2バイトずつ
			push 0xffff;
			push 1;

			// 引数4 文字列へのポインタ(ポインタ=4バイト)
			push _pszダイアログ文字列;
			call pCallFromFuncInfoFrameDialog
			// スタックがずれ込んだ分(2*3+4 = 10)
			add  esp, 0xC
		}

	}

namespace 関数 {

	void 情報フレームダイアログ表示(string ダイアログ文字列) {

		_isDoingDialog = TRUE;
		strcpy_s( _szダイアログ文字列, ダイアログ文字列.c_str() );

		__asm {
			push eax
			push ebx
			push ecx
			push edx
			push esp
			push esi
			push edi
		}

		// TENSHOU.EXE内の関数呼び出し
		_FuncInfoFrameDialogAsm();

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}
		_isDoingDialog = FALSE;
	}
}


	//---------------------二者選択ダイアログ-------------------------
	int pCallFromFuncOKCancelDialogAsm = 0x4A18D0; // 元々tenshouWNDTENSHOU.EXE内にあったCALL先
	int _iResultOfFuncOKCancelDialog = 0;
	void _FuncOKCancelDialogAsm() {
		__asm {
			// 引数1～3 2バイトずつ
			// 引数4 文字列へのポインタ(ポインタ=4バイト)
			push _pszダイアログ文字列;
			call pCallFromFuncOKCancelDialogAsm
			// スタックがずれ込んだ分(2*3+4 = 10)
			add  esp, 4
			mov _iResultOfFuncOKCancelDialog, eax;
		}

	}

namespace 関数 {
	int 実行／取消ダイアログ表示(string ダイアログ文字列) {
		_isDoingDialog = TRUE;

		strcpy_s( _szダイアログ文字列, ダイアログ文字列.c_str() );

		__asm {
			push eax
			push ebx
			push ecx
			push edx
			push esp
			push esi
			push edi
		}

		// TENSHOU.EXE内の関数呼び出し
		_FuncOKCancelDialogAsm();

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}

		_isDoingDialog = FALSE;
		// 返答がYesだったかNoだったか返す。
		return _iResultOfFuncOKCancelDialog;
	}
}



	//---------------------普通に消えてしまうダイアログ-------------------------
	int _pCallFromFuncInfoDialogAsm = 0x4A1855; // 元々TENSHOU.EXE内にあったCALL先

	void _FuncInfoDialogAsm() {
		__asm {
			// 引数1～3 2バイトずつ
			push word ptr 0xffff;
			push word ptr 0xffff;
			push word ptr 0xffff;
			// 引数4 文字列へのポインタ(ポインタ=4バイト)
			push _pszダイアログ文字列;
			call _pCallFromFuncInfoDialogAsm
			// スタックがずれ込んだ分(2*3+4 = 10)
			add  esp, 10
		}

	}

namespace 関数 {
	void 情報ダイアログ表示(string ダイアログ文字列) {
		_isDoingDialog = TRUE;

		strcpy_s( _szダイアログ文字列, ダイアログ文字列.c_str() );

		__asm {
			push eax
			push ebx
			push ecx
			push edx
			push esp
			push esi
			push edi
		}

		// TENSHOU.EXE内の関数呼び出し
		_FuncInfoDialogAsm();

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}

		_isDoingDialog = FALSE;
	}
}
//---------------------確認押すまで消えないダイアログ-------------------------
	int _pCallFromFuncConfirmDialogAsm = 0x4A187A; // 元々TENSHOU.EXE内にあったCALL先

	void _FuncConfirmDialogAsm() {

		__asm {
			// 引数1～3 2バイトずつ
			push word ptr 0xffff;
			push word ptr 0xffff;
			push word ptr 0xffff;
			// 引数4 文字列へのポインタ(ポインタ=4バイト)
			push _pszダイアログ文字列;
			call _pCallFromFuncConfirmDialogAsm
			// スタックがずれ込んだ分(2*3+4 = 10)
			add  esp, 10
		}

	}

namespace 関数 {
	void 確認ダイアログ表示(string ダイアログ文字列) {
		_isDoingDialog = TRUE;

		strcpy_s( _szダイアログ文字列, ダイアログ文字列.c_str() );

		__asm {
			push eax
			push ebx
			push ecx
			push edx
			push esp
			push esi
			push edi
		}

		// TENSHOU.EXE内の関数呼び出し
		_FuncConfirmDialogAsm();

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}

		_isDoingDialog = FALSE;
	}
}

	//---------------------警告系消えてしまうダイアログ-------------------------
	int _pCallFromFuncAssertDialog = 0x4A1831; // 元々TENSHOU.EXE内にあったCALL先

	void _FuncAssertDialogAsm() {

		__asm {
			// 引数1～3 2バイトずつ
			push word ptr 0xffff;
			push word ptr 0xffff;
			push word ptr 0xffff;
			// 引数4 文字列へのポインタ(ポインタ=4バイト)
			push _pszダイアログ文字列;
			call _pCallFromFuncAssertDialog
			// スタックがずれ込んだ分(2*3+4 = 10)
			add  esp, 10
		}

	}

namespace 関数 {
	void 警告ダイアログ表示(string ダイアログ文字列) {
		_isDoingDialog = TRUE;

		strcpy_s( _szダイアログ文字列, ダイアログ文字列.c_str() );

		__asm {
			push eax
			push ebx
			push ecx
			push edx
			push esp
			push esi
			push edi
		}

		// TENSHOU.EXE内の関数呼び出し
		_FuncAssertDialogAsm();

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}

		_isDoingDialog = FALSE;
	}
}




/*
00419AF4  |. 33DB           XOR     EBX, EBX
00419AF6  |. BF FFFF0000    MOV     EDI, 0FFFF
00419AFB  |> 53             /PUSH    EBX                             ; /Arg7				← 0 固定
00419AFC  |. 6A 70          |PUSH    70                              ; |Arg6 = 00000070		？
00419AFE  |. 53             |PUSH    EBX                             ; |Arg5
00419AFF  |. 68 A0B64C00    |PUSH    TENSHOU.004CB6A0                ; |Arg4 = 004CB6A0		文字列ポインタの配列のアドレス
00419B04  |. 6A 03          |PUSH    3                               ; |Arg3 = 00000003		選択肢の数
00419B06     68 A0000000    PUSH    0A0														Ｙ座標
00419B0B     68 18020000    PUSH    118														Ｘ座標
00419B10  |. E8 6C920800    |CALL    TENSHOU.004A2D81                ; \TENSHOU.004A2D81
00419B15  |. 83C4 1C        |ADD     ESP, 1C


RETURNであるEAXは選択肢順に0, 1, 2,...
選択しなかった場合(右クリックなど) 0xFFFF がEAXに入る。
*/

// メニューの数の最大
#define SELECT_MENU_NUM_MAX  36

// １つのメニューの中の文字列の最大は全角３１文字。半角63
#define SELECT_MENU_STRING_LENGTH_MAX	64

char *pSelectMenuStringArrayPointer[SELECT_MENU_NUM_MAX] = {NULL}; // メニューは最大で３６個。こちらは格メニューも自列へのポインタ配列
// 家宝種類のカスタム文字列

// １つのセレクトメニュー型
struct SELECT_MENU {
	char szKahouTypeString[SELECT_MENU_STRING_LENGTH_MAX];
};
SELECT_MENU select_menu_string[SELECT_MENU_NUM_MAX] = {""}; // 各々の文字列メニュー


//---------------------多項目選択式ダイアログ-------------------------
int pCallFromFuncSelectMenuDialogAsm = 0x4A2D81; // 元々TENSHOU.EXE内にあったCALL先
int iResultOfFuncSelectMenuDialog = 0;	// 選択結果
int iXPosOfSelectMenuDialog = 0xA0;		// Ｘ座標 
int iYPosOfSelectMenuDialog = 0x118;	// Ｙ座標
int iMenuNumOfSelectMenuDialog = 3;		// メニューの個数
int iMenuMinWidthOfSelectMenuDialog = 0x70; // メニュの最低幅

int iSelectMenuStringArrayPointerOfSelectMenuDialog = 0x4CB6A0; // デフォルトは披露の配列

void _FuncSelectMenuDialogAsm() {
	__asm {
		push 0xF
		push iMenuMinWidthOfSelectMenuDialog // おそらくメニューの最低幅
		push 0
		push iSelectMenuStringArrayPointerOfSelectMenuDialog
		push iMenuNumOfSelectMenuDialog
		push iYPosOfSelectMenuDialog
		push iXPosOfSelectMenuDialog

		call pCallFromFuncSelectMenuDialogAsm

		mov iResultOfFuncSelectMenuDialog, eax;

		pop eax
		pop eax
		pop eax
		pop eax
		pop eax
		pop eax
		pop eax

		mov eax, iResultOfFuncSelectMenuDialog;
	}

}

bool isInitSelectMenuPointer = false; // 未初期化フラグ
void _InitSelectMenuPointer() {
	if ( !isInitSelectMenuPointer ) {
		// 最初に各々の文字列のポインタは指しておく
		for ( int i=0; i<SELECT_MENU_NUM_MAX; i++ ) {
			pSelectMenuStringArrayPointer[i] = select_menu_string[i].szKahouTypeString;
		}

		// ポインタの配列の先頭のアドレスをint型として控えておく。メニューダイアログにはこの値を渡す必要がある。
		iSelectMenuStringArrayPointerOfSelectMenuDialog = (int)pSelectMenuStringArrayPointer;

		isInitSelectMenuPointer = true;
	}
}



int _SelectMenuDialog(vector<string> menu_list, int posX, int posY) {

	// メニューの個数が最大数を超えていれば、
	if ( menu_list.size() > SELECT_MENU_NUM_MAX ) {
		return 0xFFFF; // 何もせず閉じたのと同じこととする。
	}
	// メニュー自体１つも存在しない。
	if ( menu_list.size() == 0 ) {
		return 0xFFFF; // 何もせず閉じたのと同じこととする。
	}

	_InitSelectMenuPointer();

	// メニューの個数を控えておく
	iMenuNumOfSelectMenuDialog = menu_list.size();
	// メニュー数が、最大数をオーバーしていたら、最大数に訂正
	if ( iMenuNumOfSelectMenuDialog > SELECT_MENU_NUM_MAX ) { iMenuNumOfSelectMenuDialog = SELECT_MENU_NUM_MAX; }

	// 一番長い文字を探す。
	int max_string_length = iMenuMinWidthOfSelectMenuDialog/8; // ダイアログの最低幅を半角文字の幅で割った値

	// 各メニューの文字列を、グローバル変数にコピーしていく
	for ( int i=0; i < iMenuNumOfSelectMenuDialog ; i++ ) {

		strncpy( select_menu_string[i].szKahouTypeString, menu_list[i].c_str(), SELECT_MENU_STRING_LENGTH_MAX);

		// 一番最後をNULLにして安全弁
		select_menu_string[i].szKahouTypeString[SELECT_MENU_STRING_LENGTH_MAX-1] = NULL;

		// 一番長い文字更新チェック
		int cur_len = strlen( menu_list[i].c_str() );
		if ( max_string_length < cur_len ) {
			max_string_length = cur_len;
		}

	}

	RECT rc; // クライアント領域のサイズ
	::GetClientRect(tenshouWND, &rc);

	int width = rc.right-rc.left;
	int height = rc.bottom-rc.top;

	// 指定されていない → 中央に
	if ( posX == -1 ) {
		int left = width/2 - 4*(max_string_length); // 中央になるように左を計算。（最大の文字列数）＊８／２のピクセル分 真ん中より左に配置 
		iXPosOfSelectMenuDialog = left;
	} else {
		iXPosOfSelectMenuDialog = posX;
	}

	// 指定されていない → 中央に
	if ( posY == -1 ) {
		int top = height/2 - 8*(iMenuNumOfSelectMenuDialog+1); // 中央になるようにトップを計算。（メニュー数＋１）＊１６／２のピクセル分 真ん中より上に配置 
		iYPosOfSelectMenuDialog = top;
	} else {
		iYPosOfSelectMenuDialog = posY;
	}

	__asm {
		push eax
		push ebx
		push ecx
		push edx
		push esp
		push esi
		push edi
	}

	// TENSHOU.EXE内の関数呼び出し
	_FuncSelectMenuDialogAsm();

	__asm {
		pop edi
		pop esi
		pop esp
		pop edx
		pop ecx
		pop ebx
		pop eax
	}

	// 結果を返す。
	return iResultOfFuncSelectMenuDialog;
}


namespace 関数 {

int 選択メニューダイアログ表示(文字列リスト型 文字列リスト, int Ｘ座標, int Ｙ座標) {
	return _SelectMenuDialog(文字列リスト, Ｘ座標, Ｙ座標);
}

}



namespace 関数 {

BOOL Set_画像ＤＬＬ追加(string 画像ＤＬＬ名) {
	// 文字列がわたってないぞ。
	if (画像ＤＬＬ名.empty()) {
		return FALSE;
	}

	HMODULE hModule = NULL;

	// 該当のＤＬＬを読み込み
	hModule = LoadLibrary(画像ＤＬＬ名.c_str());

	if (!hModule) {
		string エラーメッセージ = "指定の画像用のDLL:"+画像ＤＬＬ名+"が読み込めない";
		MessageBox(NULL, エラーメッセージ.c_str(), エラーメッセージ.c_str(), NULL);
		return FALSE;
	}
	// ハッシュに登録
	mapHResistModuleHandle.insert( map<string, HMODULE>::value_type(画像ＤＬＬ名, hModule) );
	return TRUE;
}


int 画像ダイアログ表示(string 画像ファイル名, int Ｘ座標, int Ｙ座標, int 終了タイム) {
	if ( p_OpenImageDialog ) {
		return p_OpenImageDialog( (char *)画像ファイル名.c_str(), Ｘ座標, Ｙ座標, 終了タイム );
	}
	return FALSE;
}

int 画像ダイアログ表示(string 画像ファイル名, string 画像ＤＬＬ名, int Ｘ座標, int Ｙ座標, int 終了タイム) {
	HMODULE hModule = mapHResistModuleHandle[画像ＤＬＬ名];
	if ( hModule && p_OpenResourceImageDialog ) {
		return p_OpenResourceImageDialog( (char *)画像ファイル名.c_str(), hModule, Ｘ座標, Ｙ座標, 終了タイム );
	}
	return FALSE;
}


void 噴出ダイアログ《通常・左上》開始(int 武将番号【配列用】, string メッセージ ) {
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) { 

		if ( p_FuncLeftNormalFukidashiMessage ) {
			p_FuncLeftNormalFukidashiMessage(武将番号【配列用】, (char *)メッセージ.c_str() );
		}
	} else {
		デバッグ出力("武将番号【配列用】は範囲外");
	}
}

void 噴出ダイアログ《通常・右下》開始(int 武将番号【配列用】, string メッセージ ) {
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) { 

		if ( p_FuncRightNormalFukidashiMessage ) {
			p_FuncRightNormalFukidashiMessage(武将番号【配列用】, (char *)メッセージ.c_str() );
		}
	} else {
		デバッグ出力("武将番号【配列用】は範囲外");
	}
}


void 噴出ダイアログ《通常・左上》更新(int 武将番号【配列用】, string メッセージ ) {
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) { 

		if ( p_FuncLeftNormalFukidashiUpdate ) {
			p_FuncLeftNormalFukidashiUpdate(武将番号【配列用】, (char *)メッセージ.c_str() );
		}
	} else {
		デバッグ出力("武将番号【配列用】は範囲外");
	}
}

void 噴出ダイアログ《通常・右下》更新(int 武将番号【配列用】, string メッセージ ) {
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) { 

		if ( p_FuncRightNormalFukidashiUpdate ) {
			p_FuncRightNormalFukidashiUpdate(武将番号【配列用】, (char *)メッセージ.c_str() );
		}
	} else {
		デバッグ出力("武将番号【配列用】は範囲外");
	}
}

void 噴出ダイアログ《通常・左上》終了() {
	if ( p_FuncLeftNormalFukidashiDelete ) {
		p_FuncLeftNormalFukidashiDelete();
	}
}

void 噴出ダイアログ《通常・右下》終了() {
	if ( p_FuncRightNormalFukidashiDelete ) {
		p_FuncRightNormalFukidashiDelete();
	}
}

}


namespace 関数 {

	// 
	BOOL isOnSenjoFukidashiDialog = FALSE;
	void 噴出ダイアログ《戦場・中央》表示(int 武将番号【配列用】, string メッセージ) {

		if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) { 
			if ( p_FuncSenjoFukidashiDialog ) {
				p_FuncSenjoFukidashiDialog( 武将番号【配列用】, (char *)メッセージ.c_str() );
			}
		} else {
			デバッグ出力("武将番号【配列用】は範囲外");
		}
	}

}



//----------------------------------大名選択ダイアログ
/*
0042534D  /$ FF7424 08      PUSH    DWORD PTR SS:[ESP+8]
00425351  |. 8B4C24 08      MOV     ECX, DWORD PTR SS:[ESP+8]
00425355  |. E8 63010500    CALL    TENSHOU.004754BD
0042535A  |. 33C0           XOR     EAX, EAX
0042535C  |. 50             PUSH    EAX
0042535D  |. 50             PUSH    EAX
0042535E  |. 6A 08          PUSH    8
00425360  |. 6A 02          PUSH    2
00425362  |. 50             PUSH    EAX
00425363  |. 68 9F071103    PUSH    311079F
00425368  |. E8 031D0400    CALL    TENSHOU.00467070
0042536D  |. 50             PUSH    EAX                              ; |Arg2
0042536E  |. 68 D8A54D00    PUSH    TENSHOU.004DA5D8                 ; |Arg1 = 004DA5D8
00425373  |. E8 F7D10200    CALL    TENSHOU.0045256F                 ; \TENSHOU.0045256F
00425378  |. 66:A3 FCE54B00 MOV     WORD PTR DS:[4BE5FC], AX
0042537E  |. 83C4 20        ADD     ESP, 20
00425381  \. C3             RETN
*/

/*
00415B93  |> 33C0           XOR     EAX, EAX
00415B95  |. B9 FFFF0000    MOV     ECX, 0FFFF
00415B9A  |. 50             PUSH    EAX
00415B9B  |. 50             PUSH    EAX
00415B9C  |. 51             PUSH    ECX
00415B9D  |. 51             PUSH    ECX
00415B9E  |. 50             PUSH    EAX
00415B9F  |. 68 9F071103    PUSH    311079F
00415BA4  |. E8 C7140500    CALL    TENSHOU.00467070
00415BA9  |. 50             PUSH    EAX                              ; |Arg2
00415BAA  |. 68 D8A54D00    PUSH    TENSHOU.004DA5D8                 ; |Arg1 = 004DA5D8
00415BAF  |. E8 BBC90300    CALL    TENSHOU.0045256F                 ; \TENSHOU.0045256F
00415BB4  |. 66:8BD8        MOV     BX, AX   ← AXが選択大名番号

*/

//---------------------選択大名ダイアログ-------------------------
int pCallFromFuncSelectDaimyoDialog = 0x45256F; // 元々TENSHOU.EXE内にあったCALL先
int pCallFromFuncSelectDaimyoDialogSub = 0x467070; // 元々TENSHOU.EXE内にあったCALL先
int iDaimyoIDOfSelectDaimyoDialog = -1; // 主観となるiDaimyoID。友好値などがあるので、主観大名が必要。
int iReturnOfSelectDaimyoDialog = 0; // 返り値。eaxの部分のみ採用する。
int iFilterOptionOfSelectDaimyoDialog = カラム::大名::デフォルト; // フィルターオプション
WORD iArrayOfDaimyoList[最大数::大名情報::配列数+1] = {0}; // 表示する対象となる大名リスト番号。最後は0xFFFFで終わりとみなすので+1。

void _SelectDaimyoDialogAsm() {

	__asm {
		xor eax, eax
		mov ecx, 0xFFFF
	
		push eax      // 別のやり方 0 
		push eax	  //            0 
		push ecx	  //            8 
		push ecx	  //            2 
		push 0x4001	  //            0 
		push iFilterOptionOfSelectDaimyoDialog

		// call pCallFromFuncSelectDaimyoDialogSub // 自分の大名勢力の番号をeaxにセット
		mov eax, iDaimyoIDOfSelectDaimyoDialog
		push eax
		push 0x4DA5D8 // WORDで大名の番号の配列を格納してる場所。最後0xFFFF

		call pCallFromFuncSelectDaimyoDialog

		mov iReturnOfSelectDaimyoDialog, eax

		add  esp, 0x20
	}
}

// 対象となる大名リスト。
int _SelectDaimyoDialog(vector<int> list, int iFilterOption, int iMainDaimyoID ) {

	// リストが無いならなにもしない。
	if ( list.size() == 0 ) {
		return 0xFFFF;
	}
	if ( iMainDaimyoID == -1 ) {
		iMainDaimyoID = pターン情報.現在のターン【大名番号】-1;
	}
	if ( !(0 <= iMainDaimyoID && iMainDaimyoID < 最大数::大名情報::配列数 ) ) {
		return 0xFFFF;
	}
	iDaimyoIDOfSelectDaimyoDialog = iMainDaimyoID+1;

	// 渡されたvector形式のリストをWORD形式の配列へのコピーしていく。
	WORD *pCopy = iArrayOfDaimyoList;
	// 大名のリストを配列形式にする。
	for ( vector<int>::iterator it=list.begin(); it != list.end(); it++ ) {

		int iDaimyoID = *it;
		// 範囲外は無視
		if ( ! (0 <= iDaimyoID && iDaimyoID < 最大数::大名情報::配列数) ) {
			continue;
		}
		// 大名が居ない番号は無視
		if ( p大名情報[iDaimyoID].大名【武将番号】 == 0xFFFF ) {
			continue; // １つでも無効なものがあればすぐアウト
		}
		
		*pCopy = (WORD)iDaimyoID+1;
		pCopy++;
	}
	
	// コピー委ポインタが１つも進んでいない。==１つも有効な大名が居なかった
	if ( pCopy == iArrayOfDaimyoList ) {
		return 0xFFFF;
	}

	*pCopy = 0xFFFF; // 最後の部分に0xFFFFを足す。

	// 0x4DA5D8 // WORDで大名の番号の配列を格納してる場所。
	// 大名リストの内容をtenshou.exeメモリへと複製展開。
	memcpy( (void *)0x4DA5D8, iArrayOfDaimyoList, sizeof(iArrayOfDaimyoList) );

	// フィルターオプションを上書き
	iFilterOptionOfSelectDaimyoDialog = iFilterOption;

	__asm {
		push eax
		push ebx
		push ecx
		push edx
		push esp
		push esi
		push edi
	}

	// TENSHOU.EXE内の関数呼び出し
	_SelectDaimyoDialogAsm();

	__asm {
		pop edi
		pop esi
		pop esp
		pop edx
		pop ecx
		pop ebx
		pop eax
	}

	iReturnOfSelectDaimyoDialog = iReturnOfSelectDaimyoDialog & 0xFFFF; // EAXのうち、AXの部分のみ。
	if ( iReturnOfSelectDaimyoDialog == 0xFF || iReturnOfSelectDaimyoDialog == 0xFFFF ) { // 選択しなかった
		return 0xFFFF;
	} else {
		// 何番目を選択したか？ ではなくて、対象の大名番号【配列用】を直接返す。
		return iReturnOfSelectDaimyoDialog-1;
	}
}

namespace 関数 {

int 選択大名ダイアログ表示(番号リスト型 大名番号【配列用】リスト, int カラムオプション, int 主観大名番号【配列用】) {
	return _SelectDaimyoDialog(大名番号【配列用】リスト, カラムオプション, 主観大名番号【配列用】);
}

}



//-------------------------------------------------------------------------------------

/*
0045036E  |> 6A 00          /PUSH 0                                  ; /Arg5 = 00000000
00450370  |. 6A 00          |PUSH 0                                  ; |Arg4 = 00000000
00450372  |. 56             |PUSH ESI                                ; |Arg3
00450373  |. 68 7FCD0000    |PUSH 0CD7F                              ; |Arg2 = 0000CD7F (軍団選択用固定。表示項目を選べる)
00450378  |. 68 D8934D00    |PUSH TENSHOU.004D93D8                   ; |Arg1 = 004D93D8
0045037D  |. E8 D7B30000    |CALL TENSHOU.0045B759                   ; \TENSHOU.0045B759
00450382  |. 66:8BF8        |MOV DI,AX
00450385  |. 83C4 14        |ADD ESP,14
*/
/*
0045B763  |. FF75 10        PUSH    DWORD PTR SS:[EBP+10]            ; |Arg4
0045B766  |. FF75 0C        PUSH    DWORD PTR SS:[EBP+C]             ; |Arg3
0045B769     6A 01          PUSH    1										この場所の人数が、選択可能人数 1固定で書いてあるが、0に切り替え可能とする。
0045B76B  |. FF75 08        PUSH    DWORD PTR SS:[EBP+8]             ; |Arg1
0045B76E  |. E8 EEFEFFFF    CALL    TENSHOU.0045B661                 ; \TENSHOU.0045B661
*/

//---------------------選択軍団ダイアログ-------------------------
int pCallFromFuncSelectGundanDialog = 0x45B759; // 元々TENSHOU.EXE内にあったCALL先
int iReturnOfSelectGundanDialog = 0; // 返り値。AXの部分のみ採用する。
WORD iArrayOfGundanList[最大数::軍団情報::配列数+1] = {0}; // 表示する対象となる軍団リスト番号。最後は0xFFFFで終わりとみなす。
int iFilterOptionOfSelectGundanDialog = カラム::軍団::デフォルト;
static int iMultiGundanNumOfSelectGundanDialog = 1; // 選択可能な軍団の最大数。

void _SelectGundanDialogAsm() {

	__asm {
		push 0
		push 0
		push 1
		push iFilterOptionOfSelectGundanDialog // フィルター値
		push 0x4D93D8 // WORDで軍団の番号の配列を格納してる場所。最後0xFFFF

		call pCallFromFuncSelectGundanDialog

		mov iReturnOfSelectGundanDialog, eax

		add  esp, 0x14
	}
}

// 対象となる軍団リスト。
int _SelectGundanDialog(vector<int> list, int iFilterOption) {

	// リストが無いならなにもしない。
	if ( list.size() == 0 ) {
		return 0xFFFF;
	}

	// 渡されたvector形式のリストをWORD形式の配列へのコピーしていく。
	WORD *pCopy = iArrayOfGundanList;
	// 軍団のリストを配列形式にする。
	for ( vector<int>::iterator it=list.begin(); it != list.end(); it++ ) {

		int iGundanID = *it;
		// 範囲外は無視
		if ( ! (0 <= iGundanID && iGundanID < 最大数::軍団情報::配列数) ) {
			continue;
		}
		// 軍団長が居ない番号は無視
		if ( p軍団情報[iGundanID].軍団長【武将番号】 == 0xFFFF ) {
			continue;
		}
		
		*pCopy = (WORD)iGundanID+1; // 配列用→番号にして配列に格納
		pCopy++;
	}
	
	// コピー委ポインタが１つも進んでいない。==１つも有効な軍団が居なかった
	if ( pCopy == iArrayOfGundanList ) {
		return 0xFFFF;
	}

	*pCopy = 0xFFFF; // 最後の部分に0xFFFFを足す。

	// 0x4D93D8 // WORDで軍団の番号の配列を格納してる場所。
	// 軍団リストの内容をtenshou.exeメモリへと複製展開。
	memcpy( (void *)0x4D93D8, iArrayOfGundanList, sizeof(iArrayOfGundanList) );

	// フィルターオプションを上書き
	iFilterOptionOfSelectGundanDialog = iFilterOption;

	__asm {
		push eax
		push ebx
		push ecx
		push edx
		push esp
		push esi
		push edi
	}

	// TENSHOU.EXE内の関数呼び出し
	_SelectGundanDialogAsm();

	__asm {
		pop edi
		pop esi
		pop esp
		pop edx
		pop ecx
		pop ebx
		pop eax
	}

	iReturnOfSelectGundanDialog = iReturnOfSelectGundanDialog & 0xFFFF; // EAXのうち、AXの部分のみ。
	if ( iReturnOfSelectGundanDialog == 0xFF || iReturnOfSelectGundanDialog == 0xFFFF ) { // 選択しなかった
		return 0xFFFF;
	} else {
		// 何番目を選択したか？ ではなくて、対象の軍団番号【配列用】を直接返す。
		return iReturnOfSelectGundanDialog-1;
	}
}

namespace 関数 {

int 選択軍団ダイアログ表示(番号リスト型 軍団番号【配列用】リスト, int カラムオプション ) {
	return _SelectGundanDialog(軍団番号【配列用】リスト, カラムオプション);
}

}

//-----------------------------------家宝リストダイアログ

/*
00446673  |> 6A 00          /PUSH    0                               ; /Arg5 = 00000000
00446675  |. 6A 00          |PUSH    0                               ; |Arg4 = 00000000
00446677  |. 57             |PUSH    EDI                             ; |Arg3
00446678  |. 6A 1F          |PUSH    1F                              ; |Arg2 = 0000001F
0044667A  |. 68 50C84D00    |PUSH    TENSHOU.004DC850                ; |Arg1 = 004DC850
0044667F  |. E8 0FD70300    |CALL    TENSHOU.00483D93                ; \TENSHOU.00483D93
00446684  |. 83C4 14        |ADD     ESP, 14
00446687  |. 8BF0           |MOV     ESI, EAX

*/

//---------------------選択家宝ダイアログ-------------------------
int pCallFromFuncSelectKahouDialog = 0x483D93; // 元々TENSHOU.EXE内にあったCALL先
int iReturnOfSelectKahouDialog = 0; // 返り値。AXの部分のみ採用する。
int iArrayOfKahouList[最大数::家宝情報::配列数+1] = {0}; // 表示する対象となる家宝リスト番号。最後は0xFFFFで終わりとみなす。
int iFilterOptionOfSelectKahouDialog = カラム::家宝::デフォルト;
void _SelectKahouDialogAsm() {

	__asm {
		push 0
		push 0
		push 1 // 選択可能数(但し家宝を複数選択する要件はないはず)
		push iFilterOptionOfSelectKahouDialog   // 表示項目オプション。0x3とかいうのもある。
		push 0x4DC850 // WORDで家宝の番号の配列を格納してる場所。最後0xFFFF

		call pCallFromFuncSelectKahouDialog

		mov iReturnOfSelectKahouDialog, eax

		add  esp, 0x14
	}
}

// 対象となる家宝リスト。
int _SelectKahouDialog(vector<int> list, int iFilterOption) {

	// リストが無いならなにもしない。
	if ( list.size() == 0 ) {
		return 0xFFFF;
	}

	// 渡されたvector形式のリストをWORD形式の配列へのコピーしていく。
	int *pCopy = iArrayOfKahouList;
	// 家宝のリストを配列形式にする。
	for ( vector<int>::iterator it=list.begin(); it != list.end(); it++ ) {

		int iKahouID = *it;
		// 範囲外は無視
		if ( ! (0 <= iKahouID && iKahouID < 最大数::家宝情報::配列数) ) {
			continue;
		}
		
		*pCopy = iKahouID+1; // 配列用→番号にして配列に格納
		pCopy++;
	}
	
	// コピー委ポインタが１つも進んでいない。==１つも有効な家宝が１つもなかった
	if ( pCopy == iArrayOfKahouList ) {
		return 0xFFFF;
	}

	*pCopy = 0xFFFF; // 最後の部分に0xFFFFを足す。

	// 0x4DC850 // intで家宝の番号の配列を格納してる場所。
	// 家宝リストの内容をtenshou.exeメモリへと複製展開。
	memcpy( (void *)0x4DC850, iArrayOfKahouList, sizeof(iArrayOfKahouList) );

	// フィルターオプションを上書き
	iFilterOptionOfSelectKahouDialog = iFilterOption;

	__asm {
		push eax
		push ebx
		push ecx
		push edx
		push esp
		push esi
		push edi
	}

	// TENSHOU.EXE内の関数呼び出し
	_SelectKahouDialogAsm();

	__asm {
		pop edi
		pop esi
		pop esp
		pop edx
		pop ecx
		pop ebx
		pop eax
	}

	iReturnOfSelectKahouDialog = iReturnOfSelectKahouDialog & 0xFFFF; // EAXのうち、AXの部分のみ。
	if ( iReturnOfSelectKahouDialog == 0xFF || iReturnOfSelectKahouDialog == 0xFFFF ) { // 選択しなかった
		return 0xFFFF;
	} else {
		// 何番目を選択したか？ ではなくて、対象の家宝番号【配列用】を直接返す。
		return iReturnOfSelectKahouDialog-1;
	}
}


namespace 関数 {

int 選択家宝ダイアログ表示(番号リスト型 家宝番号【配列用】リスト, int カラムオプション ) {
	return _SelectKahouDialog(家宝番号【配列用】リスト, カラムオプション);
}

}


//---------------------------------------------------------武将リストダイアログ

/*
0040199E  |. 6A 00          PUSH 0                                   ; /Arg9 = 00000000
004019A0  |. 6A 00          PUSH 0                                   ; |Arg8 = 00000000
004019A2  |. 57             PUSH EDI                                 ; |Arg7 = 0xFFFF
004019A3  |. 6A 0A          PUSH 0A                                  ; |Arg6 = 0000000A
004019A5  |. 68 80100000    PUSH 1080                                ; |Arg5 = 00001080
004019AA  |. 6A 00          PUSH 0                                   ; |Arg4 = 00000000
004019AC  |. 68 103C0900    PUSH 93C10                               ; |Arg3 = 00093C10 (表示選択オプション。3FC93F9Dだと全部.pythonのbinで調査か。)
004019B1  |. FF75 FC        PUSH DWORD PTR SS:[EBP-4]                ; |Arg2 = 5 ( 選択可能人数 )
004019B4  |. FF76 70        PUSH DWORD PTR DS:[ESI+70]               ; |Arg1 = 0x4DBD40(固定)
004019B7  |. E8 797C0300    CALL TENSHOU.00439635                    ; \TENSHOU.00439635
004019BC  |. 83C4 24        ADD ESP,24
004019BF  |. 8BD8           MOV EBX,EAX


004397B3  /$ 55             PUSH EBP
004397B4  |. 8BEC           MOV EBP,ESP
004397B6  |. FF7424 24      PUSH DWORD PTR SS:[ESP+24]               ; /Arg9
004397BA  |. FF75 20        PUSH DWORD PTR SS:[EBP+20]               ; |Arg8
004397BD  |. FF75 1C        PUSH DWORD PTR SS:[EBP+1C]               ; |Arg7
004397C0  |. FF75 18        PUSH DWORD PTR SS:[EBP+18]               ; |Arg6
004397C3  |. FF75 14        PUSH DWORD PTR SS:[EBP+14]               ; |Arg5
004397C6  |. FF75 10        PUSH DWORD PTR SS:[EBP+10]               ; |Arg4
004397C9  |. FF75 0C        PUSH DWORD PTR SS:[EBP+C]                ; |Arg3	
004397CC  |. 6A 01          PUSH 1                                   ; |Arg2 = 00000001
004397CE  |. FF75 08        PUSH DWORD PTR SS:[EBP+8]                ; |Arg1
004397D1  |. E8 5FFEFFFF    CALL TENSHOU.00439635                    ; \TENSHOU.00439635
004397D6  |. 83C4 24        ADD ESP,24
004397D9  |. 83F8 01        CMP EAX,1
004397DC  |. 66:B8 FFFF     MOV AX,0FFFF
004397E0  |. 75 0A          JNZ SHORT TENSHOU.004397EC
004397E2  |. 6A 00          PUSH 0
004397E4  |. FF75 08        PUSH DWORD PTR SS:[EBP+8]				0x4DBD40(固定)
004397E7  |. E8 724EFDFF    CALL TENSHOU.0040E65E					この関数の結果は選択武将のIDとなる。
004397EC  |> 8BE5           MOV ESP,EBP
004397EE  |. 5D             POP EBP
004397EF  \. C3             RETN

0018FE0C   004DBD40  |Arg1 = 004DBD40
0018FE10   00000001  |Arg2 = 00000001
0018FE14   3FC93F9D  |Arg3 = 3FC93F9D
0018FE18   00000000  |Arg4 = 00000000
0018FE1C   00000000  |Arg5 = 00000000
0018FE20   0000FFFF  |Arg6 = 0000FFFF
0018FE24   0000FFFF  |Arg7 = 0000FFFF
0018FE28   00000000  |Arg8 = 00000000
0018FE2C   00000000  \Arg9 = 00000000
*/



//---------------------選択武将ダイアログ-------------------------
int pCallFromFuncSelectBushouDialog = 0x439635; // 元々TENSHOU.EXE内にあったCALL先
int pCallFromFuncSelectBushouDialog2 = 0x40E65E; // 元々TENSHOU.EXE内にあったCALL先
int iReturnOfSelectBushouDialog = 0; // 返り値。AXの部分のみ採用する。
WORD iArrayOfBushouList[最大数::武将情報::配列数+1] = {0}; // 表示する対象となる武将リスト番号。最後は0xFFFFで終わりとみなす。
int iFilterOptionOfSelectBushouDialog = カラム::武将::デフォルト;
int iFilterExOptionOfSelectBushouDialog = 0; // こちらは33bit目以降のオプション。

void _SelectBushouDialogAsm() {

	__asm {
		push 0
		push 0
		push 0xFFFF
		push 0xFFFF
		push 0
		push iFilterExOptionOfSelectBushouDialog // 33bit目以降の拡張オプション
		push iFilterOptionOfSelectBushouDialog // フィルター値
		push 1 // 選択可能数(但し武将を複数選択する要件はないはず)
		push 0x4DBD40 // WORDで武将の番号の配列を格納してる場所。最後0xFFFF

		call pCallFromFuncSelectBushouDialog
		add  esp, 0x24
		cmp eax, 1	
		mov ax, 0xFFFF
		jnz labelEndOfFuncSelectBushouDialogAsm

		push 0
		push 0x4DBD40
		call pCallFromFuncSelectBushouDialog2
		mov iReturnOfSelectBushouDialog, eax // これが実際の選択武将番号
		add  esp, 0x8

		labelEndOfFuncSelectBushouDialogAsm:
				;
	}
}

// 対象となる武将リスト。
int _SelectBushouDialog(vector<int> list, __int64 iFilterOption) {

	// リストが無いならなにもしない。
	if ( list.size() == 0 ) {
		return 0xFFFF;
	}

	// 返り値はデフォルトは「何も選択しなかった」
	iReturnOfSelectBushouDialog = 0xFFFF;

	// 渡されたvector形式のリストをWORD形式の配列へのコピーしていく。
	WORD *pCopy = iArrayOfBushouList;
	// 武将のリストを配列形式にする。
	for ( vector<int>::iterator it=list.begin(); it != list.end(); it++ ) {

		int iBushouID = *it;
		// 範囲外は無視
		if ( ! (0 <= iBushouID && iBushouID < 最大数::武将情報::配列数) ) {
			continue;
		}
		
		*pCopy = (WORD)iBushouID+1; // 配列用→番号にして配列に格納
		pCopy++;
	}
	
	// コピー委ポインタが１つも進んでいない。==１つも有効な武将が居なかった
	if ( pCopy == iArrayOfBushouList ) {
		return 0xFFFF;
	}

	*pCopy = 0xFFFF; // 最後の部分に0xFFFFを足す。

	// 0x4DBD40 // WORDで武将の番号の配列を格納してる場所。
	// 武将リストの内容をtenshou.exeメモリへと複製展開。
	memcpy( (void *)0x4DBD40, iArrayOfBushouList, sizeof(iArrayOfBushouList) );

	// フィルターオプションを上書き
	iFilterOptionOfSelectBushouDialog = iFilterOption & 0xFFFFFFFF;
	iFilterOption = iFilterOption >> 32; // 上位32bitを下位に持ってくる。(拡張オプションを下位に)
	iFilterExOptionOfSelectBushouDialog = iFilterOption & 0xFFFFFFFF;

	__asm {
		push eax
		push ebx
		push ecx
		push edx
		push esp
		push esi
		push edi
	}

	// TENSHOU.EXE内の関数呼び出し
	_SelectBushouDialogAsm();

	__asm {
		pop edi
		pop esi
		pop esp
		pop edx
		pop ecx
		pop ebx
		pop eax
	}

	iReturnOfSelectBushouDialog = iReturnOfSelectBushouDialog & 0xFFFF; // EAXのうち、AXの部分のみ。
	if ( iReturnOfSelectBushouDialog == 0xFFFF ) { // 選択しなかった
		return 0xFFFF;
	} else {
		// 何番目を選択したか？ ではなくて、対象の武将番号【配列用】を直接返す。
		return int(iReturnOfSelectBushouDialog)-1;
	}
}


namespace 関数 {

	// 対象となる武将リスト。
int 選択武将ダイアログ表示(番号リスト型 武将番号【配列用】リスト, __int64 カラムオプション) {
	return _SelectBushouDialog( 武将番号【配列用】リスト, カラムオプション);
}


}


//--------------------------------------------------------------------------


/*
城の引数


0018FE14   004D8F50  |Arg1 = 004D8F50			武将の格納場所
0018FE18   00000001  |Arg2 = 00000001
0018FE1C   0033D57B  |Arg3 = 0033D57B			カラムオプション
0018FE20   00000000  |Arg4 = 00000000
0018FE24   0000FFFF  |Arg5 = 0000FFFF
0018FE28   0000FFFF  |Arg6 = 0000FFFF
0018FE2C   00000000  |Arg7 = 00000000
0018FE30   00000000  \Arg8 = 00000000

城の単発用
0045040D  |> 6A 00          /PUSH 0                                  ; /Arg7 = 00000000
0045040F  |. 6A 00          |PUSH 0                                  ; |Arg6 = 00000000
00450411  |. 53             |PUSH EBX                                ; |Arg5
00450412  |. 53             |PUSH EBX                                ; |Arg4
00450413  |. 57             |PUSH EDI                                ; |Arg3
00450414  |. 68 7BD53300    |PUSH 33D57B                             ; |Arg2 = 0033D57B		カラムオプション
00450419  |. 68 508F4D00    |PUSH TENSHOU.004D8F50                   ; |Arg1 = 004D8F50		ここ固定。リストの武将の格納場所
0045041E  |. E8 B8E10200    |CALL TENSHOU.0047E5DB                   ; \TENSHOU.0047E5DB
00450423  |. 66:8BF0        |MOV SI,AX
00450426  |. 83C4 1C        |ADD     ESP, 1C


城の単発用
呼出し先。城選択は１しかない模様。
0047E5DB  /$ 55             PUSH EBP
0047E5DC  |. 8BEC           MOV EBP,ESP
0047E5DE  |. FF7424 20      PUSH DWORD PTR SS:[ESP+20]               ; /Arg8
0047E5E2  |. FF75 1C        PUSH DWORD PTR SS:[EBP+1C]               ; |Arg7
0047E5E5  |. FF75 18        PUSH DWORD PTR SS:[EBP+18]               ; |Arg6
0047E5E8  |. FF75 14        PUSH DWORD PTR SS:[EBP+14]               ; |Arg5
0047E5EB  |. FF75 10        PUSH DWORD PTR SS:[EBP+10]               ; |Arg4
0047E5EE  |. FF75 0C        PUSH DWORD PTR SS:[EBP+C]                ; |Arg3
0047E5F1  |. 6A 01          PUSH 1                                   ; |Arg2 = 00000001
0047E5F3  |. FF75 08        PUSH DWORD PTR SS:[EBP+8]                ; |Arg1
0047E5F6  |. E8 6BFEFFFF    CALL TENSHOU.0047E466                    ; \TENSHOU.0047E466
0047E5FB  |. 83C4 20        ADD ESP,20
0047E5FE  |. 83F8 01        CMP EAX,1
0047E601  |. 66:B8 FFFF     MOV AX,0FFFF
0047E605  |. 75 0A          JNZ SHORT TENSHOU.0047E611
0047E607  |. 6A 00          PUSH 0
0047E609  |. FF75 08        PUSH DWORD PTR SS:[EBP+8]			
0047E60C  |. E8 6408F9FF    CALL TENSHOU.0040EE75
0047E611  |> 8BE5           MOV ESP,EBP
0047E613  |. 5D             POP EBP
0047E614  \. C3             RETN
*/


//---------------------選択城ダイアログ-------------------------
int pCallFromFuncSelectCastleDialog = 0x47E5DB; // 元々TENSHOU.EXE内にあったCALL先
int iReturnOfSelectCastleDialog = 0; // 返り値。AXの部分のみ採用する。
WORD iArrayOfCastleList[最大数::城情報::配列数+1] = {0}; // 表示する対象となる城リスト番号。最後は0xFFFFで終わりとみなす。
int iFilterOptionOfSelectCastleDialog = カラム::城::デフォルト;
static int iMultiCastleNumOfSelectCastleDialog = 1; // 選択可能な城の最大数。

void _SelectCastleDialogAsm() {

	__asm {
		push 0 
		push 0 
		push 0xFFFF
		push 0xFFFF
		push 0 
		push iFilterOptionOfSelectCastleDialog // フィルター値
		push 0x4D8F50 // WORDで城の番号の配列を格納してる場所。最後0xFFFF

		call pCallFromFuncSelectCastleDialog

		mov iReturnOfSelectCastleDialog, eax

		add  esp, 0x1C
	}
}

// 対象となる城リスト。
int _SelectCastleDialog(vector<int> list, int iFilterOption ) {

	// リストが無いならなにもしない。
	if ( list.size() == 0 ) {
		return 0xFFFF;
	}

	// 渡されたvector形式のリストをWORD形式の配列へのコピーしていく。
	WORD *pCopy = iArrayOfCastleList;
	// 城のリストを配列形式にする。
	for ( vector<int>::iterator it=list.begin(); it != list.end(); it++ ) {

		int iCastleID = *it;
		// 範囲外は無視
		if ( ! (0 <= iCastleID && iCastleID < 最大数::城情報::配列数) ) {
			continue;
		}
		
		*pCopy = (WORD)iCastleID+1; // 配列用→番号にして配列に格納
		pCopy++;
	}
	
	// コピー委ポインタが１つも進んでいない。==１つも有効な城が居なかった
	if ( pCopy == iArrayOfCastleList ) {
		return 0xFFFF;
	}

	*pCopy = 0xFFFF; // 最後の部分に0xFFFFを足す。

	// 0x4D8F50 // WORDで城の番号の配列を格納してる場所。
	// 城リストの内容をtenshou.exeメモリへと複製展開。
	memcpy( (void *)0x4D8F50, iArrayOfCastleList, sizeof(iArrayOfCastleList) );

	// フィルターオプションを上書き
	iFilterOptionOfSelectCastleDialog = iFilterOption;

	__asm {
		push eax
		push ebx
		push ecx
		push edx
		push esp
		push esi
		push edi
	}

	// TENSHOU.EXE内の関数呼び出し
	_SelectCastleDialogAsm();

	__asm {
		pop edi
		pop esi
		pop esp
		pop edx
		pop ecx
		pop ebx
		pop eax
	}

	iReturnOfSelectCastleDialog = iReturnOfSelectCastleDialog & 0xFFFF; // EAXのうち、AXの部分のみ。
	if ( iReturnOfSelectCastleDialog == 0xFF || iReturnOfSelectCastleDialog == 0xFFFF ) { // 選択しなかった
		return 0xFFFF;
	} else {
		// 何番目を選択したか？ ではなくて、対象の城番号【配列用】を直接返す。
		return iReturnOfSelectCastleDialog-1;
	}
}


namespace 関数 {

	// 対象となる武将リスト。
int 選択城ダイアログ表示(番号リスト型 城番号【配列用】リスト, int カラムオプション) {
	return _SelectCastleDialog( 城番号【配列用】リスト, カラムオプション);
}


}





//------------官位ダイアログ

/*
00401B0A  |> 53             /PUSH EBX                                ; /Arg5 = 0
00401B0B  |. 53             |PUSH EBX                                ; |Arg4 = 0
00401B0C  |. 53             |PUSH EBX                                ; |Arg3 = 0
00401B0D  |. 6A 0F          |PUSH 0F                                 ; |Arg2 = 0000000F ← 選択オプション
00401B0F  |. 68 00B14D00    |PUSH TENSHOU.004DB100                   ; |Arg1 = 004DB100 ← 配列格納の場所
00401B14  |. E8 09750000    |CALL TENSHOU.00409022                   ; \TENSHOU.00409022
00401B19  |. 83C4 14        |ADD ESP,14
00401B1C  |. 8BF8           |MOV EDI,EAX
*/

//---------------------選択官位ダイアログ-------------------------
int pCallFromFuncSelectKaniDialog = 0x409022; // 元々TENSHOU.EXE内にあったCALL先
int iReturnOfSelectKaniDialog = 0; // 返り値。AXの部分のみ採用する。
int iArrayOfKaniList[最大数::官位情報::配列数+1] = {0}; // 表示する対象となる官位リスト番号。最後は0xFFFFで終わりとみなす。
int iFilterOptionOfSelectKaniDialog = カラム::官位::デフォルト;
void _SelectKaniDialogAsm() {

	__asm {
		push 0
		push 0
		push 0 // 選択可能数(但し官位を複数選択する要件はないはず)
		push iFilterOptionOfSelectKaniDialog   // 表示項目オプション。0x3とかいうのもある。
		push 0x4DB100 // WORDで官位の番号の配列を格納してる場所。最後0xFFFF

		call pCallFromFuncSelectKaniDialog

		mov iReturnOfSelectKaniDialog, eax

		add  esp, 0x14
	}
}

// 対象となる官位リスト。
int _SelectKaniDialog(vector<int> list, int iFilterOption) {

	// リストが無いならなにもしない。
	if ( list.size() == 0 ) {
		return 0xFFFF;
	}

	// 渡されたvector形式のリストをWORD形式の配列へのコピーしていく。
	int *pCopy = iArrayOfKaniList;
	// 官位のリストを配列形式にする。
	for ( vector<int>::iterator it=list.begin(); it != list.end(); it++ ) {

		int iKaniID = *it;
		// 範囲外は無視
		if ( ! (0 <= iKaniID && iKaniID < 最大数::官位情報::配列数) ) {
			continue;
		}
		
		*pCopy = iKaniID+1; // 配列用→番号にして配列に格納
		pCopy++;
	}
	
	// コピー委ポインタが１つも進んでいない。==１つも有効な官位が１つもなかった
	if ( pCopy == iArrayOfKaniList ) {
		return 0xFFFF;
	}

	*pCopy = 0xFFFF; // 最後の部分に0xFFFFを足す。

	// 0x4DB100 // intで官位の番号の配列を格納してる場所。
	// 官位リストの内容をtenshou.exeメモリへと複製展開。
	memcpy( (void *)0x4DB100, iArrayOfKaniList, sizeof(iArrayOfKaniList) );

	// フィルターオプションを上書き
	iFilterOptionOfSelectKaniDialog = iFilterOption;

	__asm {
		push eax
		push ebx
		push ecx
		push edx
		push esp
		push esi
		push edi
	}

	// TENSHOU.EXE内の関数呼び出し
	_SelectKaniDialogAsm();

	__asm {
		pop edi
		pop esi
		pop esp
		pop edx
		pop ecx
		pop ebx
		pop eax
	}

	iReturnOfSelectKaniDialog = iReturnOfSelectKaniDialog & 0xFFFF; // EAXのうち、AXの部分のみ。
	if ( iReturnOfSelectKaniDialog == 0xFF ||iReturnOfSelectKaniDialog == 0xFFFF ) { // 選択しなかった
		return 0xFFFF;
	} else {
		// 何番目を選択したか？ ではなくて、対象の官位番号【配列用】を直接返す。
		return iReturnOfSelectKaniDialog-1;
	}
}


namespace 関数 {

	// 対象となる武将リスト。
int 選択官位ダイアログ表示(番号リスト型 官位番号【配列用】リスト, int カラムオプション) {
	return _SelectKaniDialog( 官位番号【配列用】リスト, カラムオプション);
}


}




