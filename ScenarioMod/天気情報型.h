/*
 * 天気報型
 */
#pragma once
#pragma pack(1)

#include <windows.h>

#include "天気情報列挙.h"


struct 天気情報型 {
	byte _天気;				// Get_天気で得ること
};


namespace 関数 {

	/// <summary>
	/// 天気情報を得る《戦場限定》
	/// <para>返り値：<see cref="天気::晴れ"/>～<see cref="天気::雪"/></para>
	/// </summary>
	/// <returns>天気::晴れ～天気::雪</returns>
	byte Get_天気();


	/// <summary>
	/// 次のターンの天気を予約する。
	/// <para>デフォルトでは２ターン継続する。</para>
	/// <para><see cref="天気::晴れ"/>～<see cref="天気::雪"/>を天気として設定する。</para>
	/// </summary>
	/// <param name="i天気">指定の天気。<see cref="天気::晴れ"/>～<see cref="天気::雪"/>を指定。</param>
	/// <param name="継続ターン">指定の天気を何ターン継続させるか。</param>
	void Set_天気予約(int i天気, int 継続ターン=2);
}