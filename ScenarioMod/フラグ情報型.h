/*
 * ���������^
 */
#pragma once
#pragma pack(1)

#include <windows.h>

namespace �t���O�g {
	enum { ���C��=0, �`=1, �a=2, �b=3, �c=4, �d=5, �e=6, �f=7, �g=8 };
}

namespace �֐� {

	/// <summary>
	/// �t���O�l��ݒ肷��B
	/// <para>�e�t���O�̓��x����t���ĊǗ�����B</para>
	/// <para>�t���O���̓Z�[�u�f�[�^�ɕۑ������B</para>
	/// <para>�t���O�͍ő�Łu3000�v���p���邱�Ƃ��\�ł���B</para>
	/// <para>�Ԃ�l�F�t���O��ݒ�ł����ꍇ�^�B</para>
	/// <para>���̂悤�Ȗ��O�̃t���O�����݂��Ȃ������ꍇ�͋U</para>
	/// <para>���ł�3000�̃t���O�𗘗p���Ă���A�V�����t���O��p�ӏo���Ȃ������ꍇ�͋U</para>
	/// <para>�Q�x�Ǝg��Ȃ��Ȃ����t���O�́ADelete_�t���O���邱�Ɛ����B(�ʂ̃t���O�����̏ꏊ���g����悤�ɂȂ�)</para>
	/// </summary>
	/// <param name="�t���O��">�t���O�ɕt���郉�x�����݂����Ȃ��́B�u�ő唼�p8�����v�܂ŁB</param>
	/// <param name="�t���O�l">�t���O�ɐݒ肷��l�B
	/// <para>�u�t���O�g::���C��(�f�t�H���g)�v�̏ꍇ��-13���`+13�����x�̒l�����p�\�B</para>
	/// <para>�u�t���O�g::�`�`�t���O�g::�g�v�̏ꍇ�́ATURE(=1)��FALSE(=0) �݂̂����p�\</para>
	/// </param>
	/// <param name="�t���O�g">�g�p����t���O�g��ݒ肷��B
	/// <para>�u�t���O�g::���C���v�u�t���O�g::�`�`�t���O�g::�g�v���g����B</para>
	/// <para>�ȗ������ꍇ�́A�t���O�g::���C�����w�肵�����ƂƂȂ�B</para>
	/// </param>
	/// <returns>�t���O��ݒ�ł����ꍇ�^�B
	/// <para>���̂悤�Ȗ��O�̃t���O�����݂��Ȃ������ꍇ�͋U</para>
	/// <para>���ł�3000�̃t���O�𗘗p���Ă���A�V�����t���O��p�ӏo���Ȃ������ꍇ�͋U</para>
	/// </returns>
	int Set_�t���O( string �t���O��, int �t���O�l, int �t���O�g=�t���O�g::���C�� );


	/// <summary>
	/// �t���O�l���擾����B
	/// <para>�e�t���O�̓��x����t���ĊǗ�����B</para>
	/// <para>�t���O���̓Z�[�u�f�[�^�ɕۑ������B</para>
	/// <para>�Ԃ�l�F�t���O�̒l</para>
	/// <para>���̂悤�Ȗ��O�̃t���O�����݂��Ȃ������ꍇ�͋U</para>
	/// </summary>
	/// <param name="�t���O��">�t���O�ɕt�����Ă��郉�x�����B�u�ő唼�p8�����v�܂ŁB</param>
	/// <param name="�t���O�g">�l�����o���t���O�g���w�肷��B
	/// <para>�u�t���O�g::���C���v�u�t���O�g::�`�`�t���O�g::�g�v���g����B</para>
	/// <para>�ȗ������ꍇ�́A�t���O�g::���C�����w�肵�����ƂƂȂ�B</para>
	/// </param>
	/// <returns>�Ώۂ̃t���O�l
	/// <para>���̂悤�Ȗ��O�̃t���O�����݂��Ȃ������ꍇ�͋U</para>
	/// </returns>
	int Get_�t���O(string �t���O��, int �t���O�g = �t���O�g::���C��);


	/// <summary>
	/// �t���O�̑��݂̏����B
	/// <para>�Z�[�u�f�[�^�ɕۑ�����K�v���Ȃ��Ȃ����t���O�͏������邱�ƁB</para>
	/// </summary>
	/// <param name="�t���O��">�t���O�ɕt�����Ă��郉�x�����B�u�ő唼�p8�����v�܂ŁB</param>
	int Delete_�t���O(string �t���O��);
}

