/*
 * �R�c���^
 */
#pragma once
#pragma pack(1)

#include <windows.h>



/*
	�R�c���(21*214)

	[21�o�C�g]

	0-1	�O�̌R�c
	2-3 ���̌R�c
	4-5	���閼�i���o�[
	6-7	�R�c���i���o�[(�������O�e�[�u���̏���)
	8-9	�喼
	10	�s����
	11-12	��
	13-14	��
	15-16	�R�n
	17-18	�S�C
	19	�H
	20	aaaabbbb A ��E B �R�c�ԍ�
		0 ���� 1 ���Α叫�R 2 �Ǘ� 3 �֓��Ǘ� 4 ���B�T�� 5 �����T�� 6 ��B�T�� 7 �H�B�T�� �� Get_�R�c��E

 */
struct �R�c���^
{
	WORD �O�̌R�c�y�R�c�ԍ��z;	/// <summary>���܂�g��Ȃ��B�����N���X�g�őO�̌R�c</summary>
	WORD ���̌R�c�y�R�c�ԍ��z;	/// <summary>�Ƃ��Ɏg��Ȃ��B�����N���X�g�Ŏ��̌R�c</summary>
	WORD ��������y��ԍ��z;	/// <summary>�R�c���������̏�ԍ�</summary>
	WORD �R�c���y�����ԍ��z;	/// <summary>�R�c����p�������Ƃ��Ă̕����ԍ�</summary>
	WORD �����喼�y�喼�ԍ��z;	/// <summary>�R�c���������Ă���喼��p�喼���Ƃ��Ă̑喼�ԍ�</summary>
	byte �s����;				/// <summary>�s����</summary>
	WORD ��;					/// <summary>��</summary>
	WORD ��;					/// <summary>��</summary>
	WORD �n;					/// <summary>�n</summary>
	WORD �S�C;					/// <summary>�S�C</summary>
	byte _����`1;				/// <summary>must 0?</summary>
	byte �R�c�����ԍ�:4;		/// <summary>1-8 �� �R�c���蓖�Ĕԍ�</summary>
	byte _��E:4;				/// <summary>��E  <para>(0 ���� 1 ���Α叫�R 2 �Ǘ� 3 �֓��Ǘ� 4 ���B�T�� 5 �����T�� 6 ��B�T�� 7 �H�B�T��)</para><para>����𒼐ڗ��p����̂ł͂Ȃ��AGet_�R�c��E�Œl�𓾂邱�ƁB</para></summary>
};

namespace �֐� {

	/// <summary>
	/// �Ƃ���R�c�ɏ������镺�m�̑����𓾂�
	/// <para>�Ԃ�l�F���m����</para>
	/// </summary>
	/// <param name="�R�c�ԍ��y�z��p�z">�ΏۂƂȂ�R�c�́u�z��p�v�̔ԍ�</param>
	/// <returns>���m�̑���</returns>
	int Get_�R�c����(int �R�c�ԍ��y�z��p�z);


	/// <summary>
	/// ����(���̏u��)�A�V�ċL�ɑ��݂���R�c�́u�R�c�ԍ��y�z��p�z�v�����X�g�œ���B
	/// <para>�Ԃ�l�F�L���ȌR�c�́A�R�c�ԍ��y�z��p�z��ԍ����X�g�^�œ���B</para>
	/// </summary>
	/// <param name="�R�c�ԍ��y�z��p�z">�ΏۂƂȂ�R�c�́u�z��p�v�̔ԍ�</param>
	/// <param name="�V�����喼�ԍ��y�z��p�z">�Ƒւ���̑喼�́u�z��p�v�̔ԍ�</param>
	/// <returns>��������ΐ^�A���s����΋U</returns>
	�ԍ����X�g�^ Get_�R�c�ԍ����X�g�y�z��p�z() ;


	/// <summary>
	/// <para>�Ώۂ̑喼�ɏ�������R�c�́A�R�c�ԍ��y�z��p�z���A���X�g�Ƃ��ē���B</para>
	/// <para>�Ԃ�l�F�R�c�ԍ��y�z��p�z�����X�g�Ƃ��ē���B</para>
	/// </summary>
	/// <param name="�喼�ԍ��y�z��p�z">�ΏۂƂȂ�喼�́u�z��p�v�̔ԍ�</param>
	/// <returns>�R�c�ԍ��y�z��p�z�����X�g�Ƃ��ē���B</returns>
	�ԍ����X�g�^ Get_�喼�����R�c�ԍ����X�g�y�z��p�z(int �喼�ԍ��y�z��p�z);


	/// <summary>
	/// <para>�Ώۂ̌R�c�ɏ�������A�L���ȕ����̕����ԍ��y�z��p�z���A���X�g�Ƃ��ē���B</para>
	/// <para>�Ԃ�l�F�w��R�c�����́u�喼�E�R�c���E�����v�̕����ԍ��y�z��p�z�̃��X�g�𓾂�B</para>
	/// </summary>
	/// <param name="�喼�ԍ��y�z��p�z">�ΏۂƂȂ�R�c�́u�z��p�v�̔ԍ�</param>
	/// <returns>�w��R�c�����́u�喼�E�R�c���E�����v�̕����ԍ��y�z��p�z�̃��X�g</returns>
	�ԍ����X�g�^ Get_�R�c���������ԍ����X�g�y�z��p�z(int �R�c�ԍ��y�z��p�z);


	/// <summary>
	/// <para>�Ƃ���喼�z���̌R�c�Ɋւ��āA�u�P�`�W�̌R�c���蓖�Ĕԍ��v�Ŏg�p�ς݂̔ԍ��̃��X�g�𓾂�B</para>
	/// <para>�v����ɁA����̑喼�Ɂu��P�R�c�A��R�R�c�A��S�R�c�v�����łɐݗ�����Ă���A�Ƃ��������Ƃ𓾂�֐��B</para>
	/// <para>�Ԃ�l�F�u�R�c���蓖�Ĕԍ��v�̃��X�g��ԍ����X�g�`���œ���B</para>
	/// <para>���̃��X�g�̒l�́A�K�������Ƀ\�[�g����Ă���B</para>
	/// </summary>
	/// <param name="�喼�ԍ��y�z��p�z">�ΏۂƂȂ�喼�́u�z��p�v�̔ԍ�</param>
	/// <returns>
	/// <para>�u�R�c���蓖�čς݂̂P�`�W�̔ԍ��v�̃��X�g��ԍ����X�g�`���œ���B</para>
	/// <para>���̃��X�g�̒l�́A�K�������Ƀ\�[�g����Ă���B</para>
	/// </returns>
	�ԍ����X�g�^ Get_�R�c�����ԍ����X�g(int �喼�ԍ��y�z��p�z);


	/// <summary>
	/// <para>�Ƃ���喼�z���̌R�c�Ɋւ��āA�u�P�`�W�̌R�c���蓖�Ĕԍ��v�ł܂��g�p����Ă��Ȃ��ԍ��̃��X�g�𓾂�B</para>
	/// <para>�v����ɁA����̑喼�Ɂu��Q�R�c�A��T�R�c�A��U�R�c�A��V�R�c�v�����łɐݗ�����Ă���A�Ƃ��������Ƃ𓾂�֐��B</para>
	/// <para>�Ԃ�l�F�P�`�W�̔ԍ��̂����A�܂����蓖�Ă��Ă��Ȃ��ԍ���ԍ����X�g�`���œ���B</para>
	/// <para>���̃��X�g�̒l�́A�K�������Ƀ\�[�g����Ă���B</para>
	/// </summary>
	/// <param name="�喼�ԍ��y�z��p�z">�ΏۂƂȂ�喼�́u�z��p�v�̔ԍ�</param>
	/// <returns>
	/// <para>�u�R�c�ɂ܂����蓖�Ă��Ă��Ȃ��P�`�W�̔ԍ��v�̃��X�g��ԍ����X�g�`���œ���B</para>
	/// <para>���̃��X�g�̒l�́A�K�������Ƀ\�[�g����Ă���B</para>
	/// </returns>
	�ԍ����X�g�^ Get_�R�c�������ԍ����X�g(int �喼�ԍ��y�z��p�z);



	/// <summary>
	/// <para>��Q�R�c�ȍ~�ŁA�R�c�̊��蓖�Ĕԍ��������E�ύX����B</para>
	/// <para>�Ԃ�l�F��������ΐ^�E���s����΋U</para>
	/// </summary>
	/// <param name="�R�c�ԍ��y�z��p�z">�ΏۂƂȂ�R�c�́u�z��p�v�̔ԍ�</param>
	/// <param name="�V�����ԍ�">�V���Ȋ��蓖�Ĕԍ��B�P�`�W</param>
	/// <returns>
	/// <para>�u�R�c���蓖�čς݂̂P�`�W�̔ԍ��v�̃��X�g��ԍ����X�g�`���œ���B</para>
	/// <para>���̃��X�g�̒l�́A�K�������Ƀ\�[�g����Ă���B</para>
	/// </returns>
	bool Set_�R�c�����ԍ��ύX(int �R�c�ԍ��y�z��p�z, int �V�����ԍ�);

}

namespace �֐� {

	/// <summary>
	/// <para>�Ƃ���R�c�ɁA�R�t������΁A���̌R�t�̕����ԍ��y�z��p�z�𓾂�B</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>�R�t������΁A�R�t�̕����ԍ��y�z��p�z���Ԃ��Ă���B</para>
	/// <para>���Ȃ����0xFFFF���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�R�c�ԍ��y�z��p�z">�ΏۂƂȂ�R�c�́u�z��p�v�̔ԍ�</param>
	/// <returns>
	/// <para>�R�t������΁A�R�t�̕����ԍ��y�z��p�z���Ԃ��Ă���B</para>
	/// <para>���Ȃ����0xFFFF���Ԃ��Ă���B</para>
	/// </returns>
	int Get_�R�t�����ԍ��y�z��p�z(int �R�c�ԍ��y�z��p�z);


}


struct �R�c�V�݌����^ {
	int �喼�ԍ��y�z��p�z;                     /// <summary>�ǂ̑喼�ɂ��Ă̏��Ȃ̂��B</summary>
	BOOL Is�V�݉\;                            /// <summary>���ǁA�ȉ��̂R�v�f����l���āA�R�c�̐V�݂͉\�Ȃ̂��A�s�\�Ȃ̂��B</summary>
	�ԍ����X�g�^ ���R�c�����ԍ����X�g;        /// <summary>�R�c�����ԍ��i�P�`�W�j�ŗ]���Ă���ԍ��̃��X�g�BGet_�R�c�������ԍ����X�g(...) �Ɠ����l</summary>
	�ԍ����X�g�^ ����ԍ��y�z��p�z���X�g;    /// <summary>�����R�c��V�ݏo����Ƃ���΁A�����̏邪���ƂȂ�A�Ƃ������X�g</summary>
	�ԍ����X�g�^ ��═���ԍ��y�z��p�z���X�g;  /// <summary>�����R�c��V�ݏo����Ƃ���΁A�����̕������V���ȌR�c���Ƃ��ĔC�����꓾��A�Ƃ������X�g</summary>
};


namespace �֐� {
	/// <summary>
	/// <para>�Ƃ���喼�ƂɌR�c��V�݉\���ǂ�����₢���킹��</para>
	/// <para>���̌��ʁA�u�s�v�u�ǂ̕�������₩�v�u�ǂ̏邪��₩�v�Ƃ�������񂪓�����</para>
	/// <para>���̊֐��œ���ꂽ�������ɁA Set_�R�c�V��(...)�֐��ŌR�c�����ۂɐV�݂��邱�ƂƂȂ�B</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>�R�c�V�݌����^�̒l���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�R�c���ɂ����������ԍ��y�z��p�z</param>
	/// <param name="��ԍ��y�z��p�z">�R�c��V�݂�������ԍ��y�z��p�z</param>
	/// <param name="���S�`�F�b�N�p�R�c�V�݌���">Get_�R�c�V�݌����(...)�֐��̌��ʒl��n���K�v������B</param>
	/// <returns>
	/// <para>�R�c�V�݌����^�̒l���Ԃ��Ă���B</para>
	/// </returns>
	�R�c�V�݌����^ Get_�R�c�V�݌����(int �喼�ԍ��y�z��p�z);


	/// <summary>
	/// <para>�Ƃ���喼�ƂɌR�c��V�݂���</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>�V�݂ł����ꍇ�́A�R�c�ԍ��y�z��p�z���Ԃ��Ă���</para>
	/// <para>�V�݂ł��Ȃ������ꍇ0xFFFF���Ԃ��Ă���B</para>
	/// <para>Get_�R�c�V�݌����()�̕Ԃ�l�Ɋ�Â��āA�g�����Ƃ��z�肳��Ă���B</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�R�c���ɂ����������ԍ��y�z��p�z</param>
	/// <param name="��ԍ��y�z��p�z">�R�c��V�݂�������ԍ��y�z��p�z</param>
	/// <param name="���S�`�F�b�N�p�R�c�V�݌����">Get_�R�c�V�݌����(...)�֐��̌��ʒl��n���K�v������B</param>
	/// <returns>
	/// <para>�V�݂ł����ꍇ�́A�R�c�ԍ��y�z��p�z���Ԃ��Ă���B</para>
	/// <para>�V�݂ł��Ȃ������ꍇ0xFFFF���Ԃ��Ă���B</para>
	/// </returns>
	int Set_�R�c�V��(int �����ԍ��y�z��p�z, int ��ԍ��y�z��p�z, �R�c�V�݌����^ ���S�`�F�b�N�p�R�c�V�݌����);

	/// <summary>
	/// <para>�Ƃ���u�P�̑喼�̉��ɌR�c�`�ƌR�c�a�v������Ƃ��āA</para>
	/// <para>���̑喼�̉��ɂ���u�R�c�`�̏�v���u�ʂ̌R�c�a�v�ւƈڐ݂���</para>
	/// <para>�A���A��{���Ɍ���(��{���Ƃ͌R�c����喼�����Ȃ���)</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>���������ꍇ�͐^</para>
	/// <para>���s�����ꍇ�͐^</para>
	/// </summary>
	/// <param name="��ԍ��y�z��p�z">�ʂ̌R�c���Ɉڐ݂�������́u�z��p�v�ԍ�</param>
	/// <param name="����R�c�ԍ��y�z��p�z�z">��̐V���Ȉڐݐ�̌R�c�́u�z��p�v�ԍ�</param>
	/// <returns>
	/// <para>���������ꍇ�͐^</para>
	/// <para>���s�����ꍇ�͐^</para>
	/// </returns>
	bool Set_��{���鏊���R�c(int ��ԍ��y�z��p�z, int ����R�c�ԍ��y�z��p�z);


	/// <summary>
	/// <para>�Ƃ���喼�Ƃɏ������Ă���R�c��Ɨ������A�喼�Ƃ���</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>�Ɨ��ł����ꍇ�́A�喼�ԍ��y�z��p�z���Ԃ��Ă���</para>
	/// <para>�Ɨ��ł��Ȃ������ꍇ0xFFFF���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�R�c�ԍ��y�z��p�z">�Ɨ����������R�c�ԍ��y�z��p�z</param>
	/// <returns>
	/// <para>�Ɨ��ł����ꍇ�́A�喼�ԍ��y�z��p�z���Ԃ��Ă���</para>
	/// <para>�Ɨ��ł��Ȃ������ꍇ0xFFFF���Ԃ��Ă���B</para>
	/// </returns>
	int Set_�R�c�Ɨ�(int �R�c�ԍ��y�z��p�z);


	/// <summary>
	/// �w��̌R�c����������喼���A���͂��z���ĕύX����B
	/// <para>�喼�`�̟����̌R�c�����A�喼�a�̟����ւƌR�c���ƈƑւ�����Ƃ������ƁB</para>
	/// </summary>
	/// <param name="�R�c�ԍ��y�z��p�z">�ΏۂƂȂ�R�c�́u�z��p�v�̔ԍ�</param>
	/// <param name="����喼�ԍ��y�z��p�z">�Ƒւ���̑喼�́u�z��p�v�̔ԍ�</param>
	/// <returns>��������ΐ^�A���s����΋U</returns>
	bool Set_�R�c�����喼(int �R�c�ԍ��y�z��p�z, int ����喼�ԍ��y�z��p�z);
}


/*
	�v���C���̒S���R�c(�喼�ԍ��ł͂Ȃ��R�c�ԍ�)�B�ő�W�B
*/
struct �v���C���S���R�c���^
{
	WORD �S���R�c�y�R�c�ԍ��z;
};


namespace �֐� {

	/// <summary>
	/// <para>�Ώۂ̑喼���v���C���[�S���̑喼�ł��邩�ǂ����𔻒f����B</para>
	/// <para>�Ԃ�l�F�v���C���[���S�����Ă���喼�Ȃ�ΐ^�A�����łȂ���΋U</para>
	/// </summary>
	/// <param name="�喼�ԍ��y�z��p�z">�ΏۂƂȂ�喼�́u�z��p�v�̔ԍ�</param>
	/// <returns>
	/// <para>�v���C���[���S�����Ă���喼�Ȃ�ΐ^�A�����łȂ���΋U</para>
	/// </returns>
	bool Is_�v���C���S���喼(WORD �喼�ԍ��y�z��p�z);

	/// <summary>
	/// <para>�Ώۂ̌R�c���v���C���[�S���̑喼�̔z���R�c�ł��邩�ǂ����𔻒f����B</para>
	/// <para>�Ԃ�l�F�v���C���[���S�����Ă���喼�̔z���R�c�Ȃ�ΐ^�A�����łȂ���΋U</para>
	/// </summary>
	/// <param name="�R�c�ԍ��y�z��p�z">�ΏۂƂȂ�R�c�́u�z��p�v�̔ԍ�</param>
	/// <returns>
	/// <para>�v���C���[���S�����Ă���喼�̔z���R�c�Ȃ�ΐ^�A�����łȂ���΋U</para>
	/// </returns>
	bool Is_�v���C���S���R�c(WORD �R�c�ԍ��y�z��p�z);

	/// <summary>
	/// <para>�Ώۂ̕������v���C���[�S���̑喼�̔z�������ł��邩�ǂ����𔻒f����B</para>
	/// <para>�Ԃ�l�F�v���C���[���S�����Ă���喼�̔z�������Ȃ�ΐ^�A�����łȂ���΋U</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>
	/// <para>�v���C���[���S�����Ă���喼�̔z�������Ȃ�ΐ^�A�����łȂ���΋U</para>
	/// </returns>
	bool Is_�v���C���S������(WORD �����ԍ��y�z��p�z);

}



