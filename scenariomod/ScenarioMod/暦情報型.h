/*
 * 年情報型
 */
#pragma once
#pragma pack(1)

#include <windows.h>

#include "暦情報列挙.h"


////////////////////////////////////////////////////////////////////////////
// NB6 天翔記
/*
	[年号情報(3*1)]

	0-1		年数(1454(天翔記基準年)からの経過数)
	2		季節(0=春,1=夏,2=秋,3=冬)
*/
struct 年情報型
{
	WORD 年;				// 年数(1454(天翔記基準年)からの経過数)	 ⇒ ちゃんとした年は、Get_西暦()で得ること
	char 季節;				// 季節(0=春,1=夏,2=秋,3=冬) ⇒ 「季節::春 〜 季節::冬」と比較すると良い
};



namespace 関数 {

	/// <summary>
	/// ゲーム内での現在の西暦を数値で得る。
	/// </summary>
	/// <returns>ゲーム内での現在の西暦の数値</returns>
	int Get_西暦();


	/// <summary>
	/// <para>天翔記ゲームにおいての｢元年｣相当を西暦を数値で得る。通常デフォルトでは、西暦1454年が天翔記基準年。</para>
	/// <para>例えば、天翔記において、｢46年｣とは、｢基準年+46年｣=｢1454年+46年｣=｢西暦1500年｣のこと。</para>
	/// <para>これは武将の｢生年｣などの考え方の元となる。</para>
	/// </summary>
	/// <returns>ゲーム内での基準年の西暦の数値</returns>
	int Get_天翔記基準年();
}


struct 和暦型 {
	string 元号;			// 「天文」や「弘治」といった元号の文字列
	string 年漢字;			//  一五〇六 といった西暦を漢字にしたもの。
	int 年;					//  西暦の数値
};

namespace 関数 {

	/// <summary>
	/// 年・月・日より元号文字列を得る。
	/// <para>年月日を何も指定しなかった場合、ゲーム中の現在の西暦年の年末を指定したものとみなす。</para>
	/// <para>(天翔記では、「年の途中で元号が変わっている」場合、旧年号ではなく、新元号の方を常に採用するため、100％新年号が返る年末ベースとなっている。)</para>
	/// </summary>
	/// <param name="年">対象の年。年だけを引数として渡した場合、指定年の年末を指定したものとみなす。</param>
	/// <param name="月">対象の月。年・月だけを引数として指定した場合、該当月の31日を指定したものとみなす。(そのような日付が存在しなくとも不都合はない)</param>
	/// <param name="日">対象の日。</param>
	/// <returns><see cref="和暦型"/>の値。和暦型を参照のこと。</returns>
	和暦型 Get_和暦(int 年=-1, int 月=-1, int 日=-1);
}

