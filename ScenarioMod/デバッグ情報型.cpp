#define _CRT_SECURE_NO_WARNINGS

#include "�Q�[���f�[�^�\��.h"


// OutputDebugString�ւƃt�H�[�}�b�g(printf)�`���𗘗p���ďo�͂���B
char szBufOutputDebugStream[4096];



//------------------------------------------------------


namespace �֐� {

	�f�o�b�O�X�g���[���^ �f�o�b�O�o��;

	// String^ �^��OutputDebugStream�ɑΉ�������B
	�f�o�b�O�X�g���[���^& operator << (�f�o�b�O�X�g���[���^& os, System::String^ str) {
		string msg = string��String(str);
		os << msg;
		return os;
	}

}


