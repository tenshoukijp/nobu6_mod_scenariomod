/*
 * ���������^
 */
#pragma once
#pragma pack(1)

#include <windows.h>

using ���������X�g�^�� = char**;
using _���������X�g�^  = char *[4];

/// <summary>
/// �u���������X�g�^���J�X�^��::On_�������\�����O(int �����ԍ�) �v���\�b�h�̕Ԃ�l�̌^
/// </summary>
#define ���������X�g�^   static _���������X�g�^



namespace �֐� {
	/// <summary>
	/// <para>�u���������X�g�^���J�X�^��::On_�������\�����O(int �����ԍ�) �v���\�b�h�ŁA</para>
	/// <para>������ʂŏo��u���v�̎���ύX�������ꍇ�ɗ��p����</para>
	/// <examples>
	/// <para>��:
	/// <code>
	///      Set_�������������( nb, "%s�c");
	/// </code>
	/// </para>
	/// </examples>
	/// <param name="���������X�g�ϐ�">�����ɂ���ďC������ΏۂƂȂ�u���������X�g�^�v�̕ϐ��B</param>
	/// <param name="Printf������">�C������Printf�������B�u%s���v��u%s�v��u%s�c�v��u%s�R�v</param>
	/// </summary>
	void Set_����������(���������X�g�^�� ���������X�g�ϐ�, char *Printf������);
}