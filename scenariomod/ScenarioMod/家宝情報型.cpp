#include <cassert>
#include "ゲームデータ構造.h"


namespace 関数 {



// 家宝名を取得する
string Get_家宝名( int 家宝番号【配列用】) {

	// 範囲チェック
	if( 0 <= 家宝番号【配列用】 && 家宝番号【配列用】 < 最大数::家宝情報::配列数 ) { 

		return string( p家宝情報[家宝番号【配列用】]._家宝名 );
	} else {
		デバッグ出力("指定の家宝番号【配列用】は範囲外");
		return string( "" );
	}
}


// 家宝名を設定する
void   Set_家宝名( int 家宝番号【配列用】, string 家宝名 ) {

	// 範囲チェック
	if( 0 <= 家宝番号【配列用】 && 家宝番号【配列用】 < 最大数::家宝情報::配列数 ) { 

		strncpy_s( p家宝情報[家宝番号【配列用】]._家宝名, 家宝名.c_str(), 12 );
		p家宝情報[家宝番号【配列用】]._家宝名[12] = NULL;
	} else {
		デバッグ出力("指定の家宝番号【配列用】は範囲外");
	}
}


WORD Get_家宝番号【配列用】(string 家宝名) {

	for (int iKahouID = 0; iKahouID < 最大数::家宝情報::配列数; iKahouID++) {
		if ( Get_家宝名(iKahouID) == 家宝名) {
			return iKahouID;
		}
	}

	return 0xFFFF;

}



}


namespace 関数 {

	// 家宝による政治の上げ幅
	int Get_最大政才家宝上昇値(int iBushouID) {
		if (0 <= iBushouID && iBushouID < 最大数::武将情報::配列数) {
			int upparam = 0; // 上昇値
			for (int iKahouID = 0; iKahouID < 最大数::家宝情報::配列数; iKahouID++) {
				// 政治増加タイプ：0 茶碗  1 茶壺  2 茶入  3 茶釜  4 花入  
				if (0 <= p家宝情報[iKahouID].家宝分類 && p家宝情報[iKahouID].家宝分類 <= 4) {
					// 持ち主と指定武将が一致した
					if (p家宝情報[iKahouID].所有武将【武将番号】 == iBushouID + 1) {
						// 今までで最大の上昇値
						if (p家宝情報[iKahouID].上昇値 > upparam) {
							upparam = p家宝情報[iKahouID].上昇値;
						}
					}
				}
			}
			return upparam;
		}
		else {
			return 0;
		}
	}

	// 家宝による戦闘の上げ幅
	int Get_最大戦才家宝上昇値(int iBushouID) {
		if (0 <= iBushouID && iBushouID < 最大数::武将情報::配列数) {
			int upparam = 0; // 上昇値
			for (int iKahouID = 0; iKahouID < 最大数::家宝情報::配列数; iKahouID++) {
				// 戦闘増加タイプ：5 刀剣  6 槍  7 具足  8 馬  9 鞍  A 陣羽織   
				if (5 <= p家宝情報[iKahouID].家宝分類 && p家宝情報[iKahouID].家宝分類 <= 0xA) {
					// 持ち主と指定武将が一致した
					if (p家宝情報[iKahouID].所有武将【武将番号】 == iBushouID + 1) {
						// 今までで最大の上昇地
						if (p家宝情報[iKahouID].上昇値 > upparam) {
							upparam = p家宝情報[iKahouID].上昇値;
						}
					}
				}
			}
			return upparam;
		}
		else {
			return 0;
		}
	}

	// 家宝による智謀の上げ幅
	int Get_最大智才家宝上昇値(int iBushouID) {
		if (0 <= iBushouID && iBushouID < 最大数::武将情報::配列数) {
			int upparam = 0; // 上昇値
			for (int iKahouID = 0; iKahouID < 最大数::家宝情報::配列数; iKahouID++) {
				// 智謀増加タイプ：B 巻子本  C 明朝綴本
				if (0xB <= p家宝情報[iKahouID].家宝分類 && p家宝情報[iKahouID].家宝分類 <= 0xC) {
					// 持ち主と指定武将が一致した
					if (p家宝情報[iKahouID].所有武将【武将番号】 == iBushouID + 1) {
						// 今までで最大の上昇地
						if (p家宝情報[iKahouID].上昇値 > upparam) {
							upparam = p家宝情報[iKahouID].上昇値;
						}
					}
				}
			}

			return upparam;
		}
		else {
			return 0;
		}
	}

	// 家宝による野望の上げ幅
	int Get_野望家宝上昇値(int iBushouID) {
		if (0 <= iBushouID && iBushouID < 最大数::武将情報::配列数) {
			int upparam = 0; // 上昇値
			for (int iKahouID = 0; iKahouID < 最大数::家宝情報::配列数; iKahouID++) {
				// 野望増加タイプ：D 香木  E 地球儀  F 南蛮時計  10 水墨画  11 十字架  12 聖書  13 玉手箱  14 ビードロ杯  15 遠眼鏡  16 ルソン壺  17 煙草
				if (0xD <= p家宝情報[iKahouID].家宝分類 && p家宝情報[iKahouID].家宝分類 <= 0x17) {
					// 持ち主と指定武将が一致した
					if (p家宝情報[iKahouID].所有武将【武将番号】 == iBushouID + 1) {
						// 今までで最大の上昇地
						if (p家宝情報[iKahouID].上昇値 > upparam) {
							upparam = p家宝情報[iKahouID].上昇値;
						}
					}
				}
			}
			return upparam;
		}
		else {
			return 0;
		}
	}


	// 官位による魅力の上げ幅
	int Get_魅力官位上昇値(int iBushouID) {
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
			return upparam;
		}
		else {
			return 0;
		}
	}




	// 家宝を武将にアタッチする。元々別武将が持っていた場合は、元の武将から指定した武将へとアタッチが変わる。
	// 能力値の変更を伴う。商人に戻す場合は、0xFFFFを指定すること。
	bool Set_家宝所有者変更(int iKahouID, int iNewBushouID) {
		if (!(0 <= iKahouID && iKahouID < 最大数::家宝情報::配列数)) {
			return false;
		}

		// 消失は降ろす
		p家宝情報[iKahouID].消失 = false;
		// 未登場は降ろす。
		p家宝情報[iKahouID].未登場 = false;

		int iOldBushouID = p家宝情報[iKahouID].所有武将【武将番号】 - 1;
		// 本人だ。何もする必要がない。
		if (iOldBushouID == iNewBushouID) {
			return true;
		}
		// 元々商人が持っていて、新たな指定も商人だ。何もする必要がない。
		if (iOldBushouID >= 0xFFFE && iNewBushouID >= 0xFFFE)  {
			return true;
		}

		// 政治増加タイプ：0 茶碗  1 茶壺  2 茶入  3 茶釜  4 花入  
		if (0 <= p家宝情報[iKahouID].家宝分類 && p家宝情報[iKahouID].家宝分類 <= 4) {

			// 元の武将の政治能力の素値
			int iOldBushouPureGovMax = 0;
			// 新しい指定の武将は正規の武将であり、商人ではない。
			if (0 <= iOldBushouID && iOldBushouID < 最大数::武将情報::配列数) {
				iOldBushouPureGovMax = Get_元最大政才(iOldBushouID);
				// 不正な番号は商人ということにする。
			}
			else {
				iOldBushouID = 0xFFFF;
			}

			int iNewBushouPureGovMax = 0;
			// 新しい指定の武将は正規の武将であり、商人ではない。
			if (0 <= iNewBushouID && iNewBushouID < 最大数::武将情報::配列数) {
				iNewBushouPureGovMax = Get_元最大政才(iNewBushouID);

				// 不正な番号は商人ということにする。
			}
			else {
				iNewBushouID = 0xFFFF;
			}

			// 対象の家宝の所持者を変更する。
			p家宝情報[iKahouID].所有武将【武将番号】 = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

			// 新しい指定の武将は正規の武将であり、商人ではない。
			if (0 <= iOldBushouID && iOldBushouID < 最大数::武将情報::配列数) {
				int iOldBushouGovMaxUpByKahou = Get_最大政才家宝上昇値(iOldBushouID);
				p武将情報[iOldBushouID].最大政才 = iOldBushouPureGovMax + iOldBushouGovMaxUpByKahou;
			}

			// 新しい指定の武将は正規の武将であり、商人ではない。
			if (0 <= iNewBushouID && iNewBushouID < 最大数::武将情報::配列数) {
				int iNewBushouGovMaxUpByKahou = Get_最大政才家宝上昇値(iNewBushouID);
				p武将情報[iNewBushouID].最大政才 = iNewBushouPureGovMax + iNewBushouGovMaxUpByKahou;
			}

			// 戦闘増加タイプ：5 刀剣  6 槍  7 具足  8 馬  9 鞍  A 陣羽織   
		}
		else if (5 <= p家宝情報[iKahouID].家宝分類 && p家宝情報[iKahouID].家宝分類 <= 0xA) {

			// 元の武将の政治能力の素値
			int iOldBushouPureBatMax = 0;
			// 新しい指定の武将は正規の武将であり、商人ではない。
			if (0 <= iOldBushouID && iOldBushouID < 最大数::武将情報::配列数) {
				iOldBushouPureBatMax = Get_元最大戦才(iOldBushouID);
				// 不正な番号は商人ということにする。
			}
			else {
				iOldBushouID = 0xFFFF;
			}

			int iNewBushouPureBatMax = 0;
			// 新しい指定の武将は正規の武将であり、商人ではない。
			if (0 <= iNewBushouID && iNewBushouID < 最大数::武将情報::配列数) {
				iNewBushouPureBatMax = Get_元最大戦才(iNewBushouID);

				// 不正な番号は商人ということにする。
			}
			else {
				iNewBushouID = 0xFFFF;
			}

			// 対象の家宝の所持者を変更する。
			p家宝情報[iKahouID].所有武将【武将番号】 = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

			// 新しい指定の武将は正規の武将であり、商人ではない。
			if (0 <= iOldBushouID && iOldBushouID < 最大数::武将情報::配列数) {
				int iOldBushouBatMaxUpByKahou = Get_最大戦才家宝上昇値(iOldBushouID);
				p武将情報[iOldBushouID].最大戦才 = iOldBushouPureBatMax + iOldBushouBatMaxUpByKahou;
			}

			// 新しい指定の武将は正規の武将であり、商人ではない。
			if (0 <= iNewBushouID && iNewBushouID < 最大数::武将情報::配列数) {
				int iNewBushouBatMaxUpByKahou = Get_最大戦才家宝上昇値(iNewBushouID);
				p武将情報[iNewBushouID].最大戦才 = iNewBushouPureBatMax + iNewBushouBatMaxUpByKahou;
			}


			// 智謀増加タイプ：B 巻子本  C 明朝綴本
		}
		else if (0xB <= p家宝情報[iKahouID].家宝分類 && p家宝情報[iKahouID].家宝分類 <= 0xC) {

			// 元の武将の政治能力の素値
			int iOldBushouPureIntMax = 0;
			// 新しい指定の武将は正規の武将であり、商人ではない。
			if (0 <= iOldBushouID && iOldBushouID < 最大数::武将情報::配列数) {
				iOldBushouPureIntMax = Get_元最大智才(iOldBushouID);
				// 不正な番号は商人ということにする。
			}
			else {
				iOldBushouID = 0xFFFF;
			}

			int iNewBushouPureIntMax = 0;
			// 新しい指定の武将は正規の武将であり、商人ではない。
			if (0 <= iNewBushouID && iNewBushouID < 最大数::武将情報::配列数) {
				iNewBushouPureIntMax = Get_元最大智才(iNewBushouID);

				// 不正な番号は商人ということにする。
			}
			else {
				iNewBushouID = 0xFFFF;
			}

			// 対象の家宝の所持者を変更する。
			p家宝情報[iKahouID].所有武将【武将番号】 = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

			// 新しい指定の武将は正規の武将であり、商人ではない。
			if (0 <= iOldBushouID && iOldBushouID < 最大数::武将情報::配列数) {
				int iOldBushouIntMaxUpByKahou = Get_最大智才家宝上昇値(iOldBushouID);
				p武将情報[iOldBushouID].最大智才 = iOldBushouPureIntMax + iOldBushouIntMaxUpByKahou;
			}

			// 新しい指定の武将は正規の武将であり、商人ではない。
			if (0 <= iNewBushouID && iNewBushouID < 最大数::武将情報::配列数) {
				int iNewBushouIntMaxUpByKahou = Get_最大智才家宝上昇値(iNewBushouID);
				p武将情報[iNewBushouID].最大智才 = iNewBushouPureIntMax + iNewBushouIntMaxUpByKahou;
			}

			// 野望増加タイプ：D 香木  E 地球儀  F 南蛮時計  10 水墨画  11 十字架  12 聖書  13 玉手箱  14 ビードロ杯  15 遠眼鏡  16 ルソン壺  17 煙草
		}
		else if (0xD <= p家宝情報[iKahouID].家宝分類 && p家宝情報[iKahouID].家宝分類 <= 0x17) {

			// 元の武将の政治能力の素値
			int iOldBushouPureAmbition = 0;
			// 新しい指定の武将は正規の武将であり、商人ではない。
			if (0 <= iOldBushouID && iOldBushouID < 最大数::武将情報::配列数) {
				iOldBushouPureAmbition = Get_元野望(iOldBushouID);
				// 不正な番号は商人ということにする。
			}
			else {
				iOldBushouID = 0xFFFF;
			}

			int iNewBushouPureAmbition = 0;
			// 新しい指定の武将は正規の武将であり、商人ではない。
			if (0 <= iNewBushouID && iNewBushouID < 最大数::武将情報::配列数) {
				iNewBushouPureAmbition = Get_元野望(iNewBushouID);

				// 不正な番号は商人ということにする。
			}
			else {
				iNewBushouID = 0xFFFF; 
			}

			// 対象の家宝の所持者を変更する。
			p家宝情報[iKahouID].所有武将【武将番号】 = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

			// 新しい指定の武将は正規の武将であり、商人ではない。
			if (0 <= iOldBushouID && iOldBushouID < 最大数::武将情報::配列数) {
				int iOldBushouAmbitionUpByKahou = Get_野望家宝上昇値(iOldBushouID);
				p武将情報[iOldBushouID].野望 = iOldBushouPureAmbition + iOldBushouAmbitionUpByKahou;
			}

			// 新しい指定の武将は正規の武将であり、商人ではない。
			if (0 <= iNewBushouID && iNewBushouID < 最大数::武将情報::配列数) {
				int iNewBushouAmbitionUpByKahou = Get_野望家宝上昇値(iNewBushouID);
				p武将情報[iNewBushouID].野望 = iNewBushouPureAmbition + iNewBushouAmbitionUpByKahou;
			}

		}

		return true;
	}


	bool Set_家宝上昇値(int iKahouID, int iNewUpValue) {

		if (!(0 <= iKahouID && iKahouID < 最大数::家宝情報::配列数)) {
			return false;
		}

		int iBushouID = p家宝情報[iKahouID].所有武将【武将番号】 - 1;  // 今持ってる武将番号を【配列用】に変更して控えておく
		int 未登場 = p家宝情報[iKahouID].未登場;
		int 消失 = p家宝情報[iKahouID].消失;

		bool ret = false;
		ret = Set_家宝所有者変更(iKahouID, 0xFFFF); // 上昇値を変化させる前に、商人へと返上する
		if (ret == false) {
			return false;
		}

		if (iNewUpValue < 1) {
			iNewUpValue = 1;
		}
		if (iNewUpValue > 10) {
			iNewUpValue = 10;
		}
		p家宝情報[iKahouID].上昇値 = iNewUpValue;

		// 元々が武将が所有していたのであれば...
		if (0 <= iBushouID && iBushouID < 最大数::武将情報::配列数) {
			Set_家宝所有者変更(iKahouID, iBushouID);
		}
		// 武将が所持していなかった場合のみ、未登場や登場を元の値をそのまま
		else {
			p家宝情報[iKahouID].未登場 = 未登場;
			p家宝情報[iKahouID].消失 = 消失;
		}

		return true;
	}



	bool Set_家宝分類(int iKahouID, int 家宝分類) {

		if (!(0 <= iKahouID && iKahouID < 最大数::家宝情報::配列数)) {
			return false;
		}

		int iBushouID = p家宝情報[iKahouID].所有武将【武将番号】 - 1;  // 今持ってる武将番号を【配列用】に変更して控えておく
		int 未登場 = p家宝情報[iKahouID].未登場;
		int 消失 = p家宝情報[iKahouID].消失;

		bool ret = false;
		ret = Set_家宝所有者変更(iKahouID, 0xFFFF); // 家宝分類を変化させる前に、商人へと返上する
		if (ret == false) {
			return false;
		}

		if (家宝分類 < 家宝分類::茶碗) {
			家宝分類 = 家宝分類::茶碗;
		}
		if (家宝分類 > 家宝分類::煙草) {
			家宝分類 = 家宝分類::煙草;
		}
		p家宝情報[iKahouID].家宝分類 = 家宝分類;

		// 元々が武将が所有していたのであれば...
		if (0 <= iBushouID && iBushouID < 最大数::武将情報::配列数) {
			Set_家宝所有者変更(iKahouID, iBushouID);
		}
		// 武将が所持していなかった場合のみ、未登場や登場を元の値をそのまま
		else {
			p家宝情報[iKahouID].未登場 = 未登場;
			p家宝情報[iKahouID].消失 = 消失;
		}
		return true;
	}


}