#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include "�Q�[���f�[�^�\��.h"


extern HMODULE hModuleTSMod;


using PFNGETTAIKIBUSHOUAPPEARARRAYPOINTER = �ҋ@������o����^* (cdecl *)();
PFNGETTAIKIBUSHOUAPPEARARRAYPOINTER p_Extern_GetTaikiBushouAppearArrayPointer = NULL;

using PFNGETTAIKIBUSHOUARRAYPOINTER = �ҋ@�������^* (cdecl *)();
PFNGETTAIKIBUSHOUARRAYPOINTER p_Extern_GetTaikiBushouArrayPointer = NULL;

using PFNGETTAIKIBUSHOUNAMEARRAYPOINTER = �ҋ@�����ːЏ��^* (cdecl *)();
PFNGETTAIKIBUSHOUNAMEARRAYPOINTER p_Extern_GetTaikiBushouNameArrayPointer = NULL;

// ���̃f�[�^�ɂU�̃V�i���I�̑ҋ@�����̃f�[�^�o�b�t�@�[���܂�܂�R�s�[���Ă���̂ŁA�D���Ȃ悤�Ɉ����ėǂ��BTSMod�Ƃ͊����Ȃ��B
// (taiki.n6p�̓W�J�f�[�^�Ɠ���)
byte _�ҋ@�����f�[�^�o�b�t�@�[[6][(sizeof(�ҋ@������o����^) + sizeof(�ҋ@�������^) + sizeof(�ҋ@�����ːЏ��^)) * 1300] = { 0 }; // �{����1000�l�サ���f�[�^�Ƃ��ċl�ߍ��ނ��Ƃ��o���Ȃ����A����������B������l���o�邩������Ȃ��̂ŁA�����]�T���������Ă����B
int _�ҋ@�����f�[�^�l��[6] = { 0 };


namespace �֐� {


	// ���ݐi�s�`�̃V�i���I�ɂ�����A�ҋ@�����f�[�^�������߂�B
	int Get_�ҋ@�����o��ϐl��() {
#define GAMEDATASTRUCT_TOUZYOU_BUSHOU_NUM_ADDRESS       0x4CFC37    // �ҋ@����o�ꂵ����
		WORD *pTouzyouBushouNum = (WORD *)GAMEDATASTRUCT_TOUZYOU_BUSHOU_NUM_ADDRESS;
		return *pTouzyouBushouNum;
	}


	// ���ݎs�̋�`�̃V�i���I�ɂ����āA�ҋ@�����f�[�^���̂����A���łɓo�ꂵ�Ă��܂�����
	int Get_�ҋ@�����f�[�^��() {
#define GAMEDATASTRUCT_MITOUZYOU_BUSHOU_NUM_ADDRESS     0x4CFC39    // ���o�ꕐ���̑�����
		WORD *pMitouzyouBushouNum = (WORD *)GAMEDATASTRUCT_MITOUZYOU_BUSHOU_NUM_ADDRESS;
		return *pMitouzyouBushouNum;
	}

	�ҋ@������o����^ *Get_�ҋ@�����o���񃊃X�g() {
		int sno = Get_���݂̃V�i���I�ԍ�();
		if (1 <= sno && sno <= �ő吔::�V�i���I���::�z��) {
			byte *p = _�ҋ@�����f�[�^�o�b�t�@�[[sno - 1];
			int add = 0;
			return (�ҋ@������o����^ *)(p + add);
		}

		return NULL;
	}

	�ҋ@�������^ *Get_�ҋ@������񃊃X�g() {
		int sno = Get_���݂̃V�i���I�ԍ�();
		if (1 <= sno && sno <= �ő吔::�V�i���I���::�z��) {
			byte *p = _�ҋ@�����f�[�^�o�b�t�@�[[sno - 1];
			int add = sizeof(�ҋ@������o����^) * Get_�ҋ@�����f�[�^��(); // �����o���񕔕����܂�܂�p�X�������B
			return (�ҋ@�������^ *)(p + add);
		}

		return NULL;
	}

	�ҋ@�����ːЏ��^ *Get_�ҋ@�����ːЏ�񃊃X�g() {
		int sno = Get_���݂̃V�i���I�ԍ�();
		if (1 <= sno && sno <= �ő吔::�V�i���I���::�z��) {
			byte *p = _�ҋ@�����f�[�^�o�b�t�@�[[sno - 1];
			int add = (sizeof(�ҋ@������o����^) + sizeof(�ҋ@�������^)) * Get_�ҋ@�����f�[�^��(); // �����o����ƕ�����񕔕����܂�܂�p�X�������B
			return (�ҋ@�����ːЏ��^ *)(p + add);
		}

		return NULL;
	}
}



