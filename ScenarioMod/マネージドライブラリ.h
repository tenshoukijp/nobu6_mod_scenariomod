#pragma once

#include <string>

namespace �֐� {

	/// <summary>
	///�uSystem::String^�v�ˁustd::string�v�ցB
	/// <para>.NET��String�^������������ɂ��AC++��string�^�������Ԃ��B</para>
	/// <para>�Ԃ�l�Fstd::string�^�̕�����</para>
	/// </summary>
	/// <param name="������">.NET��System::String^�^</param>
	/// <returns>std::string�^�̕�����</returns>
	inline std::string string��String(System::String^ ������);


	/// <summary>
	///�ustd::string�v�ˁuSystem::String�v�ցB
	/// <para>C++��string�^������������ɂ��A.NET��String�^�������Ԃ��B</para>
	/// <para>�Ԃ�l�FSystem::String^�^</para>
	/// </summary>
	/// <param name="������">C++��string������</param>
	/// <returns>System::String^�^</returns>
	inline System::String^ String��string(std::string ������);
}