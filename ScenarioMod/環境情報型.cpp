#include <string>

#include "�R�}���h���^.h"
#include "�Q�[���f�[�^�\��.h"

using namespace std;
using namespace �֐�;

extern HMODULE hModuleTSMod;

using PFNOGETTSMODTXTFLAG = int (WINAPI *)(char *szFlagName);
PFNOGETTSMODTXTFLAG p_GetTSModTxtFlag = NULL;

// TSMod�ɂ����Ȃ�����Đ��֐��̃|�C���^�̓o�^
void _���֐��o�^() {
	// �K�v�s���l���㏑������B
	p_GetTSModTxtFlag = (PFNOGETTSMODTXTFLAG)GetProcAddress( hModuleTSMod, "Extern_getTSModTxtFlag" );

}

namespace �֐� {

	int Get_�s�r�l�n�c�h�m�h�ݒ�(string �t���O��) {
		if ( p_GetTSModTxtFlag ) {
			return p_GetTSModTxtFlag((char *)�t���O��.c_str());
		}
		return -0xFFFF;
	}

}


