/*
 * �������^ �y�сA �����ːЏ��^
 */
#pragma once
#pragma pack(1)

#include <windows.h>

#include "��������.h"

/*
	[�����f�[�^(47*532)]

	0-1	�O�̕���
	2-3 ���̕���
	4-5	�H
	6	����
	7	���
	8	�q��
	9-10	���n ( min 500 �` max 2000 )
	11-12	��n ( min 500 �` max 2000 )
	13-14	�q�n ( min 500 �` max 2000 )
	15	����
	16	��]
	17	����
	18-19	�M��
	20	���� 0xFF�͖���
	21-22	�喼
	23-24	�R�c
	25-26	����
	27-28	������ FFFF ����
	29	����
	30	�P��
	31	����
	32	����(0=���y,1=�R�n,2=�S�C,3=�R�n�S�C,18�܂�)
	33	�d��
	34	�� ���Ɍ����ς݃t���O����H
	35	���N
	36-37	�e��NO
	38	�v�l�@�i�v�l�A���S���Y���j
	39	aaaabbbb a-���� b-�`��
	40	00aabbcc a-�q�K b-��K c-���K
	41	�Z�\
	42	�E�� 0x00�� 0x10 �E�� 0x20 ���l 0x30 ���� 0x40 �m�� 0x50 �C�� 0x60 ���� 0x70 ���l 0x80 ���� 0x90 �؎x�O 0xA0 �R�m 0xB0 ���p�m 0xC0 ����
	43-44	���ȁE�R�n�S�C�E��C�E�S�b�D
		0123 4445 5566 6777
		0=���֌W�H,1=�S�b�D,2=�R�n�S�C,3=��C
		4,5,6,7=���R,�S�C,�R�n,���y�̕��ȁAMAX5
	45	aabbbccc a-�Ɨ� b-�E�� c-����
	46	1234aaa5 1=� 2-�⍦ 3 ���� 4-�s�� 5�Ɨ��̃r�b�g�̑���
		a-���� 
*/
/*
	�y�����z:
	0 ����			 217 �^�c�K���E���@�䕔���e�E���Ë`�v�E�E�ґS��
	1 ��V������	 152 �O�c���ƁE���q���G�E���ԏ@�΁E�������
	2 �e�\			 119 �ēc���ƁE���������M�E���ˑ��E���X�؏����Y
	3 ���M			 30 �㐙�����E����`���E�����`���E�������
	4 ���ӋC		 180 �ɒB���@�E�O�D���c�E��؏d�G�E�R�䐳��
	5 �Ќ�			 143 �D�c�M���E����ƍN�E���c�M���E�㐙���M
	6 �`��			 145 �L�b�G�g�E�֓����O�E���i�v�G�E�����`��
	7 ���			 314 �{�������E�g�쌳�t�E�R�����V���E�j���P�S��
*/

/*
	�y�����̎v�l�A���S���Y���z:
	0�c�����ƌĂ΂ꂽ�l���B�L�������ɑ����B�M���G�g�ƍN�ق��A�֓����O�⏼�i�v�G���B
	�����I�ȃo�����X�̗ǂ��^�C�v�����Acom�̏ꍇ���͂΂��葝�₵�A���܂�푈���Ȃ��B
	1�c�ҏ��ɑ����B�ēc���Ƃ�`��i�Ƃ�암������B
	2�c�퓬�ɋ��������������B�����ȂǁB
	3�c�퓬�����B���쎁�^��B�����D���H
	4�c�����]�ᓙ�A�V��E���l���̕����l�n�����B�����D���H
	5�c�E�ҕ�����A�v���e���E���n�@���`�ȂǁB�����D���B
	6�c�ڗ����Ȃ��U�R�����B���\�^�C�v�H
	7�c�I���W�i���P�B���i�͕s���B
	255�c�����_���P�B���i�͕s���B
*/

struct �������^
{
	WORD �O�̕����y�����ԍ��z;	/// <summary>���܂�g�����Ƃ͂Ȃ�</summary>
	WORD ���̕����y�����ԍ��z;	/// <summary>�Ƃ��Ɏg�����Ƃ͂Ȃ�</summary>
	WORD _����`1;				/// <summary>must 0xFFFF</summary>
	byte �ő吭��;				/// <summary>����</summary>
	byte �ő���;				/// <summary>���</summary>
	byte �ő�q��;				/// <summary>�q��</summary>
	WORD �����n���l;			/// <summary>���n</summary>
	WORD �퓬�n���l;			/// <summary>��n</summary>
	WORD �q�d�n���l;			/// <summary>�q�n</summary>
	char ����;					/// <summary>����</summary>
	char ��];					/// <summary>��]</summary>
	char ����;					/// <summary>����</summary>
	WORD �M��;					/// <summary>�M��</summary>
	byte ��������;				/// <summary>���ؔԍ� 0xFF�͖���</summary>
	WORD �����喼�y�喼�ԍ��z;	/// <summary>�喼</summary>
	WORD �����R�c�y�R�c�ԍ��z;	/// <summary>�R�c</summary>
	WORD ��������y��ԍ��z;	/// <summary>����</summary>
	WORD ������喼�y�喼�ԍ��z;/// <summary>������ 0xFFFF�͓������Ă��Ȃ�</summary>
	byte ����;					/// <summary>����</summary>
	byte �P��;					/// <summary>�P��</summary>
	byte �m�C;					/// <summary>����</summary>
	byte ����;					/// <summary>�u����::���y�`����::�R�n�S�C�v�ɑΉ�����B</summary>
	byte �d���N��;				/// <summary>�d���N��</summary>
	byte _��;					/// <summary><para>���̒l�͒��ڗ��p�����A�P�֘A�┺���֘A�̊֐��𗘗p���邱�ƁB</para><para>���̔ԍ���255�Ȃ�Ȃ͂��Ȃ��B</para><para>255�ȊO�̎�(�Ⴆ��3)�́A���̔ԍ���500�������y�����ԍ��z(�Ⴆ��503)�̏������ȂƂ�������)�B</para><para>�����ĊY���̕���(�ȕP����)��_�Ȃ�����3�̒l�ɂȂ��Ă��邱�ƁB</para></summary>
	byte ���N;					/// <summary>���N�B�l�Ƃ��ẮA����̒l-1454(�V�ċL��N)</summary>
	WORD �e��ԍ�;				/// <summary><para>�e��NO�B�Z�[�u�G�f�B�^��V�i���I�G�f�B�^�̕����̢��ԍ���ƈ�v����B</para><para>�ukao_24bit�v��u�����ꗗ.xls�v�̔ԍ��Ƃ͂P�����(�P�傫���ԍ�)�Ȃ̂Œ��ӁB</para></summary>
	byte �v�l;					/// <summary>�v�l�A���S���Y�� �u�v�l::�����`�v�l::���̑��v�ɑΉ�����B</summary>
	byte �`��:4;				/// <summary>�`��</summary>
	byte ����:4;				/// <summary>���� (0-15)</summary>
	byte �����K��:2;			/// <summary>c-���K �u�����K��::�b�`�����K��::�`�v�ɑΉ�����B</summary>
	byte �퓬�K�� : 2;			/// <summary>b-��K �u�퓬�K��::�b�`�퓬�K��::�`�v�ɑΉ�����B</summary>
	byte �q�d�K�� : 2;			/// <summary>a-�q�K �u�q�d�K��::�b�`�q�d�K��::�`�v�ɑΉ�����B</summary>
	byte _����`2:2;			//

	byte �Z�\�ꊅ:1;			/// <summary>�Z�\�E�ꊅ</summary>
	byte �Z�\�ÎE:1;			/// <summary>�Z�\�E�ÎE</summary>
	byte �Z�\���o:1;			/// <summary>�Z�\�E���o</summary>
	byte �Z�\����:1;			/// <summary>�Z�\�E����</summary>
	byte �Z�\����:1;			/// <summary>�Z�\�E����</summary>
	byte �Z�\�ِ�:1;			/// <summary>�Z�\�E�ِ�</summary>
	byte �Z�\�ē�:1;			/// <summary>�Z�\�E�ē�</summary>
	byte �Z�\����:1;			/// <summary>�Z�\�E����</summary>
	byte �E��;					/// <summary>�u�E��::�����`�E��::�����v�ɑΉ�����B</summary>

	byte ���y�K��:3;			/// <summary>���y�K�� �u���y�K��::�d�`���y�K��::�r�v�ɑΉ�����B</summary>
	byte �R�n�K��:3;			/// <summary>�R�n�K�� �u�R�n�K��::�d�`�R�n�K��::�r�v�ɑΉ�����B</summary>
	byte _�S�C�K��_hi:2;		/// <summary>�S�C�K���͂����ł͎擾�E�ݒ肪�o���Ȃ��BGet_�S�C�K���ESet_�S�C�K���𗘗p���邱�ƁB�S�C�K����ʃr�b�g</summary>
	byte _�S�C�K��_lo:1;		/// <summary>�S�C�K���͂����ł͎擾�E�ݒ肪�o���Ȃ��BGet_�S�C�K���ESet_�S�C�K���𗘗p���邱�ƁB�S�C�K�����ʃr�b�g</summary>
	byte ���R�K��:3;			/// <summary>���R�K�� �u���R�K��::�d�`���R�K��::�r�v�ɑΉ�����B</summary>

	byte ��C:1;				/// <summary>��C</summary>
	byte �R�n�S�C:1;			/// <summary>�R�n�S�C</summary>
	byte �S�b�D:1;				/// <summary>�S�b�D</summary>
	byte _����`3:1;			// 0

	byte ����:3;				/// <summary>���� 0-7�̒l</summary>
	byte �E��:3;				/// <summary>�E�� 0-7�̒l</summary>
	byte _�Ɨ�_hi:2;			/// <summary>�Ɨ��l�͂����ł͎擾�E�ݒ肪�o���Ȃ��BGet_�Ɨ��ESet_�Ɨ��𗘗p���邱�ƁB�Ɨ���ʃr�b�g</summary>
	byte _�Ɨ�_lo:1;			/// <summary>�Ɨ��l�͂����ł͎擾�E�ݒ肪�o���Ȃ��BGet_�Ɨ��ESet_�Ɨ��𗘗p���邱�ƁB�Ɨ����ʃr�b�g</summary>
	byte ����:3;				/// <summary>���� �u����::�����`����::��ʁv�ɑΉ�����B</summary>
	byte �s����:1;				/// <summary>�s����</summary>
	byte �������:1;			/// <summary>������ԁB������́A�u������喼�y�喼�ԍ��z�v�ɓ����Ă���B</summary>
	byte �⍦���:1;			/// <summary>�⍦���</summary>
	byte ���:1;				/// <summary>���</summary>
};




namespace �֐� {

	/// <summary>
	/// �Ώۂ̕����̓S�C�̓K���l���擾����B
	/// <para>�Ԃ�l�F<see cref="�S�C�K��::�d"/>�`<see cref="�S�C�K��::�r"/></para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�S�C�K��::�d�`�S�C�K��::�r</returns>
	int  Get_�S�C�K��(int �����ԍ��y�z��p�z);


	/// <summary>
	/// �Ώۂ̕����̓S�C�̓K���l��ݒ肷��B
	/// <para>�S�C�K���l�F<see cref="�|�K��::�d"/>�`<see cref="�|�K��::�r"/></para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <param name="�S�C�K���l">�ݒ肷��S�C�̓K���l�B�S�C�K��::�d�`�S�C�K��::�r</param>
	void Set_�S�C�K��(int �����ԍ��y�z��p�z, int �S�C�K���l);


	/// <summary>
	/// �Ώۂ̕����̋|�̓K���l���擾����B
	/// <para>�Ԃ�l�F<see cref="�|�K��::�d"/>�`<see cref="�|�K��::�r"/></para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�|�K��::�d�`�|�K��::�r</returns>
	int  Get_�|�K��(int �����ԍ��y�z��p�z);


	/// <summary>
	/// �Ώۂ̕����̋|�̓K���l��ݒ肷��B
	/// <para>�|�K���l�F<see cref="�|�K��::�d"/>�`<see cref="�|�K��::�r"/></para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <param name="�|�K���l">�ݒ肷��|�̓K���l�B�|�K��::�d�`�|�K��::�r</param>
	void Set_�|�K��(int �����ԍ��y�z��p�z, int �|�K���l);


	/// <summary>
	/// �Ώۂ̕����̑��̓K���l���擾����B
	/// <para>�Ԃ�l�F<see cref="���K��::�d"/>�`<see cref="���K��::�r"/></para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>���K��::�d�`���K��::�r</returns>
	int  Get_���K��( int �����ԍ��y�z��p�z);


	/// <summary>
	/// �Ώۂ̕����̑��̓K���l��ݒ肷��B
	/// <para>���K���l�F<see cref="���K��::�d"/>�`<see cref="���K��::�r"/></para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <param name="���K���l">�ݒ肷�鑄�̓K���l�B���K��::�d�`���K��::�r</param>
	void Set_���K��( int �����ԍ��y�z��p�z, int ���K���l );


	/// <summary>
	/// �Ώۂ̕����̓Ɨ��l���擾����B
	/// <para>�Ԃ�l�F0�`7�͈̔͂̒l</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>0�`7�͈̔͂̒l</returns>
	int Get_�Ɨ�(int �����ԍ��y�z��p�z);


	/// <summary>
	/// �Ώۂ̕����̓Ɨ��l��ݒ肷��B
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <param name="�Ɨ��l">0�`7�͈̔͂Œl���w�肷��B</param>
	void Set_�Ɨ�( int �����ԍ��y�z��p�z, int �Ɨ��l );


	/// <summary>
	/// �Ώۂ̕����̌��݂̐����l���擾����B(110 �x�[�X ���Z)
	/// <para>�V�ċL�ŉ�ʏ�ŕ\�������l�́A���̒l���Q�{�������́B</para>
	/// <para>�Ԃ�l�F���݂̐����̒l�B(110 �x�[�X ���Z)</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ԃ�l�F���݂̐����̒l�B(110 �x�[�X ���Z)</returns>
	int Get_�����l(int �����ԍ��y�z��p�z);


	/// <summary>
	/// �Ώۂ̕����̌��݂̐퓬�l���擾����B(110 �x�[�X ���Z)
	/// <para>�V�ċL�ŉ�ʏ�ŕ\�������l�́A���̒l���Q�{�������́B</para>
	/// <para>�Ԃ�l�F���݂̐퓬�̒l�B(110 �x�[�X ���Z)</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ԃ�l�F���݂̐퓬�̒l�B(110 �x�[�X ���Z)</returns>
	int Get_�퓬�l(int �����ԍ��y�z��p�z);


	/// <summary>
	/// �Ώۂ̕����̌��݂̒q�d�l���擾����B(110 �x�[�X ���Z)
	/// <para>�V�ċL�ŉ�ʏ�ŕ\�������l�́A���̒l���Q�{�������́B</para>
	/// <para>�Ԃ�l�F���݂̒q�d�̒l�B(110 �x�[�X ���Z)</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ԃ�l�F���݂̒q�d�̒l�B(110 �x�[�X ���Z)</returns>
	int Get_�q�d�l( int �����ԍ��y�z��p�z);


	/// <summary>
	/// �ƕ�ɂ��グ����`�����A�Ώە��������̐����ő�l���擾����B(110 �x�[�X ���Z)
	/// <para>�V�ċL�ŉ�ʏ�ŕ\�������l�́A���̒l���Q�{�������́B</para>
	/// <para>�Ԃ�l�F���������̐����̍ő�l�B(110 �x�[�X ���Z)</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ԃ�l�F���������̐����̍ő�l�B(110 �x�[�X ���Z)</returns>
	int Get_���ő吭��(int �����ԍ��y�z��p�z);


	/// <summary>
	/// �ƕ�ɂ��グ����`�����A�Ώە��������̐퓬�ő�l���擾����B(110 �x�[�X ���Z)
	/// <para>�V�ċL�ŉ�ʏ�ŕ\�������l�́A���̒l���Q�{�������́B</para>
	/// <para>�Ԃ�l�F���������̐퓬�̍ő�l�B(110 �x�[�X ���Z)</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ԃ�l�F���������̐퓬�̍ő�l�B(110 �x�[�X ���Z)</returns>
	int Get_���ő���(int �����ԍ��y�z��p�z);


	/// <summary>
	/// �ƕ�ɂ��グ����`�����A�Ώە��������̒q�d�ő�l���擾����B(110 �x�[�X ���Z)
	/// <para>�V�ċL�ŉ�ʏ�ŕ\�������l�́A���̒l���Q�{�������́B</para>
	/// <para>�Ԃ�l�F���������̒q�d�̍ő�l�B(110 �x�[�X ���Z)</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ԃ�l�F���������̒q�d�̍ő�l�B(110 �x�[�X ���Z)</returns>
	int Get_���ő�q��(int �����ԍ��y�z��p�z);


	/// <summary>
	/// �ƕ�ɂ��グ����`�����A�Ώە��������̖�]�l���擾����B
	/// <para>�Ԃ�l�F���������̖�]�l�B</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ԃ�l�F���������̖�]�l�B</returns>
	int Get_����](int �����ԍ��y�z��p�z);


	/// <summary>
	/// ���ʂɂ��グ����`�����A�Ώە��������̖��͒l���擾����B
	/// <para>�Ԃ�l�F���������̖��͒l�B</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ԃ�l�F���������̖��͒l�B</returns>
	int Get_������(int �����ԍ��y�z��p�z);


	/// <summary>
	/// �Ώۂ̕����́u���݂̏󋵂ł̕Ґ��\�ȍő啺���v���擾����B
	/// <para>�Ԃ�l�F�Ώۂ̕����̌��݂̏󋵂ł̕Ґ��\�ȍő啺��</para>
	/// <para>TSMod�͐ݒ�őΏە��������݂̐g���E��E�E���ʂ����Ɂu�ő�̕����v���ω����܂��B</para>
	/// <para>���̒l���擾���邱�Ƃ��o���܂��B</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ԃ�l�F�Ώۂ̕����̌��݂̏󋵂ł̕Ґ��\�ȍő啺��</returns>
	int Get_�����ő啺��(int �����ԍ��y�z��p�z);


	/// <summary>
	/// �����̢��ԍ���ɑΉ�����w�����́u�z��p�v�̔ԍ��x���擾����B
	/// <para>�Ԃ�l�F�����́u�z��p�v�̔ԍ�</para>
	/// <para>�Ώۂ̕������A���̏u�ԓV�ċL�ɓo�ꂵ�Ă��Ȃ��ꍇ�́A<b>�0xFFFF�</b>���Ԃ��Ă���̂Œ���!!</para>
	/// </summary>
	/// <param name="��ԍ�">�ΏۂƂȂ镐���̊�ԍ�</param>
	/// <returns>�Ԃ�l�F�����́u�z��p�v�̔ԍ�</returns>
	WORD Get_�����ԍ��y�z��p�z(int ��ԍ�);


	/// <summary>
	/// �����̢����(=�t���l�[��)��ɑΉ�����w�����́u�z��p�v�̔ԍ��x���擾����B
	/// <para>�Ԃ�l�F�����́u�z��p�v�̔ԍ�</para>
	/// <para>�Ώۂ̕������A���̏u�ԓV�ċL�ɓo�ꂵ�Ă��Ȃ��ꍇ�́A<b>�0xFFFF�</b>���Ԃ��Ă���̂Œ���!!</para>
	/// </summary>
	/// <param name="��������">�ΏۂƂȂ镐���̊�ԍ�</param>
	/// <returns>�Ԃ�l�F�����́u�z��p�v�̔ԍ�</returns>
	WORD Get_�����ԍ��y�z��p�z(string ��������);


	/// <summary>
	/// �Ώۂ̕����̔N����擾����B
	/// <para>�Ԃ�l�F�Ώۂ̕����̔N��</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ԃ�l�F�Ώۂ̕����̔N��</returns>
	int Get_�����N��(int �����ԍ��y�z��p�z);


	/// <summary>
	/// �Ώۂ̕����̔N���ݒ肷��B
	/// <para>�����N��͉��΂ł����R�ɐݒ�o����킯�ł͂Ȃ��A</para>
	/// <para>�v�Z���ʂƂ��āA�u1455�N���܂��葁�����܂ꂽ���Ɓv�ɂȂ�N��͐ݒ�ł��Ȃ�</para>
	/// <para>�v�Z���ʂƂ��āA�u1708�N���܂���x�����܂ꂽ���Ɓv�ɂȂ�N����ݒ�ł��Ȃ�</para>
	/// <para>�Ԃ�l�F�N��ݒ�ɐ�������ΐ^�E���s����΋U</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <param name="�N��">�V���ȔN��</param>
	/// <returns>�Ԃ�l�F�N��ݒ�ɐ�������ΐ^�E���s����΋U</returns>
	bool Set_�����N��(int �����ԍ��y�z��p�z, int �N��);
}



namespace �֐� {

	/// <summary>
	/// �Ώۂ̕����̉�ӌ����擾����
	/// <para>�Ԃ�l�F�Ώۂ̕����̉�ӌ�(�̎��)</para>
	/// <para><see cref="��ӌ�::�Ê�"/>�`<see cref="��ӌ�::����U��"/></para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ԃ�l�F��ӌ�::�Êρ`��ӌ�::����U��</returns>
	int Get_��ӌ�(int �����ԍ��y�z��p�z);


	/// <summary>
	/// �Ώۂ̕����ɉ�ӌ���ݒ肷��
	/// <para>�Ԃ�l�F�Ώۂ̕����̉�ӌ�(�̎��)</para>
	/// <para><see cref="��ӌ�::�Ê�"/>�`<see cref="��ӌ�::����U��"/></para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <param name="��ӌ�"><see cref="��ӌ�::�Ê�"/>�`<see cref="��ӌ�::����U��"/>��ݒ肷��B</param>
	/// <remarks>�c�O�Ȃ���l��ݒ肷�邾����AI�I�ɁA���̍s�����d�v�Ƃ����w�j���������킯�ł͂Ȃ����߁A����قǈӖ��̂�����̂ł͂Ȃ��B</remarks>
	void Set_��ӌ�(int �����ԍ��y�z��p�z, int ��ӌ�);
}


namespace �֐� {

	/// <summary>
	/// �����̍����𓾂�B �ŏ�0(�����ō�) �ő�8(�����ň�)
	/// <para>�Ԃ�l�F�ŏ���0(=�����ō�)�`�ő傪8(=�����ň�)</para>
	/// </summary>
	/// <param name="�����l�`">�P�ڂ̑����l</param>
	/// <param name="�����l�a">�Q�ڂ̑����l</param>
	/// <returns>�Ԃ�l�F�ŏ���0(=�����ō�)�`�ő傪8(=�����ň�)</returns>
	int Get_������(int �����l�`, int �����l�a);


	/// <summary>
	/// �Ώۂ̂Q�l�̕����̑����̈Ⴂ�𓾂�B�ŏ�0(�����ō�) �ő�8(�����ň�)
	/// <para>�Ԃ�l�F�ŏ���0(=�����ō�)�`�ő傪8(=�����ň�)</para>
	/// </summary>
	/// <param name="�����`�ԍ��y�z��p�z">�P�l�ڂ̕����́u�z��p�v�̔ԍ�</param>
	/// <param name="�����a�ԍ��y�z��p�z">�Q�ڂ̕����́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ԃ�l�F�ŏ���0(=�����ō�)�`�ő傪8(=�����ň�)</returns>
	int Get_����������(int �����`�ԍ��y�z��p�z, int �����a�ԍ��y�z��p�z);
}




/*
	�������O�e�[�u��(18*500�ƕP���p��18*32)

	[18�o�C�g]
	0-6		����
	7-13	���O
	14-15	�����i���o�[(����12bit�͗�`�H)
	16	���4�r�b�g�͐g��(b0000=�B��,b0001=�喼
						�@b0010=2=�h�V,b0011=3=�ƘV
						�@b0100=4=����,b0101=5=���叫
						�@b0110=6=���y��)
		����4�r�b�g	0�喼,1�R��,2����,3�B��,4�Q�l,5�P,6�ҋ@,7���S
				
	17	�� 0-�j 1-��
*/
struct �����ːЏ��^
{
	char _����[7];	//�����BGet_����(int)��Set_����(int, string)�Ŏ擾�E�ݒ肷�邱�ƁB
	char _���O[7];	//���O�BGet_���O(int)��Set_���O(int, string)�Ŏ擾�E�ݒ肷�邱�ƁB
	WORD ��ԍ�;	/// <summary>��`�ԍ��ƈ�v�B�����i���o�[(����12bit�͗�`�H)�B<para>�Z�[�u�G�f�B�^��V�i���I�G�f�B�^�̕����̢��ԍ���ƈ�v����B</para><para>�ukao_24bit�v��u�����ꗗ.xls�v�̔ԍ��Ƃ͂P�����(�����͂P�傫���ԍ�)�Ȃ̂Œ��ӁB</para></summary>
	byte ���:4;	/// <summary>�u���::�喼�`���::���S�v�ɑΉ�����B <para>��Ԃ̒l��P���ɕύX����ƁA�o�O�ɂȂ�̂Œ��ӁB</para><para>Set_������ԁs***�t��ʂ��āA�����̏�Ԃ͕ύX�\�ł���B</para></summary>
	byte �g��:4;	/// <summary>�u�g��::�B���`�g��::���y���v�ɑΉ�����B<para>�g���̒l��P���ɕύX����ƁA�o�O�ɂȂ�̂Œ��ӁB</para><para>���̐g�����u�g��::���y���`�g��::�h�V�v�ł���΁A���͈̔͂ŕύX����̂͑��v�ł���B</para></summary>

	byte ����:1;	//�u����::�j�`����::���v�ɑΉ�����B
	byte �ދp:1;	//1:���őދp�����B0:�ʏ�ʂ�
	byte �펀:1;	//1:���Ő펀�����B0:�ʏ�ʂ�
	byte _undef:5;
};



// --------------�����́A�u��Ԗ��^�� �J�X�^��::On_��Ԗ��\�����O(...)�v�̃��\�b�h�̂��߂ɂ���B
using ��Ԗ��^�� = char*;
using _��Ԗ��^ = char[7]; // �S�p�R����
/// <summary>
/// �u��Ԗ��^�� �J�X�^��::On_��Ԗ��\�����O(int �����ԍ�, int ���) �v���\�b�h�̕Ԃ�l�̌^
/// </summary>
#define ��Ԗ��^   static _��Ԗ��^

// --------------�����́A�u�g�����^�� �J�X�^��::On_�g�����\�����O(...)�v�̃��\�b�h�̂��߂ɂ���B
using �g�����^�� = char*;
using _�g�����^ = char[7]; // �S�p�R����
/// <summary>
/// �u�g�����^�� �J�X�^��::On_�g�����\�����O(int �����ԍ�, int �g��) �v���\�b�h�̕Ԃ�l�̌^
/// </summary>
#define �g�����^   static _�g�����^



/// <summary>
/// �u�퍑������`�^�� �J�X�^��::On_�퍑������`�v����(int �����ԍ�, int ��ԍ�) �v���\�b�h�̕Ԃ�l�̌^
/// </summary>
struct �퍑������`�^ {

public:
	string _���x��;
	string _�ڍ�;

public:
	/// <summary>
	/// �퍑������`��ݒ肷��B
	/// </summary>
	/// <param name="���x��">�퍑������`���ɕ\�������A���O�Ɛ��N�B36�o�C�g�܂ŁB�S�p����18�����B</param>
	/// <param name="�ڍ�">�퍑������`���ɕ\�������A�ڍׂȕ�����`�B�S�p����18�����~�S�s�B</param>
	inline �퍑������`�^(string ���x��, string �ڍ�) {
		_���x�� = ���x��;
		_�ڍ� = �ڍ�;
	};

	// NULL���^�[���ɑΉ����邽�߁B
	inline �퍑������`�^(int iDefault) {}
};
#define �퍑������`�^��	�퍑������`�^


namespace �֐� {

	/// <summary>
	/// �Ώۂ̕����̕����̖������擾����B
	/// <para>�Ԃ�l�F�Ώۂ̕����̖����̕�����B�ő�őS�p�R�����B(6�o�C�g)</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ώۂ̕����̖����̕�����B�ő�őS�p�R�����B(6�o�C�g)</returns>
	string Get_����( int �����ԍ��y�z��p�z);


	/// <summary>
	/// �Ώۂ̕����̕����̖�����ݒ肷��B
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <param name="����">�ݒ肷�閼���̕�����B</param>
	void Set_����(int �����ԍ��y�z��p�z, string ����);


	/// <summary>
	/// �Ώۂ̕����̕����̖��O���擾����B
	/// <para>�Ԃ�l�F�Ώۂ̕����̖��O�̕�����B�ő�őS�p�R�����B(6�o�C�g)</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�Ώۂ̕����̖��O�̕�����B�ő�őS�p�R�����B(6�o�C�g)</returns>
	string Get_���O(int �����ԍ��y�z��p�z);


	/// <summary>
	/// �Ώۂ̕����̕����̖��O��ݒ肷��B
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <param name="���O">�ݒ肷�閼�O�̕�����B</param>
	void Set_���O(int �����ԍ��y�z��p�z, string ���O);
}



namespace �֐� {

	/// <summary>
	/// �퍑����ɋ������Ȗ�����K���Ƀ����_���œ���B
	/// <para>�Ԃ�l�F�����̕�����B�ő�őS�p�R�����B(6�o�C�g)</para>
	/// </summary>
	string Get_�����_������();


	/// <summary>
	/// �퍑����ɋ������Ȗ��O��K���Ƀ����_���œ���B
	/// <para>�Ԃ�l�F���O�̕�����B�ő�őS�p�R�����B(6�o�C�g)</para>
	/// </summary>
	string Get_�����_�����O();


	/// <summary>
	/// �V�ċL�Ō��X�p�ӂ���Ă�100��ނ̉��z�̕P�̖��O���烉���_���łP�𓾂�B
	/// <para>�Ԃ�l�F���O�̕�����B�ő�őS�p�R�����B(6�o�C�g)</para>
	/// </summary>
	string Get_�����_���P���O();
}


namespace �֐� {

	/// <summary>
	/// �u���::�����v�̕������u���::�Q�l�v�ɂ���B
	/// <para>�喼��R�c���ȊO�̈�ʂ̕������A�Q�l�Ƃ���B</para>
	/// <para>�Ԃ�l�F����������true�A���s������false</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	bool Set_������ԁs�������Q�l�t(int �����ԍ��y�z��p�z);


	/// <summary>
	/// �u���::�Q�l�v�̕��������u���::�����v�ɂ���B
	/// <para>�Q�l�������̈ʒu�̂܂܁A�������x�z���Ă���喼(�R�c��)�̔z���ƂȂ�B</para>
	/// <para>�󔒏�ɂ���Q�l�́A���̏�̈ʒu�ł͌����ɂȂ�Ȃ��B</para>
	/// <para>�ǂ̑喼�̟����ɑ�����ׂ����s���ł��邽�߂ł���B</para>
	/// <para>�Ԃ�l�F�������Ɏ��s�����ꍇ��false���Ԃ�A����������true�B</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	bool Set_������ԁs�Q�l�������t( int �����ԍ��y�z��p�z);


	/// <summary>
	/// �����̎��S�������s���B
	/// <para>��A�̂t�h�𔺂����֘A�������s���邽�߁A�g�p�\�ȃ^�C�~���O��������֐��ł���B���ӂ�v����</para>
	/// <para>�Ɛl���������Ȃ��Ȃ�΁A�Ɛl�������w�肵�Ȃ��B(�����Ŏ��񂾂Ƃ����`�ƂȂ�)</para>
	/// <para>�Ԃ�l�F�w�蕐�����s���ł����false�A����ȊO��true���Ԃ�B</para>
	/// </summary>
	/// <param name="���S�����ԍ��y�z��p�z">���S�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <param name="�Ɛl�����ԍ��y�z��p�z">�Ɛl�ΏۂƂȂ镐���́u�z��p�v�̔ԍ��B�ȗ��\�B</param>
	bool Set_������ԁs�����S�t(int ���S�����ԍ��y�z��p�z, int �Ɛl�����ԍ��y�z��p�z = -1);


	/// <summary>
	/// ����́u�����v�̕������A���̏�̏��ɂ���B
	/// <para>��傾�������̂͂����̌����ƂȂ�B</para>
	/// <para>�Ԃ�l�F���������true�A���s�����false</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>���������true�A���s�����false</returns>
	bool Set_���(int �����ԍ��y�z��p�z);


	/// <summary>
	/// �Q�l��a��������B
	/// <para>�e��\�́E�E�ƁE�N������̊����Ɋ�Â��Ď����v�Z�����B</para>
	/// <para>��́u�\�́E�E�ƁE�N��v�Ȃǂ̊�Â��āA�u�ėp��̒�����ӂ��킵�����̂��I���v�����B</para>
	/// <para>�Ԃ�l�F�Y���̕������a������ۂɊ��蓖�Ă�ꂽ�����́u�z��p�v�̔ԍ�
	/// <para>�Q�l�쐬�Ɏ��s�����ꍇ�ɂ́A-1���Ԃ��Ă���B</para>
	/// </para>
	/// </summary>
	/// <param name="��ԍ�">��ԍ�(=��`�ԍ�)���w�肷��΁A���̊�ԍ�(=��`)�ƂȂ�B
	/// <para> (��`�ԍ������˂�̂ŁA�����灕��`�������l���������肵�Ȃ��悤�ɗv����)</para>
	/// <para>��ԍ��w����ȗ������ꍇ�A�u�\�́E�E�ƁE�N��v�Ȃǂ̊�Â��āA�u�ėp��̒�����ӂ��킵�����̂��I���v�����B</para>
	/// </param>
	/// <returns>�Y���̕������a������ۂɊ��蓖�Ă�ꂽ�����́u�z��p�v�̔ԍ�
	/// <para>�Q�l�쐬�Ɏ��s�����ꍇ�ɂ́A-1���Ԃ��Ă���B</para>
	/// </returns>
	int Set_�����a��(int ��ԍ� = -1);


	/// <summary>
	/// �u�Q�l�ƌ����̕����v��ʂ̏ꏊ�ɓ]�ڂ����邱�Ƃ��o����B
	/// <para>���͂𒴂��Ăǂ��Ɉړ����Ă��悢�B</para>
	/// <para>�A���A���x�z��(������̐��͉��ɂ������Ȃ���)�ɓ]�ڂ���ƁA�Q�l��������Ԃœ]�ڂ��邱�ƂƂȂ�B</para>
	/// <para>�Ԃ�l�F���������true�A���s�����false</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <param name="�]�����ԍ��y�z��p�z">�]����ƂȂ��́u�z��p�v�̔ԍ�</param>
	/// <returns>���������true�A���s�����false</returns>
	bool Set_�����]��(int �����ԍ��y�z��p�z, int �]�����ԍ��y�z��p�z);
}


namespace �֐� {

	/// <summary>
	/// �w�蕐���́u�����̕����ԍ��y�z��p�z�v����B
	/// <para>�Ԃ�l�F�����ƂȂ镐����Ȃ́u�z��p�v�̔ԍ�</para>
	/// <para>�v�������w�肷��΁A�ȕ����̕����ԍ��y�z��p�z���Ԃ��Ă���B</para>
	/// <para>�ȕ������w�肷��΁A�v�����̕����ԍ��y�z��p�z���Ԃ��Ă���B</para>
	/// <para> ���������Ȃ��ꍇ�ɂ́A0xFFFF���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�����ƂȂ镐����Ȃ́u�z��p�v�̔ԍ�
	/// <para>�v�������w�肷��΁A�ȕ����̕����ԍ��y�z��p�z���Ԃ��Ă���B</para>
	/// <para>�ȕ������w�肷��΁A�v�����̕����ԍ��y�z��p�z���Ԃ��Ă���B</para>
	/// <para> ���������Ȃ��ꍇ�ɂ́A0xFFFF���Ԃ��Ă���B</para>
	/// </returns>
	int Get_���������ԍ��y�z��p�z(int �����ԍ��y�z��p�z);


	/// <summary>
	/// �P(���̕����̍Ȋ܂�)���A�w��̕����ƌ���������A�����֌W���͈�ؑ��삳��Ȃ��B
	/// <para>�Ԃ�l�F���������true�A���s�����false</para>
	/// </summary>
	/// <param name="�P�����ԍ��y�z��p�z">����������P���̕����̕����ԍ��u�z��p�v</param>
	/// <param name="�v�����ԍ��y�z��p�z">����������v���̕����̕����ԍ��u�z��p�v</param>
	/// <param name="�V�W�ǓƎ��S����">
	/// <para>�v���ɍȂ������ꍇ�A���̌����ɂ�茳�ȂƂ͗������邱�ƂɂȂ�B</para>
	/// <para>�V�W�ǓƎ��S�����Ƃ́A���̗����ɂ���āA�P���V�W�ǓƂɂȂ��Ă��܂���(�e�Z�퓙��A�����̑喼��������)�ꍇ�A</para>
	/// <para>�N������Q�Əo���Ȃ��l���ƂȂ�A�Q�[�����ŕP�Ƃ��Ă̖������s�\�ł��邽�߁A���S����������Ƃ������́B</para>
	/// </param>
	/// <returns>���������true�A���s�����false</returns>
	bool Set_�P����( int �P�����ԍ��y�z��p�z, int �v�����ԍ��y�z��p�z, BOOL �V�W�ǓƎ��S����=TRUE );


	/// <summary>
	///�w��̕P�𗣍�������B�����������āA�e����Z�팳�Ɉړ�����B
	/// <para>�Ԃ�l�F���������true�A���s�����false</para>
	/// </summary>
	/// <param name="�P�����ԍ��y�z��p�z">����������P���̕����̕����ԍ��u�z��p�v</param>
	/// <param name="�V�W�ǓƎ��S����">
	/// <para>�V�W�ǓƎ��S�����Ƃ́A���̗����ɂ���āA�P���V�W�ǓƂɂȂ��Ă��܂���(�e�Z�퓙��A�����̑喼��������)�ꍇ�A</para>
	/// <para>�N������Q�Əo���Ȃ��l���ƂȂ�A�Q�[�����ŕP�Ƃ��Ă̖������s�\�ł��邽�߁A���S����������Ƃ������́B</para>
	/// </param>
	/// <returns>���������true�A���s�����false</returns>
	bool Set_�P����( int �P�����ԍ��y�z��p�z, BOOL �V�W�ǓƎ��S����=TRUE );
}

namespace �֐� {
	// �ȉ��́u�`�����v�Ɓu�a�����v�Ƃ́u���ʂȐl�Ԋ֌W�̐^�U���ȒP�ɔ���v���邽�߂̊֐��ƂȂ�B

	/// <summary>
	/// �����͑���̖����ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_�����͑���̖�( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z );

	/// <summary>
	/// �����͑���̑��q���ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_�����͑���̑��q(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z);

	/// <summary>
	/// �����͑���̎q���ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_�����͑���̎q(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z);

	/// <summary>
	/// �����͑���̐e���ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_�����͑���̐e(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z);

	/// <summary>
	/// �����͑���̕����ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_�����͑���̕�(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z);

	/// <summary>
	/// ����͎����̕����ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_����͎����̕�(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z);

	/// <summary>
	/// �����͑���̕ꂩ�ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_�����͑���̕�(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z);

	/// <summary>
	/// ����͎����̕ꂩ�ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_����͎����̕�(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z);

	/// <summary>
	/// �����͑���̒킩�ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_�����͑���̒�(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z);

	/// <summary>
	/// ����͎����̒킩�ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_����͎����̒�(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z);

	/// <summary>
	/// �����͑���̖����ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_�����͑���̖�(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z);

	/// <summary>
	/// ����͎����̖����ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_����͎����̖�(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z);

	/// <summary>
	/// �����͑���̌Z���ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_�����͑���̌Z(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z);

	/// <summary>
	/// ����͎����̌Z���ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_����͎����̌Z(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z);

	/// <summary>
	/// �����͑���̎o���ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_�����͑���̎o(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z);

	/// <summary>
	/// ����͎����̎o���ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_����͎����̎o(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z);

	/// <summary>
	/// �����Ƒ���͌Z�킩�ǂ����̔���B
	/// <para>����=�Z�A����=��A�̏��ň����Ƃ��ēn��</para>
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_�����Ƒ���͌Z��( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z );

	/// <summary>
	/// �����Ƒ���͎o�����ǂ����̔���B
	/// <para>����=�o�A����=���A�̏��ň����Ƃ��ēn��</para>
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_�����Ƒ���͎o��( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z );

	/// <summary>
	/// �����Ƒ���͎o�킩�ǂ����̔���B
	/// <para>����=�o�A����=��A�̏��ň����Ƃ��ēn��</para>
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_�����Ƒ���͎o��( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z );

	/// <summary>
	/// �����Ƒ���͌Z�����ǂ����̔���B
	/// <para>����=�Z�A����=���A�̏��ň����Ƃ��ēn��</para>
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_�����Ƒ���͌Z��( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z );

	/// <summary>
	/// �����͑���̕v���ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_�����͑���̕v(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z);

	/// <summary>
	/// �����͑���̍Ȃ��ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_�����͑���̍�(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z);

	/// <summary>
	/// �����͑���̌������ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_�����͑���̌���(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z);

	/// <summary>
	/// �������喼�ŁA����͂��̉Ɛb�Ƃ����֌W���ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_����͎����̉Ɛb( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z );

	/// <summary>
	/// �������Ɛb�ŁA����͂��̑喼�Ƃ����֌W���ǂ����̔���B
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_����͎����̑喼(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z);

	/// <summary>
	/// �����Ƒ���͓����喼�Ƃ��ǂ����̔���B
	/// <para>�Ɛb�͂������A�喼�{�l�������́u�喼�Ƃɏ������Ă���v�Ƃ݂Ȃ����B</para>
	/// <para>�Ԃ�l�Ftrue��false</para>
	/// </summary>
	/// <param name="���������ԍ��y�z��p�z">�P�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <param name="���蕐���ԍ��y�z��p�z">�Q�l�ڂ̕����ԍ��u�z��p�v</param>
	/// <returns>true��false</returns>
	bool Is_�����Ƒ���͓����喼�Ə���( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z );

}

