#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include "ゲームデータ構造.h"


extern HMODULE hModuleTSMod;


using PFNGETTAIKIBUSHOUAPPEARARRAYPOINTER = 待機武将情登場情報型* (cdecl *)();
PFNGETTAIKIBUSHOUAPPEARARRAYPOINTER p_Extern_GetTaikiBushouAppearArrayPointer = NULL;

using PFNGETTAIKIBUSHOUARRAYPOINTER = 待機武将情報型* (cdecl *)();
PFNGETTAIKIBUSHOUARRAYPOINTER p_Extern_GetTaikiBushouArrayPointer = NULL;

using PFNGETTAIKIBUSHOUNAMEARRAYPOINTER = 待機武将戸籍情報型* (cdecl *)();
PFNGETTAIKIBUSHOUNAMEARRAYPOINTER p_Extern_GetTaikiBushouNameArrayPointer = NULL;

// このデータに６つのシナリオの待機武将のデータバッファーをまるまるコピーしてあるので、好きなように扱って良い。TSModとは干渉しない。
// (taiki.n6pの展開データと同じ)
byte _待機武将データバッファー[6][(sizeof(待機武将情登場情報型) + sizeof(待機武将情報型) + sizeof(待機武将戸籍情報型)) * 1300] = { 0 }; // 本来は1000人弱しかデータとして詰め込むことが出来ないが、将来改造を達成する人が出るかもしれないので、多少余裕を持たせておく。
int _待機武将データ人数[6] = { 0 };


namespace 関数 {


	// 現在進行形のシナリオにおける、待機武将データ数を求める。
	int Get_待機武将登場済人数() {
#define GAMEDATASTRUCT_TOUZYOU_BUSHOU_NUM_ADDRESS       0x4CFC37    // 待機から登場した数
		WORD *pTouzyouBushouNum = (WORD *)GAMEDATASTRUCT_TOUZYOU_BUSHOU_NUM_ADDRESS;
		return *pTouzyouBushouNum;
	}


	// 現在市の矩形のシナリオにおいて、待機武将データ数のうち、すでに登場してしまった数
	int Get_待機武将データ数() {
#define GAMEDATASTRUCT_MITOUZYOU_BUSHOU_NUM_ADDRESS     0x4CFC39    // 未登場武将の総数数
		WORD *pMitouzyouBushouNum = (WORD *)GAMEDATASTRUCT_MITOUZYOU_BUSHOU_NUM_ADDRESS;
		return *pMitouzyouBushouNum;
	}

	待機武将情登場情報型 *Get_待機武将登場情報リスト() {
		int sno = Get_現在のシナリオ番号();
		if (1 <= sno && sno <= 最大数::シナリオ情報::配列数) {
			byte *p = _待機武将データバッファー[sno - 1];
			int add = 0;
			return (待機武将情登場情報型 *)(p + add);
		}

		return NULL;
	}

	待機武将情報型 *Get_待機武将情報リスト() {
		int sno = Get_現在のシナリオ番号();
		if (1 <= sno && sno <= 最大数::シナリオ情報::配列数) {
			byte *p = _待機武将データバッファー[sno - 1];
			int add = sizeof(待機武将情登場情報型) * Get_待機武将データ数(); // 武将登場情報部分をまるまるパスしたい。
			return (待機武将情報型 *)(p + add);
		}

		return NULL;
	}

	待機武将戸籍情報型 *Get_待機武将戸籍情報リスト() {
		int sno = Get_現在のシナリオ番号();
		if (1 <= sno && sno <= 最大数::シナリオ情報::配列数) {
			byte *p = _待機武将データバッファー[sno - 1];
			int add = (sizeof(待機武将情登場情報型) + sizeof(待機武将情報型)) * Get_待機武将データ数(); // 武将登場情報と武将情報部分をまるまるパスしたい。
			return (待機武将戸籍情報型 *)(p + add);
		}

		return NULL;
	}
}



