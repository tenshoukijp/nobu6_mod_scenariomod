/*
 * コマンド名情報
 */
#pragma once
#pragma pack(1)

#include <windows.h>
#include <string>

using namespace std;


namespace 関数 {

	namespace アプリケーション {

		/// <summary>
		/// 天翔記のフォームの「改造」メニューに、独自の メニューアイテムを追加する。
		/// <para>返り値：追加した メニューアイテムに割り当てられた「メニュー番号」</para>
		/// <para>この「メニュー番号」をどこかに自分で保存しておき、「On_アプリケーションメニュー選択時」で選択メニューの判定に利用する。</para>
		/// </summary>
		/// <param name="メニュー文字列">追加したいメニューアイテムの文字列
		/// <para>"---"を指定すると、セパレータ（横線）を追加することが出来る。</para>
		/// </param>
		/// <returns>追加した メニューアイテムに割り当てられた「メニュー番号」<para>この「メニュー番号」をどこかに自分で保存しておき、「On_アプリケーションメニュー選択時」で選択メニューの判定に利用する。</para></returns>
		int メニューアイテム追加( string メニュー文字列 );
	}
}

