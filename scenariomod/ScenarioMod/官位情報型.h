/*
 * ���ʏ��^
 */
#pragma once
#pragma pack(1)

#include <windows.h>
#include "�Q�[���f�[�^�\��.h"

#include "���ʏ���.h"

/*
	[����(18*250)]

	0-12	���O
	13		�ʊK
	14-15	���L�����ԍ�
	16		�㏸�l
	17		_undef
*/
struct ���ʏ��^
{
	char _���ʖ�[13];			/// <summary>���ʂ̖��O�B�uGet_���ʖ��v��uSet_���ʖ��v���g�����ƁB</summary>
	byte �ʊK;					/// <summary><para>���ʂ̃����N(����ʁ`�]���ʏ�܂ł𐔒l�ɂ������́B</para><para>�u�ʊK::����ʁ`�ʊK::�����ʏ�v�ɑΉ�����B</para></summary>
	WORD ���L�����y�����ԍ��z;	/// <summary>���L�҂̕����ԍ�<para>�\�͂̕ύX�𔺂����L�҂̕ύX���s�������ꍇ�́A�uSet_���ʏ��L�ҕύX�v���g���̂��ǂ��B</para></summary>
	byte �㏸�l;				/// <summary>�㏸�l(���͂̏㏸�l)�B�l��ݒ肷��ꍇ�ɂ́A���̒l�𒼐ڏ����������ɁuSet_���ʏ㏸�l�v���g���̂��ǂ��B</summary>
	byte _����`0;				//
};





namespace �֐� {

	/// <summary>
	/// �Ώۂ̊��ʂ̖��O���擾����B
	/// <para>�Ԃ�l�F�Ώۂ̊��ʂ̖��O�̕�����B�ő�őS�p�U�����B(12�o�C�g)</para>
	/// </summary>
	/// <param name="���ʔԍ��y�z��p�z">�ΏۂƂȂ銯�ʂ́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ώۂ̊��ʂ̖��O�̕�����B�ő�őS�p�U�����B(12�o�C�g)</returns>
	string Get_���ʖ�(int ���ʔԍ��y�z��p�z);


	/// <summary>
	/// �Ώۂ̊��ʂ̖��O��ݒ肷��B
	/// </summary>
	/// <param name="���ʔԍ��y�z��p�z">�ΏۂƂȂ銯�ʂ́u�z��p�v�̔ԍ�</param>
	/// <param name="���ʖ�">�ݒ肷�銯�ʂ̖��O�̕�����B�ő�őS�p�U�����B(12�o�C�g)</param>
	void Set_���ʖ�(int ���ʔԍ��y�z��p�z, string ���ʖ�);


	/// <summary>
	/// �Ώۂ̊��ʂ̏��L�҂�ύX����B
	/// <para></para>
	/// </summary>
	/// <param name="���ʔԍ��y�z��p�z">�ΏۂƂȂ銯�ʂ́u�z��p�v�̔ԍ�</param>
	/// <param name="���敐���ԍ��y�z��p�z"><para>�Ώۂ̊��ʂ́u�V�������L�ҁv�Ƃ��镐���́u�z��p�v�̔ԍ�</para><para>����ɕԋp�������ꍇ�́A0xFFFF���w�肷��B</para></param>
	/// <returns>����������true�A���s������false;</returns>
	bool Set_���ʏ��L�ҕύX(int ���ʔԍ��y�z��p�z, int ���敐���ԍ��y�z��p�z);


	/// <summary>
	/// �Ώۂ̊��ʂ̏㏸�l��ύX����B
	/// </summary>
	/// <param name="���ʔԍ��y�z��p�z">�ΏۂƂȂ銯�ʂ́u�z��p�v�̔ԍ�</param>
	/// <param name="�㏸�l">1-24�܂ł̒l</param>
	/// <returns>����������true�A���s������false;</returns>
	bool Set_���ʏ㏸�l(int ���ʔԍ��y�z��p�z, int �㏸�l);

}

