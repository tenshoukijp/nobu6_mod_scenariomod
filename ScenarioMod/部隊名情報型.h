/*
 * 部隊名情報型
 */
#pragma once
#pragma pack(1)

#include <windows.h>

using 部隊名リスト型＆ = char**;
using _部隊名リスト型  = char *[4];

/// <summary>
/// 「部隊名リスト型＆カスタム::On_部隊名表示直前(int 武将番号) 」メソッドの返り値の型
/// </summary>
#define 部隊名リスト型   static _部隊名リスト型



namespace 関数 {
	/// <summary>
	/// <para>「部隊名リスト型＆カスタム::On_部隊名表示直前(int 武将番号) 」メソッドで、</para>
	/// <para>武将画面で出る「隊」の字を変更したい場合に利用する</para>
	/// <examples>
	/// <para>例:
	/// <code>
	///      Set_部隊名語尾書式( nb, "%s団");
	/// </code>
	/// </para>
	/// </examples>
	/// <param name="部隊名リスト変数">書式によって修飾する対象となる「部隊名リスト型」の変数。</param>
	/// <param name="Printf風書式">修飾するPrintf風書式。「%s隊」や「%s」や「%s団」や「%s軍」</param>
	/// </summary>
	void Set_部隊名書式(部隊名リスト型＆ 部隊名リスト変数, char *Printf風書式);
}