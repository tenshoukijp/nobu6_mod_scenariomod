#include <cassert>
#include <algorithm>
#include "�Q�[���f�[�^�\��.h"






namespace �֐� {


	// �R�c�ɏ������镺���𓾂�
	int Get_�R�c����(int �R�c�ԍ��y�z��p�z) {
		int i���� = 0;
		for (int i = 0; i<�ő吔::�������::�z��; i++) {
			if (p�������[i].�����R�c�y�R�c�ԍ��z - 1 == �R�c�ԍ��y�z��p�z) {
				if (p�����ːЏ��[i].��� <= ���::����) { // �喼, �R�c��, ���� �ŃJ�E���g
					i���� += p�������[i].����;
				}
			}
		}
		return i����;
	}

	// �S�Ă̗L���ȌR�c���X�g�𓾂�
	�ԍ����X�g�^ Get_�R�c�ԍ����X�g�y�z��p�z() {
		�ԍ����X�g�^ list;

		// �Y���̑喼�h�c�ɑ�����R�c�����X�g�ɉ�����
		for (int i�R�cID = 0; i�R�cID < �ő吔::�R�c���::�z��; i�R�cID++) {
			if (p�R�c���[i�R�cID].�R�c���y�����ԍ��z != 0xFFFF) {
				list.push_back(i�R�cID);
			}
		}

		return list;
	}

	�ԍ����X�g�^ Get_�R�c���������ԍ����X�g�y�z��p�z(int �R�c�ԍ��y�z��p�z) {
		// ����ȊO�͉������ꂸ�ɕԂ��B
		�ԍ����X�g�^ list;

		for (int i = 0; i<�ő吔::�������::�z��; i++) {
			if (p�������[i].�����R�c�y�R�c�ԍ��z - 1 == �R�c�ԍ��y�z��p�z) {
				if (p�����ːЏ��[i].��� <= ���::����) { // �喼, �R�c��, ���� �ŃJ�E���g
					list.push_back(i);
				}
			}
		}
		return list;

	}


	// ����̑喼�����̌R�c���X�g�𓾂�
	�ԍ����X�g�^ Get_�喼�����R�c�ԍ����X�g�y�z��p�z(int �喼�ԍ��y�z��p�z) {
		�ԍ����X�g�^ list;

		if (0 <= �喼�ԍ��y�z��p�z && �喼�ԍ��y�z��p�z < �ő吔::�喼���::�z��) {

			// �Y���̑喼�h�c�ɑ�����R�c�����X�g�ɉ�����
			for (int i�R�cID = 0; i�R�cID < �ő吔::�R�c���::�z��; i�R�cID++) {
				if (p�R�c���[i�R�cID].�����喼�y�喼�ԍ��z - 1 == �喼�ԍ��y�z��p�z) {
					list.push_back(i�R�cID);
				}
			}
		}

		return list;
	}


	// �R�c�C���ԍ��̕ύX(����)�����݂�B���s�����false
	bool Set_�R�c�����ԍ��ύX(int iGundanID, int iNewWariateNum) {

		// ��P�R�c�͑喼���g�B�ύX�͖����B
		if (p�R�c���[iGundanID].�R�c�����ԍ� == 1) {
			return false;
		}

		if (!(1 <= iNewWariateNum && iNewWariateNum <= 8)) {
			return false;
		}


		// �����̌R�c�̑喼��ID
		int iDaimyoID = p�R�c���[iGundanID].�����喼�y�喼�ԍ��z - 1;

		// �喼�����ŋ󂫃X���b�g�ƂȂ��Ă���C���ԍ��ꗗ
		if (0 <= iDaimyoID && iDaimyoID < �ő吔::�喼���::�z��) {
			vector<int> sameDaimyoGundanList = Get_�喼�����R�c�ԍ����X�g�y�z��p�z(iDaimyoID);
			int iOldNinmeiNum = p�R�c���[iGundanID].�R�c�����ԍ�; // ���܂ł̔C���ԍ�

			// �ʌR�c���w��̌R�c�𗘗p���Ă���Ȃ�΁A�����̌R�c�ԍ������̌R�c�ɍ����グ��B
			for each (int iGID in sameDaimyoGundanList) {
				// ���łɕʌR�c�ŗ��p����Ă���Ȃ��
				if (p�R�c���[iGID].�R�c�����ԍ� == iNewWariateNum) {
					p�R�c���[iGID].�R�c�����ԍ� = iOldNinmeiNum;
					break;
				}
			}

			// �����͎w��̌R�c�ԍ��ƂȂ�B
			p�R�c���[iGundanID].�R�c�����ԍ� = iNewWariateNum;

			return true;
		}

		return false;

	}


	// �Ƃ���喼�z���̌R�c���ɂ���R�c�����ԍ��̃��X�g�𓾂�B
	// (�ԍ��Ɛ��𗼕��𓾂�B����)
	�ԍ����X�g�^ Get_�R�c�����ԍ����X�g(int �喼�ԍ��y�z��p�z) {

		�ԍ����X�g�^ list;

		if (0 <= �喼�ԍ��y�z��p�z && �喼�ԍ��y�z��p�z < �ő吔::�喼���::�z��) {

			// �Y���̑喼�h�c�ɑ�����R�c�����X�g�ɉ�����
			for (int i�R�cID = 0; i�R�cID < �ő吔::�R�c���::�z��; i�R�cID++) {
				if (p�R�c���[i�R�cID].�����喼�y�喼�ԍ��z - 1 == �喼�ԍ��y�z��p�z) {
					list.push_back(p�R�c���[i�R�cID].�R�c�����ԍ�);
				}
			}
		}

		std::sort(list.begin(), list.end());//�����\�[�g

		return list;
	}

	// �Ƃ���喼�z���̌R�c���ɂ���R�c�u���v�����ԍ��̃��X�g�𓾂�B
	// (�ԍ��Ɛ��𗼕��𓾂�B����)
	�ԍ����X�g�^ Get_�R�c�������ԍ����X�g(int �喼�ԍ��y�z��p�z) {

		// ���蓖�Ă��Ă���̂ɁA�P������
		int �����ԍ��z��[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

		if (0 <= �喼�ԍ��y�z��p�z && �喼�ԍ��y�z��p�z < �ő吔::�喼���::�z��) {

			// �Y���̑喼�h�c�ɑ�����R�c�����X�g�ɉ�����
			for (int i�R�cID = 0; i�R�cID < �ő吔::�R�c���::�z��; i�R�cID++) {
				if (p�R�c���[i�R�cID].�����喼�y�喼�ԍ��z - 1 == �喼�ԍ��y�z��p�z) {
					int g = p�R�c���[i�R�cID].�R�c�����ԍ�;
					if (1 <= g && g <= 8) {
						// ���蓖�Ă��Ă���̂ɁA�P������
						�����ԍ��z��[g - 1] = 1;
					}
				}
			}
		}

		�ԍ����X�g�^ ���������X�g;
		for (int ix = 0; ix<8; ix++) {
			if (�����ԍ��z��[ix] == 0) {
				���������X�g.push_back(ix + 1);
			}
		}

		std::sort(���������X�g.begin(), ���������X�g.end());//�����\�[�g

		return ���������X�g;
	}


	bool Set_�R�c�����喼(int �R�c�ԍ��y�z��p�z, int �V�����喼�ԍ��y�z��p�z) {

		// �V�喼�������ł͂Ȃ��B
		if (!(0 <= �V�����喼�ԍ��y�z��p�z && �V�����喼�ԍ��y�z��p�z < �ő吔::�喼���::�z��)) {
			return false;
		}

		// �R�c���S�����܂��Ă���Ȃ�΁A
		�ԍ����X�g�^ glist = Get_�R�c�����ԍ����X�g(�V�����喼�ԍ��y�z��p�z);
		if (glist.size() == 8) { // �R�c�͑S�����܂��Ă���
			// �����ł��Ȃ�
			return false;
		}

		int iGundanID = �R�c�ԍ��y�z��p�z;

		if (0 <= iGundanID && iGundanID < �ő吔::�R�c���::�z��) {

			// �w��̌R�c�����ݏ������Ă���喼�ԍ������߂�
			int iDaimyoID = p�R�c���[iGundanID].�����喼�y�喼�ԍ��z - 1;
			// �V������̑喼���A���������Ă���喼�ł���΁A�������邱�Ƃ͂Ȃ��B
			if (iDaimyoID == �V�����喼�ԍ��y�z��p�z) {
				return true;
			}

			// �R�c���蓖�Ĕԍ����P�Ԃ͑喼���g�B����͌Œ�B���̏ꍇ�A�����������s�Ƃ���B
			if (p�R�c���[iGundanID].�R�c�����ԍ� == 1) {
				return false;
			}

			// ���݁A�V�喼�ɏ������Ă��āA���̌R�c�y�R�c�ԍ��z��0xFFFF�ɂȂ��Ă���R�c���A�Ԃ牺����ׂ������N���X�g�̍Ōゾ�B
			// �Ԃ牺���邱�Ƃ��o���邩�A���O�Ƀ`�F�b�N���Ă����B
			int iLinkEndGundanID = -1;
			for (int iGID = 0; iGID < �ő吔::�R�c���::�z��; iGID++) {
				// 
				int iCurDaimyoID = p�R�c���[iGID].�����喼�y�喼�ԍ��z - 1;

				// �w��̐V�喼�ɏ������Ă���Ȃ�΁A
				if (iCurDaimyoID == �V�����喼�ԍ��y�z��p�z) {
					// ���̌R�c�������̂ł���΁A�������ŏI�R�c�ԍ�
					if (p�R�c���[iGID].���̌R�c�y�R�c�ԍ��z == 0xFFFF) {
						iLinkEndGundanID = iGID + 1;
					}

				}

			}

			// ���ꂪ�͈͂ɓ����Ă��Ȃ��Ȃ�΁A�V�喼�̌R�c�����N���X�g�́A��������������Ȃ�����񂪉��Ă���B
			// �����I��
			if (!(0 < iLinkEndGundanID && iLinkEndGundanID <= �ő吔::�R�c���::�z��)) {
				return false;
			}

			/* �@���R�c
			��
			��-��-��-��

			�Ƃ����̂�

			��-��-��

			�Ƃ���B
			*/

			int iPrevID = p�R�c���[iGundanID].�O�̌R�c�y�R�c�ԍ��z;
			int iNextID = p�R�c���[iGundanID].���̌R�c�y�R�c�ԍ��z;

			// ������prev�͗L���ȌR�c���B
			if (0 < iPrevID && iPrevID <= �ő吔::�R�c���::�z��) {

				// �������擪�ł͂Ȃ��R�c�ŁA
				// �P�O�̌R�c�̎��̃����N�悪���R�c�̏ꍇ
				if (iPrevID != 0xFFFF && p�R�c���[(iPrevID - 1)].���̌R�c�y�R�c�ԍ��z == iGundanID + 1) {
					// ���R�c�ł͂Ȃ��A���̌R�c�ւƌq��������B
					p�R�c���[(iPrevID - 1)].���̌R�c�y�R�c�ԍ��z = iNextID;
				}
			}

			// ������next�͗L���ȌR�c���B
			if (0 < iNextID && iNextID <= �ő吔::�R�c���::�z��) {
				// �P��̌R�c�̑O�̃����N�悪���R�c�̏ꍇ
				if (iNextID != 0xFFFF && p�R�c���[(iNextID - 1)].�O�̌R�c�y�R�c�ԍ��z == iGundanID + 1) {
					// ���R�c�ł͂Ȃ��A�O�̌R�c�ւƌq��������B
					p�R�c���[(iNextID - 1)].�O�̌R�c�y�R�c�ԍ��z = iPrevID;
				}
			}


			/* �@

			��-��

			�Ƃ����̂�

			��-��-��

			�Ƃ���B
			*/



			p�R�c���[iLinkEndGundanID - 1].���̌R�c�y�R�c�ԍ��z = iGundanID + 1; // �����N���X�g�̍Ō�̌R�c��next�����R�c��

			p�R�c���[iGundanID].�O�̌R�c�y�R�c�ԍ��z = iLinkEndGundanID; // ���R�c�̑O�̌R�c�́A�R�c�̃����N���X�g�̍Ō�̌R�c

			// ���R�c�́A�R�c���X�g�̈�ԍŌ�ɂ������B���R�c��next�͋��Ȃ�
			p�R�c���[iGundanID].���̌R�c�y�R�c�ԍ��z = 0xFFFF; // 

			// ��������������
			{
				p�R�c���[iGundanID].�R�c�����ԍ� = 8; // �����s���ɂȂ��Ă��܂��Ă��邪�����Ƃ������m���ŃZ�[�t�Ȃ��̂����

				�ԍ����X�g�^ milist = Get_�R�c�������ԍ����X�g(�V�����喼�ԍ��y�z��p�z);
				if (milist.size() > 0) {
					p�R�c���[iGundanID].�R�c�����ԍ� = milist[0]; // ��ԍ��̍ŏ��̂��̂���荞��
				}

				p�R�c���[iGundanID].�����喼�y�喼�ԍ��z = �V�����喼�ԍ��y�z��p�z + 1;
			}

			for (int iBushouID = 0; iBushouID < �ő吔::�������::�z��; iBushouID++) {
				// �w��̌R�c�ɏ������Ă��镐���́A�S�āA�V�喼�ɏ�����ύX����B
				if (p�������[iBushouID].�����R�c�y�R�c�ԍ��z == iGundanID + 1) {
					p�������[iBushouID].�����喼�y�喼�ԍ��z = �V�����喼�ԍ��y�z��p�z + 1;
					p�������[iBushouID].�d���N�� = 0; // �m���N�����Z�b�g
					p�������[iBushouID].������喼�y�喼�ԍ��z = 0xFFFF; // �����惊�Z�b�g
					p�������[iBushouID].������� = 0; // ������ԂȂ�
					p�������[iBushouID].�⍦��� = 0; // �⍦�Ȃ�
				}
			}


			return true;

		}

		return false;
	}

}

/*
�R�c�ԍ��������Ƃ��āA�R�t�̕����ԍ��𓾂�
*/
int pCallFromFuncGetGunshiBushouID = 0x454BE9; //

int iReturnOfBushouIDGetGunshiBushou = 0xFFFF;
int iSigOfGundanIDGetGunshiBushou = 0xFFFF;

void _FuncGetGunshiBushouIDAsm() {
	__asm {
		// �R�c�ԍ�������
		MOV     ESI, iSigOfGundanIDGetGunshiBushou

			// �R�c�ԍ��������Ƃ��āA�R�t�ԍ��𓾂邽�߂̊֐����Ăяo��
			PUSH    ESI
			CALL    pCallFromFuncGetGunshiBushouID
			ADD     ESP, 4

			MOV iReturnOfBushouIDGetGunshiBushou, EAX // ���ʂ̂����AAX�̔ԍ����R�t�����ԍ��Ƃ��ĕۑ�

	}
}

namespace �֐� {
	// �R�c�̌R�t�����𓾂�B�R�t����҂����Ȃ����0xFFFF���Ԃ��Ă���B
	int Get_�R�t�����ԍ��y�z��p�z(int �R�c�ԍ��y�z��p�z) {

		if (0 <= �R�c�ԍ��y�z��p�z && �R�c�ԍ��y�z��p�z < �ő吔::�R�c���::�z��) {

			iSigOfGundanIDGetGunshiBushou = �R�c�ԍ��y�z��p�z + 1; // �z��p���R�c�ɕύX

			iReturnOfBushouIDGetGunshiBushou = 0xFFFF; // �܂��́A���x���̒l�Ń��Z�b�g�B

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
			_FuncGetGunshiBushouIDAsm();

			__asm {
				pop edi
					pop esi
					pop esp
					pop edx
					pop ecx
					pop ebx
					pop eax
			}

			iReturnOfBushouIDGetGunshiBushou = iReturnOfBushouIDGetGunshiBushou & 0xFFFF; // EAX�̂����AAX�̕����������p����B

			// ���̌R�c�ɌR�t�������Ȃ��
			if (0 <= iReturnOfBushouIDGetGunshiBushou - 1 && iReturnOfBushouIDGetGunshiBushou - 1 < �ő吔::�������::�z��) {
				return iReturnOfBushouIDGetGunshiBushou - 1; // �����ԍ��������ԍ��z��p�ɂ��ĕԂ�
			}
		}

		// ���Ȃ��ꍇ��s���ȏꍇ�͑S������B
		return 0xFFFF;
	}


	�R�c�V�݌����^ Get_�R�c�V�݌����(int �喼�ԍ��y�z��p�z) {
		�R�c�V�݌����^ ret;
		ret.�喼�ԍ��y�z��p�z = �喼�ԍ��y�z��p�z;
		ret.���R�c�����ԍ����X�g = �ԍ����X�g�^();
		ret.����ԍ��y�z��p�z���X�g = �ԍ����X�g�^();
		ret.��═���ԍ��y�z��p�z���X�g = �ԍ����X�g�^();
		ret.Is�V�݉\ = FALSE;

		if (!(0 <= �喼�ԍ��y�z��p�z && �喼�ԍ��y�z��p�z < �ő吔::�喼���::�z��)) {
			�f�o�b�O�o�� << "�喼�ԍ��y�z��p�z���͈͊O" << endl;
			return ret;
		}

		bool is_gundan_has_empty_slot = false;
		for (int iGundanID = 0; iGundanID < �ő吔::�R�c���::�z��; iGundanID++) {
			if (p�R�c���[iGundanID].�����喼�y�喼�ԍ��z == 0xFFFF &&
				p�R�c���[iGundanID].��������y��ԍ��z == 0xFFFF &&
				p�R�c���[iGundanID].���̌R�c�y�R�c�ԍ��z == 0xFFFF) {
				is_gundan_has_empty_slot = true;
				break;
			}
		}
		if (is_gundan_has_empty_slot == false) {
			�f�o�b�O�o�� << "�R�c���ő傽��" << �ő吔::�R�c���::�z�� << "���S�Ė��܂��Ă���" << endl;
			return ret;
		}

		int iDaimyoBushouID = p�喼���[�喼�ԍ��y�z��p�z].�喼�y�����ԍ��z - 1;
		// ����ŊY���R�c�Ƀ^�[�������Ԃ̊댯�ȃ^�C�~���O�B���̃^�C�~���O�͏��F�҂��������Ă��Ȃ��̂ŁA�V�݂ł��Ȃ����̂Ƃ���B
		if (p�����ːЏ��[iDaimyoBushouID].�펀 || (p�����ːЏ��[iDaimyoBushouID].��� == ���::���S)) {
			return ret;
		}

		// ���蓖�Č��͗v����ɁA�܂����蓖�Ă��Ă��Ȃ��R�c�ԍ��̂���
		ret.���R�c�����ԍ����X�g = Get_�R�c�������ԍ����X�g(�喼�ԍ��y�z��p�z);

		// �w��̑喼���x�z���Ă���S��̃��X�g
		auto �喼�����郊�X�g = Get_�喼������ԍ����X�g�y�z��p�z(�喼�ԍ��y�z��p�z);

		// ���ɂ���̂́A�w��̑喼�Ǝx�z��̂����A�u�喼�v���u�R�c���v�����Ȃ���B
		// �����A�u��{���v�̂��̂Ɍ���
		for each(int iCastleID in �喼�����郊�X�g) {
			if (p����[iCastleID].�{�� == ��::�{��::��{��) {
				ret.����ԍ��y�z��p�z���X�g.push_back(iCastleID);
			}
		}

		for (int iBushouID = 0; iBushouID < �ő吔::�������::�z��; iBushouID++) {

			// �܂��Ώۂ̕����́A�w��̑喼�Ƃ̐l�Ԃł���B(�喼�܂�)
			if (p�������[iBushouID].�����喼�y�喼�ԍ��z - 1 == �喼�ԍ��y�z��p�z) {

				// �����ł���B(=�喼��R�c����q���ł͂Ȃ��A�������A�o�ꂵ�Ă����ʕ���)
				if (p�����ːЏ��[iBushouID].��� == ���::����) {
					// �펀���ł͂Ȃ�
					if (!p�����ːЏ��[iBushouID].�펀) {
						ret.��═���ԍ��y�z��p�z���X�g.push_back(iBushouID);
					}
				}
			}
		}

		// �R�c�����łɂW����
		if (ret.���R�c�����ԍ����X�g.size() == 0) {
			ret.Is�V�݉\ = FALSE;
			return ret;
		}

		// �V�R�c�����}�������悤�ȗ]������͑��݂��Ȃ�
		if (ret.����ԍ��y�z��p�z���X�g.size() == 0) {
			ret.Is�V�݉\ = FALSE;
			return ret;
		}

		// ���������R�c���ɔC�����ׂ��Ώۂ̈�ʕ��������݂��Ȃ�
		if (ret.��═���ԍ��y�z��p�z���X�g.size() == 0) {
			ret.Is�V�݉\ = FALSE;
			return ret;
		}

		ret.Is�V�݉\ = TRUE;

		return ret;
	}


	int Set_�R�c�V��(int �����ԍ��y�z��p�z, int ��ԍ��y�z��p�z, �R�c�V�݌����^ ���S�`�F�b�N�p�R�c�V�݌����) {
		if (���S�`�F�b�N�p�R�c�V�݌����.Is�V�݉\ == FALSE) {
			�f�o�b�O�o�� << "�R�c�V�݌����^.Is�V�݉\ �� FALSE" << endl;
			return 0xFFFF;
		}

		// ���O������
		auto& check = ���S�`�F�b�N�p�R�c�V�݌����;
		auto& bushous = check.��═���ԍ��y�z��p�z���X�g;
		auto& castles = check.����ԍ��y�z��p�z���X�g;
		auto& gwariates = check.���R�c�����ԍ����X�g;
		if (bushous.size() == 0 || castles.size() == 0 || gwariates.size() == 0){
			�f�o�b�O�o�� << "�R�c�V�݌����^�̒��g�f�[�^���s��" << endl;
			return 0xFFFF;
		}

		auto bitr = std::find(bushous.begin(), bushous.end(), �����ԍ��y�z��p�z);
		// �������ȊO���w�肵�Ă���B
		if (bitr == bushous.end()) {
			�f�o�b�O�o�� << "�����ԍ��y�z��p�z �� �R�c�V�݌����^.��═���ԍ��y�z��p�z���X�g �ɂȂ�" << endl;
			return 0xFFFF;
		}

		auto citr = std::find(castles.begin(), castles.end(), ��ԍ��y�z��p�z);
		// ����ȊO���w�肵�Ă���B
		if (citr == castles.end()) {
			�f�o�b�O�o�� << "��ԍ��y�z��p�z �� �R�c�V�݌����^..����ԍ��y�z��p�z���X�g �ɂȂ�" << endl;
			return 0xFFFF;
		}

		// �����X���b�g��T��
		int iSelfGundanID = 0xFFFF;
		for (int iGundanID = 0; iGundanID < �ő吔::�R�c���::�z��; iGundanID++) {
			if (p�R�c���[iGundanID].�����喼�y�喼�ԍ��z == 0xFFFF &&
				p�R�c���[iGundanID].��������y��ԍ��z == 0xFFFF &&
				p�R�c���[iGundanID].���̌R�c�y�R�c�ԍ��z == 0xFFFF) {
				iSelfGundanID = iGundanID;
				break;
			}
		}

		// �Ȃ��������B���S�`�F�b�N�p�R�c�V�݌���̎擾�̌�ASet_�R�c�V�݂��Ăԃ^�C�~���O������Ă���̂��낤�B
		if (iSelfGundanID == 0xFFFF) {
			return 0xFFFF;
		}


		// �܂��́A�R�c�ꗗ�̒����玩�����Ԃ牺����ׂ��R�c��T���B
		// ����́u�����喼�ԍ��v�ɏ������Ă��Ȃ���u���̌R�c�y�R�c�ԍ��z�v��65535 ���Ȃ킿�A
		// �����N���X�g�̖����ɏ������Ă���R�c�ł���B
		int iPrevGundanID = 0xFFFF;
		for (int iGundanID = 0; iGundanID < �ő吔::�R�c���::�z��; iGundanID++) {
			// �喼����v
			if (p�R�c���[iGundanID].�����喼�y�喼�ԍ��z == check.�喼�ԍ��y�z��p�z + 1) {
				// �Ώۂ̑喼���̌R�c�ꗗ�̂����A�����̌R�c
				if (p�R�c���[iGundanID].���̌R�c�y�R�c�ԍ��z == 0xFFFF) {
					iPrevGundanID = iGundanID;
				}
			}
		}


		if (iPrevGundanID == 0xFFFF) {
			return 0xFFFF;
		}

		// �ȏ���N���A���Ă���΁A�܂����v���낤�B

		// -------------------------------------------------------------------
		// �P�O�̌R�c�̎������g�Ƃ���
		p�R�c���[iPrevGundanID].���̌R�c�y�R�c�ԍ��z = iSelfGundanID + 1;


		// -------------------------------------------------------------------
		// �����̑O�̌R�c�Ƃ��āA�����N���X�g�����̍Ō�̌R�c�ԍ�������
		p�R�c���[iSelfGundanID].�O�̌R�c�y�R�c�ԍ��z = iPrevGundanID + 1;
		// �������g�������N���X�g�̍Ō�B
		p�R�c���[iSelfGundanID].���̌R�c�y�R�c�ԍ��z = 0xFFFF;

		// �󂢂Ă��邤���ŁA��ԎႢ�ԍ�������B
		p�R�c���[iSelfGundanID].�R�c�����ԍ� = gwariates[0];

		p�R�c���[iSelfGundanID].�����喼�y�喼�ԍ��z = check.�喼�ԍ��y�z��p�z + 1;

		p�R�c���[iSelfGundanID].��������y��ԍ��z = ��ԍ��y�z��p�z + 1;

		p�R�c���[iSelfGundanID].�R�c���y�����ԍ��z = �����ԍ��y�z��p�z + 1;

		p�R�c���[iSelfGundanID].�s���� = 50;

		Set_�R�c��E(iSelfGundanID, ��E::����);

		p�R�c���[iSelfGundanID].�� = 1000;
		p�R�c���[iSelfGundanID].�� = 1000;

		p�R�c���[iSelfGundanID].�S�C = 100;
		p�R�c���[iSelfGundanID].�n = 100;



		// -------------------------------------------------------------------
		// ��̏��⃊���N���X�g��ύX����
		p����[��ԍ��y�z��p�z].�����R�c�y�R�c�ԍ��z = iSelfGundanID + 1;

		p����[��ԍ��y�z��p�z].�{�� = �{��::�R�c��;

		// �������g(��)�������N���X�g����O���B
		// �O�̏�́u���̏�v���A���g�ł͂Ȃ��A�u���g�̎��̏�v�ɂ���B
		if (p����[��ԍ��y�z��p�z].�O�̏�y��ԍ��z != 0 && p����[��ԍ��y�z��p�z].�O�̏�y��ԍ��z != 0xFFFF) {
			int _prev = p����[��ԍ��y�z��p�z].�O�̏�y��ԍ��z - 1;
			p����[_prev].���̏�y��ԍ��z = p����[��ԍ��y�z��p�z].���̏�y��ԍ��z;
		}

		// ���̏�́u�O�̏�v���A���g�ł͂Ȃ��A�u���g�̑O�̏�v�ɂ���B
		if (p����[��ԍ��y�z��p�z].���̏�y��ԍ��z != 0 && p����[��ԍ��y�z��p�z].���̏�y��ԍ��z != 0xFFFF) {
			int _next = p����[��ԍ��y�z��p�z].���̏�y��ԍ��z - 1;
			p����[_next].�O�̏�y��ԍ��z = p����[��ԍ��y�z��p�z].�O�̏�y��ԍ��z;
		}


		// �V�݂Ȃ̂Ŏ������擪�͊m��
		p����[��ԍ��y�z��p�z].�O�̏�y��ԍ��z = 0;
		// �V�݂Ȃ̂Ŏ������Ō�͊m��
		p����[��ԍ��y�z��p�z].���̏�y��ԍ��z = 0xFFFF;

		// -------------------------------------------------------------------

		// -------------------------------------------------------------------
		// �{�l�̃p�����[�^
		// �Ώۂ̕����́A�Y����ւ̈ړ�
		Set_�����]��(�����ԍ��y�z��p�z, ��ԍ��y�z��p�z);

		Set_���(�����ԍ��y�z��p�z);

		p�����ːЏ��[�����ԍ��y�z��p�z].��� = ���::�R�c��;

		// �Y���̏�ɋ���l�B�̏����R�c�̏�������
		for (int iBushouID = 0; iBushouID < �ő吔::�������::�z��; iBushouID++) {
			if (p�������[iBushouID].�����喼�y�喼�ԍ��z == check.�喼�ԍ��y�z��p�z + 1) {
				if (p�������[iBushouID].��������y��ԍ��z == ��ԍ��y�z��p�z + 1) {
					if (p�����ːЏ��[iBushouID].��� == ���::�R�c�� || p�����ːЏ��[iBushouID].��� == ���::����) {
						// �펀���ł͂Ȃ�
						if (!p�����ːЏ��[iBushouID].�펀) {
							p�������[iBushouID].�����R�c�y�R�c�ԍ��z = iSelfGundanID + 1;
						}
					}
				}
			}
		}

		return iSelfGundanID;
	}


	bool Set_��{���鏊���R�c(int ��ԍ��y�z��p�z, int �V�R�c�ԍ��y�z��p�z) {

		if (!(0 <= ��ԍ��y�z��p�z && ��ԍ��y�z��p�z < �ő吔::����::�z��)) {
			�f�o�b�O�o�� << "��ԍ����͈͊O" << endl;
			return false;
		}

		if (p����[��ԍ��y�z��p�z].�{�� == �{��::�R�c�� || p����[��ԍ��y�z��p�z].�{�� == �{��::�喼) {
			�f�o�b�O�o�� << "�喼��R�c���̖{���n�͏����҂��ړ��ł��Ȃ�" << endl;
			return false;
		}

		if (!(0 <= �V�R�c�ԍ��y�z��p�z && �V�R�c�ԍ��y�z��p�z < �ő吔::�R�c���::�z��)) {
			�f�o�b�O�o�� << "�R�c�ԍ����͈͊O" << endl;
			return false;
		}

		int iGundanID = p����[��ԍ��y�z��p�z].�����R�c�y�R�c�ԍ��z-1;

		if (!(0 <= iGundanID && iGundanID < �ő吔::�R�c���::�z��)) {
			�f�o�b�O�o�� << "��ԍ��������炭��������" << endl;
			return false;
		}

		int iOrgDaimyoID = p�R�c���[iGundanID].�����喼�y�喼�ԍ��z - 1;
		int iDstDaimyoID = p�R�c���[�V�R�c�ԍ��y�z��p�z].�����喼�y�喼�ԍ��z - 1;

		if (iOrgDaimyoID != iDstDaimyoID) {
			�f�o�b�O�o�� << "��ԍ��ƐV�R�c�ԍ��������喼�̂��̂ł͂Ȃ�" << endl;
			return false;
		}

		// -------------------------------------------------------------------
		// �܂��A���̌R�c�̏郊���N���X�g����A�����̏���O��
		p����[��ԍ��y�z��p�z].�����R�c�y�R�c�ԍ��z = �V�R�c�ԍ��y�z��p�z + 1;

		// �������g(��)�������N���X�g����O���B
		// �O�̏�́u���̏�v���A���g�ł͂Ȃ��A�u���g�̎��̏�v�ɂ���B
		if (p����[��ԍ��y�z��p�z].�O�̏�y��ԍ��z != 0 && p����[��ԍ��y�z��p�z].�O�̏�y��ԍ��z != 0xFFFF) {
			int _prev = p����[��ԍ��y�z��p�z].�O�̏�y��ԍ��z - 1;
			p����[_prev].���̏�y��ԍ��z = p����[��ԍ��y�z��p�z].���̏�y��ԍ��z;
		}

		// ���̏�́u�O�̏�v���A���g�ł͂Ȃ��A�u���g�̑O�̏�v�ɂ���B
		if (p����[��ԍ��y�z��p�z].���̏�y��ԍ��z != 0 && p����[��ԍ��y�z��p�z].���̏�y��ԍ��z != 0xFFFF) {
			int _next = p����[��ԍ��y�z��p�z].���̏�y��ԍ��z - 1;
			p����[_next].�O�̏�y��ԍ��z = p����[��ԍ��y�z��p�z].�O�̏�y��ԍ��z;
		}

		// -------------------------------------------------------------------
		// ���ɁA�V�R�c�̏郊���N���X�g�̍Ō�̏��T��
		int iTailCastleID = 0xFFFF;
		for (int iCastleID = 0; iCastleID < �ő吔::����::�z��; iCastleID++) {
			// �Ώۂ̏�̏����R�c���A�w��̐V�R�c�ł���
			if (p����[iCastleID].�����R�c�y�R�c�ԍ��z - 1 == �V�R�c�ԍ��y�z��p�z) {
				// ���̏邪�����N���X�g�̍Ō�̏�ł���Ȃ��
				if (p����[iCastleID].���̏�y��ԍ��z == 0xFFFF) {
					iTailCastleID = iCastleID;
					break;
				}
			}
		}

		if (iTailCastleID == 0xFFFF) {
			�f�o�b�O�o�� << "�ُ펖��!! ��̃����N���X�g�����Ă���!!" << endl;
			return false;
		}

		// �����͐V�R�c�ł̓����N���X�g�̖����͊m��Ȃ̂Ŏ��̏�͂Ȃ�
		p����[��ԍ��y�z��p�z].���̏�y��ԍ��z = 0xFFFF;

		// �����̂P�O�́A����܂Ŗ�����������̔ԍ�
		p����[��ԍ��y�z��p�z].�O�̏�y��ԍ��z = iTailCastleID + 1;

		// ����܂Ń����N���X�g�̖�����������̎��̏邪����
		p����[iTailCastleID].���̏�y��ԍ��z = ��ԍ��y�z��p�z + 1;

		// -------------------------------------------------------------------
		// ���̏�ɂ��镐���B�̏�����ύX����
		// �Y���̏�ɋ���l�B�̏����R�c�̏�������
		for (int iBushouID = 0; iBushouID < �ő吔::�������::�z��; iBushouID++) {
			if (p�������[iBushouID].�����喼�y�喼�ԍ��z == iOrgDaimyoID + 1) {
				if (p�������[iBushouID].��������y��ԍ��z == ��ԍ��y�z��p�z + 1) {
					if (p�����ːЏ��[iBushouID].��� == ���::�R�c�� || p�����ːЏ��[iBushouID].��� == ���::����) {
						// �펀���ł͂Ȃ�
						if (!p�����ːЏ��[iBushouID].�펀) {
							p�������[iBushouID].�����R�c�y�R�c�ԍ��z = �V�R�c�ԍ��y�z��p�z + 1;
						}
					}
				}
			}
		}

		return true;

	}

	// �Ɩ�����߂Ă���A���S(�Ƃ������R�Â��f�[�^)���s���Ȃ̂ŁA
	// �Ƃ肠�����A�ȈՂȂ��̂ő�p
	static int _Get_Stub_�喼�a�����Ɩ�(int �����ԍ��y�z��p�z) {

		if ( ! (0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z��) ) {
			�f�o�b�O�o�� << "_Get_�喼�a�����Ɩ�̕����ԍ����͈͊O" << endl;

			return 0; // �Ԃ��悤���Ȃ��̂ŁA��U�M���̂ɂ��Ă����B
		}



		const int �Ō�̐��K�̉Ɩ�̍ő吔 = 16 * 7; // �u�Ɩ�ҏW��ʂł݂�ƁA�܂������V�i�ڂ��炢�܂ł����K�Ɩ�v�u�Ō�̂P�i�̓��[�U�[�Ɩ�v�u�Ԃ̂Q�s�͒ʏ�͏o���ׂ����̂ł͂Ȃ��n�Y�v

		// ���K�Ɩ�S�̂̔z��(�A���A
		map<int, int> ���K�̗]��Ɩ䃊�X�g;
		for (int k = 0; k < �Ō�̐��K�̉Ɩ�̍ő吔; k++) {
			���K�̗]��Ɩ䃊�X�g.insert(map<int, int>::value_type(k, k));
		}

		// ���łɑ喼���g���Ă���Ɩ���A���K�̗]��Ɩ䃊�X�g���珜�����邱�ƂŁA���g�p�̂��̂����ɂ���
		for (int iDaimyoID = 0; iDaimyoID < �ő吔::�喼���::�z��; iDaimyoID++) {

			int kamon = p�喼���[iDaimyoID].�Ɩ�;

			// �Ώۂ̉Ɩ�ԍ������X�g�ɂȂ��Ȃ�A(���K�Ɩ�ȊO�Ȃ瑊��ɂ��Ȃ�)
			���K�̗]��Ɩ䃊�X�g.erase(kamon);
		}

		int bloodNormalized = p�������[�����ԍ��y�z��p�z].��������;
		if (bloodNormalized >= �Ō�̐��K�̉Ɩ�̍ő吔) { bloodNormalized = �Ō�̐��K�̉Ɩ�̍ő吔 - 1; }

		// ���K�̗]��Ɩ䃊�X�g�ɁA�喼�̕����̌��ؔԍ��Ɠ����Ɩ�ԍ������g�p�ł��܂��Ă�Ȃ炻��ɂ��Ă���(���ؔԍ��ƉƖ�ԍ���72���炢�܂ł͈�v���Ă��邽��)
		if (���K�̗]��Ɩ䃊�X�g.count(bloodNormalized) > 0) {
			; // �������Ȃ��BbloodNormalized�̂��̂܂܂̐��l���̗p
		}
		// ���K���X�g���ɁA�喼�̕����̌��ؔԍ��Ɠ����Ɩ�ԍ��������ꍇ�́A���K�̗]��Ɩ䃊�X�g(�̗]���Ă��)
		else {

			// �����Ɠ����Ɩ䂪���܂��Ă���ꍇ�A72�Ԉȉ��́A���������ւ̖��ړx������������ɁA�L���Ȃ��̂��������낤����A
			// 72�Ԃ��傫�Ȃ��̂̂����A��ԑ傫�Ȃ��̂�I�ԁB
			for (int k = �Ō�̐��K�̉Ɩ�̍ő吔; k > 72; k--) {
				if (���K�̗]��Ɩ䃊�X�g.count(k) > 0) {
					bloodNormalized = k;
					return bloodNormalized;
				}
			}

			// ��` 72�Ԃ��傫���̂��S�Ė��܂��Ă�Ȃ� �Ȃ�ł��ǂ��Ƃ��邵���Ȃ����낤�B
			auto itr = ���K�̗]��Ɩ䃊�X�g.begin();
			bloodNormalized = itr->first;

		}

		return bloodNormalized;
	}


	int Set_�R�c�Ɨ�(int �R�c�ԍ��y�z��p�z) {
		if (!(0 <= �R�c�ԍ��y�z��p�z && �R�c�ԍ��y�z��p�z < �ő吔::�R�c���::�z��)) {
			return 0xFFFF;
		}

		int iSelfDaimyoID = 0xFFFF;
		for (int iDaimyoID = 0; iDaimyoID < �ő吔::�喼���::�z��; iDaimyoID++) {
			// �����Ă���Ƃ��������͈ȉ��̂Q�ł킩�邾�낤�B
			if (p�喼���[iDaimyoID].�喼�y�����ԍ��z == 0xFFFF &&
				p�喼���[iDaimyoID].�����R�c�y�R�c�ԍ��z == 0xFFFF) {
				iSelfDaimyoID = iDaimyoID;
				break;
			}
		}

		// �󂫂��Ȃ�������_��
		if (iSelfDaimyoID == 0xFFFF) {
			return 0xFFFF;
		}

		int iNewDaimyoBushouID = p�R�c���[�R�c�ԍ��y�z��p�z].�R�c���y�����ԍ��z - 1;
		// �f�o�b�O�o�� << Get_���O(iNewDaimyoBushouID) << endl;
		int iNewDaimyoCastleID = p�R�c���[�R�c�ԍ��y�z��p�z].��������y��ԍ��z - 1;
		// �f�o�b�O�o�� << Get_�閼(iNewDaimyoCastleID) << endl;
		// �R�c���ȊO���w�肳��Ă���B�����A�喼���g��(��P�R�c������)�R�c�ԍ����w�肳��Ă���B
		if (p�����ːЏ��[iNewDaimyoBushouID].��� != ���::�R�c��) {
			return 0xFFFF;
		}

		// ���Ŏ���ł��āA���C����ʂɖ߂�O�B�_��
		if (p�����ːЏ��[iNewDaimyoBushouID].�펀) {
			return 0xFFFF;
		}
		
		// ----------------------------------------------------
		// �S�~�|��
		p�喼���[iSelfDaimyoID].�B�������y�����ԍ��z = 0xFFFF;
		p�喼���[iSelfDaimyoID].�G�Α喼�y�喼�ԍ��z = 0xFF;
		p�喼���[iSelfDaimyoID].�F�D�喼�y�喼�ԍ��z = 0xFF;
		p�喼���[iSelfDaimyoID].���l = 50;
		p�喼���[iSelfDaimyoID].�z���� = 0;
		p�喼���[iSelfDaimyoID].�]��� = 0;
		p�喼���[iSelfDaimyoID].���l�s�� = 0;
		if (p�������[iNewDaimyoBushouID].�E�� == �E��::����) {
			p�喼���[iSelfDaimyoID].���� = 30;
		}
		else {
			p�喼���[iSelfDaimyoID].���� = 0;
		}


		p�喼���[iSelfDaimyoID].�Ɩ� = _Get_Stub_�喼�a�����Ɩ�(iNewDaimyoBushouID);

		Set_�喼��E(iSelfDaimyoID, ��E::����);

		// ----------------------------------------------------
		// �Ώۂ̌R�c���́A�l�Ƃ��đ喼�ƂȂ�
		p�����ːЏ��[iNewDaimyoBushouID].��� = ���::�喼;
		p�����ːЏ��[iNewDaimyoBushouID].�g�� = �g��::�喼;

		// �܂��͐V�݂����喼�Ƃ̑喼�́A�w��̌R�c����V�ݑ喼�̕�����
		p�喼���[iSelfDaimyoID].�喼�y�����ԍ��z = iNewDaimyoBushouID + 1;
		// �喼�̖{��P�R�c�ƂȂ�
		p�喼���[iSelfDaimyoID].�����R�c�y�R�c�ԍ��z = �R�c�ԍ��y�z��p�z + 1;

		// ----------------------------------------------------
		// ���݂̌R�c�̏����喼���A�V�݂̑喼ID�ɋA��
		p�R�c���[�R�c�ԍ��y�z��p�z].�����喼�y�喼�ԍ��z = iSelfDaimyoID + 1;

		// �����ԍ��͂P�Œ�
		p�R�c���[�R�c�ԍ��y�z��p�z].�R�c�����ԍ� = 1;

		// �R�c���̖{���������Ƃ������́A�喼�̖{���֊i�グ
		p�喼���[iSelfDaimyoID].��������y��ԍ��z = iNewDaimyoCastleID + 1;
		p����[iNewDaimyoCastleID].�{�� = �{��::�喼;

		// ----------------------------------------------------
		// �����N���X�g�̕ύX�B�����̌R�c�����A����܂ł̑喼�z���̌R�c�̃����N���X�g����폜����

		// �������g(�R�c)�������N���X�g����O���B
		// �O�̌R�c�́u���̌R�c�v���A���g�ł͂Ȃ��A�u���g�̎��̌R�c�v�ɂ���B
		if (p�R�c���[�R�c�ԍ��y�z��p�z].�O�̌R�c�y�R�c�ԍ��z != 0 && p�R�c���[�R�c�ԍ��y�z��p�z].�O�̌R�c�y�R�c�ԍ��z != 0xFFFF) {
			int _prev = p�R�c���[�R�c�ԍ��y�z��p�z].�O�̌R�c�y�R�c�ԍ��z - 1;
			p�R�c���[_prev].���̌R�c�y�R�c�ԍ��z = p�R�c���[�R�c�ԍ��y�z��p�z].���̌R�c�y�R�c�ԍ��z;
		}

		// ���̌R�c�́u�O�̌R�c�v���A���g�ł͂Ȃ��A�u���g�̑O�̌R�c�v�ɂ���B
		if (p�R�c���[�R�c�ԍ��y�z��p�z].���̌R�c�y�R�c�ԍ��z != 0 && p�R�c���[�R�c�ԍ��y�z��p�z].���̌R�c�y�R�c�ԍ��z != 0xFFFF) {
			int _next = p�R�c���[�R�c�ԍ��y�z��p�z].���̌R�c�y�R�c�ԍ��z - 1;
			p�R�c���[_next].�O�̌R�c�y�R�c�ԍ��z = p�R�c���[�R�c�ԍ��y�z��p�z].�O�̌R�c�y�R�c�ԍ��z;
		}


		// �V�݂Ȃ̂Ŏ������擪�͊m��
		p�R�c���[�R�c�ԍ��y�z��p�z].�O�̌R�c�y�R�c�ԍ��z = 0;
		// �V�݂Ȃ̂Ŏ������Ō�͊m��
		p�R�c���[�R�c�ԍ��y�z��p�z].���̌R�c�y�R�c�ԍ��z = 0xFFFF;

		// ----------------------------------------------------
		// �R�c�z�������̏�������(�������܂�)�̏����喼���A�V�ݑ喼�ւ̕ύX����
		// �m���N���̓��Z�b�g�����
		for (int iBushouID = 0; iBushouID < �ő吔::�������::�z��; iBushouID++) {
			if (p�������[iBushouID].�����R�c�y�R�c�ԍ��z == �R�c�ԍ��y�z��p�z + 1) {
				// �펀���ł͂Ȃ�
				if (!p�����ːЏ��[iBushouID].�펀) {
					p�������[iBushouID].�����喼�y�喼�ԍ��z = iSelfDaimyoID + 1;
					p�������[iBushouID].�d���N�� = 0;
				}
			}
		}

		// ----------------------------------------------------
		// �����n
		for (int iTargetDaimyoID = 0; iTargetDaimyoID < �ő吔::�喼���::�z��; iTargetDaimyoID++) {
			// �F�D�͂܂�Ȃ�
			Set_�F�D�֌W(iSelfDaimyoID, iTargetDaimyoID, 50);
			// �����⍥���̓��Z�b�g
			Set_�����֌W(iSelfDaimyoID, iTargetDaimyoID, FALSE);
			Set_�����֌W(iSelfDaimyoID, iTargetDaimyoID, FALSE);
		}
		return iSelfDaimyoID;
	}

	// �Ώۂ̑喼���v���C���[�S���̑喼�ł��邩�ǂ����𔻒f����B
	// �喼�ԍ��y�z��p�z�ɂ͔z���̔ԍ�(attach-1�̐�)��n������
	bool Is_�v���C���S���喼(WORD �喼�ԍ��y�z��p�z) {

		// �喼ID�͈̔͂Ɏ��܂��Ă��邱��
		if (0 <= �喼�ԍ��y�z��p�z&& �喼�ԍ��y�z��p�z < �ő吔::�喼���::�z��) {
			// �^�[�Q�b�g�̕����̌R�cID���v���C���[�̌R�c�ł��邩��Ԃ�
			return Is_�v���C���S���R�c(p�喼���[�喼�ԍ��y�z��p�z].�����R�c�y�R�c�ԍ��z - 1);
		}
		else {
			return false;
		}
	}



	// �Ώۂ̌R�c���v���C���[�S���R�c�̐��͉��̌R�c�ł��邩�ǂ����𔻒f����B
	// iTargetGundanID�ɂ͔z���̔ԍ�(attach-1�̐�)��n������
	bool Is_�v���C���S���R�c(WORD �R�c�ԍ��y�z��p�z) {

		if (!(0 <= �R�c�ԍ��y�z��p�z && �R�c�ԍ��y�z��p�z < �ő吔::�R�c���::�z��)) {
			return false;
		}

		WORD ix�y�R�c�ԍ��z = 0;
		for (int n�Ԗ� = 0; n�Ԗ�< �ő吔::�v���C���S���R�c���::�z��; n�Ԗ�++) {
			// �v���C���[���S�����Ă���R�c�̂h�c���m��
			ix�y�R�c�ԍ��z = p�v���C���S���R�c���[n�Ԗ�].�S���R�c�y�R�c�ԍ��z;

			// 0xFFFF�Ȃ�΃v���C���[�ł͂Ȃ�
			if (ix�y�R�c�ԍ��z == 0xFFFF) {
				continue;
			}

			// �v���C���[�S���̌R�c�̑喼���A�^�[�Q�b�g�Ƃ��Ă���Ώۂ̌R�c�̑喼�ƈ�v����Ȃ�΁A
			// ����̓v���C���[�̐��͉��̌R�c�ł���B
			// �ǂ���nb6player8��gundan�̒l�́A�����Ǘ���gundan�̒l����+1����Ă���悤�ł���B
			// ����Ă����ł�-1����B
			if (ix�y�R�c�ԍ��z >= 1 && p�R�c���[ix�y�R�c�ԍ��z - 1].�����喼�y�喼�ԍ��z == p�R�c���[�R�c�ԍ��y�z��p�z].�����喼�y�喼�ԍ��z) {
				return true;
			}
		}

		return false;
	}


	// �Ώۂ̕����������ꂩ�̃v���C���[���͉��̕����ł���
	bool Is_�v���C���S������(WORD �����ԍ��y�z��p�z) {

		// ����ID�͈̔͂Ɏ��܂��Ă��邱��
		if (0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z��) {

			// �^�[�Q�b�g�̕����̌R�cID���v���C���[�̌R�c�ł��邩��Ԃ�
			return Is_�v���C���S���R�c(p�������[�����ԍ��y�z��p�z].�����R�c�y�R�c�ԍ��z - 1);

		}
		else {
			return false;
		}
	}


}


