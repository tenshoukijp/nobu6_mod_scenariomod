#pragma once

#include <string>

namespace 関数 {

	/// <summary>
	///「System::String^」⇒「std::string」へ。
	/// <para>.NETのString型文字列を引数にし、C++のstring型文字列を返す。</para>
	/// <para>返り値：std::string型の文字列</para>
	/// </summary>
	/// <param name="文字列">.NETのSystem::String^型</param>
	/// <returns>std::string型の文字列</returns>
	inline std::string string←String(System::String^ 文字列);


	/// <summary>
	///「std::string」⇒「System::String」へ。
	/// <para>C++のstring型文字列を引数にし、.NETのString型文字列を返す。</para>
	/// <para>返り値：System::String^型</para>
	/// </summary>
	/// <param name="文字列">C++のstring文字列</param>
	/// <returns>System::String^型</returns>
	inline System::String^ String←string(std::string 文字列);
}