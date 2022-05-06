#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <cassert>
#include "ゲームデータ構造.h"
#include <string>

extern HMODULE hModuleTSMod;


using PFNSETMAPFLAG		= int (WINAPI *)(char *szFlagName, int iFlagValue, int iFlagTarget);
PFNSETMAPFLAG p_SetMapFlag = NULL;
using PFNGETMAPFLAG		= int (WINAPI *)(char *szFlagName, int iFlagTarget);
PFNGETMAPFLAG p_GetMapFlag = NULL;
using PFNDELETEMAPFLAG	= int (WINAPI *)(char *szFlagName);
PFNDELETEMAPFLAG p_DeleteMapFlag = NULL;


// TSModにしかない動画再生関数のポインタの登録
void _フラグ関数登録() {
	p_SetMapFlag = (PFNSETMAPFLAG)GetProcAddress( hModuleTSMod, "Extern_SetMapFlag" );
	p_GetMapFlag = (PFNGETMAPFLAG)GetProcAddress( hModuleTSMod, "Extern_GetMapFlag" );
	p_DeleteMapFlag = (PFNDELETEMAPFLAG)GetProcAddress( hModuleTSMod, "Extern_DeleteMapFlag" );
}


namespace 関数 {

	
int Set_フラグ( string フラグ名, int フラグ値, int フラグ枠 ) {
	if ( p_SetMapFlag ) {
		// フラグ名をcharのsz型に
		char szFlagName[9];
		strncpy( szFlagName, フラグ名.c_str(), 8 );
		szFlagName[8] = NULL;

		return p_SetMapFlag( szFlagName, フラグ値, フラグ枠 );
	}

	return 0;
}

int Get_フラグ( string フラグ名, int フラグ枠 ) {
	if ( p_GetMapFlag ) {
		// フラグ名をcharのsz型に
		char szFlagName[9];
		strncpy( szFlagName, フラグ名.c_str(), 8 );
		szFlagName[8] = NULL;

		return p_GetMapFlag( szFlagName, フラグ枠 );
	}

	return 0;
}


int Delete_フラグ( string フラグ名 ) {
	if ( p_DeleteMapFlag ) {
		// フラグ名をcharのsz型に
		char szFlagName[9];
		strncpy( szFlagName, フラグ名.c_str(), 8 );
		szFlagName[8] = NULL;

		return p_DeleteMapFlag( szFlagName );
	}

	return 0;
}

}