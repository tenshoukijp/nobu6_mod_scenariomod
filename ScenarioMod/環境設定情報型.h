/*
 * ���ݒ���^�@�@���ݒ�g�����^
 */
#pragma once
#pragma pack(1)

#include <windows.h>

#include "���ݒ����.h"

/*
	[ ���ݒ�]

	B �푈�����錩�Ȃ� / BGM / SE / ���[�r�[			
		000ebbcd d=SE c=BGM e=���[�r�[ bb =�����̐푈

	B 0?
	B ���b�Z�[�W���x
	B ��Փx
*/
struct ���ݒ���^
{
	byte ���ʉ�:1;		/// <summary><para>�r�d�̗L���B</para><para>�u���ʉ�::�n�m�v�Ɓu���ʉ�::�n�e�e�v�ɑΉ�����B</para></summary>
	byte ���y:1;		/// <summary><para>�a�f�l�̗L���B</para><para>�u���y::�n�m�v�Ɓu���y::�n�e�e�v�ɑΉ�����B</para></summary>
	byte �����̐푈:2;	/// <summary><para>�����̐푈�̃I�v�V�����B</para><para>�u�����̐푈::����v�Ɓu�����̐푈::�C�Ӂv�Ɓu�����̐푈::���Ȃ��v�ɑΉ�����B</para></summary>
	byte ���[�r�[:1;	/// <summary><para>���[�r�[�̗L���B</para><para>�u���[�r�[::�n�m�v�Ɓu���[�r�[::�n�e�e�v�ɑΉ�����B</para><para>(��enum�̒l������΂킩�邪�A�u���[�r�[::�n�m==0�v�u���[�r�[::�n�e�e==1�v�Ƃ����悤�ɃC���[�W����l�Ƃ͋t�Ȃ̂Œ���!!)</para></summary>
	byte _����`1:3;
	byte _����`2;
	byte �\�����x;	    /// <summary><para>�\�����x�̃I�v�V�����B</para><para>�u�\�����x::�O�v�`�u�\�����x::���v�ɑΉ�����B</para></summary>
	byte ��Փx;		/// <summary><para>��Փx�̃I�v�V�����B</para><para>�u��Փx::�y�v�`�u��Փx::��v�ɑΉ�����B</para></summary>
};




/*
	[ ���ݒ�g�����^ ]

	0-1   W �N���\��( ����=1 ����=0 )
	2-3   W �\���ʒu�L��(�}�E�X=1 �L��=0 )
	4-5   W ?
	6-7   W ?
	8-9   W �\���ؑփ}�b�v( �A��=1, ��A��=0 )
	10-11 W ?
	12-13 W �푈�p�x(�D��=1, ���m=0)
	14-15 W �v���p�x(����=1, ���Ȃ�=0)
	16-17 W ���S�p�x(����=1, ���Ȃ�=0)
	18-19 W ?
	20-21 W �����̐푈(�C��=2, �]��=1, ����=0)
	22-23 W �ҏW�@�\(�L��=1, ����=0)
	24-25 W ���\��(�ŏ�=2, ���Ȃ�=1,����=0 )
	26-27 W ?
	28-29 W �����s���u��(�L��=1, ����=0)
	30-31 W �P�����u��(����=2, �]��=1, ����=0 )
*/

struct ���ݒ�g�����^
{
	WORD �N���\��;		/// <summary><para>�N���\���̃I�v�V�����B</para><para>�u�N���\��::�����v�Ɓu�N���\��::����v�ɑΉ�����B</para></summary>
	WORD �\���ʒu�L��;	/// <summary><para>�\���ʒu�L���̃I�v�V�����B</para><para>�u�\���ʒu�L��::�}�E�X�v�Ɓu�\���ʒu�L��::�L���v�ɑΉ�����B</para></summary>
	WORD _����`1;
	WORD _����`2;		
	WORD �\���ؑփ}�b�v;/// <summary><para>�\���ؑփ}�b�v�̃I�v�V�����B</para><para>�u�\���ؑփ}�b�v::�A���v�Ɓu�\���ؑփ}�b�v::��A���v�ɑΉ�����B</para></summary>
	WORD _����`3;
	WORD �푈�p�x;		/// <summary><para>�푈�p�x�̃I�v�V�����B</para><para>�u�푈�p�x::�D��v�Ɓu�푈�p�x::���m�v�ɑΉ�����B</para></summary>
	WORD �v���p�x;		/// <summary><para>�v���p�x�̃I�v�V�����B</para><para>�u�v���p�x::�����v�Ɓu�v���p�x::���Ȃ��v�ɑΉ�����B</para></summary>
	WORD ���S�p�x;		/// <summary><para>���S�p�x�̃I�v�V�����B</para><para>�u���S�p�x::�����v�Ɓu���S�p�x::���Ȃ��v�ɑΉ�����B</para></summary>
	WORD _����`4;
	WORD �����̐푈;	/// <summary><para>�����̐푈�̃I�v�V�����B</para><para>�u�����̐푈::�C�Ӂv�Ɓu�����̐푈::�]���v�Ɓu�����̐푈::����v�ɑΉ�����B</para></summary>
	WORD �ҏW�@�\;		/// <summary><para>�ҏW�@�\�̃I�v�V�����B</para><para>�u�ҏW�@�\::�L��v�Ɓu�ҏW�@�\::�����v�ɑΉ�����B</para></summary>
	WORD ���\��;		/// <summary><para>���\���̃I�v�V�����B</para><para>�u���\��::�ŏ��v�Ɓu���\��::���Ȃ��v�Ɓu���\��::���ʁv�ɑΉ�����B</para></summary>
	WORD _����`5;
	WORD �����s���u��;	/// <summary><para>�����s���u��̃I�v�V�����B</para><para>�u�����s���u��::�L��v�Ɓu�����s���u��::�����v�ɑΉ�����B</para></summary>
	WORD �P�����u��;	/// <summary><para>�P�����u��̃I�v�V�����B</para><para>�u�P�����u��::����v�Ɓu�P�����u��::�]���v�Ɓu�P�����u��::�����v�ɑΉ�����B</para></summary>
};


namespace �֐� {

	/// <summary>
	/// TSMod.ini�Őݒ肳��Ă���ucmd�^�C�v�v�̐ݒ�l�𓾂�B
	/// <para>�Ԃ�l�F�Ώۂ�cmd�̐����l�B</para>
	/// <para>�R�����g�A�E�g���Ă��܂��Ă�����̂͒l�𓾂�ꂸ�A�u-0xFFFF�v�Ƃ������ʂȃ}�C�i�X�l���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�t���O��">�ΏۂƂȂ�cmd�̃t���O��</param>
	/// <returns>�Ώۂ�cmd�̐����l�B
	/// <para>�R�����g�A�E�g���Ă��܂��Ă�����̂͒l�𓾂�ꂸ�A�u-0xFFFF�v�Ƃ������ʂȃ}�C�i�X�l���Ԃ��Ă���B</para>
	/// </returns>
	int Get_�s�r�l�n�c�h�m�h�ݒ�(string �t���O��);
}

