#include "�J�X�^���쓮�֐�.h"
#include <map>
#include <time.h>
#include "lua/�k�t�`�qinterface�r.h"
#include "mruby/�l�q�t�a�x�qinterface�r.h"

#include "�v���Z�X�n���h��.h"

#pragma comment(lib, "shlwapi.lib")

using namespace std;

// �V�ċL�̃E�B���h�E�n���h��
HWND tenshouWND=NULL;

// TSMod.dll�̃n���h��
HMODULE hModuleTSMod = NULL;

extern void _���K�\���֐��o�^();
extern void _�A�v���P�[�V�����֐��o�^();
extern void _�����֐��o�^();
extern void _����֐��o�^();
extern void _�V�C�֐��o�^();
extern void _�퓬�֘A�o�^();
extern void _���֐��o�^();
extern void _���ʉ��֐��o�^();
extern void _�R�}���h�֐��o�^();
extern void	_�V�i���I�֐��o�^();
extern void _�_�C�A���O�֐��o�^();
extern void	_�t���O�֐��o�^();

extern void _�������W���[���o�^();
extern void _�������W���[������();


void WINAPI snOnDllMainBgn() {

	srand( (unsigned int)time( NULL ) ); // �����̎��ς���

	hModuleTSMod=GetModuleHandle("TSMod.dll");
	if ( !hModuleTSMod ) {;}
	// ���ɂȂɂ����Ȃ����ATSMod.dll�ȊO��ScenarioMod���������Ă���̂��낤�c�B
	// TSMod�̃\�[�X��r���܂łƂ͂������J���Ă���̂ŁA�����I�ɂ͂��̂悤�Ȍ݊�DLL���o�邱�Ƃ��l�����Ȃ��͂Ȃ��B

	LoadLuaInterpreter();
	LoadMRubyInterpreter();

	_���K�\���֐��o�^();
	_�A�v���P�[�V�����֐��o�^();
	_�����֐��o�^();
	_����֐��o�^();
	_�V�C�֐��o�^();
	_�퓬�֘A�o�^();
	_���֐��o�^();
	_���ʉ��֐��o�^();
	_�V�i���I�֐��o�^();
	_�������W���[���o�^();
	_�R�}���h�֐��o�^();
	_�_�C�A���O�֐��o�^();
	_�t���O�֐��o�^();
}

void WINAPI snOnDllMainEnd() {
	_�������W���[������();

	FreeLuaInterpreter();
	FreeMRubyInterpreter();
}


void WINAPI snOnConstructor() {

	// �E�B���h�E�n���h�����m�ۂ��Ă����B�t�H�A�O�����h�Ȃǂ̏����g�����Ƃ�����B
	tenshouWND = ::GetCurrentWindowHandle();
	if ( !tenshouWND ) { tenshouWND = FindWindow("Tenshouki95", NULL); }

	try {
		�J�X�^���쓮�֐�.On_�N����();
	} catch(...) {
	}
}


void WINAPI snOnDestructor() {
	try {
		�J�X�^���쓮�֐�.On_�I����();
	} catch(...) {
	}
}

#define TAIKIBUSHOU_STRUCT_SIZE   (sizeof(�ҋ@������o����^) + sizeof(�ҋ@�������^) + sizeof(�ҋ@�����ːЏ��^))
extern byte _�ҋ@�����f�[�^�o�b�t�@�[[6][TAIKIBUSHOU_STRUCT_SIZE * 1300]; // �{���͍ő�ł�1000�l�サ���f�[�^�ɋl�ߍ��ނ��Ƃ��o���Ȃ�
extern int _�ҋ@�����f�[�^�l��[6];
void WINAPI snOnTaikiBushouDataTransfer(byte *p0, int n0, byte *p1, int n1, byte *p2, int n2, byte *p3, int n3, byte *p4, int n4, byte *p5, int n5) {
	memcpy(&_�ҋ@�����f�[�^�o�b�t�@�[[0], p0, n0);
	memcpy(&_�ҋ@�����f�[�^�o�b�t�@�[[1], p1, n1);
	memcpy(&_�ҋ@�����f�[�^�o�b�t�@�[[2], p2, n2);
	memcpy(&_�ҋ@�����f�[�^�o�b�t�@�[[3], p3, n3);
	memcpy(&_�ҋ@�����f�[�^�o�b�t�@�[[4], p4, n4);
	memcpy(&_�ҋ@�����f�[�^�o�b�t�@�[[5], p5, n5);
	_�ҋ@�����f�[�^�l��[0] = n0 / TAIKIBUSHOU_STRUCT_SIZE;
	_�ҋ@�����f�[�^�l��[1] = n1 / TAIKIBUSHOU_STRUCT_SIZE;
	_�ҋ@�����f�[�^�l��[2] = n2 / TAIKIBUSHOU_STRUCT_SIZE;
	_�ҋ@�����f�[�^�l��[3] = n3 / TAIKIBUSHOU_STRUCT_SIZE;
	_�ҋ@�����f�[�^�l��[4] = n4 / TAIKIBUSHOU_STRUCT_SIZE;
	_�ҋ@�����f�[�^�l��[5] = n5 / TAIKIBUSHOU_STRUCT_SIZE;
}

void WINAPI snOnAfterChangeWindowSize() {
	try {
		�J�X�^���쓮�֐�.On_�E�B���h�E�𑜓x�ؑ֎�();
	} catch(...) {
	}
}

void WINAPI snOnViewingTopMenu() {
	try {
		�J�X�^���쓮�֐�.On_�g�b�v���j���[�\����();
	} catch(...) {
	}
}


void WINAPI snOnLoadSaveData(int iSelectID, char *szFileName) {
	try {
		�J�X�^���쓮�֐�.On_�Z�[�u�f�[�^�Ǎ���(iSelectID, string(szFileName));
	} catch(...) {
	}
}

void WINAPI snOnSaveSaveData(int iSelectID, char *szFileName) {
	try {
		�J�X�^���쓮�֐�.On_�Z�[�u�f�[�^�ۑ���(iSelectID, string(szFileName));
	} catch(...) {
	}
}



void WINAPI snOnViewingScenarioTitleList() {

	int pt[] = { 0x4d36E4, 0x4d36C4, 0x4d36A4, 0x4d3684, 0x4d3664, 0x4d3644 }; // �V�i���I�^�C�g�������݂���A�h���X

	char** menu = NULL;
	
	try {
		menu = �J�X�^���쓮�֐�.On_�V�i���I���j���[�\�����O(); // 1�`6��
	} catch(...) {
	}

	if ( menu ) {
		for ( int sn=0; sn<�ő吔::�V�i���I���::�z��; sn++ ) {
			if ( menu[sn] && strlen(menu[sn]) > 1 ) { // 
				strncpy( (char *)pt[sn], menu[sn], 31 ); // �S�p�P�T�����܂ŃR�s�[
			}
		}
	}
}

static int i�V�i���I�I�����V�i���I�ԍ� = -1;
char ** WINAPI snOnWritingScenarioDetail(int i�V�i���I�ԍ�) {
	i�V�i���I�I�����V�i���I�ԍ� = i�V�i���I�ԍ�;
	char **p = NULL;
	try {
		p = �J�X�^���쓮�֐�.On_�V�i���I�����\�����O(i�V�i���I�ԍ�);
	} catch(...) {
	}
	return p;
}

/*
* �V�i���I�ڍו\�����o�Ţ�m�F�����������A�喼�I����ʂ��\�������܂ł̊ԂɌĂяo������s�����֐�
* (������Ƃ܂��I�����ꂽ�V�i���I���͓n���Ă��Ȃ�)
*/
bool WINAPI snOnSelectingScenarioAfter(void* ptr�V�i���I�I��ԍ�) {

	try {
		�J�X�^���쓮�֐�.On_�V�i���I�f�[�^���f����(i�V�i���I�I�����V�i���I�ԍ�);
	}
	catch (...) {
	}
	return true;
}


/* 
 * �V�i���I�ڍו\�����o�Ţ�m�F�����������A�喼�I����ʂ��\�������܂ł̊ԂɌĂяo������s�����֐�
 * (������Ƃ܂��I�����ꂽ�V�i���I���͓n���Ă��Ȃ�)
 */
bool WINAPI snOnSelectingScenarioDaimyo(void* ptr�V�i���I�I��ԍ� ) {

	try {
		�J�X�^���쓮�֐�.On_�V�i���I�喼�I�𒼑O(i�V�i���I�I�����V�i���I�ԍ�);
	} catch(...) {
	}
	return true;
}





bool WINAPI snOnRewriteFukidashiMessage(char *�ԐM�p�o�b�t�@, char *������, char *�����b�Z�[�W, ���b�Z�[�W�֘A���^ *ptr���b�Z�[�W�֘A���) {

	���b�Z�[�W�֘A���^ ���b�Z�[�W�֘A���;
	���b�Z�[�W�֘A���.��P�l�́y�����ԍ��z = ptr���b�Z�[�W�֘A���->��P�l�́y�����ԍ��z;
	���b�Z�[�W�֘A���.��Q�l�́y�����ԍ��z = ptr���b�Z�[�W�֘A���->��Q�l�́y�����ԍ��z;
	���b�Z�[�W�֘A���.��R�l�́y�����ԍ��z = ptr���b�Z�[�W�֘A���->��R�l�́y�����ԍ��z;

	string �ԐM�p���b�Z�[�W = "";
	try {
		�ԐM�p���b�Z�[�W = �J�X�^���쓮�֐�.On_���o���b�Z�[�W���O(������, �����b�Z�[�W, ���b�Z�[�W�֘A���);
	} catch(...) {
	}
	if ( �ԐM�p���b�Z�[�W.size() > 1 ) {
		strcpy( �ԐM�p�o�b�t�@, �ԐM�p���b�Z�[�W.c_str() );
		return true;
	}

	return false;
}

void WINAPI snOnDecisionInputNumberDialog(char *sz���b�Z�[�W, ���l���̓_�C�A���O�p�����^�^ *param) {

	string ���b�Z�[�W = sz���b�Z�[�W;
	���l���̓_�C�A���O�p�����^�^ �p�����^;
	�p�����^.�ŏ��l = param->�ŏ��l;
	�p�����^.�ő�l = param->�ő�l;
	�p�����^.���͒l = param->���͒l;

	try {
		�J�X�^���쓮�֐�.On_���l���̓_�C�A���O���莞( ���b�Z�[�W, �p�����^ );
	} catch(...) {
	}
}

void WINAPI snOnRatificationDialog(char *sz���b�Z�[�W, char *szTitle ) {
	try {
		string ���b�Z�[�W = sz���b�Z�[�W;
		string �^�C�g�� = szTitle;
		�J�X�^���쓮�֐�.On_�ǔF�n�_�C�A���O�m�F��( ���b�Z�[�W, �^�C�g�� );
	} catch(...) {
	}
}


// �܂����񂾂��p�����^�����A�\�������đ����˂����낗
int WINAPI snOnCustomCondition(char *sz������, int ����1, int ����2, int ����3, char *������1, char *������2, float ��������1, float ��������2) {

	string ������(sz������);

	�J�X�^�������p�����^�^ �p�����^;
	�p�����^.����1 = ����1;
	�p�����^.����2 = ����2;
	�p�����^.����3 = ����3;
	�p�����^.������1 = ������1;
	�p�����^.������2 = ������2;
	�p�����^.��������1 = ��������1;
	�p�����^.��������2 = ��������2;

	int �Ԃ�l = -1;
	try {
		�Ԃ�l = �J�X�^���쓮�֐�.On_�J�X�^������(������,�p�����^);
	} catch(...) {
	}
	return �Ԃ�l;
}


int WINAPI snOnN6PAudioPlayTrack(int �Đ��\��ԍ�) {
	int �Ԃ�l = -1;
	try {
		�Ԃ�l = �J�X�^���쓮�֐�.On_���y�Đ����O(�Đ��\��ԍ�);
	} catch(...) {
	}
	return �Ԃ�l;
}


// ���C����ʂɂ����āA�v���C���S���喼�̂̃^�[���ƂȂ�����
void WINAPI snOnPlayerTurnInMainScreen() {
	try {
		�J�X�^���쓮�֐�.On_�v���C���S���^�[���s���C����ʁt();
	} catch(...) {
	}
}

// ����R�}���h�ւ̐N��
void WINAPI snOnEnterMainPlayerCommand(int iMainCmdID, int iSubCmdID) {
	try {
		int �R�}���h�ԍ� = 0;
		�J�X�^���쓮�֐�.On_�v���C���R�}���h�������O�s���C����ʁt(iMainCmdID, iSubCmdID);
	} catch(...) {
	}
}

// ����R�}���h����̒E�o
void WINAPI snOnLeaveMainPlayerCommand() {
	try {
		int �R�}���h�ԍ� = 0;
		�J�X�^���쓮�֐�.On_�v���C���R�}���h�������O�s���C����ʁt();
	} catch(...) {
	}
}

void WINAPI snOnGundanTurnInMainScreen(int �R�c�ԍ�) {
	try {
		�J�X�^���쓮�֐�.On_�R�c�^�[���ύX�s���C����ʁt(�R�c�ԍ�);
	} catch(...) {
	}
}


string _g�퓬�R�}���h���X�g[20];
void WINAPI snOnViewingBattleMenuInBattle5(int �����ԍ�,
										   char *p�ʏ�U��,
										   char *p��čU��,
										   char *p�ˌ�,
										   char *p�S�C�U��,
										   char *p��C�U��
										   ) {
		
	for ( int i=0; i < sizeof(_g�퓬�R�}���h���X�g)/sizeof(_g�퓬�R�}���h���X�g[0]); i++ ) {
		_g�퓬�R�}���h���X�g[i] = "";
	}
	try {
		�J�X�^���쓮�֐�.On_�퓬�R�}���h�\�����O�s�푈��ʁt(�����ԍ�);
	} catch(...) {
	}
	strncpy( p�ʏ�U��,   _g�퓬�R�}���h���X�g[ 0].c_str(), 19 );
	strncpy( p��čU��,   _g�퓬�R�}���h���X�g[ 1].c_str(), 19 );
	strncpy( p�ˌ�,		  _g�퓬�R�}���h���X�g[ 2].c_str(), 19 );
	strncpy( p�S�C�U��,   _g�퓬�R�}���h���X�g[ 3].c_str(), 19 );
	strncpy( p��C�U��,   _g�퓬�R�}���h���X�g[ 4].c_str(), 19 );
}


// �v���C������ɂ���āA�퓬���̒ʏ�R�}���h���\������鎞
string _g��{�R�}���h���X�g[20];
void WINAPI snOnViewingCommandMenuInBattle12(int �����ԍ�,
											char *p�ە�,
											char *p��O,
											char *p�ދp,
											char *p����,
											char *p�Z�\,
											char *p����,
											char *p����,
											char *p����,
											char *p�΍U��,
											char *p�ÎE,
											char *p����,
											char *p�ꊅ
											) {

	for ( int i=0; i < sizeof(_g��{�R�}���h���X�g)/sizeof(_g��{�R�}���h���X�g[0]); i++ ) {
		_g��{�R�}���h���X�g[i] = "";
	} 
	try {
		�J�X�^���쓮�֐�.On_��{�R�}���h�\�����O�s�푈��ʁt(�����ԍ�);
	} catch(...) {
	}
	strncpy( p�ە�,   _g��{�R�}���h���X�g[ 0].c_str(), 19 );
	strncpy( p��O,   _g��{�R�}���h���X�g[ 1].c_str(), 19 );
	strncpy( p�ދp,   _g��{�R�}���h���X�g[ 2].c_str(), 19 );
	strncpy( p����,   _g��{�R�}���h���X�g[ 3].c_str(), 19 );
	strncpy( p�Z�\,   _g��{�R�}���h���X�g[ 4].c_str(), 19 );
	strncpy( p����,   _g��{�R�}���h���X�g[ 5].c_str(), 19 );
	strncpy( p����,   _g��{�R�}���h���X�g[ 6].c_str(), 19 );
	strncpy( p����,   _g��{�R�}���h���X�g[ 7].c_str(), 19 );
	strncpy( p�΍U��, _g��{�R�}���h���X�g[ 8].c_str(), 19 );
	strncpy( p�ÎE,   _g��{�R�}���h���X�g[ 9].c_str(), 19 );
	strncpy( p����,   _g��{�R�}���h���X�g[10].c_str(), 19 );
	strncpy( p�ꊅ,   _g��{�R�}���h���X�g[11].c_str(), 19 );
}

// �퓬�ɂ��U���s����I�������u��
void WINAPI snOnSelectingBattleAction(int ��̕����ԍ�, int �q�̕����ԍ�, int �U�����@�ԍ�, void *�p�����^) {
	try {
		�U�����@���莞�p�����^�^ *p = (�U�����@���莞�p�����^�^*)�p�����^;

		int _���K��_�U�����@�ԍ� = �U�����@�ԍ�;
		// ScenarioMod���ł͓S�C�Ƌ|�̋�ʂ����Ă���
		if ( �U�����@�ԍ� == 2 && ( p�������[��̕����ԍ�].���� == ����::���y || p�������[��̕����ԍ�].���� == ����::�R�n ) ) {
			_���K��_�U�����@�ԍ� = �U�����@::�|;
		}

		�U�����@���莞�p�����^�^ �p�����^;
		�p�����^.�U�����@�ԍ� = _���K��_�U�����@�ԍ�;
		�p�����^.�ړ��O = p->�ړ��O;

		�J�X�^���쓮�֐�.On_�U�����@���莞�s�푈��ʁt(��̕����ԍ�+1, �q�̕����ԍ�+1, �p�����^);
	} catch (...) {
	}
}

// ��Ƃ��Đ퓬�ɂ��_���[�W
void WINAPI snOnBattleDamaged(int �����ԍ�, int �_���[�W�l, void *�p�����^) {
	try {
		�J�X�^���쓮�֐�.On_��_���[�W��(�����ԍ�, �_���[�W�l);
	} catch (...) {
	}
}



// ���݉�ʂŐ��ƂȂ��Ă���A��ԍ���TSMOD�����M�B���̏ꍇ�ɂ́A0xFFFF������B
extern int _���ݍU�钆�̏�ԍ�;
void WINAPI snSetCurrentCastleIDInBattle(int ��ԍ�) {
	_���ݍU�钆�̏�ԍ� = ��ԍ�;
}


�푈�J�n�p�����^�^ �J�n�p�����^;
void WINAPI snOnBattleStart(void *�p�����^) {
	�푈�J�n�p�����^�^ *p = (�푈�J�n�p�����^�^ *)(�p�����^);
	�J�n�p�����^.��ԍ� = p->��ԍ�;
	�J�n�p�����^.������R�c�y�R�c�ԍ��z   = p->������R�c�y�R�c�ԍ��z;
	�J�n�p�����^.������R�c���y�����ԍ��z = p->������R�c���y�����ԍ��z;
	�J�n�p�����^.�U�����R�c�y�R�c�ԍ��z   = p->�U�����R�c�y�R�c�ԍ��z;
	�J�n�p�����^.�U�����R�c���y�����ԍ��z = p->�U�����R�c���y�����ԍ��z;

	try {
		�J�X�^���쓮�֐�.On_�푈�J�n(�J�n�p�����^);
	} catch(...) {
	}
}

void WINAPI snOnChangeTurnInBattle(int �c��^�[����) {
	try {
		�J�X�^���쓮�֐�.On_�c��^�[���ύX�s�푈��ʁt(�c��^�[����);
	} catch(...) {
	}
}

int WINAPI snOnCalcWeatherInBattle(int �\��V�C, int �c��^�[����) {
	int �V�V�C = -1;
	try {
		// �V�V�C = �J�X�^���쓮�֐�.On_�V�C���莞�s�푈��ʁt(�\��V�C, �c��^�[����);
	}
	catch (...) {
	}
	return �V�V�C;
}

void WINAPI snOnChangeCastleTurnInBattle(int �^�[����) {
	try {
		�J�X�^���쓮�֐�.On_�^�[���ύX�s�U�钆��ʁt(�^�[����);
	} catch(...) {
	}
}

int WINAPI snOnChangeUnitMovePowerInBattle(int iBushouID, int iPrev, int iNext) {
	int iOverWriteNext = 1;
	try {
		iOverWriteNext = �J�X�^���쓮�֐�.On_�ړ��͎c�ʕύX���s�푈��ʁt(iBushouID + 1, iPrev, iNext);
	}
	catch (...) {
	}
	return iOverWriteNext;
}

void WINAPI snOnBattleScreenEnd() {
	try {
		�J�X�^���쓮�֐�.On_�푈��ʏI��();
	}
	catch (...) {
	}
}
void WINAPI snOnBattleEnd() {
	try {
		�J�X�^���쓮�֐�.On_�푈�I��();
	} catch(...) {
	}
}

int WINAPI snOnRequestSoldierMax(int iBushouID, int iOrgSolMax, int iModSolMax) {
	int ret = -1;
	try {
		ret = �J�X�^���쓮�֐�.On_�����ő啺���v����(iBushouID+1, iOrgSolMax, iModSolMax);
	}
	catch (...) {
	}
	return ret;
}

void WINAPI snOnMainGameStart() {
	try {
		�J�X�^���쓮�֐�.On_���C���Q�[���J�n();
	} catch(...) {
	}
}

int WINAPI snOnSkippedRekishiBushou(int �����ԍ��z��p, int �o��ϐl��, int �ҋ@�����f�[�^��) {

	try {
		int isSkipp = �J�X�^���쓮�֐�.On_�ҋ@�����o�꒼�O(�����ԍ��z��p + 1, �o��ϐl��, �ҋ@�����f�[�^��);
		return isSkipp;
	}
	catch (...) {
	}

	return -1;
}

bool WINAPI snOnBornRekishiBushou(int �����ԍ��z��p) {

	try {
		�J�X�^���쓮�֐�.On_�ҋ@�����o�꒼��(�����ԍ��z��p + 1);
	}
	catch (...) {
	}

	return true;
}

bool WINAPI snOnBornGeneralBushou(int �����ԍ��z��p) {

	try {
		�J�X�^���쓮�֐�.On_���z�����o�꒼��(�����ԍ��z��p + 1);
	}
	catch (...) {
	}

	return true;
}




bool WINAPI snOnViewingJobName(char *�ԐM�p�o�b�t�@, int �����ԍ�) {
	string �ԐM�p�E�Ɩ� = "";
	
	try {
		�ԐM�p�E�Ɩ� = �J�X�^���쓮�֐�.On_�E�Ɩ��\�����O(�����ԍ�);
	} catch(...) {
	}

	if ( �ԐM�p�E�Ɩ�.size() > 1 ) {
		strcpy( �ԐM�p�o�b�t�@, �ԐM�p�E�Ɩ�.c_str() );
		return true;
	}
	return false;

}

// �R�n�S�C�Əo��Ƃ���̕ύX
bool WINAPI snOnViewingSpecialFormName(char *�ԐM�p�o�b�t�@, int �����ԍ�) {
	string �ԐM�p���ꕺ�Ԗ� = "";
	
	try {
		�ԐM�p���ꕺ�Ԗ� = �J�X�^���쓮�֐�.On_���ꕺ�Ԗ��\�����O(�����ԍ�);
	} catch(...) {
	}

	if ( �ԐM�p���ꕺ�Ԗ�.size() > 1 ) {
		strcpy( �ԐM�p�o�b�t�@, �ԐM�p���ꕺ�Ԗ�.c_str() );
		return true;
	}
	return false;
}

// �ƕ��ޖ��̏o��Ƃ���̕ύX
bool WINAPI snOnViewingKahouTypeName(char *�ԐM�p�o�b�t�@, int �ƕ�ԍ�) {
	string �ԐM�p�ƕ��ޖ� = "";
	
	try {
		�ԐM�p�ƕ��ޖ� = �J�X�^���쓮�֐�.On_�ƕ��ޖ��\�����O( �ƕ�ԍ�, Get_�ƕ�(�ƕ�ԍ�-1) );
	} catch(...) {
	}

	if ( �ԐM�p�ƕ��ޖ�.size() > 1 ) {
		strcpy( �ԐM�p�o�b�t�@, �ԐM�p�ƕ��ޖ�.c_str() );
		return true;
	}
	return false;
}


char g�������������[11] = "";

int WINAPI snOnViewingButaiName(int �����ԍ�) {

	strcpy(g�������������, "NULL"); // NULL�̓_�~�[�����B�����ω������Ȃ��Ƃ������ƁB

	char **p�V������ = NULL;
	try {
		p�V������ = �J�X�^���쓮�֐�.On_�������\�����O(�����ԍ�);
	} catch(...) {
	}
	
	if ( p�V������ ) {
		return (int)p�V������;
	} else {
		return NULL;
	}
}

int WINAPI snOnGettingButaimeiGobiSprintf(void *pSendParam, char *pBuf) {
	if (strcmp(g�������������, "NULL") == 0) {
		return FALSE;
	}
	else {
		strcpy(pBuf, g�������������);
		return TRUE;
	}
}

bool WINAPI snOnViewingPositionName(int *p�ԐM�|�C���^, int �����ԍ�, int �Ώېg��) {

	try {
		*p�ԐM�|�C���^ = (int)�J�X�^���쓮�֐�.On_�g�����\�����O(�����ԍ�, �Ώېg��);
	}
	catch (...) {
	}

	if (p�ԐM�|�C���^) {
		return true;
	}
	else {
		return false;
	}

}

bool WINAPI snOnViewingBushouStateName(int *p�ԐM�|�C���^, int �����ԍ�, int �Ώۏ��) {

	try {
		*p�ԐM�|�C���^ = (int)�J�X�^���쓮�֐�.On_��Ԗ��\�����O(�����ԍ�, �Ώۏ��);
	}
	catch (...) {
	}

	if (p�ԐM�|�C���^) {
		return true;
	}
	else {
		return false;
	}

}

bool WINAPI snOnViewingIe(int �����ԍ�, char *p���݂̃o�b�t�@�[) {

	string �V������ = "";
	try {
		�V������ = �J�X�^���쓮�֐�.On_�Ɩ��\�����O(�����ԍ�, string(p���݂̃o�b�t�@�[));
	}
	catch (...) {
	}

	if (�V������.length() > 0) {
		strncpy(p���݂̃o�b�t�@�[, �V������.c_str(), 8); // �S�p�S������MAX
		p���݂̃o�b�t�@�[[8] = NULL; // �ԕ�
		return true;
	}
	else {
		return false;
	}


}

void WINAPI snOnViewingRetsuden(int iBushouID, int iFaceID, char *szBufTitle, char *szBufDetail) {
	try {
		�퍑������`�^ rt = �J�X�^���쓮�֐�.On_�퍑������`�v����(iBushouID+1, iFaceID );
		if (rt._���x��.size() > 0) {
			strncpy(szBufTitle, rt._���x��.c_str(), 48);
			szBufTitle[49] = NULL;
		}
		if (rt._�ڍ�.size() > 0) {
			strncpy(szBufDetail, rt._�ڍ�.c_str(), 198);
			szBufDetail[199] = NULL;
		}
	} catch (...) {}
}


void WINAPI snOnViewingMeibutsuJiten(int iKahouID, char *szBufTitle, char *szBufDetail) {
	try {
		�퍑�������T�^ rt = �J�X�^���쓮�֐�.On_�퍑�������T�v����(iKahouID + 1);
		if (rt._���x��.size() > 0) {
			strncpy(szBufTitle, rt._���x��.c_str(), 48);
			szBufTitle[49] = NULL;
		}
		if (rt._�ڍ�.size() > 0) {
			strncpy(szBufDetail, rt._�ڍ�.c_str(), 198);
			szBufDetail[199] = NULL;
		}
	}
	catch (...) {}
}

void WINAPI snOnViewingMeijoMonogatari(int iCastleID, char *szBufTitle, char *szBufDetail) {
	try {
		�퍑���镨��^ rt = �J�X�^���쓮�֐�.On_�퍑���镨��v����(iCastleID + 1);
		if (rt._���x��.size() > 0) {
			strncpy(szBufTitle, rt._���x��.c_str(), 48);
			szBufTitle[49] = NULL;
		}
		if (rt._�ڍ�.size() > 0) {
			strncpy(szBufDetail, rt._�ڍ�.c_str(), 198);
			szBufDetail[199] = NULL;
		}
	}
	catch (...) {}
}


void WINAPI snOnRequestFullcolorFaceFileName(char* szOrgFileName, char* szDstFileName) {
	try {
		string ret = �J�X�^���쓮�֐�.On_�t���J���[��O���t�@�C���v����(szOrgFileName);
		if (ret.size() > 0) {
			strncpy(szDstFileName, ret.c_str(), 98);
			szDstFileName[99] = NULL;
		}
	}
	catch (...) {}
}

extern ������^ ��������ύX; // ScenarioMod���̍��G�̋�������ύX���
void WINAPI snOnChangeSoba(������^* ����ύX�`�B�|�C���^) {
	// �����ύX�����A���ĂȂ��������Z�b�g�B
	// Set_�đ���Ȃǂ̒��ŁA�ύX�������ڂɑ��ꂪ���̂܂ܓ���B����ɂO����ꂽ��A�㏑�����Ȃ��Ƃ������ƁB
	// �f�t�H���g�ł͂����łO������̂ŁA�����̃f�t�H���g�����͑�����㏑�����Ȃ��Ƃ������ƁB
	��������ύX.�đ���		= 0;
	��������ύX.�S�C����	= 0;
	��������ύX.�n����		= 0;
	��������ύX.������		= 0;

	try {
		�J�X�^���쓮�֐�.On_����ύX���O();
	} catch(...) {
	}

	// �J�X�^��::On_����ύX���O�ɕύX���Ă�����A�ύX�t���O����TSMod�ւƕԂ��B
	����ύX�`�B�|�C���^->�đ���	= ��������ύX.�đ���;
	����ύX�`�B�|�C���^->�S�C����	= ��������ύX.�S�C����;
	����ύX�`�B�|�C���^->�n����	= ��������ύX.�n����;
	����ύX�`�B�|�C���^->������	= ��������ύX.������;
}

// ScenarioMod�Ƌ��L�̃G���f�B���O�_�C�A���O�̌^
struct TEndingDialogInfo {
	int iDaimyoNo; // +1�̕�
	char szEndingTitle[20];
	char szEndingConditionRewriteMsg[100];
	int isNeverEnding;
	char szEndingMovieName[50];
};

BOOL WINAPI snOnEndingCondition(void *pBufReturn, int iDaimyoNo, int dummy2) {
	try {
		�G���f�B���O���^ result = �J�X�^���쓮�֐�.On_�G���f�B���O���莞(iDaimyoNo);
		if (result.�喼�ԍ� == NULL) {
			return NULL;
		}

		// �󂯓n���̃o�b�t�@�[�ɒl���i�[
		((TEndingDialogInfo *)pBufReturn)->iDaimyoNo = result.�喼�ԍ�;
		strncpy(((TEndingDialogInfo *)pBufReturn)->szEndingTitle, result.�G���f�B���O�^�C�g��.c_str(), 14);
		((TEndingDialogInfo *)pBufReturn)->szEndingTitle[14] = NULL; // �ԕ��B�S�p�łV�����A�S����16�o�C�g�B�ň��ł��Ō�o�C�g��NULL�̕K�v����B
		strncpy(((TEndingDialogInfo *)pBufReturn)->szEndingConditionRewriteMsg, result.�G���f�B���O���b�Z�[�W.c_str(), 42);
		((TEndingDialogInfo *)pBufReturn)->szEndingConditionRewriteMsg[42] = NULL; // �ԕ��B�S�p��21�����A�S����44�o�C�g�̈�B�ň��ł��Ō�o�C�g��NULL�̕K�v����B
		((TEndingDialogInfo *)pBufReturn)->isNeverEnding = result.m_�G���f�B���O�L���t���O;

		// �����������Ƃ����t���O
		return TRUE;
	}
	catch (...) {
	}

	return NULL;
}


void WINAPI snOnApplicationSelectMenuItem(int �I�����j���[�ԍ�) {
	try {
		�J�X�^���쓮�֐�.On_�A�v���P�[�V�������j���[�I����(�I�����j���[�ԍ�);
	} catch(...) {
	}
}


void WINAPI snOnTick(int �V�X�e������, int �O�񍷕��Ԋu) {
	try {
		�J�X�^���쓮�֐�.On_�`�b�N(�V�X�e������, �O�񍷕��Ԋu);
	} catch(...) {
	}
}