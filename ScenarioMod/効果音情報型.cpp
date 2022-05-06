#include <cassert>
#include "�Q�[���f�[�^�\��.h"

#include <windows.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <map>

// ��������n6pwav.dll��������n6pwav1.dll
HMODULE hModuleResourceN6PWav;
extern HMODULE hModuleTSMod;

// ���[�U�ǉ��^��DLL�B�uDLL����DLL�n���h���v�̃n�b�V���B
map<string, HMODULE> mapHResistModuleHandle;

using SOUNDHANDLE = int;

using PFNPLAYSOUND2DSTR		= SOUNDHANDLE (WINAPI *)(char *szFileName, BOOL isLoop);
using PFNPLAYSOUND2DRESID	= SOUNDHANDLE (WINAPI *)(int iResID, HMODULE hModule, BOOL isLoop);
using PFNPLAYSOUND3DSTR		= SOUNDHANDLE (WINAPI *)(char *szFileName, BOOL isLoop, double px, double py, double pz, double vx, double vy, double vz);
using PFNPLAYSOUND3DRESID	= SOUNDHANDLE (WINAPI *)(int iResID, HMODULE hModule, BOOL isLoop, double px, double py, double pz, double vx, double vy, double vz);
using PFNSTOPSOUND			= void (WINAPI *)(SOUNDHANDLE hSound);
using PFNSTOPALLSOUND		= void (WINAPI *)();

PFNPLAYSOUND2DSTR p_PlaySound2DStr = NULL;
PFNPLAYSOUND2DRESID p_PlaySound2DResID = NULL;
PFNPLAYSOUND3DSTR p_PlaySound3DStr = NULL;
PFNPLAYSOUND3DRESID p_PlaySound3DResID = NULL;
PFNSTOPSOUND p_StopSound = NULL;
PFNSTOPALLSOUND p_StopAllSound = NULL;

using PFNCHANGEMIDIMAPPER	= void(WINAPI *)(char *szMidiMapperName);
PFNCHANGEMIDIMAPPER p_ChangeMidiMapper = NULL;


	// TSMod�ɂ����Ȃ�����Đ��֐��̃|�C���^�̓o�^
	void _���ʉ��֐��o�^() {
		// �V�i���I�f�[�^�̈����o���p���\�b�h�̃|�C���^�m��
		p_PlaySound2DStr = (PFNPLAYSOUND2DSTR)GetProcAddress( hModuleTSMod, "Extern_PlaySound2DStr" );
		p_PlaySound2DResID = (PFNPLAYSOUND2DRESID)GetProcAddress( hModuleTSMod, "Extern_PlaySound2DResID" );
		p_PlaySound3DStr = (PFNPLAYSOUND3DSTR)GetProcAddress( hModuleTSMod, "Extern_PlaySound3DStr" );
		p_PlaySound3DResID = (PFNPLAYSOUND3DRESID)GetProcAddress( hModuleTSMod, "Extern_PlaySound3DResID" );
		p_StopSound = (PFNSTOPSOUND)GetProcAddress( hModuleTSMod, "Extern_StopSound" );
		p_StopAllSound = (PFNSTOPALLSOUND)GetProcAddress( hModuleTSMod, "Extern_StopAllSound" );

		p_ChangeMidiMapper = (PFNCHANGEMIDIMAPPER)GetProcAddress( hModuleTSMod, "Extern_ChangeMidiMapper" );
	}


string getModuleResourceN6PWave() {
	// �������\�[�X�֘A�o�^
	struct stat  st;

	// �t�����ʉ��L�b�g�𓱓����Ă���΁c
	if (stat("n6pwav1.dll", &st) == 0) {
		return "n6pwav1.dll";

	// �ʏ��ԃV���[�Y�ł���΁c
	} else {
		return "n6pwav.dll";
	}

}

void _�������W���[���o�^() {

	string modulename = getModuleResourceN6PWave();

	// ���łɓǂݍ��܂�Ă���̂ŁA�n���h���𓾂�̂݁B
	hModuleResourceN6PWav=GetModuleHandle(modulename.c_str());
}



void _�������W���[������() {
	// ���[�U�[�o�^�̌��ʉ��p�c�k�k��S�ĉ��
	for ( map<string, HMODULE>::iterator it = mapHResistModuleHandle.begin(); it != mapHResistModuleHandle.end(); it++ ) {
		// ����HMODULE�����
		  FreeLibrary(it->second);
	}
}


namespace �֐� {


	BOOL Set_���ʉ��c�k�k�ǉ�(string ���ʉ��c�k�k��) {
		// �����񂪂킽���ĂȂ����B
		if (���ʉ��c�k�k��.empty()) {
			return FALSE;
		}

		HMODULE hModule = NULL;

		// �Y���̂c�k�k��ǂݍ���
		hModule = LoadLibrary(���ʉ��c�k�k��.c_str());

		if (!hModule) {
			string �G���[���b�Z�[�W = "�w��̌��ʉ��p��DLL:"+���ʉ��c�k�k��+"���ǂݍ��߂Ȃ�";
			MessageBox(NULL, �G���[���b�Z�[�W.c_str(), �G���[���b�Z�[�W.c_str(), NULL);
			return FALSE;
		}
		// �n�b�V���ɓo�^
		mapHResistModuleHandle.insert( map<string, HMODULE>::value_type(���ʉ��c�k�k��, hModule) );
		return TRUE;
	}


	// ���ʂɂQ�c�ł̉��̍Đ�(���\�[�X�ԍ����w�肷��^�C�v)
	���n���h���^ ���ʉ��Đ�( int ���ʉ�����, string ���ʉ��c�k�k��, BOOL ���[�v ) {
		// �����̐ݒ肪�L���ł���΁c
		if ( p���ݒ���.���ʉ� == ���ʉ�::�n�e�e ) {
			return 0;
		}

		// �f�t�H���g�͂�����
		if (���ʉ��c�k�k��.empty()) {

			if ( p_PlaySound2DResID ) {
				return p_PlaySound2DResID( ���ʉ�����, hModuleResourceN6PWav, ���[�v );
			// ����炷�B															�����͔񓯊�  �����\�[�X���
			}
			return 0;

		// ����̌��ʉ��Đ��́A���[�U�[�ɂ���Ăc�k�k���w�肳��Ă���B
		} else {
			HMODULE hModule = mapHResistModuleHandle[���ʉ��c�k�k��];

			if ( p_PlaySound2DResID ) {
				return p_PlaySound2DResID( ���ʉ�����, hModule, ���[�v );
			}
			return 0;
		}
	}

	// ���ʂɂQ�c�ł̉��̍Đ�(�t�@�C�������w�肷��^�C�v)
	���n���h���^ ���ʉ��Đ�( string �����t�@�C����, BOOL ���[�v ) {

		// �����̐ݒ肪�L���ł���΁c
		if ( p���ݒ���.���ʉ� == ���ʉ�::�n�e�e ) {
			return 0;
		}

		if ( p_PlaySound2DStr ) {
			return p_PlaySound2DStr( (char *)�����t�@�C����.c_str(), ���[�v );
		}
		return 0;
	}

	// �R�c�ł̉��̍Đ�(���\�[�X�ԍ����w�肷��^�C�v)
	���n���h���^ �R�c���ʉ��Đ�( int ���ʉ�����, string ���ʉ��c�k�k��, BOOL ���[�v, �R�c�ʒu�^ �ʒu, �R�c�x�N�g���^ �ړ��^���b) {
		// �����̐ݒ肪�L���ł���΁c
		if ( p���ݒ���.���ʉ� == ���ʉ�::�n�e�e ) {
			return 0;
		}

		// �f�t�H���g�͂�����
		if (���ʉ��c�k�k��.empty()) {

			if ( p_PlaySound3DResID ) {
				return p_PlaySound3DResID( ���ʉ�����, hModuleResourceN6PWav, ���[�v, �ʒu.�w, �ʒu.�x, �ʒu.�y,  �ړ��^���b.�w, �ړ��^���b.�x, �ړ��^���b.�y );
			// ����炷�B															
			}
			return 0;

		// ����̌��ʉ��Đ��́A���[�U�[�ɂ���Ăc�k�k���w�肳��Ă���B
		} else {
			HMODULE hModule = mapHResistModuleHandle[���ʉ��c�k�k��];

			if ( p_PlaySound3DResID ) {
				return p_PlaySound3DResID( ���ʉ�����, hModule, ���[�v, �ʒu.�w, �ʒu.�x, �ʒu.�y,  �ړ��^���b.�w, �ړ��^���b.�x, �ړ��^���b.�y );
			}
			return 0;
		}
	}

	// �R�c�ł̉��̍Đ�(�t�@�C�������w�肷��^�C�v)
	���n���h���^ �R�c���ʉ��Đ�( string �����t�@�C����, BOOL ���[�v, �R�c�ʒu�^ �ʒu, �R�c�x�N�g���^ �ړ��^���b) {
		// �����̐ݒ肪�L���ł���΁c
		if ( p���ݒ���.���ʉ� == ���ʉ�::�n�e�e ) {
			return 0;
		}

		if ( p_PlaySound3DStr ) {
			return p_PlaySound3DStr( (char *)�����t�@�C����.c_str(), ���[�v, �ʒu.�w, �ʒu.�x, �ʒu.�y,  �ړ��^���b.�w, �ړ��^���b.�x, �ړ��^���b.�y );
		}
		return 0;
	}

	// ScenarioMod����Đ������A�P�̌��ʉ����~����B
	void ���ʉ���~(���n���h���^ ���n���h��) {
		if ( p_StopSound ) {
			p_StopSound(���n���h��);
		}
	}

	// ScenarioMod����Đ������S���ʉ��̒�~
	void �S�Ă̌��ʉ���~() {
		if ( p_StopAllSound ) {
			return p_StopAllSound();
		}
	}

	void Set_�l�h�c�h�f�o�C�X(string �f�o�C�X��) {
		if ( p_ChangeMidiMapper ) {
			p_ChangeMidiMapper( (char *)�f�o�C�X��.c_str() );
		}
	}

}




