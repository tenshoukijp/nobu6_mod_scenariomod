#include <string>

#include "コマンド情報型.h"
#include "ゲームデータ構造.h"

using namespace std;
using namespace 関数;

extern HMODULE hModuleTSMod;

using PFNOGETTSMODTXTFLAG = int (WINAPI *)(char *szFlagName);
PFNOGETTSMODTXTFLAG p_GetTSModTxtFlag = NULL;

// TSModにしかない動画再生関数のポインタの登録
void _環境関数登録() {
	// 必要行動値を上書きする。
	p_GetTSModTxtFlag = (PFNOGETTSMODTXTFLAG)GetProcAddress( hModuleTSMod, "Extern_getTSModTxtFlag" );

}

namespace 関数 {

	int Get_ＴＳＭＯＤＩＮＩ設定(string フラグ名) {
		if ( p_GetTSModTxtFlag ) {
			return p_GetTSModTxtFlag((char *)フラグ名.c_str());
		}
		return -0xFFFF;
	}

}


