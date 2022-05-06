/*
 * 部隊名情報型
 */
#pragma once
#pragma pack(1)

#include <windows.h>


using シナリオ説明文型＆	= char**;
using _シナリオ説明文型		= char *[3];
#define シナリオ説明文型	static _シナリオ説明文型

using シナリオメニュー型＆	= char**;
using _シナリオメニュー型	= char *[6];
#define シナリオメニュー型	static _シナリオメニュー型


namespace 関数 {

	/// <summary>
	/// シナリオ番号から、シナリオのタイトル名を取得する。
	/// <para>返り値：シナリオ名の文字列。</para>
	/// <para>不正なシナリオ番号の場合は、空文字""が返る。</para>
	/// </summary>
	/// <param name="シナリオ番号">対象のシナリオ番号</param>
	/// <returns>シナリオ名の文字列<para>不正なシナリオ番号の場合は、空文字""が返る。</para></returns>
	string Get_シナリオ名(int シナリオ番号);


	/// <summary>
	/// 現在選択されている(あるいはプレイ中の)シナリオ番号を得る。
	/// <para>返り値：シナリオ番号</para>
	/// <para>どのシナリオにも属さない場合、-1が返る。</para>
	/// </summary>
	/// <returns>シナリオ番号<para>どのシナリオにも属さない場合、-1が返る。</para></returns>
	int Get_現在のシナリオ番号();
}

