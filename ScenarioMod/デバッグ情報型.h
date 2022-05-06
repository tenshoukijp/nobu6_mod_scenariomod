#pragma once
#pragma pack(1)

#include <windows.h>
#include "デバッグクラス.h"

namespace 関数 {

	/// <summary>
	/// デバッグ出力ストリーム。
	/// C言語のprintf関数風、もしくは、C++言語のcout風の記述が可能。
	/// <examples>
	/// <para>① printf(format, ...);  にそっくりな記法</para>
	/// <para>
	/// <code>
	/// デバッグ出力( "%s", 元メッセージ.c_str() );
	/// </code>
	/// </para>
	/// <para>② cout &lt;&lt; ... &lt;&lt; endl;  にそっくりな記法</para>
	/// <para>
	/// <code>
	/// デバッグ出力 &lt;&lt; 武将名 &lt;&lt; ":" &lt;&lt; 元メッセージ &lt;&lt; (int)メッセージ関連情報.第１人称【武将番号】 &lt;&lt; endl;
	/// <para>(endl もしくは、デバッグ出力.flush() した段階で出力される。)</para>
	/// </code>
	/// </para>
	/// </examples>
	/// </summary>
	extern デバッグストリーム型 デバッグ出力;

	/// <summary>
	/// System::String^ 型をデバッグ出力に対応させる。
	/// </summary>
	extern デバッグストリーム型& operator << (デバッグストリーム型& os, System::String^ str);

}

