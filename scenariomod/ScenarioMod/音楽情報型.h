/*
 * ���y���A������a�f�l�֘A
 */
#pragma once
#pragma pack(1)

#include <windows.h>



// �w��̉��y(�a�f�l)���Đ�����(���̉��y�ԍ��́A�_�p�b�`�Ŏw�肷��ԍ��ƍ��v���Ă�ƍl���ėǂ�)
namespace �֐� {

	/// <summary>
	/// �Đ�����BGM�̔ԍ��𓾂�B
	/// <para>�g���b�N�ԍ��Ɠ����ł���A�_�p�b�`��TSMod.ini�ɋL�ڂ���Ă���ԍ��Ɠ����ł���B</para>
	/// <para>�Ԃ�l�F1�ȏ�̒l���Ԃ��Ă���B0xFFFF���Ɖ����Đ����Ă��Ȃ��B</para>
	/// <para>���ݒ�̢���y��̍��ڂ��n�e�e�̎����A0xFFFF���Ԃ��Ă��邱�ƂƂȂ�B</para>
	/// </summary>
	/// <returns>1�ȏ�̒l���Ԃ��Ă���B0xFFFF���Ɖ����Đ����Ă��Ȃ��B���ݒ�̢���y��̍��ڂ��n�e�e�̎����A0xFFFF���Ԃ��Ă��邱�ƂƂȂ�B</returns>
	int Get_�Đ����y�ԍ�();


	/// <summary>
	///  _INMM�𗘗p���čĐ����Ă��邩�ǂ����𔻒肷��B
	/// <para>�Ԃ�l�F_INMM�𗘗p���Ă�����^�A���p���Ă��Ȃ��Ȃ�U</para>
	/// </summary>
	bool Is_INMM���[�h();


	/// <summary>
	/// �w��̔ԍ���BGM���Đ�����B
	/// </summary>
	/// <param name="���y�ԍ�">�Đ����������y�ԍ�
	/// <para>�g���b�N�ԍ��Ɠ����ł���A�_�p�b�`��TSMod.ini�ɋL�ڂ���Ă���ԍ��Ɠ����ł���B</para>
	/// </param>
	void ���y�Đ�(int ���y�ԍ�);


	/// <summary>
	/// �Đ�����BGM���~����B
	/// </summary>
	void ���y��~();
}

