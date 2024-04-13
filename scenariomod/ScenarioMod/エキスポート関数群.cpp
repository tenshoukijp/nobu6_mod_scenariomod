#include "カスタム駆動関数.h"
#include <map>
#include <time.h>
#include "lua/ＬＵＡ〈interface〉.h"
#include "mruby/ＭＲＵＢＹ〈interface〉.h"

#include "プロセスハンドル.h"

#pragma comment(lib, "shlwapi.lib")

using namespace std;

// 天翔記のウィンドウハンドル
HWND tenshouWND=NULL;

// TSMod.dllのハンドル
HMODULE hModuleTSMod = NULL;

extern void _正規表現関数登録();
extern void _アプリケーション関数登録();
extern void _武将関数登録();
extern void _動画関数登録();
extern void _天気関数登録();
extern void _戦闘関連登録();
extern void _環境関数登録();
extern void _効果音関数登録();
extern void _コマンド関数登録();
extern void	_シナリオ関数登録();
extern void _ダイアログ関数登録();
extern void	_フラグ関数登録();

extern void _音源モジュール登録();
extern void _音源モジュール解除();


void WINAPI snOnDllMainBgn() {

	srand( (unsigned int)time( NULL ) ); // 乱数の種を変える

	hModuleTSMod=GetModuleHandle("TSMod.dll");
	if ( !hModuleTSMod ) {;}
	// 特になにもしないが、TSMod.dll以外がScenarioModを処理しているのだろう…。
	// TSModのソースを途中までとはいえ公開しているので、将来的にはそのような互換DLLが出ることも考えられなくはない。

	LoadLuaInterpreter();
	LoadMRubyInterpreter();

	_正規表現関数登録();
	_アプリケーション関数登録();
	_武将関数登録();
	_動画関数登録();
	_天気関数登録();
	_戦闘関連登録();
	_環境関数登録();
	_効果音関数登録();
	_シナリオ関数登録();
	_音源モジュール登録();
	_コマンド関数登録();
	_ダイアログ関数登録();
	_フラグ関数登録();
}

void WINAPI snOnDllMainEnd() {
	_音源モジュール解除();

	FreeLuaInterpreter();
	FreeMRubyInterpreter();
}


void WINAPI snOnConstructor() {

	// ウィンドウハンドルを確保しておく。フォアグランドなどの情報を使うこともある。
	tenshouWND = ::GetCurrentWindowHandle();
	if ( !tenshouWND ) { tenshouWND = FindWindow("Tenshouki95", NULL); }

	try {
		カスタム駆動関数.On_起動時();
	} catch(...) {
	}
}


void WINAPI snOnDestructor() {
	try {
		カスタム駆動関数.On_終了時();
	} catch(...) {
	}
}

#define TAIKIBUSHOU_STRUCT_SIZE   (sizeof(待機武将情登場情報型) + sizeof(待機武将情報型) + sizeof(待機武将戸籍情報型))
extern byte _待機武将データバッファー[6][TAIKIBUSHOU_STRUCT_SIZE * 1300]; // 本来は最大でも1000人弱しかデータに詰め込むことが出来ない
extern int _待機武将データ人数[6];
void WINAPI snOnTaikiBushouDataTransfer(byte *p0, int n0, byte *p1, int n1, byte *p2, int n2, byte *p3, int n3, byte *p4, int n4, byte *p5, int n5) {
	memcpy(&_待機武将データバッファー[0], p0, n0);
	memcpy(&_待機武将データバッファー[1], p1, n1);
	memcpy(&_待機武将データバッファー[2], p2, n2);
	memcpy(&_待機武将データバッファー[3], p3, n3);
	memcpy(&_待機武将データバッファー[4], p4, n4);
	memcpy(&_待機武将データバッファー[5], p5, n5);
	_待機武将データ人数[0] = n0 / TAIKIBUSHOU_STRUCT_SIZE;
	_待機武将データ人数[1] = n1 / TAIKIBUSHOU_STRUCT_SIZE;
	_待機武将データ人数[2] = n2 / TAIKIBUSHOU_STRUCT_SIZE;
	_待機武将データ人数[3] = n3 / TAIKIBUSHOU_STRUCT_SIZE;
	_待機武将データ人数[4] = n4 / TAIKIBUSHOU_STRUCT_SIZE;
	_待機武将データ人数[5] = n5 / TAIKIBUSHOU_STRUCT_SIZE;
}

void WINAPI snOnAfterChangeWindowSize() {
	try {
		カスタム駆動関数.On_ウィンドウ解像度切替時();
	} catch(...) {
	}
}

void WINAPI snOnViewingTopMenu() {
	try {
		カスタム駆動関数.On_トップメニュー表示時();
	} catch(...) {
	}
}


void WINAPI snOnLoadSaveData(int iSelectID, char *szFileName) {
	try {
		カスタム駆動関数.On_セーブデータ読込時(iSelectID, string(szFileName));
	} catch(...) {
	}
}

void WINAPI snOnSaveSaveData(int iSelectID, char *szFileName) {
	try {
		カスタム駆動関数.On_セーブデータ保存時(iSelectID, string(szFileName));
	} catch(...) {
	}
}



void WINAPI snOnViewingScenarioTitleList() {

	int pt[] = { 0x4d36E4, 0x4d36C4, 0x4d36A4, 0x4d3684, 0x4d3664, 0x4d3644 }; // シナリオタイトルが存在するアドレス

	char** menu = NULL;
	
	try {
		menu = カスタム駆動関数.On_シナリオメニュー表示直前(); // 1～6で
	} catch(...) {
	}

	if ( menu ) {
		for ( int sn=0; sn<最大数::シナリオ情報::配列数; sn++ ) {
			if ( menu[sn] && strlen(menu[sn]) > 1 ) { // 
				strncpy( (char *)pt[sn], menu[sn], 31 ); // 全角１５文字までコピー
			}
		}
	}
}

static int iシナリオ選択時シナリオ番号 = -1;
char ** WINAPI snOnWritingScenarioDetail(int iシナリオ番号) {
	iシナリオ選択時シナリオ番号 = iシナリオ番号;
	char **p = NULL;
	try {
		p = カスタム駆動関数.On_シナリオ説明表示直前(iシナリオ番号);
	} catch(...) {
	}
	return p;
}

/*
* シナリオ詳細表示が出で｢確認｣を押した後、大名選択画面が表示されるまでの間に呼び出され実行される関数
* (ちょっとまだ選択されたシナリオ情報は渡していない)
*/
bool WINAPI snOnSelectingScenarioAfter(void* ptrシナリオ選択番号) {

	try {
		カスタム駆動関数.On_シナリオデータ反映直後(iシナリオ選択時シナリオ番号);
	}
	catch (...) {
	}
	return true;
}


/* 
 * シナリオ詳細表示が出で｢確認｣を押した後、大名選択画面が表示されるまでの間に呼び出され実行される関数
 * (ちょっとまだ選択されたシナリオ情報は渡していない)
 */
bool WINAPI snOnSelectingScenarioDaimyo(void* ptrシナリオ選択番号 ) {

	try {
		カスタム駆動関数.On_シナリオ大名選択直前(iシナリオ選択時シナリオ番号);
	} catch(...) {
	}
	return true;
}





bool WINAPI snOnRewriteFukidashiMessage(char *返信用バッファ, char *武将名, char *元メッセージ, メッセージ関連情報型 *ptrメッセージ関連情報) {

	メッセージ関連情報型 メッセージ関連情報;
	メッセージ関連情報.第１人称【武将番号】 = ptrメッセージ関連情報->第１人称【武将番号】;
	メッセージ関連情報.第２人称【武将番号】 = ptrメッセージ関連情報->第２人称【武将番号】;
	メッセージ関連情報.第３人称【武将番号】 = ptrメッセージ関連情報->第３人称【武将番号】;

	string 返信用メッセージ = "";
	try {
		返信用メッセージ = カスタム駆動関数.On_噴出メッセージ直前(武将名, 元メッセージ, メッセージ関連情報);
	} catch(...) {
	}
	if ( 返信用メッセージ.size() > 1 ) {
		strcpy( 返信用バッファ, 返信用メッセージ.c_str() );
		return true;
	}

	return false;
}

void WINAPI snOnDecisionInputNumberDialog(char *szメッセージ, 数値入力ダイアログパラメタ型 *param) {

	string メッセージ = szメッセージ;
	数値入力ダイアログパラメタ型 パラメタ;
	パラメタ.最小値 = param->最小値;
	パラメタ.最大値 = param->最大値;
	パラメタ.入力値 = param->入力値;

	try {
		カスタム駆動関数.On_数値入力ダイアログ決定時( メッセージ, パラメタ );
	} catch(...) {
	}
}

void WINAPI snOnRatificationDialog(char *szメッセージ, char *szTitle ) {
	try {
		string メッセージ = szメッセージ;
		string タイトル = szTitle;
		カスタム駆動関数.On_追認系ダイアログ確認時( メッセージ, タイトル );
	} catch(...) {
	}
}


// まぁこんだけパラメタありゃ、十分すぎて増えねぇだろｗ
int WINAPI snOnCustomCondition(char *sz条件名, int 整数1, int 整数2, int 整数3, char *文字列1, char *文字列2, float 浮動小数1, float 浮動小数2) {

	string 条件名(sz条件名);

	カスタム条件パラメタ型 パラメタ;
	パラメタ.整数1 = 整数1;
	パラメタ.整数2 = 整数2;
	パラメタ.整数3 = 整数3;
	パラメタ.文字列1 = 文字列1;
	パラメタ.文字列2 = 文字列2;
	パラメタ.浮動小数1 = 浮動小数1;
	パラメタ.浮動小数2 = 浮動小数2;

	int 返り値 = -1;
	try {
		返り値 = カスタム駆動関数.On_カスタム条件(条件名,パラメタ);
	} catch(...) {
	}
	return 返り値;
}


int WINAPI snOnN6PAudioPlayTrack(int 再生予定番号) {
	int 返り値 = -1;
	try {
		返り値 = カスタム駆動関数.On_音楽再生直前(再生予定番号);
	} catch(...) {
	}
	return 返り値;
}


// メイン画面において、プレイヤ担当大名ののターンとなった時
void WINAPI snOnPlayerTurnInMainScreen() {
	try {
		カスタム駆動関数.On_プレイヤ担当ターン《メイン画面》();
	} catch(...) {
	}
}

// 特定コマンドへの侵入
void WINAPI snOnEnterMainPlayerCommand(int iMainCmdID, int iSubCmdID) {
	try {
		int コマンド番号 = 0;
		カスタム駆動関数.On_プレイヤコマンド発生直前《メイン画面》(iMainCmdID, iSubCmdID);
	} catch(...) {
	}
}

// 特定コマンドからの脱出
void WINAPI snOnLeaveMainPlayerCommand() {
	try {
		int コマンド番号 = 0;
		カスタム駆動関数.On_プレイヤコマンド完了直前《メイン画面》();
	} catch(...) {
	}
}

void WINAPI snOnGundanTurnInMainScreen(int 軍団番号) {
	try {
		カスタム駆動関数.On_軍団ターン変更《メイン画面》(軍団番号);
	} catch(...) {
	}
}


string _g戦闘コマンドリスト[20];
void WINAPI snOnViewingBattleMenuInBattle5(int 武将番号,
										   char *p通常攻撃,
										   char *p一斉攻撃,
										   char *p突撃,
										   char *p鉄砲攻撃,
										   char *p大砲攻撃
										   ) {
		
	for ( int i=0; i < sizeof(_g戦闘コマンドリスト)/sizeof(_g戦闘コマンドリスト[0]); i++ ) {
		_g戦闘コマンドリスト[i] = "";
	}
	try {
		カスタム駆動関数.On_戦闘コマンド表示直前《戦争画面》(武将番号);
	} catch(...) {
	}
	strncpy( p通常攻撃,   _g戦闘コマンドリスト[ 0].c_str(), 19 );
	strncpy( p一斉攻撃,   _g戦闘コマンドリスト[ 1].c_str(), 19 );
	strncpy( p突撃,		  _g戦闘コマンドリスト[ 2].c_str(), 19 );
	strncpy( p鉄砲攻撃,   _g戦闘コマンドリスト[ 3].c_str(), 19 );
	strncpy( p大砲攻撃,   _g戦闘コマンドリスト[ 4].c_str(), 19 );
}


// プレイヤ操作によって、戦闘中の通常コマンドが表示される時
string _g基本コマンドリスト[20];
void WINAPI snOnViewingCommandMenuInBattle12(int 武将番号,
											char *p鼓舞,
											char *p城外,
											char *p退却,
											char *p内応,
											char *p技能,
											char *p挑発,
											char *p煽動,
											char *p混乱,
											char *p火攻め,
											char *p暗殺,
											char *p徴兵,
											char *p一喝
											) {

	for ( int i=0; i < sizeof(_g基本コマンドリスト)/sizeof(_g基本コマンドリスト[0]); i++ ) {
		_g基本コマンドリスト[i] = "";
	} 
	try {
		カスタム駆動関数.On_基本コマンド表示直前《戦争画面》(武将番号);
	} catch(...) {
	}
	strncpy( p鼓舞,   _g基本コマンドリスト[ 0].c_str(), 19 );
	strncpy( p城外,   _g基本コマンドリスト[ 1].c_str(), 19 );
	strncpy( p退却,   _g基本コマンドリスト[ 2].c_str(), 19 );
	strncpy( p内応,   _g基本コマンドリスト[ 3].c_str(), 19 );
	strncpy( p技能,   _g基本コマンドリスト[ 4].c_str(), 19 );
	strncpy( p挑発,   _g基本コマンドリスト[ 5].c_str(), 19 );
	strncpy( p煽動,   _g基本コマンドリスト[ 6].c_str(), 19 );
	strncpy( p混乱,   _g基本コマンドリスト[ 7].c_str(), 19 );
	strncpy( p火攻め, _g基本コマンドリスト[ 8].c_str(), 19 );
	strncpy( p暗殺,   _g基本コマンドリスト[ 9].c_str(), 19 );
	strncpy( p徴兵,   _g基本コマンドリスト[10].c_str(), 19 );
	strncpy( p一喝,   _g基本コマンドリスト[11].c_str(), 19 );
}

// 戦闘による攻撃行動を選択した瞬間
void WINAPI snOnSelectingBattleAction(int 主体武将番号, int 客体武将番号, int 攻撃方法番号, void *パラメタ) {
	try {
		攻撃方法決定時パラメタ型 *p = (攻撃方法決定時パラメタ型*)パラメタ;

		int _正規済_攻撃方法番号 = 攻撃方法番号;
		// ScenarioMod内では鉄砲と弓の区別をつけておく
		if ( 攻撃方法番号 == 2 && ( p武将情報[主体武将番号].兵態 == 兵態::足軽 || p武将情報[主体武将番号].兵態 == 兵態::騎馬 ) ) {
			_正規済_攻撃方法番号 = 攻撃方法::弓;
		}

		攻撃方法決定時パラメタ型 パラメタ;
		パラメタ.攻撃方法番号 = _正規済_攻撃方法番号;
		パラメタ.移動前 = p->移動前;

		カスタム駆動関数.On_攻撃方法決定時《戦争画面》(主体武将番号+1, 客体武将番号+1, パラメタ);
	} catch (...) {
	}
}

// 主として戦闘によるダメージ
void WINAPI snOnBattleDamaged(int 武将番号, int ダメージ値, void *パラメタ) {
	try {
		カスタム駆動関数.On_被ダメージ時(武将番号, ダメージ値);
	} catch (...) {
	}
}



// 現在画面で戦場となっている、城番号をTSMODから受信。野戦の場合には、0xFFFFが入る。
extern int _現在攻城中の城番号;
void WINAPI snSetCurrentCastleIDInBattle(int 城番号) {
	_現在攻城中の城番号 = 城番号;
}


戦争開始パラメタ型 開始パラメタ;
void WINAPI snOnBattleStart(void *パラメタ) {
	戦争開始パラメタ型 *p = (戦争開始パラメタ型 *)(パラメタ);
	開始パラメタ.城番号 = p->城番号;
	開始パラメタ.守備側軍団【軍団番号】   = p->守備側軍団【軍団番号】;
	開始パラメタ.守備側軍団長【武将番号】 = p->守備側軍団長【武将番号】;
	開始パラメタ.攻撃側軍団【軍団番号】   = p->攻撃側軍団【軍団番号】;
	開始パラメタ.攻撃側軍団長【武将番号】 = p->攻撃側軍団長【武将番号】;

	try {
		カスタム駆動関数.On_戦争開始(開始パラメタ);
	} catch(...) {
	}
}

void WINAPI snOnChangeTurnInBattle(int 残りターン数) {
	try {
		カスタム駆動関数.On_残りターン変更《戦争画面》(残りターン数);
	} catch(...) {
	}
}

int WINAPI snOnCalcWeatherInBattle(int 予定天気, int 残りターン数) {
	int 新天気 = -1;
	try {
		// 新天気 = カスタム駆動関数.On_天気決定時《戦争画面》(予定天気, 残りターン数);
	}
	catch (...) {
	}
	return 新天気;
}

void WINAPI snOnChangeCastleTurnInBattle(int ターン数) {
	try {
		カスタム駆動関数.On_ターン変更《攻城中画面》(ターン数);
	} catch(...) {
	}
}

int WINAPI snOnChangeUnitMovePowerInBattle(int iBushouID, int iPrev, int iNext) {
	int iOverWriteNext = 1;
	try {
		iOverWriteNext = カスタム駆動関数.On_移動力残量変更時《戦争画面》(iBushouID + 1, iPrev, iNext);
	}
	catch (...) {
	}
	return iOverWriteNext;
}

void WINAPI snOnBattleScreenEnd() {
	try {
		カスタム駆動関数.On_戦争画面終了();
	}
	catch (...) {
	}
}
void WINAPI snOnBattleEnd() {
	try {
		カスタム駆動関数.On_戦争終了();
	} catch(...) {
	}
}

int WINAPI snOnRequestSoldierMax(int iBushouID, int iOrgSolMax, int iModSolMax) {
	int ret = -1;
	try {
		ret = カスタム駆動関数.On_武将最大兵数要求時(iBushouID+1, iOrgSolMax, iModSolMax);
	}
	catch (...) {
	}
	return ret;
}

void WINAPI snOnMainGameStart() {
	try {
		カスタム駆動関数.On_メインゲーム開始();
	} catch(...) {
	}
}

int WINAPI snOnSkippedRekishiBushou(int 武将番号配列用, int 登場済人数, int 待機武将データ数) {

	try {
		int isSkipp = カスタム駆動関数.On_待機武将登場直前(武将番号配列用 + 1, 登場済人数, 待機武将データ数);
		return isSkipp;
	}
	catch (...) {
	}

	return -1;
}

bool WINAPI snOnBornRekishiBushou(int 武将番号配列用) {

	try {
		カスタム駆動関数.On_待機武将登場直後(武将番号配列用 + 1);
	}
	catch (...) {
	}

	return true;
}

bool WINAPI snOnBornGeneralBushou(int 武将番号配列用) {

	try {
		カスタム駆動関数.On_仮想武将登場直後(武将番号配列用 + 1);
	}
	catch (...) {
	}

	return true;
}




bool WINAPI snOnViewingJobName(char *返信用バッファ, int 武将番号) {
	string 返信用職業名 = "";
	
	try {
		返信用職業名 = カスタム駆動関数.On_職業名表示直前(武将番号);
	} catch(...) {
	}

	if ( 返信用職業名.size() > 1 ) {
		strcpy( 返信用バッファ, 返信用職業名.c_str() );
		return true;
	}
	return false;

}

// 騎馬鉄砲と出るところの変更
bool WINAPI snOnViewingSpecialFormName(char *返信用バッファ, int 武将番号) {
	string 返信用特殊兵態名 = "";
	
	try {
		返信用特殊兵態名 = カスタム駆動関数.On_特殊兵態名表示直前(武将番号);
	} catch(...) {
	}

	if ( 返信用特殊兵態名.size() > 1 ) {
		strcpy( 返信用バッファ, 返信用特殊兵態名.c_str() );
		return true;
	}
	return false;
}

// 家宝種類名の出るところの変更
bool WINAPI snOnViewingKahouTypeName(char *返信用バッファ, int 家宝番号) {
	string 返信用家宝種類名 = "";
	
	try {
		返信用家宝種類名 = カスタム駆動関数.On_家宝種類名表示直前( 家宝番号, Get_家宝名(家宝番号-1) );
	} catch(...) {
	}

	if ( 返信用家宝種類名.size() > 1 ) {
		strcpy( 返信用バッファ, 返信用家宝種類名.c_str() );
		return true;
	}
	return false;
}


char g部隊名語尾書式[11] = "";

int WINAPI snOnViewingButaiName(int 武将番号) {

	strcpy(g部隊名語尾書式, "NULL"); // NULLはダミー文字。何も変化させないということ。

	char **p新部隊名 = NULL;
	try {
		p新部隊名 = カスタム駆動関数.On_部隊名表示直前(武将番号);
	} catch(...) {
	}
	
	if ( p新部隊名 ) {
		return (int)p新部隊名;
	} else {
		return NULL;
	}
}

int WINAPI snOnGettingButaimeiGobiSprintf(void *pSendParam, char *pBuf) {
	if (strcmp(g部隊名語尾書式, "NULL") == 0) {
		return FALSE;
	}
	else {
		strcpy(pBuf, g部隊名語尾書式);
		return TRUE;
	}
}

bool WINAPI snOnViewingPositionName(int *p返信ポインタ, int 武将番号, int 対象身分) {

	try {
		*p返信ポインタ = (int)カスタム駆動関数.On_身分名表示直前(武将番号, 対象身分);
	}
	catch (...) {
	}

	if (p返信ポインタ) {
		return true;
	}
	else {
		return false;
	}

}

bool WINAPI snOnViewingBushouStateName(int *p返信ポインタ, int 武将番号, int 対象状態) {

	try {
		*p返信ポインタ = (int)カスタム駆動関数.On_状態名表示直前(武将番号, 対象状態);
	}
	catch (...) {
	}

	if (p返信ポインタ) {
		return true;
	}
	else {
		return false;
	}

}

bool WINAPI snOnViewingIe(int 武将番号, char *p現在のバッファー) {

	string 新文字列 = "";
	try {
		新文字列 = カスタム駆動関数.On_家名表示直前(武将番号, string(p現在のバッファー));
	}
	catch (...) {
	}

	if (新文字列.length() > 0) {
		strncpy(p現在のバッファー, 新文字列.c_str(), 8); // 全角４文字がMAX
		p現在のバッファー[8] = NULL; // 番兵
		return true;
	}
	else {
		return false;
	}


}

void WINAPI snOnViewingRetsuden(int iBushouID, int iFaceID, char *szBufTitle, char *szBufDetail) {
	try {
		戦国武将列伝型 rt = カスタム駆動関数.On_戦国武将列伝要求時(iBushouID+1, iFaceID );
		if (rt._ラベル.size() > 0) {
			strncpy(szBufTitle, rt._ラベル.c_str(), 48);
			szBufTitle[49] = NULL;
		}
		if (rt._詳細.size() > 0) {
			strncpy(szBufDetail, rt._詳細.c_str(), 198);
			szBufDetail[199] = NULL;
		}
	} catch (...) {}
}


void WINAPI snOnViewingMeibutsuJiten(int iKahouID, char *szBufTitle, char *szBufDetail) {
	try {
		戦国名物事典型 rt = カスタム駆動関数.On_戦国名物事典要求時(iKahouID + 1);
		if (rt._ラベル.size() > 0) {
			strncpy(szBufTitle, rt._ラベル.c_str(), 48);
			szBufTitle[49] = NULL;
		}
		if (rt._詳細.size() > 0) {
			strncpy(szBufDetail, rt._詳細.c_str(), 198);
			szBufDetail[199] = NULL;
		}
	}
	catch (...) {}
}

void WINAPI snOnViewingMeijoMonogatari(int iCastleID, char *szBufTitle, char *szBufDetail) {
	try {
		戦国名城物語型 rt = カスタム駆動関数.On_戦国名城物語要求時(iCastleID + 1);
		if (rt._ラベル.size() > 0) {
			strncpy(szBufTitle, rt._ラベル.c_str(), 48);
			szBufTitle[49] = NULL;
		}
		if (rt._詳細.size() > 0) {
			strncpy(szBufDetail, rt._詳細.c_str(), 198);
			szBufDetail[199] = NULL;
		}
	}
	catch (...) {}
}


void WINAPI snOnRequestFullcolorFaceFileName(char* szOrgFileName, char* szDstFileName) {
	try {
		string ret = カスタム駆動関数.On_フルカラー顔グラファイル要求時(szOrgFileName);
		if (ret.size() > 0) {
			strncpy(szDstFileName, ret.c_str(), 98);
			szDstFileName[99] = NULL;
		}
	}
	catch (...) {}
}

extern 相場情報型 強制相場変更; // ScenarioMod内の今季の強制相場変更情報
void WINAPI snOnChangeSoba(相場情報型* 相場変更伝達ポインタ) {
	// 毎期変更した、してない情報をリセット。
	// Set_米相場などの中で、変更した項目に相場がそのまま入る。相場に０を入れたら、上書きしないということ。
	// デフォルトではここで０を入れるので、毎期のデフォルト挙動は相場を上書きしないということ。
	強制相場変更.米相場		= 0;
	強制相場変更.鉄砲相場	= 0;
	強制相場変更.馬相場		= 0;
	強制相場変更.兵相場		= 0;

	try {
		カスタム駆動関数.On_相場変更直前();
	} catch(...) {
	}

	// カスタム::On_相場変更直前に変更していたら、変更フラグ情報をTSModへと返す。
	相場変更伝達ポインタ->米相場	= 強制相場変更.米相場;
	相場変更伝達ポインタ->鉄砲相場	= 強制相場変更.鉄砲相場;
	相場変更伝達ポインタ->馬相場	= 強制相場変更.馬相場;
	相場変更伝達ポインタ->兵相場	= 強制相場変更.兵相場;
}

// ScenarioModと共有のエンディングダイアログの型
struct TEndingDialogInfo {
	int iDaimyoNo; // +1の方
	char szEndingTitle[20];
	char szEndingConditionRewriteMsg[100];
	int isNeverEnding;
	char szEndingMovieName[50];
};

BOOL WINAPI snOnEndingCondition(void *pBufReturn, int iDaimyoNo, int dummy2) {
	try {
		エンディング情報型 result = カスタム駆動関数.On_エンディング判定時(iDaimyoNo);
		if (result.大名番号 == NULL) {
			return NULL;
		}

		// 受け渡しのバッファーに値を格納
		((TEndingDialogInfo *)pBufReturn)->iDaimyoNo = result.大名番号;
		strncpy(((TEndingDialogInfo *)pBufReturn)->szEndingTitle, result.エンディングタイトル.c_str(), 14);
		((TEndingDialogInfo *)pBufReturn)->szEndingTitle[14] = NULL; // 番兵。全角で７文字、全部で16バイト。最悪でも最後バイトはNULLの必要あり。
		strncpy(((TEndingDialogInfo *)pBufReturn)->szEndingConditionRewriteMsg, result.エンディングメッセージ.c_str(), 42);
		((TEndingDialogInfo *)pBufReturn)->szEndingConditionRewriteMsg[42] = NULL; // 番兵。全角で21文字、全部で44バイト領域。最悪でも最後バイトはNULLの必要あり。
		((TEndingDialogInfo *)pBufReturn)->isNeverEnding = result.m_エンディング有効フラグ;

		// 書き換えたというフラグ
		return TRUE;
	}
	catch (...) {
	}

	return NULL;
}


void WINAPI snOnApplicationSelectMenuItem(int 選択メニュー番号) {
	try {
		カスタム駆動関数.On_アプリケーションメニュー選択時(選択メニュー番号);
	} catch(...) {
	}
}


void WINAPI snOnTick(int システム時刻, int 前回差分間隔) {
	try {
		カスタム駆動関数.On_チック(システム時刻, 前回差分間隔);
	} catch(...) {
	}
}