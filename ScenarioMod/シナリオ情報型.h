/*
 * ���������^
 */
#pragma once
#pragma pack(1)

#include <windows.h>


using �V�i���I�������^��	= char**;
using _�V�i���I�������^		= char *[3];
#define �V�i���I�������^	static _�V�i���I�������^

using �V�i���I���j���[�^��	= char**;
using _�V�i���I���j���[�^	= char *[6];
#define �V�i���I���j���[�^	static _�V�i���I���j���[�^


namespace �֐� {

	/// <summary>
	/// �V�i���I�ԍ�����A�V�i���I�̃^�C�g�������擾����B
	/// <para>�Ԃ�l�F�V�i���I���̕�����B</para>
	/// <para>�s���ȃV�i���I�ԍ��̏ꍇ�́A�󕶎�""���Ԃ�B</para>
	/// </summary>
	/// <param name="�V�i���I�ԍ�">�Ώۂ̃V�i���I�ԍ�</param>
	/// <returns>�V�i���I���̕�����<para>�s���ȃV�i���I�ԍ��̏ꍇ�́A�󕶎�""���Ԃ�B</para></returns>
	string Get_�V�i���I��(int �V�i���I�ԍ�);


	/// <summary>
	/// ���ݑI������Ă���(���邢�̓v���C����)�V�i���I�ԍ��𓾂�B
	/// <para>�Ԃ�l�F�V�i���I�ԍ�</para>
	/// <para>�ǂ̃V�i���I�ɂ������Ȃ��ꍇ�A-1���Ԃ�B</para>
	/// </summary>
	/// <returns>�V�i���I�ԍ�<para>�ǂ̃V�i���I�ɂ������Ȃ��ꍇ�A-1���Ԃ�B</para></returns>
	int Get_���݂̃V�i���I�ԍ�();
}

