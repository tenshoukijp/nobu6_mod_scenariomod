#include <cassert>
#include "ゲームデータ構造.h"


int DeNormalizeDaimyoYakusyokuValue(int iYakusyokuValue) {
	switch (iYakusyokuValue) {
	case 役職::征夷大将軍:
		return 0x01;
	case 役職::管領:
		return 0x02;
	case 役職::関東管領:
		return 0x04;
	case 役職::奥州探題:
		return 0x08;
	case 役職::西国探題:
		return 0x10;
	case 役職::九州探題:
		return 0x20;
	case 役職::羽州探題:
		return 0x40;
	default:
		return 0;
	}
}

namespace 関数 {




// 大名IDから正規化された(0〜7へと振りなおされた)役職IDを得る
int Get_大名役職(int 大名番号【配列用】) {

	// 範囲チェック
	if ( 0 <= 大名番号【配列用】 && 大名番号【配列用】 < 最大数::武将情報::配列数 ) { 

		switch ( p大名情報[大名番号【配列用】]._役職) {
			case 0x01:
				return 役職::征夷大将軍;
			case 0x02:
				return 役職::管領;
			case 0x04:
				return 役職::関東管領;
			case 0x08 :
				return 役職::奥州探題;
			case 0x10:
				return 役職::西国探題;
			case 0x20:
				return 役職::九州探題;
			case 0x40:
				return 役職::羽州探題;
			default:
				return 0;
		}
	}
	return 0;
}

// 軍団IDから正規化された役職IDを得る
int Get_軍団役職(int 軍団番号【配列用】) {

	// 範囲チェック
	if ( 0 <= 軍団番号【配列用】 && 軍団番号【配列用】 < 最大数::軍団情報::配列数 ) { 

		// 大名自身なら、別処理
		if (p軍団情報[軍団番号【配列用】].軍団割当番号 == 1) {
			int iDaimyoID = p軍団情報[軍団番号【配列用】].所属大名【大名番号】 - 1;
			if (0 <= iDaimyoID && iDaimyoID < 最大数::大名情報::配列数) {
				return Get_大名役職(iDaimyoID);
			}
		}

		return p軍団情報[軍団番号【配列用】]._役職;
	}
	デバッグ出力("指定の軍団番号【配列用】は範囲外");
	return -1;
}


bool Set_大名役職(int iDaimyoID, int iYakusyokuValue) {
	if (0 <= iDaimyoID && iDaimyoID < 最大数::大名情報::配列数) {

		if (役職::無し <= iYakusyokuValue && iYakusyokuValue <= 役職::羽州探題) {

			int DenormalizeyakusyokuValue = DeNormalizeDaimyoYakusyokuValue(iYakusyokuValue);

			// 大名で目的のIDの役職を持っている人
			for (int iDID = 0; iDID < 最大数::大名情報::配列数; iDID++) {
				int iDaimyoYakusyokuID = Get_大名役職(iDID);
				// その役職を持っていれば、はく奪
				if (iDaimyoYakusyokuID == iYakusyokuValue) {
					p大名情報[iDID]._役職 = 0;
				}
			}

			// 軍団で目的のIDの役職を持っている人
			for (int iGID = 0; iGID < 最大数::軍団情報::配列数; iGID++) {
				int iGundanYakusyokuID = Get_軍団役職(iGID);
				// その役職を持っていれば、はく奪
				if (iGundanYakusyokuID == iYakusyokuValue) {
					p軍団情報[iGID]._役職 = 0;
				}
			}

			// 自分に対象の役職をつける。
			p大名情報[iDaimyoID]._役職 = DenormalizeyakusyokuValue;

			return true;
		}
	}

	return false;
}


bool Set_軍団役職(int iGundanID, int iYakusyokuValue) {

	if (0 <= iGundanID && iGundanID < 最大数::軍団情報::配列数) {

		// 大名自身なら、別処理
		if (p軍団情報[iGundanID].軍団割当番号 == 1) {
			int iDaimyoID = p軍団情報[iGundanID].所属大名【大名番号】 - 1;
			Set_大名役職(iDaimyoID, iYakusyokuValue);
		}

		if (役職::無し <= iYakusyokuValue && iYakusyokuValue <= 役職::羽州探題) {

			// 大名で目的のIDの役職を持っている人
			for (int iDID = 0; iDID < 最大数::大名情報::配列数; iDID++) {
				int iDaimyoYakusyokuID = Get_大名役職(iDID);
				// その役職を持っていれば、はく奪
				if (iDaimyoYakusyokuID == iYakusyokuValue) {
					p大名情報[iDID]._役職 = 0;
				}
			}

			// 軍団で目的のIDの役職を持っている人
			for (int iGID = 0; iGID < 最大数::軍団情報::配列数; iGID++) {
				int iGundanYakusyokuID = Get_軍団役職(iGID);
				// その役職を持っていれば、はく奪
				if (iGundanYakusyokuID == iYakusyokuValue) {
					p軍団情報[iGID]._役職 = 0;
				}
			}

			// 自分に対象の役職をつける。
			p軍団情報[iGundanID]._役職 = iYakusyokuValue;

			return true;
		}
	}

	return false;
}


}