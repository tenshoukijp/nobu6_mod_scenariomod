#include <cassert>
#include "�Q�[���f�[�^�\��.h"


extern HMODULE hModuleTSMod;

using PFNRESERVEWEATHER = void (WINAPI *)(int eTenki, int iContinueTurn);
PFNRESERVEWEATHER p_FuncReserveWeather = NULL;

	// TSMod�ɂ����Ȃ��V�C�\��֐��̃|�C���^�̓o�^

	void _�V�C�֐��o�^() {
		// �V�i���I�f�[�^�̈����o���p���\�b�h�̃|�C���^�m��
		p_FuncReserveWeather = (PFNRESERVEWEATHER)GetProcAddress( hModuleTSMod, "Extern_reserveWeather" );
	}



namespace �֐� {


// �V�C���𓾂� 0:���� 1:�܂� 2:�J 3:��
byte Get_�V�C() {

	return p�V�C���._�V�C;
}

}





/*
00436101  |> 56             PUSH    ESI						�� �V�C�ԍ�
00436102  |. E8 29020600    CALL    TENSHOU.00496330		�� �V�C��ύX���āA�`����X�V�̊֐�
00436107  |. 83C4 04        ADD     ESP, 4
*/

int pCallFromFuncSetWeather = 0x496330; // ���XTENSHOU.EXE���ɂ�����CALL��B�V�C�l�ƓV�C�O���t�B�b�N��ύX

int iWeatherIDInFuncSetWeather = 1L;    // ���S����ID

// �V�C�̕ύX
void FuncSetWeatherAsm() {
	__asm {
		push iWeatherIDInFuncSetWeather
		call pCallFromFuncSetWeather
		add esp, 0x4
	}
}



namespace �֐� {



// �V�C�̕ύX�̃��b�p�[
void Set_�V�C(int i�V�C) {

	// �֐��p�̂�́A1�����̂ŁA��������
	iWeatherIDInFuncSetWeather = i�V�C;

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
	FuncSetWeatherAsm();

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

// ���̃^�[���̓V�C��\�񂷂�
void Set_�V�C�\��(int �\��V�C, int �p���^�[��) {

	if ( p_FuncReserveWeather ) {
		p_FuncReserveWeather(�\��V�C, �p���^�[��);
	}
}


}




