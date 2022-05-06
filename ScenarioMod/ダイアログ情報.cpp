#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <cassert>
#include "�Q�[���f�[�^�\��.h"
#include <mmsystem.h>
#include <map>

extern HWND tenshouWND;
extern HMODULE hModuleTSMod;

// ���[�U�ǉ��^��DLL�B�uDLL����DLL�n���h���v�̃n�b�V���B
extern map<string, HMODULE> mapHResistModuleHandle;


using PFNOPENIMAGEDIALOG			= int (WINAPI *)(char *szTargetName, int posX, int posY, int iTime);
PFNOPENIMAGEDIALOG p_OpenImageDialog = NULL;

using PFNSTARTIMAGEDIALOG			= int (WINAPI *)(char *szTargetName, int posX, int posY);
PFNSTARTIMAGEDIALOG p_StartImageDialog = NULL;

using PFNENDIMAGEDIALOG				= int (WINAPI *)();
PFNENDIMAGEDIALOG p_EndImageDialog = NULL;

using PFNOPENRESOURCEIMAGEDIALOG	= int (WINAPI *)(char *szTargetName, HMODULE hModule, int posX, int posY, int iTime);
PFNOPENRESOURCEIMAGEDIALOG p_OpenResourceImageDialog = NULL;

using PFNSTARTRESOURCEIMAGEDIALOG	= int (WINAPI *)(char *szTargetName, HMODULE hModule, int posX, int posY);
PFNSTARTRESOURCEIMAGEDIALOG p_StartResourceImageDialog = NULL;

using PFNENDRESOURCEIMAGEDIALOG		= int (WINAPI *)();
PFNENDRESOURCEIMAGEDIALOG p_EndResourceImageDialog = NULL;

using PFNFUNCNORMALFUKIDASHIMESSAGE = void (WINAPI *)(int iBushouID, char *szMessage);
PFNFUNCNORMALFUKIDASHIMESSAGE p_FuncLeftNormalFukidashiMessage = NULL;
PFNFUNCNORMALFUKIDASHIMESSAGE p_FuncRightNormalFukidashiMessage = NULL;
PFNFUNCNORMALFUKIDASHIMESSAGE p_FuncLeftNormalFukidashiUpdate = NULL;
PFNFUNCNORMALFUKIDASHIMESSAGE p_FuncRightNormalFukidashiUpdate = NULL;

using PFNFUNCNORMALFUKIDASHIDELETE  = void(WINAPI *)();
PFNFUNCNORMALFUKIDASHIDELETE p_FuncLeftNormalFukidashiDelete = NULL;
PFNFUNCNORMALFUKIDASHIDELETE p_FuncRightNormalFukidashiDelete = NULL;

using PFNFUNCSENJOFUKIDADIALOG		= void (WINAPI *)(int iBushouID, char *szMessage);
PFNFUNCSENJOFUKIDADIALOG p_FuncSenjoFukidashiDialog = NULL;

// TSMod�ɂ����Ȃ�����Đ��֐��̃|�C���^�̓o�^
void _�_�C�A���O�֐��o�^() {
	// �K�v�s���l���㏑������B
	p_OpenImageDialog = (PFNOPENIMAGEDIALOG)GetProcAddress( hModuleTSMod, "Extern_OpenImageDialog" );
	p_StartImageDialog = (PFNSTARTIMAGEDIALOG)GetProcAddress( hModuleTSMod, "Extern_StartImageDialog" );
	p_EndImageDialog = (PFNENDIMAGEDIALOG)GetProcAddress( hModuleTSMod, "Extern_EndImageDialog" );
	p_OpenResourceImageDialog = (PFNOPENRESOURCEIMAGEDIALOG)GetProcAddress( hModuleTSMod, "Extern_OpenResourceImageDialog" );
	p_StartResourceImageDialog = (PFNSTARTRESOURCEIMAGEDIALOG)GetProcAddress( hModuleTSMod, "Extern_StartResourceImageDialog" );
	p_EndResourceImageDialog = (PFNENDRESOURCEIMAGEDIALOG)GetProcAddress( hModuleTSMod, "Extern_EndResourceImageDialog" );
	p_FuncLeftNormalFukidashiMessage  = (PFNFUNCNORMALFUKIDASHIMESSAGE)GetProcAddress( hModuleTSMod, "Extern_FuncLeftNormalFukidashiMessage" );
	p_FuncRightNormalFukidashiMessage = (PFNFUNCNORMALFUKIDASHIMESSAGE)GetProcAddress( hModuleTSMod, "Extern_FuncRightNormalFukidashiMessage" );
	p_FuncLeftNormalFukidashiUpdate  = (PFNFUNCNORMALFUKIDASHIMESSAGE)GetProcAddress( hModuleTSMod, "Extern_FuncLeftNormalFukidashiUpdate" );
	p_FuncRightNormalFukidashiUpdate = (PFNFUNCNORMALFUKIDASHIMESSAGE)GetProcAddress( hModuleTSMod, "Extern_FuncRightNormalFukidashiUpdate" );
	p_FuncLeftNormalFukidashiDelete  = (PFNFUNCNORMALFUKIDASHIDELETE)GetProcAddress( hModuleTSMod, "Extern_FuncLeftNormalFukidashiDelete" );
	p_FuncRightNormalFukidashiDelete = (PFNFUNCNORMALFUKIDASHIDELETE)GetProcAddress( hModuleTSMod, "Extern_FuncRightNormalFukidashiDelete" );
	p_FuncSenjoFukidashiDialog = (PFNFUNCSENJOFUKIDADIALOG)GetProcAddress( hModuleTSMod, "Extern_FuncSenjoFukidashiDialog" );
}


BOOL _isDoingDialog = FALSE;

	char _sz�_�C�A���O������[255] = "";
	char * _psz�_�C�A���O������ = _sz�_�C�A���O������;


/* // �t���[���p�̃_�C�A���O
0043666B  |> 68 FFFF0000    PUSH    0FFFF
00436670  |. 6A 01          PUSH    1
00436672  |. 68 C0974D00    PUSH    TENSHOU.004D97C0                                  ;  ASCII "���M�j����
������Ԃ���񕜂��܂���"
00436677  |. E8 23E30600    CALL    TENSHOU.004A499F
0043667C  |. 83C4 0C        ADD     ESP, 0C
*/


	//---------------------�퓬���Ȃǂŗǂ��ł�t���[���_�C�A���O-------------------------
	int pCallFromFuncInfoFrameDialog = 0x4A499F; // ���XTENSHOU.EXE���ɂ�����CALL��

	void _FuncInfoFrameDialogAsm() {

		__asm {
			// ����1�`3 2�o�C�g����
			push 0xffff;
			push 1;

			// ����4 ������ւ̃|�C���^(�|�C���^=4�o�C�g)
			push _psz�_�C�A���O������;
			call pCallFromFuncInfoFrameDialog
			// �X�^�b�N�����ꍞ�񂾕�(2*3+4 = 10)
			add  esp, 0xC
		}

	}

namespace �֐� {

	void ���t���[���_�C�A���O�\��(string �_�C�A���O������) {

		_isDoingDialog = TRUE;
		strcpy_s( _sz�_�C�A���O������, �_�C�A���O������.c_str() );

		__asm {
			push eax
			push ebx
			push ecx
			push edx
			push esp
			push esi
			push edi
		}

		// TENSHOU.EXE���̊֐��Ăяo��
		_FuncInfoFrameDialogAsm();

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}
		_isDoingDialog = FALSE;
	}
}


	//---------------------��ґI���_�C�A���O-------------------------
	int pCallFromFuncOKCancelDialogAsm = 0x4A18D0; // ���XtenshouWNDTENSHOU.EXE���ɂ�����CALL��
	int _iResultOfFuncOKCancelDialog = 0;
	void _FuncOKCancelDialogAsm() {
		__asm {
			// ����1�`3 2�o�C�g����
			// ����4 ������ւ̃|�C���^(�|�C���^=4�o�C�g)
			push _psz�_�C�A���O������;
			call pCallFromFuncOKCancelDialogAsm
			// �X�^�b�N�����ꍞ�񂾕�(2*3+4 = 10)
			add  esp, 4
			mov _iResultOfFuncOKCancelDialog, eax;
		}

	}

namespace �֐� {
	int ���s�^����_�C�A���O�\��(string �_�C�A���O������) {
		_isDoingDialog = TRUE;

		strcpy_s( _sz�_�C�A���O������, �_�C�A���O������.c_str() );

		__asm {
			push eax
			push ebx
			push ecx
			push edx
			push esp
			push esi
			push edi
		}

		// TENSHOU.EXE���̊֐��Ăяo��
		_FuncOKCancelDialogAsm();

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}

		_isDoingDialog = FALSE;
		// �ԓ���Yes��������No���������Ԃ��B
		return _iResultOfFuncOKCancelDialog;
	}
}



	//---------------------���ʂɏ����Ă��܂��_�C�A���O-------------------------
	int _pCallFromFuncInfoDialogAsm = 0x4A1855; // ���XTENSHOU.EXE���ɂ�����CALL��

	void _FuncInfoDialogAsm() {
		__asm {
			// ����1�`3 2�o�C�g����
			push word ptr 0xffff;
			push word ptr 0xffff;
			push word ptr 0xffff;
			// ����4 ������ւ̃|�C���^(�|�C���^=4�o�C�g)
			push _psz�_�C�A���O������;
			call _pCallFromFuncInfoDialogAsm
			// �X�^�b�N�����ꍞ�񂾕�(2*3+4 = 10)
			add  esp, 10
		}

	}

namespace �֐� {
	void ���_�C�A���O�\��(string �_�C�A���O������) {
		_isDoingDialog = TRUE;

		strcpy_s( _sz�_�C�A���O������, �_�C�A���O������.c_str() );

		__asm {
			push eax
			push ebx
			push ecx
			push edx
			push esp
			push esi
			push edi
		}

		// TENSHOU.EXE���̊֐��Ăяo��
		_FuncInfoDialogAsm();

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}

		_isDoingDialog = FALSE;
	}
}
//---------------------�m�F�����܂ŏ����Ȃ��_�C�A���O-------------------------
	int _pCallFromFuncConfirmDialogAsm = 0x4A187A; // ���XTENSHOU.EXE���ɂ�����CALL��

	void _FuncConfirmDialogAsm() {

		__asm {
			// ����1�`3 2�o�C�g����
			push word ptr 0xffff;
			push word ptr 0xffff;
			push word ptr 0xffff;
			// ����4 ������ւ̃|�C���^(�|�C���^=4�o�C�g)
			push _psz�_�C�A���O������;
			call _pCallFromFuncConfirmDialogAsm
			// �X�^�b�N�����ꍞ�񂾕�(2*3+4 = 10)
			add  esp, 10
		}

	}

namespace �֐� {
	void �m�F�_�C�A���O�\��(string �_�C�A���O������) {
		_isDoingDialog = TRUE;

		strcpy_s( _sz�_�C�A���O������, �_�C�A���O������.c_str() );

		__asm {
			push eax
			push ebx
			push ecx
			push edx
			push esp
			push esi
			push edi
		}

		// TENSHOU.EXE���̊֐��Ăяo��
		_FuncConfirmDialogAsm();

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}

		_isDoingDialog = FALSE;
	}
}

	//---------------------�x���n�����Ă��܂��_�C�A���O-------------------------
	int _pCallFromFuncAssertDialog = 0x4A1831; // ���XTENSHOU.EXE���ɂ�����CALL��

	void _FuncAssertDialogAsm() {

		__asm {
			// ����1�`3 2�o�C�g����
			push word ptr 0xffff;
			push word ptr 0xffff;
			push word ptr 0xffff;
			// ����4 ������ւ̃|�C���^(�|�C���^=4�o�C�g)
			push _psz�_�C�A���O������;
			call _pCallFromFuncAssertDialog
			// �X�^�b�N�����ꍞ�񂾕�(2*3+4 = 10)
			add  esp, 10
		}

	}

namespace �֐� {
	void �x���_�C�A���O�\��(string �_�C�A���O������) {
		_isDoingDialog = TRUE;

		strcpy_s( _sz�_�C�A���O������, �_�C�A���O������.c_str() );

		__asm {
			push eax
			push ebx
			push ecx
			push edx
			push esp
			push esi
			push edi
		}

		// TENSHOU.EXE���̊֐��Ăяo��
		_FuncAssertDialogAsm();

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}

		_isDoingDialog = FALSE;
	}
}




/*
00419AF4  |. 33DB           XOR     EBX, EBX
00419AF6  |. BF FFFF0000    MOV     EDI, 0FFFF
00419AFB  |> 53             /PUSH    EBX                             ; /Arg7				�� 0 �Œ�
00419AFC  |. 6A 70          |PUSH    70                              ; |Arg6 = 00000070		�H
00419AFE  |. 53             |PUSH    EBX                             ; |Arg5
00419AFF  |. 68 A0B64C00    |PUSH    TENSHOU.004CB6A0                ; |Arg4 = 004CB6A0		������|�C���^�̔z��̃A�h���X
00419B04  |. 6A 03          |PUSH    3                               ; |Arg3 = 00000003		�I�����̐�
00419B06     68 A0000000    PUSH    0A0														�x���W
00419B0B     68 18020000    PUSH    118														�w���W
00419B10  |. E8 6C920800    |CALL    TENSHOU.004A2D81                ; \TENSHOU.004A2D81
00419B15  |. 83C4 1C        |ADD     ESP, 1C


RETURN�ł���EAX�͑I��������0, 1, 2,...
�I�����Ȃ������ꍇ(�E�N���b�N�Ȃ�) 0xFFFF ��EAX�ɓ���B
*/

// ���j���[�̐��̍ő�
#define SELECT_MENU_NUM_MAX  36

// �P�̃��j���[�̒��̕�����̍ő�͑S�p�R�P�����B���p63
#define SELECT_MENU_STRING_LENGTH_MAX	64

char *pSelectMenuStringArrayPointer[SELECT_MENU_NUM_MAX] = {NULL}; // ���j���[�͍ő�łR�U�B������͊i���j���[������ւ̃|�C���^�z��
// �ƕ��ނ̃J�X�^��������

// �P�̃Z���N�g���j���[�^
struct SELECT_MENU {
	char szKahouTypeString[SELECT_MENU_STRING_LENGTH_MAX];
};
SELECT_MENU select_menu_string[SELECT_MENU_NUM_MAX] = {""}; // �e�X�̕����񃁃j���[


//---------------------�����ڑI�����_�C�A���O-------------------------
int pCallFromFuncSelectMenuDialogAsm = 0x4A2D81; // ���XTENSHOU.EXE���ɂ�����CALL��
int iResultOfFuncSelectMenuDialog = 0;	// �I������
int iXPosOfSelectMenuDialog = 0xA0;		// �w���W 
int iYPosOfSelectMenuDialog = 0x118;	// �x���W
int iMenuNumOfSelectMenuDialog = 3;		// ���j���[�̌�
int iMenuMinWidthOfSelectMenuDialog = 0x70; // ���j���̍Œᕝ

int iSelectMenuStringArrayPointerOfSelectMenuDialog = 0x4CB6A0; // �f�t�H���g�͔�I�̔z��

void _FuncSelectMenuDialogAsm() {
	__asm {
		push 0xF
		push iMenuMinWidthOfSelectMenuDialog // �����炭���j���[�̍Œᕝ
		push 0
		push iSelectMenuStringArrayPointerOfSelectMenuDialog
		push iMenuNumOfSelectMenuDialog
		push iYPosOfSelectMenuDialog
		push iXPosOfSelectMenuDialog

		call pCallFromFuncSelectMenuDialogAsm

		mov iResultOfFuncSelectMenuDialog, eax;

		pop eax
		pop eax
		pop eax
		pop eax
		pop eax
		pop eax
		pop eax

		mov eax, iResultOfFuncSelectMenuDialog;
	}

}

bool isInitSelectMenuPointer = false; // ���������t���O
void _InitSelectMenuPointer() {
	if ( !isInitSelectMenuPointer ) {
		// �ŏ��Ɋe�X�̕�����̃|�C���^�͎w���Ă���
		for ( int i=0; i<SELECT_MENU_NUM_MAX; i++ ) {
			pSelectMenuStringArrayPointer[i] = select_menu_string[i].szKahouTypeString;
		}

		// �|�C���^�̔z��̐擪�̃A�h���X��int�^�Ƃ��čT���Ă����B���j���[�_�C�A���O�ɂ͂��̒l��n���K�v������B
		iSelectMenuStringArrayPointerOfSelectMenuDialog = (int)pSelectMenuStringArrayPointer;

		isInitSelectMenuPointer = true;
	}
}



int _SelectMenuDialog(vector<string> menu_list, int posX, int posY) {

	// ���j���[�̌����ő吔�𒴂��Ă���΁A
	if ( menu_list.size() > SELECT_MENU_NUM_MAX ) {
		return 0xFFFF; // �������������̂Ɠ������ƂƂ���B
	}
	// ���j���[���̂P�����݂��Ȃ��B
	if ( menu_list.size() == 0 ) {
		return 0xFFFF; // �������������̂Ɠ������ƂƂ���B
	}

	_InitSelectMenuPointer();

	// ���j���[�̌����T���Ă���
	iMenuNumOfSelectMenuDialog = menu_list.size();
	// ���j���[�����A�ő吔���I�[�o�[���Ă�����A�ő吔�ɒ���
	if ( iMenuNumOfSelectMenuDialog > SELECT_MENU_NUM_MAX ) { iMenuNumOfSelectMenuDialog = SELECT_MENU_NUM_MAX; }

	// ��Ԓ���������T���B
	int max_string_length = iMenuMinWidthOfSelectMenuDialog/8; // �_�C�A���O�̍Œᕝ�𔼊p�����̕��Ŋ������l

	// �e���j���[�̕�������A�O���[�o���ϐ��ɃR�s�[���Ă���
	for ( int i=0; i < iMenuNumOfSelectMenuDialog ; i++ ) {

		strncpy( select_menu_string[i].szKahouTypeString, menu_list[i].c_str(), SELECT_MENU_STRING_LENGTH_MAX);

		// ��ԍŌ��NULL�ɂ��Ĉ��S��
		select_menu_string[i].szKahouTypeString[SELECT_MENU_STRING_LENGTH_MAX-1] = NULL;

		// ��Ԓ��������X�V�`�F�b�N
		int cur_len = strlen( menu_list[i].c_str() );
		if ( max_string_length < cur_len ) {
			max_string_length = cur_len;
		}

	}

	RECT rc; // �N���C�A���g�̈�̃T�C�Y
	::GetClientRect(tenshouWND, &rc);

	int width = rc.right-rc.left;
	int height = rc.bottom-rc.top;

	// �w�肳��Ă��Ȃ� �� ������
	if ( posX == -1 ) {
		int left = width/2 - 4*(max_string_length); // �����ɂȂ�悤�ɍ����v�Z�B�i�ő�̕����񐔁j���W�^�Q�̃s�N�Z���� �^�񒆂�荶�ɔz�u 
		iXPosOfSelectMenuDialog = left;
	} else {
		iXPosOfSelectMenuDialog = posX;
	}

	// �w�肳��Ă��Ȃ� �� ������
	if ( posY == -1 ) {
		int top = height/2 - 8*(iMenuNumOfSelectMenuDialog+1); // �����ɂȂ�悤�Ƀg�b�v���v�Z�B�i���j���[���{�P�j���P�U�^�Q�̃s�N�Z���� �^�񒆂���ɔz�u 
		iYPosOfSelectMenuDialog = top;
	} else {
		iYPosOfSelectMenuDialog = posY;
	}

	__asm {
		push eax
		push ebx
		push ecx
		push edx
		push esp
		push esi
		push edi
	}

	// TENSHOU.EXE���̊֐��Ăяo��
	_FuncSelectMenuDialogAsm();

	__asm {
		pop edi
		pop esi
		pop esp
		pop edx
		pop ecx
		pop ebx
		pop eax
	}

	// ���ʂ�Ԃ��B
	return iResultOfFuncSelectMenuDialog;
}


namespace �֐� {

int �I�����j���[�_�C�A���O�\��(�����񃊃X�g�^ �����񃊃X�g, int �w���W, int �x���W) {
	return _SelectMenuDialog(�����񃊃X�g, �w���W, �x���W);
}

}



namespace �֐� {

BOOL Set_�摜�c�k�k�ǉ�(string �摜�c�k�k��) {
	// �����񂪂킽���ĂȂ����B
	if (�摜�c�k�k��.empty()) {
		return FALSE;
	}

	HMODULE hModule = NULL;

	// �Y���̂c�k�k��ǂݍ���
	hModule = LoadLibrary(�摜�c�k�k��.c_str());

	if (!hModule) {
		string �G���[���b�Z�[�W = "�w��̉摜�p��DLL:"+�摜�c�k�k��+"���ǂݍ��߂Ȃ�";
		MessageBox(NULL, �G���[���b�Z�[�W.c_str(), �G���[���b�Z�[�W.c_str(), NULL);
		return FALSE;
	}
	// �n�b�V���ɓo�^
	mapHResistModuleHandle.insert( map<string, HMODULE>::value_type(�摜�c�k�k��, hModule) );
	return TRUE;
}


int �摜�_�C�A���O�\��(string �摜�t�@�C����, int �w���W, int �x���W, int �I���^�C��) {
	if ( p_OpenImageDialog ) {
		return p_OpenImageDialog( (char *)�摜�t�@�C����.c_str(), �w���W, �x���W, �I���^�C�� );
	}
	return FALSE;
}

int �摜�_�C�A���O�\��(string �摜�t�@�C����, string �摜�c�k�k��, int �w���W, int �x���W, int �I���^�C��) {
	HMODULE hModule = mapHResistModuleHandle[�摜�c�k�k��];
	if ( hModule && p_OpenResourceImageDialog ) {
		return p_OpenResourceImageDialog( (char *)�摜�t�@�C����.c_str(), hModule, �w���W, �x���W, �I���^�C�� );
	}
	return FALSE;
}


void ���o�_�C�A���O�s�ʏ�E����t�J�n(int �����ԍ��y�z��p�z, string ���b�Z�[�W ) {
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) { 

		if ( p_FuncLeftNormalFukidashiMessage ) {
			p_FuncLeftNormalFukidashiMessage(�����ԍ��y�z��p�z, (char *)���b�Z�[�W.c_str() );
		}
	} else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
	}
}

void ���o�_�C�A���O�s�ʏ�E�E���t�J�n(int �����ԍ��y�z��p�z, string ���b�Z�[�W ) {
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) { 

		if ( p_FuncRightNormalFukidashiMessage ) {
			p_FuncRightNormalFukidashiMessage(�����ԍ��y�z��p�z, (char *)���b�Z�[�W.c_str() );
		}
	} else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
	}
}


void ���o�_�C�A���O�s�ʏ�E����t�X�V(int �����ԍ��y�z��p�z, string ���b�Z�[�W ) {
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) { 

		if ( p_FuncLeftNormalFukidashiUpdate ) {
			p_FuncLeftNormalFukidashiUpdate(�����ԍ��y�z��p�z, (char *)���b�Z�[�W.c_str() );
		}
	} else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
	}
}

void ���o�_�C�A���O�s�ʏ�E�E���t�X�V(int �����ԍ��y�z��p�z, string ���b�Z�[�W ) {
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) { 

		if ( p_FuncRightNormalFukidashiUpdate ) {
			p_FuncRightNormalFukidashiUpdate(�����ԍ��y�z��p�z, (char *)���b�Z�[�W.c_str() );
		}
	} else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
	}
}

void ���o�_�C�A���O�s�ʏ�E����t�I��() {
	if ( p_FuncLeftNormalFukidashiDelete ) {
		p_FuncLeftNormalFukidashiDelete();
	}
}

void ���o�_�C�A���O�s�ʏ�E�E���t�I��() {
	if ( p_FuncRightNormalFukidashiDelete ) {
		p_FuncRightNormalFukidashiDelete();
	}
}

}


namespace �֐� {

	// 
	BOOL isOnSenjoFukidashiDialog = FALSE;
	void ���o�_�C�A���O�s���E�����t�\��(int �����ԍ��y�z��p�z, string ���b�Z�[�W) {

		if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) { 
			if ( p_FuncSenjoFukidashiDialog ) {
				p_FuncSenjoFukidashiDialog( �����ԍ��y�z��p�z, (char *)���b�Z�[�W.c_str() );
			}
		} else {
			�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
		}
	}

}



//----------------------------------�喼�I���_�C�A���O
/*
0042534D  /$ FF7424 08      PUSH    DWORD PTR SS:[ESP+8]
00425351  |. 8B4C24 08      MOV     ECX, DWORD PTR SS:[ESP+8]
00425355  |. E8 63010500    CALL    TENSHOU.004754BD
0042535A  |. 33C0           XOR     EAX, EAX
0042535C  |. 50             PUSH    EAX
0042535D  |. 50             PUSH    EAX
0042535E  |. 6A 08          PUSH    8
00425360  |. 6A 02          PUSH    2
00425362  |. 50             PUSH    EAX
00425363  |. 68 9F071103    PUSH    311079F
00425368  |. E8 031D0400    CALL    TENSHOU.00467070
0042536D  |. 50             PUSH    EAX                              ; |Arg2
0042536E  |. 68 D8A54D00    PUSH    TENSHOU.004DA5D8                 ; |Arg1 = 004DA5D8
00425373  |. E8 F7D10200    CALL    TENSHOU.0045256F                 ; \TENSHOU.0045256F
00425378  |. 66:A3 FCE54B00 MOV     WORD PTR DS:[4BE5FC], AX
0042537E  |. 83C4 20        ADD     ESP, 20
00425381  \. C3             RETN
*/

/*
00415B93  |> 33C0           XOR     EAX, EAX
00415B95  |. B9 FFFF0000    MOV     ECX, 0FFFF
00415B9A  |. 50             PUSH    EAX
00415B9B  |. 50             PUSH    EAX
00415B9C  |. 51             PUSH    ECX
00415B9D  |. 51             PUSH    ECX
00415B9E  |. 50             PUSH    EAX
00415B9F  |. 68 9F071103    PUSH    311079F
00415BA4  |. E8 C7140500    CALL    TENSHOU.00467070
00415BA9  |. 50             PUSH    EAX                              ; |Arg2
00415BAA  |. 68 D8A54D00    PUSH    TENSHOU.004DA5D8                 ; |Arg1 = 004DA5D8
00415BAF  |. E8 BBC90300    CALL    TENSHOU.0045256F                 ; \TENSHOU.0045256F
00415BB4  |. 66:8BD8        MOV     BX, AX   �� AX���I��喼�ԍ�

*/

//---------------------�I��喼�_�C�A���O-------------------------
int pCallFromFuncSelectDaimyoDialog = 0x45256F; // ���XTENSHOU.EXE���ɂ�����CALL��
int pCallFromFuncSelectDaimyoDialogSub = 0x467070; // ���XTENSHOU.EXE���ɂ�����CALL��
int iDaimyoIDOfSelectDaimyoDialog = -1; // ��ςƂȂ�iDaimyoID�B�F�D�l�Ȃǂ�����̂ŁA��ϑ喼���K�v�B
int iReturnOfSelectDaimyoDialog = 0; // �Ԃ�l�Beax�̕����̂ݍ̗p����B
int iFilterOptionOfSelectDaimyoDialog = �J����::�喼::�f�t�H���g; // �t�B���^�[�I�v�V����
WORD iArrayOfDaimyoList[�ő吔::�喼���::�z��+1] = {0}; // �\������ΏۂƂȂ�喼���X�g�ԍ��B�Ō��0xFFFF�ŏI���Ƃ݂Ȃ��̂�+1�B

void _SelectDaimyoDialogAsm() {

	__asm {
		xor eax, eax
		mov ecx, 0xFFFF
	
		push eax      // �ʂ̂��� 0 
		push eax	  //            0 
		push ecx	  //            8 
		push ecx	  //            2 
		push 0x4001	  //            0 
		push iFilterOptionOfSelectDaimyoDialog

		// call pCallFromFuncSelectDaimyoDialogSub // �����̑喼���͂̔ԍ���eax�ɃZ�b�g
		mov eax, iDaimyoIDOfSelectDaimyoDialog
		push eax
		push 0x4DA5D8 // WORD�ő喼�̔ԍ��̔z����i�[���Ă�ꏊ�B�Ō�0xFFFF

		call pCallFromFuncSelectDaimyoDialog

		mov iReturnOfSelectDaimyoDialog, eax

		add  esp, 0x20
	}
}

// �ΏۂƂȂ�喼���X�g�B
int _SelectDaimyoDialog(vector<int> list, int iFilterOption, int iMainDaimyoID ) {

	// ���X�g�������Ȃ�Ȃɂ����Ȃ��B
	if ( list.size() == 0 ) {
		return 0xFFFF;
	}
	if ( iMainDaimyoID == -1 ) {
		iMainDaimyoID = p�^�[�����.���݂̃^�[���y�喼�ԍ��z-1;
	}
	if ( !(0 <= iMainDaimyoID && iMainDaimyoID < �ő吔::�喼���::�z�� ) ) {
		return 0xFFFF;
	}
	iDaimyoIDOfSelectDaimyoDialog = iMainDaimyoID+1;

	// �n���ꂽvector�`���̃��X�g��WORD�`���̔z��ւ̃R�s�[���Ă����B
	WORD *pCopy = iArrayOfDaimyoList;
	// �喼�̃��X�g��z��`���ɂ���B
	for ( vector<int>::iterator it=list.begin(); it != list.end(); it++ ) {

		int iDaimyoID = *it;
		// �͈͊O�͖���
		if ( ! (0 <= iDaimyoID && iDaimyoID < �ő吔::�喼���::�z��) ) {
			continue;
		}
		// �喼�����Ȃ��ԍ��͖���
		if ( p�喼���[iDaimyoID].�喼�y�����ԍ��z == 0xFFFF ) {
			continue; // �P�ł������Ȃ��̂�����΂����A�E�g
		}
		
		*pCopy = (WORD)iDaimyoID+1;
		pCopy++;
	}
	
	// �R�s�[�σ|�C���^���P���i��ł��Ȃ��B==�P���L���ȑ喼�����Ȃ�����
	if ( pCopy == iArrayOfDaimyoList ) {
		return 0xFFFF;
	}

	*pCopy = 0xFFFF; // �Ō�̕�����0xFFFF�𑫂��B

	// 0x4DA5D8 // WORD�ő喼�̔ԍ��̔z����i�[���Ă�ꏊ�B
	// �喼���X�g�̓��e��tenshou.exe�������ւƕ����W�J�B
	memcpy( (void *)0x4DA5D8, iArrayOfDaimyoList, sizeof(iArrayOfDaimyoList) );

	// �t�B���^�[�I�v�V�������㏑��
	iFilterOptionOfSelectDaimyoDialog = iFilterOption;

	__asm {
		push eax
		push ebx
		push ecx
		push edx
		push esp
		push esi
		push edi
	}

	// TENSHOU.EXE���̊֐��Ăяo��
	_SelectDaimyoDialogAsm();

	__asm {
		pop edi
		pop esi
		pop esp
		pop edx
		pop ecx
		pop ebx
		pop eax
	}

	iReturnOfSelectDaimyoDialog = iReturnOfSelectDaimyoDialog & 0xFFFF; // EAX�̂����AAX�̕����̂݁B
	if ( iReturnOfSelectDaimyoDialog == 0xFF || iReturnOfSelectDaimyoDialog == 0xFFFF ) { // �I�����Ȃ�����
		return 0xFFFF;
	} else {
		// ���Ԗڂ�I���������H �ł͂Ȃ��āA�Ώۂ̑喼�ԍ��y�z��p�z�𒼐ڕԂ��B
		return iReturnOfSelectDaimyoDialog-1;
	}
}

namespace �֐� {

int �I��喼�_�C�A���O�\��(�ԍ����X�g�^ �喼�ԍ��y�z��p�z���X�g, int �J�����I�v�V����, int ��ϑ喼�ԍ��y�z��p�z) {
	return _SelectDaimyoDialog(�喼�ԍ��y�z��p�z���X�g, �J�����I�v�V����, ��ϑ喼�ԍ��y�z��p�z);
}

}



//-------------------------------------------------------------------------------------

/*
0045036E  |> 6A 00          /PUSH 0                                  ; /Arg5 = 00000000
00450370  |. 6A 00          |PUSH 0                                  ; |Arg4 = 00000000
00450372  |. 56             |PUSH ESI                                ; |Arg3
00450373  |. 68 7FCD0000    |PUSH 0CD7F                              ; |Arg2 = 0000CD7F (�R�c�I��p�Œ�B�\�����ڂ�I�ׂ�)
00450378  |. 68 D8934D00    |PUSH TENSHOU.004D93D8                   ; |Arg1 = 004D93D8
0045037D  |. E8 D7B30000    |CALL TENSHOU.0045B759                   ; \TENSHOU.0045B759
00450382  |. 66:8BF8        |MOV DI,AX
00450385  |. 83C4 14        |ADD ESP,14
*/
/*
0045B763  |. FF75 10        PUSH    DWORD PTR SS:[EBP+10]            ; |Arg4
0045B766  |. FF75 0C        PUSH    DWORD PTR SS:[EBP+C]             ; |Arg3
0045B769     6A 01          PUSH    1										���̏ꏊ�̐l�����A�I���\�l�� 1�Œ�ŏ����Ă��邪�A0�ɐ؂�ւ��\�Ƃ���B
0045B76B  |. FF75 08        PUSH    DWORD PTR SS:[EBP+8]             ; |Arg1
0045B76E  |. E8 EEFEFFFF    CALL    TENSHOU.0045B661                 ; \TENSHOU.0045B661
*/

//---------------------�I���R�c�_�C�A���O-------------------------
int pCallFromFuncSelectGundanDialog = 0x45B759; // ���XTENSHOU.EXE���ɂ�����CALL��
int iReturnOfSelectGundanDialog = 0; // �Ԃ�l�BAX�̕����̂ݍ̗p����B
WORD iArrayOfGundanList[�ő吔::�R�c���::�z��+1] = {0}; // �\������ΏۂƂȂ�R�c���X�g�ԍ��B�Ō��0xFFFF�ŏI���Ƃ݂Ȃ��B
int iFilterOptionOfSelectGundanDialog = �J����::�R�c::�f�t�H���g;
static int iMultiGundanNumOfSelectGundanDialog = 1; // �I���\�ȌR�c�̍ő吔�B

void _SelectGundanDialogAsm() {

	__asm {
		push 0
		push 0
		push 1
		push iFilterOptionOfSelectGundanDialog // �t�B���^�[�l
		push 0x4D93D8 // WORD�ŌR�c�̔ԍ��̔z����i�[���Ă�ꏊ�B�Ō�0xFFFF

		call pCallFromFuncSelectGundanDialog

		mov iReturnOfSelectGundanDialog, eax

		add  esp, 0x14
	}
}

// �ΏۂƂȂ�R�c���X�g�B
int _SelectGundanDialog(vector<int> list, int iFilterOption) {

	// ���X�g�������Ȃ�Ȃɂ����Ȃ��B
	if ( list.size() == 0 ) {
		return 0xFFFF;
	}

	// �n���ꂽvector�`���̃��X�g��WORD�`���̔z��ւ̃R�s�[���Ă����B
	WORD *pCopy = iArrayOfGundanList;
	// �R�c�̃��X�g��z��`���ɂ���B
	for ( vector<int>::iterator it=list.begin(); it != list.end(); it++ ) {

		int iGundanID = *it;
		// �͈͊O�͖���
		if ( ! (0 <= iGundanID && iGundanID < �ő吔::�R�c���::�z��) ) {
			continue;
		}
		// �R�c�������Ȃ��ԍ��͖���
		if ( p�R�c���[iGundanID].�R�c���y�����ԍ��z == 0xFFFF ) {
			continue;
		}
		
		*pCopy = (WORD)iGundanID+1; // �z��p���ԍ��ɂ��Ĕz��Ɋi�[
		pCopy++;
	}
	
	// �R�s�[�σ|�C���^���P���i��ł��Ȃ��B==�P���L���ȌR�c�����Ȃ�����
	if ( pCopy == iArrayOfGundanList ) {
		return 0xFFFF;
	}

	*pCopy = 0xFFFF; // �Ō�̕�����0xFFFF�𑫂��B

	// 0x4D93D8 // WORD�ŌR�c�̔ԍ��̔z����i�[���Ă�ꏊ�B
	// �R�c���X�g�̓��e��tenshou.exe�������ւƕ����W�J�B
	memcpy( (void *)0x4D93D8, iArrayOfGundanList, sizeof(iArrayOfGundanList) );

	// �t�B���^�[�I�v�V�������㏑��
	iFilterOptionOfSelectGundanDialog = iFilterOption;

	__asm {
		push eax
		push ebx
		push ecx
		push edx
		push esp
		push esi
		push edi
	}

	// TENSHOU.EXE���̊֐��Ăяo��
	_SelectGundanDialogAsm();

	__asm {
		pop edi
		pop esi
		pop esp
		pop edx
		pop ecx
		pop ebx
		pop eax
	}

	iReturnOfSelectGundanDialog = iReturnOfSelectGundanDialog & 0xFFFF; // EAX�̂����AAX�̕����̂݁B
	if ( iReturnOfSelectGundanDialog == 0xFF || iReturnOfSelectGundanDialog == 0xFFFF ) { // �I�����Ȃ�����
		return 0xFFFF;
	} else {
		// ���Ԗڂ�I���������H �ł͂Ȃ��āA�Ώۂ̌R�c�ԍ��y�z��p�z�𒼐ڕԂ��B
		return iReturnOfSelectGundanDialog-1;
	}
}

namespace �֐� {

int �I���R�c�_�C�A���O�\��(�ԍ����X�g�^ �R�c�ԍ��y�z��p�z���X�g, int �J�����I�v�V���� ) {
	return _SelectGundanDialog(�R�c�ԍ��y�z��p�z���X�g, �J�����I�v�V����);
}

}

//-----------------------------------�ƕ󃊃X�g�_�C�A���O

/*
00446673  |> 6A 00          /PUSH    0                               ; /Arg5 = 00000000
00446675  |. 6A 00          |PUSH    0                               ; |Arg4 = 00000000
00446677  |. 57             |PUSH    EDI                             ; |Arg3
00446678  |. 6A 1F          |PUSH    1F                              ; |Arg2 = 0000001F
0044667A  |. 68 50C84D00    |PUSH    TENSHOU.004DC850                ; |Arg1 = 004DC850
0044667F  |. E8 0FD70300    |CALL    TENSHOU.00483D93                ; \TENSHOU.00483D93
00446684  |. 83C4 14        |ADD     ESP, 14
00446687  |. 8BF0           |MOV     ESI, EAX

*/

//---------------------�I���ƕ�_�C�A���O-------------------------
int pCallFromFuncSelectKahouDialog = 0x483D93; // ���XTENSHOU.EXE���ɂ�����CALL��
int iReturnOfSelectKahouDialog = 0; // �Ԃ�l�BAX�̕����̂ݍ̗p����B
int iArrayOfKahouList[�ő吔::�ƕ���::�z��+1] = {0}; // �\������ΏۂƂȂ�ƕ󃊃X�g�ԍ��B�Ō��0xFFFF�ŏI���Ƃ݂Ȃ��B
int iFilterOptionOfSelectKahouDialog = �J����::�ƕ�::�f�t�H���g;
void _SelectKahouDialogAsm() {

	__asm {
		push 0
		push 0
		push 1 // �I���\��(�A���ƕ�𕡐��I������v���͂Ȃ��͂�)
		push iFilterOptionOfSelectKahouDialog   // �\�����ڃI�v�V�����B0x3�Ƃ������̂�����B
		push 0x4DC850 // WORD�ŉƕ�̔ԍ��̔z����i�[���Ă�ꏊ�B�Ō�0xFFFF

		call pCallFromFuncSelectKahouDialog

		mov iReturnOfSelectKahouDialog, eax

		add  esp, 0x14
	}
}

// �ΏۂƂȂ�ƕ󃊃X�g�B
int _SelectKahouDialog(vector<int> list, int iFilterOption) {

	// ���X�g�������Ȃ�Ȃɂ����Ȃ��B
	if ( list.size() == 0 ) {
		return 0xFFFF;
	}

	// �n���ꂽvector�`���̃��X�g��WORD�`���̔z��ւ̃R�s�[���Ă����B
	int *pCopy = iArrayOfKahouList;
	// �ƕ�̃��X�g��z��`���ɂ���B
	for ( vector<int>::iterator it=list.begin(); it != list.end(); it++ ) {

		int iKahouID = *it;
		// �͈͊O�͖���
		if ( ! (0 <= iKahouID && iKahouID < �ő吔::�ƕ���::�z��) ) {
			continue;
		}
		
		*pCopy = iKahouID+1; // �z��p���ԍ��ɂ��Ĕz��Ɋi�[
		pCopy++;
	}
	
	// �R�s�[�σ|�C���^���P���i��ł��Ȃ��B==�P���L���ȉƕ󂪂P���Ȃ�����
	if ( pCopy == iArrayOfKahouList ) {
		return 0xFFFF;
	}

	*pCopy = 0xFFFF; // �Ō�̕�����0xFFFF�𑫂��B

	// 0x4DC850 // int�ŉƕ�̔ԍ��̔z����i�[���Ă�ꏊ�B
	// �ƕ󃊃X�g�̓��e��tenshou.exe�������ւƕ����W�J�B
	memcpy( (void *)0x4DC850, iArrayOfKahouList, sizeof(iArrayOfKahouList) );

	// �t�B���^�[�I�v�V�������㏑��
	iFilterOptionOfSelectKahouDialog = iFilterOption;

	__asm {
		push eax
		push ebx
		push ecx
		push edx
		push esp
		push esi
		push edi
	}

	// TENSHOU.EXE���̊֐��Ăяo��
	_SelectKahouDialogAsm();

	__asm {
		pop edi
		pop esi
		pop esp
		pop edx
		pop ecx
		pop ebx
		pop eax
	}

	iReturnOfSelectKahouDialog = iReturnOfSelectKahouDialog & 0xFFFF; // EAX�̂����AAX�̕����̂݁B
	if ( iReturnOfSelectKahouDialog == 0xFF || iReturnOfSelectKahouDialog == 0xFFFF ) { // �I�����Ȃ�����
		return 0xFFFF;
	} else {
		// ���Ԗڂ�I���������H �ł͂Ȃ��āA�Ώۂ̉ƕ�ԍ��y�z��p�z�𒼐ڕԂ��B
		return iReturnOfSelectKahouDialog-1;
	}
}


namespace �֐� {

int �I���ƕ�_�C�A���O�\��(�ԍ����X�g�^ �ƕ�ԍ��y�z��p�z���X�g, int �J�����I�v�V���� ) {
	return _SelectKahouDialog(�ƕ�ԍ��y�z��p�z���X�g, �J�����I�v�V����);
}

}


//---------------------------------------------------------�������X�g�_�C�A���O

/*
0040199E  |. 6A 00          PUSH 0                                   ; /Arg9 = 00000000
004019A0  |. 6A 00          PUSH 0                                   ; |Arg8 = 00000000
004019A2  |. 57             PUSH EDI                                 ; |Arg7 = 0xFFFF
004019A3  |. 6A 0A          PUSH 0A                                  ; |Arg6 = 0000000A
004019A5  |. 68 80100000    PUSH 1080                                ; |Arg5 = 00001080
004019AA  |. 6A 00          PUSH 0                                   ; |Arg4 = 00000000
004019AC  |. 68 103C0900    PUSH 93C10                               ; |Arg3 = 00093C10 (�\���I���I�v�V�����B3FC93F9D���ƑS��.python��bin�Œ������B)
004019B1  |. FF75 FC        PUSH DWORD PTR SS:[EBP-4]                ; |Arg2 = 5 ( �I���\�l�� )
004019B4  |. FF76 70        PUSH DWORD PTR DS:[ESI+70]               ; |Arg1 = 0x4DBD40(�Œ�)
004019B7  |. E8 797C0300    CALL TENSHOU.00439635                    ; \TENSHOU.00439635
004019BC  |. 83C4 24        ADD ESP,24
004019BF  |. 8BD8           MOV EBX,EAX


004397B3  /$ 55             PUSH EBP
004397B4  |. 8BEC           MOV EBP,ESP
004397B6  |. FF7424 24      PUSH DWORD PTR SS:[ESP+24]               ; /Arg9
004397BA  |. FF75 20        PUSH DWORD PTR SS:[EBP+20]               ; |Arg8
004397BD  |. FF75 1C        PUSH DWORD PTR SS:[EBP+1C]               ; |Arg7
004397C0  |. FF75 18        PUSH DWORD PTR SS:[EBP+18]               ; |Arg6
004397C3  |. FF75 14        PUSH DWORD PTR SS:[EBP+14]               ; |Arg5
004397C6  |. FF75 10        PUSH DWORD PTR SS:[EBP+10]               ; |Arg4
004397C9  |. FF75 0C        PUSH DWORD PTR SS:[EBP+C]                ; |Arg3	
004397CC  |. 6A 01          PUSH 1                                   ; |Arg2 = 00000001
004397CE  |. FF75 08        PUSH DWORD PTR SS:[EBP+8]                ; |Arg1
004397D1  |. E8 5FFEFFFF    CALL TENSHOU.00439635                    ; \TENSHOU.00439635
004397D6  |. 83C4 24        ADD ESP,24
004397D9  |. 83F8 01        CMP EAX,1
004397DC  |. 66:B8 FFFF     MOV AX,0FFFF
004397E0  |. 75 0A          JNZ SHORT TENSHOU.004397EC
004397E2  |. 6A 00          PUSH 0
004397E4  |. FF75 08        PUSH DWORD PTR SS:[EBP+8]				0x4DBD40(�Œ�)
004397E7  |. E8 724EFDFF    CALL TENSHOU.0040E65E					���̊֐��̌��ʂ͑I�𕐏���ID�ƂȂ�B
004397EC  |> 8BE5           MOV ESP,EBP
004397EE  |. 5D             POP EBP
004397EF  \. C3             RETN

0018FE0C   004DBD40  |Arg1 = 004DBD40
0018FE10   00000001  |Arg2 = 00000001
0018FE14   3FC93F9D  |Arg3 = 3FC93F9D
0018FE18   00000000  |Arg4 = 00000000
0018FE1C   00000000  |Arg5 = 00000000
0018FE20   0000FFFF  |Arg6 = 0000FFFF
0018FE24   0000FFFF  |Arg7 = 0000FFFF
0018FE28   00000000  |Arg8 = 00000000
0018FE2C   00000000  \Arg9 = 00000000
*/



//---------------------�I�𕐏��_�C�A���O-------------------------
int pCallFromFuncSelectBushouDialog = 0x439635; // ���XTENSHOU.EXE���ɂ�����CALL��
int pCallFromFuncSelectBushouDialog2 = 0x40E65E; // ���XTENSHOU.EXE���ɂ�����CALL��
int iReturnOfSelectBushouDialog = 0; // �Ԃ�l�BAX�̕����̂ݍ̗p����B
WORD iArrayOfBushouList[�ő吔::�������::�z��+1] = {0}; // �\������ΏۂƂȂ镐�����X�g�ԍ��B�Ō��0xFFFF�ŏI���Ƃ݂Ȃ��B
int iFilterOptionOfSelectBushouDialog = �J����::����::�f�t�H���g;
int iFilterExOptionOfSelectBushouDialog = 0; // �������33bit�ڈȍ~�̃I�v�V�����B

void _SelectBushouDialogAsm() {

	__asm {
		push 0
		push 0
		push 0xFFFF
		push 0xFFFF
		push 0
		push iFilterExOptionOfSelectBushouDialog // 33bit�ڈȍ~�̊g���I�v�V����
		push iFilterOptionOfSelectBushouDialog // �t�B���^�[�l
		push 1 // �I���\��(�A�������𕡐��I������v���͂Ȃ��͂�)
		push 0x4DBD40 // WORD�ŕ����̔ԍ��̔z����i�[���Ă�ꏊ�B�Ō�0xFFFF

		call pCallFromFuncSelectBushouDialog
		add  esp, 0x24
		cmp eax, 1	
		mov ax, 0xFFFF
		jnz labelEndOfFuncSelectBushouDialogAsm

		push 0
		push 0x4DBD40
		call pCallFromFuncSelectBushouDialog2
		mov iReturnOfSelectBushouDialog, eax // ���ꂪ���ۂ̑I�𕐏��ԍ�
		add  esp, 0x8

		labelEndOfFuncSelectBushouDialogAsm:
				;
	}
}

// �ΏۂƂȂ镐�����X�g�B
int _SelectBushouDialog(vector<int> list, __int64 iFilterOption) {

	// ���X�g�������Ȃ�Ȃɂ����Ȃ��B
	if ( list.size() == 0 ) {
		return 0xFFFF;
	}

	// �Ԃ�l�̓f�t�H���g�́u�����I�����Ȃ������v
	iReturnOfSelectBushouDialog = 0xFFFF;

	// �n���ꂽvector�`���̃��X�g��WORD�`���̔z��ւ̃R�s�[���Ă����B
	WORD *pCopy = iArrayOfBushouList;
	// �����̃��X�g��z��`���ɂ���B
	for ( vector<int>::iterator it=list.begin(); it != list.end(); it++ ) {

		int iBushouID = *it;
		// �͈͊O�͖���
		if ( ! (0 <= iBushouID && iBushouID < �ő吔::�������::�z��) ) {
			continue;
		}
		
		*pCopy = (WORD)iBushouID+1; // �z��p���ԍ��ɂ��Ĕz��Ɋi�[
		pCopy++;
	}
	
	// �R�s�[�σ|�C���^���P���i��ł��Ȃ��B==�P���L���ȕ��������Ȃ�����
	if ( pCopy == iArrayOfBushouList ) {
		return 0xFFFF;
	}

	*pCopy = 0xFFFF; // �Ō�̕�����0xFFFF�𑫂��B

	// 0x4DBD40 // WORD�ŕ����̔ԍ��̔z����i�[���Ă�ꏊ�B
	// �������X�g�̓��e��tenshou.exe�������ւƕ����W�J�B
	memcpy( (void *)0x4DBD40, iArrayOfBushouList, sizeof(iArrayOfBushouList) );

	// �t�B���^�[�I�v�V�������㏑��
	iFilterOptionOfSelectBushouDialog = iFilterOption & 0xFFFFFFFF;
	iFilterOption = iFilterOption >> 32; // ���32bit�����ʂɎ����Ă���B(�g���I�v�V���������ʂ�)
	iFilterExOptionOfSelectBushouDialog = iFilterOption & 0xFFFFFFFF;

	__asm {
		push eax
		push ebx
		push ecx
		push edx
		push esp
		push esi
		push edi
	}

	// TENSHOU.EXE���̊֐��Ăяo��
	_SelectBushouDialogAsm();

	__asm {
		pop edi
		pop esi
		pop esp
		pop edx
		pop ecx
		pop ebx
		pop eax
	}

	iReturnOfSelectBushouDialog = iReturnOfSelectBushouDialog & 0xFFFF; // EAX�̂����AAX�̕����̂݁B
	if ( iReturnOfSelectBushouDialog == 0xFFFF ) { // �I�����Ȃ�����
		return 0xFFFF;
	} else {
		// ���Ԗڂ�I���������H �ł͂Ȃ��āA�Ώۂ̕����ԍ��y�z��p�z�𒼐ڕԂ��B
		return int(iReturnOfSelectBushouDialog)-1;
	}
}


namespace �֐� {

	// �ΏۂƂȂ镐�����X�g�B
int �I�𕐏��_�C�A���O�\��(�ԍ����X�g�^ �����ԍ��y�z��p�z���X�g, __int64 �J�����I�v�V����) {
	return _SelectBushouDialog( �����ԍ��y�z��p�z���X�g, �J�����I�v�V����);
}


}


//--------------------------------------------------------------------------


/*
��̈���


0018FE14   004D8F50  |Arg1 = 004D8F50			�����̊i�[�ꏊ
0018FE18   00000001  |Arg2 = 00000001
0018FE1C   0033D57B  |Arg3 = 0033D57B			�J�����I�v�V����
0018FE20   00000000  |Arg4 = 00000000
0018FE24   0000FFFF  |Arg5 = 0000FFFF
0018FE28   0000FFFF  |Arg6 = 0000FFFF
0018FE2C   00000000  |Arg7 = 00000000
0018FE30   00000000  \Arg8 = 00000000

��̒P���p
0045040D  |> 6A 00          /PUSH 0                                  ; /Arg7 = 00000000
0045040F  |. 6A 00          |PUSH 0                                  ; |Arg6 = 00000000
00450411  |. 53             |PUSH EBX                                ; |Arg5
00450412  |. 53             |PUSH EBX                                ; |Arg4
00450413  |. 57             |PUSH EDI                                ; |Arg3
00450414  |. 68 7BD53300    |PUSH 33D57B                             ; |Arg2 = 0033D57B		�J�����I�v�V����
00450419  |. 68 508F4D00    |PUSH TENSHOU.004D8F50                   ; |Arg1 = 004D8F50		�����Œ�B���X�g�̕����̊i�[�ꏊ
0045041E  |. E8 B8E10200    |CALL TENSHOU.0047E5DB                   ; \TENSHOU.0047E5DB
00450423  |. 66:8BF0        |MOV SI,AX
00450426  |. 83C4 1C        |ADD     ESP, 1C


��̒P���p
�ďo����B��I���͂P�����Ȃ��͗l�B
0047E5DB  /$ 55             PUSH EBP
0047E5DC  |. 8BEC           MOV EBP,ESP
0047E5DE  |. FF7424 20      PUSH DWORD PTR SS:[ESP+20]               ; /Arg8
0047E5E2  |. FF75 1C        PUSH DWORD PTR SS:[EBP+1C]               ; |Arg7
0047E5E5  |. FF75 18        PUSH DWORD PTR SS:[EBP+18]               ; |Arg6
0047E5E8  |. FF75 14        PUSH DWORD PTR SS:[EBP+14]               ; |Arg5
0047E5EB  |. FF75 10        PUSH DWORD PTR SS:[EBP+10]               ; |Arg4
0047E5EE  |. FF75 0C        PUSH DWORD PTR SS:[EBP+C]                ; |Arg3
0047E5F1  |. 6A 01          PUSH 1                                   ; |Arg2 = 00000001
0047E5F3  |. FF75 08        PUSH DWORD PTR SS:[EBP+8]                ; |Arg1
0047E5F6  |. E8 6BFEFFFF    CALL TENSHOU.0047E466                    ; \TENSHOU.0047E466
0047E5FB  |. 83C4 20        ADD ESP,20
0047E5FE  |. 83F8 01        CMP EAX,1
0047E601  |. 66:B8 FFFF     MOV AX,0FFFF
0047E605  |. 75 0A          JNZ SHORT TENSHOU.0047E611
0047E607  |. 6A 00          PUSH 0
0047E609  |. FF75 08        PUSH DWORD PTR SS:[EBP+8]			
0047E60C  |. E8 6408F9FF    CALL TENSHOU.0040EE75
0047E611  |> 8BE5           MOV ESP,EBP
0047E613  |. 5D             POP EBP
0047E614  \. C3             RETN
*/


//---------------------�I����_�C�A���O-------------------------
int pCallFromFuncSelectCastleDialog = 0x47E5DB; // ���XTENSHOU.EXE���ɂ�����CALL��
int iReturnOfSelectCastleDialog = 0; // �Ԃ�l�BAX�̕����̂ݍ̗p����B
WORD iArrayOfCastleList[�ő吔::����::�z��+1] = {0}; // �\������ΏۂƂȂ�郊�X�g�ԍ��B�Ō��0xFFFF�ŏI���Ƃ݂Ȃ��B
int iFilterOptionOfSelectCastleDialog = �J����::��::�f�t�H���g;
static int iMultiCastleNumOfSelectCastleDialog = 1; // �I���\�ȏ�̍ő吔�B

void _SelectCastleDialogAsm() {

	__asm {
		push 0 
		push 0 
		push 0xFFFF
		push 0xFFFF
		push 0 
		push iFilterOptionOfSelectCastleDialog // �t�B���^�[�l
		push 0x4D8F50 // WORD�ŏ�̔ԍ��̔z����i�[���Ă�ꏊ�B�Ō�0xFFFF

		call pCallFromFuncSelectCastleDialog

		mov iReturnOfSelectCastleDialog, eax

		add  esp, 0x1C
	}
}

// �ΏۂƂȂ�郊�X�g�B
int _SelectCastleDialog(vector<int> list, int iFilterOption ) {

	// ���X�g�������Ȃ�Ȃɂ����Ȃ��B
	if ( list.size() == 0 ) {
		return 0xFFFF;
	}

	// �n���ꂽvector�`���̃��X�g��WORD�`���̔z��ւ̃R�s�[���Ă����B
	WORD *pCopy = iArrayOfCastleList;
	// ��̃��X�g��z��`���ɂ���B
	for ( vector<int>::iterator it=list.begin(); it != list.end(); it++ ) {

		int iCastleID = *it;
		// �͈͊O�͖���
		if ( ! (0 <= iCastleID && iCastleID < �ő吔::����::�z��) ) {
			continue;
		}
		
		*pCopy = (WORD)iCastleID+1; // �z��p���ԍ��ɂ��Ĕz��Ɋi�[
		pCopy++;
	}
	
	// �R�s�[�σ|�C���^���P���i��ł��Ȃ��B==�P���L���ȏ邪���Ȃ�����
	if ( pCopy == iArrayOfCastleList ) {
		return 0xFFFF;
	}

	*pCopy = 0xFFFF; // �Ō�̕�����0xFFFF�𑫂��B

	// 0x4D8F50 // WORD�ŏ�̔ԍ��̔z����i�[���Ă�ꏊ�B
	// �郊�X�g�̓��e��tenshou.exe�������ւƕ����W�J�B
	memcpy( (void *)0x4D8F50, iArrayOfCastleList, sizeof(iArrayOfCastleList) );

	// �t�B���^�[�I�v�V�������㏑��
	iFilterOptionOfSelectCastleDialog = iFilterOption;

	__asm {
		push eax
		push ebx
		push ecx
		push edx
		push esp
		push esi
		push edi
	}

	// TENSHOU.EXE���̊֐��Ăяo��
	_SelectCastleDialogAsm();

	__asm {
		pop edi
		pop esi
		pop esp
		pop edx
		pop ecx
		pop ebx
		pop eax
	}

	iReturnOfSelectCastleDialog = iReturnOfSelectCastleDialog & 0xFFFF; // EAX�̂����AAX�̕����̂݁B
	if ( iReturnOfSelectCastleDialog == 0xFF || iReturnOfSelectCastleDialog == 0xFFFF ) { // �I�����Ȃ�����
		return 0xFFFF;
	} else {
		// ���Ԗڂ�I���������H �ł͂Ȃ��āA�Ώۂ̏�ԍ��y�z��p�z�𒼐ڕԂ��B
		return iReturnOfSelectCastleDialog-1;
	}
}


namespace �֐� {

	// �ΏۂƂȂ镐�����X�g�B
int �I����_�C�A���O�\��(�ԍ����X�g�^ ��ԍ��y�z��p�z���X�g, int �J�����I�v�V����) {
	return _SelectCastleDialog( ��ԍ��y�z��p�z���X�g, �J�����I�v�V����);
}


}





//------------���ʃ_�C�A���O

/*
00401B0A  |> 53             /PUSH EBX                                ; /Arg5 = 0
00401B0B  |. 53             |PUSH EBX                                ; |Arg4 = 0
00401B0C  |. 53             |PUSH EBX                                ; |Arg3 = 0
00401B0D  |. 6A 0F          |PUSH 0F                                 ; |Arg2 = 0000000F �� �I���I�v�V����
00401B0F  |. 68 00B14D00    |PUSH TENSHOU.004DB100                   ; |Arg1 = 004DB100 �� �z��i�[�̏ꏊ
00401B14  |. E8 09750000    |CALL TENSHOU.00409022                   ; \TENSHOU.00409022
00401B19  |. 83C4 14        |ADD ESP,14
00401B1C  |. 8BF8           |MOV EDI,EAX
*/

//---------------------�I�����ʃ_�C�A���O-------------------------
int pCallFromFuncSelectKaniDialog = 0x409022; // ���XTENSHOU.EXE���ɂ�����CALL��
int iReturnOfSelectKaniDialog = 0; // �Ԃ�l�BAX�̕����̂ݍ̗p����B
int iArrayOfKaniList[�ő吔::���ʏ��::�z��+1] = {0}; // �\������ΏۂƂȂ銯�ʃ��X�g�ԍ��B�Ō��0xFFFF�ŏI���Ƃ݂Ȃ��B
int iFilterOptionOfSelectKaniDialog = �J����::����::�f�t�H���g;
void _SelectKaniDialogAsm() {

	__asm {
		push 0
		push 0
		push 0 // �I���\��(�A�����ʂ𕡐��I������v���͂Ȃ��͂�)
		push iFilterOptionOfSelectKaniDialog   // �\�����ڃI�v�V�����B0x3�Ƃ������̂�����B
		push 0x4DB100 // WORD�Ŋ��ʂ̔ԍ��̔z����i�[���Ă�ꏊ�B�Ō�0xFFFF

		call pCallFromFuncSelectKaniDialog

		mov iReturnOfSelectKaniDialog, eax

		add  esp, 0x14
	}
}

// �ΏۂƂȂ銯�ʃ��X�g�B
int _SelectKaniDialog(vector<int> list, int iFilterOption) {

	// ���X�g�������Ȃ�Ȃɂ����Ȃ��B
	if ( list.size() == 0 ) {
		return 0xFFFF;
	}

	// �n���ꂽvector�`���̃��X�g��WORD�`���̔z��ւ̃R�s�[���Ă����B
	int *pCopy = iArrayOfKaniList;
	// ���ʂ̃��X�g��z��`���ɂ���B
	for ( vector<int>::iterator it=list.begin(); it != list.end(); it++ ) {

		int iKaniID = *it;
		// �͈͊O�͖���
		if ( ! (0 <= iKaniID && iKaniID < �ő吔::���ʏ��::�z��) ) {
			continue;
		}
		
		*pCopy = iKaniID+1; // �z��p���ԍ��ɂ��Ĕz��Ɋi�[
		pCopy++;
	}
	
	// �R�s�[�σ|�C���^���P���i��ł��Ȃ��B==�P���L���Ȋ��ʂ��P���Ȃ�����
	if ( pCopy == iArrayOfKaniList ) {
		return 0xFFFF;
	}

	*pCopy = 0xFFFF; // �Ō�̕�����0xFFFF�𑫂��B

	// 0x4DB100 // int�Ŋ��ʂ̔ԍ��̔z����i�[���Ă�ꏊ�B
	// ���ʃ��X�g�̓��e��tenshou.exe�������ւƕ����W�J�B
	memcpy( (void *)0x4DB100, iArrayOfKaniList, sizeof(iArrayOfKaniList) );

	// �t�B���^�[�I�v�V�������㏑��
	iFilterOptionOfSelectKaniDialog = iFilterOption;

	__asm {
		push eax
		push ebx
		push ecx
		push edx
		push esp
		push esi
		push edi
	}

	// TENSHOU.EXE���̊֐��Ăяo��
	_SelectKaniDialogAsm();

	__asm {
		pop edi
		pop esi
		pop esp
		pop edx
		pop ecx
		pop ebx
		pop eax
	}

	iReturnOfSelectKaniDialog = iReturnOfSelectKaniDialog & 0xFFFF; // EAX�̂����AAX�̕����̂݁B
	if ( iReturnOfSelectKaniDialog == 0xFF ||iReturnOfSelectKaniDialog == 0xFFFF ) { // �I�����Ȃ�����
		return 0xFFFF;
	} else {
		// ���Ԗڂ�I���������H �ł͂Ȃ��āA�Ώۂ̊��ʔԍ��y�z��p�z�𒼐ڕԂ��B
		return iReturnOfSelectKaniDialog-1;
	}
}


namespace �֐� {

	// �ΏۂƂȂ镐�����X�g�B
int �I�����ʃ_�C�A���O�\��(�ԍ����X�g�^ ���ʔԍ��y�z��p�z���X�g, int �J�����I�v�V����) {
	return _SelectKaniDialog( ���ʔԍ��y�z��p�z���X�g, �J�����I�v�V����);
}


}




