#include <cassert>
#include "�Q�[���f�[�^�\��.h"

#pragma comment(lib, "winmm.lib")

	//---------------------�a�f�l��~-------------------------
	int pCallFromFuncStopBGM = 0x48D483; // ���XTENSHOU.EXE���ɂ�����CALL��

	void _FuncStopBGMAsm() {
		__asm {
			push eax
			push ebx
			push ecx
			push edx
			push esp
			push esi
			push edi
		}

		__asm {
			call pCallFromFuncStopBGM
		}

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}

	}


	//---------------------�a�f�l�Đ�-------------------------
	#define GAMEDATASTRUCT_PLAYING_BGM_ID_ADDRESS	0x4D2A7C	// �Đ�����BGM��ID�̃A�h���X(WORD)

	int _pCallFromFuncPlayBGM = 0x48D3E9; // ���XTENSHOU.EXE���ɂ�����CALL��

	int _iBgmIdFuncPlayBGM = -1;

	void _FuncPlayBGMAsm() {

		__asm {
			push 0x1  // ���Ȃ̂��͂킩���c���[�v�t���O�Ƃ����ȁH

			push _iBgmIdFuncPlayBGM

			call _pCallFromFuncPlayBGM

			add esp, 8
		}

	}

namespace �֐� {

	// �w��̂a�f�l���Đ�����(���̉��y�ԍ��́A�_�p�b�`�Ŏw�肷��ԍ��ƍ��v���Ă�ƍl���ėǂ�[-1�Ƃ�����K�v���Ȃ�])
	void ���y�Đ�(int ���y�ԍ�) {

		// TSMod��_�p�b�`�x�[�X�̔ԍ���Tenshouki�����ԍ��ɒ����B
		if ( 1 <= ���y�ԍ� && ���y�ԍ� < 0xFFFF ) {
			���y�ԍ�--;
		}
		_iBgmIdFuncPlayBGM = ���y�ԍ�;

		__asm {
			push eax
			push ebx
			push ecx
			push edx
			push esp
			push esi
			push edi
		}


		// TENSHOU.EXE���̊֐��Ăяo��
		_FuncPlayBGMAsm();

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}

	}


	// �a�f�l���~����B
	void ���y��~() {
		// TENSHOU.EXE���̊֐��Ăяo��
		_FuncStopBGMAsm();
	}

	// �Đ�����BGM��ID�𓾂�B0xFFFF���Ɖ����Đ����Ă��Ȃ��B
	int Get_�Đ����y�ԍ�() {

		WORD *pBGMID = (WORD *)GAMEDATASTRUCT_PLAYING_BGM_ID_ADDRESS;
		// tenshouki�����ԍ����_�p�b�`�ԍ��ɒ���
		if ( 1 <= *pBGMID && *pBGMID != 0xFFFF ) {
			return (*pBGMID)+1;
		} else {
			return 0xFFFF;
		}

	}


	#define GAMEDATASTRUCT_WINMM_DLL_NAME_ADDRESS	0x4E7CC0	// WINMM.DLL��_INMM.DLL�Ȃ̂��B

	// _INMM���[�h���H
	bool Is_INMM���[�h() {

		char *winmm = (char *)GAMEDATASTRUCT_WINMM_DLL_NAME_ADDRESS;

		int mode = Get_�s�r�l�n�c�h�m�h�ݒ�("environment_bgm_mode");

		if ( strcmp( winmm, "_INMM.dll") == 0 ) {
			return true;
		} else if ( mode == 1 || mode == 2 ) {
			return true;
		}

		return false;
	}

}

