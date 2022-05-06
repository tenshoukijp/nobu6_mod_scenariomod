/*
 * 武将情報型 及び、 武将戸籍情報型
 */
#pragma once
#pragma pack(1)

#include <windows.h>

#include "武将情報列挙.h"

/*
	[武将データ(47*532)]

	0-1	前の武将
	2-3 後ろの武将
	4-5	？
	6	政才
	7	戦才
	8	智才
	9-10	政熟 ( min 500 ～ max 2000 )
	11-12	戦熟 ( min 500 ～ max 2000 )
	13-14	智熟 ( min 500 ～ max 2000 )
	15	魅力
	16	野望
	17	忠誠
	18-19	勲功
	20	血筋 0xFFは無縁
	21-22	大名
	23-24	軍団
	25-26	居城
	27-28	内応先 FFFF 無し
	29	兵数
	30	訓練
	31	兵忠
	32	兵態(0=足軽,1=騎馬,2=鉄砲,3=騎馬鉄砲,18まで)
	33	仕官
	34	妻 他に結婚済みフラグあり？
	35	生年
	36-37	親顔NO
	38	思考　（思考アルゴリズム）
	39	aaaabbbb a-相性 b-義理
	40	00aabbcc a-智適 b-戦適 c-政適
	41	技能
	42	職業 0x00無 0x10 忍者 0x20 茶人 0x30 剣豪 0x40 僧侶 0x50 海賊 0x60 高家 0x70 商人 0x80 庶民 0x90 切支丹 0xA0 騎士 0xB0 魔術士 0xC0 魔族
	43-44	兵科・騎馬鉄砲・大砲・鉄甲船
		0123 4445 5566 6777
		0=無関係？,1=鉄甲船,2=騎馬鉄砲,3=大砲
		4,5,6,7=水軍,鉄砲,騎馬,足軽の兵科、MAX5
	45	aabbbccc a-独立 b-勇猛 c-寿命
	46	1234aaa5 1=会見 2-遺恨 3 内応 4-行動 5独立のビットの続き
		a-口調 
*/
/*
	【口調】:
	0 無口			 217 真田幸村・長宗我部元親・島津義久・忍者全員
	1 礼儀正しい	 152 前田利家・明智光秀・立花宗茂・徳川光圀
	2 粗暴			 119 柴田勝家・龍造寺隆信・可児才蔵・佐々木小次郎
	3 高貴			 30 上杉憲政・今川義元・足利義晴・一条兼定
	4 生意気		 180 伊達政宗・三好長慶・鈴木重秀・由比正雪
	5 威厳			 143 織田信長・徳川家康・武田信玄・上杉謙信
	6 饒舌			 145 豊臣秀吉・斎藤道三・松永久秀・足利義昭
	7 一般			 314 本多忠勝・吉川元春・山中鹿之助・史実姫全員
*/

/*
	【武将の思考アルゴリズム】:
	0…名将と呼ばれた人物。有名武将に多い。信長秀吉家康ほか、斎藤道三や松永久秀も。
	総合的なバランスの良いタイプだが、comの場合兵力ばかり増やし、あまり戦争しない。
	1…猛将に多い。柴田勝家や柿崎景家や南部晴政ら。
	2…戦闘に強い武将が多い。剣豪など。
	3…戦闘嫌い。今川氏真ら。政治好き？
	4…板部岡江雪等、坊主・茶人等の文化人系武将。政治好き？
	5…忍者武将や、久武親直・金地院崇伝など。調略好き。
	6…目立たないザコ武将。無能タイプ？
	7…オリジナル姫。性格は不明。
	255…ランダム姫。性格は不明。
*/

struct 武将情報型
{
	WORD 前の武将【武将番号】;	/// <summary>あまり使うことはない</summary>
	WORD 次の武将【武将番号】;	/// <summary>とくに使うことはない</summary>
	WORD _未定義1;				/// <summary>must 0xFFFF</summary>
	byte 最大政才;				/// <summary>政才</summary>
	byte 最大戦才;				/// <summary>戦才</summary>
	byte 最大智才;				/// <summary>智才</summary>
	WORD 政治熟練値;			/// <summary>政熟</summary>
	WORD 戦闘熟練値;			/// <summary>戦熟</summary>
	WORD 智謀熟練値;			/// <summary>智熟</summary>
	char 魅力;					/// <summary>魅力</summary>
	char 野望;					/// <summary>野望</summary>
	char 忠誠;					/// <summary>忠誠</summary>
	WORD 勲功;					/// <summary>勲功</summary>
	byte 所属血筋;				/// <summary>血筋番号 0xFFは無縁</summary>
	WORD 所属大名【大名番号】;	/// <summary>大名</summary>
	WORD 所属軍団【軍団番号】;	/// <summary>軍団</summary>
	WORD 所属居城【城番号】;	/// <summary>居城</summary>
	WORD 内応先大名【大名番号】;/// <summary>内応先 0xFFFFは内応していない</summary>
	byte 兵数;					/// <summary>兵数</summary>
	byte 訓練;					/// <summary>訓練</summary>
	byte 士気;					/// <summary>兵忠</summary>
	byte 兵態;					/// <summary>「兵態::足軽～兵隊::騎馬鉄砲」に対応する。</summary>
	byte 仕官年数;				/// <summary>仕官年数</summary>
	byte _妻;					/// <summary><para>この値は直接利用せず、姫関連や伴侶関連の関数を利用すること。</para><para>この番号が255なら妻はいない。</para><para>255以外の時(例えば3)は、その番号に500足した【武将番号】(例えば503)の女性が妻ということ)。</para><para>そして該当の武将(妻姫武将)の_妻も同じ3の値になっていること。</para></summary>
	byte 生年;					/// <summary>生年。値としては、西暦の値-1454(天翔記基準年)</summary>
	WORD 親顔番号;				/// <summary><para>親顔NO。セーブエディタやシナリオエディタの武将の｢顔番号｣と一致する。</para><para>「kao_24bit」や「武将一覧.xls」の番号とは１つずれる(１つ大きい番号)なので注意。</para></summary>
	byte 思考;					/// <summary>思考アルゴリズム 「思考::名将～思考::その他」に対応する。</summary>
	byte 義理:4;				/// <summary>義理</summary>
	byte 相性:4;				/// <summary>相性 (0-15)</summary>
	byte 政治適性:2;			/// <summary>c-政適 「政治適性::Ｃ～政治適性::Ａ」に対応する。</summary>
	byte 戦闘適性 : 2;			/// <summary>b-戦適 「戦闘適性::Ｃ～戦闘適性::Ａ」に対応する。</summary>
	byte 智謀適性 : 2;			/// <summary>a-智適 「智謀適性::Ｃ～智謀適性::Ａ」に対応する。</summary>
	byte _未定義2:2;			//

	byte 技能一喝:1;			/// <summary>技能・一喝</summary>
	byte 技能暗殺:1;			/// <summary>技能・暗殺</summary>
	byte 技能流出:1;			/// <summary>技能・流出</summary>
	byte 技能煽動:1;			/// <summary>技能・煽動</summary>
	byte 技能流言:1;			/// <summary>技能・流言</summary>
	byte 技能弁舌:1;			/// <summary>技能・弁舌</summary>
	byte 技能焼討:1;			/// <summary>技能・焼討</summary>
	byte 技能挑発:1;			/// <summary>技能・挑発</summary>
	byte 職業;					/// <summary>「職業::無し～職業::魔族」に対応する。</summary>

	byte 足軽適性:3;			/// <summary>足軽適性 「足軽適性::Ｅ～足軽適性::Ｓ」に対応する。</summary>
	byte 騎馬適性:3;			/// <summary>騎馬適性 「騎馬適性::Ｅ～騎馬適性::Ｓ」に対応する。</summary>
	byte _鉄砲適性_hi:2;		/// <summary>鉄砲適性はここでは取得・設定が出来ない。Get_鉄砲適性・Set_鉄砲適性を利用すること。鉄砲適性上位ビット</summary>
	byte _鉄砲適性_lo:1;		/// <summary>鉄砲適性はここでは取得・設定が出来ない。Get_鉄砲適性・Set_鉄砲適性を利用すること。鉄砲適性下位ビット</summary>
	byte 水軍適性:3;			/// <summary>水軍適性 「水軍適性::Ｅ～水軍適性::Ｓ」に対応する。</summary>

	byte 大砲:1;				/// <summary>大砲</summary>
	byte 騎馬鉄砲:1;			/// <summary>騎馬鉄砲</summary>
	byte 鉄甲船:1;				/// <summary>鉄甲船</summary>
	byte _未定義3:1;			// 0

	byte 寿命:3;				/// <summary>寿命 0-7の値</summary>
	byte 勇猛:3;				/// <summary>勇猛 0-7の値</summary>
	byte _独立_hi:2;			/// <summary>独立値はここでは取得・設定が出来ない。Get_独立・Set_独立を利用すること。独立上位ビット</summary>
	byte _独立_lo:1;			/// <summary>独立値はここでは取得・設定が出来ない。Get_独立・Set_独立を利用すること。独立下位ビット</summary>
	byte 口調:3;				/// <summary>口調 「口調::無口～口調::一般」に対応する。</summary>
	byte 行動済:1;				/// <summary>行動済</summary>
	byte 内応状態:1;			/// <summary>内応状態。内応先は、「内応先大名【大名番号】」に入っている。</summary>
	byte 遺恨状態:1;			/// <summary>遺恨状態</summary>
	byte 会見済:1;				/// <summary>会見済</summary>
};




namespace 関数 {

	/// <summary>
	/// 対象の武将の鉄砲の適性値を取得する。
	/// <para>返り値：<see cref="鉄砲適性::Ｅ"/>～<see cref="鉄砲適性::Ｓ"/></para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <returns>鉄砲適性::Ｅ～鉄砲適性::Ｓ</returns>
	int  Get_鉄砲適性(int 武将番号【配列用】);


	/// <summary>
	/// 対象の武将の鉄砲の適性値を設定する。
	/// <para>鉄砲適性値：<see cref="弓適性::Ｅ"/>～<see cref="弓適性::Ｓ"/></para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <param name="鉄砲適性値">設定する鉄砲の適性値。鉄砲適性::Ｅ～鉄砲適性::Ｓ</param>
	void Set_鉄砲適性(int 武将番号【配列用】, int 鉄砲適性値);


	/// <summary>
	/// 対象の武将の弓の適性値を取得する。
	/// <para>返り値：<see cref="弓適性::Ｅ"/>～<see cref="弓適性::Ｓ"/></para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <returns>弓適性::Ｅ～弓適性::Ｓ</returns>
	int  Get_弓適性(int 武将番号【配列用】);


	/// <summary>
	/// 対象の武将の弓の適性値を設定する。
	/// <para>弓適性値：<see cref="弓適性::Ｅ"/>～<see cref="弓適性::Ｓ"/></para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <param name="弓適性値">設定する弓の適性値。弓適性::Ｅ～弓適性::Ｓ</param>
	void Set_弓適性(int 武将番号【配列用】, int 弓適性値);


	/// <summary>
	/// 対象の武将の槍の適性値を取得する。
	/// <para>返り値：<see cref="槍適性::Ｅ"/>～<see cref="槍適性::Ｓ"/></para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <returns>槍適性::Ｅ～槍適性::Ｓ</returns>
	int  Get_槍適性( int 武将番号【配列用】);


	/// <summary>
	/// 対象の武将の槍の適性値を設定する。
	/// <para>槍適性値：<see cref="槍適性::Ｅ"/>～<see cref="槍適性::Ｓ"/></para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <param name="槍適性値">設定する槍の適性値。槍適性::Ｅ～槍適性::Ｓ</param>
	void Set_槍適性( int 武将番号【配列用】, int 槍適性値 );


	/// <summary>
	/// 対象の武将の独立値を取得する。
	/// <para>返り値：0～7の範囲の値</para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <returns>0～7の範囲の値</returns>
	int Get_独立(int 武将番号【配列用】);


	/// <summary>
	/// 対象の武将の独立値を設定する。
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <param name="独立値">0～7の範囲で値を指定する。</param>
	void Set_独立( int 武将番号【配列用】, int 独立値 );


	/// <summary>
	/// 対象の武将の現在の政治値を取得する。(110 ベース 換算)
	/// <para>天翔記で画面上で表示される値は、この値を２倍したもの。</para>
	/// <para>返り値：現在の政治の値。(110 ベース 換算)</para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <returns>返り値：現在の政治の値。(110 ベース 換算)</returns>
	int Get_政治値(int 武将番号【配列用】);


	/// <summary>
	/// 対象の武将の現在の戦闘値を取得する。(110 ベース 換算)
	/// <para>天翔記で画面上で表示される値は、この値を２倍したもの。</para>
	/// <para>返り値：現在の戦闘の値。(110 ベース 換算)</para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <returns>返り値：現在の戦闘の値。(110 ベース 換算)</returns>
	int Get_戦闘値(int 武将番号【配列用】);


	/// <summary>
	/// 対象の武将の現在の智謀値を取得する。(110 ベース 換算)
	/// <para>天翔記で画面上で表示される値は、この値を２倍したもの。</para>
	/// <para>返り値：現在の智謀の値。(110 ベース 換算)</para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <returns>返り値：現在の智謀の値。(110 ベース 換算)</returns>
	int Get_智謀値( int 武将番号【配列用】);


	/// <summary>
	/// 家宝による上げ幅を覗いた、対象武将元来の政治最大値を取得する。(110 ベース 換算)
	/// <para>天翔記で画面上で表示される値は、この値を２倍したもの。</para>
	/// <para>返り値：武将元来の政治の最大値。(110 ベース 換算)</para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <returns>返り値：武将元来の政治の最大値。(110 ベース 換算)</returns>
	int Get_元最大政才(int 武将番号【配列用】);


	/// <summary>
	/// 家宝による上げ幅を覗いた、対象武将元来の戦闘最大値を取得する。(110 ベース 換算)
	/// <para>天翔記で画面上で表示される値は、この値を２倍したもの。</para>
	/// <para>返り値：武将元来の戦闘の最大値。(110 ベース 換算)</para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <returns>返り値：武将元来の戦闘の最大値。(110 ベース 換算)</returns>
	int Get_元最大戦才(int 武将番号【配列用】);


	/// <summary>
	/// 家宝による上げ幅を覗いた、対象武将元来の智謀最大値を取得する。(110 ベース 換算)
	/// <para>天翔記で画面上で表示される値は、この値を２倍したもの。</para>
	/// <para>返り値：武将元来の智謀の最大値。(110 ベース 換算)</para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <returns>返り値：武将元来の智謀の最大値。(110 ベース 換算)</returns>
	int Get_元最大智才(int 武将番号【配列用】);


	/// <summary>
	/// 家宝による上げ幅を覗いた、対象武将元来の野望値を取得する。
	/// <para>返り値：武将元来の野望値。</para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <returns>返り値：武将元来の野望値。</returns>
	int Get_元野望(int 武将番号【配列用】);


	/// <summary>
	/// 官位による上げ幅を覗いた、対象武将元来の魅力値を取得する。
	/// <para>返り値：武将元来の魅力値。</para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <returns>返り値：武将元来の魅力値。</returns>
	int Get_元魅力(int 武将番号【配列用】);


	/// <summary>
	/// 対象の武将の「現在の状況での編成可能な最大兵数」を取得する。
	/// <para>返り値：対象の武将の現在の状況での編成可能な最大兵数</para>
	/// <para>TSModは設定で対象武将が現在の身分・役職・官位を元に「最大の兵数」が変化します。</para>
	/// <para>その値を取得することが出来ます。</para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <returns>返り値：対象の武将の現在の状況での編成可能な最大兵数</returns>
	int Get_武将最大兵数(int 武将番号【配列用】);


	/// <summary>
	/// 武将の｢顔番号｣に対応する『武将の「配列用」の番号』を取得する。
	/// <para>返り値：武将の「配列用」の番号</para>
	/// <para>対象の武将が、その瞬間天翔記に登場していない場合は、<b>｢0xFFFF｣</b>が返ってくるので注意!!</para>
	/// </summary>
	/// <param name="顔番号">対象となる武将の顔番号</param>
	/// <returns>返り値：武将の「配列用」の番号</returns>
	WORD Get_武将番号【配列用】(int 顔番号);


	/// <summary>
	/// 武将の｢姓名(=フルネーム)｣に対応する『武将の「配列用」の番号』を取得する。
	/// <para>返り値：武将の「配列用」の番号</para>
	/// <para>対象の武将が、その瞬間天翔記に登場していない場合は、<b>｢0xFFFF｣</b>が返ってくるので注意!!</para>
	/// </summary>
	/// <param name="武将姓名">対象となる武将の顔番号</param>
	/// <returns>返り値：武将の「配列用」の番号</returns>
	WORD Get_武将番号【配列用】(string 武将姓名);


	/// <summary>
	/// 対象の武将の年齢を取得する。
	/// <para>返り値：対象の武将の年齢</para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <returns>返り値：対象の武将の年齢</returns>
	int Get_武将年齢(int 武将番号【配列用】);


	/// <summary>
	/// 対象の武将の年齢を設定する。
	/// <para>武将年齢は何歳でも自由に設定出来るわけではなく、</para>
	/// <para>計算結果として、「1455年生まれより早く生まれたこと」になる年齢は設定できない</para>
	/// <para>計算結果として、「1708年生まれより遅く生まれたこと」になる年齢も設定できない</para>
	/// <para>返り値：年齢設定に成功すれば真・失敗すれば偽</para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <param name="年齢">新たな年齢</param>
	/// <returns>返り値：年齢設定に成功すれば真・失敗すれば偽</returns>
	bool Set_武将年齢(int 武将番号【配列用】, int 年齢);
}



namespace 関数 {

	/// <summary>
	/// 対象の武将の会見意向を取得する
	/// <para>返り値：対象の武将の会見意向(の種類)</para>
	/// <para><see cref="会見意向::静観"/>～<see cref="会見意向::合戦誘発"/></para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <returns>返り値：会見意向::静観～会見意向::合戦誘発</returns>
	int Get_会見意向(int 武将番号【配列用】);


	/// <summary>
	/// 対象の武将に会見意向を設定する
	/// <para>返り値：対象の武将の会見意向(の種類)</para>
	/// <para><see cref="会見意向::静観"/>～<see cref="会見意向::合戦誘発"/></para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <param name="会見意向"><see cref="会見意向::静観"/>～<see cref="会見意向::合戦誘発"/>を設定する。</param>
	/// <remarks>残念ながら値を設定するだけでAI的に、その行動が重要という指針が増えたわけではないため、それほど意味のあるものではない。</remarks>
	void Set_会見意向(int 武将番号【配列用】, int 会見意向);
}


namespace 関数 {

	/// <summary>
	/// 相性の差分を得る。 最小0(相性最高) 最大8(相性最悪)
	/// <para>返り値：最小が0(=相性最高)～最大が8(=相性最悪)</para>
	/// </summary>
	/// <param name="相性値Ａ">１つ目の相性値</param>
	/// <param name="相性値Ｂ">２つ目の相性値</param>
	/// <returns>返り値：最小が0(=相性最高)～最大が8(=相性最悪)</returns>
	int Get_相性差(int 相性値Ａ, int 相性値Ｂ);


	/// <summary>
	/// 対象の２人の武将の相性の違いを得る。最小0(相性最高) 最大8(相性最悪)
	/// <para>返り値：最小が0(=相性最高)～最大が8(=相性最悪)</para>
	/// </summary>
	/// <param name="武将Ａ番号【配列用】">１人目の武将の「配列用」の番号</param>
	/// <param name="武将Ｂ番号【配列用】">２つ目の武将の「配列用」の番号</param>
	/// <returns>返り値：最小が0(=相性最高)～最大が8(=相性最悪)</returns>
	int Get_武将相性差(int 武将Ａ番号【配列用】, int 武将Ｂ番号【配列用】);
}




/*
	武将名前テーブル(18*500と姫等用に18*32)

	[18バイト]
	0-6		名字
	7-13	名前
	14-15	武将ナンバー(下位12bitは列伝？)
	16	上位4ビットは身分(b0000=隠居,b0001=大名
						　b0010=2=宿老,b0011=3=家老
						　b0100=4=部将,b0101=5=侍大将
						　b0110=6=足軽頭)
		下位4ビット	0大名,1軍長,2現役,3隠居,4浪人,5姫,6待機,7死亡
				
	17	性 0-男 1-女
*/
struct 武将戸籍情報型
{
	char _名字[7];	//名字。Get_名字(int)やSet_名字(int, string)で取得・設定すること。
	char _名前[7];	//名前。Get_名前(int)やSet_名前(int, string)で取得・設定すること。
	WORD 顔番号;	/// <summary>列伝番号と一致。武将ナンバー(下位12bitは列伝？)。<para>セーブエディタやシナリオエディタの武将の｢顔番号｣と一致する。</para><para>「kao_24bit」や「武将一覧.xls」の番号とは１つずれる(これらは１つ大きい番号)なので注意。</para></summary>
	byte 状態:4;	/// <summary>「状態::大名～状態::死亡」に対応する。 <para>状態の値を単純に変更すると、バグになるので注意。</para><para>Set_武将状態《***》を通して、武将の状態は変更可能である。</para></summary>
	byte 身分:4;	/// <summary>「身分::隠居～身分::足軽頭」に対応する。<para>身分の値を単純に変更すると、バグになるので注意。</para><para>元の身分が「身分::足軽頭～身分::宿老」であれば、その範囲で変更するのは大丈夫である。</para></summary>

	byte 性別:1;	//「性別::男～性別::女」に対応する。
	byte 退却:1;	//1:戦場で退却した。0:通常通り
	byte 戦死:1;	//1:戦場で戦死した。0:通常通り
	byte _undef:5;
};



// --------------これらは、「状態名型＆ カスタム::On_状態名表示直前(...)」のメソッドのためにある。
using 状態名型＆ = char*;
using _状態名型 = char[7]; // 全角３文字
/// <summary>
/// 「状態名型＆ カスタム::On_状態名表示直前(int 武将番号, int 状態) 」メソッドの返り値の型
/// </summary>
#define 状態名型   static _状態名型

// --------------これらは、「身分名型＆ カスタム::On_身分名表示直前(...)」のメソッドのためにある。
using 身分名型＆ = char*;
using _身分名型 = char[7]; // 全角３文字
/// <summary>
/// 「身分名型＆ カスタム::On_身分名表示直前(int 武将番号, int 身分) 」メソッドの返り値の型
/// </summary>
#define 身分名型   static _身分名型



/// <summary>
/// 「戦国武将列伝型＆ カスタム::On_戦国武将列伝要求時(int 武将番号, int 顔番号) 」メソッドの返り値の型
/// </summary>
struct 戦国武将列伝型 {

public:
	string _ラベル;
	string _詳細;

public:
	/// <summary>
	/// 戦国武将列伝を設定する。
	/// </summary>
	/// <param name="ラベル">戦国武将列伝時に表示される、名前と生年。36バイトまで。全角だと18文字。</param>
	/// <param name="詳細">戦国武将列伝時に表示される、詳細な武将列伝。全角だと18文字×４行。</param>
	inline 戦国武将列伝型(string ラベル, string 詳細) {
		_ラベル = ラベル;
		_詳細 = 詳細;
	};

	// NULLリターンに対応するため。
	inline 戦国武将列伝型(int iDefault) {}
};
#define 戦国武将列伝型＆	戦国武将列伝型


namespace 関数 {

	/// <summary>
	/// 対象の武将の武将の名字を取得する。
	/// <para>返り値：対象の武将の名字の文字列。最大で全角３文字。(6バイト)</para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <returns>対象の武将の名字の文字列。最大で全角３文字。(6バイト)</returns>
	string Get_名字( int 武将番号【配列用】);


	/// <summary>
	/// 対象の武将の武将の名字を設定する。
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <param name="名字">設定する名字の文字列。</param>
	void Set_名字(int 武将番号【配列用】, string 名字);


	/// <summary>
	/// 対象の武将の武将の名前を取得する。
	/// <para>返り値：対象の武将の名前の文字列。最大で全角３文字。(6バイト)</para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <returns>対象の武将の名前の文字列。最大で全角３文字。(6バイト)</returns>
	string Get_名前(int 武将番号【配列用】);


	/// <summary>
	/// 対象の武将の武将の名前を設定する。
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <param name="名前">設定する名前の文字列。</param>
	void Set_名前(int 武将番号【配列用】, string 名前);
}



namespace 関数 {

	/// <summary>
	/// 戦国時代に居そうな名字を適当にランダムで得る。
	/// <para>返り値：名字の文字列。最大で全角３文字。(6バイト)</para>
	/// </summary>
	string Get_ランダム名字();


	/// <summary>
	/// 戦国時代に居そうな名前を適当にランダムで得る。
	/// <para>返り値：名前の文字列。最大で全角３文字。(6バイト)</para>
	/// </summary>
	string Get_ランダム名前();


	/// <summary>
	/// 天翔記で元々用意されてる100種類の仮想の姫の名前からランダムで１つを得る。
	/// <para>返り値：名前の文字列。最大で全角３文字。(6バイト)</para>
	/// </summary>
	string Get_ランダム姫名前();
}


namespace 関数 {

	/// <summary>
	/// 「状態::現役」の武将を「状態::浪人」にする。
	/// <para>大名や軍団長以外の一般の武将を、浪人とする。</para>
	/// <para>返り値：成功したらtrue、失敗したらfalse</para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	bool Set_武将状態《現役→浪人》(int 武将番号【配列用】);


	/// <summary>
	/// 「状態::浪人」の武将を→「状態::現役」にする。
	/// <para>浪人が居る城の位置のまま、そこを支配している大名(軍団長)の配下となる。</para>
	/// <para>空白城にいる浪人は、その城の位置では現役になれない。</para>
	/// <para>どの大名の麾下に属するべきか不明であるためである。</para>
	/// <para>返り値：現役化に失敗した場合はfalseが返り、成功したらtrue。</para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	bool Set_武将状態《浪人→現役》( int 武将番号【配列用】);


	/// <summary>
	/// 武将の死亡処理を行う。
	/// <para>一連のＵＩを伴った関連処理が行われるため、使用可能なタイミングが限られる関数である。注意を要する</para>
	/// <para>犯人武将が居ないならば、犯人武将を指定しない。(自分で死んだという形となる)</para>
	/// <para>返り値：指定武将が不正であればfalse、それ以外はtrueが返る。</para>
	/// </summary>
	/// <param name="死亡武将番号【配列用】">死亡対象となる武将の「配列用」の番号</param>
	/// <param name="犯人武将番号【配列用】">犯人対象となる武将の「配列用」の番号。省略可能。</param>
	bool Set_武将状態《→死亡》(int 死亡武将番号【配列用】, int 犯人武将番号【配列用】 = -1);


	/// <summary>
	/// 特定の「現役」の武将を、その城の城主にする。
	/// <para>城主だったものはただの現役となる。</para>
	/// <para>返り値：成功すればtrue、失敗すればfalse</para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <returns>成功すればtrue、失敗すればfalse</returns>
	bool Set_城主(int 武将番号【配列用】);


	/// <summary>
	/// 浪人を誕生させる。
	/// <para>各種能力・職業・年齢等が一定の割合に基づいて自動計算される。</para>
	/// <para>顔は「能力・職業・年齢」などの基づいて、「汎用顔の中からふさわしいものが選択」される。</para>
	/// <para>返り値：該当の武将が誕生する際に割り当てられた武将の「配列用」の番号
	/// <para>浪人作成に失敗した場合には、-1が返ってくる。</para>
	/// </para>
	/// </summary>
	/// <param name="顔番号">顔番号(=列伝番号)を指定すれば、その顔番号(=列伝)となる。
	/// <para> (列伝番号も兼ねるので、同じ顔＆列伝が複数人生存したりしないように要注意)</para>
	/// <para>顔番号指定を省略した場合、「能力・職業・年齢」などの基づいて、「汎用顔の中からふさわしいものが選択」される。</para>
	/// </param>
	/// <returns>該当の武将が誕生する際に割り当てられた武将の「配列用」の番号
	/// <para>浪人作成に失敗した場合には、-1が返ってくる。</para>
	/// </returns>
	int Set_武将誕生(int 顔番号 = -1);


	/// <summary>
	/// 「浪人と現役の武将」を別の場所に転移させることが出来る。
	/// <para>勢力を超えてどこに移動してもよい。</para>
	/// <para>但し、未支配城(いずれの勢力下にも属さない城)に転移すると、浪人化した状態で転移することとなる。</para>
	/// <para>返り値：成功すればtrue、失敗すればfalse</para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <param name="転居先城番号【配列用】">転居先となる城の「配列用」の番号</param>
	/// <returns>成功すればtrue、失敗すればfalse</returns>
	bool Set_武将転居(int 武将番号【配列用】, int 転居先城番号【配列用】);
}


namespace 関数 {

	/// <summary>
	/// 指定武将の「伴侶の武将番号【配列用】」得る。
	/// <para>返り値：伴侶となる武将や妻の「配列用」の番号</para>
	/// <para>夫武将を指定すれば、妻武将の武将番号【配列用】が返ってくる。</para>
	/// <para>妻武将を指定すれば、夫武将の武将番号【配列用】が返ってくる。</para>
	/// <para> 伴侶が居ない場合には、0xFFFFが返ってくる。</para>
	/// </summary>
	/// <param name="武将番号【配列用】">対象となる武将の「配列用」の番号</param>
	/// <returns>伴侶となる武将や妻の「配列用」の番号
	/// <para>夫武将を指定すれば、妻武将の武将番号【配列用】が返ってくる。</para>
	/// <para>妻武将を指定すれば、夫武将の武将番号【配列用】が返ってくる。</para>
	/// <para> 伴侶が居ない場合には、0xFFFFが返ってくる。</para>
	/// </returns>
	int Get_伴侶武将番号【配列用】(int 武将番号【配列用】);


	/// <summary>
	/// 姫(他の武将の妻含む)を、指定の武将と結婚させる、同盟関係等は一切操作されない。
	/// <para>返り値：成功すればtrue、失敗すればfalse</para>
	/// </summary>
	/// <param name="姫武将番号【配列用】">結婚させる姫側の武将の武将番号「配列用」</param>
	/// <param name="夫武将番号【配列用】">結婚させる夫側の武将の武将番号「配列用」</param>
	/// <param name="天蓋孤独死亡処理">
	/// <para>夫側に妻がいた場合、この結婚により元妻とは離婚することになる。</para>
	/// <para>天蓋孤独死亡処理とは、この離婚によって、姫が天蓋孤独になってしまった(親兄弟等や、血縁の大名等が無い)場合、</para>
	/// <para>誰からも参照出来ない人物となり、ゲーム内で姫としての役割が不可能であるため、死亡処理を入れるというもの。</para>
	/// </param>
	/// <returns>成功すればtrue、失敗すればfalse</returns>
	bool Set_姫結婚( int 姫武将番号【配列用】, int 夫武将番号【配列用】, BOOL 天蓋孤独死亡処理=TRUE );


	/// <summary>
	///指定の姫を離婚させる。無事離婚して、親元や兄弟元に移動する。
	/// <para>返り値：成功すればtrue、失敗すればfalse</para>
	/// </summary>
	/// <param name="姫武将番号【配列用】">結婚させる姫側の武将の武将番号「配列用」</param>
	/// <param name="天蓋孤独死亡処理">
	/// <para>天蓋孤独死亡処理とは、この離婚によって、姫が天蓋孤独になってしまった(親兄弟等や、血縁の大名等が無い)場合、</para>
	/// <para>誰からも参照出来ない人物となり、ゲーム内で姫としての役割が不可能であるため、死亡処理を入れるというもの。</para>
	/// </param>
	/// <returns>成功すればtrue、失敗すればfalse</returns>
	bool Set_姫離婚( int 姫武将番号【配列用】, BOOL 天蓋孤独死亡処理=TRUE );
}

namespace 関数 {
	// 以下は「Ａ武将」と「Ｂ武将」との「特別な人間関係の真偽を簡単に判定」するための関数となる。

	/// <summary>
	/// 自分は相手の娘かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_自分は相手の娘( int 自分武将番号【配列用】, int 相手武将番号【配列用】 );

	/// <summary>
	/// 自分は相手の息子かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_自分は相手の息子(int 自分武将番号【配列用】, int 相手武将番号【配列用】);

	/// <summary>
	/// 自分は相手の子かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_自分は相手の子(int 自分武将番号【配列用】, int 相手武将番号【配列用】);

	/// <summary>
	/// 自分は相手の親かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_自分は相手の親(int 自分武将番号【配列用】, int 相手武将番号【配列用】);

	/// <summary>
	/// 自分は相手の父かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_自分は相手の父(int 自分武将番号【配列用】, int 相手武将番号【配列用】);

	/// <summary>
	/// 相手は自分の父かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_相手は自分の父(int 自分武将番号【配列用】, int 相手武将番号【配列用】);

	/// <summary>
	/// 自分は相手の母かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_自分は相手の母(int 自分武将番号【配列用】, int 相手武将番号【配列用】);

	/// <summary>
	/// 相手は自分の母かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_相手は自分の母(int 自分武将番号【配列用】, int 相手武将番号【配列用】);

	/// <summary>
	/// 自分は相手の弟かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_自分は相手の弟(int 自分武将番号【配列用】, int 相手武将番号【配列用】);

	/// <summary>
	/// 相手は自分の弟かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_相手は自分の弟(int 自分武将番号【配列用】, int 相手武将番号【配列用】);

	/// <summary>
	/// 自分は相手の妹かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_自分は相手の妹(int 自分武将番号【配列用】, int 相手武将番号【配列用】);

	/// <summary>
	/// 相手は自分の妹かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_相手は自分の妹(int 自分武将番号【配列用】, int 相手武将番号【配列用】);

	/// <summary>
	/// 自分は相手の兄かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_自分は相手の兄(int 自分武将番号【配列用】, int 相手武将番号【配列用】);

	/// <summary>
	/// 相手は自分の兄かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_相手は自分の兄(int 自分武将番号【配列用】, int 相手武将番号【配列用】);

	/// <summary>
	/// 自分は相手の姉かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_自分は相手の姉(int 自分武将番号【配列用】, int 相手武将番号【配列用】);

	/// <summary>
	/// 相手は自分の姉かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_相手は自分の姉(int 自分武将番号【配列用】, int 相手武将番号【配列用】);

	/// <summary>
	/// 自分と相手は兄弟かどうかの判定。
	/// <para>自分=兄、相手=弟、の順で引数として渡す</para>
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_自分と相手は兄弟( int 自分武将番号【配列用】, int 相手武将番号【配列用】 );

	/// <summary>
	/// 自分と相手は姉妹かどうかの判定。
	/// <para>自分=姉、相手=妹、の順で引数として渡す</para>
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_自分と相手は姉妹( int 自分武将番号【配列用】, int 相手武将番号【配列用】 );

	/// <summary>
	/// 自分と相手は姉弟かどうかの判定。
	/// <para>自分=姉、相手=弟、の順で引数として渡す</para>
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_自分と相手は姉弟( int 自分武将番号【配列用】, int 相手武将番号【配列用】 );

	/// <summary>
	/// 自分と相手は兄妹かどうかの判定。
	/// <para>自分=兄、相手=妹、の順で引数として渡す</para>
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_自分と相手は兄妹( int 自分武将番号【配列用】, int 相手武将番号【配列用】 );

	/// <summary>
	/// 自分は相手の夫かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_自分は相手の夫(int 自分武将番号【配列用】, int 相手武将番号【配列用】);

	/// <summary>
	/// 自分は相手の妻かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_自分は相手の妻(int 自分武将番号【配列用】, int 相手武将番号【配列用】);

	/// <summary>
	/// 自分は相手の血縁かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_自分は相手の血縁(int 自分武将番号【配列用】, int 相手武将番号【配列用】);

	/// <summary>
	/// 自分が大名で、相手はその家臣という関係かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_相手は自分の家臣( int 自分武将番号【配列用】, int 相手武将番号【配列用】 );

	/// <summary>
	/// 自分が家臣で、相手はその大名という関係かどうかの判定。
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_相手は自分の大名(int 自分武将番号【配列用】, int 相手武将番号【配列用】);

	/// <summary>
	/// 自分と相手は同じ大名家かどうかの判定。
	/// <para>家臣はもちろん、大名本人も自分の「大名家に所属している」とみなされる。</para>
	/// <para>返り値：trueかfalse</para>
	/// </summary>
	/// <param name="自分武将番号【配列用】">１人目の武将番号「配列用」</param>
	/// <param name="相手武将番号【配列用】">２人目の武将番号「配列用」</param>
	/// <returns>trueかfalse</returns>
	bool Is_自分と相手は同じ大名家所属( int 自分武将番号【配列用】, int 相手武将番号【配列用】 );

}

