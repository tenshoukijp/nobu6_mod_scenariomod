#include <cassert>
#include "�Q�[���f�[�^�\��.h"


namespace �֐� {


// ���ʖ����擾����
string Get_���ʖ�( int ���ʔԍ��y�z��p�z) {

	// �͈̓`�F�b�N
	if ( 0 <= ���ʔԍ��y�z��p�z && ���ʔԍ��y�z��p�z < �ő吔::���ʏ��::�z�� ) { 
		return string( p���ʏ��[���ʔԍ��y�z��p�z]._���ʖ� );
	} else {
		�f�o�b�O�o��("���ʔԍ��y�z��p�z�͔͈͊O");
		return string("");
	}
}


// ���ʖ���ݒ肷��
void   Set_���ʖ�( int ���ʔԍ��y�z��p�z, string ���ʖ� ) {

	// �͈̓`�F�b�N
	if ( 0 <= ���ʔԍ��y�z��p�z && ���ʔԍ��y�z��p�z < �ő吔::���ʏ��::�z�� ) { 
		strncpy_s( p���ʏ��[���ʔԍ��y�z��p�z]._���ʖ�, ���ʖ�.c_str(), 12 );
		p���ʏ��[���ʔԍ��y�z��p�z]._���ʖ�[12] = NULL;
	} else {
		�f�o�b�O�o��("���ʔԍ��y�z��p�z�͔͈͊O");
	}
}


// ���ʂɂ�閣�͂̏グ��
extern int Get_���͊��ʏ㏸�l(int iBushouID);


// ���ʂ𕐏��ɃA�^�b�`����B���X�ʕ����������Ă����ꍇ�́A���̕�������w�肵�������ւƃA�^�b�`���ς��B
// �\�͒l�̕ύX�𔺂��B����ɖ߂��ꍇ�́A0xFFFF���w�肷�邱�ƁB
bool Set_���ʏ��L�ҕύX(int iKaniID, int iNewBushouID) {
	if (!(0 <= iKaniID && iKaniID < �ő吔::���ʏ��::�z��)) {
		return false;
	}

	int iOldBushouID = p���ʏ��[iKaniID].���L�����y�����ԍ��z - 1;
	// �{�l���B��������K�v���Ȃ��B
	if (iOldBushouID == iNewBushouID) {
		return true;
	}
	// ���X���삪�����Ă��āA�V���Ȏw������삾�B��������K�v���Ȃ��B
	if (iOldBushouID >= 0xFFFE && iNewBushouID >= 0xFFFE)  {
		return true;
	}


	// ���̕����̐����\�͂̑f�l
	int iOldBushouPureCharm = 0;
	// �V�����w��̕����͐��K�̕����ł���A����ł͂Ȃ��B
	if (0 <= iOldBushouID && iOldBushouID < �ő吔::�������::�z��) {
		iOldBushouPureCharm = Get_������(iOldBushouID);
		// �s���Ȕԍ��͒���Ƃ������Ƃɂ���B
	}
	else {
		iOldBushouID = 0xFFFF;
	}

	int iNewBushouPureCharm = 0;
	// �V�����w��̕����͐��K�̕����ł���A����ł͂Ȃ��B
	if (0 <= iNewBushouID && iNewBushouID < �ő吔::�������::�z��) {
		iNewBushouPureCharm = Get_������(iNewBushouID);

		// �s���Ȕԍ��͒���Ƃ������Ƃɂ���B
	}
	else {
		iNewBushouID = 0xFFFF;
	}

	// �Ώۂ̉ƕ�̏����҂�ύX����B
	p���ʏ��[iKaniID].���L�����y�����ԍ��z = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

	// ���̕����͐��K�̕����ł���A����ł͂Ȃ��B
	if (0 <= iOldBushouID && iOldBushouID < �ő吔::�������::�z��) {
		int iOldBushouCharmUpByKani = Get_���͊��ʏ㏸�l(iOldBushouID);
		p�������[iOldBushouID].���� = iOldBushouPureCharm + iOldBushouCharmUpByKani;
	}

	// �V�����w��̕����͐��K�̕����ł���A����ł͂Ȃ��B
	if (0 <= iNewBushouID && iNewBushouID < �ő吔::�������::�z��) {
		int iNewBushouCharmUpByKani = Get_���͊��ʏ㏸�l(iNewBushouID);
		p�������[iNewBushouID].���� = iNewBushouPureCharm + iNewBushouCharmUpByKani;
	}

	return true;
}


// 
bool Set_���ʏ㏸�l(int iKaniID, int iNewUpValue) {

	if (!(0 <= iKaniID && iKaniID < �ő吔::���ʏ��::�z��)) {
		return false;
	}

	int iBushouID = p���ʏ��[iKaniID].���L�����y�����ԍ��z - 1;  // �������Ă镐���ԍ����y�z��p�z�ɕύX���čT���Ă���

	bool ret = false;
	ret = Set_���ʏ��L�ҕύX(iKaniID, 0xFFFF); // �㏸�l��ω�������O�ɁA����ւƕԏシ��
	if (ret == false) {
		return false;
	}

	if (iNewUpValue < 1) {
		iNewUpValue = 1;
	}
	if (iNewUpValue > 24) {
		iNewUpValue = 24;
	}
	p���ʏ��[iKaniID].�㏸�l = iNewUpValue;

	// ���X�����������L���Ă����̂ł����...
	if (0 <= iBushouID && iBushouID < �ő吔::�������::�z��) {
		Set_���ʏ��L�ҕύX(iKaniID, iBushouID);
	}

	return true;
}



}