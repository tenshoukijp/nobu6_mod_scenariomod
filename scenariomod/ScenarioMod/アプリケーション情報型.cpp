
#include <string>

#include "�Q�[���f�[�^�\��.h"

using namespace std;
using namespace �֐�;

extern HMODULE hModuleTSMod;

using PFNADDMENUITEM = void (WINAPI *)(char *menuname, int position, int wID);
PFNADDMENUITEM p_AddMenuItem = NULL;

// �A�v���P�[�V�������^
void _�A�v���P�[�V�����֐��o�^() {
	// ���j���[�A�C�e���ǉ��B
	p_AddMenuItem = (PFNADDMENUITEM)GetProcAddress( hModuleTSMod, "Extern_AddMenuItem" );
}


static int _���j���[�X�^�[�g�ԍ� = 59000; // 59000�ԍ�����̃X�^�[�g

namespace �֐� {

	namespace �A�v���P�[�V���� {

		// �Ԃ�l�����j���[�A�C�e���Ɋ��蓖�Ă���ԍ�
		// ���̔ԍ����ǂ����ɕۑ����Ă����A�A�uOn_�A�v���P�[�V�����̃��j���[�A�C�e���̃N���b�N���v�ɔ���p�Ƃ��ė��p����B
		int ���j���[�A�C�e���ǉ�( string ���j���[������ ) {
			if (p_AddMenuItem) {
				p_AddMenuItem((char *)���j���[������.c_str(), NULL, _���j���[�X�^�[�g�ԍ�);
				return _���j���[�X�^�[�g�ԍ�++;
			}
			return -1;
		}
	}
}