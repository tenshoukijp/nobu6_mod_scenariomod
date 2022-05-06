#include <cassert>
#include "ゲームデータ構造.h"


namespace 関数 {


// 官位名を取得する
string Get_官位名( int 官位番号【配列用】) {

	// 範囲チェック
	if ( 0 <= 官位番号【配列用】 && 官位番号【配列用】 < 最大数::官位情報::配列数 ) { 
		return string( p官位情報[官位番号【配列用】]._官位名 );
	} else {
		デバッグ出力("官位番号【配列用】は範囲外");
		return string("");
	}
}


// 官位名を設定する
void   Set_官位名( int 官位番号【配列用】, string 官位名 ) {

	// 範囲チェック
	if ( 0 <= 官位番号【配列用】 && 官位番号【配列用】 < 最大数::官位情報::配列数 ) { 
		strncpy_s( p官位情報[官位番号【配列用】]._官位名, 官位名.c_str(), 12 );
		p官位情報[官位番号【配列用】]._官位名[12] = NULL;
	} else {
		デバッグ出力("官位番号【配列用】は範囲外");
	}
}


// 官位による魅力の上げ幅
extern int Get_魅力官位上昇値(int iBushouID);


// 官位を武将にアタッチする。元々別武将が持っていた場合は、元の武将から指定した武将へとアタッチが変わる。
// 能力値の変更を伴う。朝廷に戻す場合は、0xFFFFを指定すること。
bool Set_官位所有者変更(int iKaniID, int iNewBushouID) {
	if (!(0 <= iKaniID && iKaniID < 最大数::官位情報::配列数)) {
		return false;
	}

	int iOldBushouID = p官位情報[iKaniID].所有武将【武将番号】 - 1;
	// 本人だ。何もする必要がない。
	if (iOldBushouID == iNewBushouID) {
		return true;
	}
	// 元々朝廷が持っていて、新たな指定も朝廷だ。何もする必要がない。
	if (iOldBushouID >= 0xFFFE && iNewBushouID >= 0xFFFE)  {
		return true;
	}


	// 元の武将の政治能力の素値
	int iOldBushouPureCharm = 0;
	// 新しい指定の武将は正規の武将であり、朝廷ではない。
	if (0 <= iOldBushouID && iOldBushouID < 最大数::武将情報::配列数) {
		iOldBushouPureCharm = Get_元魅力(iOldBushouID);
		// 不正な番号は朝廷ということにする。
	}
	else {
		iOldBushouID = 0xFFFF;
	}

	int iNewBushouPureCharm = 0;
	// 新しい指定の武将は正規の武将であり、朝廷ではない。
	if (0 <= iNewBushouID && iNewBushouID < 最大数::武将情報::配列数) {
		iNewBushouPureCharm = Get_元魅力(iNewBushouID);

		// 不正な番号は朝廷ということにする。
	}
	else {
		iNewBushouID = 0xFFFF;
	}

	// 対象の家宝の所持者を変更する。
	p官位情報[iKaniID].所有武将【武将番号】 = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

	// 元の武将は正規の武将であり、朝廷ではない。
	if (0 <= iOldBushouID && iOldBushouID < 最大数::武将情報::配列数) {
		int iOldBushouCharmUpByKani = Get_魅力官位上昇値(iOldBushouID);
		p武将情報[iOldBushouID].魅力 = iOldBushouPureCharm + iOldBushouCharmUpByKani;
	}

	// 新しい指定の武将は正規の武将であり、朝廷ではない。
	if (0 <= iNewBushouID && iNewBushouID < 最大数::武将情報::配列数) {
		int iNewBushouCharmUpByKani = Get_魅力官位上昇値(iNewBushouID);
		p武将情報[iNewBushouID].魅力 = iNewBushouPureCharm + iNewBushouCharmUpByKani;
	}

	return true;
}


// 
bool Set_官位上昇値(int iKaniID, int iNewUpValue) {

	if (!(0 <= iKaniID && iKaniID < 最大数::官位情報::配列数)) {
		return false;
	}

	int iBushouID = p官位情報[iKaniID].所有武将【武将番号】 - 1;  // 今持ってる武将番号を【配列用】に変更して控えておく

	bool ret = false;
	ret = Set_官位所有者変更(iKaniID, 0xFFFF); // 上昇値を変化させる前に、朝廷へと返上する
	if (ret == false) {
		return false;
	}

	if (iNewUpValue < 1) {
		iNewUpValue = 1;
	}
	if (iNewUpValue > 24) {
		iNewUpValue = 24;
	}
	p官位情報[iKaniID].上昇値 = iNewUpValue;

	// 元々が武将が所有していたのであれば...
	if (0 <= iBushouID && iBushouID < 最大数::武将情報::配列数) {
		Set_官位所有者変更(iKaniID, iBushouID);
	}

	return true;
}



}