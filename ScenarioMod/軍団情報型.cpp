#include <cassert>
#include <algorithm>
#include "ゲームデータ構造.h"






namespace 関数 {


	// 軍団に所属する兵数を得る
	int Get_軍団兵数(int 軍団番号【配列用】) {
		int i兵数 = 0;
		for (int i = 0; i<最大数::武将情報::配列数; i++) {
			if (p武将情報[i].所属軍団【軍団番号】 - 1 == 軍団番号【配列用】) {
				if (p武将戸籍情報[i].状態 <= 状態::現役) { // 大名, 軍団長, 現役 でカウント
					i兵数 += p武将情報[i].兵数;
				}
			}
		}
		return i兵数;
	}

	// 全ての有効な軍団リストを得る
	番号リスト型 Get_軍団番号リスト【配列用】() {
		番号リスト型 list;

		// 該当の大名ＩＤに属する軍団をリストに加える
		for (int i軍団ID = 0; i軍団ID < 最大数::軍団情報::配列数; i軍団ID++) {
			if (p軍団情報[i軍団ID].軍団長【武将番号】 != 0xFFFF) {
				list.push_back(i軍団ID);
			}
		}

		return list;
	}

	番号リスト型 Get_軍団麾下武将番号リスト【配列用】(int 軍団番号【配列用】) {
		// それ以外は何も入れずに返す。
		番号リスト型 list;

		for (int i = 0; i<最大数::武将情報::配列数; i++) {
			if (p武将情報[i].所属軍団【軍団番号】 - 1 == 軍団番号【配列用】) {
				if (p武将戸籍情報[i].状態 <= 状態::現役) { // 大名, 軍団長, 現役 でカウント
					list.push_back(i);
				}
			}
		}
		return list;

	}


	// 特定の大名麾下の軍団リストを得る
	番号リスト型 Get_大名麾下軍団番号リスト【配列用】(int 大名番号【配列用】) {
		番号リスト型 list;

		if (0 <= 大名番号【配列用】 && 大名番号【配列用】 < 最大数::大名情報::配列数) {

			// 該当の大名ＩＤに属する軍団をリストに加える
			for (int i軍団ID = 0; i軍団ID < 最大数::軍団情報::配列数; i軍団ID++) {
				if (p軍団情報[i軍団ID].所属大名【大名番号】 - 1 == 大名番号【配列用】) {
					list.push_back(i軍団ID);
				}
			}
		}

		return list;
	}


	// 軍団任命番号の変更(入替)を試みる。失敗すればfalse
	bool Set_軍団割当番号変更(int iGundanID, int iNewWariateNum) {

		// 第１軍団は大名自身。変更は無理。
		if (p軍団情報[iGundanID].軍団割当番号 == 1) {
			return false;
		}

		if (!(1 <= iNewWariateNum && iNewWariateNum <= 8)) {
			return false;
		}


		// 自分の軍団の大名のID
		int iDaimyoID = p軍団情報[iGundanID].所属大名【大名番号】 - 1;

		// 大名麾下で空きスロットとなっている任命番号一覧
		if (0 <= iDaimyoID && iDaimyoID < 最大数::大名情報::配列数) {
			vector<int> sameDaimyoGundanList = Get_大名麾下軍団番号リスト【配列用】(iDaimyoID);
			int iOldNinmeiNum = p軍団情報[iGundanID].軍団割当番号; // 今までの任命番号

			// 別軍団が指定の軍団を利用しているならば、自分の軍団番号をその軍団に差し上げる。
			for each (int iGID in sameDaimyoGundanList) {
				// すでに別軍団で利用されているならば
				if (p軍団情報[iGID].軍団割当番号 == iNewWariateNum) {
					p軍団情報[iGID].軍団割当番号 = iOldNinmeiNum;
					break;
				}
			}

			// 自分は指定の軍団番号となる。
			p軍団情報[iGundanID].軍団割当番号 = iNewWariateNum;

			return true;
		}

		return false;

	}


	// とある大名配下の軍団下にある軍団割当番号のリストを得る。
	// (番号と数を両方を得る。昇順)
	番号リスト型 Get_軍団割当番号リスト(int 大名番号【配列用】) {

		番号リスト型 list;

		if (0 <= 大名番号【配列用】 && 大名番号【配列用】 < 最大数::大名情報::配列数) {

			// 該当の大名ＩＤに属する軍団をリストに加える
			for (int i軍団ID = 0; i軍団ID < 最大数::軍団情報::配列数; i軍団ID++) {
				if (p軍団情報[i軍団ID].所属大名【大名番号】 - 1 == 大名番号【配列用】) {
					list.push_back(p軍団情報[i軍団ID].軍団割当番号);
				}
			}
		}

		std::sort(list.begin(), list.end());//昇順ソート

		return list;
	}

	// とある大名配下の軍団下にある軍団「未」割当番号のリストを得る。
	// (番号と数を両方を得る。昇順)
	番号リスト型 Get_軍団未割当番号リスト(int 大名番号【配列用】) {

		// 割り当てられてるものに、１を入れる
		int 割当番号配列[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

		if (0 <= 大名番号【配列用】 && 大名番号【配列用】 < 最大数::大名情報::配列数) {

			// 該当の大名ＩＤに属する軍団をリストに加える
			for (int i軍団ID = 0; i軍団ID < 最大数::軍団情報::配列数; i軍団ID++) {
				if (p軍団情報[i軍団ID].所属大名【大名番号】 - 1 == 大名番号【配列用】) {
					int g = p軍団情報[i軍団ID].軍団割当番号;
					if (1 <= g && g <= 8) {
						// 割り当てられてるものに、１を入れる
						割当番号配列[g - 1] = 1;
					}
				}
			}
		}

		番号リスト型 未割当リスト;
		for (int ix = 0; ix<8; ix++) {
			if (割当番号配列[ix] == 0) {
				未割当リスト.push_back(ix + 1);
			}
		}

		std::sort(未割当リスト.begin(), 未割当リスト.end());//昇順ソート

		return 未割当リスト;
	}


	bool Set_軍団所属大名(int 軍団番号【配列用】, int 新所属大名番号【配列用】) {

		// 新大名が正当ではない。
		if (!(0 <= 新所属大名番号【配列用】 && 新所属大名番号【配列用】 < 最大数::大名情報::配列数)) {
			return false;
		}

		// 軍団が全部埋まっているならば、
		番号リスト型 glist = Get_軍団割当番号リスト(新所属大名番号【配列用】);
		if (glist.size() == 8) { // 軍団は全部埋まっている
			// 何もできない
			return false;
		}

		int iGundanID = 軍団番号【配列用】;

		if (0 <= iGundanID && iGundanID < 最大数::軍団情報::配列数) {

			// 指定の軍団が現在所属している大名番号を求める
			int iDaimyoID = p軍団情報[iGundanID].所属大名【大名番号】 - 1;
			// 新所属先の大名が、今所属している大名であれば、何もすることはない。
			if (iDaimyoID == 新所属大名番号【配列用】) {
				return true;
			}

			// 軍団割り当て番号が１番は大名自身。これは固定。この場合、何もせず失敗とする。
			if (p軍団情報[iGundanID].軍団割当番号 == 1) {
				return false;
			}

			// 現在、新大名に所属していて、次の軍団【軍団番号】が0xFFFFになっている軍団が、ぶら下がるべきリンクリストの最後だ。
			// ぶら下がることが出来るか、事前にチェックしておく。
			int iLinkEndGundanID = -1;
			for (int iGID = 0; iGID < 最大数::軍団情報::配列数; iGID++) {
				// 
				int iCurDaimyoID = p軍団情報[iGID].所属大名【大名番号】 - 1;

				// 指定の新大名に所属しているならば、
				if (iCurDaimyoID == 新所属大名番号【配列用】) {
					// 次の軍団が無いのであれば、そいつが最終軍団番号
					if (p軍団情報[iGID].次の軍団【軍団番号】 == 0xFFFF) {
						iLinkEndGundanID = iGID + 1;
					}

				}

			}

			// それが範囲に入っていないならば、新大名の軍団リンクリストは、改造か何かしらないが情報が壊れている。
			// 処理終了
			if (!(0 < iLinkEndGundanID && iLinkEndGundanID <= 最大数::軍団情報::配列数)) {
				return false;
			}

			/* 　自軍団
			↓
			○-●-○-○

			というのを

			○-○-○

			とする。
			*/

			int iPrevID = p軍団情報[iGundanID].前の軍団【軍団番号】;
			int iNextID = p軍団情報[iGundanID].次の軍団【軍団番号】;

			// 自分のprevは有効な軍団だ。
			if (0 < iPrevID && iPrevID <= 最大数::軍団情報::配列数) {

				// 自分が先頭ではない軍団で、
				// １つ前の軍団の次のリンク先が自軍団の場合
				if (iPrevID != 0xFFFF && p軍団情報[(iPrevID - 1)].次の軍団【軍団番号】 == iGundanID + 1) {
					// 自軍団ではなく、次の軍団へと繋ぎかえる。
					p軍団情報[(iPrevID - 1)].次の軍団【軍団番号】 = iNextID;
				}
			}

			// 自分のnextは有効な軍団だ。
			if (0 < iNextID && iNextID <= 最大数::軍団情報::配列数) {
				// １つ後の軍団の前のリンク先が自軍団の場合
				if (iNextID != 0xFFFF && p軍団情報[(iNextID - 1)].前の軍団【軍団番号】 == iGundanID + 1) {
					// 自軍団ではなく、前の軍団へと繋ぎかえる。
					p軍団情報[(iNextID - 1)].前の軍団【軍団番号】 = iPrevID;
				}
			}


			/* 　

			○-○

			というのを

			○-○-●

			とする。
			*/



			p軍団情報[iLinkEndGundanID - 1].次の軍団【軍団番号】 = iGundanID + 1; // リンクリストの最後の軍団のnextを自軍団に

			p軍団情報[iGundanID].前の軍団【軍団番号】 = iLinkEndGundanID; // 自軍団の前の軍団は、軍団のリンクリストの最後の軍団

			// 自軍団は、軍団リストの一番最後にくっつく。自軍団のnextは居ない
			p軍団情報[iGundanID].次の軍団【軍団番号】 = 0xFFFF; // 

			// メモリ書き換え
			{
				p軍団情報[iGundanID].軍団割当番号 = 8; // もう不正になってしまっているがもっとも高い確率でセーフなものを取る

				番号リスト型 milist = Get_軍団未割当番号リスト(新所属大名番号【配列用】);
				if (milist.size() > 0) {
					p軍団情報[iGundanID].軍団割当番号 = milist[0]; // 空番号の最初のものを放り込む
				}

				p軍団情報[iGundanID].所属大名【大名番号】 = 新所属大名番号【配列用】 + 1;
			}

			for (int iBushouID = 0; iBushouID < 最大数::武将情報::配列数; iBushouID++) {
				// 指定の軍団に所属している武将は、全て、新大名に所属を変更する。
				if (p武将情報[iBushouID].所属軍団【軍団番号】 == iGundanID + 1) {
					p武将情報[iBushouID].所属大名【大名番号】 = 新所属大名番号【配列用】 + 1;
					p武将情報[iBushouID].仕官年数 = 0; // 士官年数リセット
					p武将情報[iBushouID].内応先大名【大名番号】 = 0xFFFF; // 内応先リセット
					p武将情報[iBushouID].内応状態 = 0; // 内応状態なし
					p武将情報[iBushouID].遺恨状態 = 0; // 遺恨なし
				}
			}


			return true;

		}

		return false;
	}

}

/*
軍団番号を引数として、軍師の武将番号を得る
*/
int pCallFromFuncGetGunshiBushouID = 0x454BE9; //

int iReturnOfBushouIDGetGunshiBushou = 0xFFFF;
int iSigOfGundanIDGetGunshiBushou = 0xFFFF;

void _FuncGetGunshiBushouIDAsm() {
	__asm {
		// 軍団番号が引数
		MOV     ESI, iSigOfGundanIDGetGunshiBushou

			// 軍団番号を引数として、軍師番号を得るための関数を呼び出す
			PUSH    ESI
			CALL    pCallFromFuncGetGunshiBushouID
			ADD     ESP, 4

			MOV iReturnOfBushouIDGetGunshiBushou, EAX // 結果のうち、AXの番号を軍師武将番号として保存

	}
}

namespace 関数 {
	// 軍団の軍師武将を得る。軍師たる者が居なければ0xFFFFが返ってくる。
	int Get_軍師武将番号【配列用】(int 軍団番号【配列用】) {

		if (0 <= 軍団番号【配列用】 && 軍団番号【配列用】 < 最大数::軍団情報::配列数) {

			iSigOfGundanIDGetGunshiBushou = 軍団番号【配列用】 + 1; // 配列用→軍団に変更

			iReturnOfBushouIDGetGunshiBushou = 0xFFFF; // まずは、毎度この値でリセット。

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
			_FuncGetGunshiBushouIDAsm();

			__asm {
				pop edi
					pop esi
					pop esp
					pop edx
					pop ecx
					pop ebx
					pop eax
			}

			iReturnOfBushouIDGetGunshiBushou = iReturnOfBushouIDGetGunshiBushou & 0xFFFF; // EAXのうち、AXの部分だけ利用する。

			// その軍団に軍師が居たならば
			if (0 <= iReturnOfBushouIDGetGunshiBushou - 1 && iReturnOfBushouIDGetGunshiBushou - 1 < 最大数::武将情報::配列数) {
				return iReturnOfBushouIDGetGunshiBushou - 1; // 武将番号→武将番号配列用にして返す
			}
		}

		// 居ない場合や不正な場合は全部これ。
		return 0xFFFF;
	}


	軍団新設候補情報型 Get_軍団新設候補情報(int 大名番号【配列用】) {
		軍団新設候補情報型 ret;
		ret.大名番号【配列用】 = 大名番号【配列用】;
		ret.候補軍団割当番号リスト = 番号リスト型();
		ret.候補城番号【配列用】リスト = 番号リスト型();
		ret.候補武将番号【配列用】リスト = 番号リスト型();
		ret.Is新設可能 = FALSE;

		if (!(0 <= 大名番号【配列用】 && 大名番号【配列用】 < 最大数::大名情報::配列数)) {
			デバッグ出力 << "大名番号【配列用】が範囲外" << endl;
			return ret;
		}

		bool is_gundan_has_empty_slot = false;
		for (int iGundanID = 0; iGundanID < 最大数::軍団情報::配列数; iGundanID++) {
			if (p軍団情報[iGundanID].所属大名【大名番号】 == 0xFFFF &&
				p軍団情報[iGundanID].所属居城【城番号】 == 0xFFFF &&
				p軍団情報[iGundanID].次の軍団【軍団番号】 == 0xFFFF) {
				is_gundan_has_empty_slot = true;
				break;
			}
		}
		if (is_gundan_has_empty_slot == false) {
			デバッグ出力 << "軍団数最大たる" << 最大数::軍団情報::配列数 << "が全て埋まっている" << endl;
			return ret;
		}

		int iDaimyoBushouID = p大名情報[大名番号【配列用】].大名【武将番号】 - 1;
		// 死んで該当軍団にターンが回る間の危険なタイミング。このタイミングは承認者が生存していないので、新設できないものとする。
		if (p武将戸籍情報[iDaimyoBushouID].戦死 || (p武将戸籍情報[iDaimyoBushouID].状態 == 状態::死亡)) {
			return ret;
		}

		// 割り当て候補は要するに、まだ割り当てられていない軍団番号のこと
		ret.候補軍団割当番号リスト = Get_軍団未割当番号リスト(大名番号【配列用】);

		// 指定の大名が支配している全城のリスト
		auto 大名所属城リスト = Get_大名所持城番号リスト【配列用】(大名番号【配列用】);

		// 候補にするのは、指定の大名家支配城のうち、「大名」も「軍団長」も居ない城。
		// 即ち、「非本拠」のものに限る
		for each(int iCastleID in 大名所属城リスト) {
			if (p城情報[iCastleID].本城 == 城::本城::非本拠) {
				ret.候補城番号【配列用】リスト.push_back(iCastleID);
			}
		}

		for (int iBushouID = 0; iBushouID < 最大数::武将情報::配列数; iBushouID++) {

			// まず対象の武将は、指定の大名家の人間である。(大名含む)
			if (p武将情報[iBushouID].所属大名【大名番号】 - 1 == 大名番号【配列用】) {

				// 現役である。(=大名や軍団長やヒメではなく、生存し、登場している一般武将)
				if (p武将戸籍情報[iBushouID].状態 == 状態::現役) {
					// 戦死中ではない
					if (!p武将戸籍情報[iBushouID].戦死) {
						ret.候補武将番号【配列用】リスト.push_back(iBushouID);
					}
				}
			}
		}

		// 軍団がすでに８つある
		if (ret.候補軍団割当番号リスト.size() == 0) {
			ret.Is新設可能 = FALSE;
			return ret;
		}

		// 新軍団長を迎え入れるような余った城は存在しない
		if (ret.候補城番号【配列用】リスト.size() == 0) {
			ret.Is新設可能 = FALSE;
			return ret;
		}

		// そもそも軍団長に任命すべき対象の一般武将が存在しない
		if (ret.候補武将番号【配列用】リスト.size() == 0) {
			ret.Is新設可能 = FALSE;
			return ret;
		}

		ret.Is新設可能 = TRUE;

		return ret;
	}


	int Set_軍団新設(int 武将番号【配列用】, int 城番号【配列用】, 軍団新設候補情報型 安全チェック用軍団新設候補情報) {
		if (安全チェック用軍団新設候補情報.Is新設可能 == FALSE) {
			デバッグ出力 << "軍団新設候補情報型.Is新設可能 が FALSE" << endl;
			return 0xFFFF;
		}

		// 名前長すぎ
		auto& check = 安全チェック用軍団新設候補情報;
		auto& bushous = check.候補武将番号【配列用】リスト;
		auto& castles = check.候補城番号【配列用】リスト;
		auto& gwariates = check.候補軍団割当番号リスト;
		if (bushous.size() == 0 || castles.size() == 0 || gwariates.size() == 0){
			デバッグ出力 << "軍団新設候補情報型の中身データが不正" << endl;
			return 0xFFFF;
		}

		auto bitr = std::find(bushous.begin(), bushous.end(), 武将番号【配列用】);
		// 武将候補以外を指定している。
		if (bitr == bushous.end()) {
			デバッグ出力 << "武将番号【配列用】 が 軍団新設候補情報型.候補武将番号【配列用】リスト にない" << endl;
			return 0xFFFF;
		}

		auto citr = std::find(castles.begin(), castles.end(), 城番号【配列用】);
		// 城候補以外を指定している。
		if (citr == castles.end()) {
			デバッグ出力 << "城番号【配列用】 が 軍団新設候補情報型..候補城番号【配列用】リスト にない" << endl;
			return 0xFFFF;
		}

		// あきスロットを探す
		int iSelfGundanID = 0xFFFF;
		for (int iGundanID = 0; iGundanID < 最大数::軍団情報::配列数; iGundanID++) {
			if (p軍団情報[iGundanID].所属大名【大名番号】 == 0xFFFF &&
				p軍団情報[iGundanID].所属居城【城番号】 == 0xFFFF &&
				p軍団情報[iGundanID].次の軍団【軍団番号】 == 0xFFFF) {
				iSelfGundanID = iGundanID;
				break;
			}
		}

		// なぜか無い。安全チェック用軍団新設候補情の取得の後、Set_軍団新設を呼ぶタイミングがずれているのだろう。
		if (iSelfGundanID == 0xFFFF) {
			return 0xFFFF;
		}


		// まずは、軍団一覧の中から自分がぶら下がるべき軍団を探す。
		// それは「同じ大名番号」に所属していながら「次の軍団【軍団番号】」が65535 すなわち、
		// リンクリストの末尾に所属している軍団である。
		int iPrevGundanID = 0xFFFF;
		for (int iGundanID = 0; iGundanID < 最大数::軍団情報::配列数; iGundanID++) {
			// 大名が一致
			if (p軍団情報[iGundanID].所属大名【大名番号】 == check.大名番号【配列用】 + 1) {
				// 対象の大名内の軍団一覧のうち、末尾の軍団
				if (p軍団情報[iGundanID].次の軍団【軍団番号】 == 0xFFFF) {
					iPrevGundanID = iGundanID;
				}
			}
		}


		if (iPrevGundanID == 0xFFFF) {
			return 0xFFFF;
		}

		// 以上をクリアしていれば、まぁ大丈夫だろう。

		// -------------------------------------------------------------------
		// １つ前の軍団の次を自身とする
		p軍団情報[iPrevGundanID].次の軍団【軍団番号】 = iSelfGundanID + 1;


		// -------------------------------------------------------------------
		// 自分の前の軍団として、リンクリスト末尾の最後の軍団番号を入れる
		p軍団情報[iSelfGundanID].前の軍団【軍団番号】 = iPrevGundanID + 1;
		// 自分自身がリンクリストの最後。
		p軍団情報[iSelfGundanID].次の軍団【軍団番号】 = 0xFFFF;

		// 空いているうちで、一番若い番号を入れる。
		p軍団情報[iSelfGundanID].軍団割当番号 = gwariates[0];

		p軍団情報[iSelfGundanID].所属大名【大名番号】 = check.大名番号【配列用】 + 1;

		p軍団情報[iSelfGundanID].所属居城【城番号】 = 城番号【配列用】 + 1;

		p軍団情報[iSelfGundanID].軍団長【武将番号】 = 武将番号【配列用】 + 1;

		p軍団情報[iSelfGundanID].行動力 = 50;

		Set_軍団役職(iSelfGundanID, 役職::無し);

		p軍団情報[iSelfGundanID].金 = 1000;
		p軍団情報[iSelfGundanID].米 = 1000;

		p軍団情報[iSelfGundanID].鉄砲 = 100;
		p軍団情報[iSelfGundanID].馬 = 100;



		// -------------------------------------------------------------------
		// 城の情報やリンクリストを変更する
		p城情報[城番号【配列用】].所属軍団【軍団番号】 = iSelfGundanID + 1;

		p城情報[城番号【配列用】].本城 = 本城::軍団長;

		// 自分自身(城)をリンクリストから外す。
		// 前の城の「次の城」を、自身ではなく、「自身の次の城」にする。
		if (p城情報[城番号【配列用】].前の城【城番号】 != 0 && p城情報[城番号【配列用】].前の城【城番号】 != 0xFFFF) {
			int _prev = p城情報[城番号【配列用】].前の城【城番号】 - 1;
			p城情報[_prev].次の城【城番号】 = p城情報[城番号【配列用】].次の城【城番号】;
		}

		// 次の城の「前の城」を、自身ではなく、「自身の前の城」にする。
		if (p城情報[城番号【配列用】].次の城【城番号】 != 0 && p城情報[城番号【配列用】].次の城【城番号】 != 0xFFFF) {
			int _next = p城情報[城番号【配列用】].次の城【城番号】 - 1;
			p城情報[_next].前の城【城番号】 = p城情報[城番号【配列用】].前の城【城番号】;
		}


		// 新設なので自分が先頭は確定
		p城情報[城番号【配列用】].前の城【城番号】 = 0;
		// 新設なので自分が最後は確定
		p城情報[城番号【配列用】].次の城【城番号】 = 0xFFFF;

		// -------------------------------------------------------------------

		// -------------------------------------------------------------------
		// 本人のパラメータ
		// 対象の武将の、該当城への移動
		Set_武将転居(武将番号【配列用】, 城番号【配列用】);

		Set_城主(武将番号【配列用】);

		p武将戸籍情報[武将番号【配列用】].状態 = 状態::軍団長;

		// 該当の城に居る人達の所属軍団の書き換え
		for (int iBushouID = 0; iBushouID < 最大数::武将情報::配列数; iBushouID++) {
			if (p武将情報[iBushouID].所属大名【大名番号】 == check.大名番号【配列用】 + 1) {
				if (p武将情報[iBushouID].所属居城【城番号】 == 城番号【配列用】 + 1) {
					if (p武将戸籍情報[iBushouID].状態 == 状態::軍団長 || p武将戸籍情報[iBushouID].状態 == 状態::現役) {
						// 戦死中ではない
						if (!p武将戸籍情報[iBushouID].戦死) {
							p武将情報[iBushouID].所属軍団【軍団番号】 = iSelfGundanID + 1;
						}
					}
				}
			}
		}

		return iSelfGundanID;
	}


	bool Set_非本拠城所属軍団(int 城番号【配列用】, int 新軍団番号【配列用】) {

		if (!(0 <= 城番号【配列用】 && 城番号【配列用】 < 最大数::城情報::配列数)) {
			デバッグ出力 << "城番号が範囲外" << endl;
			return false;
		}

		if (p城情報[城番号【配列用】].本城 == 本城::軍団長 || p城情報[城番号【配列用】].本城 == 本城::大名) {
			デバッグ出力 << "大名や軍団長の本拠地は所持者を移動できない" << endl;
			return false;
		}

		if (!(0 <= 新軍団番号【配列用】 && 新軍団番号【配列用】 < 最大数::軍団情報::配列数)) {
			デバッグ出力 << "軍団番号が範囲外" << endl;
			return false;
		}

		int iGundanID = p城情報[城番号【配列用】].所属軍団【軍団番号】-1;

		if (!(0 <= iGundanID && iGundanID < 最大数::軍団情報::配列数)) {
			デバッグ出力 << "城番号がおそらく未統治城" << endl;
			return false;
		}

		int iOrgDaimyoID = p軍団情報[iGundanID].所属大名【大名番号】 - 1;
		int iDstDaimyoID = p軍団情報[新軍団番号【配列用】].所属大名【大名番号】 - 1;

		if (iOrgDaimyoID != iDstDaimyoID) {
			デバッグ出力 << "城番号と新軍団番号が同じ大名のものではない" << endl;
			return false;
		}

		// -------------------------------------------------------------------
		// まず、元の軍団の城リンクリストから、自分の城を外す
		p城情報[城番号【配列用】].所属軍団【軍団番号】 = 新軍団番号【配列用】 + 1;

		// 自分自身(城)をリンクリストから外す。
		// 前の城の「次の城」を、自身ではなく、「自身の次の城」にする。
		if (p城情報[城番号【配列用】].前の城【城番号】 != 0 && p城情報[城番号【配列用】].前の城【城番号】 != 0xFFFF) {
			int _prev = p城情報[城番号【配列用】].前の城【城番号】 - 1;
			p城情報[_prev].次の城【城番号】 = p城情報[城番号【配列用】].次の城【城番号】;
		}

		// 次の城の「前の城」を、自身ではなく、「自身の前の城」にする。
		if (p城情報[城番号【配列用】].次の城【城番号】 != 0 && p城情報[城番号【配列用】].次の城【城番号】 != 0xFFFF) {
			int _next = p城情報[城番号【配列用】].次の城【城番号】 - 1;
			p城情報[_next].前の城【城番号】 = p城情報[城番号【配列用】].前の城【城番号】;
		}

		// -------------------------------------------------------------------
		// 次に、新軍団の城リンクリストの最後の城を探す
		int iTailCastleID = 0xFFFF;
		for (int iCastleID = 0; iCastleID < 最大数::城情報::配列数; iCastleID++) {
			// 対象の城の所属軍団が、指定の新軍団であり
			if (p城情報[iCastleID].所属軍団【軍団番号】 - 1 == 新軍団番号【配列用】) {
				// その城がリンクリストの最後の城であるならば
				if (p城情報[iCastleID].次の城【城番号】 == 0xFFFF) {
					iTailCastleID = iCastleID;
					break;
				}
			}
		}

		if (iTailCastleID == 0xFFFF) {
			デバッグ出力 << "異常事態!! 城のリンクリストが壊れている!!" << endl;
			return false;
		}

		// 自分は新軍団ではリンクリストの末尾は確定なので次の城はない
		p城情報[城番号【配列用】].次の城【城番号】 = 0xFFFF;

		// 自分の１つ前は、これまで末尾だった城の番号
		p城情報[城番号【配列用】].前の城【城番号】 = iTailCastleID + 1;

		// これまでリンクリストの末尾だった城の次の城が自分
		p城情報[iTailCastleID].次の城【城番号】 = 城番号【配列用】 + 1;

		// -------------------------------------------------------------------
		// その城にいる武将達の所属を変更する
		// 該当の城に居る人達の所属軍団の書き換え
		for (int iBushouID = 0; iBushouID < 最大数::武将情報::配列数; iBushouID++) {
			if (p武将情報[iBushouID].所属大名【大名番号】 == iOrgDaimyoID + 1) {
				if (p武将情報[iBushouID].所属居城【城番号】 == 城番号【配列用】 + 1) {
					if (p武将戸籍情報[iBushouID].状態 == 状態::軍団長 || p武将戸籍情報[iBushouID].状態 == 状態::現役) {
						// 戦死中ではない
						if (!p武将戸籍情報[iBushouID].戦死) {
							p武将情報[iBushouID].所属軍団【軍団番号】 = 新軍団番号【配列用】 + 1;
						}
					}
				}
			}
		}

		return true;

	}

	// 家紋を決めているアルゴ(というか紐づけデータ)が不明なので、
	// とりあえず、簡易なもので代用
	static int _Get_Stub_大名誕生時家紋(int 武将番号【配列用】) {

		if ( ! (0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数) ) {
			デバッグ出力 << "_Get_大名誕生時家紋の武将番号が範囲外" << endl;

			return 0; // 返しようもないので、一旦信長のにしておく。
		}



		const int 最後の正規の家紋の最大数 = 16 * 7; // 「家紋編集画面でみると、まぁ多分７段目ぐらいまでが正規家紋」「最後の１段はユーザー家紋」「間の２行は通常は出すべきものではないハズ」

		// 正規家紋全体の配列(但し、
		map<int, int> 正規の余り家紋リスト;
		for (int k = 0; k < 最後の正規の家紋の最大数; k++) {
			正規の余り家紋リスト.insert(map<int, int>::value_type(k, k));
		}

		// すでに大名が使っている家紋を、正規の余り家紋リストから除去することで、未使用のものだけにする
		for (int iDaimyoID = 0; iDaimyoID < 最大数::大名情報::配列数; iDaimyoID++) {

			int kamon = p大名情報[iDaimyoID].家紋;

			// 対象の家紋番号がリストにないなら、(正規家紋以外なら相手にしない)
			正規の余り家紋リスト.erase(kamon);
		}

		int bloodNormalized = p武将情報[武将番号【配列用】].所属血筋;
		if (bloodNormalized >= 最後の正規の家紋の最大数) { bloodNormalized = 最後の正規の家紋の最大数 - 1; }

		// 正規の余り家紋リストに、大名の武将の血筋番号と同じ家紋番号が未使用であまってるならそれにしておく(血筋番号と家紋番号は72ぐらいまでは一致しているため)
		if (正規の余り家紋リスト.count(bloodNormalized) > 0) {
			; // 何もしない。bloodNormalizedのそのままの数値を採用
		}
		// 正規リスト内に、大名の武将の血筋番号と同じ家紋番号が無い場合は、正規の余り家紋リスト(の余ってるの)
		else {

			// 血縁と同じ家紋が埋まっている場合、72番以下は、所属血縁への密接度合いが高い上に、有名なものが多いだろうから、
			// 72番より大きなもののうち、一番大きなものを選ぶ。
			for (int k = 最後の正規の家紋の最大数; k > 72; k--) {
				if (正規の余り家紋リスト.count(k) > 0) {
					bloodNormalized = k;
					return bloodNormalized;
				}
			}

			// ん～ 72番より大きいのが全て埋まってるなら なんでも良いとするしかないだろう。
			auto itr = 正規の余り家紋リスト.begin();
			bloodNormalized = itr->first;

		}

		return bloodNormalized;
	}


	int Set_軍団独立(int 軍団番号【配列用】) {
		if (!(0 <= 軍団番号【配列用】 && 軍団番号【配列用】 < 最大数::軍団情報::配列数)) {
			return 0xFFFF;
		}

		int iSelfDaimyoID = 0xFFFF;
		for (int iDaimyoID = 0; iDaimyoID < 最大数::大名情報::配列数; iDaimyoID++) {
			// あいているという条件は以下の２つでわかるだろう。
			if (p大名情報[iDaimyoID].大名【武将番号】 == 0xFFFF &&
				p大名情報[iDaimyoID].所属軍団【軍団番号】 == 0xFFFF) {
				iSelfDaimyoID = iDaimyoID;
				break;
			}
		}

		// 空きがなかったらダメ
		if (iSelfDaimyoID == 0xFFFF) {
			return 0xFFFF;
		}

		int iNewDaimyoBushouID = p軍団情報[軍団番号【配列用】].軍団長【武将番号】 - 1;
		// デバッグ出力 << Get_名前(iNewDaimyoBushouID) << endl;
		int iNewDaimyoCastleID = p軍団情報[軍団番号【配列用】].所属居城【城番号】 - 1;
		// デバッグ出力 << Get_城名(iNewDaimyoCastleID) << endl;
		// 軍団長以外が指定されている。即ち、大名自身の(第１軍団相当の)軍団番号が指定されている。
		if (p武将戸籍情報[iNewDaimyoBushouID].状態 != 状態::軍団長) {
			return 0xFFFF;
		}

		// 戦場で死んでいて、メイン画面に戻る前。ダメ
		if (p武将戸籍情報[iNewDaimyoBushouID].戦死) {
			return 0xFFFF;
		}
		
		// ----------------------------------------------------
		// ゴミ掃除
		p大名情報[iSelfDaimyoID].隠居武将【武将番号】 = 0xFFFF;
		p大名情報[iSelfDaimyoID].敵対大名【大名番号】 = 0xFF;
		p大名情報[iSelfDaimyoID].友好大名【大名番号】 = 0xFF;
		p大名情報[iSelfDaimyoID].商人 = 50;
		p大名情報[iSelfDaimyoID].布教済 = 0;
		p大名情報[iSelfDaimyoID].評定済 = 0;
		p大名情報[iSelfDaimyoID].商人不在 = 0;
		if (p武将情報[iNewDaimyoBushouID].職業 == 職業::高家) {
			p大名情報[iSelfDaimyoID].朝廷 = 30;
		}
		else {
			p大名情報[iSelfDaimyoID].朝廷 = 0;
		}


		p大名情報[iSelfDaimyoID].家紋 = _Get_Stub_大名誕生時家紋(iNewDaimyoBushouID);

		Set_大名役職(iSelfDaimyoID, 役職::無し);

		// ----------------------------------------------------
		// 対象の軍団長は、個人として大名となる
		p武将戸籍情報[iNewDaimyoBushouID].状態 = 状態::大名;
		p武将戸籍情報[iNewDaimyoBushouID].身分 = 身分::大名;

		// まずは新設した大名家の大名は、指定の軍団長を新設大名の武将に
		p大名情報[iSelfDaimyoID].大名【武将番号】 = iNewDaimyoBushouID + 1;
		// 大名の本第１軍団となる
		p大名情報[iSelfDaimyoID].所属軍団【軍団番号】 = 軍団番号【配列用】 + 1;

		// ----------------------------------------------------
		// 現在の軍団の所属大名が、新設の大名IDに帰属
		p軍団情報[軍団番号【配列用】].所属大名【大名番号】 = iSelfDaimyoID + 1;

		// 割当番号は１固定
		p軍団情報[軍団番号【配列用】].軍団割当番号 = 1;

		// 軍団長の本拠だったという情報は、大名の本拠へ格上げ
		p大名情報[iSelfDaimyoID].所属居城【城番号】 = iNewDaimyoCastleID + 1;
		p城情報[iNewDaimyoCastleID].本城 = 本城::大名;

		// ----------------------------------------------------
		// リンクリストの変更。自分の軍団だけ、これまでの大名配下の軍団のリンクリストから削除する

		// 自分自身(軍団)をリンクリストから外す。
		// 前の軍団の「次の軍団」を、自身ではなく、「自身の次の軍団」にする。
		if (p軍団情報[軍団番号【配列用】].前の軍団【軍団番号】 != 0 && p軍団情報[軍団番号【配列用】].前の軍団【軍団番号】 != 0xFFFF) {
			int _prev = p軍団情報[軍団番号【配列用】].前の軍団【軍団番号】 - 1;
			p軍団情報[_prev].次の軍団【軍団番号】 = p軍団情報[軍団番号【配列用】].次の軍団【軍団番号】;
		}

		// 次の軍団の「前の軍団」を、自身ではなく、「自身の前の軍団」にする。
		if (p軍団情報[軍団番号【配列用】].次の軍団【軍団番号】 != 0 && p軍団情報[軍団番号【配列用】].次の軍団【軍団番号】 != 0xFFFF) {
			int _next = p軍団情報[軍団番号【配列用】].次の軍団【軍団番号】 - 1;
			p軍団情報[_next].前の軍団【軍団番号】 = p軍団情報[軍団番号【配列用】].前の軍団【軍団番号】;
		}


		// 新設なので自分が先頭は確定
		p軍団情報[軍団番号【配列用】].前の軍団【軍団番号】 = 0;
		// 新設なので自分が最後は確定
		p軍団情報[軍団番号【配列用】].次の軍団【軍団番号】 = 0xFFFF;

		// ----------------------------------------------------
		// 軍団配下武将の所属武将(自分を含む)の所属大名を、新設大名への変更する
		// 士官年数はリセットされる
		for (int iBushouID = 0; iBushouID < 最大数::武将情報::配列数; iBushouID++) {
			if (p武将情報[iBushouID].所属軍団【軍団番号】 == 軍団番号【配列用】 + 1) {
				// 戦死中ではない
				if (!p武将戸籍情報[iBushouID].戦死) {
					p武将情報[iBushouID].所属大名【大名番号】 = iSelfDaimyoID + 1;
					p武将情報[iBushouID].仕官年数 = 0;
				}
			}
		}

		// ----------------------------------------------------
		// 同盟系
		for (int iTargetDaimyoID = 0; iTargetDaimyoID < 最大数::大名情報::配列数; iTargetDaimyoID++) {
			// 友好はまんなか
			Set_友好関係(iSelfDaimyoID, iTargetDaimyoID, 50);
			// 同盟や婚姻はリセット
			Set_同盟関係(iSelfDaimyoID, iTargetDaimyoID, FALSE);
			Set_婚姻関係(iSelfDaimyoID, iTargetDaimyoID, FALSE);
		}
		return iSelfDaimyoID;
	}

	// 対象の大名がプレイヤー担当の大名であるかどうかを判断する。
	// 大名番号【配列用】には配列上の番号(attach-1の数)を渡すこと
	bool Is_プレイヤ担当大名(WORD 大名番号【配列用】) {

		// 大名IDの範囲に収まっていること
		if (0 <= 大名番号【配列用】&& 大名番号【配列用】 < 最大数::大名情報::配列数) {
			// ターゲットの武将の軍団IDがプレイヤーの軍団であるかを返す
			return Is_プレイヤ担当軍団(p大名情報[大名番号【配列用】].所属軍団【軍団番号】 - 1);
		}
		else {
			return false;
		}
	}



	// 対象の軍団がプレイヤー担当軍団の勢力下の軍団であるかどうかを判断する。
	// iTargetGundanIDには配列上の番号(attach-1の数)を渡すこと
	bool Is_プレイヤ担当軍団(WORD 軍団番号【配列用】) {

		if (!(0 <= 軍団番号【配列用】 && 軍団番号【配列用】 < 最大数::軍団情報::配列数)) {
			return false;
		}

		WORD ix【軍団番号】 = 0;
		for (int n番目 = 0; n番目< 最大数::プレイヤ担当軍団情報::配列数; n番目++) {
			// プレイヤーが担当している軍団のＩＤを確保
			ix【軍団番号】 = pプレイヤ担当軍団情報[n番目].担当軍団【軍団番号】;

			// 0xFFFFならばプレイヤーではない
			if (ix【軍団番号】 == 0xFFFF) {
				continue;
			}

			// プレイヤー担当の軍団の大名が、ターゲットとしている対象の軍団の大名と一致するならば、
			// それはプレイヤーの勢力下の軍団である。
			// どうもnb6player8のgundanの値は、内部管理のgundanの値よりも+1されているようである。
			// よってここでは-1する。
			if (ix【軍団番号】 >= 1 && p軍団情報[ix【軍団番号】 - 1].所属大名【大名番号】 == p軍団情報[軍団番号【配列用】].所属大名【大名番号】) {
				return true;
			}
		}

		return false;
	}


	// 対象の武将がいずれかのプレイヤー勢力下の武将である
	bool Is_プレイヤ担当武将(WORD 武将番号【配列用】) {

		// 武将IDの範囲に収まっていること
		if (0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数) {

			// ターゲットの武将の軍団IDがプレイヤーの軍団であるかを返す
			return Is_プレイヤ担当軍団(p武将情報[武将番号【配列用】].所属軍団【軍団番号】 - 1);

		}
		else {
			return false;
		}
	}


}


