/*
 * �V�C��^
 */
#pragma once
#pragma pack(1)

#include <windows.h>

#include "�V�C����.h"


struct �V�C���^ {
	byte _�V�C;				// Get_�V�C�œ��邱��
};


namespace �֐� {

	/// <summary>
	/// �V�C���𓾂�s������t
	/// <para>�Ԃ�l�F<see cref="�V�C::����"/>�`<see cref="�V�C::��"/></para>
	/// </summary>
	/// <returns>�V�C::����`�V�C::��</returns>
	byte Get_�V�C();


	/// <summary>
	/// ���̃^�[���̓V�C��\�񂷂�B
	/// <para>�f�t�H���g�ł͂Q�^�[���p������B</para>
	/// <para><see cref="�V�C::����"/>�`<see cref="�V�C::��"/>��V�C�Ƃ��Đݒ肷��B</para>
	/// </summary>
	/// <param name="i�V�C">�w��̓V�C�B<see cref="�V�C::����"/>�`<see cref="�V�C::��"/>���w��B</param>
	/// <param name="�p���^�[��">�w��̓V�C�����^�[���p�������邩�B</param>
	void Set_�V�C�\��(int i�V�C, int �p���^�[��=2);
}