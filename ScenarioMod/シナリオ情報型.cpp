#define _CRT_SECURE_NO_WARNINGS

#include <string>

#include "�R�}���h���^.h"
#include "�Q�[���f�[�^�\��.h"

using namespace std;
using namespace �֐�;

#define GAMEDATASTRUCT_SCENARIO_NAME_POINTER_ARRAY_ADDRESS		0x4D3728 // �U�̃V�i���I���ւ̃|�C���^�z��̐擪�A�h���X


extern HMODULE hModuleTSMod;

using PFNOGETCURSCENARIOLOCATION = int (WINAPI *)();
PFNOGETCURSCENARIOLOCATION p_getCurScenarioLocation = NULL;

// TSMod�ɂ����Ȃ�����Đ��֐��̃|�C���^�̓o�^
void _�V�i���I�֐��o�^() {
	// �K�v�s���l���㏑������B
	p_getCurScenarioLocation = (PFNOGETCURSCENARIOLOCATION)GetProcAddress( hModuleTSMod, "Extern_getCurScenarioLocation" );
}

/*
004D3728  [E4 36 4D 00] [C4 36 4D 00] [A4 36 4D 00] [84 36 4D 00]  �EM.�6M.�6M.�EM.
004D3738  [64 36 4D 00] [44 36 4D 00]                          d6M.D6M.
*/
namespace �֐� {

string Get_�V�i���I��(int i�V�i���I�ԍ�) {
	if ( 1 <= i�V�i���I�ԍ� && i�V�i���I�ԍ� <= �ő吔::�V�i���I���::�z�� ) {
		int iLocation = i�V�i���I�ԍ�-1;
		int *p = (int *)GAMEDATASTRUCT_SCENARIO_NAME_POINTER_ARRAY_ADDRESS;
		int iTargetAddress = *(p+iLocation);
		char *pTitle = (char *)iTargetAddress;
		string title = string(pTitle);
		return title;
	} else {
		return string("");
	}
}

int Get_���݂̃V�i���I�ԍ�() {
	if ( p_getCurScenarioLocation ) {
		int iLocation = p_getCurScenarioLocation();
		if ( 0 <= iLocation && iLocation < �ő吔::�V�i���I���::�z�� ) {
			return iLocation+1;
		}
	}
	return -1;
}


}