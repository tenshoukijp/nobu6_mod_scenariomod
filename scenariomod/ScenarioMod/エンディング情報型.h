/*
* ���ʉ����^
*/
#pragma once
#pragma pack(1)

#include <string>
#include <windows.h>

using namespace std;

enum �G���f�B���O�t���O {
	�L�� = 0, ���� = 1
};

struct �G���f�B���O���^ {

public:
	int �喼�ԍ�;
	string �G���f�B���O�^�C�g��;
	string �G���f�B���O���b�Z�[�W;
	BOOL m_�G���f�B���O�L���t���O;

	/// <summary>
	/// �G���f�B���O�̏����Z�b�e�B���O����B
	/// </summary>
	/// <param name="�喼�ԍ�">�喼�ԍ��BOn_�G���f�B���O���莞(int �喼�ԍ�)�œn���Ă����l�����̂܂ܐݒ肷��B</param>
	/// <param name="�G���f�B���O�^�C�g��">�G���f�B���O�B�����ɏo��_�C�A���O�̃^�C�g��������B�ő�S�p�V����</param>
	/// <param name="�G���f�B���O���b�Z�[�W">�G���f�B���O�B�����ɏo��_�C�A���O�̃G���f�B���O���b�Z�[�W������B�ő�S�p�Q�P����</param>
	�G���f�B���O���^(int �喼�ԍ�, string �G���f�B���O�^�C�g�� = "", string �G���f�B���O���b�Z�[�W = "");

	/// <summary>
	/// �G���f�B���O�̏����Z�b�e�B���O����B
	/// </summary>
	/// <param name="�喼�ԍ�">�喼�ԍ��BOn_�G���f�B���O���莞(int �喼�ԍ�)�œn���Ă����l�����̂܂ܐݒ肷��B</param>
	/// <param name="�t���O">�G���f�B���O�t���O::���� �������� �G���f�B���O�t���O::�L���̒l������B����́uOn_�G���f�B���O���莞�v����ł͂����Ȃ�G���f�B���O�����������Ȃ����ɗ��p����B</param>
	�G���f�B���O���^(int �喼�ԍ�, �G���f�B���O�t���O �t���O);
};

using �G���f�B���O���^�� = �G���f�B���O���^;

