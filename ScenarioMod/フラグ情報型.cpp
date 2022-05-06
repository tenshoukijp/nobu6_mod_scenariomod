#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <cassert>
#include "�Q�[���f�[�^�\��.h"
#include <string>

extern HMODULE hModuleTSMod;


using PFNSETMAPFLAG		= int (WINAPI *)(char *szFlagName, int iFlagValue, int iFlagTarget);
PFNSETMAPFLAG p_SetMapFlag = NULL;
using PFNGETMAPFLAG		= int (WINAPI *)(char *szFlagName, int iFlagTarget);
PFNGETMAPFLAG p_GetMapFlag = NULL;
using PFNDELETEMAPFLAG	= int (WINAPI *)(char *szFlagName);
PFNDELETEMAPFLAG p_DeleteMapFlag = NULL;


// TSMod�ɂ����Ȃ�����Đ��֐��̃|�C���^�̓o�^
void _�t���O�֐��o�^() {
	p_SetMapFlag = (PFNSETMAPFLAG)GetProcAddress( hModuleTSMod, "Extern_SetMapFlag" );
	p_GetMapFlag = (PFNGETMAPFLAG)GetProcAddress( hModuleTSMod, "Extern_GetMapFlag" );
	p_DeleteMapFlag = (PFNDELETEMAPFLAG)GetProcAddress( hModuleTSMod, "Extern_DeleteMapFlag" );
}


namespace �֐� {

	
int Set_�t���O( string �t���O��, int �t���O�l, int �t���O�g ) {
	if ( p_SetMapFlag ) {
		// �t���O����char��sz�^��
		char szFlagName[9];
		strncpy( szFlagName, �t���O��.c_str(), 8 );
		szFlagName[8] = NULL;

		return p_SetMapFlag( szFlagName, �t���O�l, �t���O�g );
	}

	return 0;
}

int Get_�t���O( string �t���O��, int �t���O�g ) {
	if ( p_GetMapFlag ) {
		// �t���O����char��sz�^��
		char szFlagName[9];
		strncpy( szFlagName, �t���O��.c_str(), 8 );
		szFlagName[8] = NULL;

		return p_GetMapFlag( szFlagName, �t���O�g );
	}

	return 0;
}


int Delete_�t���O( string �t���O�� ) {
	if ( p_DeleteMapFlag ) {
		// �t���O����char��sz�^��
		char szFlagName[9];
		strncpy( szFlagName, �t���O��.c_str(), 8 );
		szFlagName[8] = NULL;

		return p_DeleteMapFlag( szFlagName );
	}

	return 0;
}

}