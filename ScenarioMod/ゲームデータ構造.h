#pragma once

#pragma pack(1)

#pragma warning ( error : 4706 ) // �������̔�r�l���A����̌��ʂɂȂ��Ă���̂̓A�E�g�Ƃ���B (if���ȂǂŔ�r�ł͂Ȃ�����������Ă�Ǝv�������m���G���[�����Ƃ���)

#include <windows.h>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <shlwapi.h>
#include <cctype>

using namespace std;

#include "�ő吔.h"
#include "��񃁃����A�h���X.h"

#include "�⏕���C�u����.h"

#include "���b�Z�[�W�֘A���^.h"
#include "�J�X�^���������^.h"

#include "�^�[�����^.h"
#include "�n����^.h"
#include "����^.h"
#include "�V�C���^.h"
#include "�喼���^.h"
#include "���ʏ��^.h"
#include "�ƕ���^.h"
#include "����^.h"
#include "�������^.h"
#include "�ҋ@�������^.h"
#include "������^.h"
#include "�R�c���^.h"
#include "��E���^.h"
#include "�����^.h"
#include "���ݒ���^.h"
#include "���ʉ����^.h"
#include "���y���^.h"
#include "������^.h"
#include "��ʉ��o���^.h"
#include "�R�}���h���^.h"
#include "�_�C�A���O���^.h"
#include "���������^.h"
#include "�V�i���I���^.h"
#include "�G���f�B���O���^.h"
#include "�Q�c�ʒu���^.h"
#include "�R�c�ʒu���^.h"
#include "�t���O���^.h"
#include "���t�������^.h"
#include "�f�o�b�O���^.h"
#include "�f�o�b�O�摜���^.h"
#include "�A�v���P�[�V�������^.h"
#include "�k�t�`.h"
#include "�l�q�t�a�x.h"

#include "�g���Z�[�u�f�[�^���.h"
#include "�}�l�[�W�h���C�u����.h"


using namespace �֐�;


#define p�N���					d�N���[0]
#define p�^�[�����				d�^�[�����[0]
#define p������				d������[0]
#define p�V�C���				d�V�C���[0]
#define p���ݒ���			d���ݒ���[0]
#define p���ݒ�g�����		d���ݒ�g�����[0]


extern	�N���^				*const d�N���;
extern	�^�[�����^			*const d�^�[�����;
extern	������^				*const d������;
extern	�V�C���^				*const d�V�C���;

extern	�������^				*const p�������;

extern	�����ːЏ��^			*const p�����ːЏ��;

extern	�R�c���^				*const p�R�c���;
extern	�v���C���S���R�c���^	*const p�v���C���S���R�c���;

extern	�喼���^				*const p�喼���;

extern	����^				*const p����;
extern	��t�����^			*const p��t�����;

extern	�n����^				*const p�n����;

extern	���ʏ��^				*const p���ʏ��;
extern	�ƕ���^				*const p�ƕ���;

extern	���ݒ���^			*const d���ݒ���;
extern	���ݒ�g�����^		*const d���ݒ�g�����;

