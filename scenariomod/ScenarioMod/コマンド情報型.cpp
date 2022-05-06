#define _CRT_SECURE_NO_WARNINGS

#include <string>

#include "コマンド情報型.h"
#include "ゲームデータ構造.h"

using namespace std;
using namespace 関数;

extern HMODULE hModuleTSMod;

using PFNOVERWRITENEEDKOUDOURYOKU = int(WINAPI *)(int 行動タイプ, int 行動値);
PFNOVERWRITENEEDKOUDOURYOKU p_OverWriteNeedKoudouryoku = NULL;

// TSModにしかない動画再生関数のポインタの登録
void _コマンド関数登録() {
	// 必要行動値を上書きする。
	p_OverWriteNeedKoudouryoku = (PFNOVERWRITENEEDKOUDOURYOKU)GetProcAddress( hModuleTSMod, "Extern_OverWriteNeedKoudouryoku" );
}



extern string _g戦闘コマンドリスト[];
extern string _g基本コマンドリスト[];


namespace 関数 {
	void Set_コマンド名( int コマンド名ＩＤ, string 新コマンドの文字列 ) {

		// 鼓舞よりも小さい番号ならば、それは戦闘コマンドだ
		if ( コマンド名ＩＤ < 戦争画面::基本コマンド名::鼓舞 ) {
			_g戦闘コマンドリスト[コマンド名ＩＤ] = 新コマンドの文字列;

		// 基本コマンドのリストだ
		} else {
			コマンド名ＩＤ -= 戦争画面::基本コマンド名::鼓舞; // 0オリジンとする。
			_g基本コマンドリスト[コマンド名ＩＤ] = 新コマンドの文字列;
		}
	}
}


/*
　各種行動に必要な値の設定。神パッチよりの移植。
 */



namespace 関数 {

void Set_コマンド行動力(int eコマンド行動力タイプ, int 行動力) {

	if ( p_OverWriteNeedKoudouryoku ) {
		p_OverWriteNeedKoudouryoku( eコマンド行動力タイプ, 行動力 );
	}
}

}






/*
0041C09A   . 57             PUSH    EDI					← 武将番号
0041C09B   . E8 198D0100    CALL    TENSHOU.00434DB9
0041C0A0   . 83C4 04        ADD     ESP, 4
*/

int pCallFromFuncDoTaikyakuInBattle = 0x434DB9; // 元々TENSHOU.EXE内にあったCALL先

int iBushouIDInFuncDoTaikyakuInBattle = 1L;    // 死亡武将ID

// メイン画面で指定の武将を殺害
void FuncDoTaikyakuInBattleAsm() {
	__asm {
		push iBushouIDInFuncDoTaikyakuInBattle
		call pCallFromFuncDoTaikyakuInBattle
		add esp, 0x4
	}
}


// メイン画面で指定の武将を殺害
namespace 関数 {
	int Do_コマンド《戦争画面》《退却》(int 武将番号【配列用】) {

		// 野戦ちゅうでもなく、かつ、攻城戦中でもないならば、ダメ
		if ( !Is_野戦中() && !Is_攻城戦中() ) {
			return false;
		}

		int iBushouID = 武将番号【配列用】;
		if ( 0 <= iBushouID && iBushouID < 最大数::武将情報::配列数 ) {

			// すでに戦死していたらダメ
			if ( p武将戸籍情報[iBushouID].戦死 ) {
				return false;
			}
			// すでに退却していたらダメ
			if ( p武将戸籍情報[iBushouID].退却 ) {
				return false;
			}

			// 関数用のやつは、1つ多いので、足しこみ
			iBushouIDInFuncDoTaikyakuInBattle = iBushouID+1;
		
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
			FuncDoTaikyakuInBattleAsm();

			__asm {
				pop edi
				pop esi
				pop esp
				pop edx
				pop ecx
				pop ebx
				pop eax
			}
			return true;
		}

		return false;
	}
}
