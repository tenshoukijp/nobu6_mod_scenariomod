/*
 * 動画情報、いわゆるムービー関連
 */
#pragma once
#pragma pack(1)

#include <windows.h>

#include "動画情報列挙.h"

namespace 関数 {

	/// <summary>
	/// 指定の動画を再生する。
	/// <examples>
	/// <para>
	/// <code>
	/// 動画再生("KOEILOGO"); // movieフォルダにあるkoeilogo.avi ファイルを普通の動画と同様に再生
	/// </code>
	/// </para>
	/// <para>
	/// <code>
	/// 動画再生("HOGEHOGE", 動画::黒背景ＯＦＦ | 動画::ＢＧＭ継続); // movieフォルダにあるhogehoge.aviファイルを、背景黒にせず、BGMを継続したま再生する。
	/// </code>
	/// </para>
	/// <para>
	/// <code>
	/// 動画再生("SN_MY.+"); // このように正規表現で指定すると、その条件を満たすものをから１つを選択して再生する。 満たすものが１つも無いと、ＣＤ－ＲＯＭの挿入が求められるので注意。
	/// </code>
	/// </para>
	/// </examples>
	/// </summary>
	/// <param name="動画名">対象の動画ファイルの名前。「movie\(動画名).avi」というファイルを探しにいく。</param>
	/// <param name="オプション">「動画::黒背景ＯＮ～動画::ＢＧＭ継続」 を「|」で組み合わせて利用する。
	/// <para>デフォルト値は「オプション= 動画::黒背景ＯＮ|動画::ＢＧＭ停止」</para>
	/// </param>
	void 動画再生(string 動画名, int オプション= 動画::黒背景ＯＮ|動画::ＢＧＭ停止);

}


