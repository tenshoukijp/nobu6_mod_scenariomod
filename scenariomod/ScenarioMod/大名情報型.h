/*
 * �喼���^
 */
#pragma once
#pragma pack(1)

#include <windows.h>

#include "�喼����.h"

/*
	�喼(22*72)

	0-1	����INDEX
	2-3	�R�c�ԍ�
	4-5	����
	6-7	�B�����X�g�擪
	8	�Ɩ�
	9	����
	A	�G�Α喼
	B	�F�D�喼
	C
	D	���l
	E	000A 000B  A�]�� B�z��
	F	��E 0x01 ���R 0x02 �Ǘ� 0x04 �֓��Ǘ� 0x08 ���B�T�� 0x10 �����T�� 0x20 ��B�T�� 0x40 �H�B�T��@��Get_�喼��E
		�������E�ɂ͂Ȃ�Ȃ��悤��
*/
struct �喼���^
{
    WORD �喼�y�����ԍ��z;		/// <summary>�喼�̕����Ƃ��Ă̔ԍ�</summary>
	WORD �����R�c�y�R�c�ԍ��z;	/// <summary>�R�c �R�c�ԍ�</summary>
	WORD ��������y��ԍ��z;	/// <summary>����</summary>
	WORD �B�������y�����ԍ��z;	/// <summary>���܂�g�����Ƃ͂Ȃ��B�B�����X�g�擪</summary>
	byte �Ɩ�;					/// <summary>�Ɩ�ԍ��B0�`159�B�Ō��16�̓��[�U�[���ҏW�����Ɩ�ƂȂ�B</summary>
    byte ����;					/// <summary>����Ƃ̐e���x</summary>
	byte �G�Α喼�y�喼�ԍ��z;	/// <summary>�G�Α喼�B�G�Α喼�����Ȃ��ꍇ��255(=0xFF)�B</summary>
	byte �F�D�喼�y�喼�ԍ��z;	/// <summary>�����喼�B�F�D�喼�Ƃ������O�����u�F�D�l�v�Ƃ͖��֌W�B�����喼�����Ȃ��ꍇ��255(=0xFF)�B</summary>
	byte ��p���l : 4;			/// <summary>�ǂ��̏��l��<para>�u��p���l::�_���@�X�v�`�u��p���l::�D���ЗR�v�܂ł̒l���Ƃ�B</para></summary>
	byte _����`0 : 4;			//
	byte ���l;					/// <summary>���l�Ƃ̐V���x</summary>
	byte �z����:1;				/// <summary>�z�� :�z���ς݂��ۂ�</summary>
	byte ���l�s�� : 1;			/// <summary>���l���{���Ă��܂��ĕs�݁B1�Ȃ�s�݁B0�Ȃ珤���\�B</summary>
	byte _����`2:2;			/// must 0 ���̎c���r�b�g�ɉ߂��Ȃ��B����ɐ��l����Ȃ�����
	byte �]��� : 1;			/// <summary>�]�� :�]��ς݂��ǂ���</summary>
	byte _����`3:3;			/// <summary>must 0 �]��̎c���r�b�g�ɉ߂��Ȃ��B����ɐ��l����Ȃ�����</summary>
	byte _��E;					/// <summary><para>��E�B</para><para>0x01 ���R 0x02 �Ǘ� 0x04 �֓��Ǘ� 0x08 ���B�T�� 0x10 �����T�� 0x20 ��B�T�� 0x40 �H�B�T��B</para><para>���̒l�𒼐ڎg�p�����AGet_�喼��E�Ȃǂ��g�p���邱�ƁB</para></summary>
	byte _����`4[6];			//
};



namespace �֐� {

	/// <summary>
	/// ���ݗL���ȑ喼�̃��X�g�𓾂�B
	/// <para>�u�喼�S�́v�ɉ�����������A�u�I��喼�_�C�A���O�\��()�v�֐����A�u�喼�ꗗ�������ɓn���v�ړI�ŗ��p����B</para>
	/// <para>�Ԃ�l�F�喼�́u�z��p�v�̔ԍ��̃��X�g��Ԃ��B</para>
	/// </summary>
	/// <param name="�^�[���喼���܂�">FALSE���w�肷��ƁA�^�[��������Ă���喼�ȊO�̃��X�g�ƂȂ�B</param>
	/// <returns>�喼�́u�z��p�v�̔ԍ��̃��X�g��Ԃ��B</returns>
	�ԍ����X�g�^ Get_�喼�ԍ����X�g�y�z��p�z(BOOL �^�[���喼���܂�=TRUE);
}



/*
 */
namespace �֐� {

	/// <summary>
	/// �`�喼�Ƃa�喼�Ƃ̗F�D�l�𓾂�B
	/// <para>�Ԃ�l�F�F�D�l</para>
	/// </summary>
	/// <param name="�喼�`�ԍ��y�z��p�z">�P�l�ڂ̑喼�́u�z��p�v�̔ԍ�</param>
	/// <param name="�喼�a�ԍ��y�z��p�z">�Q�ڂ̑喼�́u�z��p�v�̔ԍ�</param>
	/// <returns>�F�D�l</returns>
	int Get_�F�D�֌W(int �喼�`�ԍ��y�z��p�z, int �喼�a�ԍ��y�z��p�z);


	/// <summary>
	/// �`�喼�Ƃa�喼�Ƃ̗F�D�l��ݒ肷��B
	/// <para>�F�D�l��92�̂悤�Ȓ��r���[�Ȑ��������ꍇ90�Ƃ����悤�ɐ؂�̂Ă���B</para>
	/// <para>�}�C�i�X�l��0�ɁA100�I�[�o�[��100�ƂȂ�B</para>
	/// </summary>
	/// <param name="�喼�`�ԍ��y�z��p�z">�P�l�ڂ̑喼�́u�z��p�v�̔ԍ�</param>
	/// <param name="�喼�a�ԍ��y�z��p�z">�Q�ڂ̑喼�́u�z��p�v�̔ԍ�</param>
	/// <param name="�F�D�l">�ݒ肵�����F�D�l
	/// <remarks>
	/// <para>���܂�C�ɂ���K�v�͂Ȃ����A�F�D�֌W�̒l�́A�����Ď��R�Ȃ��̂ł͂Ȃ��A16��ނ̋K��l�̒�����w�肳��Ă���B</para>
	/// <para>�������A�����̒�����w�肵�����r����A�Ƃ����̂͂����ɂ��ʓ|�ł�������񒼊��I�Ȃ̂ŁA</para>
	/// <para>Set_�F�D�֌W�ł́A���ʂɒ����I�Ȓl�ɂāA0�`100�܂Ŏ��R�ɐݒ肵�āA�����I�ɋK��ɒl�ւƕϊ������Ƃ����d�g�݂Ƃ����B</para>
	/// <para>�Ⴆ�ΗF�D�l�Ƃ��āA�94��Ǝw�肵���ꍇ�A���ۂɂ͂��̂悤�ȗF�D�l(�̋K��l)�͑��݂����Ȃ��A�����I��90�ւ�(�l���������Ȃ������)�ϊ����Ă���B</para>
	/// </remarks>
	/// </param>
	void Set_�F�D�֌W(int �喼�`�ԍ��y�z��p�z, int �喼�a�ԍ��y�z��p�z, int �F�D�l);


	/// <summary>
	/// �`�喼�Ƃa�喼�������֌W���ǂ����𓾂�B
	/// <para>�Ԃ�l�F�����֌W�Ȃ�^�A�����֌W�łȂ��Ȃ�U</para>
	/// </summary>
	/// <param name="�喼�`�ԍ��y�z��p�z">�P�l�ڂ̑喼�́u�z��p�v�̔ԍ�</param>
	/// <param name="�喼�a�ԍ��y�z��p�z">�Q�ڂ̑喼�́u�z��p�v�̔ԍ�</param>
	/// <returns>�����֌W�Ȃ�^�A�����֌W�łȂ��Ȃ�U</returns>
	int Is_�����֌W(int �喼�`�ԍ��y�z��p�z, int �喼�a�ԍ��y�z��p�z);


	/// <summary>
	/// �`�喼�Ƃa�喼�������֌W���ǂ����𓾂�B
	/// <para>�Ԃ�l�F�����֌W�Ȃ�^�A�����֌W�łȂ��Ȃ�U</para>
	/// </summary>
	/// <param name="�喼�`�ԍ��y�z��p�z">�P�l�ڂ̑喼�́u�z��p�v�̔ԍ�</param>
	/// <param name="�喼�a�ԍ��y�z��p�z">�Q�ڂ̑喼�́u�z��p�v�̔ԍ�</param>
	/// <returns>�����֌W�Ȃ�^�A�����֌W�łȂ��Ȃ�U</returns>
	int Is_�����֌W(int �喼�`�ԍ��y�z��p�z, int �喼�a�ԍ��y�z��p�z);


	/// <summary>
	/// �`�喼�Ƃa�喼�𓯖���ԂƂ���B
	/// </summary>
	/// <param name="�喼�`�ԍ��y�z��p�z">�P�l�ڂ̑喼�́u�z��p�v�̔ԍ�</param>
	/// <param name="�喼�a�ԍ��y�z��p�z">�Q�ڂ̑喼�́u�z��p�v�̔ԍ�</param>
	/// <param name="������">TRUE�Ȃ瓯�����AFALSE�Ȃ瓯������</param>
	void Set_�����֌W(int �喼�`�ԍ��y�z��p�z, int �喼�a�ԍ��y�z��p�z, BOOL ������ = TRUE);


	/// <summary>
	/// �`�喼�Ƃa�喼��������ԂƂ���B
	/// </summary>
	/// <param name="�喼�`�ԍ��y�z��p�z">�P�l�ڂ̑喼�́u�z��p�v�̔ԍ�</param>
	/// <param name="�喼�a�ԍ��y�z��p�z">�Q�ڂ̑喼�́u�z��p�v�̔ԍ�</param>
	/// <param name="������">TRUE�Ȃ獥�����AFALSE�Ȃ獥������</param>
	void Set_�����֌W(int �喼�`�ԍ��y�z��p�z, int �喼�a�ԍ��y�z��p�z, BOOL ������ = TRUE);

}

