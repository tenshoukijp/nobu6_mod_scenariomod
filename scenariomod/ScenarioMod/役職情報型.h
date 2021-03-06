/*
 * 武将情報型 及び、 武将戸籍情報型
 */
#pragma once
#pragma pack(1)

#include <windows.h>

#include "役職情報列挙.h"



namespace 関数 {


	/// <summary>
	/// 対象の大名勢力(の大名)が所持する役職のIDを得る。
	/// <para>返り値：<see cref="役職::無し"/>〜<see cref="役職::羽州探題"/></para>
	/// </summary>
	/// <param name="大名番号【配列用】">対象となる大名勢力の「配列用」の番号</param>
	/// <returns>役職::無し〜役職::羽州探題</returns>
	int Get_大名役職(int 大名番号【配列用】);

	/// <summary>
	/// 対象の大名勢力(の大名)の役職を設定する。
	/// <para>成功なら真、失敗なら偽</para>
	/// </summary>
	/// <param name="大名番号【配列用】">対象となる大名勢力の「配列用」の番号</param>
	/// <param name="役職値">役職::無し〜役職::羽州探題</param>
	/// <returns>成功したなら真、失敗したなら偽</returns>
	bool Set_大名役職(int 大名番号【配列用】, int 役職値);


	/// <summary>
	/// 対象の軍団勢力(の軍団長)が所持する役職のIDを得る。
	/// <para>返り値：<see cref="役職::無し"/>〜<see cref="役職::羽州探題"/></para>
	/// </summary>
	/// <param name="軍団番号【配列用】">対象となる軍団勢力の「配列用」の番号</param>
	/// <returns>役職::無し〜役職::羽州探題</returns>
	int Get_軍団役職(int 軍団番号【配列用】);

	/// <summary>
	/// 対象の軍団勢力(の軍団長)の役職を設定する。
	/// <para>成功なら真、失敗なら偽</para>
	/// </summary>
	/// <param name="軍団番号【配列用】">対象となる軍団勢力の「配列用」の番号</param>
	/// <param name="役職値">役職::無し〜役職::羽州探題</param>
	/// <returns>成功したなら真、失敗したなら偽</returns>
	bool Set_軍団役職(int 軍団番号【配列用】, int 役職値);

}

