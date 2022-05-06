#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include "�Q�[���f�[�^�\��.h"


extern HMODULE hModuleTSMod;


using PFNSETBUSHOUEXAPTITUDE = int (WINAPI *)(int �����ԍ��y�z��p�z, int �K�����, int �K���l);
PFNSETBUSHOUEXAPTITUDE p_SetBushouExAptitude = NULL;

using PFNGETKAIKENIKOUAI	 = int (WINAPI *)(int �����ԍ��y�z��p�z);
PFNGETKAIKENIKOUAI p_GetKaikenIkouAI = NULL;

using PFNSETKAIKENIKOUAI	 = void (WINAPI *)(int �����ԍ��y�z��p�z, int ��ӌ�);
PFNSETKAIKENIKOUAI p_SetKaikenIkouAI = NULL;

using PFNGETCUSTOMSOLDIERMAX = int (WINAPI *)(int �����ԍ��y�z��p�z);
PFNGETCUSTOMSOLDIERMAX p_GetCustomSoldierMax = NULL;

using PFNGENERALABUSHOUBORNEXECUTE = int (WINAPI *)(int ������ԍ�);
PFNGENERALABUSHOUBORNEXECUTE p_GeneralABushouBornExecute = NULL;


// TSMod�ɂ����Ȃ�����Đ��֐��̃|�C���^�̓o�^
void _�����֐��o�^() {
	// �V�i���I�f�[�^�̈����o���p���\�b�h�̃|�C���^�m��
	p_SetBushouExAptitude = (PFNSETBUSHOUEXAPTITUDE)GetProcAddress( hModuleTSMod, "Extern_setBushouExAptitude" );

	// ��ӌ��擾
	p_GetKaikenIkouAI = (PFNGETKAIKENIKOUAI)GetProcAddress( hModuleTSMod, "Extern_getKaikenIkouAI" );

	// ��ӌ��擾
	p_SetKaikenIkouAI = (PFNSETKAIKENIKOUAI)GetProcAddress( hModuleTSMod, "Extern_setKaikenIkouAI" );

	// �Ώە����̍ő啺��(�J�X�^��SoldierMAX)
	p_GetCustomSoldierMax = (PFNGETCUSTOMSOLDIERMAX)GetProcAddress( hModuleTSMod, "Extern_getCustomSoldierMax" );

	// �����a��
	p_GeneralABushouBornExecute = (PFNGENERALABUSHOUBORNEXECUTE)GetProcAddress( hModuleTSMod, "Extern_GeneralABushouBornExecute" );
}




//------------------�K�v�M���n�z��
#define GAMEDATASTRUCT_REQUIREDMERITS_ADDRESS   0x4D1950    // [�K�v�M���l�̃A�h���X]
/*
    �K�v�M���l
 */
struct NB6REQUIREDMERITS
{
	DWORD merits;
};
NB6REQUIREDMERITS   *const nb6requiredmerits = (NB6REQUIREDMERITS *)GAMEDATASTRUCT_REQUIREDMERITS_ADDRESS;




namespace �֐� {
	// �ƕ�Ȃǂ��܂߂Ȃ��f�̐����˔\
	int Get_���ő吭��(int iBushouID) {
		if (0 <= iBushouID && iBushouID < �ő吔::�������::�z��) {
			int upparam = 0; // �㏸�l
			for (int iKahouID = 0; iKahouID < �ő吔::�ƕ���::�z��; iKahouID++) {
				// ���������^�C�v�F0 ���q  1 ����  2 ����  3 ����  4 �ԓ�  
				if (�ƕ󕪗�::���q <= p�ƕ���[iKahouID].�ƕ󕪗� && p�ƕ���[iKahouID].�ƕ󕪗� <= �ƕ󕪗�::�ԓ�) {
					// ������Ǝw�蕐������v����
					if (p�ƕ���[iKahouID].���L�����y�����ԍ��z == iBushouID + 1) {
						// ���܂łōő�̏㏸�l
						if (p�ƕ���[iKahouID].�㏸�l > upparam) {
							upparam = p�ƕ���[iKahouID].�㏸�l;
						}
					}
				}
			}

			int maxgov = p�������[iBushouID].�ő吭��;
			return (maxgov - upparam) > 0 ? (maxgov - upparam) : 1;
		}
		else {
			return 0;
		}
	}

	// �ƕ�Ȃǂ��܂߂Ȃ��f�̐퓬�˔\
	int Get_���ő���(int iBushouID) {
		if (0 <= iBushouID && iBushouID < �ő吔::�������::�z��) {
			int upparam = 0; // �㏸�l
			for (int iKahouID = 0; iKahouID < �ő吔::�ƕ���::�z��; iKahouID++) {
				// �퓬�����^�C�v�F5 ����  6 ��  7 �  8 �n  9 ��  A �w�H�D   
				if (�ƕ󕪗�::���� <= p�ƕ���[iKahouID].�ƕ󕪗� && p�ƕ���[iKahouID].�ƕ󕪗� <= �ƕ󕪗�::�w�H�D) {
					// ������Ǝw�蕐������v����
					if (p�ƕ���[iKahouID].���L�����y�����ԍ��z == iBushouID + 1) {
						// ���܂łōő�̏㏸�n
						if (p�ƕ���[iKahouID].�㏸�l > upparam) {
							upparam = p�ƕ���[iKahouID].�㏸�l;
						}
					}
				}
			}

			int maxbat = p�������[iBushouID].�ő���;
			return (maxbat - upparam) > 0 ? (maxbat - upparam) : 1;
		}
		else {
			return 0;
		}
	}

	// �ƕ�Ȃǂ��܂߂Ȃ��f�̒q�d�˔\
	int Get_���ő�q��(int iBushouID) {
		if (0 <= iBushouID && iBushouID < �ő吔::�������::�z��) {
			int upparam = 0; // �㏸�l
			for (int iKahouID = 0; iKahouID < �ő吔::�ƕ���::�z��; iKahouID++) {
				// �q�d�����^�C�v�FB ���q�{  C �����Ԗ{
				if (�ƕ󕪗�::���q�{ <= p�ƕ���[iKahouID].�ƕ󕪗� && p�ƕ���[iKahouID].�ƕ󕪗� <= �ƕ󕪗�::�����Ԗ{) {
					// ������Ǝw�蕐������v����
					if (p�ƕ���[iKahouID].���L�����y�����ԍ��z == iBushouID + 1) {
						// ���܂łōő�̏㏸�n
						if (p�ƕ���[iKahouID].�㏸�l > upparam) {
							upparam = p�ƕ���[iKahouID].�㏸�l;
						}
					}
				}
			}

			int maxint = p�������[iBushouID].�ő�q��;
			return (maxint - upparam) > 0 ? (maxint - upparam) : 1;
		}
		else {
			return 0;
		}
	}

	// �ƕ�Ȃǂ��܂߂Ȃ��f�̖�]
	int Get_����](int iBushouID) {
		if (0 <= iBushouID && iBushouID < �ő吔::�������::�z��) {
			int upparam = 0; // �㏸�l
			for (int iKahouID = 0; iKahouID < �ő吔::�ƕ���::�z��; iKahouID++) {
				// ��]�����^�C�v�FD ����  E �n���V  F ��؎��v  10 ���n��  11 �\����  12 ����  13 �ʎ蔠  14 �r�[�h���t  15 ���ዾ  16 ���\����  17 ����
				if (�ƕ󕪗�::���� <= p�ƕ���[iKahouID].�ƕ󕪗� && p�ƕ���[iKahouID].�ƕ󕪗� <= �ƕ󕪗�::����) {
					// ������Ǝw�蕐������v����
					if (p�ƕ���[iKahouID].���L�����y�����ԍ��z == iBushouID + 1) {
						// ���܂łōő�̏㏸�n
						if (p�ƕ���[iKahouID].�㏸�l > upparam) {
							upparam = p�ƕ���[iKahouID].�㏸�l;
						}
					}
				}
			}

			int ambition = p�������[iBushouID].��];
			return (ambition - upparam) > 0 ? (ambition - upparam) : 1;
		}
		else {
			return 0;
		}
	}

	// ���ʂȂǂ��܂߂Ȃ��f�̖���
	int Get_������(int iBushouID) {
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

			int charm = p�������[iBushouID].����;
			return (charm - upparam) > 0 ? (charm - upparam) : 1;
		}
		else {
			return 0;
		}
	}



}



namespace �֐� {


// �S�C�̓K���𐔒l�Ŏ擾����B(0=E,1=D,2=C,3=B,4=A,5=S  �S�C�K��::�r �` �S�C�K��::�d �Ɣ�r����Ɨǂ�)
int Get_�S�C�K��( int �����ԍ��y�z��p�z ) {

	// �͈̓`�F�b�N
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) { 

		// �S�C�͂Q�̃t�B�b�g�t�B�[���h�ɕ�����Ă��܂��Ă���̂ŁA�v�Z
		int �S�C�K���l = p�������[�����ԍ��y�z��p�z]._�S�C�K��_lo << 2;
		�S�C�K���l += p�������[�����ԍ��y�z��p�z]._�S�C�K��_hi;
		return �S�C�K���l;
	} else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
		return -1;
	}
}

// �S�C�̓K���𐔒l�Őݒ肷��B(0=E,1=D,2=C,3=B,4=A,5=S  �S�C�K��::�r �` �S�C�K��::�d �Őݒ肷��Ɨǂ�)
void Set_�S�C�K��( int �����ԍ��y�z��p�z, int �S�C�K���l ) {

	// �͈̓`�F�b�N
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) { 

		// �͈̓`�F�b�N
		if ( �S�C�K��::�d <= �S�C�K���l && �S�C�K���l <= �S�C�K��::�r) {
			// �S�C�͂Q�̃t�B�b�g�t�B�[���h�ɕ�����Ă��܂��Ă���̂ŁA�v�Z
			p�������[�����ԍ��y�z��p�z]._�S�C�K��_hi = �S�C�K���l & 0x0003;  // 0b000000HH
			p�������[�����ԍ��y�z��p�z]._�S�C�K��_lo = �S�C�K���l >> 2;	   // 0b00000L00
		} else {
			�f�o�b�O�o��("�S�C�K���l�͔͈͊O");
		}
	} else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
	}
}


// �|�̓K���𐔒l�Ŏ擾����B(0=E,1=D,2=C,3=B,4=A,5=S  �|�K��::�r �` �|�K��::�d �Ɣ�r����Ɨǂ�)
int Get_�|�K��( int �����ԍ��y�z��p�z ) {

	// �͈̓`�F�b�N
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) {
		if ( p_SetBushouExAptitude ) {
			int �|�K���l = p_SetBushouExAptitude( �����ԍ��y�z��p�z, 5, -1 ); // 5�͋|(TSMod��), -1��������l�͐ݒ肹���Ɏ擾�̂݁B
			return �|�K���l;
		}
		return -1;
	} else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
		return -1;
	}
}

// �|�̓K���𐔒l�Őݒ肷��B(0=E,1=D,2=C,3=B,4=A,5=S  �|�K��::�r �` �|�K��::�d �Őݒ肷��Ɨǂ�)
void Set_�|�K��( int �����ԍ��y�z��p�z, int �|�K���l ) {

	// �͈̓`�F�b�N
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) {

		// �͈̓`�F�b�N
		if ( �|�K��::�d <= �|�K���l && �|�K���l <= �|�K��::�r ) { 

			if ( p_SetBushouExAptitude ) {
				p_SetBushouExAptitude( �����ԍ��y�z��p�z, 5, �|�K���l); // 5�͋|(TSMod��)
			}
		} else {
			�f�o�b�O�o��("�|�K���l�͔͈͊O");
		}
	} else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
	}
}


// ���̓K���𐔒l�Ŏ擾����B(0=E,1=D,2=C,3=B,4=A,5=S  ���K��::�r �` ���K��::�d �Ɣ�r����Ɨǂ�)
int Get_���K��( int �����ԍ��y�z��p�z ) {

	// �͈̓`�F�b�N
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) {

		if ( p_SetBushouExAptitude ) {
			int ���K���l = p_SetBushouExAptitude( �����ԍ��y�z��p�z, 6, -1 ); // 6�͑�(TSMod��), -1��������l�͐ݒ肹���Ɏ擾�̂݁B
			return ���K���l;
		} else {
			return -1;
		}
	} else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
		return -1;
	}
}

// ���̓K���𐔒l�Őݒ肷��B(0=E,1=D,2=C,3=B,4=A,5=S  ���K��::�r �` ���K��::�d �Őݒ肷��Ɨǂ�)
void Set_���K��( int �����ԍ��y�z��p�z, int ���K���l ) {

	// �͈̓`�F�b�N
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) {

		// �͈̓`�F�b�N
		if ( ���K��::�d <= ���K���l && ���K���l <= ���K��::�r ) {

			if ( p_SetBushouExAptitude ) {
				p_SetBushouExAptitude( �����ԍ��y�z��p�z, 6, ���K���l); // 6�͑�(TSMod��)
			}
		} else {
			�f�o�b�O�o��("���K���l�͔͈͊O");
		}
	} else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
	}
}



// �S�C�̓K���𐔒l�Ŏ擾����B
int Get_�Ɨ�( int �����ԍ��y�z��p�z ) {

	// �͈̓`�F�b�N
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) { 

		// �Ɨ��͂Q�̃t�B�b�g�t�B�[���h�ɕ�����Ă��܂��Ă���̂ŁA�v�Z
		int �Ɨ��l = p�������[�����ԍ��y�z��p�z]._�Ɨ�_lo << 2;
		�Ɨ��l += p�������[�����ԍ��y�z��p�z]._�Ɨ�_hi;
		return �Ɨ��l;
	} else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
		return -1;
	}
}

// �S�C�̓K���𐔒l�Őݒ肷��
void Set_�Ɨ�( int �����ԍ��y�z��p�z, int �Ɨ��l ) {

	// �͈̓`�F�b�N
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) { 

		// �Ɨ��͂Q�̃t�B�b�g�t�B�[���h�ɕ�����Ă��܂��Ă���̂ŁA�v�Z
		p�������[�����ԍ��y�z��p�z]._�Ɨ�_hi = �Ɨ��l & 0x0003;  // 0b000000HH
		p�������[�����ԍ��y�z��p�z]._�Ɨ�_lo = �Ɨ��l >> 2;	   // 0b00000L00
	} else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
	}
}


// �����̐����l���擾����
int Get_�����l( int �����ԍ��y�z��p�z) {

	// �͈̓`�F�b�N
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) { 

		return int(p�������[�����ԍ��y�z��p�z].�ő吭�� * (float(p�������[�����ԍ��y�z��p�z].�����n���l) / float(2000)));
	} else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
		return -1;
	}
}

// �����̐퓬�l���擾����
int Get_�퓬�l( int �����ԍ��y�z��p�z) {

	// �͈̓`�F�b�N
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) { 

		return int(p�������[�����ԍ��y�z��p�z].�ő��� * (float(p�������[�����ԍ��y�z��p�z].�퓬�n���l) / float(2000)));
	} else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
		return -1;
	}
}

// �����̒q�d�l���擾����
int Get_�q�d�l( int �����ԍ��y�z��p�z) {

	// �͈̓`�F�b�N
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) { 

		return int(p�������[�����ԍ��y�z��p�z].�ő�q�� * (float(p�������[�����ԍ��y�z��p�z].�q�d�n���l) / float(2000)));
	} else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
		return -1;
	}
}

// �����̍ő啺�����擾����
int Get_�����ő啺��(int �����ԍ��y�z��p�z) {

	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) { 
		if ( p_GetCustomSoldierMax ) {
			int �ő啺�� = p_GetCustomSoldierMax( �����ԍ��y�z��p�z);
			if ( �ő啺�� < 0 ) {
				return 0;
			} else {
				return �ő啺��;
			}
		} else {
			return 0;
		}
	} else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
		return 0;
	}
}



// �����̖������擾����
string Get_����( int �����ԍ��y�z��p�z) {

	// �͈̓`�F�b�N
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) { 

		return string( p�����ːЏ��[�����ԍ��y�z��p�z]._���� );
	} else {
		return string("");
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
	}
}

// �����̖�����ݒ肷��
void   Set_����( int �����ԍ��y�z��p�z, string ���� ) {

	// �͈̓`�F�b�N
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) { 

		strncpy( p�����ːЏ��[�����ԍ��y�z��p�z]._����, ����.c_str(), 6 );
		p�����ːЏ��[�����ԍ��y�z��p�z]._����[6] = NULL;
	} else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
	}
}

// �����̖��O���擾����
string Get_���O( int �����ԍ��y�z��p�z) {

	// �͈̓`�F�b�N
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) { 

		return string( p�����ːЏ��[�����ԍ��y�z��p�z]._���O );
	} else {
		return string("");
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
	}
}


// �����̖��O��ݒ肷��
void   Set_���O( int �����ԍ��y�z��p�z, string ���O ) {

	// �͈̓`�F�b�N
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) { 

		strncpy_s( p�����ːЏ��[�����ԍ��y�z��p�z]._���O, ���O.c_str(), 6 );
		p�����ːЏ��[�����ԍ��y�z��p�z]._���O[6] = NULL;
	} else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
	}
}


}

// �Q�[���Ō��X�p�ӂ���Ă��郉���_���ȕP���𓾂�B
// 
#define GAMEDATASTRUCT_HIMENAME_ARRAY			0x4CA9B0	// �P�������񂳂�Ă���ꏊ�B1�l7�o�C�g�B(�S�p3�����{NULL)��100�l���B
struct _HIME_NAME {
	char name[7];
};

namespace �֐� {

string Get_�����_���P���O() {
	// �P�|�C���^�̈ʒu
	_HIME_NAME *pHName = (_HIME_NAME *)GAMEDATASTRUCT_HIMENAME_ARRAY;
	int iRnd = rand() % 100; // 100�l�p�ӂ���Ă���B
	return pHName[iRnd].name;
}


/* 
 * �����̊�ԍ����畐���ԍ����擾����B���݂��Ȃ��ꍇ�́A�0xFFFF����Ԃ��Ă���B
 */
WORD Get_�����ԍ��y�z��p�z(int ��ԍ�) {

	// ��ԍ��͈̔̓`�F�b�N�͂����Ă��Ȃ��BKaoSwapEx�Ȃǂ����邽�߁B
	for (int �����ԍ��y�z��p�z=0; �����ԍ��y�z��p�z < �ő吔::�������::�z��; �����ԍ��y�z��p�z++ ) {
		if ( p�����ːЏ��[�����ԍ��y�z��p�z].��ԍ� == ��ԍ� ) {
			return �����ԍ��y�z��p�z;
		}
	}

	return 0xFFFF;
}

/* 
 * �����̐������畐���ԍ����擾����B���݂��Ȃ��ꍇ�́A�0xFFFF����Ԃ��Ă���B
 */
WORD Get_�����ԍ��y�z��p�z(string ��������) {

	// ��ԍ��͈̔̓`�F�b�N�͂����Ă��Ȃ��BKaoSwapEx�Ȃǂ����邽�߁B

	for (int �����ԍ��y�z��p�z=0; �����ԍ��y�z��p�z < �ő吔::�������::�z��; �����ԍ��y�z��p�z++ ) {
		if ( �������� == Get_����(�����ԍ��y�z��p�z)+Get_���O(�����ԍ��y�z��p�z)) {
			return �����ԍ��y�z��p�z;
		}
	}

	return 0xFFFF;
}

/*
 * �����̔N��𓾂�B
 */
int Get_�����N��(int �����ԍ��y�z��p�z) {
	// �͈̓`�F�b�N
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) {
		return p�N���.�N - p�������[�����ԍ��y�z��p�z].���N + 1;
	}
	�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
	return 0xFF;
}

/*
 * �����̔N���ݒ肷��B
 */
bool Set_�����N��(int �����ԍ��y�z��p�z, int �N��) {

	// �͈̓`�F�b�N
	if (0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z��) {

		int check = p�N���.�N + 1 - �N��;
		if (check < 0) {
			�f�o�b�O�o��("�N��͔͈͊O�B�a���N�����ʂƂ��āA�V�ċL��N(1454)��葁�����܂�ƂȂ��Ă��܂��Ă���B");
			check = 0;
		}
		if (check > 255) {
			�f�o�b�O�o��("�N��͔͈͊O�B�a���N�����ʂƂ��āA�V�ċL�ŏI�N(1708)���x�����܂�ƂȂ��Ă��܂��Ă���B");
			check = 255;
		}
		p�������[�����ԍ��y�z��p�z].���N = check;
		return TRUE;
	}
	else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
		return FALSE;
	}
}



// �w�蕐���̔�����iBushouID�𓾂�B���������Ȃ��ꍇ�ɂ́A0xFFFF���Ԃ��Ă���B
int Get_���������ԍ��y�z��p�z(int �����ԍ��y�z��p�z) {

	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) {

		int iBushouID = �����ԍ��y�z��p�z;

		// �w��̕����̔������
		int iBushouIDSpouse = p�������[iBushouID]._��; //

		// �������Ă��Ȃ�
		if ( iBushouIDSpouse == 0xFF ) {
			return 0xFFFF;
		}

		int iTsumaBushouID = iBushouIDSpouse+500;

		// �����̔ԍ����������g��������A�����͍ȑ��̗���
		if ( iTsumaBushouID == iBushouID ) {
			for ( int i=0; i<�ő吔::�������::�z��; i++ ) {
				// �������g�ȊO�ŁA���������ԍ��������Ă�̂��A�����̕���
				if ( i != iBushouID &&  p�������[i]._�� == iBushouIDSpouse ) {
					return i;
				}
			}
			return 0xFFFF;

		// �����͕v���B�Ȃɂ������ԍ����ݒ肳��Ă��邩�m�F�B
		} else {
			if ( p�������[iTsumaBushouID]._�� == iBushouIDSpouse ) {
				return iTsumaBushouID;
			// �Ȃ����ݒ肳��Ă��Ȃ��c�B�������Ńf�[�^���Ă���B
			} else {
				return 0xFFFF;
			}
		}
	
	} else {
		�f�o�b�O�o��("�����ԍ��y�z��p�z�͔͈͊O");
		return 0xFFFF;
	}
}

// �P(���̕����̍Ȋ܂�)���A�w��̕����ƌ���������A�����֌W���͈�ؑ��삳��Ȃ��B
bool Set_�P����( int �P�����ԍ��y�z��p�z, int �v�����ԍ��y�z��p�z, BOOL �V�W�ǓƎ��S���� ) {
	int iOttoID = �v�����ԍ��y�z��p�z;
	int iHimeID = �P�����ԍ��y�z��p�z;

	// ����l���B�A�E�g�B
	if ( iHimeID == iOttoID ) { return false; }

	// �v�ƕP���K��͈̔͂ɓ����Ă��Ȃ���΃A�E�g
	if (   0 <= iOttoID && iOttoID < �ő吔::�������::�z�� &&
		 500 <= iHimeID && iHimeID < �ő吔::�������::�z��) {

		// �����P���̂h�c�̕������A�P�łȂ��Ȃ�΁A�A�E�g
		if ( p�����ːЏ��[iHimeID].��� != ���::�P ) {
			return false;
		}

		// �g���Y��ɂȂ����̂ŁA���߂Č���
		int _�V�Ȓl = iHimeID-500; // �Ȃɓ���ׂ��l�́A�P�����ԍ��y�z��p�z-500

		// ���łɗ��҂͕v�w�ł���A��������K�v�������B
		if ( p�������[iOttoID]._�� == _�V�Ȓl &&  p�������[iHimeID]._�� == _�V�Ȓl ) {
			return true;
		}

		// �v�������łɌ������Ă��邩�A�������Ă����痣��
		int _�v���Ȓl = p�������[iOttoID]._��; //
		Set_�P����( _�v���Ȓl+500, �V�W�ǓƎ��S���� );

		p�����ːЏ��[iHimeID].��� = ���::�P; // �V�W�ǓƏ����Ŏ��S������������Ȃ��̂ŕP�ɖ߂��B

		int _�ȑ��Ȓl = p�������[iHimeID]._��; //
		Set_�P����( _�ȑ��Ȓl+500, �V�W�ǓƎ��S���� );

		p�����ːЏ��[iHimeID].��� = ���::�P; // �V�W�ǓƏ����Ŏ��S������������Ȃ��̂ŕP�ɖ߂��B

		// �g���Y��ɂȂ����̂ŉ��߂Č���
		p�������[iOttoID]._�� = _�V�Ȓl;
		p�������[iHimeID]._�� = _�V�Ȓl;

		// ���喼�Ƃ��o���Ă�����
		int ��DaimyoID = p�������[iHimeID].�����喼�y�喼�ԍ��z;

		// �v���̑喼�̕��ɐg���񂹂�
		p�������[iHimeID].�����喼�y�喼�ԍ��z = p�������[iOttoID].�����喼�y�喼�ԍ��z;
		Set_����(iHimeID, Get_����(iOttoID) );

		// ���ʁA�喼�Ƃ��ω������̂ł���΁A�m���N�������Z�b�g
		if ( ��DaimyoID != p�������[iHimeID].�����喼�y�喼�ԍ��z) {
			p�������[iHimeID].�d���N�� = 0;
		}

		return true;
	}

	return false;
}


// �w��̕P�𗣍�������B
bool Set_�P����( int �P�����ԍ��y�z��p�z, BOOL �V�W�ǓƎ��S���� ) {
	int iHimeID = �P�����ԍ��y�z��p�z;

	// �v�ƕP���K��͈̔͂ɓ����Ă��Ȃ���΃A�E�g
	if ( 500 <= iHimeID && iHimeID < �ő吔::�������::�z�� ) {


		// �����P���̂h�c�̕������A�P�łȂ��Ȃ�΁A�A�E�g
		if ( p�����ːЏ��[iHimeID].��� != ���::�P ) {
			return false;
		}

		int _�Ȓl = p�������[iHimeID]._��; //

		// ���X�������Ă��Ȃ��B
		if ( _�Ȓl == 0xFF ) {
			return false;
		}

		// ���҂̌��������N���A
		for ( int iBushouID=0; iBushouID < �ő吔::�������::�z��; iBushouID++ ) {
			// �v�������͍Ȃł���
			if ( p�������[iBushouID]._�� == _�Ȓl ) {
				// ����
				p�������[iBushouID]._�� = 0xFF;
				// �v�ƍ�2�l�����Ƃ��l��0xFF�ɂ���K�v������̂ŁAbreak���Ȃ����ƁB
				// ���łɃf�[�^�ɃS�~�������Ă���ꍇ�ł��N���A
			}
		}


		// ���喼�Ƃ��o���Ă�����
		int ��DaimyoID = p�������[iHimeID].�����喼�y�喼�ԍ��z;

		// �ȉ��̐g������l�n�̏����́A�v���O�������ŏo���邾������Ă������Ƃ�����|�B
		// ���ɂ����œK�؂ȑ喼�ɋA���]�ڂł��Ȃ������Ƃ��Ă��A�V�ċL�̃v���O�����{�̂����G�ߎ��ɂ́A�K�؂ȑ喼�ɋA�������鏈�����s���B

		// ���������̂ŏ����喼��ύX����K�v��������B�܂��A�e���喼�����Ă��邩�ǂ����B
		for ( int iBushouID=0; iBushouID < �ő吔::�������::�z��; iBushouID++ ) {

			// �喼�̂����c
			if ( p�����ːЏ��[iBushouID].��� == ���::�喼 ) {

				// �����̐e���喼����Ă�B
				if ( p�������[iHimeID].�e��ԍ� < 5000 ) {
					if ( p�����ːЏ��[iBushouID].��ԍ� == p�������[iHimeID].�e��ԍ� ) {

						// �����ɐg���񂹂�
						p�������[iHimeID].�����喼�y�喼�ԍ��z = p�������[iBushouID].�����喼�y�喼�ԍ��z;
						Set_����(iHimeID, Get_����(iBushouID) );
						break;
					}
				}
			}
		}

		// �e���喼������Ă��Ȃ��Ƃ��A�e�������l(�����Z��o��)���喼������Ă��邩�ǂ����B
		for ( int iBushouID=0; iBushouID < �ő吔::�������::�z��; iBushouID++ ) {

			// �喼�̂����c
			if ( p�����ːЏ��[iBushouID].��� == ���::�喼 ) {

				// �e���������B
				if ( p�������[iHimeID].�e��ԍ� < 5000 ) {
					if ( p�������[iBushouID].�e��ԍ� == p�������[iHimeID].�e��ԍ� ) {

						// �����ɐg���񂹂�
						p�������[iHimeID].�����喼�y�喼�ԍ��z = p�������[iBushouID].�����喼�y�喼�ԍ��z;
						Set_����(iHimeID, Get_����(iBushouID) );
						break;
					}
				}
			}
		}

		// �e�Z�킪�喼����Ă��Ȃ��Ă��A��傪�喼������Ă���̂ł͂Ȃ����B
		for ( int iBushouID=0; iBushouID < �ő吔::�������::�z��; iBushouID++ ) {

			// �喼�̂����c
			if ( p�����ːЏ��[iBushouID].��� == ���::�喼 ) {

				// �e���������B
				if ( p�������[iHimeID].�������� != 0xFF ) {
					if ( p�������[iBushouID].�������� == p�������[iHimeID].�������� ) {

						// �����ɐg���񂹂�
						p�������[iHimeID].�����喼�y�喼�ԍ��z = p�������[iBushouID].�����喼�y�喼�ԍ��z;
						Set_����(iHimeID, Get_����(iBushouID) );
						break;
					}
				}
			}
		}

		bool is�V�W�Ǔ� = true;
		// �喼�łȂ��Ƃ��A�e���ǂ����ɂ���̂ł͂Ȃ����H
		for ( int iBushouID=0; iBushouID < �ő吔::�������::�z��; iBushouID++ ) {

			// �����̐e
			if ( p�������[iHimeID].�e��ԍ� < 5000 ) {
				if ( p�����ːЏ��[iBushouID].��ԍ� == p�������[iHimeID].�e��ԍ� ) {

					// �����ɐg���񂹂�
					p�������[iHimeID].�����喼�y�喼�ԍ��z = p�������[iBushouID].�����喼�y�喼�ԍ��z;
					Set_����(iHimeID, Get_����(iBushouID) );
					is�V�W�Ǔ� = false;
					break;
				}
			}
		}

		// �喼�łȂ��Ƃ��A�e�������l(�����Z��o��)���ǂ����ɂ���̂ł͂Ȃ����H
		for ( int iBushouID=0; iBushouID < �ő吔::�������::�z��; iBushouID++ ) {

			// �e���������B
			if ( p�������[iHimeID].�e��ԍ� < 5000 ) {
				if ( p�������[iBushouID].�e��ԍ� == p�������[iHimeID].�e��ԍ� ) {

					// �����ɐg���񂹂�
					p�������[iHimeID].�����喼�y�喼�ԍ��z = p�������[iBushouID].�����喼�y�喼�ԍ��z;
					Set_����(iHimeID, Get_����(iBushouID) );
					is�V�W�Ǔ� = false;
					break;
				}
			}
		}


		// ���ʁA�喼�Ƃ��ω������̂ł���΁A�m���N�������Z�b�g
		if ( ��DaimyoID != p�������[iHimeID].�����喼�y�喼�ԍ��z) {
			p�������[iHimeID].�d���N�� = 0;
		}

		if ( �V�W�ǓƎ��S���� ) {
			if ( is�V�W�Ǔ� ) {
				p�����ːЏ��[iHimeID].��� = ���::���S;
			}
		}

		return true;
	}

	return false;
}



bool Set_������ԁs�������Q�l�t(int �����ԍ��y�z��p�z) {

	int iBushouID = �����ԍ��y�z��p�z;

	if ( 0 <= iBushouID && iBushouID < �ő吔::�������::�z�� ) {

		if ( p�����ːЏ��[iBushouID].��� == ���::���� ) { // ���𕐏��̏ꍇ��������������B

			// �Y�������̋��邪�����Ƃ�����񂪊i�[����Ă���B(���[�U�[�������ɂ���ĉ��Ă��Ȃ�)
			int iCastleID = p�������[iBushouID].��������y��ԍ��z-1;
			if (0 <= iCastleID && iCastleID <  �ő吔::����::�z�� ) {

				if ( p����[iCastleID].���y�����ԍ��z == 0xFFFF ) { return false; } // �����N���X�g�����Ă���̂���ɒN���������Ă��Ȃ��B�������Ȃ��Breturn;

				// ��������̒l�ύX
				{
					p�����ːЏ��[iBushouID].��� = ���::�Q�l; // ��Ԃ�Q�l�Ƃ���B

					p�����ːЏ��[iBushouID].�g�� = �g��::���y��; // �g���𑫌y�Ƃ���B

					p�������[iBushouID].�����喼�y�喼�ԍ��z = 0xFFFF; // �喼�ɏ������Ȃ��B
					p�������[iBushouID].�����R�c�y�R�c�ԍ��z = 0xFFFF; // �R�c�ɏ������Ȃ��B
					p�������[iBushouID].���� = 50; // ������50�Ƃ���B
					p�������[iBushouID].�d���N�� = 0; // �m���N����0�Ƃ���B

					p�������[iBushouID].������喼�y�喼�ԍ��z = 0xFFFF; // ��������Ȃ��Ƃ���B
					p�������[iBushouID].������� = 0; // �����Ȃ��B

					p�������[iBushouID].���� = 0; // ������0�Ƃ���B
					p�������[iBushouID].�P�� = 0; // �P����0�Ƃ���B
					p�������[iBushouID].�m�C = 0; // ������0�Ƃ���B
					p�������[iBushouID].���� = ����::���y; // ���y�Ƃ���B

					// �M�����Z�b�g���Ȃ����[�h���ƁA�M�����V���c��
					if ( Get_�s�r�l�n�c�h�m�h�ݒ�("all_bushou_non_meritorious_reset") > 0 ) {
						p�������[iBushouID].�M�� = (WORD)(p�������[iBushouID].�M�� * 0.7); 

					// �f�t�H���g���ƌM���͂O
					} else {
						p�������[iBushouID].�M�� = 0; // �M����0�Ƃ���B
					}
				}

				/*����̕������X�H

				�@ �@����
				   ��
				   ��-��-��-��

				   �Ƃ����̂�

				   ��-��-��

				   �Ƃ���B
				   */

				int iPrevID = p�������[iBushouID].�O�̕����y�����ԍ��z;
				int iNextID = p�������[iBushouID].���̕����y�����ԍ��z;

				// �Q�l�ɂ����������́A���܏�傾
				if ( p����[iCastleID].���y�����ԍ��z-1 == iBushouID ) {
					p����[iCastleID].���y�����ԍ��z =  iNextID; // ������next�����ɂ���B
				}

				// ������prev�͗L���ȕ������B
				if ( 0 < iPrevID && iPrevID <= �ő吔::�������::�z�� ) {

					// ���������ł͂Ȃ������ŁA
					// �P�O�̐l�̎��̃����N�悪�������g�̏ꍇ
					if ( iPrevID != 0xFFFF && p�������[(iPrevID-1)].���̕����y�����ԍ��z == iBushouID+1 ) {
						// �����ł͂Ȃ��A���̐l�ւƌq��������B
						p�������[(iPrevID-1)].���̕����y�����ԍ��z = iNextID;
					}
				}

				// ������next�͗L���ȕ������B
				if ( 0 < iNextID && iNextID <= �ő吔::�������::�z�� ) {
					// �P��̐l�̑O�̃����N�悪�������g�̏ꍇ
					if ( iNextID != 0xFFFF && p�������[(iNextID-1)].�O�̕����y�����ԍ��z == iBushouID+1 ) {
						// �����ł͂Ȃ��A�O�̐l�ւƌq��������B
						p�������[(iNextID-1)].�O�̕����y�����ԍ��z = iPrevID;
					}
				}


				/* ����̘Q�l���X�g�@

				��-��

				�Ƃ����̂�

				��-��-��

				�Ƃ���B
				*/

				// �Q�l�Ƃ��Ă݂Ȃ������A������next�́A���ݘQ�l���X�g�̐擪�̐l
				int iRonin = p����[iCastleID]._�Q�l�擪�����y�����ԍ��z;
				p�������[iBushouID].���̕����y�����ԍ��z = iRonin; // ���݂̐擪�̐l�������̎��̐l��

				// next���L���ȕ����Ȃ�΁c
				if ( 0 < iRonin && iRonin <= �ő吔::�������::�z�� ) {
					// ���̐l��prev��������
					p�������[iRonin-1].�O�̕����y�����ԍ��z = iBushouID+1;
				}
				p�������[iBushouID].�O�̕����y�����ԍ��z = 0xFFFF; // prev�͋��Ȃ�

				p����[iCastleID]._�Q�l�擪�����y�����ԍ��z = iBushouID+1; // ��̘Q�l�̐擪�������ɂ���B

				return true;
			}
		}
	}

	return false;
}




bool Set_������ԁs�Q�l�������t(int �����ԍ��y�z��p�z) {

	int iBushouID = �����ԍ��y�z��p�z;

	if ( 0 <= iBushouID && iBushouID < �ő吔::�������::�z�� ) {
		if ( p�����ːЏ��[iBushouID].��� == ���::�Q�l ) { // �Q�l�����̏ꍇ��������������B

			// �Y�������̋��邪�����Ƃ�����񂪊i�[����Ă���B(���[�U�[�������ɂ���ĉ��Ă��Ȃ�)
			int iCastleID = p�������[iBushouID].��������y��ԍ��z-1;
			if (0 <= iCastleID && iCastleID <  �ő吔::����::�z�� ) {

				if ( p����[iCastleID]._�Q�l�擪�����y�����ԍ��z == 0xFFFF ) { return false; } // �����N���X�g�����Ă���̂��Q�l���N�����Ȃ����ƂɂȂ�������Ă�B�������Ȃ��Breturn;
				if ( p����[iCastleID].�����R�c�y�R�c�ԍ��z == 0xFFFF ) { return false; } // �Y���̏邪�ǂ��̌R�c�ɂ��������Ă��Ȃ��ꍇ�A�Q�l�������Ƃ͏o���Ȃ��B
																		       // �Ȃ��Ȃ�A����͑喼�����邱�Ƃ��Ӗ����邩��B

				// �ȍ~�A�R�c�A���A�喼�A�����ł��Ȃ��Ȃ�΁Afalse��Ԃ��B
				int iAttachGundanID = p����[iCastleID].�����R�c�y�R�c�ԍ��z-1;
				int iAttachDaimyoID = -1;
				if ( 0 <= iAttachGundanID && iAttachGundanID < �ő吔::�R�c���::�z�� ) {
					iAttachDaimyoID = p�R�c���[iAttachGundanID].�����喼�y�喼�ԍ��z - 1;
				} else {
					return false;
				}
				if ( ! (0 <= iAttachDaimyoID && iAttachDaimyoID < �ő吔::�喼���::�z�� ) ) {
					return false;
				}

				// ���݂̏�̏�傩��A�����N���X�g��H���Ă���
				int iLinkEndBusyouID = p����[iCastleID].���y�����ԍ��z;
				int iSafetyCnt = 0;
				while ( true ) {
					// �Z�[�t�e�B�J�E���g���\�����Ă���B(���[�U�[�ɂ���āA���łɃ����N���X�g������ɑ��삳��A�󂳂�Ă���)
					if ( iSafetyCnt > �ő吔::�������::�z�� ) { 
						return false;
					}

					// ��傪���Ȃ��Ȃ�΁A�I���
					if ( iLinkEndBusyouID == 0xFFFF ) {
						break;
					}

					// ���݂̕����́Anext���L���ł͂Ȃ���΁A���݂̕������Ō�̐l�B�I���B
					if ( p�������[iLinkEndBusyouID-1].���̕����y�����ԍ��z == 0xFFFF ) {
						break;

					// ���݂̐l���L���ł���B
					} else {
						// �����N���X�g�����̐l�Ƃ���B
						if ( 0 < iLinkEndBusyouID && iLinkEndBusyouID <= �ő吔::�������::�z�� ) {
							iLinkEndBusyouID = p�������[iLinkEndBusyouID-1].���̕����y�����ԍ��z;
						}
					}
				}

				// ��������̒l�ύX
				{
					p�����ːЏ��[iBushouID].��� = ���::����; // ��Ԃ������Ƃ���B
						
					p�������[iBushouID].�����喼�y�喼�ԍ��z = iAttachDaimyoID+1; // �喼�ɏ�������B
					p�������[iBushouID].�����R�c�y�R�c�ԍ��z = iAttachGundanID+1; // �R�c�ɏ�������B
					p�������[iBushouID].���� = 50; // ������50�Ƃ���B
					p�������[iBushouID].�d���N�� = 0; // �m���N����0�Ƃ���B

					p�������[iBushouID].������喼�y�喼�ԍ��z = 0xFFFF; // ��������Ȃ��Ƃ���B
					p�������[iBushouID].������� = 0; // �����Ȃ��B

					p�������[iBushouID].���� = 0; // ������0�Ƃ���B
					p�������[iBushouID].�P�� = 0; // �P����0�Ƃ���B
					p�������[iBushouID].�m�C = 0; // ������0�Ƃ���B
					p�������[iBushouID].���� = ����::���y; // ���y�Ƃ���B


					//------------------------------------------------------
					// �M�����Z�b�g���Ȃ����[�h���ƁA�c��M���ɍ��킹�ď��i
					if ( Get_�s�r�l�n�c�h�m�h�ݒ�("all_bushou_non_meritorious_reset") > 0 ) {

						if (p�������[iBushouID].�M�� >= nb6requiredmerits[0].merits ) { // �h�V���M�������B
							p�����ːЏ��[iBushouID].�g�� = �g��::�h�V;
						} else if ( p�������[iBushouID].�M�� >= nb6requiredmerits[1].merits ) { // �ƘV���M�������B
							p�����ːЏ��[iBushouID].�g�� = �g��::�ƘV;
						} else if ( p�������[iBushouID].�M�� >= nb6requiredmerits[2].merits ) { // �������M�������B
							p�����ːЏ��[iBushouID].�g�� = �g��::����;
						} else if ( p�������[iBushouID].�M�� >= nb6requiredmerits[3].merits ) { // ���叫���M�������B
							p�����ːЏ��[iBushouID].�g�� = �g��::���叫;
						}
					// �f�t�H���g���Ƒ��y
					} else {
						p�����ːЏ��[iBushouID].�g�� = �g��::���y��; // �g���𑫌y�Ƃ���B
					}


				}

				/* �@����
				      ��
				   ��-��-��-��

				   �Ƃ����̂�

				   ��-��-��

				   �Ƃ���B
				*/

				int iPrevID = p�������[iBushouID].�O�̕����y�����ԍ��z;
				int iNextID = p�������[iBushouID].���̕����y�����ԍ��z;

				// �����ɂ����������́A���ܘQ�l���X�g�̐擪��
				if ( p����[iCastleID]._�Q�l�擪�����y�����ԍ��z-1 == iBushouID ) {
					p����[iCastleID]._�Q�l�擪�����y�����ԍ��z =  iNextID; // ������next�����ɂ���B
				}

				// ������prev�͗L���ȕ������B
				if ( 0 < iPrevID && iPrevID <= �ő吔::�������::�z�� ) {

					// �������擪�ł͂Ȃ������ŁA
					// �P�O�̐l�̎��̃����N�悪�������g�̏ꍇ
					if ( iPrevID != 0xFFFF && p�������[(iPrevID-1)].���̕����y�����ԍ��z == iBushouID+1 ) {
						// �����ł͂Ȃ��A���̐l�ւƌq��������B
						p�������[(iPrevID-1)].���̕����y�����ԍ��z = iNextID;
					}
				}

				// ������next�͗L���ȕ������B
				if ( 0 < iNextID && iNextID <= �ő吔::�������::�z�� ) {
					// �P��̐l�̑O�̃����N�悪�������g�̏ꍇ
					if ( iNextID != 0xFFFF && p�������[(iNextID-1)].�O�̕����y�����ԍ��z == iBushouID+1 ) {
						// �����ł͂Ȃ��A�O�̐l�ւƌq��������B
						p�������[(iNextID-1)].�O�̕����y�����ԍ��z = iPrevID;
					}
				}


				/* �@
				     
				   ��-��

				   �Ƃ����̂�

				   ��-��-��

				   �Ƃ���B
				*/


				// �����͌����Ƃ��āA�������X�g�̈�ԍŌ�ɂ������B������next�͋��Ȃ�
				p�������[iBushouID].���̕����y�����ԍ��z = 0xFFFF; // 

				// ���������́A�����ɂȂ�ƂƂ��ɁA���ɂ��Ȃ�ׂ��Ȃ�΁c
				if ( iLinkEndBusyouID == 0xFFFF ) {
					p�������[iBushouID].�O�̕����y�����ԍ��z = 0xFFFF; // �����̑O�̐l�͋��Ȃ�

					p����[iCastleID].���y�����ԍ��z = iBushouID+1; // ���͎���

				// ���������N���X�g�̈�ԍŌ�ɂԂ牺����ׂ��B
				} else {

					p�������[iLinkEndBusyouID-1].���̕����y�����ԍ��z = iBushouID+1; // �����N���X�g�̍Ō��next��������

					p�������[iBushouID].�O�̕����y�����ԍ��z = iLinkEndBusyouID; // �����̑O�̐l�́A��̃����N���X�g�̍Ō�̐l��
				}
				return true;

			}
		}
	}

	return false;
}

} // namespace 



int pCallFromFuncDoDeathInMain = 0x40B962; // ���XTENSHOU.EXE���ɂ�����CALL��

int iBushouIDInFuncDoDeathInMain = 1L;    // ���S����ID

// ���C����ʂŎw��̕������E�Q
void FuncDoDeathInMainAsm() {
	__asm {
		mov esi, iBushouIDInFuncDoDeathInMain
		push iBushouIDInFuncDoDeathInMain
		call pCallFromFuncDoDeathInMain
		add esp, 0x4
	}
}


int pCallFromFuncDoDeathInBattle = 0x430A75; // ���XTENSHOU.EXE���ɂ�����CALL��BUnit�n���C��
int pCallFromFuncDoDeathInBattle2 = 0x40A352; // ���XTENSHOU.EXE���ɂ�����CALL��B���C���n�Ő��펀�t���O�𗧂Ă���

int iKilledBushouIDInFuncDoDeathInBattle = 1L;    // �E����镐��ID
int iCriminalBushouIDInFuncDoDeathInBattle = 1L;    // �Ɛl�̕���ID

// �퓬��ʂŎw��̕������E�Q
void FuncDoDeathInBattleAsm() {
	__asm {
		push 0x2
		push iCriminalBushouIDInFuncDoDeathInBattle
		push iKilledBushouIDInFuncDoDeathInBattle
		call pCallFromFuncDoDeathInBattle
		add esp, 0xC

		push 0x400
		push iKilledBushouIDInFuncDoDeathInBattle
		call pCallFromFuncDoDeathInBattle2
		add esp, 0x8
	}
}



namespace �֐� {

bool Set_������ԁs�����S�t(int ���S�����ԍ��y�z��p�z, int �Ɛl�����ԍ��y�z��p�z) {

	int iKilledBushouID = ���S�����ԍ��y�z��p�z;
	int iCriminalBushouID = �Ɛl�����ԍ��y�z��p�z;

	// �Ɛl���w�肵�Ȃ���΁A���E�Ƃ������Ƃɂ���B
	if ( iCriminalBushouID == -1 ) {
		iCriminalBushouID = iKilledBushouID;	
	}

	if ( 0 <= iKilledBushouID && iKilledBushouID < �ő吔::�������::�z�� && 0 <= iCriminalBushouID && iCriminalBushouID < �ő吔::�������::�z��  ) {
		if ( Is_��풆() || Is_�U��풆() ) {

			// ���łɐ펀���Ă����牽�����Ȃ�
			if ( p�����ːЏ��[iKilledBushouID].�펀 ) {
				return false;
			}

			// �֐��p�̂�́A1�����̂ŁA��������
			iKilledBushouIDInFuncDoDeathInBattle = iKilledBushouID+1;		// �E����鑤�̕���ID
			iCriminalBushouIDInFuncDoDeathInBattle = iCriminalBushouID+1;    // �Ɛl�̕���ID

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
			FuncDoDeathInBattleAsm();

			__asm {
				pop edi
				pop esi
				pop esp
				pop edx
				pop ecx
				pop ebx
				pop eax
			}

		} else {
			// �֐��p�̂�́A1�����̂ŁA��������
			iBushouIDInFuncDoDeathInMain = iKilledBushouID+1;

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
			FuncDoDeathInMainAsm();

			__asm {
				pop edi
				pop esi
				pop esp
				pop edx
				pop ecx
				pop ebx
				pop eax
			}

			return true;
		}
	}
	return false;
}

}



namespace �֐� {

bool Set_���(int �����ԍ��y�z��p�z) {

	int iBushouID = �����ԍ��y�z��p�z;

	if ( 0 <= iBushouID && iBushouID < �ő吔::�������::�z�� ) {

		if ( p�����ːЏ��[iBushouID].��� == ���::���� ) { // ���𕐏��̏ꍇ��������������B

			// �Y�������̋��邪�����Ƃ�����񂪊i�[����Ă���B(���[�U�[�������ɂ���ĉ��Ă��Ȃ�)
			int iCastleID = p�������[iBushouID].��������y��ԍ��z-1;

			if (0 <= iCastleID && iCastleID <  �ő吔::����::�z�� ) {

				if ( p����[iCastleID].���y�����ԍ��z == 0xFFFF ) { return false; } // �����N���X�g�����Ă���̂���ɒN���������Ă��Ȃ��B�������Ȃ��Breturn;

				// �����܂ŗ������傪����̂Łc
				int i���BusyouID = p����[iCastleID].���y�����ԍ��z-1;

				// �w�蕐�������łɏ��Ȃ牽�����Ȃ��Ă����ł���B
				if ( iBushouID== i���BusyouID ) { return true; }

				// ���͋��邪(��������)�������Ȕj����f�[�^�ɂȂ��Ă�����A�������Ȃ��B
				if ( ! (0 <= i���BusyouID && i���BusyouID < �ő吔::�������::�z�� ) ) {
					return false;
				}
				// ��傪�喼�ł��R�c���ł��Ȃ��Ȃ��(�喼)�A�������Ȃ��B����ւ���ƕςȂ��ƂɂȂ�B
				if ( p�����ːЏ��[i���BusyouID].��� == ���::���� ) {
					; // ���ɉ������Ȃ�
				} else if ( p�����ːЏ��[i���BusyouID].��� == ���::�R�c�� ) {
					// ���̌R�c���������Ƃ���
					p�����ːЏ��[i���BusyouID].��� = ���::����;
					// �t�Ɏw�蕐�����R�c��������
					p�����ːЏ��[iBushouID].��� = ���::�R�c��;
					int iGundanID = p�������[i���BusyouID].�����R�c�y�R�c�ԍ��z-1;
					// �����ėv��ʔ���̂͂��ł��邪�ꉞ
					if ( 0 <= iGundanID && iGundanID < �ő吔::�R�c���::�z�� ) {
						// �R�c���̌R�c���̔ԍ����A�w��̕����ɂ���B
						p�R�c���[iGundanID].�R�c���y�����ԍ��z = iBushouID + 1;
					}

				} else if ( p�����ːЏ��[i���BusyouID].��� == ���::�喼 ) {
					// ���̑喼�������Ƃ���
					p�����ːЏ��[i���BusyouID].��� = ���::����;
					// �喼�������l�̐g�����h�V�Ƃ���B
					p�����ːЏ��[i���BusyouID].�g�� = �g��::�h�V;
					// �t�Ɏw�蕐����喼�Ƃ���
					p�����ːЏ��[iBushouID].��� = ���::�喼;
					p�����ːЏ��[iBushouID].�g�� = �g��::�喼;
					int iGundanID = p�������[i���BusyouID].�����R�c�y�R�c�ԍ��z-1;
					int iDaimyoID = p�������[i���BusyouID].�����喼�y�喼�ԍ��z-1;
					// �����ėv��ʔ���̂͂��ł��邪�ꉞ
					if ( 0 <= iGundanID && iGundanID < �ő吔::�R�c���::�z�� ) {
						// �R�c���̌R�c���̔ԍ����A�w��̕����ɂ���B
						p�R�c���[iGundanID].�R�c���y�����ԍ��z = iBushouID + 1;
					}
					if ( 0 <= iDaimyoID && iDaimyoID < �ő吔::�喼���::�z�� ) {
						// �喼���̑喼�̔ԍ����A�w��̕����ɂ���B
						p�喼���[iDaimyoID].�喼�y�����ԍ��z = iBushouID + 1;
					}

				} else {
					return false;
				}




				/*����̕������X�g

				�@ �@����
				   ��
				   ��-��-��-��

				   �Ƃ����̂�

				   ��-��-��

				   �Ƃ���B
				   */

				int iPrevID = p�������[iBushouID].�O�̕����y�����ԍ��z;
				int iNextID = p�������[iBushouID].���̕����y�����ԍ��z;

				// �p�[�W�ɂ����������́A���܏�傾
				if ( p����[iCastleID].���y�����ԍ��z-1 == iBushouID ) {
					p����[iCastleID].���y�����ԍ��z =  iNextID; // ������next�����ɂ���B
				}

				// ������prev�͗L���ȕ������B
				if ( 0 < iPrevID && iPrevID <= �ő吔::�������::�z�� ) {

					// ���������ł͂Ȃ������ŁA
					// �P�O�̐l�̎��̃����N�悪�������g�̏ꍇ
					if ( iPrevID != 0xFFFF && p�������[(iPrevID-1)].���̕����y�����ԍ��z == iBushouID+1 ) {
						// �����ł͂Ȃ��A���̐l�ւƌq��������B
						p�������[(iPrevID-1)].���̕����y�����ԍ��z = iNextID;
					}
				}

				// ������next�͗L���ȕ������B
				if ( 0 < iNextID && iNextID <= �ő吔::�������::�z�� ) {
					// �P��̐l�̑O�̃����N�悪�������g�̏ꍇ
					if ( iNextID != 0xFFFF && p�������[(iNextID-1)].�O�̕����y�����ԍ��z == iBushouID+1 ) {
						// �����ł͂Ȃ��A�O�̐l�ւƌq��������B
						p�������[(iNextID-1)].�O�̕����y�����ԍ��z = iPrevID;
					}
				}


				/* ����̏�僊�X�g�@

				��-��

				�Ƃ����̂�

				��-��-��

				�Ƃ���B
				*/

				// �����Ƃ��Ă݂Ȃ������A������next�́A���݌������X�g�̐擪�̐l
				int iJosyu = p����[iCastleID].���y�����ԍ��z;
				p�������[iBushouID].���̕����y�����ԍ��z = iJosyu; // ���݂̐擪�̐l�������̎��̐l��

				// next���L���ȕ����Ȃ�΁c
				if ( 0 < iJosyu && iJosyu <= �ő吔::�������::�z�� ) {
					// ���̐l��prev��������
					p�������[iJosyu-1].�O�̕����y�����ԍ��z = iBushouID+1;
				}
				p�������[iBushouID].�O�̕����y�����ԍ��z = 0xFFFF; // prev�͋��Ȃ�

				p����[iCastleID].���y�����ԍ��z = iBushouID+1; // ��̏��������ɂ���B

				return true;
			}
		}
	}

	return false;
}

} // namespace �֐�

bool _Set_�����]���s�Q�l�t(int �����ԍ��y�z��p�z, int �]�����ԍ��y�z��p�z) {

	int iBushouID = �����ԍ��y�z��p�z;

	if ( 0 <= iBushouID && iBushouID < �ő吔::�������::�z�� ) {
		if ( p�����ːЏ��[iBushouID].��� == ���::�Q�l ) { // �Q�l�����̏ꍇ��������������B

			// �Y�������̋��邪�����Ƃ�����񂪊i�[����Ă���B(���[�U�[�������ɂ���ĉ��Ă��Ȃ�)
			int iCastleID = p�������[iBushouID].��������y��ԍ��z-1;
			int iNewCastleID = �]�����ԍ��y�z��p�z;

			if ( iCastleID == iNewCastleID ) { return true; } // �]���悪�����Ȃ牽������K�v�͂Ȃ��B

			if ((0 <= iCastleID && iCastleID <  �ő吔::����::�z��) && (0 <= iNewCastleID && iNewCastleID <  �ő吔::����::�z��)) {

				if ( p����[iCastleID]._�Q�l�擪�����y�����ԍ��z == 0xFFFF ) { return false; } // �����N���X�g�����Ă���̂��Q�l���N�����Ȃ����ƂɂȂ�������Ă�B�������Ȃ��Breturn;

				// ��������̒l�ύX
				{
					p�������[iBushouID].��������y��ԍ��z= iNewCastleID+1;
				}

				/* �@����
				      ��
				   ��-��-��-��

				   �Ƃ����̂�

				   ��-��-��

				   �Ƃ���B
				*/

				int iPrevID = p�������[iBushouID].�O�̕����y�����ԍ��z;
				int iNextID = p�������[iBushouID].���̕����y�����ԍ��z;

				// �]���ɂ����������́A���ܘQ�l���X�g�̐擪��
				if ( p����[iCastleID]._�Q�l�擪�����y�����ԍ��z-1 == iBushouID ) {
					p����[iCastleID]._�Q�l�擪�����y�����ԍ��z =  iNextID; // ������next�����ɂ���B
				}

				// ������prev�͗L���ȕ������B
				if ( 0 < iPrevID && iPrevID <= �ő吔::�������::�z�� ) {

					// �������擪�ł͂Ȃ������ŁA
					// �P�O�̐l�̎��̃����N�悪�������g�̏ꍇ
					if ( iPrevID != 0xFFFF && p�������[(iPrevID-1)].���̕����y�����ԍ��z == iBushouID+1 ) {
						// �����ł͂Ȃ��A���̐l�ւƌq��������B
						p�������[(iPrevID-1)].���̕����y�����ԍ��z = iNextID;
					}
				}

				// ������next�͗L���ȕ������B
				if ( 0 < iNextID && iNextID <= �ő吔::�������::�z�� ) {
					// �P��̐l�̑O�̃����N�悪�������g�̏ꍇ
					if ( iNextID != 0xFFFF && p�������[(iNextID-1)].�O�̕����y�����ԍ��z == iBushouID+1 ) {
						// �����ł͂Ȃ��A�O�̐l�ւƌq��������B
						p�������[(iNextID-1)].�O�̕����y�����ԍ��z = iPrevID;
					}
				}


				/* �]����̏���̘Q�l���X�g�@

				��-��

				�Ƃ����̂�

				��-��-��

				�Ƃ���B
				*/

				// �Q�l�Ƃ��Ă݂Ȃ������A������next�́A���ݘQ�l���X�g�̐擪�̐l
				int iRonin = p����[iNewCastleID]._�Q�l�擪�����y�����ԍ��z;
				p�������[iBushouID].���̕����y�����ԍ��z = iRonin; // ���݂̐擪�̐l�������̎��̐l��

				// next���L���ȕ����Ȃ�΁c
				if ( 0 < iRonin && iRonin <= �ő吔::�������::�z�� ) {
					// ���̐l��prev��������
					p�������[iRonin-1].�O�̕����y�����ԍ��z = iBushouID+1;
				}
				p�������[iBushouID].�O�̕����y�����ԍ��z = 0xFFFF; // prev�͋��Ȃ�

				p����[iNewCastleID]._�Q�l�擪�����y�����ԍ��z = iBushouID+1; // ��̘Q�l�̐擪�������ɂ���B

				return true;

			}
		}
	}

	return false;
}

namespace �֐� {

int Set_�����a��(int ��ԍ�) {
	if ( p_GeneralABushouBornExecute ) {
		int iBushouID = p_GeneralABushouBornExecute( ��ԍ� );
		return iBushouID;
	}
	return -1;
}

bool Set_�����]��(int �����ԍ��y�z��p�z, int �]�����ԍ��y�z��p�z) {
	int iBushouID = �����ԍ��y�z��p�z;

	if ( 0 <= iBushouID && iBushouID < �ő吔::�������::�z�� ) {

		// ���̋���ƐV��������
		int iCastleID = p�������[iBushouID].��������y��ԍ��z-1;
		int iNewCastleID = �]�����ԍ��y�z��p�z;

		if ( iCastleID == iNewCastleID ) { return true; } // ������ꏊ�ƁA�]���悪�����Ȃ牽������K�v�͂Ȃ��B

		// �Q�l�̏ꍇ�͈ړ]���邾��
		if ( p�����ːЏ��[iBushouID].��� == ���::�Q�l ) { // �Q�l�����̏ꍇ��������������B
			return _Set_�����]���s�Q�l�t(�����ԍ��y�z��p�z, �]�����ԍ��y�z��p�z);

		// �����̏ꍇ�́A�Q�l�����Ă���A�ړ]���āA�܂�(�\�ł����)�����ɖ߂��B
		// �������邾�ƘQ�l�̂܂܈ړ]���邱�ƂƂȂ�B
		} else if ( p�����ːЏ��[iBushouID].��� == ���::���� ) {
			int _�M�� = p�������[�����ԍ��y�z��p�z].�M��;
			int _�d���N�� = p�������[�����ԍ��y�z��p�z].�d���N��;
			int _�g�� = p�����ːЏ��[�����ԍ��y�z��p�z].�g��;
			int _���� = p�������[�����ԍ��y�z��p�z].����;
			int _���� = p�������[�����ԍ��y�z��p�z].����;
			int _�P�� = p�������[�����ԍ��y�z��p�z].�P��;
			int _�m�C = p�������[�����ԍ��y�z��p�z].�m�C;
			int _���� = p�������[�����ԍ��y�z��p�z].����;
			int _�喼 = p�������[�����ԍ��y�z��p�z].�����喼�y�喼�ԍ��z;
			int _������喼 = p�������[�����ԍ��y�z��p�z].������喼�y�喼�ԍ��z;
			int _������� = p�������[�����ԍ��y�z��p�z].�������;

			bool is�Q�l�� = Set_������ԁs�������Q�l�t(�����ԍ��y�z��p�z);
			if (! is�Q�l��) { return false; }

			bool is�]���� = _Set_�����]���s�Q�l�t(�����ԍ��y�z��p�z, �]�����ԍ��y�z��p�z);
			if (! is�]����) { return false; }

			bool is������ = Set_������ԁs�Q�l�������t(�����ԍ��y�z��p�z);
			if (! is������) { return false; }

			p�������[�����ԍ��y�z��p�z].�M�� = _�M��;
			p�����ːЏ��[�����ԍ��y�z��p�z].�g�� = _�g��;
			p�������[�����ԍ��y�z��p�z].���� = _����;
			p�������[�����ԍ��y�z��p�z].���� = _����;
			p�������[�����ԍ��y�z��p�z].�P�� = _�P��;
			p�������[�����ԍ��y�z��p�z].�m�C = _�m�C;
			p�������[�����ԍ��y�z��p�z].���� = _����;

			// �]���O�Ɠ]����ő喼���ω����Ă��Ȃ��ꍇ�̂݁A�m���N��������n�����̒l�𕜌�
			if (_�喼 == p�������[�����ԍ��y�z��p�z].�����喼�y�喼�ԍ��z) {
				p�������[�����ԍ��y�z��p�z].�d���N�� = _�d���N��;
				p�������[�����ԍ��y�z��p�z].������喼�y�喼�ԍ��z = _������喼;
				p�������[�����ԍ��y�z��p�z].������� = _�������;
			} else {
				p�������[�����ԍ��y�z��p�z].�⍦��� = 0; // �喼���ω����Ă���΁A���݂͏����B
			}

		}
	}
	return false;
}



// �����̗֔z��B(�v�Z�p)
int ����������[32] = {8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7};

// A������B�����̑����̍����𓾂�
// �ŏ�0(�����ō�) �ő�8(�����ň�)
int Get_������(int �����l�`, int �����l�a) {

	// �͈̓`�F�b�N
	if ( �����l�` < 0 ) {
		�����l�` = 0;
		�f�o�b�O�o��("�����l�`���O��菬�����w�肳��Ă���");
	}
	if ( �����l�a < 0 ) {
		�����l�a = 0;
		�f�o�b�O�o��("�����l�a���O��菬�����w�肳��Ă���");
	}
	if ( �����l�` >= �ő吔::�������::������ ) {
		�����l�` = �ő吔::�������::������-1;
		�f�o�b�O�o��("�����l�`���P�T���傫���w�肳��Ă���");
	} 
	if ( �����l�a >= �ő吔::�������::������ ) {
		�����l�a = �ő吔::�������::������-1;
		�f�o�b�O�o��("�����l�a���P�T���傫���w�肳��Ă���");
	} 

	// �܂��AA�����̑����ʒu�𒆉�������
	int �`�̑����ʒu = 0;
	for (int ������IX=8; ������IX<8+�ő吔::�������::������; ������IX++ ) {
		// A�̑����l����������A������A�̈ʒu
		if ( ����������[������IX] == �����l�` ) {
			�`�̑����ʒu = ������IX;
		}
	}

	// �s���Ȑ����̏ꍇ�́A�������͍ł��������̂Ƃ���B
	if ( �`�̑����ʒu == 0 ) { return 8; }

	// B�����̑����ʒu��A������-8����X�^�[�g
	int �a�̑����ʒu = 0;
	for (int ������IX=�`�̑����ʒu-8; ������IX<�`�̑����ʒu+8; ������IX++ ) {
		// B�̑����l����������A������B�̈ʒu
		if ( ����������[������IX] == �����l�a ) {
			�a�̑����ʒu = ������IX;
		}
	}

	// �s���Ȑ����̏ꍇ�́A�������͍ł��������̂Ƃ���B
	if ( �a�̑����ʒu == 0 ) { return 8; }

	// �Q�̑����̈ʒu�̍�����������
	return abs(�a�̑����ʒu-�`�̑����ʒu);
}


/*
* 2�l�̕���ID���瑊���̈Ⴂ�𓾂�B
* �ŏ�0(�����ō�) �ő�8(�����ň�)
*/
int Get_����������(int �����`�ԍ��y�z��p�z, int �����a�ԍ��y�z��p�z) {

	// �͈̓`�F�b�N
	if ( 0 <= �����`�ԍ��y�z��p�z && �����`�ԍ��y�z��p�z < �ő吔::�������::�z�� ) {
	} else {
		�f�o�b�O�o��("�����`�ԍ��y�z��p�z�͔͈͊O");
	}

	// �͈̓`�F�b�N
	if ( 0 <= �����a�ԍ��y�z��p�z && �����a�ԍ��y�z��p�z < �ő吔::�������::�z�� ) {
	} else {
		�f�o�b�O�o��("�����a�ԍ��y�z��p�z�͔͈͊O");
	}
	if ( 0 <= �����`�ԍ��y�z��p�z && �����`�ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		0 <= �����a�ԍ��y�z��p�z && �����a�ԍ��y�z��p�z < �ő吔::�������::�z�� ) {
		// �����̑����̍���Ԃ�
		return Get_������( p�������[�����`�ԍ��y�z��p�z].����, p�������[�����a�ԍ��y�z��p�z].���� );
	} else {
		return -1;
	}
}



int Get_��ӌ�(int �����ԍ��y�z��p�z) {
	if ( p_GetKaikenIkouAI ) {
		return p_GetKaikenIkouAI(�����ԍ��y�z��p�z);
	}
	return ��ӌ�::�Ê�;
}

void Set_��ӌ�(int �����ԍ��y�z��p�z, int ��ӌ�) {
	if ( p_SetKaikenIkouAI ) {
		p_SetKaikenIkouAI(�����ԍ��y�z��p�z, ��ӌ�);
	}
}







bool Is_�����͑���̖�( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	if ( 0 <= ���������ԍ��y�z��p�z && ���������ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		 0 <= ���蕐���ԍ��y�z��p�z && ���蕐���ԍ��y�z��p�z < �ő吔::�������::�z��) {

		if ( p�������[���������ԍ��y�z��p�z].�e��ԍ� == p�����ːЏ��[���蕐���ԍ��y�z��p�z].��ԍ� && 
			 Get_�����N��(���������ԍ��y�z��p�z) < Get_�����N��(���蕐���ԍ��y�z��p�z) &&
			 p�����ːЏ��[���������ԍ��y�z��p�z].���� == ����::�� ) {
			
			 return true;
		}
	}
	return false;
}

bool Is_�����͑���̑��q( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	if ( 0 <= ���������ԍ��y�z��p�z && ���������ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		 0 <= ���蕐���ԍ��y�z��p�z && ���蕐���ԍ��y�z��p�z < �ő吔::�������::�z��) {

		if ( p�������[���������ԍ��y�z��p�z].�e��ԍ� == p�����ːЏ��[���蕐���ԍ��y�z��p�z].��ԍ� && 
			 Get_�����N��(���������ԍ��y�z��p�z) < Get_�����N��(���蕐���ԍ��y�z��p�z) &&
			 p�����ːЏ��[���������ԍ��y�z��p�z].���� == ����::�j ) {
			
			 return true;
		}
	}
	return false;
}

bool Is_�����͑���̎q( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	if ( 0 <= ���������ԍ��y�z��p�z && ���������ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		 0 <= ���蕐���ԍ��y�z��p�z && ���蕐���ԍ��y�z��p�z < �ő吔::�������::�z��) {

		if ( p�������[���蕐���ԍ��y�z��p�z].�e��ԍ� == p�����ːЏ��[���������ԍ��y�z��p�z].��ԍ� && 
			 Get_�����N��(���������ԍ��y�z��p�z) < Get_�����N��(���蕐���ԍ��y�z��p�z) ) {

			 return true;
		}
	}
	return false;
}

bool Is_�����͑���̐e( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	if ( 0 <= ���������ԍ��y�z��p�z && ���������ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		 0 <= ���蕐���ԍ��y�z��p�z && ���蕐���ԍ��y�z��p�z < �ő吔::�������::�z��) {
		if ( p�������[���蕐���ԍ��y�z��p�z].�e��ԍ� == p�����ːЏ��[���������ԍ��y�z��p�z].��ԍ� && 
			 Get_�����N��(���������ԍ��y�z��p�z) > Get_�����N��(���蕐���ԍ��y�z��p�z) ) {

			 return true;
		}
	}
	return false;
}

bool Is_�����͑���̕�( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	if ( 0 <= ���������ԍ��y�z��p�z && ���������ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		 0 <= ���蕐���ԍ��y�z��p�z && ���蕐���ԍ��y�z��p�z < �ő吔::�������::�z��) {

		if ( p�������[���蕐���ԍ��y�z��p�z].�e��ԍ� == p�����ːЏ��[���������ԍ��y�z��p�z].��ԍ� && 
			 Get_�����N��(���������ԍ��y�z��p�z) > Get_�����N��(���蕐���ԍ��y�z��p�z) &&
			 p�����ːЏ��[���������ԍ��y�z��p�z].���� == ����::�j ) {

			 return true;
		}
	}
	return false;
}

bool Is_����͎����̕�( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	return Is_�����͑���̕�(���蕐���ԍ��y�z��p�z, ���������ԍ��y�z��p�z);
}



bool Is_�����͑���̕�( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	if ( 0 <= ���������ԍ��y�z��p�z && ���������ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		 0 <= ���蕐���ԍ��y�z��p�z && ���蕐���ԍ��y�z��p�z < �ő吔::�������::�z��) {

		if ( p�������[���蕐���ԍ��y�z��p�z].�e��ԍ� == p�����ːЏ��[���������ԍ��y�z��p�z].��ԍ� && 
			 Get_�����N��(���������ԍ��y�z��p�z) > Get_�����N��(���蕐���ԍ��y�z��p�z) &&
			 p�����ːЏ��[���������ԍ��y�z��p�z].���� == ����::�� ) {

			 return true;
		}
	}
	return false;
}

bool Is_����͎����̕�( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	return Is_�����͑���̕�(���蕐���ԍ��y�z��p�z, ���������ԍ��y�z��p�z);
}

bool Is_�����͑���̒�( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	if ( 0 <= ���������ԍ��y�z��p�z && ���������ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		 0 <= ���蕐���ԍ��y�z��p�z && ���蕐���ԍ��y�z��p�z < �ő吔::�������::�z��) {

		if ( p�������[���������ԍ��y�z��p�z].�e��ԍ� < 5000 && 
			 p�������[���������ԍ��y�z��p�z].�e��ԍ� == p�������[���蕐���ԍ��y�z��p�z].�e��ԍ� && 
			 Get_�����N��(���������ԍ��y�z��p�z) < Get_�����N��(���蕐���ԍ��y�z��p�z) &&
			 p�����ːЏ��[���������ԍ��y�z��p�z].���� == ����::�j ) {

			 return true;
		}
	}
	return false;
}

bool Is_����͎����̒�( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	return Is_�����͑���̒�( ���蕐���ԍ��y�z��p�z, ���������ԍ��y�z��p�z );
}

bool Is_�����͑���̖�( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	if ( 0 <= ���������ԍ��y�z��p�z && ���������ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		 0 <= ���蕐���ԍ��y�z��p�z && ���蕐���ԍ��y�z��p�z < �ő吔::�������::�z��) {

		if ( p�������[���������ԍ��y�z��p�z].�e��ԍ� < 5000 && 
			 p�������[���������ԍ��y�z��p�z].�e��ԍ� == p�������[���蕐���ԍ��y�z��p�z].�e��ԍ� && 
			 Get_�����N��(���������ԍ��y�z��p�z) < Get_�����N��(���蕐���ԍ��y�z��p�z) &&
			 p�����ːЏ��[���������ԍ��y�z��p�z].���� == ����::�� ) {

			 return true;
		}
	}
	return false;
}

bool Is_����͎����̖�( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	return Is_�����͑���̖�( ���蕐���ԍ��y�z��p�z, ���������ԍ��y�z��p�z );
}

bool Is_�����͑���̌Z( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	if ( 0 <= ���������ԍ��y�z��p�z && ���������ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		 0 <= ���蕐���ԍ��y�z��p�z && ���蕐���ԍ��y�z��p�z < �ő吔::�������::�z��) {

		if ( p�������[���������ԍ��y�z��p�z].�e��ԍ� < 5000 && 
			 p�������[���������ԍ��y�z��p�z].�e��ԍ� == p�������[���蕐���ԍ��y�z��p�z].�e��ԍ� && 
			 Get_�����N��(���������ԍ��y�z��p�z) > Get_�����N��(���蕐���ԍ��y�z��p�z) &&
			 p�����ːЏ��[���������ԍ��y�z��p�z].���� == ����::�j ) {

			 return true;
		}
	}
	return false;
}

bool Is_����͎����̌Z( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	return Is_�����͑���̌Z( ���蕐���ԍ��y�z��p�z, ���������ԍ��y�z��p�z);
}


bool Is_�����͑���̎o( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	if ( 0 <= ���������ԍ��y�z��p�z && ���������ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		 0 <= ���蕐���ԍ��y�z��p�z && ���蕐���ԍ��y�z��p�z < �ő吔::�������::�z��) {

		if ( p�������[���������ԍ��y�z��p�z].�e��ԍ� < 5000 && 
			 p�������[���������ԍ��y�z��p�z].�e��ԍ� == p�������[���蕐���ԍ��y�z��p�z].�e��ԍ� && 
			 Get_�����N��(���������ԍ��y�z��p�z) > Get_�����N��(���蕐���ԍ��y�z��p�z) &&
			 p�����ːЏ��[���������ԍ��y�z��p�z].���� == ����::�� ) {

			 return true;
		}
	}
	return false;
}

bool Is_����͎����̎o( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	return Is_�����͑���̎o( ���蕐���ԍ��y�z��p�z, ���������ԍ��y�z��p�z);
}

bool Is_�����Ƒ���͌Z��( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	if ( 0 <= ���������ԍ��y�z��p�z && ���������ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		 0 <= ���蕐���ԍ��y�z��p�z && ���蕐���ԍ��y�z��p�z < �ő吔::�������::�z��) {

		if ( p�������[���������ԍ��y�z��p�z].�e��ԍ� < 5000 && 
			 p�������[���������ԍ��y�z��p�z].�e��ԍ� == p�������[���蕐���ԍ��y�z��p�z].�e��ԍ� &&
			 Get_�����N��(���������ԍ��y�z��p�z) > Get_�����N��(���蕐���ԍ��y�z��p�z) &&
			 p�����ːЏ��[���������ԍ��y�z��p�z].���� == ����::�j && p�����ːЏ��[���蕐���ԍ��y�z��p�z].���� == ����::�j) {

			 return true;
		}
	}
	return false;
}

bool Is_�����Ƒ���͎o��( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	if ( 0 <= ���������ԍ��y�z��p�z && ���������ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		 0 <= ���蕐���ԍ��y�z��p�z && ���蕐���ԍ��y�z��p�z < �ő吔::�������::�z��) {

		if ( p�������[���������ԍ��y�z��p�z].�e��ԍ� < 5000 && 
			 p�������[���������ԍ��y�z��p�z].�e��ԍ� == p�������[���蕐���ԍ��y�z��p�z].�e��ԍ� && 
			 Get_�����N��(���������ԍ��y�z��p�z) > Get_�����N��(���蕐���ԍ��y�z��p�z) &&
			 p�����ːЏ��[���������ԍ��y�z��p�z].���� == ����::�� && p�����ːЏ��[���蕐���ԍ��y�z��p�z].���� == ����::��) {

			 return true;
		}
	}
	return false;
}


bool Is_�����Ƒ���͎o��( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	if ( 0 <= ���������ԍ��y�z��p�z && ���������ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		 0 <= ���蕐���ԍ��y�z��p�z && ���蕐���ԍ��y�z��p�z < �ő吔::�������::�z��) {

		if ( p�������[���������ԍ��y�z��p�z].�e��ԍ� < 5000 && 
			 p�������[���������ԍ��y�z��p�z].�e��ԍ� == p�������[���蕐���ԍ��y�z��p�z].�e��ԍ� &&
			 Get_�����N��(���������ԍ��y�z��p�z) > Get_�����N��(���蕐���ԍ��y�z��p�z) &&
			 p�����ːЏ��[���������ԍ��y�z��p�z].���� == ����::�� && p�����ːЏ��[���蕐���ԍ��y�z��p�z].���� == ����::�j) {

			 return true;
		}
	}
	return false;
}



bool Is_�����Ƒ���͌Z��( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	if ( 0 <= ���������ԍ��y�z��p�z && ���������ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		 0 <= ���蕐���ԍ��y�z��p�z && ���蕐���ԍ��y�z��p�z < �ő吔::�������::�z��) {

		if ( p�������[���������ԍ��y�z��p�z].�e��ԍ� < 5000 && 
			 p�������[���������ԍ��y�z��p�z].�e��ԍ� == p�������[���蕐���ԍ��y�z��p�z].�e��ԍ� &&
			 Get_�����N��(���������ԍ��y�z��p�z) > Get_�����N��(���蕐���ԍ��y�z��p�z) &&
			 p�����ːЏ��[���������ԍ��y�z��p�z].���� == ����::�j && p�����ːЏ��[���蕐���ԍ��y�z��p�z].���� == ����::��) {

			 return true;
		}
	}
	return false;
}




bool Is_�����͑���̕v( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	if ( 0 <= ���������ԍ��y�z��p�z && ���������ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		 0 <= ���蕐���ԍ��y�z��p�z && ���蕐���ԍ��y�z��p�z < �ő吔::�������::�z��) {

		if ( p�������[���������ԍ��y�z��p�z]._�� != 0xFF &&
			 p�������[���������ԍ��y�z��p�z]._�� == p�������[���蕐���ԍ��y�z��p�z]._�� && 
			 p�����ːЏ��[���������ԍ��y�z��p�z].���� == ����::�j ) {

			 return true;
		}
	}
	return false;
}

bool Is_�����͑���̍�( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	if ( 0 <= ���������ԍ��y�z��p�z && ���������ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		 0 <= ���蕐���ԍ��y�z��p�z && ���蕐���ԍ��y�z��p�z < �ő吔::�������::�z��) {

		if ( p�������[���������ԍ��y�z��p�z]._�� != 0xFF &&
			 p�������[���������ԍ��y�z��p�z]._�� == p�������[���蕐���ԍ��y�z��p�z]._�� && 
			 p�����ːЏ��[���������ԍ��y�z��p�z].���� == ����::�� ) {

			 return true;
		}
	}
	return false;
}


bool Is_�����͑���̌���( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	if ( 0 <= ���������ԍ��y�z��p�z && ���������ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		 0 <= ���蕐���ԍ��y�z��p�z && ���蕐���ԍ��y�z��p�z < �ő吔::�������::�z��) {

		if ( p�������[���������ԍ��y�z��p�z].�������� != 0xFF &&
			p�������[���������ԍ��y�z��p�z].�������� == p�������[���蕐���ԍ��y�z��p�z].�������� ) {

			return true;
		}
	}
	return false;
}

bool Is_����͎����̉Ɛb( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	if ( 0 <= ���������ԍ��y�z��p�z && ���������ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		 0 <= ���蕐���ԍ��y�z��p�z && ���蕐���ԍ��y�z��p�z < �ő吔::�������::�z��) {
		 // ��P�l�̂͑喼
		if ( p�����ːЏ��[���������ԍ��y�z��p�z].��� == ���::�喼 ) {
			// ��Q�l�̂͑喼�ɂ����Ə������Ă���B
			if ( 0 <= p�������[���蕐���ԍ��y�z��p�z].�����喼�y�喼�ԍ��z-1 && p�������[���蕐���ԍ��y�z��p�z].�����喼�y�喼�ԍ��z-1 < �ő吔::�喼���::�z�� ) {
				int iAttachDaimyoID = p�������[���蕐���ԍ��y�z��p�z].�����喼�y�喼�ԍ��z-1;
				if ( ���������ԍ��y�z��p�z == p�喼���[iAttachDaimyoID].�喼�y�����ԍ��z-1 ) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Is_����͎����̑喼( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	return Is_����͎����̉Ɛb( ���蕐���ԍ��y�z��p�z, ���������ԍ��y�z��p�z );
}

// �Ɛb�͂������A�喼���g�������̑喼�Ƃɏ������Ă���Ƃ݂Ȃ����B
bool Is_�����Ƒ���͓����喼�Ə���( int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z ) {
	if ( 0 <= ���������ԍ��y�z��p�z && ���������ԍ��y�z��p�z < �ő吔::�������::�z�� &&
		 0 <= ���蕐���ԍ��y�z��p�z && ���蕐���ԍ��y�z��p�z < �ő吔::�������::�z��) {

		int i1stAttachDaimyoID = -1;
		int i2ndAttachDaimyoID = -1;

		// ��P�l�̂͑喼�ɂ����Ə������Ă���B
		if ( 0 <= p�������[���������ԍ��y�z��p�z].�����喼�y�喼�ԍ��z-1 && p�������[���������ԍ��y�z��p�z].�����喼�y�喼�ԍ��z-1 < �ő吔::�喼���::�z�� ) {
			i1stAttachDaimyoID = p�������[���������ԍ��y�z��p�z].�����喼�y�喼�ԍ��z-1;
		}

		// ��Q�l�̂͑喼�ɂ����Ə������Ă���B
		if ( 0 <= p�������[���蕐���ԍ��y�z��p�z].�����喼�y�喼�ԍ��z-1 && p�������[���蕐���ԍ��y�z��p�z].�����喼�y�喼�ԍ��z-1 < �ő吔::�喼���::�z�� ) {
			i2ndAttachDaimyoID = p�������[���蕐���ԍ��y�z��p�z].�����喼�y�喼�ԍ��z-1;
		}

		if ( i1stAttachDaimyoID != -1 && i2ndAttachDaimyoID != -1 ) {
			if ( i1stAttachDaimyoID == i2ndAttachDaimyoID ) { 
				return true;
			}
		}
	}
	return false;
}

} // namespace �֐�
