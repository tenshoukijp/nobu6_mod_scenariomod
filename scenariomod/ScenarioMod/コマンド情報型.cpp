#define _CRT_SECURE_NO_WARNINGS

#include <string>

#include "�R�}���h���^.h"
#include "�Q�[���f�[�^�\��.h"

using namespace std;
using namespace �֐�;

extern HMODULE hModuleTSMod;

using PFNOVERWRITENEEDKOUDOURYOKU = int(WINAPI *)(int �s���^�C�v, int �s���l);
PFNOVERWRITENEEDKOUDOURYOKU p_OverWriteNeedKoudouryoku = NULL;

// TSMod�ɂ����Ȃ�����Đ��֐��̃|�C���^�̓o�^
void _�R�}���h�֐��o�^() {
	// �K�v�s���l���㏑������B
	p_OverWriteNeedKoudouryoku = (PFNOVERWRITENEEDKOUDOURYOKU)GetProcAddress( hModuleTSMod, "Extern_OverWriteNeedKoudouryoku" );
}



extern string _g�퓬�R�}���h���X�g[];
extern string _g��{�R�}���h���X�g[];


namespace �֐� {
	void Set_�R�}���h��( int �R�}���h���h�c, string �V�R�}���h�̕����� ) {

		// �ە������������ԍ��Ȃ�΁A����͐퓬�R�}���h��
		if ( �R�}���h���h�c < �푈���::��{�R�}���h��::�ە� ) {
			_g�퓬�R�}���h���X�g[�R�}���h���h�c] = �V�R�}���h�̕�����;

		// ��{�R�}���h�̃��X�g��
		} else {
			�R�}���h���h�c -= �푈���::��{�R�}���h��::�ە�; // 0�I���W���Ƃ���B
			_g��{�R�}���h���X�g[�R�}���h���h�c] = �V�R�}���h�̕�����;
		}
	}
}


/*
�@�e��s���ɕK�v�Ȓl�̐ݒ�B�_�p�b�`���̈ڐA�B
 */



namespace �֐� {

void Set_�R�}���h�s����(int e�R�}���h�s���̓^�C�v, int �s����) {

	if ( p_OverWriteNeedKoudouryoku ) {
		p_OverWriteNeedKoudouryoku( e�R�}���h�s���̓^�C�v, �s���� );
	}
}

}






/*
0041C09A   . 57             PUSH    EDI					�� �����ԍ�
0041C09B   . E8 198D0100    CALL    TENSHOU.00434DB9
0041C0A0   . 83C4 04        ADD     ESP, 4
*/

int pCallFromFuncDoTaikyakuInBattle = 0x434DB9; // ���XTENSHOU.EXE���ɂ�����CALL��

int iBushouIDInFuncDoTaikyakuInBattle = 1L;    // ���S����ID

// ���C����ʂŎw��̕������E�Q
void FuncDoTaikyakuInBattleAsm() {
	__asm {
		push iBushouIDInFuncDoTaikyakuInBattle
		call pCallFromFuncDoTaikyakuInBattle
		add esp, 0x4
	}
}


// ���C����ʂŎw��̕������E�Q
namespace �֐� {
	int Do_�R�}���h�s�푈��ʁt�s�ދp�t(int �����ԍ��y�z��p�z) {

		// ��킿�イ�ł��Ȃ��A���A�U��풆�ł��Ȃ��Ȃ�΁A�_��
		if ( !Is_��풆() && !Is_�U��풆() ) {
			return false;
		}

		int iBushouID = �����ԍ��y�z��p�z;
		if ( 0 <= iBushouID && iBushouID < �ő吔::�������::�z�� ) {

			// ���łɐ펀���Ă�����_��
			if ( p�����ːЏ��[iBushouID].�펀 ) {
				return false;
			}
			// ���łɑދp���Ă�����_��
			if ( p�����ːЏ��[iBushouID].�ދp ) {
				return false;
			}

			// �֐��p�̂�́A1�����̂ŁA��������
			iBushouIDInFuncDoTaikyakuInBattle = iBushouID+1;
		
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
			FuncDoTaikyakuInBattleAsm();

			__asm {
				pop edi
				pop esi
				pop esp
				pop edx
				pop ecx
				pop ebx
				pop eax
			}
			return true;
		}

		return false;
	}
}
