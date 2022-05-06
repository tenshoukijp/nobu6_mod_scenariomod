#include <cassert>
#include "�Q�[���f�[�^�\��.h"


int DeNormalizeDaimyoYakusyokuValue(int iYakusyokuValue) {
	switch (iYakusyokuValue) {
	case ��E::���Α叫�R:
		return 0x01;
	case ��E::�Ǘ�:
		return 0x02;
	case ��E::�֓��Ǘ�:
		return 0x04;
	case ��E::���B�T��:
		return 0x08;
	case ��E::�����T��:
		return 0x10;
	case ��E::��B�T��:
		return 0x20;
	case ��E::�H�B�T��:
		return 0x40;
	default:
		return 0;
	}
}

namespace �֐� {




// �喼ID���琳�K�����ꂽ(0�`7�ւƐU��Ȃ����ꂽ)��EID�𓾂�
int Get_�喼��E(int �喼�ԍ��y�z��p�z) {

	// �͈̓`�F�b�N
	if ( 0 <= �喼�ԍ��y�z��p�z && �喼�ԍ��y�z��p�z < �ő吔::�������::�z�� ) { 

		switch ( p�喼���[�喼�ԍ��y�z��p�z]._��E) {
			case 0x01:
				return ��E::���Α叫�R;
			case 0x02:
				return ��E::�Ǘ�;
			case 0x04:
				return ��E::�֓��Ǘ�;
			case 0x08 :
				return ��E::���B�T��;
			case 0x10:
				return ��E::�����T��;
			case 0x20:
				return ��E::��B�T��;
			case 0x40:
				return ��E::�H�B�T��;
			default:
				return 0;
		}
	}
	return 0;
}

// �R�cID���琳�K�����ꂽ��EID�𓾂�
int Get_�R�c��E(int �R�c�ԍ��y�z��p�z) {

	// �͈̓`�F�b�N
	if ( 0 <= �R�c�ԍ��y�z��p�z && �R�c�ԍ��y�z��p�z < �ő吔::�R�c���::�z�� ) { 

		// �喼���g�Ȃ�A�ʏ���
		if (p�R�c���[�R�c�ԍ��y�z��p�z].�R�c�����ԍ� == 1) {
			int iDaimyoID = p�R�c���[�R�c�ԍ��y�z��p�z].�����喼�y�喼�ԍ��z - 1;
			if (0 <= iDaimyoID && iDaimyoID < �ő吔::�喼���::�z��) {
				return Get_�喼��E(iDaimyoID);
			}
		}

		return p�R�c���[�R�c�ԍ��y�z��p�z]._��E;
	}
	�f�o�b�O�o��("�w��̌R�c�ԍ��y�z��p�z�͔͈͊O");
	return -1;
}


bool Set_�喼��E(int iDaimyoID, int iYakusyokuValue) {
	if (0 <= iDaimyoID && iDaimyoID < �ő吔::�喼���::�z��) {

		if (��E::���� <= iYakusyokuValue && iYakusyokuValue <= ��E::�H�B�T��) {

			int DenormalizeyakusyokuValue = DeNormalizeDaimyoYakusyokuValue(iYakusyokuValue);

			// �喼�ŖړI��ID�̖�E�������Ă���l
			for (int iDID = 0; iDID < �ő吔::�喼���::�z��; iDID++) {
				int iDaimyoYakusyokuID = Get_�喼��E(iDID);
				// ���̖�E�������Ă���΁A�͂��D
				if (iDaimyoYakusyokuID == iYakusyokuValue) {
					p�喼���[iDID]._��E = 0;
				}
			}

			// �R�c�ŖړI��ID�̖�E�������Ă���l
			for (int iGID = 0; iGID < �ő吔::�R�c���::�z��; iGID++) {
				int iGundanYakusyokuID = Get_�R�c��E(iGID);
				// ���̖�E�������Ă���΁A�͂��D
				if (iGundanYakusyokuID == iYakusyokuValue) {
					p�R�c���[iGID]._��E = 0;
				}
			}

			// �����ɑΏۂ̖�E������B
			p�喼���[iDaimyoID]._��E = DenormalizeyakusyokuValue;

			return true;
		}
	}

	return false;
}


bool Set_�R�c��E(int iGundanID, int iYakusyokuValue) {

	if (0 <= iGundanID && iGundanID < �ő吔::�R�c���::�z��) {

		// �喼���g�Ȃ�A�ʏ���
		if (p�R�c���[iGundanID].�R�c�����ԍ� == 1) {
			int iDaimyoID = p�R�c���[iGundanID].�����喼�y�喼�ԍ��z - 1;
			Set_�喼��E(iDaimyoID, iYakusyokuValue);
		}

		if (��E::���� <= iYakusyokuValue && iYakusyokuValue <= ��E::�H�B�T��) {

			// �喼�ŖړI��ID�̖�E�������Ă���l
			for (int iDID = 0; iDID < �ő吔::�喼���::�z��; iDID++) {
				int iDaimyoYakusyokuID = Get_�喼��E(iDID);
				// ���̖�E�������Ă���΁A�͂��D
				if (iDaimyoYakusyokuID == iYakusyokuValue) {
					p�喼���[iDID]._��E = 0;
				}
			}

			// �R�c�ŖړI��ID�̖�E�������Ă���l
			for (int iGID = 0; iGID < �ő吔::�R�c���::�z��; iGID++) {
				int iGundanYakusyokuID = Get_�R�c��E(iGID);
				// ���̖�E�������Ă���΁A�͂��D
				if (iGundanYakusyokuID == iYakusyokuValue) {
					p�R�c���[iGID]._��E = 0;
				}
			}

			// �����ɑΏۂ̖�E������B
			p�R�c���[iGundanID]._��E = iYakusyokuValue;

			return true;
		}
	}

	return false;
}


}