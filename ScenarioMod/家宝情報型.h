/*
 * �ƕ���^
 */
#pragma once
#pragma pack(1)

#include <windows.h>

#include "�ƕ����.h"

/*
	[�ƕ�(19*120)]

	0-12	���O
	13	����
			0 ���q     1 ����     2 ����    3 ����        4 �ԓ�    5 ����      6 ��        7 �   8 �n 
			9 ��       A �w�H�D   B ���q�{  C �����Ԗ{    D ����    E �n���V    F ��؎��v 10 ���n��
			11 �\����  12 ����    13 �ʎ蔠 14 �r�[�h���t 15 ���ዾ 16 ���\���� 17 ����
	14	�摜
	15-16	��������
	17	0000AAAA A = �㏸�l
	18	AB000000 A = ����  B = ���o��
*/
struct �ƕ���^
{
	char _�ƕ�[13];			// ���O
	byte �ƕ󕪗�;				/// <summary> <para>���ޔԍ��B�u�ƕ󕪗�::���q�`�ƕ󕪗�::�����v�ɑΉ�����B</para><para>�l���Z�b�g���鎞�́A�uSet_�ƕ󕪗ށv�̊֐��𗘗p����ƁA�ƕ�㏸�l�ύX�ɔ����āA�����̍ő�\�͂̕ω��������Ōv�Z�����B</para></summary>
	byte �ƕ�摜;				// �摜�ԍ��B�u�ƕ�摜::���q�`�ƕ�摜::���؁v�ɑΉ�����B
	WORD ���L�����y�����ԍ��z;	/// <summary><para>���L�ҁB0xFFFF�Ȃ珤�l�B</para><para>���̒l�𒼐ڏ���������̂ł͂Ȃ��A�uSet_�ƕ󏊗L�ҕύX�v�̊֐��𗘗p����ƁA�ƕ󏊗L�ҕύX�ɔ����āA�����̍ő�\�͂̕ω��������Ōv�Z�����B</para></summary>
	byte �㏸�l:4;				/// <summary><para>�㏸�l (1�`10�Ȃ̂ŋC�����邱��) �B</para><para>�l���Z�b�g���鎞�́A�uSet_�ƕ�㏸�l�v�̊֐��𗘗p����ƁA�ƕ�㏸�l�ύX�ɔ����āA�����̍ő�\�͂̕ω��������Ōv�Z�����B</para></summary>
	byte _����`0:4;			// 0
	byte _����`1:6;			//
	byte ���o��:1;				/// <summary><para>���o��(1=���o�� 0=�o��)</para><para>�l���Z�b�g���鎞�́A��ɉƕ�����l�ɕԂ��Ă���Z�b�g���邱�ƁB</para></summary>
	byte ����:1;				/// <summary><para>����(1=���� 0=����)</para><para>�l���Z�b�g���鎞�́A��ɉƕ�����l�ɕԂ��Ă���Z�b�g���邱�ƁB</para></summary>
};



namespace �֐� {


	/// <summary>
	/// �Ώۂ̉ƕ�̖��O���擾����B
	/// <para>�Ԃ�l�F�Ώۂ̉ƕ�̖��O�̕�����B�ő�őS�p�U�����B(12�o�C�g)</para>
	/// </summary>
	/// <param name="�ƕ�ԍ��y�z��p�z">�ΏۂƂȂ�ƕ�́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ώۂ̉ƕ�̖��O�̕�����B�ő�őS�p�U�����B(12�o�C�g)</returns>
	string Get_�ƕ�( int �ƕ�ԍ��y�z��p�z);


	/// <summary>
	/// �Ώۂ̉ƕ�̖��O��ݒ肷��B
	/// </summary>
	/// <param name="�ƕ�ԍ��y�z��p�z">�ΏۂƂȂ�ƕ�́u�z��p�v�̔ԍ�</param>
	/// <param name="�ƕ�">�ݒ肷��ƕ�̖��O�̕�����B�ő�őS�p�U�����B(12�o�C�g)</param>
	void Set_�ƕ�( int �ƕ�ԍ��y�z��p�z, string �ƕ� );


	/// <summary>
	/// �ƕ�̢���O��ɑΉ�����w�ƕ�́u�z��p�v�̔ԍ��x���擾����B
	/// <para>�Ԃ�l�F�ƕ�́u�z��p�v�̔ԍ�</para>
	/// <para>�Ώۂ̉ƕ󂪁A���̏u�ԓV�ċL�ɓo�ꂵ�Ă��邩�A���Ă��Ȃ����͊֌W�Ȃ��A�Ώۂ̉ƕ󖼂ɑΉ�����ԍ����Ԃ�B</para>
	/// <para>���̂悤�ȉƕ󂪌�����Ȃ������ꍇ��0xFFFF���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�ƕ�">�ΏۂƂȂ�ƕ�̖���</param>
	/// <returns>�Ԃ�l�F�ƕ�́u�z��p�v�̔ԍ�</returns>
	WORD Get_�ƕ�ԍ��y�z��p�z(string �ƕ�);

	/// <summary>
	/// <para>�Ώۂ̉ƕ�̏��L�҂�ύX����B</para><para>���o�������̉ƕ�ɑ΂��āA���̊֐������s����Ɖƕ�͓o�ꂷ��`�ƂȂ�B</para>
	/// <para></para>
	/// </summary>
	/// <param name="�ƕ�ԍ��y�z��p�z">�ΏۂƂȂ�ƕ�́u�z��p�v�̔ԍ�</param>
	/// <param name="���敐���ԍ��y�z��p�z"><para>�Ώۂ̉ƕ�́u�V�������L�ҁv�Ƃ��镐���́u�z��p�v�̔ԍ�</para><para>���l�ɕԋp�������ꍇ�́A0xFFFF���w�肷��B</para></param>
	bool Set_�ƕ󏊗L�ҕύX(int �ƕ�ԍ��y�z��p�z, int ���敐���ԍ��y�z��p�z);


	/// <summary>
	/// <para>�Ώۂ̉ƕ�̏㏸�l��ύX����B</para><para>���������ƕ�ɑ΂��āA���̊֐������s����Ɖƕ�͓o�ꂷ��B</para><para>����A���l�������Ă����ƕ�̏ꍇ�́A�o�������t���O�͈ێ������B</para>
	/// </summary>
	/// <param name="�ƕ�ԍ��y�z��p�z">�ΏۂƂȂ�ƕ�́u�z��p�v�̔ԍ�</param>
	/// <param name="�㏸�l">1-10�܂ł̒l</param>
	/// <returns>����������true�A���s������false;</returns>
	bool Set_�ƕ�㏸�l(int ���ʔԍ��y�z��p�z, int �㏸�l);


	/// <summary>
	/// <para>�Ώۂ̉ƕ�̕��ނ�ύX����B</para><para>���������ƕ�ɑ΂��āA���̊֐������s����Ɖƕ�͓o�ꂷ��B</para><para>����A���l�������Ă����ƕ�̏ꍇ�́A�o�������t���O�͈ێ������B</para>
	/// </summary>
	/// <param name="�ƕ�ԍ��y�z��p�z">�ΏۂƂȂ�ƕ�́u�z��p�v�̔ԍ�</param>
	/// <param name="�ƕ󕪗�">�u�ƕ󕪗�::���q�`�ƕ󕪗�::�����v�̒l</param>
	/// <returns>����������true�A���s������false;</returns>
	bool Set_�ƕ󕪗�(int ���ʔԍ��y�z��p�z, int �ƕ󕪗�);
}



/// <summary>
/// �u�퍑�������T�^�� �J�X�^��::On_�퍑�������T�v����(int �ƕ�ԍ� �v���\�b�h�̕Ԃ�l�̌^
/// </summary>
struct �퍑�������T�^ {

public:
	string _���x��;
	string _�ڍ�;

public:
	/// <summary>
	/// �퍑�������T��ݒ肷��B
	/// </summary>
	/// <param name="���x��">�퍑�������T���ɕ\�������A���O�B36�o�C�g�܂ŁB�S�p����18�����B</param>
	/// <param name="�ڍ�">�퍑�������T���ɕ\�������A�ڍׂȖ������T�B�S�p����18�����~�S�s�B</param>
	inline �퍑�������T�^(string ���x��, string �ڍ�) {
		_���x�� = ���x��;
		_�ڍ� = �ڍ�;
	};

	// NULL���^�[���ɑΉ����邽�߁B
	inline �퍑�������T�^(int iDefault) {}
};
#define �퍑�������T�^��	�퍑�������T�^
