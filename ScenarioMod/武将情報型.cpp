#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include "ゲームデータ構造.h"


extern HMODULE hModuleTSMod;


using PFNSETBUSHOUEXAPTITUDE = int (WINAPI *)(int 武将番号【配列用】, int 適性種類, int 適性値);
PFNSETBUSHOUEXAPTITUDE p_SetBushouExAptitude = NULL;

using PFNGETKAIKENIKOUAI	 = int (WINAPI *)(int 武将番号【配列用】);
PFNGETKAIKENIKOUAI p_GetKaikenIkouAI = NULL;

using PFNSETKAIKENIKOUAI	 = void (WINAPI *)(int 武将番号【配列用】, int 会見意向);
PFNSETKAIKENIKOUAI p_SetKaikenIkouAI = NULL;

using PFNGETCUSTOMSOLDIERMAX = int (WINAPI *)(int 武将番号【配列用】);
PFNGETCUSTOMSOLDIERMAX p_GetCustomSoldierMax = NULL;

using PFNGENERALABUSHOUBORNEXECUTE = int (WINAPI *)(int 強制顔番号);
PFNGENERALABUSHOUBORNEXECUTE p_GeneralABushouBornExecute = NULL;


// TSModにしかない動画再生関数のポインタの登録
void _武将関数登録() {
	// シナリオデータの引き出し用メソッドのポインタ確保
	p_SetBushouExAptitude = (PFNSETBUSHOUEXAPTITUDE)GetProcAddress( hModuleTSMod, "Extern_setBushouExAptitude" );

	// 会見意向取得
	p_GetKaikenIkouAI = (PFNGETKAIKENIKOUAI)GetProcAddress( hModuleTSMod, "Extern_getKaikenIkouAI" );

	// 会見意向取得
	p_SetKaikenIkouAI = (PFNSETKAIKENIKOUAI)GetProcAddress( hModuleTSMod, "Extern_setKaikenIkouAI" );

	// 対象武将の最大兵数(カスタムSoldierMAX)
	p_GetCustomSoldierMax = (PFNGETCUSTOMSOLDIERMAX)GetProcAddress( hModuleTSMod, "Extern_getCustomSoldierMax" );

	// 武将誕生
	p_GeneralABushouBornExecute = (PFNGENERALABUSHOUBORNEXECUTE)GetProcAddress( hModuleTSMod, "Extern_GeneralABushouBornExecute" );
}




//------------------必要勲功系配列
#define GAMEDATASTRUCT_REQUIREDMERITS_ADDRESS   0x4D1950    // [必要勲功値のアドレス]
/*
    必要勲功値
 */
struct NB6REQUIREDMERITS
{
	DWORD merits;
};
NB6REQUIREDMERITS   *const nb6requiredmerits = (NB6REQUIREDMERITS *)GAMEDATASTRUCT_REQUIREDMERITS_ADDRESS;




namespace 関数 {
	// 家宝などを含めない素の政治才能
	int Get_元最大政才(int iBushouID) {
		if (0 <= iBushouID && iBushouID < 最大数::武将情報::配列数) {
			int upparam = 0; // 上昇値
			for (int iKahouID = 0; iKahouID < 最大数::家宝情報::配列数; iKahouID++) {
				// 政治増加タイプ：0 茶碗  1 茶壺  2 茶入  3 茶釜  4 花入  
				if (家宝分類::茶碗 <= p家宝情報[iKahouID].家宝分類 && p家宝情報[iKahouID].家宝分類 <= 家宝分類::花入) {
					// 持ち主と指定武将が一致した
					if (p家宝情報[iKahouID].所有武将【武将番号】 == iBushouID + 1) {
						// 今までで最大の上昇値
						if (p家宝情報[iKahouID].上昇値 > upparam) {
							upparam = p家宝情報[iKahouID].上昇値;
						}
					}
				}
			}

			int maxgov = p武将情報[iBushouID].最大政才;
			return (maxgov - upparam) > 0 ? (maxgov - upparam) : 1;
		}
		else {
			return 0;
		}
	}

	// 家宝などを含めない素の戦闘才能
	int Get_元最大戦才(int iBushouID) {
		if (0 <= iBushouID && iBushouID < 最大数::武将情報::配列数) {
			int upparam = 0; // 上昇値
			for (int iKahouID = 0; iKahouID < 最大数::家宝情報::配列数; iKahouID++) {
				// 戦闘増加タイプ：5 刀剣  6 槍  7 具足  8 馬  9 鞍  A 陣羽織   
				if (家宝分類::刀剣 <= p家宝情報[iKahouID].家宝分類 && p家宝情報[iKahouID].家宝分類 <= 家宝分類::陣羽織) {
					// 持ち主と指定武将が一致した
					if (p家宝情報[iKahouID].所有武将【武将番号】 == iBushouID + 1) {
						// 今までで最大の上昇地
						if (p家宝情報[iKahouID].上昇値 > upparam) {
							upparam = p家宝情報[iKahouID].上昇値;
						}
					}
				}
			}

			int maxbat = p武将情報[iBushouID].最大戦才;
			return (maxbat - upparam) > 0 ? (maxbat - upparam) : 1;
		}
		else {
			return 0;
		}
	}

	// 家宝などを含めない素の智謀才能
	int Get_元最大智才(int iBushouID) {
		if (0 <= iBushouID && iBushouID < 最大数::武将情報::配列数) {
			int upparam = 0; // 上昇値
			for (int iKahouID = 0; iKahouID < 最大数::家宝情報::配列数; iKahouID++) {
				// 智謀増加タイプ：B 巻子本  C 明朝綴本
				if (家宝分類::巻子本 <= p家宝情報[iKahouID].家宝分類 && p家宝情報[iKahouID].家宝分類 <= 家宝分類::明朝綴本) {
					// 持ち主と指定武将が一致した
					if (p家宝情報[iKahouID].所有武将【武将番号】 == iBushouID + 1) {
						// 今までで最大の上昇地
						if (p家宝情報[iKahouID].上昇値 > upparam) {
							upparam = p家宝情報[iKahouID].上昇値;
						}
					}
				}
			}

			int maxint = p武将情報[iBushouID].最大智才;
			return (maxint - upparam) > 0 ? (maxint - upparam) : 1;
		}
		else {
			return 0;
		}
	}

	// 家宝などを含めない素の野望
	int Get_元野望(int iBushouID) {
		if (0 <= iBushouID && iBushouID < 最大数::武将情報::配列数) {
			int upparam = 0; // 上昇値
			for (int iKahouID = 0; iKahouID < 最大数::家宝情報::配列数; iKahouID++) {
				// 野望増加タイプ：D 香木  E 地球儀  F 南蛮時計  10 水墨画  11 十字架  12 聖書  13 玉手箱  14 ビードロ杯  15 遠眼鏡  16 ルソン壺  17 煙草
				if (家宝分類::香木 <= p家宝情報[iKahouID].家宝分類 && p家宝情報[iKahouID].家宝分類 <= 家宝分類::煙草) {
					// 持ち主と指定武将が一致した
					if (p家宝情報[iKahouID].所有武将【武将番号】 == iBushouID + 1) {
						// 今までで最大の上昇地
						if (p家宝情報[iKahouID].上昇値 > upparam) {
							upparam = p家宝情報[iKahouID].上昇値;
						}
					}
				}
			}

			int ambition = p武将情報[iBushouID].野望;
			return (ambition - upparam) > 0 ? (ambition - upparam) : 1;
		}
		else {
			return 0;
		}
	}

	// 官位などを含めない素の魅力
	int Get_元魅力(int iBushouID) {
		if (0 <= iBushouID && iBushouID < 最大数::武将情報::配列数) {
			int upparam = 0; // 上昇値
			for (int iKaniID = 0; iKaniID < 最大数::官位情報::配列数; iKaniID++) {
				// 持ち主と指定武将が一致した
				if (p官位情報[iKaniID].所有武将【武将番号】 == iBushouID + 1) {
					// 今までで最大の上昇地
					if (p官位情報[iKaniID].上昇値 > upparam) {
						upparam = p官位情報[iKaniID].上昇値;
					}
				}
			}

			int charm = p武将情報[iBushouID].魅力;
			return (charm - upparam) > 0 ? (charm - upparam) : 1;
		}
		else {
			return 0;
		}
	}



}



namespace 関数 {


// 鉄砲の適性を数値で取得する。(0=E,1=D,2=C,3=B,4=A,5=S  鉄砲適性::Ｓ ～ 鉄砲適性::Ｅ と比較すると良い)
int Get_鉄砲適性( int 武将番号【配列用】 ) {

	// 範囲チェック
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) { 

		// 鉄砲は２つのフィットフィールドに分かれてしまっているので、計算
		int 鉄砲適性値 = p武将情報[武将番号【配列用】]._鉄砲適性_lo << 2;
		鉄砲適性値 += p武将情報[武将番号【配列用】]._鉄砲適性_hi;
		return 鉄砲適性値;
	} else {
		デバッグ出力("武将番号【配列用】は範囲外");
		return -1;
	}
}

// 鉄砲の適性を数値で設定する。(0=E,1=D,2=C,3=B,4=A,5=S  鉄砲適性::Ｓ ～ 鉄砲適性::Ｅ で設定すると良い)
void Set_鉄砲適性( int 武将番号【配列用】, int 鉄砲適性値 ) {

	// 範囲チェック
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) { 

		// 範囲チェック
		if ( 鉄砲適性::Ｅ <= 鉄砲適性値 && 鉄砲適性値 <= 鉄砲適性::Ｓ) {
			// 鉄砲は２つのフィットフィールドに分かれてしまっているので、計算
			p武将情報[武将番号【配列用】]._鉄砲適性_hi = 鉄砲適性値 & 0x0003;  // 0b000000HH
			p武将情報[武将番号【配列用】]._鉄砲適性_lo = 鉄砲適性値 >> 2;	   // 0b00000L00
		} else {
			デバッグ出力("鉄砲適性値は範囲外");
		}
	} else {
		デバッグ出力("武将番号【配列用】は範囲外");
	}
}


// 弓の適性を数値で取得する。(0=E,1=D,2=C,3=B,4=A,5=S  弓適性::Ｓ ～ 弓適性::Ｅ と比較すると良い)
int Get_弓適性( int 武将番号【配列用】 ) {

	// 範囲チェック
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) {
		if ( p_SetBushouExAptitude ) {
			int 弓適性値 = p_SetBushouExAptitude( 武将番号【配列用】, 5, -1 ); // 5は弓(TSMod内), -1だったら値は設定せずに取得のみ。
			return 弓適性値;
		}
		return -1;
	} else {
		デバッグ出力("武将番号【配列用】は範囲外");
		return -1;
	}
}

// 弓の適性を数値で設定する。(0=E,1=D,2=C,3=B,4=A,5=S  弓適性::Ｓ ～ 弓適性::Ｅ で設定すると良い)
void Set_弓適性( int 武将番号【配列用】, int 弓適性値 ) {

	// 範囲チェック
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) {

		// 範囲チェック
		if ( 弓適性::Ｅ <= 弓適性値 && 弓適性値 <= 弓適性::Ｓ ) { 

			if ( p_SetBushouExAptitude ) {
				p_SetBushouExAptitude( 武将番号【配列用】, 5, 弓適性値); // 5は弓(TSMod内)
			}
		} else {
			デバッグ出力("弓適性値は範囲外");
		}
	} else {
		デバッグ出力("武将番号【配列用】は範囲外");
	}
}


// 槍の適性を数値で取得する。(0=E,1=D,2=C,3=B,4=A,5=S  槍適性::Ｓ ～ 槍適性::Ｅ と比較すると良い)
int Get_槍適性( int 武将番号【配列用】 ) {

	// 範囲チェック
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) {

		if ( p_SetBushouExAptitude ) {
			int 槍適性値 = p_SetBushouExAptitude( 武将番号【配列用】, 6, -1 ); // 6は槍(TSMod内), -1だったら値は設定せずに取得のみ。
			return 槍適性値;
		} else {
			return -1;
		}
	} else {
		デバッグ出力("武将番号【配列用】は範囲外");
		return -1;
	}
}

// 槍の適性を数値で設定する。(0=E,1=D,2=C,3=B,4=A,5=S  槍適性::Ｓ ～ 槍適性::Ｅ で設定すると良い)
void Set_槍適性( int 武将番号【配列用】, int 槍適性値 ) {

	// 範囲チェック
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) {

		// 範囲チェック
		if ( 槍適性::Ｅ <= 槍適性値 && 槍適性値 <= 槍適性::Ｓ ) {

			if ( p_SetBushouExAptitude ) {
				p_SetBushouExAptitude( 武将番号【配列用】, 6, 槍適性値); // 6は槍(TSMod内)
			}
		} else {
			デバッグ出力("槍適性値は範囲外");
		}
	} else {
		デバッグ出力("武将番号【配列用】は範囲外");
	}
}



// 鉄砲の適性を数値で取得する。
int Get_独立( int 武将番号【配列用】 ) {

	// 範囲チェック
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) { 

		// 独立は２つのフィットフィールドに分かれてしまっているので、計算
		int 独立値 = p武将情報[武将番号【配列用】]._独立_lo << 2;
		独立値 += p武将情報[武将番号【配列用】]._独立_hi;
		return 独立値;
	} else {
		デバッグ出力("武将番号【配列用】は範囲外");
		return -1;
	}
}

// 鉄砲の適性を数値で設定する
void Set_独立( int 武将番号【配列用】, int 独立値 ) {

	// 範囲チェック
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) { 

		// 独立は２つのフィットフィールドに分かれてしまっているので、計算
		p武将情報[武将番号【配列用】]._独立_hi = 独立値 & 0x0003;  // 0b000000HH
		p武将情報[武将番号【配列用】]._独立_lo = 独立値 >> 2;	   // 0b00000L00
	} else {
		デバッグ出力("武将番号【配列用】は範囲外");
	}
}


// 武将の政治値を取得する
int Get_政治値( int 武将番号【配列用】) {

	// 範囲チェック
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) { 

		return int(p武将情報[武将番号【配列用】].最大政才 * (float(p武将情報[武将番号【配列用】].政治熟練値) / float(2000)));
	} else {
		デバッグ出力("武将番号【配列用】は範囲外");
		return -1;
	}
}

// 武将の戦闘値を取得する
int Get_戦闘値( int 武将番号【配列用】) {

	// 範囲チェック
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) { 

		return int(p武将情報[武将番号【配列用】].最大戦才 * (float(p武将情報[武将番号【配列用】].戦闘熟練値) / float(2000)));
	} else {
		デバッグ出力("武将番号【配列用】は範囲外");
		return -1;
	}
}

// 武将の智謀値を取得する
int Get_智謀値( int 武将番号【配列用】) {

	// 範囲チェック
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) { 

		return int(p武将情報[武将番号【配列用】].最大智才 * (float(p武将情報[武将番号【配列用】].智謀熟練値) / float(2000)));
	} else {
		デバッグ出力("武将番号【配列用】は範囲外");
		return -1;
	}
}

// 武将の最大兵数を取得する
int Get_武将最大兵数(int 武将番号【配列用】) {

	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) { 
		if ( p_GetCustomSoldierMax ) {
			int 最大兵数 = p_GetCustomSoldierMax( 武将番号【配列用】);
			if ( 最大兵数 < 0 ) {
				return 0;
			} else {
				return 最大兵数;
			}
		} else {
			return 0;
		}
	} else {
		デバッグ出力("武将番号【配列用】は範囲外");
		return 0;
	}
}



// 武将の名字を取得する
string Get_名字( int 武将番号【配列用】) {

	// 範囲チェック
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) { 

		return string( p武将戸籍情報[武将番号【配列用】]._名字 );
	} else {
		return string("");
		デバッグ出力("武将番号【配列用】は範囲外");
	}
}

// 武将の名字を設定する
void   Set_名字( int 武将番号【配列用】, string 名字 ) {

	// 範囲チェック
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) { 

		strncpy( p武将戸籍情報[武将番号【配列用】]._名字, 名字.c_str(), 6 );
		p武将戸籍情報[武将番号【配列用】]._名字[6] = NULL;
	} else {
		デバッグ出力("武将番号【配列用】は範囲外");
	}
}

// 武将の名前を取得する
string Get_名前( int 武将番号【配列用】) {

	// 範囲チェック
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) { 

		return string( p武将戸籍情報[武将番号【配列用】]._名前 );
	} else {
		return string("");
		デバッグ出力("武将番号【配列用】は範囲外");
	}
}


// 武将の名前を設定する
void   Set_名前( int 武将番号【配列用】, string 名前 ) {

	// 範囲チェック
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) { 

		strncpy_s( p武将戸籍情報[武将番号【配列用】]._名前, 名前.c_str(), 6 );
		p武将戸籍情報[武将番号【配列用】]._名前[6] = NULL;
	} else {
		デバッグ出力("武将番号【配列用】は範囲外");
	}
}


}

// ゲームで元々用意されているランダムな姫名を得る。
// 
#define GAMEDATASTRUCT_HIMENAME_ARRAY			0x4CA9B0	// 姫名が羅列されている場所。1人7バイト。(全角3文字＋NULL)で100人分。
struct _HIME_NAME {
	char name[7];
};

namespace 関数 {

string Get_ランダム姫名前() {
	// 姫ポインタの位置
	_HIME_NAME *pHName = (_HIME_NAME *)GAMEDATASTRUCT_HIMENAME_ARRAY;
	int iRnd = rand() % 100; // 100人用意されている。
	return pHName[iRnd].name;
}


/* 
 * 武将の顔番号から武将番号を取得する。存在しない場合は、｢0xFFFF｣が返ってくる。
 */
WORD Get_武将番号【配列用】(int 顔番号) {

	// 顔番号の範囲チェックはあえてしない。KaoSwapExなどがあるため。
	for (int 武将番号【配列用】=0; 武将番号【配列用】 < 最大数::武将情報::配列数; 武将番号【配列用】++ ) {
		if ( p武将戸籍情報[武将番号【配列用】].顔番号 == 顔番号 ) {
			return 武将番号【配列用】;
		}
	}

	return 0xFFFF;
}

/* 
 * 武将の姓名から武将番号を取得する。存在しない場合は、｢0xFFFF｣が返ってくる。
 */
WORD Get_武将番号【配列用】(string 武将姓名) {

	// 顔番号の範囲チェックはあえてしない。KaoSwapExなどがあるため。

	for (int 武将番号【配列用】=0; 武将番号【配列用】 < 最大数::武将情報::配列数; 武将番号【配列用】++ ) {
		if ( 武将姓名 == Get_名字(武将番号【配列用】)+Get_名前(武将番号【配列用】)) {
			return 武将番号【配列用】;
		}
	}

	return 0xFFFF;
}

/*
 * 武将の年齢を得る。
 */
int Get_武将年齢(int 武将番号【配列用】) {
	// 範囲チェック
	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) {
		return p年情報.年 - p武将情報[武将番号【配列用】].生年 + 1;
	}
	デバッグ出力("武将番号【配列用】は範囲外");
	return 0xFF;
}

/*
 * 武将の年齢を設定する。
 */
bool Set_武将年齢(int 武将番号【配列用】, int 年齢) {

	// 範囲チェック
	if (0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数) {

		int check = p年情報.年 + 1 - 年齢;
		if (check < 0) {
			デバッグ出力("年齢は範囲外。誕生年が結果として、天翔記基準年(1454)より早い生まれとなってしまっている。");
			check = 0;
		}
		if (check > 255) {
			デバッグ出力("年齢は範囲外。誕生年が結果として、天翔記最終年(1708)より遅い生まれとなってしまっている。");
			check = 255;
		}
		p武将情報[武将番号【配列用】].生年 = check;
		return TRUE;
	}
	else {
		デバッグ出力("武将番号【配列用】は範囲外");
		return FALSE;
	}
}



// 指定武将の伴侶のiBushouIDを得る。伴侶が居ない場合には、0xFFFFが返ってくる。
int Get_伴侶武将番号【配列用】(int 武将番号【配列用】) {

	if ( 0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数 ) {

		int iBushouID = 武将番号【配列用】;

		// 指定の武将の伴侶情報
		int iBushouIDSpouse = p武将情報[iBushouID]._妻; //

		// 結婚していない
		if ( iBushouIDSpouse == 0xFF ) {
			return 0xFFFF;
		}

		int iTsumaBushouID = iBushouIDSpouse+500;

		// 伴侶の番号が自分自身だったら、自分は妻側の立場
		if ( iTsumaBushouID == iBushouID ) {
			for ( int i=0; i<最大数::武将情報::配列数; i++ ) {
				// 自分自身以外で、同じ伴侶番号を持ってるのが、伴侶の武将
				if ( i != iBushouID &&  p武将情報[i]._妻 == iBushouIDSpouse ) {
					return i;
				}
			}
			return 0xFFFF;

		// 自分は夫側。妻にも同じ番号が設定されているか確認。
		} else {
			if ( p武将情報[iTsumaBushouID]._妻 == iBushouIDSpouse ) {
				return iTsumaBushouID;
			// なぜか設定されていない…。改造等でデータ壊れている。
			} else {
				return 0xFFFF;
			}
		}
	
	} else {
		デバッグ出力("武将番号【配列用】は範囲外");
		return 0xFFFF;
	}
}

// 姫(他の武将の妻含む)を、指定の武将と結婚させる、同盟関係等は一切操作されない。
bool Set_姫結婚( int 姫武将番号【配列用】, int 夫武将番号【配列用】, BOOL 天蓋孤独死亡処理 ) {
	int iOttoID = 夫武将番号【配列用】;
	int iHimeID = 姫武将番号【配列用】;

	// 同一人物。アウト。
	if ( iHimeID == iOttoID ) { return false; }

	// 夫と姫が規定の範囲に入っていなければアウト
	if (   0 <= iOttoID && iOttoID < 最大数::武将情報::配列数 &&
		 500 <= iHimeID && iHimeID < 最大数::武将情報::配列数) {

		// もし姫側のＩＤの武将が、姫でないならば、アウト
		if ( p武将戸籍情報[iHimeID].状態 != 状態::姫 ) {
			return false;
		}

		// 身が綺麗になったので、改めて結婚
		int _新妻値 = iHimeID-500; // 妻に入るべき値は、姫武将番号【配列用】-500

		// すでに両者は夫婦である、何もする必要が無い。
		if ( p武将情報[iOttoID]._妻 == _新妻値 &&  p武将情報[iHimeID]._妻 == _新妻値 ) {
			return true;
		}

		// 夫側がすでに結婚しているか、結婚していたら離婚
		int _夫側妻値 = p武将情報[iOttoID]._妻; //
		Set_姫離婚( _夫側妻値+500, 天蓋孤独死亡処理 );

		p武将戸籍情報[iHimeID].状態 = 状態::姫; // 天蓋孤独処理で死亡したかもしれないので姫に戻す。

		int _妻側妻値 = p武将情報[iHimeID]._妻; //
		Set_姫離婚( _妻側妻値+500, 天蓋孤独死亡処理 );

		p武将戸籍情報[iHimeID].状態 = 状態::姫; // 天蓋孤独処理で死亡したかもしれないので姫に戻す。

		// 身が綺麗になったので改めて結婚
		p武将情報[iOttoID]._妻 = _新妻値;
		p武将情報[iHimeID]._妻 = _新妻値;

		// 旧大名家を覚えておいて
		int 旧DaimyoID = p武将情報[iHimeID].所属大名【大名番号】;

		// 夫側の大名の方に身を寄せる
		p武将情報[iHimeID].所属大名【大名番号】 = p武将情報[iOttoID].所属大名【大名番号】;
		Set_名字(iHimeID, Get_名字(iOttoID) );

		// 結果、大名家が変化したのであれば、士官年数もリセット
		if ( 旧DaimyoID != p武将情報[iHimeID].所属大名【大名番号】) {
			p武将情報[iHimeID].仕官年数 = 0;
		}

		return true;
	}

	return false;
}


// 指定の姫を離婚させる。
bool Set_姫離婚( int 姫武将番号【配列用】, BOOL 天蓋孤独死亡処理 ) {
	int iHimeID = 姫武将番号【配列用】;

	// 夫と姫が規定の範囲に入っていなければアウト
	if ( 500 <= iHimeID && iHimeID < 最大数::武将情報::配列数 ) {


		// もし姫側のＩＤの武将が、姫でないならば、アウト
		if ( p武将戸籍情報[iHimeID].状態 != 状態::姫 ) {
			return false;
		}

		int _妻値 = p武将情報[iHimeID]._妻; //

		// 元々結婚していない。
		if ( _妻値 == 0xFF ) {
			return false;
		}

		// 両者の結婚情報をクリア
		for ( int iBushouID=0; iBushouID < 最大数::武将情報::配列数; iBushouID++ ) {
			// 夫もしくは妻である
			if ( p武将情報[iBushouID]._妻 == _妻値 ) {
				// 離婚
				p武将情報[iBushouID]._妻 = 0xFF;
				// 夫と妻2人両方とも値を0xFFにする必要があるので、breakしないこと。
				// ついでにデータにゴミが入っている場合でもクリア
			}
		}


		// 旧大名家を覚えておいて
		int 旧DaimyoID = p武将情報[iHimeID].所属大名【大名番号】;

		// 以下の身元引受人系の処理は、プログラム側で出来るだけやっておこうという趣旨。
		// 仮にここで適切な大名に帰属転移できなかったとしても、天翔記のプログラム本体が次季節時には、適切な大名に帰属させる処理を行う。

		// 離婚したので所属大名を変更する必要性がある。まず、親が大名をしているかどうか。
		for ( int iBushouID=0; iBushouID < 最大数::武将情報::配列数; iBushouID++ ) {

			// 大名のうち…
			if ( p武将戸籍情報[iBushouID].状態 == 状態::大名 ) {

				// 自分の親が大名やってる。
				if ( p武将情報[iHimeID].親顔番号 < 5000 ) {
					if ( p武将戸籍情報[iBushouID].顔番号 == p武将情報[iHimeID].親顔番号 ) {

						// そこに身を寄せる
						p武将情報[iHimeID].所属大名【大名番号】 = p武将情報[iBushouID].所属大名【大名番号】;
						Set_名字(iHimeID, Get_名字(iBushouID) );
						break;
					}
				}
			}
		}

		// 親が大名をやっていなくとも、親が同じ人(即ち兄弟姉妹)が大名をやっているかどうか。
		for ( int iBushouID=0; iBushouID < 最大数::武将情報::配列数; iBushouID++ ) {

			// 大名のうち…
			if ( p武将戸籍情報[iBushouID].状態 == 状態::大名 ) {

				// 親が同じだ。
				if ( p武将情報[iHimeID].親顔番号 < 5000 ) {
					if ( p武将情報[iBushouID].親顔番号 == p武将情報[iHimeID].親顔番号 ) {

						// そこに身を寄せる
						p武将情報[iHimeID].所属大名【大名番号】 = p武将情報[iBushouID].所属大名【大名番号】;
						Set_名字(iHimeID, Get_名字(iBushouID) );
						break;
					}
				}
			}
		}

		// 親兄弟が大名やっていなくても、一門が大名をやっているのではないか。
		for ( int iBushouID=0; iBushouID < 最大数::武将情報::配列数; iBushouID++ ) {

			// 大名のうち…
			if ( p武将戸籍情報[iBushouID].状態 == 状態::大名 ) {

				// 親が同じだ。
				if ( p武将情報[iHimeID].所属血筋 != 0xFF ) {
					if ( p武将情報[iBushouID].所属血筋 == p武将情報[iHimeID].所属血筋 ) {

						// そこに身を寄せる
						p武将情報[iHimeID].所属大名【大名番号】 = p武将情報[iBushouID].所属大名【大名番号】;
						Set_名字(iHimeID, Get_名字(iBushouID) );
						break;
					}
				}
			}
		}

		bool is天蓋孤独 = true;
		// 大名でなくとも、親がどこかにいるのではないか？
		for ( int iBushouID=0; iBushouID < 最大数::武将情報::配列数; iBushouID++ ) {

			// 自分の親
			if ( p武将情報[iHimeID].親顔番号 < 5000 ) {
				if ( p武将戸籍情報[iBushouID].顔番号 == p武将情報[iHimeID].親顔番号 ) {

					// そこに身を寄せる
					p武将情報[iHimeID].所属大名【大名番号】 = p武将情報[iBushouID].所属大名【大名番号】;
					Set_名字(iHimeID, Get_名字(iBushouID) );
					is天蓋孤独 = false;
					break;
				}
			}
		}

		// 大名でなくとも、親が同じ人(即ち兄弟姉妹)がどこかにいるのではないか？
		for ( int iBushouID=0; iBushouID < 最大数::武将情報::配列数; iBushouID++ ) {

			// 親が同じだ。
			if ( p武将情報[iHimeID].親顔番号 < 5000 ) {
				if ( p武将情報[iBushouID].親顔番号 == p武将情報[iHimeID].親顔番号 ) {

					// そこに身を寄せる
					p武将情報[iHimeID].所属大名【大名番号】 = p武将情報[iBushouID].所属大名【大名番号】;
					Set_名字(iHimeID, Get_名字(iBushouID) );
					is天蓋孤独 = false;
					break;
				}
			}
		}


		// 結果、大名家が変化したのであれば、士官年数もリセット
		if ( 旧DaimyoID != p武将情報[iHimeID].所属大名【大名番号】) {
			p武将情報[iHimeID].仕官年数 = 0;
		}

		if ( 天蓋孤独死亡処理 ) {
			if ( is天蓋孤独 ) {
				p武将戸籍情報[iHimeID].状態 = 状態::死亡;
			}
		}

		return true;
	}

	return false;
}



bool Set_武将状態《現役→浪人》(int 武将番号【配列用】) {

	int iBushouID = 武将番号【配列用】;

	if ( 0 <= iBushouID && iBushouID < 最大数::武将情報::配列数 ) {

		if ( p武将戸籍情報[iBushouID].状態 == 状態::現役 ) { // 現役武将の場合だけ処理をする。

			// 該当武将の居城がちゃんとした情報が格納されている。(ユーザー改造等によって壊れていない)
			int iCastleID = p武将情報[iBushouID].所属居城【城番号】-1;
			if (0 <= iCastleID && iCastleID <  最大数::城情報::配列数 ) {

				if ( p城情報[iCastleID].城主【武将番号】 == 0xFFFF ) { return false; } // リンクリストが壊れているのか城に誰も所属していない。何もしない。return;

				// メモリ上の値変更
				{
					p武将戸籍情報[iBushouID].状態 = 状態::浪人; // 状態を浪人とする。

					p武将戸籍情報[iBushouID].身分 = 身分::足軽頭; // 身分を足軽とする。

					p武将情報[iBushouID].所属大名【大名番号】 = 0xFFFF; // 大名に所属しない。
					p武将情報[iBushouID].所属軍団【軍団番号】 = 0xFFFF; // 軍団に所属しない。
					p武将情報[iBushouID].忠誠 = 50; // 忠誠を50とする。
					p武将情報[iBushouID].仕官年数 = 0; // 士官年数を0とする。

					p武将情報[iBushouID].内応先大名【大名番号】 = 0xFFFF; // 内応先をなしとする。
					p武将情報[iBushouID].内応状態 = 0; // 内応なし。

					p武将情報[iBushouID].兵数 = 0; // 兵数を0とする。
					p武将情報[iBushouID].訓練 = 0; // 訓練を0とする。
					p武将情報[iBushouID].士気 = 0; // 兵忠を0とする。
					p武将情報[iBushouID].兵態 = 兵態::足軽; // 足軽とする。

					// 勲功リセットしないモードだと、勲功が７割残る
					if ( Get_ＴＳＭＯＤＩＮＩ設定("all_bushou_non_meritorious_reset") > 0 ) {
						p武将情報[iBushouID].勲功 = (WORD)(p武将情報[iBushouID].勲功 * 0.7); 

					// デフォルトだと勲功は０
					} else {
						p武将情報[iBushouID].勲功 = 0; // 勲功を0とする。
					}
				}

				/*城情報の武将リス路

				　 　自分
				   ↓
				   ○-●-○-○

				   というのを

				   ○-○-○

				   とする。
				   */

				int iPrevID = p武将情報[iBushouID].前の武将【武将番号】;
				int iNextID = p武将情報[iBushouID].次の武将【武将番号】;

				// 浪人にしたい武将は、いま城主だ
				if ( p城情報[iCastleID].城主【武将番号】-1 == iBushouID ) {
					p城情報[iCastleID].城主【武将番号】 =  iNextID; // 自分のnextを城主にする。
				}

				// 自分のprevは有効な武将だ。
				if ( 0 < iPrevID && iPrevID <= 最大数::武将情報::配列数 ) {

					// 自分が城主ではない武将で、
					// １つ前の人の次のリンク先が自分自身の場合
					if ( iPrevID != 0xFFFF && p武将情報[(iPrevID-1)].次の武将【武将番号】 == iBushouID+1 ) {
						// 自分ではなく、次の人へと繋ぎかえる。
						p武将情報[(iPrevID-1)].次の武将【武将番号】 = iNextID;
					}
				}

				// 自分のnextは有効な武将だ。
				if ( 0 < iNextID && iNextID <= 最大数::武将情報::配列数 ) {
					// １つ後の人の前のリンク先が自分自身の場合
					if ( iNextID != 0xFFFF && p武将情報[(iNextID-1)].前の武将【武将番号】 == iBushouID+1 ) {
						// 自分ではなく、前の人へと繋ぎかえる。
						p武将情報[(iNextID-1)].前の武将【武将番号】 = iPrevID;
					}
				}


				/* 城情報の浪人リスト　

				○-○

				というのを

				●-○-○

				とする。
				*/

				// 浪人としてみなした時、自分のnextは、現在浪人リストの先頭の人
				int iRonin = p城情報[iCastleID]._浪人先頭武将【武将番号】;
				p武将情報[iBushouID].次の武将【武将番号】 = iRonin; // 現在の先頭の人を自分の次の人に

				// nextが有効な武将ならば…
				if ( 0 < iRonin && iRonin <= 最大数::武将情報::配列数 ) {
					// 次の人のprevを自分に
					p武将情報[iRonin-1].前の武将【武将番号】 = iBushouID+1;
				}
				p武将情報[iBushouID].前の武将【武将番号】 = 0xFFFF; // prevは居ない

				p城情報[iCastleID]._浪人先頭武将【武将番号】 = iBushouID+1; // 城の浪人の先頭を自分にする。

				return true;
			}
		}
	}

	return false;
}




bool Set_武将状態《浪人→現役》(int 武将番号【配列用】) {

	int iBushouID = 武将番号【配列用】;

	if ( 0 <= iBushouID && iBushouID < 最大数::武将情報::配列数 ) {
		if ( p武将戸籍情報[iBushouID].状態 == 状態::浪人 ) { // 浪人武将の場合だけ処理をする。

			// 該当武将の居城がちゃんとした情報が格納されている。(ユーザー改造等によって壊れていない)
			int iCastleID = p武将情報[iBushouID].所属居城【城番号】-1;
			if (0 <= iCastleID && iCastleID <  最大数::城情報::配列数 ) {

				if ( p城情報[iCastleID]._浪人先頭武将【武将番号】 == 0xFFFF ) { return false; } // リンクリストが壊れているのか浪人が誰も居ないことになっちゃってる。何もしない。return;
				if ( p城情報[iCastleID].所属軍団【軍団番号】 == 0xFFFF ) { return false; } // 該当の城がどこの軍団にも所属していない場合、浪人を現役とは出来ない。
																		       // なぜなら、それは大名化することを意味するから。

				// 以降、軍団帰属、大名帰属ができないならば、falseを返す。
				int iAttachGundanID = p城情報[iCastleID].所属軍団【軍団番号】-1;
				int iAttachDaimyoID = -1;
				if ( 0 <= iAttachGundanID && iAttachGundanID < 最大数::軍団情報::配列数 ) {
					iAttachDaimyoID = p軍団情報[iAttachGundanID].所属大名【大名番号】 - 1;
				} else {
					return false;
				}
				if ( ! (0 <= iAttachDaimyoID && iAttachDaimyoID < 最大数::大名情報::配列数 ) ) {
					return false;
				}

				// 現在の城の城主から、リンクリストを辿っていく
				int iLinkEndBusyouID = p城情報[iCastleID].城主【武将番号】;
				int iSafetyCnt = 0;
				while ( true ) {
					// セーフティカウントが暴走している。(ユーザーによって、すでにリンクリストが勝手に操作され、壊されている)
					if ( iSafetyCnt > 最大数::武将情報::配列数 ) { 
						return false;
					}

					// 城主が居ないならば、終わり
					if ( iLinkEndBusyouID == 0xFFFF ) {
						break;
					}

					// 現在の武将の、nextが有効ではなければ、現在の武将が最後の人。終わり。
					if ( p武将情報[iLinkEndBusyouID-1].次の武将【武将番号】 == 0xFFFF ) {
						break;

					// 現在の人が有効である。
					} else {
						// リンクリストを次の人とする。
						if ( 0 < iLinkEndBusyouID && iLinkEndBusyouID <= 最大数::武将情報::配列数 ) {
							iLinkEndBusyouID = p武将情報[iLinkEndBusyouID-1].次の武将【武将番号】;
						}
					}
				}

				// メモリ上の値変更
				{
					p武将戸籍情報[iBushouID].状態 = 状態::現役; // 状態を現役とする。
						
					p武将情報[iBushouID].所属大名【大名番号】 = iAttachDaimyoID+1; // 大名に所属する。
					p武将情報[iBushouID].所属軍団【軍団番号】 = iAttachGundanID+1; // 軍団に所属する。
					p武将情報[iBushouID].忠誠 = 50; // 忠誠を50とする。
					p武将情報[iBushouID].仕官年数 = 0; // 士官年数を0とする。

					p武将情報[iBushouID].内応先大名【大名番号】 = 0xFFFF; // 内応先をなしとする。
					p武将情報[iBushouID].内応状態 = 0; // 内応なし。

					p武将情報[iBushouID].兵数 = 0; // 兵数を0とする。
					p武将情報[iBushouID].訓練 = 0; // 訓練を0とする。
					p武将情報[iBushouID].士気 = 0; // 兵忠を0とする。
					p武将情報[iBushouID].兵態 = 兵態::足軽; // 足軽とする。


					//------------------------------------------------------
					// 勲功リセットしないモードだと、残り勲功に合わせて昇進
					if ( Get_ＴＳＭＯＤＩＮＩ設定("all_bushou_non_meritorious_reset") > 0 ) {

						if (p武将情報[iBushouID].勲功 >= nb6requiredmerits[0].merits ) { // 宿老級勲功を持つ。
							p武将戸籍情報[iBushouID].身分 = 身分::宿老;
						} else if ( p武将情報[iBushouID].勲功 >= nb6requiredmerits[1].merits ) { // 家老級勲功を持つ。
							p武将戸籍情報[iBushouID].身分 = 身分::家老;
						} else if ( p武将情報[iBushouID].勲功 >= nb6requiredmerits[2].merits ) { // 部将級勲功を持つ。
							p武将戸籍情報[iBushouID].身分 = 身分::部将;
						} else if ( p武将情報[iBushouID].勲功 >= nb6requiredmerits[3].merits ) { // 侍大将級勲功を持つ。
							p武将戸籍情報[iBushouID].身分 = 身分::侍大将;
						}
					// デフォルトだと足軽
					} else {
						p武将戸籍情報[iBushouID].身分 = 身分::足軽頭; // 身分を足軽とする。
					}


				}

				/* 　自分
				      ↓
				   ○-●-○-○

				   というのを

				   ○-○-○

				   とする。
				*/

				int iPrevID = p武将情報[iBushouID].前の武将【武将番号】;
				int iNextID = p武将情報[iBushouID].次の武将【武将番号】;

				// 現役にしたい武将は、いま浪人リストの先頭だ
				if ( p城情報[iCastleID]._浪人先頭武将【武将番号】-1 == iBushouID ) {
					p城情報[iCastleID]._浪人先頭武将【武将番号】 =  iNextID; // 自分のnextを城主にする。
				}

				// 自分のprevは有効な武将だ。
				if ( 0 < iPrevID && iPrevID <= 最大数::武将情報::配列数 ) {

					// 自分が先頭ではない武将で、
					// １つ前の人の次のリンク先が自分自身の場合
					if ( iPrevID != 0xFFFF && p武将情報[(iPrevID-1)].次の武将【武将番号】 == iBushouID+1 ) {
						// 自分ではなく、次の人へと繋ぎかえる。
						p武将情報[(iPrevID-1)].次の武将【武将番号】 = iNextID;
					}
				}

				// 自分のnextは有効な武将だ。
				if ( 0 < iNextID && iNextID <= 最大数::武将情報::配列数 ) {
					// １つ後の人の前のリンク先が自分自身の場合
					if ( iNextID != 0xFFFF && p武将情報[(iNextID-1)].前の武将【武将番号】 == iBushouID+1 ) {
						// 自分ではなく、前の人へと繋ぎかえる。
						p武将情報[(iNextID-1)].前の武将【武将番号】 = iPrevID;
					}
				}


				/* 　
				     
				   ○-○

				   というのを

				   ○-○-●

				   とする。
				*/


				// 自分は現役として、武将リストの一番最後にくっつく。自分のnextは居ない
				p武将情報[iBushouID].次の武将【武将番号】 = 0xFFFF; // 

				// もし自分は、現役になるとともに、城主にもなるべきならば…
				if ( iLinkEndBusyouID == 0xFFFF ) {
					p武将情報[iBushouID].前の武将【武将番号】 = 0xFFFF; // 自分の前の人は居ない

					p城情報[iCastleID].城主【武将番号】 = iBushouID+1; // 城主は自分

				// 武将リンクリストの一番最後にぶら下がるべき。
				} else {

					p武将情報[iLinkEndBusyouID-1].次の武将【武将番号】 = iBushouID+1; // リンクリストの最後のnextを自分に

					p武将情報[iBushouID].前の武将【武将番号】 = iLinkEndBusyouID; // 自分の前の人は、城のリンクリストの最後の人物
				}
				return true;

			}
		}
	}

	return false;
}

} // namespace 



int pCallFromFuncDoDeathInMain = 0x40B962; // 元々TENSHOU.EXE内にあったCALL先

int iBushouIDInFuncDoDeathInMain = 1L;    // 死亡武将ID

// メイン画面で指定の武将を殺害
void FuncDoDeathInMainAsm() {
	__asm {
		mov esi, iBushouIDInFuncDoDeathInMain
		push iBushouIDInFuncDoDeathInMain
		call pCallFromFuncDoDeathInMain
		add esp, 0x4
	}
}


int pCallFromFuncDoDeathInBattle = 0x430A75; // 元々TENSHOU.EXE内にあったCALL先。Unit系情報修正
int pCallFromFuncDoDeathInBattle2 = 0x40A352; // 元々TENSHOU.EXE内にあったCALL先。メイン系で戦場戦死フラグを立てたり

int iKilledBushouIDInFuncDoDeathInBattle = 1L;    // 殺される武将ID
int iCriminalBushouIDInFuncDoDeathInBattle = 1L;    // 犯人の武将ID

// 戦闘画面で指定の武将を殺害
void FuncDoDeathInBattleAsm() {
	__asm {
		push 0x2
		push iCriminalBushouIDInFuncDoDeathInBattle
		push iKilledBushouIDInFuncDoDeathInBattle
		call pCallFromFuncDoDeathInBattle
		add esp, 0xC

		push 0x400
		push iKilledBushouIDInFuncDoDeathInBattle
		call pCallFromFuncDoDeathInBattle2
		add esp, 0x8
	}
}



namespace 関数 {

bool Set_武将状態《→死亡》(int 死亡武将番号【配列用】, int 犯人武将番号【配列用】) {

	int iKilledBushouID = 死亡武将番号【配列用】;
	int iCriminalBushouID = 犯人武将番号【配列用】;

	// 犯人を指定しなければ、自殺ということにする。
	if ( iCriminalBushouID == -1 ) {
		iCriminalBushouID = iKilledBushouID;	
	}

	if ( 0 <= iKilledBushouID && iKilledBushouID < 最大数::武将情報::配列数 && 0 <= iCriminalBushouID && iCriminalBushouID < 最大数::武将情報::配列数  ) {
		if ( Is_野戦中() || Is_攻城戦中() ) {

			// すでに戦死していたら何もしない
			if ( p武将戸籍情報[iKilledBushouID].戦死 ) {
				return false;
			}

			// 関数用のやつは、1つ多いので、足しこみ
			iKilledBushouIDInFuncDoDeathInBattle = iKilledBushouID+1;		// 殺される側の武将ID
			iCriminalBushouIDInFuncDoDeathInBattle = iCriminalBushouID+1;    // 犯人の武将ID

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
			FuncDoDeathInBattleAsm();

			__asm {
				pop edi
				pop esi
				pop esp
				pop edx
				pop ecx
				pop ebx
				pop eax
			}

		} else {
			// 関数用のやつは、1つ多いので、足しこみ
			iBushouIDInFuncDoDeathInMain = iKilledBushouID+1;

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
			FuncDoDeathInMainAsm();

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
	}
	return false;
}

}



namespace 関数 {

bool Set_城主(int 武将番号【配列用】) {

	int iBushouID = 武将番号【配列用】;

	if ( 0 <= iBushouID && iBushouID < 最大数::武将情報::配列数 ) {

		if ( p武将戸籍情報[iBushouID].状態 == 状態::現役 ) { // 現役武将の場合だけ処理をする。

			// 該当武将の居城がちゃんとした情報が格納されている。(ユーザー改造等によって壊れていない)
			int iCastleID = p武将情報[iBushouID].所属居城【城番号】-1;

			if (0 <= iCastleID && iCastleID <  最大数::城情報::配列数 ) {

				if ( p城情報[iCastleID].城主【武将番号】 == 0xFFFF ) { return false; } // リンクリストが壊れているのか城に誰も所属していない。何もしない。return;

				// ここまで来たら城主が居るので…
				int i城主BusyouID = p城情報[iCastleID].城主【武将番号】-1;

				// 指定武将がすでに城主なら何もしなくても城主である。
				if ( iBushouID== i城主BusyouID ) { return true; }

				// 城主は居るが(改造等で)おかしな破たんデータになっていたら、何もしない。
				if ( ! (0 <= i城主BusyouID && i城主BusyouID < 最大数::武将情報::配列数 ) ) {
					return false;
				}
				// 城主が大名でも軍団長でもないならば(大名)、何もしない。入れ替えると変なことになる。
				if ( p武将戸籍情報[i城主BusyouID].状態 == 状態::現役 ) {
					; // 特に何もしない
				} else if ( p武将戸籍情報[i城主BusyouID].状態 == 状態::軍団長 ) {
					// 今の軍団長を現役とする
					p武将戸籍情報[i城主BusyouID].状態 = 状態::現役;
					// 逆に指定武将を軍団長化する
					p武将戸籍情報[iBushouID].状態 = 状態::軍団長;
					int iGundanID = p武将情報[i城主BusyouID].所属軍団【軍団番号】-1;
					// 決して要らぬ判定のはずであるが一応
					if ( 0 <= iGundanID && iGundanID < 最大数::軍団情報::配列数 ) {
						// 軍団情報の軍団長の番号を、指定の武将にする。
						p軍団情報[iGundanID].軍団長【武将番号】 = iBushouID + 1;
					}

				} else if ( p武将戸籍情報[i城主BusyouID].状態 == 状態::大名 ) {
					// 今の大名を現役とする
					p武将戸籍情報[i城主BusyouID].状態 = 状態::現役;
					// 大名だった人の身分を宿老とする。
					p武将戸籍情報[i城主BusyouID].身分 = 身分::宿老;
					// 逆に指定武将を大名とする
					p武将戸籍情報[iBushouID].状態 = 状態::大名;
					p武将戸籍情報[iBushouID].身分 = 身分::大名;
					int iGundanID = p武将情報[i城主BusyouID].所属軍団【軍団番号】-1;
					int iDaimyoID = p武将情報[i城主BusyouID].所属大名【大名番号】-1;
					// 決して要らぬ判定のはずであるが一応
					if ( 0 <= iGundanID && iGundanID < 最大数::軍団情報::配列数 ) {
						// 軍団情報の軍団長の番号を、指定の武将にする。
						p軍団情報[iGundanID].軍団長【武将番号】 = iBushouID + 1;
					}
					if ( 0 <= iDaimyoID && iDaimyoID < 最大数::大名情報::配列数 ) {
						// 大名情報の大名の番号を、指定の武将にする。
						p大名情報[iDaimyoID].大名【武将番号】 = iBushouID + 1;
					}

				} else {
					return false;
				}




				/*城情報の武将リスト

				　 　自分
				   ↓
				   ○-●-○-○

				   というのを

				   ○-○-○

				   とする。
				   */

				int iPrevID = p武将情報[iBushouID].前の武将【武将番号】;
				int iNextID = p武将情報[iBushouID].次の武将【武将番号】;

				// パージにしたい武将は、いま城主だ
				if ( p城情報[iCastleID].城主【武将番号】-1 == iBushouID ) {
					p城情報[iCastleID].城主【武将番号】 =  iNextID; // 自分のnextを城主にする。
				}

				// 自分のprevは有効な武将だ。
				if ( 0 < iPrevID && iPrevID <= 最大数::武将情報::配列数 ) {

					// 自分が城主ではない武将で、
					// １つ前の人の次のリンク先が自分自身の場合
					if ( iPrevID != 0xFFFF && p武将情報[(iPrevID-1)].次の武将【武将番号】 == iBushouID+1 ) {
						// 自分ではなく、次の人へと繋ぎかえる。
						p武将情報[(iPrevID-1)].次の武将【武将番号】 = iNextID;
					}
				}

				// 自分のnextは有効な武将だ。
				if ( 0 < iNextID && iNextID <= 最大数::武将情報::配列数 ) {
					// １つ後の人の前のリンク先が自分自身の場合
					if ( iNextID != 0xFFFF && p武将情報[(iNextID-1)].前の武将【武将番号】 == iBushouID+1 ) {
						// 自分ではなく、前の人へと繋ぎかえる。
						p武将情報[(iNextID-1)].前の武将【武将番号】 = iPrevID;
					}
				}


				/* 城情報の城主リスト　

				○-○

				というのを

				●-○-○

				とする。
				*/

				// 現役としてみなした時、自分のnextは、現在現役リストの先頭の人
				int iJosyu = p城情報[iCastleID].城主【武将番号】;
				p武将情報[iBushouID].次の武将【武将番号】 = iJosyu; // 現在の先頭の人を自分の次の人に

				// nextが有効な武将ならば…
				if ( 0 < iJosyu && iJosyu <= 最大数::武将情報::配列数 ) {
					// 次の人のprevを自分に
					p武将情報[iJosyu-1].前の武将【武将番号】 = iBushouID+1;
				}
				p武将情報[iBushouID].前の武将【武将番号】 = 0xFFFF; // prevは居ない

				p城情報[iCastleID].城主【武将番号】 = iBushouID+1; // 城の城主を自分にする。

				return true;
			}
		}
	}

	return false;
}

} // namespace 関数

bool _Set_武将転居《浪人》(int 武将番号【配列用】, int 転居先城番号【配列用】) {

	int iBushouID = 武将番号【配列用】;

	if ( 0 <= iBushouID && iBushouID < 最大数::武将情報::配列数 ) {
		if ( p武将戸籍情報[iBushouID].状態 == 状態::浪人 ) { // 浪人武将の場合だけ処理をする。

			// 該当武将の居城がちゃんとした情報が格納されている。(ユーザー改造等によって壊れていない)
			int iCastleID = p武将情報[iBushouID].所属居城【城番号】-1;
			int iNewCastleID = 転居先城番号【配列用】;

			if ( iCastleID == iNewCastleID ) { return true; } // 転居先が同じなら何もする必要はない。

			if ((0 <= iCastleID && iCastleID <  最大数::城情報::配列数) && (0 <= iNewCastleID && iNewCastleID <  最大数::城情報::配列数)) {

				if ( p城情報[iCastleID]._浪人先頭武将【武将番号】 == 0xFFFF ) { return false; } // リンクリストが壊れているのか浪人が誰も居ないことになっちゃってる。何もしない。return;

				// メモリ上の値変更
				{
					p武将情報[iBushouID].所属居城【城番号】= iNewCastleID+1;
				}

				/* 　自分
				      ↓
				   ○-●-○-○

				   というのを

				   ○-○-○

				   とする。
				*/

				int iPrevID = p武将情報[iBushouID].前の武将【武将番号】;
				int iNextID = p武将情報[iBushouID].次の武将【武将番号】;

				// 転居にしたい武将は、いま浪人リストの先頭だ
				if ( p城情報[iCastleID]._浪人先頭武将【武将番号】-1 == iBushouID ) {
					p城情報[iCastleID]._浪人先頭武将【武将番号】 =  iNextID; // 自分のnextを城主にする。
				}

				// 自分のprevは有効な武将だ。
				if ( 0 < iPrevID && iPrevID <= 最大数::武将情報::配列数 ) {

					// 自分が先頭ではない武将で、
					// １つ前の人の次のリンク先が自分自身の場合
					if ( iPrevID != 0xFFFF && p武将情報[(iPrevID-1)].次の武将【武将番号】 == iBushouID+1 ) {
						// 自分ではなく、次の人へと繋ぎかえる。
						p武将情報[(iPrevID-1)].次の武将【武将番号】 = iNextID;
					}
				}

				// 自分のnextは有効な武将だ。
				if ( 0 < iNextID && iNextID <= 最大数::武将情報::配列数 ) {
					// １つ後の人の前のリンク先が自分自身の場合
					if ( iNextID != 0xFFFF && p武将情報[(iNextID-1)].前の武将【武将番号】 == iBushouID+1 ) {
						// 自分ではなく、前の人へと繋ぎかえる。
						p武将情報[(iNextID-1)].前の武将【武将番号】 = iPrevID;
					}
				}


				/* 転居先の城情報の浪人リスト　

				○-○

				というのを

				●-○-○

				とする。
				*/

				// 浪人としてみなした時、自分のnextは、現在浪人リストの先頭の人
				int iRonin = p城情報[iNewCastleID]._浪人先頭武将【武将番号】;
				p武将情報[iBushouID].次の武将【武将番号】 = iRonin; // 現在の先頭の人を自分の次の人に

				// nextが有効な武将ならば…
				if ( 0 < iRonin && iRonin <= 最大数::武将情報::配列数 ) {
					// 次の人のprevを自分に
					p武将情報[iRonin-1].前の武将【武将番号】 = iBushouID+1;
				}
				p武将情報[iBushouID].前の武将【武将番号】 = 0xFFFF; // prevは居ない

				p城情報[iNewCastleID]._浪人先頭武将【武将番号】 = iBushouID+1; // 城の浪人の先頭を自分にする。

				return true;

			}
		}
	}

	return false;
}

namespace 関数 {

int Set_武将誕生(int 顔番号) {
	if ( p_GeneralABushouBornExecute ) {
		int iBushouID = p_GeneralABushouBornExecute( 顔番号 );
		return iBushouID;
	}
	return -1;
}

bool Set_武将転居(int 武将番号【配列用】, int 転居先城番号【配列用】) {
	int iBushouID = 武将番号【配列用】;

	if ( 0 <= iBushouID && iBushouID < 最大数::武将情報::配列数 ) {

		// 今の居城と新しい居城
		int iCastleID = p武将情報[iBushouID].所属居城【城番号】-1;
		int iNewCastleID = 転居先城番号【配列用】;

		if ( iCastleID == iNewCastleID ) { return true; } // 今居る場所と、転居先が同じなら何もする必要はない。

		// 浪人の場合は移転するだけ
		if ( p武将戸籍情報[iBushouID].状態 == 状態::浪人 ) { // 浪人武将の場合だけ処理をする。
			return _Set_武将転居《浪人》(武将番号【配列用】, 転居先城番号【配列用】);

		// 現役の場合は、浪人化してから、移転して、また(可能であれば)現役に戻す。
		// 未統治城だと浪人のまま移転することとなる。
		} else if ( p武将戸籍情報[iBushouID].状態 == 状態::現役 ) {
			int _勲功 = p武将情報[武将番号【配列用】].勲功;
			int _仕官年数 = p武将情報[武将番号【配列用】].仕官年数;
			int _身分 = p武将戸籍情報[武将番号【配列用】].身分;
			int _忠誠 = p武将情報[武将番号【配列用】].忠誠;
			int _兵数 = p武将情報[武将番号【配列用】].兵数;
			int _訓練 = p武将情報[武将番号【配列用】].訓練;
			int _士気 = p武将情報[武将番号【配列用】].士気;
			int _兵態 = p武将情報[武将番号【配列用】].兵態;
			int _大名 = p武将情報[武将番号【配列用】].所属大名【大名番号】;
			int _内応先大名 = p武将情報[武将番号【配列用】].内応先大名【大名番号】;
			int _内応状態 = p武将情報[武将番号【配列用】].内応状態;

			bool is浪人化 = Set_武将状態《現役→浪人》(武将番号【配列用】);
			if (! is浪人化) { return false; }

			bool is転居化 = _Set_武将転居《浪人》(武将番号【配列用】, 転居先城番号【配列用】);
			if (! is転居化) { return false; }

			bool is現役化 = Set_武将状態《浪人→現役》(武将番号【配列用】);
			if (! is現役化) { return false; }

			p武将情報[武将番号【配列用】].勲功 = _勲功;
			p武将戸籍情報[武将番号【配列用】].身分 = _身分;
			p武将情報[武将番号【配列用】].忠誠 = _忠誠;
			p武将情報[武将番号【配列用】].兵数 = _兵数;
			p武将情報[武将番号【配列用】].訓練 = _訓練;
			p武将情報[武将番号【配列用】].士気 = _士気;
			p武将情報[武将番号【配列用】].兵態 = _兵態;

			// 転居前と転居後で大名が変化していない場合のみ、士官年数や内応系も元の値を復元
			if (_大名 == p武将情報[武将番号【配列用】].所属大名【大名番号】) {
				p武将情報[武将番号【配列用】].仕官年数 = _仕官年数;
				p武将情報[武将番号【配列用】].内応先大名【大名番号】 = _内応先大名;
				p武将情報[武将番号【配列用】].内応状態 = _内応状態;
			} else {
				p武将情報[武将番号【配列用】].遺恨状態 = 0; // 大名が変化していれば、恨みは消す。
			}

		}
	}
	return false;
}



// 相性の輪配列。(計算用)
int 武将相性環[32] = {8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7};

// A武将とB武将の相性の差分を得る
// 最小0(相性最高) 最大8(相性最悪)
int Get_相性差(int 相性値Ａ, int 相性値Ｂ) {

	// 範囲チェック
	if ( 相性値Ａ < 0 ) {
		相性値Ａ = 0;
		デバッグ出力("相性値Ａが０より小さく指定されている");
	}
	if ( 相性値Ｂ < 0 ) {
		相性値Ｂ = 0;
		デバッグ出力("相性値Ｂが０より小さく指定されている");
	}
	if ( 相性値Ａ >= 最大数::武将情報::相性数 ) {
		相性値Ａ = 最大数::武将情報::相性数-1;
		デバッグ出力("相性値Ａが１５より大きく指定されている");
	} 
	if ( 相性値Ｂ >= 最大数::武将情報::相性数 ) {
		相性値Ｂ = 最大数::武将情報::相性数-1;
		デバッグ出力("相性値Ｂが１５より大きく指定されている");
	} 

	// まず、A武将の相性位置を中央から取る
	int Ａの相性位置 = 0;
	for (int 相性環IX=8; 相性環IX<8+最大数::武将情報::相性数; 相性環IX++ ) {
		// Aの相性値を見つけたら、そこがAの位置
		if ( 武将相性環[相性環IX] == 相性値Ａ ) {
			Ａの相性位置 = 相性環IX;
		}
	}

	// 不正な数字の場合は、相性差は最も悪いものとする。
	if ( Ａの相性位置 == 0 ) { return 8; }

	// B武将の相性位置はA武将の-8からスタート
	int Ｂの相性位置 = 0;
	for (int 相性環IX=Ａの相性位置-8; 相性環IX<Ａの相性位置+8; 相性環IX++ ) {
		// Bの相性値を見つけたら、そこがBの位置
		if ( 武将相性環[相性環IX] == 相性値Ｂ ) {
			Ｂの相性位置 = 相性環IX;
		}
	}

	// 不正な数字の場合は、相性差は最も悪いものとする。
	if ( Ｂの相性位置 == 0 ) { return 8; }

	// ２つの相性の位置の差分が相性差
	return abs(Ｂの相性位置-Ａの相性位置);
}


/*
* 2人の武将IDから相性の違いを得る。
* 最小0(相性最高) 最大8(相性最悪)
*/
int Get_武将相性差(int 武将Ａ番号【配列用】, int 武将Ｂ番号【配列用】) {

	// 範囲チェック
	if ( 0 <= 武将Ａ番号【配列用】 && 武将Ａ番号【配列用】 < 最大数::武将情報::配列数 ) {
	} else {
		デバッグ出力("武将Ａ番号【配列用】は範囲外");
	}

	// 範囲チェック
	if ( 0 <= 武将Ｂ番号【配列用】 && 武将Ｂ番号【配列用】 < 最大数::武将情報::配列数 ) {
	} else {
		デバッグ出力("武将Ｂ番号【配列用】は範囲外");
	}
	if ( 0 <= 武将Ａ番号【配列用】 && 武将Ａ番号【配列用】 < 最大数::武将情報::配列数 &&
		0 <= 武将Ｂ番号【配列用】 && 武将Ｂ番号【配列用】 < 最大数::武将情報::配列数 ) {
		// 武将の相性の差を返す
		return Get_相性差( p武将情報[武将Ａ番号【配列用】].相性, p武将情報[武将Ｂ番号【配列用】].相性 );
	} else {
		return -1;
	}
}



int Get_会見意向(int 武将番号【配列用】) {
	if ( p_GetKaikenIkouAI ) {
		return p_GetKaikenIkouAI(武将番号【配列用】);
	}
	return 会見意向::静観;
}

void Set_会見意向(int 武将番号【配列用】, int 会見意向) {
	if ( p_SetKaikenIkouAI ) {
		p_SetKaikenIkouAI(武将番号【配列用】, 会見意向);
	}
}







bool Is_自分は相手の娘( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	if ( 0 <= 自分武将番号【配列用】 && 自分武将番号【配列用】 < 最大数::武将情報::配列数 &&
		 0 <= 相手武将番号【配列用】 && 相手武将番号【配列用】 < 最大数::武将情報::配列数) {

		if ( p武将情報[自分武将番号【配列用】].親顔番号 == p武将戸籍情報[相手武将番号【配列用】].顔番号 && 
			 Get_武将年齢(自分武将番号【配列用】) < Get_武将年齢(相手武将番号【配列用】) &&
			 p武将戸籍情報[自分武将番号【配列用】].性別 == 性別::女 ) {
			
			 return true;
		}
	}
	return false;
}

bool Is_自分は相手の息子( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	if ( 0 <= 自分武将番号【配列用】 && 自分武将番号【配列用】 < 最大数::武将情報::配列数 &&
		 0 <= 相手武将番号【配列用】 && 相手武将番号【配列用】 < 最大数::武将情報::配列数) {

		if ( p武将情報[自分武将番号【配列用】].親顔番号 == p武将戸籍情報[相手武将番号【配列用】].顔番号 && 
			 Get_武将年齢(自分武将番号【配列用】) < Get_武将年齢(相手武将番号【配列用】) &&
			 p武将戸籍情報[自分武将番号【配列用】].性別 == 性別::男 ) {
			
			 return true;
		}
	}
	return false;
}

bool Is_自分は相手の子( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	if ( 0 <= 自分武将番号【配列用】 && 自分武将番号【配列用】 < 最大数::武将情報::配列数 &&
		 0 <= 相手武将番号【配列用】 && 相手武将番号【配列用】 < 最大数::武将情報::配列数) {

		if ( p武将情報[相手武将番号【配列用】].親顔番号 == p武将戸籍情報[自分武将番号【配列用】].顔番号 && 
			 Get_武将年齢(自分武将番号【配列用】) < Get_武将年齢(相手武将番号【配列用】) ) {

			 return true;
		}
	}
	return false;
}

bool Is_自分は相手の親( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	if ( 0 <= 自分武将番号【配列用】 && 自分武将番号【配列用】 < 最大数::武将情報::配列数 &&
		 0 <= 相手武将番号【配列用】 && 相手武将番号【配列用】 < 最大数::武将情報::配列数) {
		if ( p武将情報[相手武将番号【配列用】].親顔番号 == p武将戸籍情報[自分武将番号【配列用】].顔番号 && 
			 Get_武将年齢(自分武将番号【配列用】) > Get_武将年齢(相手武将番号【配列用】) ) {

			 return true;
		}
	}
	return false;
}

bool Is_自分は相手の父( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	if ( 0 <= 自分武将番号【配列用】 && 自分武将番号【配列用】 < 最大数::武将情報::配列数 &&
		 0 <= 相手武将番号【配列用】 && 相手武将番号【配列用】 < 最大数::武将情報::配列数) {

		if ( p武将情報[相手武将番号【配列用】].親顔番号 == p武将戸籍情報[自分武将番号【配列用】].顔番号 && 
			 Get_武将年齢(自分武将番号【配列用】) > Get_武将年齢(相手武将番号【配列用】) &&
			 p武将戸籍情報[自分武将番号【配列用】].性別 == 性別::男 ) {

			 return true;
		}
	}
	return false;
}

bool Is_相手は自分の父( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	return Is_自分は相手の父(相手武将番号【配列用】, 自分武将番号【配列用】);
}



bool Is_自分は相手の母( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	if ( 0 <= 自分武将番号【配列用】 && 自分武将番号【配列用】 < 最大数::武将情報::配列数 &&
		 0 <= 相手武将番号【配列用】 && 相手武将番号【配列用】 < 最大数::武将情報::配列数) {

		if ( p武将情報[相手武将番号【配列用】].親顔番号 == p武将戸籍情報[自分武将番号【配列用】].顔番号 && 
			 Get_武将年齢(自分武将番号【配列用】) > Get_武将年齢(相手武将番号【配列用】) &&
			 p武将戸籍情報[自分武将番号【配列用】].性別 == 性別::女 ) {

			 return true;
		}
	}
	return false;
}

bool Is_相手は自分の母( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	return Is_自分は相手の母(相手武将番号【配列用】, 自分武将番号【配列用】);
}

bool Is_自分は相手の弟( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	if ( 0 <= 自分武将番号【配列用】 && 自分武将番号【配列用】 < 最大数::武将情報::配列数 &&
		 0 <= 相手武将番号【配列用】 && 相手武将番号【配列用】 < 最大数::武将情報::配列数) {

		if ( p武将情報[自分武将番号【配列用】].親顔番号 < 5000 && 
			 p武将情報[自分武将番号【配列用】].親顔番号 == p武将情報[相手武将番号【配列用】].親顔番号 && 
			 Get_武将年齢(自分武将番号【配列用】) < Get_武将年齢(相手武将番号【配列用】) &&
			 p武将戸籍情報[自分武将番号【配列用】].性別 == 性別::男 ) {

			 return true;
		}
	}
	return false;
}

bool Is_相手は自分の弟( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	return Is_自分は相手の弟( 相手武将番号【配列用】, 自分武将番号【配列用】 );
}

bool Is_自分は相手の妹( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	if ( 0 <= 自分武将番号【配列用】 && 自分武将番号【配列用】 < 最大数::武将情報::配列数 &&
		 0 <= 相手武将番号【配列用】 && 相手武将番号【配列用】 < 最大数::武将情報::配列数) {

		if ( p武将情報[自分武将番号【配列用】].親顔番号 < 5000 && 
			 p武将情報[自分武将番号【配列用】].親顔番号 == p武将情報[相手武将番号【配列用】].親顔番号 && 
			 Get_武将年齢(自分武将番号【配列用】) < Get_武将年齢(相手武将番号【配列用】) &&
			 p武将戸籍情報[自分武将番号【配列用】].性別 == 性別::女 ) {

			 return true;
		}
	}
	return false;
}

bool Is_相手は自分の妹( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	return Is_自分は相手の妹( 相手武将番号【配列用】, 自分武将番号【配列用】 );
}

bool Is_自分は相手の兄( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	if ( 0 <= 自分武将番号【配列用】 && 自分武将番号【配列用】 < 最大数::武将情報::配列数 &&
		 0 <= 相手武将番号【配列用】 && 相手武将番号【配列用】 < 最大数::武将情報::配列数) {

		if ( p武将情報[自分武将番号【配列用】].親顔番号 < 5000 && 
			 p武将情報[自分武将番号【配列用】].親顔番号 == p武将情報[相手武将番号【配列用】].親顔番号 && 
			 Get_武将年齢(自分武将番号【配列用】) > Get_武将年齢(相手武将番号【配列用】) &&
			 p武将戸籍情報[自分武将番号【配列用】].性別 == 性別::男 ) {

			 return true;
		}
	}
	return false;
}

bool Is_相手は自分の兄( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	return Is_自分は相手の兄( 相手武将番号【配列用】, 自分武将番号【配列用】);
}


bool Is_自分は相手の姉( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	if ( 0 <= 自分武将番号【配列用】 && 自分武将番号【配列用】 < 最大数::武将情報::配列数 &&
		 0 <= 相手武将番号【配列用】 && 相手武将番号【配列用】 < 最大数::武将情報::配列数) {

		if ( p武将情報[自分武将番号【配列用】].親顔番号 < 5000 && 
			 p武将情報[自分武将番号【配列用】].親顔番号 == p武将情報[相手武将番号【配列用】].親顔番号 && 
			 Get_武将年齢(自分武将番号【配列用】) > Get_武将年齢(相手武将番号【配列用】) &&
			 p武将戸籍情報[自分武将番号【配列用】].性別 == 性別::女 ) {

			 return true;
		}
	}
	return false;
}

bool Is_相手は自分の姉( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	return Is_自分は相手の姉( 相手武将番号【配列用】, 自分武将番号【配列用】);
}

bool Is_自分と相手は兄弟( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	if ( 0 <= 自分武将番号【配列用】 && 自分武将番号【配列用】 < 最大数::武将情報::配列数 &&
		 0 <= 相手武将番号【配列用】 && 相手武将番号【配列用】 < 最大数::武将情報::配列数) {

		if ( p武将情報[自分武将番号【配列用】].親顔番号 < 5000 && 
			 p武将情報[自分武将番号【配列用】].親顔番号 == p武将情報[相手武将番号【配列用】].親顔番号 &&
			 Get_武将年齢(自分武将番号【配列用】) > Get_武将年齢(相手武将番号【配列用】) &&
			 p武将戸籍情報[自分武将番号【配列用】].性別 == 性別::男 && p武将戸籍情報[相手武将番号【配列用】].性別 == 性別::男) {

			 return true;
		}
	}
	return false;
}

bool Is_自分と相手は姉妹( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	if ( 0 <= 自分武将番号【配列用】 && 自分武将番号【配列用】 < 最大数::武将情報::配列数 &&
		 0 <= 相手武将番号【配列用】 && 相手武将番号【配列用】 < 最大数::武将情報::配列数) {

		if ( p武将情報[自分武将番号【配列用】].親顔番号 < 5000 && 
			 p武将情報[自分武将番号【配列用】].親顔番号 == p武将情報[相手武将番号【配列用】].親顔番号 && 
			 Get_武将年齢(自分武将番号【配列用】) > Get_武将年齢(相手武将番号【配列用】) &&
			 p武将戸籍情報[自分武将番号【配列用】].性別 == 性別::女 && p武将戸籍情報[相手武将番号【配列用】].性別 == 性別::女) {

			 return true;
		}
	}
	return false;
}


bool Is_自分と相手は姉弟( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	if ( 0 <= 自分武将番号【配列用】 && 自分武将番号【配列用】 < 最大数::武将情報::配列数 &&
		 0 <= 相手武将番号【配列用】 && 相手武将番号【配列用】 < 最大数::武将情報::配列数) {

		if ( p武将情報[自分武将番号【配列用】].親顔番号 < 5000 && 
			 p武将情報[自分武将番号【配列用】].親顔番号 == p武将情報[相手武将番号【配列用】].親顔番号 &&
			 Get_武将年齢(自分武将番号【配列用】) > Get_武将年齢(相手武将番号【配列用】) &&
			 p武将戸籍情報[自分武将番号【配列用】].性別 == 性別::女 && p武将戸籍情報[相手武将番号【配列用】].性別 == 性別::男) {

			 return true;
		}
	}
	return false;
}



bool Is_自分と相手は兄妹( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	if ( 0 <= 自分武将番号【配列用】 && 自分武将番号【配列用】 < 最大数::武将情報::配列数 &&
		 0 <= 相手武将番号【配列用】 && 相手武将番号【配列用】 < 最大数::武将情報::配列数) {

		if ( p武将情報[自分武将番号【配列用】].親顔番号 < 5000 && 
			 p武将情報[自分武将番号【配列用】].親顔番号 == p武将情報[相手武将番号【配列用】].親顔番号 &&
			 Get_武将年齢(自分武将番号【配列用】) > Get_武将年齢(相手武将番号【配列用】) &&
			 p武将戸籍情報[自分武将番号【配列用】].性別 == 性別::男 && p武将戸籍情報[相手武将番号【配列用】].性別 == 性別::女) {

			 return true;
		}
	}
	return false;
}




bool Is_自分は相手の夫( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	if ( 0 <= 自分武将番号【配列用】 && 自分武将番号【配列用】 < 最大数::武将情報::配列数 &&
		 0 <= 相手武将番号【配列用】 && 相手武将番号【配列用】 < 最大数::武将情報::配列数) {

		if ( p武将情報[自分武将番号【配列用】]._妻 != 0xFF &&
			 p武将情報[自分武将番号【配列用】]._妻 == p武将情報[相手武将番号【配列用】]._妻 && 
			 p武将戸籍情報[自分武将番号【配列用】].性別 == 性別::男 ) {

			 return true;
		}
	}
	return false;
}

bool Is_自分は相手の妻( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	if ( 0 <= 自分武将番号【配列用】 && 自分武将番号【配列用】 < 最大数::武将情報::配列数 &&
		 0 <= 相手武将番号【配列用】 && 相手武将番号【配列用】 < 最大数::武将情報::配列数) {

		if ( p武将情報[自分武将番号【配列用】]._妻 != 0xFF &&
			 p武将情報[自分武将番号【配列用】]._妻 == p武将情報[相手武将番号【配列用】]._妻 && 
			 p武将戸籍情報[自分武将番号【配列用】].性別 == 性別::女 ) {

			 return true;
		}
	}
	return false;
}


bool Is_自分は相手の血縁( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	if ( 0 <= 自分武将番号【配列用】 && 自分武将番号【配列用】 < 最大数::武将情報::配列数 &&
		 0 <= 相手武将番号【配列用】 && 相手武将番号【配列用】 < 最大数::武将情報::配列数) {

		if ( p武将情報[自分武将番号【配列用】].所属血筋 != 0xFF &&
			p武将情報[自分武将番号【配列用】].所属血筋 == p武将情報[相手武将番号【配列用】].所属血筋 ) {

			return true;
		}
	}
	return false;
}

bool Is_相手は自分の家臣( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	if ( 0 <= 自分武将番号【配列用】 && 自分武将番号【配列用】 < 最大数::武将情報::配列数 &&
		 0 <= 相手武将番号【配列用】 && 相手武将番号【配列用】 < 最大数::武将情報::配列数) {
		 // 第１人称は大名
		if ( p武将戸籍情報[自分武将番号【配列用】].状態 == 状態::大名 ) {
			// 第２人称は大名にちゃんと所属している。
			if ( 0 <= p武将情報[相手武将番号【配列用】].所属大名【大名番号】-1 && p武将情報[相手武将番号【配列用】].所属大名【大名番号】-1 < 最大数::大名情報::配列数 ) {
				int iAttachDaimyoID = p武将情報[相手武将番号【配列用】].所属大名【大名番号】-1;
				if ( 自分武将番号【配列用】 == p大名情報[iAttachDaimyoID].大名【武将番号】-1 ) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Is_相手は自分の大名( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	return Is_相手は自分の家臣( 相手武将番号【配列用】, 自分武将番号【配列用】 );
}

// 家臣はもちろん、大名自身も自分の大名家に所属しているとみなされる。
bool Is_自分と相手は同じ大名家所属( int 自分武将番号【配列用】, int 相手武将番号【配列用】 ) {
	if ( 0 <= 自分武将番号【配列用】 && 自分武将番号【配列用】 < 最大数::武将情報::配列数 &&
		 0 <= 相手武将番号【配列用】 && 相手武将番号【配列用】 < 最大数::武将情報::配列数) {

		int i1stAttachDaimyoID = -1;
		int i2ndAttachDaimyoID = -1;

		// 第１人称は大名にちゃんと所属している。
		if ( 0 <= p武将情報[自分武将番号【配列用】].所属大名【大名番号】-1 && p武将情報[自分武将番号【配列用】].所属大名【大名番号】-1 < 最大数::大名情報::配列数 ) {
			i1stAttachDaimyoID = p武将情報[自分武将番号【配列用】].所属大名【大名番号】-1;
		}

		// 第２人称は大名にちゃんと所属している。
		if ( 0 <= p武将情報[相手武将番号【配列用】].所属大名【大名番号】-1 && p武将情報[相手武将番号【配列用】].所属大名【大名番号】-1 < 最大数::大名情報::配列数 ) {
			i2ndAttachDaimyoID = p武将情報[相手武将番号【配列用】].所属大名【大名番号】-1;
		}

		if ( i1stAttachDaimyoID != -1 && i2ndAttachDaimyoID != -1 ) {
			if ( i1stAttachDaimyoID == i2ndAttachDaimyoID ) { 
				return true;
			}
		}
	}
	return false;
}

} // namespace 関数
