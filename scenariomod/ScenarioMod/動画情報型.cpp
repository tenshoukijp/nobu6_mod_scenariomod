#include <cassert>
#include "�Q�[���f�[�^�\��.h"
#include "���b�Z�[�W�֘A���^.h"

using namespace �֐�;

extern HMODULE hModuleTSMod;

using PFNFUNCPLAYMOVIE = void (WINAPI *)(char *szMovieName, BOOL isWithBlackBack);
PFNFUNCPLAYMOVIE p_FuncPlayMovie = NULL;

	// TSMod�ɂ����Ȃ�����Đ��֐��̃|�C���^�̓o�^
	void _����֐��o�^() {
		// �V�i���I�f�[�^�̈����o���p���\�b�h�̃|�C���^�m��
		p_FuncPlayMovie = (PFNFUNCPLAYMOVIE)GetProcAddress( hModuleTSMod, "Extern_FuncPlayMovie" );
	}


namespace �֐� {

	// �w��̃��[�r�[�Đ�����
	void ����Đ�(string ���於, int �I�v�V����) {

		if ( p_FuncPlayMovie ) {
			p_FuncPlayMovie((char *)���於.c_str(), �I�v�V���� );
		}
	}
}

