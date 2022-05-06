#include <cassert>
#include <math.h>
#include "ゲームデータ構造.h"
#include <map>
using namespace std;


extern HMODULE hModuleTSMod;

using PFNISBATTLEMODE				 = int (WINAPI *)();
PFNISBATTLEMODE p_IsBattleMode = NULL;

using PFNGETCURINCREMENTTURNINBATTLE = int (WINAPI *)();
PFNGETCURINCREMENTTURNINBATTLE p_GetCurIncrementTurnInBattle = NULL;

using PFNGETREMAINTURNINBATTLE		 = int (WINAPI *)();
PFNGETREMAINTURNINBATTLE p_GetRemainTurnInBattle = NULL;

using PFNGETCASTLETURNINBATTLE		 = int (WINAPI *)();
PFNGETCASTLETURNINBATTLE p_GetCastleTurnInBattle = NULL;



// TSModにしかない動画再生関数のポインタの登録
void _戦闘関連登録() {
	// 戦闘中かどうか。（メイン画面上の戦争も戦争中とみなす）
	p_IsBattleMode = (PFNISBATTLEMODE)GetProcAddress( hModuleTSMod, "Extern_IsBattleMode" );

	// 現在のTSMod内の素のiCurIncrementTurnInBattle値。画面も戦争中かどうかの判定に必要。
	p_GetCurIncrementTurnInBattle = (PFNGETCURINCREMENTTURNINBATTLE)GetProcAddress( hModuleTSMod, "Extern_GetCurIncrementTurnInBattle" );

	// 残りターン取得用の関数
	p_GetRemainTurnInBattle = (PFNGETREMAINTURNINBATTLE)GetProcAddress( hModuleTSMod, "Extern_getRemainTurnInBattle" );

	// 現在のTSMod内の素のiCurIncrementTurnInBattle値。画面も戦争中かどうかの判定に必要。
	p_GetCastleTurnInBattle = (PFNGETCASTLETURNINBATTLE)GetProcAddress( hModuleTSMod, "Extern_getCastleTurnInBattle" );

}





//------------------------------------------------以下 HEX関係の定義
#define GAMEDATASTRUCT_CASTLE_HEX_ROLE_ADDRESS	0x4D5182	// 城内の役割の概念のデータのアドレス(18*16バイト)
#define GAMEDATASTRUCT_CASTLE_HEX_HIGH_ADDRESS	0x4D555A	// 城内の高さの概念のデータのアドレス(18*16バイト)


#define GAMEDATASTRUCT_FIELD_HEX_ROLE_ADDRESS	0x4D5182	// 野戦の役割の概念のデータのアドレス(41*24バイト)
#define GAMEDATASTRUCT_FIELD_HEX_UNIT_POS_ADDRESS	0x4D5932	// 野戦でユニットがいる位置がポツリポツリ。現在表示中のHEXマップでほとんどがFF、ユニットいるところは、ユニット番号が入っている。
#define GAMEDATASTRUCT_CASTLE_HEX_UNIT_POS_ADDRESS	0x4D5932	// 攻城戦でユニットがいる位置がポツリポツリ。現在表示中のHEXマップでほとんどがFF、ユニットいるところは、ユニット番号が入っている。
																// 野戦と共通のアドレス。
#define GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_ADDRESS	0x4D5D58	// HEXマップにおける各ユニットの情報(1人32bit) x 1城から出てくる８人 × １野戦あたり９城で合計 72人x32bit
#define GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM	72			// HEXマップにおけるユニットの最大数。1城から出てくる８人 × １野戦あたり９城

#define GAMEDATASTRUCT_CASTLE_HEX_FIRE_ROLE_ADDRESS	0x4D4DAA	// 城内の火の手関連の概念のデータのアドレス(18*16バイト)

#define GAMEDATASTRUCT_FIELD_HEX_COLS			41	// 野戦のHEXの横の数
#define GAMEDATASTRUCT_FIELD_HEX_ROWS			24	// 野戦のHEXの縦の数

#define GAMEDATASTRUCT_CASTLE_HEX_COLS			18	// 攻城戦のHEXの横の数
#define GAMEDATASTRUCT_CASTLE_HEX_ROWS			16	// 攻城戦のHEXの縦の数

#define GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_ADDRESS	0x4D4D48	//  ヘックスマップにおいて、この戦争に関わっている「大名・軍団・総大将・[攻め手・受け手・中立]」情報
#define GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_NUM		9			//  戦争に関係する大名は最大９大名まで。


// 戦闘画面の城内ヘックスの役割のバイト列
union NB6CASTLE_HEX_ROLE {
	BYTE index[GAMEDATASTRUCT_CASTLE_HEX_COLS * GAMEDATASTRUCT_CASTLE_HEX_ROWS];				// バイト列のインデックスとしてみた場合
	struct {
		BYTE pos_x[GAMEDATASTRUCT_CASTLE_HEX_COLS];				// 18桁、16行として見た場合;
	} pos_y[GAMEDATASTRUCT_CASTLE_HEX_ROWS];
};

// 戦闘画面の城内ヘックスの高さのバイト列
union NB6CASTLE_HEX_HIGH {
	BYTE index[GAMEDATASTRUCT_CASTLE_HEX_COLS * GAMEDATASTRUCT_CASTLE_HEX_ROWS];				// バイト列のインデックスとしてみた場合
	struct {
		BYTE pos_x[GAMEDATASTRUCT_CASTLE_HEX_COLS];				// 18桁、16行として見た場合;
	} pos_y[GAMEDATASTRUCT_CASTLE_HEX_ROWS];
};

// 城攻時のユニットのマップ内のポジション
union NB6CASTLE_HEX_UNIT_POS {
	BYTE index[GAMEDATASTRUCT_CASTLE_HEX_COLS * GAMEDATASTRUCT_CASTLE_HEX_ROWS];				// バイト列のインデックスとしてみた場合
	struct {
		BYTE pos_x[GAMEDATASTRUCT_CASTLE_HEX_COLS];				// 18桁、16行として見た場合;
	} pos_y[GAMEDATASTRUCT_CASTLE_HEX_ROWS];
};

// 野戦時のヘックスの役割のバイト列
union NB6FIELD_HEX_ROLE {
	BYTE index[GAMEDATASTRUCT_FIELD_HEX_COLS * GAMEDATASTRUCT_FIELD_HEX_ROWS];				// バイト列のインデックスとしてみた場合
	struct {
		BYTE pos_x[GAMEDATASTRUCT_FIELD_HEX_COLS];				// 41桁、24行として見た場合;
	} pos_y[GAMEDATASTRUCT_FIELD_HEX_ROWS];
};

// 野戦時のユニットのマップ内のポジション
union NB6FIELD_HEX_UNIT_POS {
	BYTE index[GAMEDATASTRUCT_FIELD_HEX_COLS * GAMEDATASTRUCT_FIELD_HEX_ROWS];				// バイト列のインデックスとしてみた場合
	struct {
		BYTE pos_x[GAMEDATASTRUCT_FIELD_HEX_COLS];				// 41桁、24行として見た場合;
	} pos_y[GAMEDATASTRUCT_FIELD_HEX_ROWS];
};

// このユニット番号
struct NB6BUSHOU_HEX_UNIT_INFO {
	WORD bushou;					// 武将番号。1大きい数の方。武将配列番号に治すには-1すること。
	WORD junban;					// この値はターン順番。戦争において、この数値が若い軍団から順番が回るということ。
	int	 pos_x;						// 行内におけるpos_x。捕まったり、退却したりして、戦場から居なくなると、0xFFFF
	int	 pos_y;						// 行内におけるpos_y。捕まったり、退却したりして、戦場から居なくなると、0xFFFF
	BYTE movepower;					// 移動力残量。0x1～0xFぐらいの数値が入っている。
	WORD _undef2;					// 不明2 ユニット存在してるのはFFFF、していないのは
	BYTE _undef3;					// 不明1
	BYTE _undef4;					// 不明1
	BYTE _undef5;					// 不明1
	WORD _what1;					// 何か意味がありそう。1～8ぐらいの数値が入っている。
	WORD _undef6;					// ほぼ0x0000
	WORD _undef7;					// ほぼ0xFFFF
	BYTE konran:4;					// 1=通常混乱 2=大混乱
	BYTE bEnd:4;					// 行動済フラグ。0x2=行動済み, 0x0=未行動
	BYTE _what4;					// 何か意味がありそう。存在してる武将は、｢0x2｣が多い
	WORD _what5;					// 何か意味がありそう。存在してる武将は、｢0x70｣が多い
	int	 _undef8;					// 不明
};

// ヘックスマップにおける。担当ターン情報や、大名、軍団など。
struct NB6GUNDAN_HEX_INFO {
	int _undef;			// 不明
	int daimyo;			// 現在ターンの大名番号
	int gundan;			// 現在ターンの軍団番号
	int seiryoku;		// 現在ターンの勢力。野戦や攻城戦のヘックスマップ内において、今どちらのターン中なのか、1=受け手、2=攻め手
						// 恐らく、1＝受けて、２＝攻めて、３＝同盟、４＝中立
};

// ヘックスマップにおいて、この戦争に関わっている「大名・軍団・総大将・[攻め手・受け手・中立]」情報
struct NB6WAR_JOINT_DAIMYO_HEX_GROUP_INFO {
	WORD daimyo;		// 大名番号
	WORD gundan;		// 軍団番号
	WORD soudaisho;		// 総大将の武将番号
	WORD group;			// 何番が攻側か、受側か、などは、不定。あくまでも、戦闘開始時の攻め側大名と同じグループが攻め側の援軍、受側の大名と同じグループが受側、それ以外が中立である。
	WORD _undef;		// 特になにもなし。must 0000
};


NB6CASTLE_HEX_ROLE	*const _nb6castle_hex_role = (NB6CASTLE_HEX_ROLE *)GAMEDATASTRUCT_CASTLE_HEX_ROLE_ADDRESS;
NB6CASTLE_HEX_HIGH	*const _nb6castle_hex_high = (NB6CASTLE_HEX_HIGH *)GAMEDATASTRUCT_CASTLE_HEX_HIGH_ADDRESS;

NB6CASTLE_HEX_ROLE *const _nb6fire_hex_role = (NB6CASTLE_HEX_ROLE *)GAMEDATASTRUCT_CASTLE_HEX_FIRE_ROLE_ADDRESS;

NB6FIELD_HEX_ROLE  *const _nb6field_hex_role = (NB6FIELD_HEX_ROLE *)GAMEDATASTRUCT_FIELD_HEX_ROLE_ADDRESS;


NB6CASTLE_HEX_UNIT_POS *const _nb6castle_hex_unit_pos = (NB6CASTLE_HEX_UNIT_POS *)GAMEDATASTRUCT_CASTLE_HEX_UNIT_POS_ADDRESS;
NB6FIELD_HEX_UNIT_POS  *const _nb6field_hex_unit_pos  = (NB6FIELD_HEX_UNIT_POS *)GAMEDATASTRUCT_FIELD_HEX_UNIT_POS_ADDRESS;

NB6BUSHOU_HEX_UNIT_INFO *const nb6bushou_hex_unit_info = (NB6BUSHOU_HEX_UNIT_INFO *)GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_ADDRESS; // 戦場における各武将の情報

NB6WAR_JOINT_DAIMYO_HEX_GROUP_INFO *const nb6war_joint_daimyo_hex_group_info = (NB6WAR_JOINT_DAIMYO_HEX_GROUP_INFO *)GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_ADDRESS; // 戦場に参加した大名や総大将の情報

extern NB6FIELD_HEX_ROLE *const _nb6field_hex_role;
extern NB6CASTLE_HEX_ROLE *const _nb6castle_hex_role;
#define							  nb6castle_hex_role		_nb6castle_hex_role[0]
extern NB6CASTLE_HEX_HIGH *const _nb6castle_hex_high;
#define							  nb6castle_hex_high		_nb6castle_hex_high[0]

extern NB6FIELD_HEX_ROLE *const _nb6field_hex_role;
#define							 nb6field_hex_role			_nb6field_hex_role[0]

extern NB6CASTLE_HEX_ROLE *const _nb6fire_hex_role;
#define							  nb6fire_hex_role			_nb6fire_hex_role[0]

extern NB6CASTLE_HEX_UNIT_POS *const _nb6castle_hex_unit_pos;
#define							      nb6castle_hex_unit_pos		_nb6castle_hex_unit_pos[0]
extern NB6FIELD_HEX_UNIT_POS *const  _nb6field_hex_unit_pos;
#define							      nb6field_hex_unit_pos			_nb6field_hex_unit_pos[0]

extern NB6BUSHOU_HEX_UNIT_INFO *const nb6bushou_hex_unit_info;
extern NB6GUNDAN_HEX_INFO	   *const _nb6gundan_hex_info;
#define							      nb6gundan_hex_info		_nb6gundan_hex_info[0]

extern 戦争開始パラメタ型 開始パラメタ;
//------------------------------------------------以上 HEX関係の定義


namespace 関数 {

	// 現在進行中の戦争に関わっているiDaimyoIDのリスト。(出陣しているかどうかは関係ない)
	番号リスト型 Get_参戦の大名番号リスト【配列用】() {
		vector<int> list;
		if ( Is_野戦中() || Is_攻城戦中() ) {
			// 参加大名番号を検索して、
			for ( int ix=0; ix < GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_NUM; ix++ ) {

				int iDaimyoID = (int)nb6war_joint_daimyo_hex_group_info[ix].daimyo - 1;
				// 範囲内であれば、リストに追加
				if ( 0 <= iDaimyoID && iDaimyoID < 最大数::大名情報::配列数 ) {
					// 該当の値がすでにlist内にあるか
					vector<int>::iterator  iter = std::find( list.begin(), list.end() , iDaimyoID );
					// 存在しなければ…
					if ( iter == list.end() ) {
						// 追加
						list.push_back( iDaimyoID );
					}
				}
			}
		}
		
		return list;
	}

	// 現在進行中の戦争に関わっているiGundanIDのリスト。(出陣しているかどうかは関係ない)
	番号リスト型 Get_参戦の軍団番号リスト【配列用】() {
		vector<int> list;
		if ( Is_野戦中() || Is_攻城戦中() ) {
			// 参加大名番号を検索して、
			for ( int ix=0; ix < GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_NUM; ix++ ) {

				int iGundanID = (int)nb6war_joint_daimyo_hex_group_info[ix].gundan - 1;
				// 範囲内であれば、リストに追加
				if ( 0 <= iGundanID && iGundanID < 最大数::軍団情報::配列数 ) {
					list.push_back( iGundanID );
				}
			}
		}

		return list;
	}


	// 該当の軍団の戦場における立場を返す(不明=0, 直接攻める側=1, 直接守る側=2, 攻める側の援軍=3, 守る側の援軍=4, 中立軍=5)
	int Get_軍団の参戦立場(int 軍団番号【配列用】) {

		int iGundanID = 軍団番号【配列用】;

		if ( !(0 <= iGundanID && iGundanID < 最大数::軍団情報::配列数 ) ) {
			return 参戦立場::不明;
		}

		if ( Is_野戦中() || Is_攻城戦中() ) {

			//----------直接攻撃、もしくは直接守備の場合

			// 指定の軍団の大名ID
			int iDaimyoID = p軍団情報[iGundanID].所属大名【大名番号】-1;

			// 攻撃側の軍団の大名ID
			int iAttackDaimyoID = -1; 
			if ( 0 <= 開始パラメタ.攻撃側軍団【軍団番号】-1 && 開始パラメタ.攻撃側軍団【軍団番号】-1 < 最大数::軍団情報::配列数 ) {
				iAttackDaimyoID = p軍団情報[開始パラメタ.攻撃側軍団【軍団番号】-1].所属大名【大名番号】-1;
			}

			// 守備側の軍団の大名ID
			int iDefendDaimyoID = -1; 
			if ( 0 <= 開始パラメタ.守備側軍団【軍団番号】-1 && 開始パラメタ.守備側軍団【軍団番号】-1 < 最大数::軍団情報::配列数 ) {
				iDefendDaimyoID = p軍団情報[開始パラメタ.守備側軍団【軍団番号】-1].所属大名【大名番号】-1;
			}

			// 指定の軍団の大名は直接攻撃の大名
			if ( iDaimyoID == iAttackDaimyoID ) {
				return 参戦立場::攻撃軍; // 直接攻撃側
			}
			// 指定の軍団の大名は直接守備の大名
			else if ( iDaimyoID == iDefendDaimyoID ) {
				return 参戦立場::守備軍; // 直接防御側
			}


			// 参加大名番号を検索して、攻撃側のグループID、守備側のグループIDを出す。
			for ( int ix=0; ix < GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_NUM; ix++ ) {

				// 援軍や中立軍かチェック
				int JoinGundanID = (int)nb6war_joint_daimyo_hex_group_info[ix].gundan - 1; // 参加軍団ID
				int JoinDaimyoID = (int)nb6war_joint_daimyo_hex_group_info[ix].daimyo - 1; // 参加大名ID

				// 指定の軍団と同じ軍団IDである場合のみ値を返す。
				if (iGundanID == JoinGundanID) {

					// 指定の軍団の大名は直接攻撃の大名
					if (JoinDaimyoID == iAttackDaimyoID) {
						return 参戦立場::攻撃軍; // 直接攻撃側
					}
					// 指定の軍団の大名は直接守備の大名
					else if (JoinDaimyoID == iDefendDaimyoID) {
						return 参戦立場::守備軍; // 直接防御側
					}

					// 2か6なら中立軍。2が中立の親軍で、6が中立の子軍
					else if (nb6war_joint_daimyo_hex_group_info[ix].group == 2 || nb6war_joint_daimyo_hex_group_info[ix].group == 6) {
						// 中立軍
						return 参戦立場::中立軍; // 中立軍
					}
					// 1か5なら援軍の攻撃軍。1が援軍の親軍で、5が援軍の子軍
					else if (nb6war_joint_daimyo_hex_group_info[ix].group == 1 || nb6war_joint_daimyo_hex_group_info[ix].group == 5) {
						// 攻撃の援軍
						return 参戦立場::攻撃の援軍; // 攻撃の援軍
					}
					// 0か4なら援軍の守備軍。0が援軍の親軍で、4が援軍の子軍
					else if (nb6war_joint_daimyo_hex_group_info[ix].group == 0 || nb6war_joint_daimyo_hex_group_info[ix].group == 4) {
						// 守備の援軍
						return 参戦立場::守備の援軍; // 防御の援軍
					}

				}
			}
		}

		return 参戦立場::不明; // 不明
	}

	// 該当の武将の戦場における立場を返す(不明=0, 直接攻める側=1, 直接守る側=2, 攻める側の援軍=3, 守る側の援軍=4, 中立軍=5)
	int Get_武将の参戦立場(int 武将番号【配列用】) {
		int iBushouID = 武将番号【配列用】;

		// 範囲チェック
		if ( !(0 <= iBushouID && iBushouID < 最大数::武将情報::配列数) ) {
			return 参戦立場::不明;
		}

		// 該当武将の軍団ID入手
		int iGundanID = p武将情報[iBushouID].所属軍団【軍団番号】-1;
		if ( 0 <= iGundanID && iGundanID < 最大数::軍団情報::配列数 ) {
			return Get_軍団の参戦立場(iGundanID);
		}

		return 参戦立場::不明;
	}

	// 現在の戦において、指定軍団の大将(軍団長や大名のことではなく、戦場においての軍団代表者)
	int Get_参戦軍団の指揮者(int 軍団番号【配列用】) {
		int iGundanID = 軍団番号【配列用】;
		if ( !(0 <= iGundanID && iGundanID < 最大数::軍団情報::配列数 ) ) {
			return 0xFFFF;
		}

		if ( Is_野戦中() || Is_攻城戦中() ) {
			// 参加大名番号を検索して、攻撃側のグループID、守備側のグループIDを出す。
			for ( int ix=0; ix < GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_NUM; ix++ ) {

				int iJointGundanID = (int)nb6war_joint_daimyo_hex_group_info[ix].gundan-1;

				// 指定の軍団を見つけた。
				if ( iGundanID == iJointGundanID ) {
					// 武将番号(+1の方)の範囲に収まっている。
					if ( 0 < nb6war_joint_daimyo_hex_group_info[ix].soudaisho && nb6war_joint_daimyo_hex_group_info[ix].soudaisho <= 最大数::武将情報::配列数 ) {
						return nb6war_joint_daimyo_hex_group_info[ix].soudaisho-1;
					// 武将番号の範囲に収まっていないということは、大名や軍団は決まっているが、総大将が決まっていない。ユニット配置前だと総大将が決まらないので、このような値となる。
					} else {
						return 0xFFFF;
					}
				}
			}
		}

		return 0xFFFF;
	}

}



 // 現在画面に出てて攻城中の城番号。0xFFFFなら城を攻城中ではなく、野戦中。
int _現在攻城中の城番号 = 0xFFFF;


namespace 関数 {

	int Get_戦争残りターン数() {
		if ( p_GetRemainTurnInBattle ) {
			return p_GetRemainTurnInBattle();
		} else {
			return -1;
		}
	}

	int Get_攻城戦ターン数() {
		if ( p_GetCastleTurnInBattle ) {
			return p_GetCastleTurnInBattle();
		} else {
			return -1;
		}
	}

	WORD Get_攻城戦中の城番号() {
		if ( p_IsBattleMode && p_GetCurIncrementTurnInBattle ) {
			if ( p_IsBattleMode() && (p_GetCurIncrementTurnInBattle()>=0) ) {
				return _現在攻城中の城番号;
			}
		}
		return 0xFFFF;
	}

	// 現在画面に出てる戦場は、野戦
	bool Is_野戦中() {
		if ( p_IsBattleMode && p_GetCurIncrementTurnInBattle ) {
			return _現在攻城中の城番号 == 0xFFFF && p_IsBattleMode() && (p_GetCurIncrementTurnInBattle()>=0);
		} else {
			return _現在攻城中の城番号 == 0xFFFF;
		}			
	}

	// 現在画面に出てる戦場は、攻城戦
	bool Is_攻城戦中() {
		if ( p_IsBattleMode && p_GetCurIncrementTurnInBattle ) {
			return ( 0 <= _現在攻城中の城番号-1 && _現在攻城中の城番号-1 < 最大数::城情報::配列数 ) && p_IsBattleMode() && (p_GetCurIncrementTurnInBattle()>=0);
		} else {
			return ( 0 <= _現在攻城中の城番号-1 && _現在攻城中の城番号-1 < 最大数::城情報::配列数 ); 
		}
	}
}


namespace 関数 {

	// 戦場において、該当の武将番号【配列用】の武将は、既に行動済みである。
	// 行動済みならTRUEが、未行動ならFALSEが返ってくる。
	bool Is_武将行動済《戦争画面》(int 武将番号【配列用】) {
		for ( int i=0; i < GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++ ) {
			if ( nb6bushou_hex_unit_info[i].bushou == 武将番号【配列用】+1 ) {
				if ( nb6bushou_hex_unit_info[i].bEnd == 0x2 ) { // 行動済である。
					return TRUE;
				} else {
					return FALSE;
				}
				break;
			}
		}
		return FALSE;
	}

	// 戦場において、該当の武将番号【配列用】の武将は混乱している。
	int Get_武将混乱状態(int 武将番号【配列用】) {
		for ( int i=0; i < GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++ ) {
			if ( nb6bushou_hex_unit_info[i].bushou == 武将番号【配列用】+1 ) {
				return nb6bushou_hex_unit_info[i].konran; // 無し・混乱・大混乱
			}
		}
		return 混乱状態::無し;
	}

	// 戦場において、該当の武将番号【配列用】の武将を混乱させる。
	bool Set_武将混乱状態(int 武将番号【配列用】, int i混乱状態) {
		for ( int i=0; i < GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++ ) {
			if ( nb6bushou_hex_unit_info[i].bushou == 武将番号【配列用】+1 ) {
				nb6bushou_hex_unit_info[i].konran = i混乱状態; // 無し・混乱・大混乱
				if ( i混乱状態 > 0 ) {
					nb6bushou_hex_unit_info[i].bEnd = 0x2; // 行動済。
				}
				武将ユニット状態描画更新《戦争画面》(武将番号【配列用】);
				return TRUE;
			}
		}
		return FALSE;
	}

	int Set_武将移動力残量(int 武将番号【配列用】, int 移動力残量) {
		int iBushouID = 武将番号【配列用】;

		// 移動力を若干回復
		for ( int i=0; i < GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++ ) {
			if ( nb6bushou_hex_unit_info[i].bushou == iBushouID+1 ) {
				nb6bushou_hex_unit_info[i].movepower = 移動力残量;  // 行動パワー設定
				break;
			}
		}
		return 0xFFFF;
	}

	int Get_武将移動力残量(int 武将番号【配列用】) {

		int iBushouID = 武将番号【配列用】;

		// 移動力を若干回復
		for ( int i=0; i < GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++ ) {
			if ( nb6bushou_hex_unit_info[i].bushou == iBushouID+1 ) {
				return nb6bushou_hex_unit_info[i].movepower;
			}
		}
		return -1;
	}
}


/*
戦闘画面、ユニットの混乱や大混乱など、アイコン状態更新
/*
00430619  |. 56             PUSH    ESI                              ; /Arg1
0043061A  |. E8 EB9A0600    CALL    TENSHOU.0049A10A                 ; \TENSHOU.0049A10A
0043061F  |. 83C4 04        ADD     ESP, 4
*/
int pfuncAddress = 0x49A10A;
int pCallFromFuncBattleUnitStatusRepaint = 0x49A10A; //
int iBushouIDOfBattleUnitStatusRepaint = -1;

void FuncBattleUnitStatusRepaintAsm() {
	__asm {
		push iBushouIDOfBattleUnitStatusRepaint
		call pCallFromFuncBattleUnitStatusRepaint
		add esp, 4
	}
}

namespace 関数 {
	void 武将ユニット状態描画更新《戦争画面》(int 武将番号【配列用】) {

		int iBushouID = 武将番号【配列用】;

		if ( !(0 <= iBushouID && iBushouID < 最大数::武将情報::配列数) ) {
			return;
		}

		iBushouIDOfBattleUnitStatusRepaint = iBushouID+1;

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
		FuncBattleUnitStatusRepaintAsm();

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
}

/*
戦闘画面、ユニットの兵数描画。
*
/*
00433F8C  |. 56             PUSH    ESI
00433F8D  |. E8 FE6E0600    CALL    TENSHOU.0049AE90
00433F92  |. 83C4 04        ADD     ESP, 4
*/

int pCallFromFuncBattleUnitNumRepaint = 0x49AE90; //
int iBushouIDOfBattleUnitNumRepaint = -1;

void FuncBattleUnitNumRepaintAsm() {
	__asm {
		PUSH    iBushouIDOfBattleUnitNumRepaint
		CALL    pCallFromFuncBattleUnitNumRepaint
		ADD     ESP, 4
	}
}


namespace 関数 {
	// 
	void 武将ユニット兵数描画更新《戦争画面》(int 武将番号【配列用】) {

		int iBushouID = 武将番号【配列用】;

		if ( !(0 <= iBushouID && iBushouID < 最大数::武将情報::配列数) ) {
			return;
		}

		iBushouIDOfBattleUnitNumRepaint = iBushouID+1;

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
		FuncBattleUnitNumRepaintAsm();

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
}



namespace 関数 {
	// ある野戦ヘックス場所のチップの役割(攻城戦ヘックス役割)を得る
	int Get_野戦ヘックス役割(double x, double y) {
		// 座標値は妥当な範囲か？
		if ( 0<=x && x<= GAMEDATASTRUCT_FIELD_HEX_COLS && 0<=y && y<=GAMEDATASTRUCT_FIELD_HEX_ROWS) {
			// yを座標実値にして、整数化
			int _y = round《整数化》(y);
			// 野戦の偶数行目か奇数行目かで、半身ずらす。偶数行なら、"半HEX"多い値がxに入ってくるため。
			if (_y % 2==1) {
				x = x - 0.5;
			}
			// xを最も近い値の整数化
			int _x = round《整数化》(x);
			// ０より小さくなることもあるので０に
			if ( _x < 0 ) { _x = 0; }
			if ( _x >= GAMEDATASTRUCT_FIELD_HEX_COLS ) { _x = GAMEDATASTRUCT_FIELD_HEX_COLS-1; }
			if ( _y >= GAMEDATASTRUCT_FIELD_HEX_ROWS ) { _y = GAMEDATASTRUCT_FIELD_HEX_ROWS-1; }
			// 該当の場所にあるチップの役割番号(攻城戦ヘックス役割)を返す
			return nb6field_hex_role.pos_y[_y].pos_x[_x];
		} else {
			return -1;
		}
	}

	int Get_野戦ヘックス役割(ヘックス位置型 p) {
		return Get_野戦ヘックス役割(p.Ｘ, p.Ｙ);
	}


	ヘックス位置リスト型 Get_特定の役割の野戦ヘックス位置リスト(int 野戦ヘックス役割) {
		ヘックス位置リスト型 vec;
		for (int x = 0; x < GAMEDATASTRUCT_FIELD_HEX_COLS; x++) {
			for (int y = 0; y < GAMEDATASTRUCT_FIELD_HEX_ROWS; y++) {
				if (nb6field_hex_role.pos_y[y].pos_x[x] == 野戦ヘックス役割) {

					ヘックス位置型 pos;
					if (y % 2 == 1) {
						pos.Ｘ = (double)x + 0.5;
						pos.Ｙ  = y;
					}
					else {
						pos.Ｘ = x;
						pos.Ｙ = y;
					}

					vec.push_back(pos);
				}
			}
		}

		return vec;
	}


	// ある城ヘックス場所のチップの役割(野戦ヘックス役割)を得る
	int Get_攻城戦ヘックス役割(double x, double y) {
		// 座標値は妥当な範囲か？
		if ( 0<=x && x< GAMEDATASTRUCT_CASTLE_HEX_COLS && 0<=y && y< GAMEDATASTRUCT_CASTLE_HEX_ROWS) {
			// yを座標実値にして、整数化
			int _y = round《整数化》(y);
			// 野戦の偶数行目か奇数行目かで、半身ずらす。偶数行なら、"半HEX"多い値がxに入ってくるため。
			if (_y % 2==1) {
				x = x - 0.5;
			}
			// xを最も近い値の整数化
			int _x = round《整数化》(x);
			// ０より小さくなることもあるので０に
			if ( _x < 0 ) { _x = 0; }
			if ( _x >= GAMEDATASTRUCT_CASTLE_HEX_COLS ) { _x = GAMEDATASTRUCT_CASTLE_HEX_COLS-1; }
			if ( _y >= GAMEDATASTRUCT_CASTLE_HEX_ROWS ) { _y = GAMEDATASTRUCT_CASTLE_HEX_ROWS-1; }
			// 該当の場所にあるチップの役割番号(野戦ヘックス役割)を返す
			return nb6castle_hex_role.pos_y[_y].pos_x[_x];
		} else {
			return -1;
		}
	}

	int Get_攻城戦ヘックス役割(ヘックス位置型 p) {
		return Get_攻城戦ヘックス役割(p.Ｘ, p.Ｙ);
	}

	ヘックス位置リスト型 Get_特定の役割の攻城戦ヘックス位置リスト(int 攻城戦ヘックス役割) {
		ヘックス位置リスト型 vec;
		for (int x = 0; x < GAMEDATASTRUCT_CASTLE_HEX_COLS; x++) {
			for (int y = 0; y < GAMEDATASTRUCT_CASTLE_HEX_ROWS; y++) {
				if (nb6castle_hex_role.pos_y[y].pos_x[x] == 攻城戦ヘックス役割) {

					ヘックス位置型 pos;
					if (y % 2 == 1) {
						pos.Ｘ = (double)x + 0.5;
						pos.Ｙ = y;
					}
					else {
						pos.Ｘ = x;
						pos.Ｙ = y;
					}

					vec.push_back(pos);
				}
			}
		}

		return vec;
	}

	// ある城ヘックス場所のチップの高さを得る
	int Get_攻城戦ヘックス高さ(double x, double y) {
		// 座標値は妥当な範囲か？
		if ( 0<=x && x< GAMEDATASTRUCT_CASTLE_HEX_COLS && 0<=y && y< GAMEDATASTRUCT_CASTLE_HEX_ROWS) {
			// yを座標実値にして、整数化
			int _y = round《整数化》(y);
			// 野戦の偶数行目か奇数行目かで、半身ずらす。偶数行なら、"半HEX"多い値がxに入ってくるため。
			if (_y % 2==1) {
				x = x - 0.5;
			}
			// xを最も近い値の整数化
			int _x = round《整数化》(x);
			// ０より小さくなることもあるので０に
			if ( _x < 0 ) { _x = 0; }
			if ( _x >= GAMEDATASTRUCT_CASTLE_HEX_COLS ) { _x = GAMEDATASTRUCT_CASTLE_HEX_COLS-1; }
			if ( _y >= GAMEDATASTRUCT_CASTLE_HEX_ROWS ) { _y = GAMEDATASTRUCT_CASTLE_HEX_ROWS-1; }
			// 該当の場所にあるチップの役割番号(野戦ヘックス役割)を返す
			return nb6castle_hex_high.pos_y[_y].pos_x[_x];
		} else {
			return -1;
		}
	}

	int Get_攻城戦ヘックス高さ(ヘックス位置型 p) {
		return Get_攻城戦ヘックス高さ(p.Ｘ, p.Ｙ);
	}


	// あるヘックス場所のチップの炎の役割(CASTLE_HEX_ROLE)を得る
	// 炎が付いている所は、右の１バイトが1になる。
	int Get_攻城戦ヘックス炎上(double x, double y) {
		// 座標値は妥当な範囲か？
		if ( 0<=x && x< GAMEDATASTRUCT_CASTLE_HEX_COLS && 0<=y && y< GAMEDATASTRUCT_CASTLE_HEX_ROWS) {
			// yを座標実値にして、整数化
			int _y = round《整数化》(y);
			// 野戦の偶数行目か奇数行目かで、半身ずらす。偶数行なら、"半HEX"多い値がxに入ってくるため。
			if (_y % 2==1) {
				x = x - 0.5;
			}
			// xを最も近い値の整数化
			int _x = round《整数化》(x);
			// ０より小さくなることもあるので０に
			if ( _x < 0 ) { _x = 0; }
			if ( _x >= GAMEDATASTRUCT_CASTLE_HEX_COLS ) { _x = GAMEDATASTRUCT_CASTLE_HEX_COLS-1; }
			if ( _y >= GAMEDATASTRUCT_CASTLE_HEX_ROWS ) { _y = GAMEDATASTRUCT_CASTLE_HEX_ROWS-1; }
			// 該当の場所にあるチップの役割番号(野戦ヘックス役割)を返す
			return (nb6fire_hex_role.pos_y[_y].pos_x[_x] & 0xF) == 1;
		} else {
			return -1;
		}
	}


	int Get_攻城戦ヘックス炎上(ヘックス位置型 p) {
		return Get_攻城戦ヘックス炎上(p.Ｘ, p.Ｙ);
	}

	ヘックス位置リスト型 Get_炎上の攻城戦ヘックス位置リスト(int 攻城戦ヘックス炎上) {
		ヘックス位置リスト型 vec;
		for (int x = 0; x < GAMEDATASTRUCT_CASTLE_HEX_COLS; x++) {
			for (int y = 0; y < GAMEDATASTRUCT_CASTLE_HEX_ROWS; y++) {
				if ((nb6fire_hex_role.pos_y[y].pos_x[x] & 0xF) == 攻城戦ヘックス炎上) {

					ヘックス位置型 pos;
					if (y % 2 == 1) {
						pos.Ｘ = (double)x + 0.5;
						pos.Ｙ = y;
					}
					else {
						pos.Ｘ = x;
						pos.Ｙ = y;
					}

					vec.push_back(pos);
				}
			}
		}

		return vec;
	}

	// ヘックス間隔の取得。p1→p2まで何枡移動する必要があるのか(全ての枡は行けるものと仮定する)
	int Get_ヘックス間隔( ヘックス位置型 p1, ヘックス位置型 p2 ) {
		double ax = double(abs(p1.Ｘ-p2.Ｘ));
		double ay = double(abs(p1.Ｙ-p2.Ｙ));
		if ( p1.Ｙ == p2.Ｙ ) { // 同じ行に居るならば…
			return round《整数化》(ax);
		} else if ( ax*2 <= ay ) { // 2点間のX座標の差が2点間のY座標の差の半分以下の場合、Y座標の移動だけで該当ポイントまで到達できる。
			return round《整数化》(ay);
		} else {
			// Xの差 + Yの差 - Yの差の半分
			return round《整数化》( ax + ay - 0.5*ay );
		}
	}

	番号リスト型 Get_出陣中の武将番号リスト【配列用】() {
		vector<int> bArray;

		// 戦場にいる武将から条件を満たすものの移動残量を増やす。
		for ( int i=0; i<GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++ ) {
			if ( nb6bushou_hex_unit_info[i].bushou == 0xFFFF ) { continue; } // 0xFFFFだとそのスロットに武将は居ない。次の人
			if ( nb6bushou_hex_unit_info[i].bushou > 最大数::武将情報::配列数 ) { continue; } // ここで範囲保障しておいてあげる。次の人
			
			int iBushouID = nb6bushou_hex_unit_info[i].bushou - 1;

			if ( 0 <= iBushouID && iBushouID < 最大数::武将情報::配列数 ) {
				if ( p武将戸籍情報[iBushouID].戦死 == 0 && p武将戸籍情報[iBushouID].退却 == 0 ) {
					bArray.push_back( iBushouID );
				}
			}
		}

		return bArray;
	}


	番号リスト型 Get_出陣中の武将番号リスト【配列用】《表示中マップ》() {

		vector<int> bArray;

		if ( Is_攻城戦中() ) {
			for ( int i=0; i<GAMEDATASTRUCT_CASTLE_HEX_COLS * GAMEDATASTRUCT_CASTLE_HEX_ROWS; i++ ) {
				int iBango = nb6castle_hex_unit_pos.index[i];
				if ( 1 <= iBango && iBango <= GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM ) {
					if ( nb6bushou_hex_unit_info[iBango-1].bushou != 0xFFFF ) {
						int iBushouID = nb6bushou_hex_unit_info[iBango-1].bushou-1;
						if ( 0 <= iBushouID && iBushouID < 最大数::武将情報::配列数 ) {
							if ( p武将戸籍情報[iBushouID].戦死 == 0 && p武将戸籍情報[iBushouID].退却 == 0 ) {
								bArray.push_back( iBushouID );
							}
						}
					}
				}
			}
		}
		if ( Is_野戦中() ) {
			for ( int i=0; i<GAMEDATASTRUCT_FIELD_HEX_COLS * GAMEDATASTRUCT_FIELD_HEX_ROWS; i++ ) {
				int iBango = nb6field_hex_unit_pos.index[i];
				if ( 1 <= iBango && iBango <= GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM ) {
					if ( nb6bushou_hex_unit_info[iBango-1].bushou != 0xFFFF ) {
						int iBushouID = nb6bushou_hex_unit_info[iBango-1].bushou-1;
						if ( 0 <= iBushouID && iBushouID < 最大数::武将情報::配列数 ) {
							if ( p武将戸籍情報[iBushouID].戦死 == 0 && p武将戸籍情報[iBushouID].退却 == 0 ) {
								bArray.push_back( iBushouID );
							}
						}
					}
				}
			}
		}
		return bArray;
	}

	// 指定の武将ＩＤの武将がどこにいるのか？ 居ない場合、p(x=0xFFFF, y=0xFFFF) が返ってくる。
	ヘックス位置型 Get_武将の野戦ヘックス位置(int 武将番号【配列用】) {

		ヘックス位置型 pos( 0xFFFF, 0xFFFF );

		if ( !(0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数) ) {
			return pos;
		}
		if ( !Is_野戦中() ) {
			return pos;
		}

		// 戦場にいる武将から条件を満たすものの移動残量を増やす。
		for ( int i=0; i<GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++ ) {
			if ( nb6bushou_hex_unit_info[i].bushou == 0xFFFF ) { continue; } // 0xFFFFだとそのスロットに武将は居ない。次の人
			if ( nb6bushou_hex_unit_info[i].bushou > 最大数::武将情報::配列数 ) { continue; } // ここで範囲保障しておいてあげる。次の人

			// 探してる武将が、表示中の野戦に居た!!
			if ( 武将番号【配列用】 == nb6bushou_hex_unit_info[i].bushou - 1 ) {
				int x = nb6bushou_hex_unit_info[i].pos_x;
				int y = nb6bushou_hex_unit_info[i].pos_y;

				if ( x==0xFFFF ) {
					return pos;
				}

				// yを座標実値にして、整数化
				pos.Ｙ = y;

				// 野戦の偶数行目か奇数行目かで、半身ずらす。偶数行なら、"座標を0.5分右にずらす。
				if (y % 2==1) {
					pos.Ｘ = x + 0.5;
				} else {
					pos.Ｘ = x;
				}

				return pos;
			}
		}

		return pos;
	}



	// 指定の武将ＩＤの武将がどこにいるのか？ 居ない場合、p(x=0xFFFF, y=0xFFFF) が返ってくる。
	ヘックス位置型 Get_武将の攻城戦ヘックス位置(int 武将番号【配列用】) {
		ヘックス位置型 pos( 0xFFFF, 0xFFFF );

		if ( !(0 <= 武将番号【配列用】 && 武将番号【配列用】 < 最大数::武将情報::配列数) ) {
			return pos;
		}
		if ( !Is_攻城戦中() ) {
			return pos;
		}

		// 戦場にいる武将から条件を満たすものの移動残量を増やす。
		for ( int i=0; i<GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++ ) {
			if ( nb6bushou_hex_unit_info[i].bushou == 0xFFFF ) { continue; } // 0xFFFFだとそのスロットに武将は居ない。次の人
			if ( nb6bushou_hex_unit_info[i].bushou > 最大数::武将情報::配列数 ) { continue; } // ここで範囲保障しておいてあげる。次の人

			// 探してる武将が、表示中の攻城戦闘に居た!!
			if ( 武将番号【配列用】 == nb6bushou_hex_unit_info[i].bushou - 1 ) {
				int x = nb6bushou_hex_unit_info[i].pos_x;
				int y = nb6bushou_hex_unit_info[i].pos_y;

				if ( x==0xFFFF ) {
					return pos;
				}

				// yを座標実値にして、整数化
				pos.Ｙ = y;

				// 野戦の偶数行目か奇数行目かで、半身ずらす。偶数行なら、"座標を0.5分右にずらす。
				if (y % 2==1) {
					pos.Ｘ = x + 0.5;
				} else {
					pos.Ｘ = x;
				}

				return pos;
			}
		}

		return pos;
	}


	// フィールドヘックスの座標→普通の３次元座標(左手デカルト・音と同じへ)
	３Ｄ位置型 野戦ヘックス位置→３Ｄ位置(ヘックス位置型 p) {
		３Ｄ位置型 p_real;
		p_real.Ｘ = p.Ｘ - 野戦ヘックス::中心Ｘ;
		p_real.Ｚ = (p.Ｙ - 野戦ヘックス::中心Ｙ) * ( sqrt(3.0f) / 2.0f ) * -1; // sin60°
		if ( p_real.Ｚ == 0 ) { p_real.Ｚ = 0; } // アホみたいだが、"-0"とならないようにする。

		// yの高さを決めるにあたって、低山なら1, 中山なら2, 高山なら3とする。
		int iHexRole = Get_野戦ヘックス役割( p.Ｘ, p.Ｙ );

		if ( iHexRole == 野戦ヘックス役割::高山 ) {
			p_real.Ｙ = 3;
		} else if ( iHexRole == 野戦ヘックス役割::中山 ) {
			p_real.Ｙ = 2;
		} else if ( iHexRole == 野戦ヘックス役割::低山 ) {
			p_real.Ｙ = 1;
		} else {
			p_real.Ｙ = 0;
		}
		return p_real;
	}

	// 普通の３次元座標(左手デカルト)→フィールドヘックスの座標へ
	ヘックス位置型 ３Ｄ位置→野戦ヘックス位置(３Ｄ位置型 p) {
		ヘックス位置型 p_hex;
		p_hex.Ｘ = round《整数化》(p.Ｘ + 野戦ヘックス::中心Ｘ);
		p_hex.Ｙ = round《二分の一吸着化》((2.0f / sqrt(3.0f) ) * (p.Ｚ) * -1 + 野戦ヘックス::中心Ｙ);
		return p_hex;
	}

	// 城ヘックスの座標→普通の３次元座標(左手デカルト・音と同じへ)
	３Ｄ位置型 攻城戦ヘックス位置→３Ｄ位置(ヘックス位置型 p) {
		３Ｄ位置型 p_real;
		p_real.Ｘ = p.Ｘ - 野戦ヘックス::中心Ｘ;
		p_real.Ｚ = (p.Ｙ - 野戦ヘックス::中心Ｙ) * ( sqrt(3.0f) / 2.0f ) * -1; // sin60°
		if ( p_real.Ｚ == 0 ) { p_real.Ｚ = 0; } // アホみたいだが、"-0"とならないようにする。

		// yの高さを決めるにあたって城の高さ情報を当てはめる。
		int iHexHigh = Get_攻城戦ヘックス高さ( p.Ｘ, p.Ｙ );
		p_real.Ｙ = iHexHigh;
		return p_real;
	}

	// 普通の３次元座標(左手デカルト)→城ヘックスの座標へ
	ヘックス位置型 ３Ｄ位置→攻城戦ヘックス位置(３Ｄ位置型 p) {
		ヘックス位置型 p_hex;
		p_hex.Ｘ = round《整数化》(p.Ｘ + 野戦ヘックス::中心Ｘ);
		p_hex.Ｙ = round《二分の一吸着化》((2.0f / sqrt(3.0f) ) * (p.Ｚ) * -1 + 野戦ヘックス::中心Ｙ);
		return p_hex;
	}

	// ２点間座標の差
	ヘックスベクトル型 operator-(ヘックス位置型 &p1, ヘックス位置型 &p2) {
		ヘックスベクトル型 v;
		v.Ｘ = p1.Ｘ - p2.Ｘ;
		v.Ｙ = p1.Ｙ - p2.Ｙ;
		return v;
	}

}