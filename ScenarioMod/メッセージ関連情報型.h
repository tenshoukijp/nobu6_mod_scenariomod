/*
 * 噴出しなどにおける、｢主体・客体・第３者」のID
 */
#pragma once
#pragma pack(1)

#include <windows.h>
#include <string>
#include <vector>
#include <map>

using namespace std;


using 文字列リスト型 = vector<string>;

// --------------------------------------メッセージ関連情報
struct メッセージ関連情報型 {
	WORD 第１人称【武将番号】;	// 自分のID(通常武将ID)
	WORD 第２人称【武将番号】;	// 相手のID(通常武将ID。イベント顔や商人顔は531,農民顔は532となる)
	WORD 第３人称【武将番号】;	// 第３者のID(通常1stPersonと2ndPersonの会話の中で出てくる人のID);

	// -----------以下予備。将来の拡張に対する互換性確保のため。
	DWORD _undef1;
	DWORD _undef2;
	DWORD _undef3;
	DWORD _undef4;
	DWORD _undef5;
};





// --------------------------------------文字列判定のための正規表現関数

namespace 関数 {

	// 対象文字列に、部分文字列が含まれているかどうかの判定
	BOOL Is_文字列マッチ( string 対象文字列, string 部分文字列);



	/// <summary>
	/// 「Is_正規表現マッチ」の関数で、キャプチャーを受け取るための型。
	/// </summary>
	using 正規表現マッチ結果型 = map<int, string>;

	/// <summary>
	/// 正規表現判定用の関数。
	/// <examples>
	/// <para>-------------------------------------------------
	/// <para>使い方の例①: 簡単な正規表現の例</para>
	/// <code>
	/// <para>　 　</para>
	/// <para>if ( Is_正規表現マッチ(元メッセージ, &quot;米を.+?ほど\x0A売&quot;) ) {</para>
	/// <para>   ....</para>
	/// <para>}</para>
	/// </code>
	/// </para>
	/// <para>-------------------------------------------------
	/// <para>使い方の例②: 詳細結果(キャプチャ結果)を求める場合</para>
	/// <code>
	/// <para>　 　</para>
	/// <para>正規表現マッチ結果型 マッチ結果;</para>
	/// <para>if ( Is_正規表現マッチ(元メッセージ, &quot;米を(.+?)ほど&quot;, &amp;マッチ結果 ) ) {</para>
	/// <para>   ....</para>
	/// <para>}</para>
	///	<para>デバッグ出力 &lt;&lt; マッチ結果[0] &lt;&lt; &quot;:&quot; &lt;&lt; マッチ結果[1] &lt;&lt; endl;</para>
	/// </code>
	/// <para>　 　</para>
	/// <para>マッチ結果[1]のように番号でアクセスする。中身は文字列。</para>
	/// <para>０番目がマッチした部分の文字列全体</para>
    /// <para>１番目以降が（　）でくくった部分にマッチした文字列が順次格納される。</para>
	/// <para>存在しない番号の文字列にアクセスした場合は、空の文字列相当である｢""｣が返ってくる。</para>
	/// </para>
	/// <para>-------------------------------------------------
	/// <para>使い方の例③: メタキャラクターも使用可能</para>
	/// <code>
	/// <para>　 　</para>
	/// <para>if ( Is_正規表現マッチ(元メッセージ, &quot;^他.+[米馬鉄砲]+を[0-9]+ほど\\s売&quot; ) ) { </para>
	/// <para>   ....</para>
	/// <para>}</para>
	/// </code>
	/// <para>　 　</para>
	/// <para>以上のように｢^｣や｢\\d｣、｢\\s｣などが利用可能だ。エスケープに注意する必要がある。</para>
	/// </para>
	/// </examples>
	/// </summary>
	/// <param name="対象文字列">対象の元の文字列</param>
	/// <param name="正規表現文字列">正規表現が入った文字列。</param>
	/// <param name="正規表現マッチ結果">正規表現マッチ結果型の変数のポインタを渡す。(.+?)等によるキャプチャ結果を受け取るためのもの。</param>
	/// <return>正規表現結果が真ならTRUE、偽ならFALSE</return>
	BOOL Is_正規表現マッチ(string 対象文字列, string 正規表現文字列, 正規表現マッチ結果型* 正規表現マッチ結果 = NULL);
}

