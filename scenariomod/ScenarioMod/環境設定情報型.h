/*
 * 環境設定情報型　　環境設定拡張情報型
 */
#pragma once
#pragma pack(1)

#include <windows.h>

#include "環境設定情報列挙.h"

/*
	[ 環境設定]

	B 戦争を見る見ない / BGM / SE / ムービー			
		000ebbcd d=SE c=BGM e=ムービー bb =他国の戦争

	B 0?
	B メッセージ速度
	B 難易度
*/
struct 環境設定情報型
{
	byte 効果音:1;		/// <summary><para>ＳＥの有無。</para><para>「効果音::ＯＮ」と「効果音::ＯＦＦ」に対応する。</para></summary>
	byte 音楽:1;		/// <summary><para>ＢＧＭの有無。</para><para>「音楽::ＯＮ」と「音楽::ＯＦＦ」に対応する。</para></summary>
	byte 他国の戦争:2;	/// <summary><para>他国の戦争のオプション。</para><para>「他国の戦争::見る」と「他国の戦争::任意」と「他国の戦争::見ない」に対応する。</para></summary>
	byte ムービー:1;	/// <summary><para>ムービーの有無。</para><para>「ムービー::ＯＮ」と「ムービー::ＯＦＦ」に対応する。</para><para>(※enumの値を見ればわかるが、「ムービー::ＯＮ==0」「ムービー::ＯＦＦ==1」というようにイメージする値とは逆なので注意!!)</para></summary>
	byte _未定義1:3;
	byte _未定義2;
	byte 表示速度;	    /// <summary><para>表示速度のオプション。</para><para>「表示速度::０」～「表示速度::∞」に対応する。</para></summary>
	byte 難易度;		/// <summary><para>難易度のオプション。</para><para>「難易度::楽」～「難易度::難」に対応する。</para></summary>
};




/*
	[ 環境設定拡張情報型 ]

	0-1   W 年号表示( 元号=1 西暦=0 )
	2-3   W 表示位置記憶(マウス=1 記憶=0 )
	4-5   W ?
	6-7   W ?
	8-9   W 表示切替マップ( 連動=1, 非連動=0 )
	10-11 W ?
	12-13 W 戦争頻度(好戦=1, 理知=0)
	14-15 W 計略頻度(多い=1, 少ない=0)
	16-17 W 死亡頻度(多い=1, 少ない=0)
	18-19 W ?
	20-21 W 自国の戦争(任意=2, 従来=1, 見る=0)
	22-23 W 編集機能(有り=1, 無し=0)
	24-25 W 情報表示(最小=2, 少ない=1,普通=0 )
	26-27 W ?
	28-29 W 武将行動志願(有り=1, 無し=0)
	30-31 W 姫武将志願(毎回=2, 従来=1, 無し=0 )
*/

struct 環境設定拡張情報型
{
	WORD 年号表示;		/// <summary><para>年号表示のオプション。</para><para>「年号表示::元号」と「年号表示::西暦」に対応する。</para></summary>
	WORD 表示位置記憶;	/// <summary><para>表示位置記憶のオプション。</para><para>「表示位置記憶::マウス」と「表示位置記憶::記憶」に対応する。</para></summary>
	WORD _未定義1;
	WORD _未定義2;		
	WORD 表示切替マップ;/// <summary><para>表示切替マップのオプション。</para><para>「表示切替マップ::連動」と「表示切替マップ::非連動」に対応する。</para></summary>
	WORD _未定義3;
	WORD 戦争頻度;		/// <summary><para>戦争頻度のオプション。</para><para>「戦争頻度::好戦」と「戦争頻度::理知」に対応する。</para></summary>
	WORD 計略頻度;		/// <summary><para>計略頻度のオプション。</para><para>「計略頻度::多い」と「計略頻度::少ない」に対応する。</para></summary>
	WORD 死亡頻度;		/// <summary><para>死亡頻度のオプション。</para><para>「死亡頻度::多い」と「死亡頻度::少ない」に対応する。</para></summary>
	WORD _未定義4;
	WORD 自国の戦争;	/// <summary><para>自国の戦争のオプション。</para><para>「他国の戦争::任意」と「他国の戦争::従来」と「他国の戦争::見る」に対応する。</para></summary>
	WORD 編集機能;		/// <summary><para>編集機能のオプション。</para><para>「編集機能::有り」と「編集機能::無し」に対応する。</para></summary>
	WORD 情報表示;		/// <summary><para>情報表示のオプション。</para><para>「情報表示::最小」と「情報表示::少ない」と「情報表示::普通」に対応する。</para></summary>
	WORD _未定義5;
	WORD 武将行動志願;	/// <summary><para>武将行動志願のオプション。</para><para>「武将行動志願::有り」と「武将行動志願::無し」に対応する。</para></summary>
	WORD 姫武将志願;	/// <summary><para>姫武将志願のオプション。</para><para>「姫武将志願::毎回」と「姫武将志願::従来」と「姫武将志願::無し」に対応する。</para></summary>
};


namespace 関数 {

	/// <summary>
	/// TSMod.iniで設定されている「cmdタイプ」の設定値を得る。
	/// <para>返り値：対象のcmdの整数値。</para>
	/// <para>コメントアウトしてしまっているものは値を得られず、「-0xFFFF」という特別なマイナス値が返ってくる。</para>
	/// </summary>
	/// <param name="フラグ名">対象となるcmdのフラグ名</param>
	/// <returns>対象のcmdの整数値。
	/// <para>コメントアウトしてしまっているものは値を得られず、「-0xFFFF」という特別なマイナス値が返ってくる。</para>
	/// </returns>
	int Get_ＴＳＭＯＤＩＮＩ設定(string フラグ名);
}

