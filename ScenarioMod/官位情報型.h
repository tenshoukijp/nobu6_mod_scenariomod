/*
 * 官位情報型
 */
#pragma once
#pragma pack(1)

#include <windows.h>
#include "ゲームデータ構造.h"

#include "官位情報列挙.h"

/*
	[官位(18*250)]

	0-12	名前
	13		位階
	14-15	所有武将番号
	16		上昇値
	17		_undef
*/
struct 官位情報型
{
	char _官位名[13];			/// <summary>官位の名前。「Get_官位名」や「Set_官位名」を使うこと。</summary>
	byte 位階;					/// <summary><para>官位のランク(正一位～従八位上までを数値にしたもの。</para><para>「位階::正一位～位階::正八位上」に対応する。</para></summary>
	WORD 所有武将【武将番号】;	/// <summary>所有者の武将番号<para>能力の変更を伴う所有者の変更を行いたい場合は、「Set_官位所有者変更」を使うのが良い。</para></summary>
	byte 上昇値;				/// <summary>上昇値(魅力の上昇値)。値を設定する場合には、この値を直接書き換えずに「Set_官位上昇値」を使うのが良い。</summary>
	byte _未定義0;				//
};





namespace 関数 {

	/// <summary>
	/// 対象の官位の名前を取得する。
	/// <para>返り値：対象の官位の名前の文字列。最大で全角６文字。(12バイト)</para>
	/// </summary>
	/// <param name="官位番号【配列用】">対象となる官位の「配列用」の番号</param>
	/// <returns>対象の官位の名前の文字列。最大で全角６文字。(12バイト)</returns>
	string Get_官位名(int 官位番号【配列用】);


	/// <summary>
	/// 対象の官位の名前を設定する。
	/// </summary>
	/// <param name="官位番号【配列用】">対象となる官位の「配列用」の番号</param>
	/// <param name="官位名">設定する官位の名前の文字列。最大で全角６文字。(12バイト)</param>
	void Set_官位名(int 官位番号【配列用】, string 官位名);


	/// <summary>
	/// 対象の官位の所有者を変更する。
	/// <para></para>
	/// </summary>
	/// <param name="官位番号【配列用】">対象となる官位の「配列用」の番号</param>
	/// <param name="宛先武将番号【配列用】"><para>対象の官位の「新しい所有者」とする武将の「配列用」の番号</para><para>朝廷に返却したい場合は、0xFFFFを指定する。</para></param>
	/// <returns>成功したらtrue、失敗したらfalse;</returns>
	bool Set_官位所有者変更(int 官位番号【配列用】, int 宛先武将番号【配列用】);


	/// <summary>
	/// 対象の官位の上昇値を変更する。
	/// </summary>
	/// <param name="官位番号【配列用】">対象となる官位の「配列用」の番号</param>
	/// <param name="上昇値">1-24までの値</param>
	/// <returns>成功したらtrue、失敗したらfalse;</returns>
	bool Set_官位上昇値(int 官位番号【配列用】, int 上昇値);

}

