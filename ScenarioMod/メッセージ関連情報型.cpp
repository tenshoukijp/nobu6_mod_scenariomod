#define  _CRT_SECURE_NO_WARNINGS

#include <string>
#include <map>

#include "���b�Z�[�W�֘A���^.h"
#include "�f�o�b�O���^.h"

using namespace std;
using namespace �֐�;


extern HMODULE hModuleTSMod;

using PFNONIGMATCHALLOC = int (WINAPI *)(char *�Ώە�����, char *���K�\��������, int *���K�\���}�b�`����);
PFNONIGMATCHALLOC p_OnigMatchAlloc = NULL;

using PFNONIGMATCHFREE	= int (WINAPI *)(int *���K�\���}�b�`����);
PFNONIGMATCHFREE p_OnigMatchFree = NULL;

// TSMod�ɂ����Ȃ����K�\���֘A�̂̃|�C���^�̓o�^
void _���K�\���֐��o�^() {
	p_OnigMatchAlloc = (PFNONIGMATCHALLOC)GetProcAddress( hModuleTSMod, "Extern_OnigMatchAlloc" );
	p_OnigMatchFree = (PFNONIGMATCHFREE)GetProcAddress( hModuleTSMod, "Extern_OnigMatchFree" );
}


// ���K�\���}�b�`���O�p�̊֐�

namespace �֐� {

	BOOL Is_������}�b�`(  string �Ώە�����, string ���������� ) {
		return �Ώە�����.find(����������) != string::npos;
	}


	BOOL Is_���K�\���}�b�`(  string �Ώە�����, string ���K�\��������, ���K�\���}�b�`���ʌ^* ���K�\���}�b�`���� ) {

		// �܂��A�������ʂ͍폜
		if ( ���K�\���}�b�`���� ) {
			���K�\���}�b�`����->clear();
		}

		// �ǂ��炩�����g����Ȃ�Afalse��Ԃ��B
		if ( �Ώە�����.length() == 0 || ���K�\��������.length() == 0 ) {
			return false;
		}

		if ( p_OnigMatchAlloc ) {

			int matches[100] = {0};

			int ret = false;

			// ���K�\���}�b�`���ʂ��s�v�Ȃ�΁ANULL�ɂ��Ă����B
			if ( ���K�\���}�b�`���� ) {
				ret = p_OnigMatchAlloc( (char *)�Ώە�����.c_str(), (char *)���K�\��������.c_str(), matches );
			} else {
				ret = p_OnigMatchAlloc( (char *)�Ώە�����.c_str(), (char *)���K�\��������.c_str(), 0 );
			}

			// ���ʂ��i�[����Ă���B
			if ( matches ) {
				// �\���h�~�̂��߁B������Ȃ�ł�100�J�b�R�Ƃ��Ȃ��ł���B
				for (int i=0; i<sizeof(matches)/sizeof(matches[0]); i++) {
					int address = matches[i];
					if (address == 0xFFFF) { // �I���̔ԕ��B�R�s�[�I��
						break;
					}
					// �L���ȃA�h���X�ł���΁A��������w�����Ă���B
					if (address) {
						string cp = string((char *)address); // ������Ƃ��ăR�s�[
						���K�\���}�b�`����->insert( ���K�\���}�b�`���ʌ^::value_type( i, cp ) );
					}
				}
			}


			// ���̉���͕K�{
			if ( p_OnigMatchFree ) {
				p_OnigMatchFree(matches);
			}

			return ret;
		}

		return false; // �֐����Ȃ�
	}

} // namespace