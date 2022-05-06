#define _CRT_SECURE_NO_WARNINGS

#include <string>

#include "コマンド情報型.h"
#include "ゲームデータ構造.h"

using namespace std;
using namespace 関数;

#define GAMEDATASTRUCT_SCENARIO_NAME_POINTER_ARRAY_ADDRESS		0x4D3728 // ６つのシナリオ名へのポインタ配列の先頭アドレス


extern HMODULE hModuleTSMod;

using PFNOGETCURSCENARIOLOCATION = int (WINAPI *)();
PFNOGETCURSCENARIOLOCATION p_getCurScenarioLocation = NULL;

// TSModにしかない動画再生関数のポインタの登録
void _シナリオ関数登録() {
	// 必要行動値を上書きする。
	p_getCurScenarioLocation = (PFNOGETCURSCENARIOLOCATION)GetProcAddress( hModuleTSMod, "Extern_getCurScenarioLocation" );
}

/*
004D3728  [E4 36 4D 00] [C4 36 4D 00] [A4 36 4D 00] [84 36 4D 00]  ・M.ﾄ6M.､6M.・M.
004D3738  [64 36 4D 00] [44 36 4D 00]                          d6M.D6M.
*/
namespace 関数 {

string Get_シナリオ名(int iシナリオ番号) {
	if ( 1 <= iシナリオ番号 && iシナリオ番号 <= 最大数::シナリオ情報::配列数 ) {
		int iLocation = iシナリオ番号-1;
		int *p = (int *)GAMEDATASTRUCT_SCENARIO_NAME_POINTER_ARRAY_ADDRESS;
		int iTargetAddress = *(p+iLocation);
		char *pTitle = (char *)iTargetAddress;
		string title = string(pTitle);
		return title;
	} else {
		return string("");
	}
}

int Get_現在のシナリオ番号() {
	if ( p_getCurScenarioLocation ) {
		int iLocation = p_getCurScenarioLocation();
		if ( 0 <= iLocation && iLocation < 最大数::シナリオ情報::配列数 ) {
			return iLocation+1;
		}
	}
	return -1;
}


}