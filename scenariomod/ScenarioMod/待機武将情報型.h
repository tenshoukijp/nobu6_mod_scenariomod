/*
* �ҋ@�������^ �y�сA �ҋ@�����ːЏ��^
*/
#pragma once
#pragma pack(1)

#include <windows.h>


struct �ҋ@������o����^
{
	byte �o��N;				/// <summary>�o��N�B�l�Ƃ��ẮA1454(�V�ċL��N)����̍����̒l�B</summary>
	WORD ��������y��ԍ��z;	/// <summary><para>�����喼���L���ł���A���̏邪�喼�x�z���ł���΁A���̏�ɂĎm������B</para><para>�喼���L���ł���A���̏邪�喼�x�z���ɂ͂Ȃ��ꍇ�A���̏�ԍ��͖��������B</para><para>�o��\��̑喼�Ƃ����łɖŖS���Ă���ꍇ�A���̏�ɂĘQ�l�Ƃ��ēo�ꂵ�A</para><para>���̂܂܂��̏���x�z����喼�Ƃɓo�p����邱�Ƃ�����</para></summary>
	WORD �����喼�y�喼�ԍ��z;	/// <summary>���̑喼���L���ł���΁A�o�ꎞ�Ɏm�����邱�ƂƂȂ�喼</summary>
};


// �������^�Ɠ����t�B�[���h
struct �ҋ@�������^ : �������^
{
};

// �����ːЏ��^�Ǝ����t�B�[���h
struct �ҋ@�����ːЏ��^
{
	char _����[7];	//�����B
	char _���O[7];	//���O�B
	WORD ��ԍ�;	/// <summary>��`�ԍ��ƈ�v�B�����i���o�[(����12bit�͗�`�H)�B<para>�Z�[�u�G�f�B�^��V�i���I�G�f�B�^�̕����̢��ԍ���ƈ�v����B</para><para>�ukao_24bit�v��u�����ꗗ.xls�v�̔ԍ��Ƃ͂P�����(�����͂P�傫���ԍ�)�Ȃ̂Œ��ӁB</para></summary>
	byte ��� : 4;	/// <summary>�S���A�u���::�ҋ@�v</summary>
	byte �g�� : 4;	/// <summary>�S���A�u�g��::���y���v</summary>
	byte ���� : 1;	/// <summary>�u����::�j�`����::���v�ɑΉ�����B</summary>
};

namespace �֐�  {

	/// <summary>
	/// <para>���ݐi�s�`�̃V�i���I�ɂ�����A�u�ҋ@�����́v�u�ҋ@������o����^�v�̏��𓾂�</para>
	/// </summary>
	�ҋ@������o����^* Get_�ҋ@�����o���񃊃X�g();

	/// <summary>
	/// <para>���ݐi�s�`�̃V�i���I�ɂ�����A�u�ҋ@�����́v�u�ҋ@�������^�v�̏��𓾂�</para>
	/// </summary>
	�ҋ@�������^* Get_�ҋ@������񃊃X�g();

	/// <summary>
	/// <para>���ݐi�s�`�̃V�i���I�ɂ�����A�u�ҋ@�����́v�u�ҋ@�����ːЏ��^�v�̏��𓾂�</para>
	/// </summary>
	�ҋ@�����ːЏ��^* Get_�ҋ@�����ːЏ�񃊃X�g();
	
	/// <summary>
	/// <para>���ݐi�s�`�̃V�i���I�ɂ����āA�ҋ@�����f�[�^���̂����A���łɓo�ꂵ�Ă��܂�����</para>
	/// </summary>
	int Get_�ҋ@�����o��ϐl��();

	/// <summary>
	/// <para>���ݐi�s�`�̃V�i���I�ɂ�����A�ҋ@�����f�[�^�������߂�B</para>
	/// </summary>
	int Get_�ҋ@�����f�[�^��();
}