#include <cassert>
#include "�Q�[���f�[�^�\��.h"


namespace �֐� {



// �ƕ󖼂��擾����
string Get_�ƕ�( int �ƕ�ԍ��y�z��p�z) {

	// �͈̓`�F�b�N
	if( 0 <= �ƕ�ԍ��y�z��p�z && �ƕ�ԍ��y�z��p�z < �ő吔::�ƕ���::�z�� ) { 

		return string( p�ƕ���[�ƕ�ԍ��y�z��p�z]._�ƕ� );
	} else {
		�f�o�b�O�o��("�w��̉ƕ�ԍ��y�z��p�z�͔͈͊O");
		return string( "" );
	}
}


// �ƕ󖼂�ݒ肷��
void   Set_�ƕ�( int �ƕ�ԍ��y�z��p�z, string �ƕ� ) {

	// �͈̓`�F�b�N
	if( 0 <= �ƕ�ԍ��y�z��p�z && �ƕ�ԍ��y�z��p�z < �ő吔::�ƕ���::�z�� ) { 

		strncpy_s( p�ƕ���[�ƕ�ԍ��y�z��p�z]._�ƕ�, �ƕ�.c_str(), 12 );
		p�ƕ���[�ƕ�ԍ��y�z��p�z]._�ƕ�[12] = NULL;
	} else {
		�f�o�b�O�o��("�w��̉ƕ�ԍ��y�z��p�z�͔͈͊O");
	}
}


WORD Get_�ƕ�ԍ��y�z��p�z(string �ƕ�) {

	for (int iKahouID = 0; iKahouID < �ő吔::�ƕ���::�z��; iKahouID++) {
		if ( Get_�ƕ�(iKahouID) == �ƕ�) {
			return iKahouID;
		}
	}

	return 0xFFFF;

}



}


namespace �֐� {

	// �ƕ�ɂ�鐭���̏グ��
	int Get_�ő吭�ˉƕ�㏸�l(int iBushouID) {
		if (0 <= iBushouID && iBushouID < �ő吔::�������::�z��) {
			int upparam = 0; // �㏸�l
			for (int iKahouID = 0; iKahouID < �ő吔::�ƕ���::�z��; iKahouID++) {
				// ���������^�C�v�F0 ���q  1 ����  2 ����  3 ����  4 �ԓ�  
				if (0 <= p�ƕ���[iKahouID].�ƕ󕪗� && p�ƕ���[iKahouID].�ƕ󕪗� <= 4) {
					// ������Ǝw�蕐������v����
					if (p�ƕ���[iKahouID].���L�����y�����ԍ��z == iBushouID + 1) {
						// ���܂łōő�̏㏸�l
						if (p�ƕ���[iKahouID].�㏸�l > upparam) {
							upparam = p�ƕ���[iKahouID].�㏸�l;
						}
					}
				}
			}
			return upparam;
		}
		else {
			return 0;
		}
	}

	// �ƕ�ɂ��퓬�̏グ��
	int Get_�ő��ˉƕ�㏸�l(int iBushouID) {
		if (0 <= iBushouID && iBushouID < �ő吔::�������::�z��) {
			int upparam = 0; // �㏸�l
			for (int iKahouID = 0; iKahouID < �ő吔::�ƕ���::�z��; iKahouID++) {
				// �퓬�����^�C�v�F5 ����  6 ��  7 �  8 �n  9 ��  A �w�H�D   
				if (5 <= p�ƕ���[iKahouID].�ƕ󕪗� && p�ƕ���[iKahouID].�ƕ󕪗� <= 0xA) {
					// ������Ǝw�蕐������v����
					if (p�ƕ���[iKahouID].���L�����y�����ԍ��z == iBushouID + 1) {
						// ���܂łōő�̏㏸�n
						if (p�ƕ���[iKahouID].�㏸�l > upparam) {
							upparam = p�ƕ���[iKahouID].�㏸�l;
						}
					}
				}
			}
			return upparam;
		}
		else {
			return 0;
		}
	}

	// �ƕ�ɂ��q�d�̏グ��
	int Get_�ő�q�ˉƕ�㏸�l(int iBushouID) {
		if (0 <= iBushouID && iBushouID < �ő吔::�������::�z��) {
			int upparam = 0; // �㏸�l
			for (int iKahouID = 0; iKahouID < �ő吔::�ƕ���::�z��; iKahouID++) {
				// �q�d�����^�C�v�FB ���q�{  C �����Ԗ{
				if (0xB <= p�ƕ���[iKahouID].�ƕ󕪗� && p�ƕ���[iKahouID].�ƕ󕪗� <= 0xC) {
					// ������Ǝw�蕐������v����
					if (p�ƕ���[iKahouID].���L�����y�����ԍ��z == iBushouID + 1) {
						// ���܂łōő�̏㏸�n
						if (p�ƕ���[iKahouID].�㏸�l > upparam) {
							upparam = p�ƕ���[iKahouID].�㏸�l;
						}
					}
				}
			}

			return upparam;
		}
		else {
			return 0;
		}
	}

	// �ƕ�ɂ���]�̏グ��
	int Get_��]�ƕ�㏸�l(int iBushouID) {
		if (0 <= iBushouID && iBushouID < �ő吔::�������::�z��) {
			int upparam = 0; // �㏸�l
			for (int iKahouID = 0; iKahouID < �ő吔::�ƕ���::�z��; iKahouID++) {
				// ��]�����^�C�v�FD ����  E �n���V  F ��؎��v  10 ���n��  11 �\����  12 ����  13 �ʎ蔠  14 �r�[�h���t  15 ���ዾ  16 ���\����  17 ����
				if (0xD <= p�ƕ���[iKahouID].�ƕ󕪗� && p�ƕ���[iKahouID].�ƕ󕪗� <= 0x17) {
					// ������Ǝw�蕐������v����
					if (p�ƕ���[iKahouID].���L�����y�����ԍ��z == iBushouID + 1) {
						// ���܂łōő�̏㏸�n
						if (p�ƕ���[iKahouID].�㏸�l > upparam) {
							upparam = p�ƕ���[iKahouID].�㏸�l;
						}
					}
				}
			}
			return upparam;
		}
		else {
			return 0;
		}
	}


	// ���ʂɂ�閣�͂̏グ��
	int Get_���͊��ʏ㏸�l(int iBushouID) {
		if (0 <= iBushouID && iBushouID < �ő吔::�������::�z��) {
			int upparam = 0; // �㏸�l
			for (int iKaniID = 0; iKaniID < �ő吔::���ʏ��::�z��; iKaniID++) {
				// ������Ǝw�蕐������v����
				if (p���ʏ��[iKaniID].���L�����y�����ԍ��z == iBushouID + 1) {
					// ���܂łōő�̏㏸�n
					if (p���ʏ��[iKaniID].�㏸�l > upparam) {
						upparam = p���ʏ��[iKaniID].�㏸�l;
					}
				}
			}
			return upparam;
		}
		else {
			return 0;
		}
	}




	// �ƕ�𕐏��ɃA�^�b�`����B���X�ʕ����������Ă����ꍇ�́A���̕�������w�肵�������ւƃA�^�b�`���ς��B
	// �\�͒l�̕ύX�𔺂��B���l�ɖ߂��ꍇ�́A0xFFFF���w�肷�邱�ƁB
	bool Set_�ƕ󏊗L�ҕύX(int iKahouID, int iNewBushouID) {
		if (!(0 <= iKahouID && iKahouID < �ő吔::�ƕ���::�z��)) {
			return false;
		}

		// �����͍~�낷
		p�ƕ���[iKahouID].���� = false;
		// ���o��͍~�낷�B
		p�ƕ���[iKahouID].���o�� = false;

		int iOldBushouID = p�ƕ���[iKahouID].���L�����y�����ԍ��z - 1;
		// �{�l���B��������K�v���Ȃ��B
		if (iOldBushouID == iNewBushouID) {
			return true;
		}
		// ���X���l�������Ă��āA�V���Ȏw������l���B��������K�v���Ȃ��B
		if (iOldBushouID >= 0xFFFE && iNewBushouID >= 0xFFFE)  {
			return true;
		}

		// ���������^�C�v�F0 ���q  1 ����  2 ����  3 ����  4 �ԓ�  
		if (0 <= p�ƕ���[iKahouID].�ƕ󕪗� && p�ƕ���[iKahouID].�ƕ󕪗� <= 4) {

			// ���̕����̐����\�͂̑f�l
			int iOldBushouPureGovMax = 0;
			// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
			if (0 <= iOldBushouID && iOldBushouID < �ő吔::�������::�z��) {
				iOldBushouPureGovMax = Get_���ő吭��(iOldBushouID);
				// �s���Ȕԍ��͏��l�Ƃ������Ƃɂ���B
			}
			else {
				iOldBushouID = 0xFFFF;
			}

			int iNewBushouPureGovMax = 0;
			// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
			if (0 <= iNewBushouID && iNewBushouID < �ő吔::�������::�z��) {
				iNewBushouPureGovMax = Get_���ő吭��(iNewBushouID);

				// �s���Ȕԍ��͏��l�Ƃ������Ƃɂ���B
			}
			else {
				iNewBushouID = 0xFFFF;
			}

			// �Ώۂ̉ƕ�̏����҂�ύX����B
			p�ƕ���[iKahouID].���L�����y�����ԍ��z = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

			// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
			if (0 <= iOldBushouID && iOldBushouID < �ő吔::�������::�z��) {
				int iOldBushouGovMaxUpByKahou = Get_�ő吭�ˉƕ�㏸�l(iOldBushouID);
				p�������[iOldBushouID].�ő吭�� = iOldBushouPureGovMax + iOldBushouGovMaxUpByKahou;
			}

			// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
			if (0 <= iNewBushouID && iNewBushouID < �ő吔::�������::�z��) {
				int iNewBushouGovMaxUpByKahou = Get_�ő吭�ˉƕ�㏸�l(iNewBushouID);
				p�������[iNewBushouID].�ő吭�� = iNewBushouPureGovMax + iNewBushouGovMaxUpByKahou;
			}

			// �퓬�����^�C�v�F5 ����  6 ��  7 �  8 �n  9 ��  A �w�H�D   
		}
		else if (5 <= p�ƕ���[iKahouID].�ƕ󕪗� && p�ƕ���[iKahouID].�ƕ󕪗� <= 0xA) {

			// ���̕����̐����\�͂̑f�l
			int iOldBushouPureBatMax = 0;
			// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
			if (0 <= iOldBushouID && iOldBushouID < �ő吔::�������::�z��) {
				iOldBushouPureBatMax = Get_���ő���(iOldBushouID);
				// �s���Ȕԍ��͏��l�Ƃ������Ƃɂ���B
			}
			else {
				iOldBushouID = 0xFFFF;
			}

			int iNewBushouPureBatMax = 0;
			// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
			if (0 <= iNewBushouID && iNewBushouID < �ő吔::�������::�z��) {
				iNewBushouPureBatMax = Get_���ő���(iNewBushouID);

				// �s���Ȕԍ��͏��l�Ƃ������Ƃɂ���B
			}
			else {
				iNewBushouID = 0xFFFF;
			}

			// �Ώۂ̉ƕ�̏����҂�ύX����B
			p�ƕ���[iKahouID].���L�����y�����ԍ��z = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

			// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
			if (0 <= iOldBushouID && iOldBushouID < �ő吔::�������::�z��) {
				int iOldBushouBatMaxUpByKahou = Get_�ő��ˉƕ�㏸�l(iOldBushouID);
				p�������[iOldBushouID].�ő��� = iOldBushouPureBatMax + iOldBushouBatMaxUpByKahou;
			}

			// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
			if (0 <= iNewBushouID && iNewBushouID < �ő吔::�������::�z��) {
				int iNewBushouBatMaxUpByKahou = Get_�ő��ˉƕ�㏸�l(iNewBushouID);
				p�������[iNewBushouID].�ő��� = iNewBushouPureBatMax + iNewBushouBatMaxUpByKahou;
			}


			// �q�d�����^�C�v�FB ���q�{  C �����Ԗ{
		}
		else if (0xB <= p�ƕ���[iKahouID].�ƕ󕪗� && p�ƕ���[iKahouID].�ƕ󕪗� <= 0xC) {

			// ���̕����̐����\�͂̑f�l
			int iOldBushouPureIntMax = 0;
			// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
			if (0 <= iOldBushouID && iOldBushouID < �ő吔::�������::�z��) {
				iOldBushouPureIntMax = Get_���ő�q��(iOldBushouID);
				// �s���Ȕԍ��͏��l�Ƃ������Ƃɂ���B
			}
			else {
				iOldBushouID = 0xFFFF;
			}

			int iNewBushouPureIntMax = 0;
			// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
			if (0 <= iNewBushouID && iNewBushouID < �ő吔::�������::�z��) {
				iNewBushouPureIntMax = Get_���ő�q��(iNewBushouID);

				// �s���Ȕԍ��͏��l�Ƃ������Ƃɂ���B
			}
			else {
				iNewBushouID = 0xFFFF;
			}

			// �Ώۂ̉ƕ�̏����҂�ύX����B
			p�ƕ���[iKahouID].���L�����y�����ԍ��z = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

			// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
			if (0 <= iOldBushouID && iOldBushouID < �ő吔::�������::�z��) {
				int iOldBushouIntMaxUpByKahou = Get_�ő�q�ˉƕ�㏸�l(iOldBushouID);
				p�������[iOldBushouID].�ő�q�� = iOldBushouPureIntMax + iOldBushouIntMaxUpByKahou;
			}

			// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
			if (0 <= iNewBushouID && iNewBushouID < �ő吔::�������::�z��) {
				int iNewBushouIntMaxUpByKahou = Get_�ő�q�ˉƕ�㏸�l(iNewBushouID);
				p�������[iNewBushouID].�ő�q�� = iNewBushouPureIntMax + iNewBushouIntMaxUpByKahou;
			}

			// ��]�����^�C�v�FD ����  E �n���V  F ��؎��v  10 ���n��  11 �\����  12 ����  13 �ʎ蔠  14 �r�[�h���t  15 ���ዾ  16 ���\����  17 ����
		}
		else if (0xD <= p�ƕ���[iKahouID].�ƕ󕪗� && p�ƕ���[iKahouID].�ƕ󕪗� <= 0x17) {

			// ���̕����̐����\�͂̑f�l
			int iOldBushouPureAmbition = 0;
			// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
			if (0 <= iOldBushouID && iOldBushouID < �ő吔::�������::�z��) {
				iOldBushouPureAmbition = Get_����](iOldBushouID);
				// �s���Ȕԍ��͏��l�Ƃ������Ƃɂ���B
			}
			else {
				iOldBushouID = 0xFFFF;
			}

			int iNewBushouPureAmbition = 0;
			// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
			if (0 <= iNewBushouID && iNewBushouID < �ő吔::�������::�z��) {
				iNewBushouPureAmbition = Get_����](iNewBushouID);

				// �s���Ȕԍ��͏��l�Ƃ������Ƃɂ���B
			}
			else {
				iNewBushouID = 0xFFFF; 
			}

			// �Ώۂ̉ƕ�̏����҂�ύX����B
			p�ƕ���[iKahouID].���L�����y�����ԍ��z = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

			// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
			if (0 <= iOldBushouID && iOldBushouID < �ő吔::�������::�z��) {
				int iOldBushouAmbitionUpByKahou = Get_��]�ƕ�㏸�l(iOldBushouID);
				p�������[iOldBushouID].��] = iOldBushouPureAmbition + iOldBushouAmbitionUpByKahou;
			}

			// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
			if (0 <= iNewBushouID && iNewBushouID < �ő吔::�������::�z��) {
				int iNewBushouAmbitionUpByKahou = Get_��]�ƕ�㏸�l(iNewBushouID);
				p�������[iNewBushouID].��] = iNewBushouPureAmbition + iNewBushouAmbitionUpByKahou;
			}

		}

		return true;
	}


	bool Set_�ƕ�㏸�l(int iKahouID, int iNewUpValue) {

		if (!(0 <= iKahouID && iKahouID < �ő吔::�ƕ���::�z��)) {
			return false;
		}

		int iBushouID = p�ƕ���[iKahouID].���L�����y�����ԍ��z - 1;  // �������Ă镐���ԍ����y�z��p�z�ɕύX���čT���Ă���
		int ���o�� = p�ƕ���[iKahouID].���o��;
		int ���� = p�ƕ���[iKahouID].����;

		bool ret = false;
		ret = Set_�ƕ󏊗L�ҕύX(iKahouID, 0xFFFF); // �㏸�l��ω�������O�ɁA���l�ւƕԏシ��
		if (ret == false) {
			return false;
		}

		if (iNewUpValue < 1) {
			iNewUpValue = 1;
		}
		if (iNewUpValue > 10) {
			iNewUpValue = 10;
		}
		p�ƕ���[iKahouID].�㏸�l = iNewUpValue;

		// ���X�����������L���Ă����̂ł����...
		if (0 <= iBushouID && iBushouID < �ő吔::�������::�z��) {
			Set_�ƕ󏊗L�ҕύX(iKahouID, iBushouID);
		}
		// �������������Ă��Ȃ������ꍇ�̂݁A���o���o������̒l�����̂܂�
		else {
			p�ƕ���[iKahouID].���o�� = ���o��;
			p�ƕ���[iKahouID].���� = ����;
		}

		return true;
	}



	bool Set_�ƕ󕪗�(int iKahouID, int �ƕ󕪗�) {

		if (!(0 <= iKahouID && iKahouID < �ő吔::�ƕ���::�z��)) {
			return false;
		}

		int iBushouID = p�ƕ���[iKahouID].���L�����y�����ԍ��z - 1;  // �������Ă镐���ԍ����y�z��p�z�ɕύX���čT���Ă���
		int ���o�� = p�ƕ���[iKahouID].���o��;
		int ���� = p�ƕ���[iKahouID].����;

		bool ret = false;
		ret = Set_�ƕ󏊗L�ҕύX(iKahouID, 0xFFFF); // �ƕ󕪗ނ�ω�������O�ɁA���l�ւƕԏシ��
		if (ret == false) {
			return false;
		}

		if (�ƕ󕪗� < �ƕ󕪗�::���q) {
			�ƕ󕪗� = �ƕ󕪗�::���q;
		}
		if (�ƕ󕪗� > �ƕ󕪗�::����) {
			�ƕ󕪗� = �ƕ󕪗�::����;
		}
		p�ƕ���[iKahouID].�ƕ󕪗� = �ƕ󕪗�;

		// ���X�����������L���Ă����̂ł����...
		if (0 <= iBushouID && iBushouID < �ő吔::�������::�z��) {
			Set_�ƕ󏊗L�ҕύX(iKahouID, iBushouID);
		}
		// �������������Ă��Ȃ������ꍇ�̂݁A���o���o������̒l�����̂܂�
		else {
			p�ƕ���[iKahouID].���o�� = ���o��;
			p�ƕ���[iKahouID].���� = ����;
		}
		return true;
	}


}