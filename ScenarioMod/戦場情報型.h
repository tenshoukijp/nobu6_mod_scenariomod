/*
 * �������^ �y�сA �����ːЏ��^
 */
#pragma once
#pragma pack(1)

#include <windows.h>
#include <vector>

#include "�Q�c�ʒu���^.h"
#include "�R�c�ʒu���^.h"

#include "������.h"

using namespace std;


/// <summary>
/// �u�J�X�^��::On_�푈�J�n�v�̃��\�b�h�p�̃p�����[�^
/// </summary>
struct �푈�J�n�p�����^�^ {
	int ��ԍ�;						// �W�I�̏�ԍ�
	int ������R�c�y�R�c�ԍ��z;		// ������̌R�c�ԍ�
	int ������R�c���y�����ԍ��z;	// ������̌R�c���̕����ԍ�
	int �U�����R�c�y�R�c�ԍ��z;		// �U�߂����̌R�c�ԍ�
	int �U�����R�c���y�����ԍ��z;	// �U�߂����̌R�c���̕����ԍ�
};


/// <summary>
/// �u�J�X�^��::On_�U�����@���莞�s�푈��ʁt�v�̃��\�b�h�p�̃p�����[�^
/// </summary>
struct �U�����@���莞�p�����^�^ {
	int �U�����@�ԍ�;	/// <summary>�u�U�����@::�U���v�`�u�U�����@::�|�v�̂����ꂩ�̒l�Ɣ�r����B</summary>
	int �ړ��O;
};


namespace �֐� {

	/// <summary>
	/// ���ݐi�s���̐푈�Ɋւ���Ă���喼���͂̃��X�g�𓾂�B
	/// <para>(����o�w���Ă��邩�ǂ����͊֌W�Ȃ�)</para>
	/// <para>�Ԃ�l�F�Q�킵�Ă���喼�́A�喼�ԍ��y�z��p�z��ԍ����X�g�^�œ���B</para>
	/// </summary>
	/// <returns>�Q�킵�Ă���喼�́A�喼�ԍ��y�z��p�z��ԍ����X�g�^�œ���B</returns>
	�ԍ����X�g�^ Get_�Q��̑喼�ԍ����X�g�y�z��p�z();

	/// <summary>
	/// ���ݐi�s���̐푈�Ɋւ���Ă���R�c���͂̃��X�g�𓾂�B
	/// <para>(����o�w���Ă��邩�ǂ����͊֌W�Ȃ�)</para>
	/// <para>�Ԃ�l�F�Q�킵�Ă���R�c�́A�R�c�ԍ��y�z��p�z��ԍ����X�g�^�œ���B</para>
	/// </summary>
	/// <returns>�Q�킵�Ă���R�c�́A�R�c�ԍ��y�z��p�z��ԍ����X�g�^�œ���B</returns>
	�ԍ����X�g�^ Get_�Q��̌R�c�ԍ����X�g�y�z��p�z();


	/// <summary>
	/// �Y���̌R�c�̐��ɂ����闧���Ԃ��B
	/// <para>�Ԃ�l�F�u<see cref="�Q�헧��::�s��"/>�v�`�u<see cref="�Q�헧��::�����R"/>�v�̂����ꂩ�̒l���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�R�c�ԍ��y�z��p�z">�ΏۂƂȂ�R�c�́u�z��p�v�̔ԍ�</param>
	/// <returns>�u�Q�헧��::�s���v�`�u�Q�헧��::�����v</returns>
	int Get_�R�c�̎Q�헧��(int �R�c�ԍ��y�z��p�z);

	/// <summary>
	/// �Y���̕����̐��ɂ����闧���Ԃ��B
	/// <para>�Ԃ�l�F�u<see cref="�Q�헧��::�s��"/>�v�`�u<see cref="�Q�헧��::�����R"/>�v�̂����ꂩ�̒l���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�u�Q�헧��::�s���v�`�u�Q�헧��::�����v</returns>
	int Get_�����̎Q�헧��(int �����ԍ��y�z��p�z);


	/// <summary>
	/// ���݂̐푈�ɂ����āA�w��̌R�c�̑�\�҂̕�����Ԃ��B
	/// <para>(����\�҂Ƃ́A�R�c����喼�Ƃ͌���Ȃ��B�喼��R�c�������ɋ��Ȃ��ꍇ�Ȃǂ́A</para>
	/// <para>�@ ���ɂčł����������҂���\�҂Ƃ��ēV�ċL�V�X�e���ɂ��I�΂�Ă���B)</para>
	/// <para>�Ԃ�l�F��\�҂ł��镐���́u�z��p�v�̔ԍ���Ԃ��B</para>
	/// </summary>
	/// <param name="�R�c�ԍ��y�z��p�z">�ΏۂƂȂ�R�c�́u�z��p�v�̔ԍ�</param>
	/// <returns>��\�҂ł��镐���́u�z��p�v�̔ԍ���Ԃ��B</returns>
	int Get_�Q��R�c�̎w����(int �R�c�ԍ��y�z��p�z);
}




namespace �֐� {

	/// <summary>
	/// ���݉�ʂɏo�Ă���́A���
	/// </summary>
	bool Is_��풆();

	/// <summary>
	/// ���݉�ʂɏo�Ă���́A�U���
	/// </summary>
	bool Is_�U��풆();

	/// <summary>
	/// <para>���݉�ʏ�ōU�������Ă����́u�z��p�v�̔ԍ��𓾂�B</para>
	/// <para>�������A�U�������Ă��Ȃ���΁A0xFFFF���Ԃ��Ă���B</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>�@�U�������Ă���ꍇ�A��́u�z��p�v�̔ԍ����Ԃ��Ă���B</para>
	/// <para>�@�U�������Ă��Ȃ���΁A0xFFFF���Ԃ��Ă���B</para>
	/// </summary>
	/// <returns>
	/// <para>�U�������Ă���ꍇ�A��́u�z��p�v�̔ԍ����Ԃ��Ă���B</para>
	/// <para>�U�������Ă��Ȃ���΁A0xFFFF���Ԃ��Ă���B</para>
	/// </returns>
	WORD Get_�U��풆�̏�ԍ�(); // 

	/// <summary>
	/// <para>(���݉�ʂōs���Ă���)�푈�̎c��^�[�����𓾂�</para>
	/// <para>�u�c��^�[���v�Ƃ́A�푈���̉�ʂŌ����Ă���u�c�聛���^�[���v�Əo�Ă��鐔�l�̂��ƁB</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>�@�푈�̎c��^�[�����Ԃ��Ă���B</para>
	/// <para>�@�푈���łȂ��ꍇ�ɂ́A-1���Ԃ��Ă���B</para>
	/// </summary>
	/// <returns>
	/// <para>�푈�̎c��^�[�����Ԃ��Ă���B</para>
	/// <para>�푈���łȂ��ꍇ�ɂ́A-1���Ԃ��Ă���B</para>
	/// </returns>
	int Get_�푈�c��^�[����();

	/// <summary>
	/// <para>(���݉�ʂōs���Ă���)�U���̃^�[�����𓾂�</para>
	/// <para>�u�U���̃^�[�����v�Ƃ́A�U���̉�ʂŌ����Ă���R�́��̐��i�P�`�R�j�̂��ƁB</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>�@�U���̃^�[�������Ԃ��Ă���B�i�P�`�R�j</para>
	/// <para>�@�U���łȂ��ꍇ�ɂ́A-1���Ԃ��Ă���B</para>
	/// </summary>
	/// <returns>
	/// <para>�U���̃^�[�������Ԃ��Ă���B�i�P�`�R�j</para>
	/// <para>�U���łȂ��ꍇ�ɂ́A-1���Ԃ��Ă���B</para>
	/// </returns>
	int Get_�U���^�[����();


	/// <summary>
	/// <para>���݂́u���S��v��ΏۂƂ��ďo�w���Ă��镐���̃��X�g�𓾂�B</para>
	/// <para>���S��Ƃ́A��ʏ�ɕ\������Ă��Ȃ��悤�ȍU���Ȃǂɏo�w���̕������܂܂��B</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>�@�o�w���̕����B�́u�����ԍ��y�z��p�z�v���ԍ����X�g�^�ŕԂ��Ă���B</para>
	/// <para>�@�N���o�w���Ă��Ȃ��ꍇ�A�v�f�����O�̔ԍ����X�g�^���Ԃ��Ă���B</para>
	/// </summary>
	/// <returns>
	/// <para>�o�w���̕����B�́u�����ԍ��y�z��p�z�v���ԍ����X�g�^�ŕԂ��Ă���B</para>
	/// <para>�N���o�w���Ă��Ȃ��ꍇ�A�v�f�����O�̔ԍ����X�g�^���Ԃ��Ă���B</para>
	/// </returns>
	�ԍ����X�g�^ Get_�o�w���̕����ԍ����X�g�y�z��p�z();

	/// <summary>
	/// <para>���ݕ\�����̐퓬�}�b�v�ɏo�w���Ă��镐���ԍ��z��p�̃��X�g�𓾂�B</para>
	/// <para>���ݕ\������Ă���}�b�v�݂̂��ΏۂƂȂ�B(���}�b�v�������͓���̍U���}�b�v�j</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>�@�o�w���̕����B�́u�����ԍ��y�z��p�z�v���ԍ����X�g�^�ŕԂ��Ă���B</para>
	/// <para>�@�N���o�w���Ă��Ȃ��ꍇ�A�v�f�����O�̔ԍ����X�g�^���Ԃ��Ă���B</para>
	/// </summary>
	/// <returns>
	/// <para>�o�w���̕����B�́u�����ԍ��y�z��p�z�v���ԍ����X�g�^�ŕԂ��Ă���B</para>
	/// <para>�N���o�w���Ă��Ȃ��ꍇ�A�v�f�����O�̔ԍ����X�g�^���Ԃ��Ă���B</para>
	/// </returns>
	�ԍ����X�g�^ Get_�o�w���̕����ԍ����X�g�y�z��p�z�s�\�����}�b�v�t();

}


namespace �֐� {


	/// <summary>
	/// ���ɂ����āA�Y���̕������A���ɍs���ς��ǂ����𓾂�B
	/// <para>�Ԃ�l�F�s���ς݂Ȃ�^���A���s���Ȃ�U���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�s���ς݂Ȃ�^���A���s���Ȃ�U���Ԃ��Ă���B</returns>
	bool Is_�����s���ρs�푈��ʁt(int �����ԍ��y�z��p�z);


	/// <summary>
	/// ���ɂ����āA�Y���̕����̍�����Ԃ𓾂�B
	/// <para>�Ԃ�l�F�u�������::�����v�`�u�������::���������v�̒l���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�u�������::�����v�`�u�������::���������v�̒l���Ԃ��Ă���B</returns>
	int Get_�����������(int �����ԍ��y�z��p�z);

	/// <summary>
	/// ���ɂ����āA�Y���̕�����������Ԃ�ύX����B
	/// <para>���̊֐������s���Ă��A�����I�Ȓl��ύX���邾���ŁA��ʏ�̃��j�b�g�̃A�C�R���ɍ�����Ԃ̕ύX���f����Ȃ��B</para>
	/// <para>�u�������j�b�g��ԕ`��X�V�s�푈��ʁt�v�̊֐����Ăяo�����Ƃŉ�ʏ�ɔ��f�����邱�Ƃ��o����B</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <param name="�������">�u�������::�����v�`�u�������::���������v�̂����ꂩ��ݒ肷��B</param>
	/// <returns>�u�������::�����v�`�u�������::���������v�̒l���Ԃ��Ă���B</returns>
	bool Set_�����������(int �����ԍ��y�z��p�z, int �������);


	/// <summary>
	/// ���ɂ����āA�Ώۂ̕����̈ړ��͂̎c�ʒl���擾����B
	/// <para>�Ԃ�l�F�ʏ� 0�`15 �̒��x�̒l</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�ʏ� 0�`15 �̒��x�̒l</returns>
	int Get_�����ړ��͎c��(int �����ԍ��y�z��p�z);

	/// <summary>
	/// ���ɂ����āA�Ώۂ̕����̈ړ��͂̎c�ʒl��ݒ肷��B
	/// <para>�Ԃ�l�F���ɑΏۂ̕��������Ȃ��ꍇ�́A0xFFFF�̒l���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <param name="�ړ��͎c��">�V�ċL�̖{���̎d�l�ɏ]���΁A�ʏ�0�`15���x�̒l��ݒ肷��B���傫�Ȓl��ݒ肷�邱�Ƃ��\�B</param>
	/// <returns>���ɑΏۂ̕��������Ȃ��ꍇ�́A0xFFFF�̒l���Ԃ��Ă���B</returns>
	int Set_�����ړ��͎c��(int �����ԍ��y�z��p�z, int �ړ��͎c��);


	/// <summary>
	/// �Ώۂ̕����̕������A�`���̃��j�b�g�A�C�R���ɔ��f������B
	/// <para>������ύX���������ł́A��ʏ�ɂ��̂��Ƃ��`�B����Ȃ����߁A</para>
	/// <para>���f�������ꍇ�ɂ́A���̊֐����Ăяo���B</para>
	/// <para>���̊֐��Ŏ蓮�ōX�V����B</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	void �������j�b�g�����`��X�V�s�푈��ʁt(int �����ԍ��y�z��p�z);

	/// <summary>
	/// �Ώۂ̕����̑卬���⍬���Ȃǂ̏�Ԃ��A�`���̃��j�b�g�A�C�R���ɔ��f������B
	/// <para>������������Ԃ⒧��������Ԃɐݒ肵�������ł́A���j�b�g�̉摜�A�C�R���͍X�V����Ȃ����߁A</para>
	/// <para>���f�������ꍇ�ɂ́A���̊֐����Ăяo���B</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	void �������j�b�g��ԕ`��X�V�s�푈��ʁt(int �����ԍ��y�z��p�z);
}



//-------------�푈�̃w�b�N�X�ʒu��w�b�N�X���֘A---------------------------------------------------------------

namespace ���w�b�N�X {
	const int ���S�w = 20; ///<summary>���̉�ʂ̒��S�w�̑z��ʒu�B</summary>
	const int ���S�x = 12; ///<summary>���̉�ʂ̒��S�x�̑z��ʒu�B</summary>
}
namespace �U���w�b�N�X {
	const int ���S�w = 9;  ///<summary>�U���̉�ʂ̒��S�w�̑z��ʒu�B</summary>
	const int ���S�x = 8;  ///<summary>�U���̉�ʂ̒��S�w�̑z��ʒu�B</summary>
}


/// <summary>
/// �w�b�N�X�̍��W���n�B
/// ��ʂɑΉ�������ƁA�u�w��  �x���v�̕����Œl���������Ă����B
/// </summary>
struct �w�b�N�X�ʒu�^ : public �Q�c�x�N�g���^ {
	�w�b�N�X�ʒu�^(double �w�ʒu, double �x�ʒu) : �w(�w�ʒu),�x(�x�ʒu) {}
	�w�b�N�X�ʒu�^() : �w(0),�x(0) {}
	double �w; // �w���W
	double �x; // �x���W
};

using �w�b�N�X�ʒu���X�g�^ = vector<�w�b�N�X�ʒu�^>;

/// <summary>
/// �w�b�N�X���W�̃x�N�g���B
/// ��ʂɑΉ�������ƁA�u�w��  �x���v�̕����Œl���������Ă����B
/// </summary>
struct �w�b�N�X�x�N�g���^ : public �Q�c�x�N�g���^ {
	�w�b�N�X�x�N�g���^(double �w����, double �x����) : �w(�w����),�x(�x����) {}
	�w�b�N�X�x�N�g���^() : �w(0),�x(0) {}
	double �w; // �w����
	double �x; // �x����
};


namespace �֐� {

	/// <summary>
	/// �Q�_�Ԃ̍��W�̍��ɂ���āA�w�b�N�X�x�N�g����������B
	/// �w�b�N�X�ʒu���u�̌��Z�B�u���W�`�����W�a�v�ւ̃x�N�g�������߂�̂ɁA�a�|�`��p�ɂɂ��邾�낤����B
	/// </summary>
	�w�b�N�X�x�N�g���^ operator-(�w�b�N�X�ʒu�^ &p1, �w�b�N�X�ʒu�^ &p2);

}




namespace �֐� {

	/// <summary>
	/// <para>���̃w�b�N�X�}�b�v��ɂ����āA�w��ʒu�̃w�b�N�X�`�b�v�Ƃ��Ă̖����𓾂�B</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>�@�u���w�b�N�X����::�g�O�v�`�u���w�b�N�X����::��v���Ԃ��Ă���B</para>
	/// <para>�@���W���}�b�v�����w���Ă��Ȃ��ꍇ��-1</para>
	/// </summary>
	/// <param name="�w�ʒu">�w��̂w�̈ʒu</param>
	/// <param name="�x�ʒu">�w��̂x�̈ʒu</param>
	/// <returns>
	/// <para>�u���w�b�N�X����::�g�O�v�`�u���w�b�N�X����::��v���Ԃ��Ă���B</para>
	/// <para>���W���}�b�v�����w���Ă��Ȃ��ꍇ��-1</para>
	/// </returns>
	int Get_���w�b�N�X����(double �w�ʒu, double �x�ʒu);

	/// <summary>
	/// <para>���̃w�b�N�X�}�b�v��ɂ����āA�w��ʒu�̃w�b�N�X�`�b�v�Ƃ��Ă̖����𓾂�B</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>�@�u���w�b�N�X����::�g�O�v�`�u���w�b�N�X����::��v���Ԃ��Ă���B</para>
	/// <para>�@���W���}�b�v�����w���Ă��Ȃ��ꍇ��-1</para>
	/// </summary>
	/// <param name="�o">�w��̃w�b�N�X�ʒu</param>
	/// <returns>
	/// <para>�u���w�b�N�X����::�g�O�v�`�u���w�b�N�X����::��v���Ԃ��Ă���B</para>
	/// <para>���W���}�b�v�����w���Ă��Ȃ��ꍇ��-1</para>
	/// </returns>
	int Get_���w�b�N�X����(�w�b�N�X�ʒu�^ �o);

	/// <summary>
	/// <para>�w��̃w�b�N�X�`�b�v�Ƃ��Ă̖����𖞂����A���w�b�N�X�ʒu�̃��X�g�𓾂�</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>���̖����𖞂����w�b�N�X�ʒu�̃��X�g���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="���w�b�N�X����">�u���w�b�N�X����::�g�O�v�`�u���w�b�N�X����::��v���w�肷��</param>
	/// <returns>
	/// <para>���̖����𖞂����w�b�N�X�ʒu�̃��X�g���Ԃ��Ă���B</para>
	/// </returns>
	�w�b�N�X�ʒu���X�g�^ Get_����̖����̖��w�b�N�X�ʒu���X�g(int ���w�b�N�X����);

	/// <summary>
	/// <para>�U���̃w�b�N�X�}�b�v��ɂ����āA�w��ʒu�̃w�b�N�X�`�b�v�Ƃ��Ă̖����𓾂�B</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>�@�u�U���w�b�N�X����::�g�O�v�`�u�U���w�b�N�X����::�{�ہv���Ԃ��Ă���B</para>
	/// <para>�@���W���}�b�v�����w���Ă��Ȃ��ꍇ��-1</para>
	/// </summary>
	/// <param name="�w�ʒu">�w��̂w�̈ʒu</param>
	/// <param name="�x�ʒu">�w��̂x�̈ʒu</param>
	/// <returns>
	/// <para>�u�U���w�b�N�X����::�g�O�v�`�u�U���w�b�N�X����::�{�ہv���Ԃ��Ă���B</para>
	/// <para>���W���}�b�v�����w���Ă��Ȃ��ꍇ��-1</para>
	/// </returns>
	int Get_�U���w�b�N�X����(double �w�ʒu, double �x�ʒu);

	/// <summary>
	/// <para>�U���̃w�b�N�X�}�b�v��ɂ����āA�w��ʒu�̃w�b�N�X�`�b�v�Ƃ��Ă̖����𓾂�B</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>�@�u�U���w�b�N�X����::�g�O�v�`�u�U���w�b�N�X����::�{�ہv���Ԃ��Ă���B</para>
	/// <para>�@���W���}�b�v�����w���Ă��Ȃ��ꍇ��-1</para>
	/// </summary>
	/// <param name="�o">�w��̃w�b�N�X�ʒu</param>
	/// <returns>
	/// <para>�u�U���w�b�N�X����::�g�O�v�`�u�U���w�b�N�X����::�{�ہv���Ԃ��Ă���B</para>
	/// <para>���W���}�b�v�����w���Ă��Ȃ��ꍇ��-1</para>
	/// </returns>
	int Get_�U���w�b�N�X����(�w�b�N�X�ʒu�^ �o) ;

	/// <summary>
	/// <para>�w��̃w�b�N�X�`�b�v�Ƃ��Ă̖����𖞂����A�U���̃w�b�N�X�ʒu�̃��X�g�𓾂�</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>���̖����𖞂����w�b�N�X�ʒu�̃��X�g���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�U���w�b�N�X����">�u�U���w�b�N�X����::�g�O�v�`�u�U���w�b�N�X����::�{�ہv���w�肷��</param>
	/// <returns>
	/// <para>���̖����𖞂����w�b�N�X�ʒu�̃��X�g���Ԃ��Ă���B</para>
	/// </returns>
	�w�b�N�X�ʒu���X�g�^ Get_����̖����̍U���w�b�N�X�ʒu���X�g(int �U���w�b�N�X����);

	/// <summary>
	/// <para>�U���̃w�b�N�X�}�b�v��ɂ����āA�w��ʒu�̍����𓾂�B</para>
	/// <para>(�V�ċL�̍U���͂Q�c�ł͂��邪�A��ǂň͂܂�Ă��āA���w���ɍ������ݒ肳��Ă���B)</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>�@�w��̃w�b�N�X�ʒu�̍������Ԃ��Ă���B</para>
	/// <para>�@���W���}�b�v�����w���Ă��Ȃ��ꍇ��-1</para>
	/// </summary>
	/// <param name="�w�ʒu">�w��̂w�̈ʒu</param>
	/// <param name="�x�ʒu">�w��̂x�̈ʒu</param>
	/// <returns>
	/// <para>�w��̃w�b�N�X�ʒu�̍������Ԃ��Ă���B</para>
	/// <para>���W���}�b�v�����w���Ă��Ȃ��ꍇ��-1</para>
	/// </returns>
	int Get_�U���w�b�N�X����(double �w�ʒu, double �x�ʒu);

	/// <summary>
	/// <para>�U���̃w�b�N�X�}�b�v��ɂ����āA�w��ʒu�̍����𓾂�B</para>
	/// <para>(�V�ċL�̍U���͂Q�c�ł͂��邪�A��ǂň͂܂�Ă��āA���w���ɍ������ݒ肳��Ă���B)</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>�@�w��̃w�b�N�X�ʒu�̍������Ԃ��Ă���B</para>
	/// <para>�@���W���}�b�v�����w���Ă��Ȃ��ꍇ��-1</para>
	/// </summary>
	/// <param name="�o">�w��̃w�b�N�X�ʒu</param>
	/// <returns>
	/// <para>�w��̃w�b�N�X�ʒu�̍������Ԃ��Ă���B</para>
	/// <para>���W���}�b�v�����w���Ă��Ȃ��ꍇ��-1</para>
	/// </returns>
	int Get_�U���w�b�N�X����(�w�b�N�X�ʒu�^ �o);


	/// <summary>
	/// <para>�U���̃w�b�N�X�}�b�v��ɂ����āA�w��ʒu�����サ�Ă��邩�ǂ����𓾂�B</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>�E���サ�Ă���Ȃ�u�U���w�b�N�X����::����v</para>
	/// <para>�E���サ�Ă��Ȃ��Ȃ�u�U���w�b�N�X����::�����v</para>
	/// <para>�E���W���}�b�v�����w���Ă��Ȃ��ꍇ��-1</para>
	/// <para>���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�w�ʒu">�w��̂w�̈ʒu</param>
	/// <param name="�x�ʒu">�w��̂x�̈ʒu</param>
	/// <returns>
	/// <para>�E���サ�Ă���Ȃ�u�U���w�b�N�X����::����v</para>
	/// <para>�E���サ�Ă��Ȃ��Ȃ�u�U���w�b�N�X����::�����v</para>
	/// <para>�E���W���}�b�v�����w���Ă��Ȃ��ꍇ��-1</para>
	/// <para>���Ԃ��Ă���</para>
	/// </returns>
	int Get_�U���w�b�N�X����(double �w�ʒu, double �x�ʒu);

	/// <summary>
	/// <para>�U���̃w�b�N�X�}�b�v��ɂ����āA�w��ʒu�����サ�Ă��邩�ǂ����𓾂�B</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>�E���サ�Ă���Ȃ�u�U���w�b�N�X����::����v</para>
	/// <para>�E���サ�Ă��Ȃ��Ȃ�u�U���w�b�N�X����::�����v</para>
	/// <para>�E���W���}�b�v�����w���Ă��Ȃ��ꍇ��-1</para>
	/// <para>���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�o">�w��̃w�b�N�X�ʒu</param>
	/// <returns>
	/// <para>�E���サ�Ă���Ȃ�u�U���w�b�N�X����::����v</para>
	/// <para>�E���サ�Ă��Ȃ��Ȃ�u�U���w�b�N�X����::�����v</para>
	/// <para>�E���W���}�b�v�����w���Ă��Ȃ��ꍇ��-1</para>
	/// <para>���Ԃ��Ă���</para>
	/// </returns>
	int Get_�U���w�b�N�X����(�w�b�N�X�ʒu�^ �o);

	/// <summary>
	/// <para>�U���ŉ��サ�Ă���w�b�N�X�ʒu�̃��X�g�𓾂�</para>
	/// <para>�Ԃ�l�F</para>
	/// <para>���サ�Ă���w�b�N�X�ʒu�̃��X�g���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�U���w�b�N�X����">�u�U���w�b�N�X����::�g�O�v�`�u�U���w�b�N�X����::�{�ہv���w�肷��</param>
	/// <returns>
	/// <para>�w�肵�������Ԃ̃w�b�N�X�ʒu�̃��X�g���Ԃ��Ă���B</para>
	/// </returns>
	�w�b�N�X�ʒu���X�g�^ Get_����̍U���w�b�N�X�ʒu���X�g(int �U���w�b�N�X���� = �U���w�b�N�X����::����);

	/// <summary>
	/// <para>�w�b�N�X�}�b�v��ɂ����āA�o�P�̈ʒu�ƁA�o�Q�̈ʒu�ŁA�u���}�X�v����Ă���̂��𓾂�B</para>
	/// <para>�ړ��o�H�Ȃǂ͈�؍l�����Ȃ��B�S�Ẵ}�X�͈ړ��\�Ȃ��̂Ƃ��Čv�Z����B</para>
	/// <para>(�o�P�ɂ��������}�X�ړ�����΁A�o�Q�ɂ��ǂ蒅����̂��H �Ƃ����l���Ǝv���΂悢�B)</para>
	/// <para>�Ԃ�l�F�o�P�Ƃo�Q�̊Ԋu</para>
	/// </summary>
	/// <param name="�o�P">�P�ڂ̃w�b�N�X��̈ʒu�B</param>
	/// <param name="�o�Q">�Q�ڂ̃w�b�N�X��̈ʒu�B</param>
	/// <returns>�o�P�Ƃo�Q�̊Ԋu�B</returns>
	int Get_�w�b�N�X�Ԋu(�w�b�N�X�ʒu�^ �o�P, �w�b�N�X�ʒu�^ �o�Q);


	/// <summary>
	/// �w��̕��������}�b�v��̂ǂ��ɂ���̂��A�𓾂�B
	/// <para>�Ԃ�l�F���ł̃w�b�N�X�ʒu�^�ŕԂ��B</para>
	/// <para>�\�����̃}�b�v�ɋ��Ȃ��ꍇ�A���w�b�N�X�ʒu�^�̂o(x=0xFFFF, y=0xFFFF) ���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>���ł̃w�b�N�X�ʒu�^�ŕԂ��B</returns>
	�w�b�N�X�ʒu�^ Get_�����̖��w�b�N�X�ʒu(int �����ԍ��y�z��p�z);

	/// <summary>
	/// �w��̕������U���}�b�v��̂ǂ��ɂ���̂��A�𓾂�B
	/// <para>�Ԃ�l�F�U���ł̃w�b�N�X�ʒu�^�ŕԂ��B</para>
	/// <para>�\�����̃}�b�v�ɋ��Ȃ��ꍇ�A�U���w�b�N�X�ʒu�^�̂o(x=0xFFFF, y=0xFFFF) ���Ԃ��Ă���B</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	/// <returns>�U���ł̃w�b�N�X�ʒu�^�ŕԂ��B</returns>
	�w�b�N�X�ʒu�^ Get_�����̍U���w�b�N�X�ʒu(int �����ԍ��y�z��p�z);

	/// <summary>
	/// ���ł̃w�b�N�X�̍��W�����ʂ̂R�������W(����f�J���g)�ւƕϊ�����B
	/// <para>�Ԃ�l�F���ł̃w�b�N�X�ł̈ʒu�o�ɑΉ�����A��Ԃł̍��W��Ԃ��B</para>
	/// </summary>
	/// <param name="�o">���ł̃w�b�N�X�̈ʒu</param>
	/// <returns>���w�b�N�X�ł̈ʒu�o�ɑΉ�����A��Ԃł̍��W��Ԃ��B</returns>
	�R�c�ʒu�^ ���w�b�N�X�ʒu���R�c�ʒu(�w�b�N�X�ʒu�^ �o);

	/// <summary>
	/// ���ʂ̂R�������W(����f�J���g)�����ł̃w�b�N�X�̍��W�ւƕϊ�����B
	/// <para>�Ԃ�l�F���ł̃w�b�N�X�ʒu�^�ŕԂ��B</para>
	/// </summary>
	/// <param name="�o">���ʂ̂R�������W�B���W���͍���f�J���g�B</param>
	/// <returns>���ł̃w�b�N�X�ʒu�^�ŕԂ��B</returns>
	�w�b�N�X�ʒu�^ �R�c�ʒu�����w�b�N�X�ʒu(�R�c�ʒu�^ �o);

	/// <summary>
	/// �U���ł̃w�b�N�X�̍��W�����ʂ̂R�������W(����f�J���g)�ւƕϊ�����B
	/// <para>�Ԃ�l�F�U���ł̃w�b�N�X�ł̈ʒu�o�ɑΉ�����A��Ԃł̍��W��Ԃ��B</para>
	/// </summary>
	/// <param name="�o">�U���ł̃w�b�N�X�̈ʒu</param>
	/// <returns>�U���w�b�N�X�ł̈ʒu�o�ɑΉ�����A��Ԃł̍��W��Ԃ��B</returns>
	�R�c�ʒu�^ �U���w�b�N�X�ʒu���R�c�ʒu(�w�b�N�X�ʒu�^ �o);

	/// <summary>
	/// ���ʂ̂R�������W(����f�J���g)���U���ł̃w�b�N�X�̍��W�ւƕϊ�����B
	/// <para>�Ԃ�l�F�U���ł̃w�b�N�X�ʒu�^�ŕԂ��B</para>
	/// </summary>
	/// <param name="�o">���ʂ̂R�������W�B���W���͍���f�J���g�B</param>
	/// <returns>�U���ł̃w�b�N�X�ʒu�^�ŕԂ��B</returns>
	�w�b�N�X�ʒu�^ �R�c�ʒu���U���w�b�N�X�ʒu(�R�c�ʒu�^ �o);
}



