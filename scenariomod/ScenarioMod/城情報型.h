/*
 * ����^ �y�сA ��t�����^
 */
#pragma once
#pragma pack(1)

#include <windows.h>

#include "�����.h"

using namespace std;

/*
	����(33*214)

	[33�o�C�g]

	0-1		�R�c�������X�g�̑O
	2-3		���X�g�̌��
	4-5		���
	6-7		�Q�l�擪
	8-16	�閼
	17-18	����	�����R�c�̌R�c�ԍ�
	19		��s
	20-21	�΍�
	22		����
	23-24	�l��-������
	25		����
	26-27	������
	28		���� 0-2
	29		ABC0 EFGH
			A �Ꝅ B ���ۍ` C �` E �n�Y�n F �b�� G �{�� H ����
	30		ABCD EFGH
			C �Ꝅ� G ���R H ��R
	31		AAAAAA BB
			A:���	0x00 �� 0x01 ��V 0x02 �� 0x04 �䏊 0x08 �� 0x10 �� 0x20 ��A����ȊO�̒l=�����t���Ȃ�
			B:��G���\���������́A�w�i�̎��(0=�R) (1=��) (2=�C) (3=����)
	32		000A000B A-���� B ���O�ύX
*/
struct ����^
{
	WORD �O�̏�y��ԍ��z;			/// <summary>���܂�g�����Ƃ͂Ȃ�  �R�c�����郊�X�g �O�̏�</summary>
	WORD ���̏�y��ԍ��z;			/// <summary>�Ƃ��Ɏg�����Ƃ͂Ȃ�  �R�c�����郊�X�g ��̏�</summary>
	WORD ���y�����ԍ��z;			/// <summary><para>���̕����ԍ��B</para><para>���̏�̕����̃����N���X�g�̐擪�ł����邽�߁A���̔ԍ��𒼐ڕҏW���Ȃ����ƁB</para><para>����ύX�������ꍇ�ASet_���(...) �𗘗p���邱��</para></summary>
	WORD _�Q�l�擪�����y�����ԍ��z;	/// <summary>���܂�g�����Ƃ͂Ȃ��B���̏�ɘQ�l������ۂ̘Q�l�����N���X�g�̍ŏ��̕����ԍ��B</summary>

	char _�閼[9];					/// <summary>�閼�B����𒼐ڎg�킸�AGet_�閼(...)���g�����ƁB</summary>
	WORD �����R�c�y�R�c�ԍ��z;		/// <summary>�����R�c�ԍ��Bp�R�c���[ix]��ix�̒l���P�傫�Ȑ��B</summary>
	byte ��s;						/// <summary>��s</summary>
	WORD �΍�;						/// <summary>�΍�</summary>
	byte ����;						/// <summary>����</summary>
	WORD �l��;						/// <summary>�l��</summary>
	byte ����;						/// <summary>����</summary>
	WORD ������;					/// <summary>������</summary>

	byte ����;						/// <summary><para>���� 0-2  (��=0, ��=1, ��=2)</para><para>�u����::���v�`�u����::�ǁv�ɑΉ�����B</para></summary>
	byte �{��:2;					/// <summary><para>�{�� ���� (�喼�̖{��=1, �R�c���̋���=2)�B</para><para>�u�{��::�喼�A�{��::�R�c���v�ɑΉ�����B</para></summary>
	byte �b��:1;					/// <summary>�b��</summary>
	byte �n�Y�n:1;					/// <summary>�n�Y�n</summary>
	byte _����`3:1;				/// <summary>0</summary>
	byte �`:1;						/// <summary>�`</summary>
	byte ���ۍ`:1;					/// <summary>���ۍ`</summary>
	byte _����`4:1;				
	byte ��R:1;					/// <summary><para>��R</para><para>��R�������Ă���ƁA���̏�́u���R�v�̕]�����a�ƂȂ�B</para><para>���R�������Ă���ƁA���̏�́u���R�v�̕]�����`�ƂȂ�B</para><para>��R�Ƌ��R�̗����������Ă���ƁA���̏�́u���R�v�̕]�����r�ƂȂ�B</para><para>���������Ă��Ȃ��ꍇ�́A���̏�́u���R�v�̕]���́~�ƂȂ�B</para></summary>
	byte ���R:1;					/// <summary><para>���R</para><para>��R�������Ă���ƁA���̏�́u���R�v�̕]�����a�ƂȂ�B</para><para>���R�������Ă���ƁA���̏�́u���R�v�̕]�����`�ƂȂ�B</para><para>��R�Ƌ��R�̗����������Ă���ƁA���̏�́u���R�v�̕]�����r�ƂȂ�B</para><para>���������Ă��Ȃ��ꍇ�́A���̏�́u���R�v�̕]���́~�ƂȂ�B</para></summary>
	byte _����`5:2;				///
	byte �Ꝅ� : 1;				/// <summary>�Ꝅ�</summary>
	byte _����`6:3;				///

	byte ��G�w�i:2;				/// <summary><para>��G���\���������́A�w�i�̎�� ���(0=�R) (1=��) (2=�C) (3=����)�B</para><para>�u��G�w�i::�R�v�`�u��G�w�i::����v�ɑΉ�����B</para></summary>
	byte _���:6;					/// <summary>�����̏���Get_���(...)�œ��邱�ƁB</summary>
	byte _�閼�ύX��:1;				///  <summary><para>�閼��ύX���Ă��邽�߁A�K���u_�閼[9]�v��u_��́v�̕����f�[�^�Ƃ��ĎQ�Ƃ���A�Ƃ����t���O</para></summary>
	byte _����`7 : 2;				///  
	byte ����:1;					/// <summary>����</summary>

	byte _����`8 :4;				/// <summary>��{�O�������Ă���͗l</summary>
};


namespace �֐� {

	/// <summary>
	/// �Ώۂ̏閼���擾������擾����B
	/// <para>�Ԃ�l�F�Ώۂ̏閼�̕�����B�ő�őS�p�S�����B(8�o�C�g)</para>
	/// </summary>
	/// <param name="��ԍ��y�z��p�z">�Ώۂ̏�́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ώۂ̏閼�̕�����B�ő�őS�p�S�����B(8�o�C�g)</returns>
	string Get_�閼( int ��ԍ��y�z��p�z);


	/// <summary>
	/// �Ώۂ̏�̖��O��ݒ肷��B
	/// </summary>
	/// <param name="��ԍ��y�z��p�z">�Ώۂ̏�́u�z��p�v�̔ԍ�</param>
	/// <param name="�閼�z">�Ώۂ̏�̖��O�B�ő�őS�p�S�����B(8�o�C�g)</param>
	void Set_�閼( int ��ԍ��y�z��p�z, string �閼 );


	/// <summary>
	/// �u��E�䏊�E�فv�Ƃ������悤�ȁA�閼�ɕt�����̂̕�����𓾂�B
	/// <para>�Ԃ�l�F�Ώۂ̏�̏�̂̕�����</para>
	/// </summary>
	/// <param name="��ԍ��y�z��p�z">�Ώۂ̏�́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ώۂ̏�̏�̂̕�����</returns>
	string Get_���(int ��ԍ��y�z��p�z);


	/// <summary>
	/// �u��E�䏊�E�فv�Ƃ������悤�ȁA�閼�ɕt�����̂̕������ݒ肷��B
	/// </summary>
	/// <param name="��ԍ��y�z��p�z">�Ώۂ̏�́u�z��p�v�̔ԍ�</param>
	/// <param name="���">"��"�A"��V"�A"��"�A"�䏊"�A"��"�A"��" �̂����ꂩ�̎w�肷��B"��"�̑����""�ł��悢�B</param>
	/// <returns>�Ώۂ̏�̏�̂̕�����</returns>
	void Set_���(int ��ԍ��y�z��p�z, string ���);

	/// <summary>
	/// �Ώۂ̏閼�ɑΉ������ԍ��u�z��p�v���擾����B
	/// <para>�Ԃ�l�F�Ώۂ̏閼�ɑΉ������ԍ��u�z��p�v�B�Ώۂ̏邪���݂��Ȃ����ɂ�0xFFFF���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�閼">�Ώۂ̏閼�̕�����B
	/// <para><para>�������v��u�������v�̂����u�����v��u�����v�ɑ������镶������w�肷�邱�ƁB</para></para>
	/// </param>
	/// <returns>�Ώۂ̏閼�ɑΉ������ԍ��u�z��p�v�B�Ώۂ̏邪���݂��Ȃ����ɂ�0xFFFF���Ԃ��Ă���B</returns>
	int Get_��ԍ��y�z��p�z(string �閼);


	/// <summary>
	/// �w��̌R�c���������Ă����̐��𓾂�B
	/// <para>�Ԃ�l�F�w��R�c���������Ă����̐��B�w��R�c�����݂��Ȃ��ꍇ�Ȃǂ�0���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�R�c�ԍ��y�z��p�z">�Ώۂ̌R�c�́u�z��p�v�̔ԍ�</param>
	/// <returns>�w��R�c���������Ă����̐��B�w��R�c�����݂��Ȃ��ꍇ�Ȃǂ�0���Ԃ��Ă���B</returns>
	int Get_�R�c�����鐔(int �R�c�ԍ��y�z��p�z);


	/// <summary>
	/// �w��̌R�c���������Ă����́u�z��p�v�ԍ��̃��X�g�𓾂�B
	/// <para>�Ԃ�l�F�w��R�c���������Ă����́u�z��p�v�ԍ��̃��X�g�B�w��R�c�����݂��Ȃ��ꍇ�Ȃǂ͋�̃��X�g���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�R�c�ԍ��y�z��p�z">�Ώۂ̌R�c�́u�z��p�v�̔ԍ�</param>
	/// <returns>�w��R�c���������Ă����́u�z��p�v�ԍ��̃��X�g�B�w��R�c�����݂��Ȃ��ꍇ�Ȃǂ͋�̃��X�g���Ԃ��Ă���B</returns>
	�ԍ����X�g�^ Get_�R�c������ԍ����X�g�y�z��p�z(int �R�c�ԍ��y�z��p�z);


	/// <summary>
	/// �w��̑喼���������Ă����̐��𓾂�B
	/// <para>�Ԃ�l�F�w��喼���������Ă����̐��B�w��喼�����݂��Ȃ��ꍇ�Ȃǂ�0���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�喼�ԍ��y�z��p�z">�Ώۂ̑喼�́u�z��p�v�̔ԍ�</param>
	/// <returns>�w��喼���������Ă����̐��B�w��喼�����݂��Ȃ��ꍇ�Ȃǂ�0���Ԃ��Ă���B</returns>
	int Get_�喼�����鐔(int �喼�ԍ��y�z��p�z);


	/// <summary>
	/// �w��̑喼���������Ă����́u�z��p�v�ԍ��̃��X�g�𓾂�B
	/// <para>�Ԃ�l�F�w��喼���������Ă����́u�z��p�v�ԍ��̃��X�g�B�w��喼�����݂��Ȃ��ꍇ�Ȃǂ͋�̃��X�g���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�喼�ԍ��y�z��p�z">�Ώۂ̑喼�́u�z��p�v�̔ԍ�</param>
	/// <returns>�w��喼���������Ă����́u�z��p�v�ԍ��̃��X�g�B�w��喼�����݂��Ȃ��ꍇ�Ȃǂ͋�̃��X�g���Ԃ��Ă���B</returns>
	�ԍ����X�g�^ Get_�喼������ԍ����X�g�y�z��p�z(int �喼�ԍ��y�z��p�z);
}


/*
	��̈ʒu���Ȃ�(8*214)

	[8�o�C�g]

	0	�n�於
	1	0
	2	�΍��ő�l/10
	3	���ƍő�l
	4	X�Z�����W(�}�b�v�Ō����Ă�̂Ƃ͈قȂ��؂�� 50�ŋ�؂��Ă���)
	5	Y�Z�����W(��Ɠ����ŁA�}�b�v�Ō����Ă���̂Ƃ͈قȂ��؂��12���x�ŋ�؂��Ă���)
	6	X_offset
	7	Y_offset
*/
struct ��t�����^
{
    byte �����n��y�n��ԍ��z;	/// <summary>�Ώۂ̏邪�����Ă���n��B�n����^���Q�Ƃ̂��ƁB</summary>
	byte _����`1;				/// <summary>must 0</summary>
	byte �ő�΍���10;			/// <summary>�ő�΍���10�B��ʏ�ł͂��̒l��10�{�̒l���\�������B</summary>
	byte �ő古�ƒl;			/// <summary>�ő古��</summary>
	byte _�w���;				/// <summary><para>���s�����B���ɗ��p���邱�Ƃ͂Ȃ��B</para><para>��q�̂w�ʒu�Ƒ��֓I�Ȓl�B</para></summary>
	byte _�x���;				/// <summary><para>���s�����B���ɗ��p���邱�Ƃ͂Ȃ��B</para><para>��q�̂x�ʒu�Ƒ��֓I�Ȓl�B</para></summary>
	byte �w�ʒu;				/// <summary><para>��̂w�ʒu�B</para><para>Set_��ʒu(...)�Ŏw�肷��l�Ɠ����B�O���b�h�}�b�v�𓱓�����΂悭�킩��B</para><para>�O���b�h���̂w���͂T�i�����S���g���A�P�͋��E����j</para></summary>
	byte �x�ʒu;				/// <summary><para>��̂x�ʒu�B</para><para>Set_��ʒu(...)�Ŏw�肷��l�Ɠ����B�O���b�h�}�b�v�𓱓�����΂悭�킩��B</para><para>�O���b�h���̂x���͂R�D</para></summary>
};

namespace �֐� {

	/// <summary>
	/// ��̈ʒu���ړ�����B
	/// <para>�u������O���b�h���v�ňړ����邱�ƁB�O���b�h���͂ݏo���ƁA����N���b�N���Ă��������Ȃ��Ȃ��Ă��܂��B</para>
	/// </summary>
	/// <param name="��ԍ��y�z��p�z">�Ώۂ̏�́u�z��p�v�̔ԍ�</param>
	/// <param name="�w�ʒu">��̂w�ʒu�B</param>
	/// <param name="�x�ʒu">��̂x�ʒu�B</param>
	void Set_��ʒu(int ��ԍ��y�z��p�z, int �w�ʒu, int �x�ʒu);
}



/*
 �ȉ��A���C���}�b�v�̃O���b�h���ŋ�؂�ꂽ��O���b�h�̈ʒu�̌v�Z
 */

/// <summary>
/// <para>���C���}�b�v�̃O���b�h�p�̍\���́B</para>
/// <para>Get_��O���b�h�ʒu(int ��ԍ��y�z��p�z)�֐��̕Ԃ�l�Ƃ��ē��邱�Ƃ��o����B</para>
/// </summary>
struct ��O���b�h�ʒu�^ {
	int �w; // �w�����̃O���b�h�ԖځB�O�n�܂�B��ʂ̍��[���O�B
	int �x; // �x�����̃O���b�h�ԖځB�O�n�܂�B��ʂ̏�[���O�B
	��O���b�h�ʒu�^(int _x,int _y);
	��O���b�h�ʒu�^() : �w(0),�x(0) {}

	WORD �k���y��ԍ��z; // ���݂��Ȃ����́A0xFFFF;
	WORD �k�y��ԍ��z;   // ���݂��Ȃ����́A0xFFFF;
	WORD �k���y��ԍ��z; // ���݂��Ȃ����́A0xFFFF;
	WORD ���y��ԍ��z;   // ���݂��Ȃ����́A0xFFFF;
	WORD ���y��ԍ��z;   // ���݂��Ȃ����́A0xFFFF;
	WORD �쐼�y��ԍ��z; // ���݂��Ȃ����́A0xFFFF;
	WORD ��y��ԍ��z;   // ���݂��Ȃ����́A0xFFFF;
	WORD �쓌�y��ԍ��z; // ���݂��Ȃ����́A0xFFFF;
};

/// <summary>
/// �u�Q�_�̏�O���b�h�ʒu�^�v�̍������Ӗ���������x�N�g���B
/// </summary>
struct ��O���b�h�x�N�g���^ {
	int �w;
	int �x;
	��O���b�h�x�N�g���^(int �w����, int �x����) : �w(�w����),�x(�x����) {}
	��O���b�h�x�N�g���^() : �w(0),�x(0) {}
};

namespace �֐� {

	/// <summary>
	/// �Ώۂ̏�̉�ʂ́u�O���b�h�Ƃ��Ắv�ʒu�𓾂�B
	/// <para>����O���b�h��0,0�BMapDataObgkMod(���O���b�h�}�b�v)�𓱓����Ă���ƁA</para>
	/// <para>�O���b�h���͂�����ƖڂŌ�����̂ł킩��₷��</para>
	/// <para>��ʏ�ł́A�オ�O�ŉ�ʂ̉��ɂ����قǐ��l��������B</para>
	/// <para>(���P�̃O���b�h�ɂ́A�P�̏邵���Ȃ��B)</para>
	/// <para>�Ԃ�l�F�Ώۂ̏�́u��O���b�h�ʒu�^�v�Ƃ��Ă̏��B</para>
	/// </summary>
	/// <param name="��ԍ��y�z��p�z">�Ώۂ̏�́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ώۂ̏�́u��O���b�h�ʒu�^�v�Ƃ��Ă̏��B</returns>
	��O���b�h�ʒu�^ Get_��O���b�h�ʒu(int ��ԍ��y�z��p�z);


	/// <summary>
	/// ��O���b�h���W���u�̌��Z�B���W�`�����W�a�̍��ł�������x�N�g���B
	/// </summary>
	��O���b�h�x�N�g���^ operator-(��O���b�h�ʒu�^ &p1, ��O���b�h�ʒu�^ &p2);


	/// <summary>
	/// ��`�Ə�a���אڂ��Ă��邩�ǂ����B(�����Ȃ����Ă��邩�ǂ����͍l�����Ȃ�)
	/// <para>�Ԃ�l�F�אڂ��Ă�����true�A�אڂ��Ă��Ȃ����false</para>
	/// </summary>
	/// <param name="��`�ԍ��y�z��p�z">�Ώۂ̏�`�́u�z��p�v�̔ԍ�</param>
	/// <param name="��a�ԍ��y�z��p�z">�Ώۂ̏�a�́u�z��p�v�̔ԍ�</param>
	/// <returns>�אڂ��Ă�����true�A�אڂ��Ă��Ȃ����false</returns>
	bool Is_�אڏ�(int ��`�ԍ��y�z��p�z, int ��a�ԍ��y�z��p�z);


	/// <summary>
	/// ��`�Ə�a���אڂ��Ă��邩�ǂ����B(�����Ȃ����Ă��邩�ǂ����͍l�����Ȃ�)
	/// <para>�Ԃ�l�F�אڂ��Ă�����true�A�אڂ��Ă��Ȃ����false</para>
	/// </summary>
	/// <param name="�ʒu�P">�Ώۂ̏�`�̏�O���b�h�ʒu�^�̒l</param>
	/// <param name="�ʒu�Q">�Ώۂ̏�a�̏�O���b�h�ʒu�^�̒l</param>
	/// <returns>�אڂ��Ă�����true�A�אڂ��Ă��Ȃ����false</returns>
	bool Is_�אڏ�(��O���b�h�ʒu�^ &�ʒu�P, ��O���b�h�ʒu�^ &�ʒu�Q);


	/// <summary>
	/// �Ώۂ̏�𒆐S�ɁA�u�o�H(��)�v���q�����Ă�����ӂ̏�ԍ��̃��X�g�𓾂�B
	/// <para>�Ԃ�l�F�Ώۏ�́u���ӂ̗אڏ�v�ł��u�����q�����Ă����v�́u��ԍ��w�z��p�x�v�̃��X�g�B</para>
	/// </summary>
	/// <param name="��ԍ��y�z��p�z">�Ώۂ̏�́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ώۏ�́u���ӂ̗אڏ�v�ł��u�����q�����Ă����v�́u��ԍ��w�z��p�x�v�̃��X�g�B</returns>
	�ԍ����X�g�^ Get_�o�H�A���̗אڏ�ԍ����X�g�y�z��p�z(int ��ԍ��y�z��p�z);


	/*
	�������牺�͌o�H�T���֘A�B
	*/

	// 
	/// <summary>
	/// ��o�H�̃O���t�����ݎ��s���̓��A�����ʒu�̏������ɍč\�z����B
	/// </summary>
	void Set_��o�H�O���t������();


	/// <summary>
	/// <para>��o�H�̃O���t�֘A�̌v�Z�ɂ����āA�Ώۂ̏�́u�o�H�v�Z�v���珜�O����B</para>
	/// <para>����ɂ���āA�uGet_�o�H��̏�ԍ����X�g�y�z��p�z(...)�v�̊֐��Ōo�H�T���̑Ώ۔͈͂��R���g���[���o����B</para>
	/// </summary>
	/// <param name="��ԍ��y�z��p�z">�Ώۂ̏�́u�z��p�v�̔ԍ�</param>
	void Set_��o�H�O���t�����폜(int ��ԍ��y�z��p�z);


	/// <summary>
	/// <para>�J�n�_�̏�`���ړI�_�̏�a�܂ŁA���z�I�ɓ��o�H�łȂ����ہA�H�邱�ƂƂȂ�o�H��̏�ꗗ�𓾂�B</para>
	/// <para>�Ԃ�l�F�Ώۏ�́u���ӂ̗אڏ�v�ł��u�����q�����Ă����v�́u��ԍ��w�z��p�x�v�̃��X�g�B</para>
	/// </summary>
	/// <param name="�J�n��ԍ��y�z��p�z">�J�n(�N�_)�|�C���g�ƂȂ��́u�z��p�v�̔ԍ�</param>
	/// <param name="�ړI��ԍ��y�z��p�z">�ړI(�I�_)�|�C���g�ƂȂ��́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ώۏ�́u���ӂ̗אڏ�v�ł��u�����q�����Ă����v�́u��ԍ��w�z��p�x�v�̃��X�g�B</returns>
	�ԍ����X�g�^ Get_�o�H��̏�ԍ����X�g�y�z��p�z(int �J�n��ԍ��y�z��p�z, int �ړI��ԍ��y�z��p�z);
}





/// <summary>
/// �u�퍑���镨��^�� �J�X�^��::On_�퍑���镨��v����(int ��ԍ�) �v���\�b�h�̕Ԃ�l�̌^
/// </summary>
struct �퍑���镨��^ {

public:
	string _���x��;
	string _�ڍ�;

public:
	/// <summary>
	/// �퍑���镨���ݒ肷��B
	/// </summary>
	/// <param name="���x��">�퍑���镨�ꎞ�ɕ\�������A���O�B36�o�C�g�܂ŁB�S�p����18�����B</param>
	/// <param name="�ڍ�">�퍑���镨�ꎞ�ɕ\�������A�ڍׂȖ��镨��B�S�p����18�����~�S�s�B</param>
	inline  �퍑���镨��^(string ���x��, string �ڍ�) {
		_���x�� = ���x��;
		_�ڍ� = �ڍ�;
	};

	// NULL���^�[���ɑΉ����邽�߁B
	inline  �퍑���镨��^(int iDefault) {}
};
#define  �퍑���镨��^��	 �퍑���镨��^
