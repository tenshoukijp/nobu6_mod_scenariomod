#include "�Q�[���f�[�^�\��.h"



using namespace System;
using namespace System::Drawing;

extern HWND tenshouWND;

//------------------------------------------------------


namespace �֐� {

	// �N���C�A���g��`��bmp�ւ̕ۑ�
	void �f�o�b�O�摜�o��(string �t�@�C����) {

		RECT rect;
		// �L���v�`�����邽�߂ɂ̓A�N�e�B�u�ɂ���K�v������(���̃E�B���h�E�ŉB��Ă��Ă����͂Ȃ����A�A�N�e�B�u�ł���K�v�͂���)
		::SetForegroundWindow(tenshouWND);

		// �E�B���h�E�g
		::GetWindowRect(tenshouWND, &rect);
		System::Drawing::Bitmap^ img = gcnew System::Drawing::Bitmap(rect.right - rect.left, rect.bottom - rect.top);
		// �C���[�W�I�u�W�F�N�g�ւ̃��t�@�����X���R���e�i�Ƃ��Ď��O���t�B�b�N�I�u�W�F�N�g���m��
		Graphics^ memg = Graphics::FromImage(img);
		// �O���t�B�b�N�X�@�\�Ƀf�o�C�X�R���e�L�X�g���A�^�b�`
		IntPtr dc = memg->GetHdc();
		// win32�`���g���̂ŕϊ�����
		HDC bmpDC = (HDC)dc.ToPointer();
		// �E�B���h�E�n���h���̃f�o�C�X�R���e�L�X�g
		HDC winDC = ::GetWindowDC(tenshouWND);
		// �E�B���h�E�n���h���̃f�o�C�X�R���e�L�X�g�̃C���[�W���������肻�̂܂܁A�O���t�B�b�N�X�I�u�W�F�N�g�̃f�o�C�X�R���e�L�X�g�ւƃR�s�[
		::BitBlt(bmpDC, 0, 0, img->Width, img->Height, winDC, 0, 0, SRCCOPY);
		// �O���t�B�b�N�X�@�\�̕��ɃA�^�b�`���Ă����f�o�C�X�R���e�L�X�g��j��
		memg->ReleaseHdc(dc);
		// �E�B���h�E�n���h���̃A�^�b�`�Ɏg���Ă����f�o�C�X�R���e�L�X�g���j��
		::ReleaseDC(tenshouWND, bmpDC);

		String^ filename = String��string(�t�@�C����);
		if (Is_���K�\���}�b�`(�t�@�C����, "\\.bmp$")) {
			img->Save(filename, System::Drawing::Imaging::ImageFormat::Bmp);
		}
		else if (Is_���K�\���}�b�`(�t�@�C����, "\\.jpe?g$")) {
			img->Save(filename, System::Drawing::Imaging::ImageFormat::Jpeg);
		}
		else if (Is_���K�\���}�b�`(�t�@�C����, "\\.png$")) {
			img->Save(filename, System::Drawing::Imaging::ImageFormat::Png);
		}
	}
}
