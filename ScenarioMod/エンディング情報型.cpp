#include "�G���f�B���O���^.h"

#include <windows.h>

�G���f�B���O���^::�G���f�B���O���^(int �喼�ԍ�, string �G���f�B���O�^�C�g��, string �G���f�B���O���b�Z�[�W) {
	this->�喼�ԍ� = �喼�ԍ�;
	this->�G���f�B���O�^�C�g�� = �G���f�B���O�^�C�g��;
	this->�G���f�B���O���b�Z�[�W = �G���f�B���O���b�Z�[�W;
	this->m_�G���f�B���O�L���t���O = �G���f�B���O�t���O::�L��; // �L������
}

�G���f�B���O���^::�G���f�B���O���^(int �喼�ԍ�, �G���f�B���O�t���O �t���O) {
	this->�喼�ԍ� = 0xFFFF;
	this->�G���f�B���O�^�C�g�� = "";
	this->�G���f�B���O���b�Z�[�W = "";
	this->m_�G���f�B���O�L���t���O = �t���O;
}