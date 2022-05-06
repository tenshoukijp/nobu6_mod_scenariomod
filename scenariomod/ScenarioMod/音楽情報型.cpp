#include <cassert>
#include "ゲームデータ構造.h"

#pragma comment(lib, "winmm.lib")

	//---------------------ＢＧＭ停止-------------------------
	int pCallFromFuncStopBGM = 0x48D483; // 元々TENSHOU.EXE内にあったCALL先

	void _FuncStopBGMAsm() {
		__asm {
			push eax
			push ebx
			push ecx
			push edx
			push esp
			push esi
			push edi
		}

		__asm {
			call pCallFromFuncStopBGM
		}

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}

	}


	//---------------------ＢＧＭ再生-------------------------
	#define GAMEDATASTRUCT_PLAYING_BGM_ID_ADDRESS	0x4D2A7C	// 再生中のBGMのIDのアドレス(WORD)

	int _pCallFromFuncPlayBGM = 0x48D3E9; // 元々TENSHOU.EXE内にあったCALL先

	int _iBgmIdFuncPlayBGM = -1;

	void _FuncPlayBGMAsm() {

		__asm {
			push 0x1  // 何なのかはわからん…ループフラグとかかな？

			push _iBgmIdFuncPlayBGM

			call _pCallFromFuncPlayBGM

			add esp, 8
		}

	}

namespace 関数 {

	// 指定のＢＧＭを再生する(この音楽番号は、神パッチで指定する番号と合致してると考えて良い[-1とかする必要がない])
	void 音楽再生(int 音楽番号) {

		// TSModや神パッチベースの番号→Tenshouki内部番号に直す。
		if ( 1 <= 音楽番号 && 音楽番号 < 0xFFFF ) {
			音楽番号--;
		}
		_iBgmIdFuncPlayBGM = 音楽番号;

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
		_FuncPlayBGMAsm();

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}

	}


	// ＢＧＭを停止する。
	void 音楽停止() {
		// TENSHOU.EXE内の関数呼び出し
		_FuncStopBGMAsm();
	}

	// 再生中のBGMのIDを得る。0xFFFFだと何も再生していない。
	int Get_再生音楽番号() {

		WORD *pBGMID = (WORD *)GAMEDATASTRUCT_PLAYING_BGM_ID_ADDRESS;
		// tenshouki内部番号→神パッチ番号に直す
		if ( 1 <= *pBGMID && *pBGMID != 0xFFFF ) {
			return (*pBGMID)+1;
		} else {
			return 0xFFFF;
		}

	}


	#define GAMEDATASTRUCT_WINMM_DLL_NAME_ADDRESS	0x4E7CC0	// WINMM.DLLか_INMM.DLLなのか。

	// _INMMモードか？
	bool Is_INMMモード() {

		char *winmm = (char *)GAMEDATASTRUCT_WINMM_DLL_NAME_ADDRESS;

		int mode = Get_ＴＳＭＯＤＩＮＩ設定("environment_bgm_mode");

		if ( strcmp( winmm, "_INMM.dll") == 0 ) {
			return true;
		} else if ( mode == 1 || mode == 2 ) {
			return true;
		}

		return false;
	}

}

