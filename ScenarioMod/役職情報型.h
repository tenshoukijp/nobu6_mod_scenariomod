/*
 * �������^ �y�сA �����ːЏ��^
 */
#pragma once
#pragma pack(1)

#include <windows.h>

#include "��E����.h"



namespace �֐� {


	/// <summary>
	/// �Ώۂ̑喼����(�̑喼)�����������E��ID�𓾂�B
	/// <para>�Ԃ�l�F<see cref="��E::����"/>�`<see cref="��E::�H�B�T��"/></para>
	/// </summary>
	/// <param name="�喼�ԍ��y�z��p�z">�ΏۂƂȂ�喼���͂́u�z��p�v�̔ԍ�</param>
	/// <returns>��E::�����`��E::�H�B�T��</returns>
	int Get_�喼��E(int �喼�ԍ��y�z��p�z);

	/// <summary>
	/// �Ώۂ̑喼����(�̑喼)�̖�E��ݒ肷��B
	/// <para>�����Ȃ�^�A���s�Ȃ�U</para>
	/// </summary>
	/// <param name="�喼�ԍ��y�z��p�z">�ΏۂƂȂ�喼���͂́u�z��p�v�̔ԍ�</param>
	/// <param name="��E�l">��E::�����`��E::�H�B�T��</param>
	/// <returns>���������Ȃ�^�A���s�����Ȃ�U</returns>
	bool Set_�喼��E(int �喼�ԍ��y�z��p�z, int ��E�l);


	/// <summary>
	/// �Ώۂ̌R�c����(�̌R�c��)�����������E��ID�𓾂�B
	/// <para>�Ԃ�l�F<see cref="��E::����"/>�`<see cref="��E::�H�B�T��"/></para>
	/// </summary>
	/// <param name="�R�c�ԍ��y�z��p�z">�ΏۂƂȂ�R�c���͂́u�z��p�v�̔ԍ�</param>
	/// <returns>��E::�����`��E::�H�B�T��</returns>
	int Get_�R�c��E(int �R�c�ԍ��y�z��p�z);

	/// <summary>
	/// �Ώۂ̌R�c����(�̌R�c��)�̖�E��ݒ肷��B
	/// <para>�����Ȃ�^�A���s�Ȃ�U</para>
	/// </summary>
	/// <param name="�R�c�ԍ��y�z��p�z">�ΏۂƂȂ�R�c���͂́u�z��p�v�̔ԍ�</param>
	/// <param name="��E�l">��E::�����`��E::�H�B�T��</param>
	/// <returns>���������Ȃ�^�A���s�����Ȃ�U</returns>
	bool Set_�R�c��E(int �R�c�ԍ��y�z��p�z, int ��E�l);

}

