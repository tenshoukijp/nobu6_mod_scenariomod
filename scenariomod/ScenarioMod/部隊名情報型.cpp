#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <cassert>
#include "�Q�[���f�[�^�\��.h"
#include <string>


extern char g�������������[11];

namespace �֐� {
	void Set_����������(���������X�g�^�� ���������X�g�ϐ�, char *sprintf����) {
		strncpy(g�������������, sprintf����, 10);
		g�������������[10] = NULL;
	}
}