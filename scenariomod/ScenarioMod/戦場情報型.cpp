#include <cassert>
#include <math.h>
#include "�Q�[���f�[�^�\��.h"
#include <map>
using namespace std;


extern HMODULE hModuleTSMod;

using PFNISBATTLEMODE				 = int (WINAPI *)();
PFNISBATTLEMODE p_IsBattleMode = NULL;

using PFNGETCURINCREMENTTURNINBATTLE = int (WINAPI *)();
PFNGETCURINCREMENTTURNINBATTLE p_GetCurIncrementTurnInBattle = NULL;

using PFNGETREMAINTURNINBATTLE		 = int (WINAPI *)();
PFNGETREMAINTURNINBATTLE p_GetRemainTurnInBattle = NULL;

using PFNGETCASTLETURNINBATTLE		 = int (WINAPI *)();
PFNGETCASTLETURNINBATTLE p_GetCastleTurnInBattle = NULL;



// TSMod�ɂ����Ȃ�����Đ��֐��̃|�C���^�̓o�^
void _�퓬�֘A�o�^() {
	// �퓬�����ǂ����B�i���C����ʏ�̐푈���푈���Ƃ݂Ȃ��j
	p_IsBattleMode = (PFNISBATTLEMODE)GetProcAddress( hModuleTSMod, "Extern_IsBattleMode" );

	// ���݂�TSMod���̑f��iCurIncrementTurnInBattle�l�B��ʂ��푈�����ǂ����̔���ɕK�v�B
	p_GetCurIncrementTurnInBattle = (PFNGETCURINCREMENTTURNINBATTLE)GetProcAddress( hModuleTSMod, "Extern_GetCurIncrementTurnInBattle" );

	// �c��^�[���擾�p�̊֐�
	p_GetRemainTurnInBattle = (PFNGETREMAINTURNINBATTLE)GetProcAddress( hModuleTSMod, "Extern_getRemainTurnInBattle" );

	// ���݂�TSMod���̑f��iCurIncrementTurnInBattle�l�B��ʂ��푈�����ǂ����̔���ɕK�v�B
	p_GetCastleTurnInBattle = (PFNGETCASTLETURNINBATTLE)GetProcAddress( hModuleTSMod, "Extern_getCastleTurnInBattle" );

}





//------------------------------------------------�ȉ� HEX�֌W�̒�`
#define GAMEDATASTRUCT_CASTLE_HEX_ROLE_ADDRESS	0x4D5182	// ����̖����̊T�O�̃f�[�^�̃A�h���X(18*16�o�C�g)
#define GAMEDATASTRUCT_CASTLE_HEX_HIGH_ADDRESS	0x4D555A	// ����̍����̊T�O�̃f�[�^�̃A�h���X(18*16�o�C�g)


#define GAMEDATASTRUCT_FIELD_HEX_ROLE_ADDRESS	0x4D5182	// ���̖����̊T�O�̃f�[�^�̃A�h���X(41*24�o�C�g)
#define GAMEDATASTRUCT_FIELD_HEX_UNIT_POS_ADDRESS	0x4D5932	// ���Ń��j�b�g������ʒu���|�c���|�c���B���ݕ\������HEX�}�b�v�łقƂ�ǂ�FF�A���j�b�g����Ƃ���́A���j�b�g�ԍ��������Ă���B
#define GAMEDATASTRUCT_CASTLE_HEX_UNIT_POS_ADDRESS	0x4D5932	// �U���Ń��j�b�g������ʒu���|�c���|�c���B���ݕ\������HEX�}�b�v�łقƂ�ǂ�FF�A���j�b�g����Ƃ���́A���j�b�g�ԍ��������Ă���B
																// ���Ƌ��ʂ̃A�h���X�B
#define GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_ADDRESS	0x4D5D58	// HEX�}�b�v�ɂ�����e���j�b�g�̏��(1�l32bit) x 1�邩��o�Ă���W�l �~ �P��킠����X��ō��v 72�lx32bit
#define GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM	72			// HEX�}�b�v�ɂ����郆�j�b�g�̍ő吔�B1�邩��o�Ă���W�l �~ �P��킠����X��

#define GAMEDATASTRUCT_CASTLE_HEX_FIRE_ROLE_ADDRESS	0x4D4DAA	// ����̉΂̎�֘A�̊T�O�̃f�[�^�̃A�h���X(18*16�o�C�g)

#define GAMEDATASTRUCT_FIELD_HEX_COLS			41	// ����HEX�̉��̐�
#define GAMEDATASTRUCT_FIELD_HEX_ROWS			24	// ����HEX�̏c�̐�

#define GAMEDATASTRUCT_CASTLE_HEX_COLS			18	// �U����HEX�̉��̐�
#define GAMEDATASTRUCT_CASTLE_HEX_ROWS			16	// �U����HEX�̏c�̐�

#define GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_ADDRESS	0x4D4D48	//  �w�b�N�X�}�b�v�ɂ����āA���̐푈�Ɋւ���Ă���u�喼�E�R�c�E���叫�E[�U�ߎ�E�󂯎�E����]�v���
#define GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_NUM		9			//  �푈�Ɋ֌W����喼�͍ő�X�喼�܂ŁB


// �퓬��ʂ̏���w�b�N�X�̖����̃o�C�g��
union NB6CASTLE_HEX_ROLE {
	BYTE index[GAMEDATASTRUCT_CASTLE_HEX_COLS * GAMEDATASTRUCT_CASTLE_HEX_ROWS];				// �o�C�g��̃C���f�b�N�X�Ƃ��Ă݂��ꍇ
	struct {
		BYTE pos_x[GAMEDATASTRUCT_CASTLE_HEX_COLS];				// 18���A16�s�Ƃ��Č����ꍇ;
	} pos_y[GAMEDATASTRUCT_CASTLE_HEX_ROWS];
};

// �퓬��ʂ̏���w�b�N�X�̍����̃o�C�g��
union NB6CASTLE_HEX_HIGH {
	BYTE index[GAMEDATASTRUCT_CASTLE_HEX_COLS * GAMEDATASTRUCT_CASTLE_HEX_ROWS];				// �o�C�g��̃C���f�b�N�X�Ƃ��Ă݂��ꍇ
	struct {
		BYTE pos_x[GAMEDATASTRUCT_CASTLE_HEX_COLS];				// 18���A16�s�Ƃ��Č����ꍇ;
	} pos_y[GAMEDATASTRUCT_CASTLE_HEX_ROWS];
};

// ��U���̃��j�b�g�̃}�b�v���̃|�W�V����
union NB6CASTLE_HEX_UNIT_POS {
	BYTE index[GAMEDATASTRUCT_CASTLE_HEX_COLS * GAMEDATASTRUCT_CASTLE_HEX_ROWS];				// �o�C�g��̃C���f�b�N�X�Ƃ��Ă݂��ꍇ
	struct {
		BYTE pos_x[GAMEDATASTRUCT_CASTLE_HEX_COLS];				// 18���A16�s�Ƃ��Č����ꍇ;
	} pos_y[GAMEDATASTRUCT_CASTLE_HEX_ROWS];
};

// ��펞�̃w�b�N�X�̖����̃o�C�g��
union NB6FIELD_HEX_ROLE {
	BYTE index[GAMEDATASTRUCT_FIELD_HEX_COLS * GAMEDATASTRUCT_FIELD_HEX_ROWS];				// �o�C�g��̃C���f�b�N�X�Ƃ��Ă݂��ꍇ
	struct {
		BYTE pos_x[GAMEDATASTRUCT_FIELD_HEX_COLS];				// 41���A24�s�Ƃ��Č����ꍇ;
	} pos_y[GAMEDATASTRUCT_FIELD_HEX_ROWS];
};

// ��펞�̃��j�b�g�̃}�b�v���̃|�W�V����
union NB6FIELD_HEX_UNIT_POS {
	BYTE index[GAMEDATASTRUCT_FIELD_HEX_COLS * GAMEDATASTRUCT_FIELD_HEX_ROWS];				// �o�C�g��̃C���f�b�N�X�Ƃ��Ă݂��ꍇ
	struct {
		BYTE pos_x[GAMEDATASTRUCT_FIELD_HEX_COLS];				// 41���A24�s�Ƃ��Č����ꍇ;
	} pos_y[GAMEDATASTRUCT_FIELD_HEX_ROWS];
};

// ���̃��j�b�g�ԍ�
struct NB6BUSHOU_HEX_UNIT_INFO {
	WORD bushou;					// �����ԍ��B1�傫�����̕��B�����z��ԍ��Ɏ����ɂ�-1���邱�ƁB
	WORD junban;					// ���̒l�̓^�[�����ԁB�푈�ɂ����āA���̐��l���Ⴂ�R�c���珇�Ԃ����Ƃ������ƁB
	int	 pos_x;						// �s���ɂ�����pos_x�B�߂܂�����A�ދp�����肵�āA��ꂩ�狏�Ȃ��Ȃ�ƁA0xFFFF
	int	 pos_y;						// �s���ɂ�����pos_y�B�߂܂�����A�ދp�����肵�āA��ꂩ�狏�Ȃ��Ȃ�ƁA0xFFFF
	BYTE movepower;					// �ړ��͎c�ʁB0x1�`0xF���炢�̐��l�������Ă���B
	WORD _undef2;					// �s��2 ���j�b�g���݂��Ă�̂�FFFF�A���Ă��Ȃ��̂�
	BYTE _undef3;					// �s��1
	BYTE _undef4;					// �s��1
	BYTE _undef5;					// �s��1
	WORD _what1;					// �����Ӗ������肻���B1�`8���炢�̐��l�������Ă���B
	WORD _undef6;					// �ق�0x0000
	WORD _undef7;					// �ق�0xFFFF
	BYTE konran:4;					// 1=�ʏ퍬�� 2=�卬��
	BYTE bEnd:4;					// �s���σt���O�B0x2=�s���ς�, 0x0=���s��
	BYTE _what4;					// �����Ӗ������肻���B���݂��Ă镐���́A�0x2�������
	WORD _what5;					// �����Ӗ������肻���B���݂��Ă镐���́A�0x70�������
	int	 _undef8;					// �s��
};

// �w�b�N�X�}�b�v�ɂ�����B�S���^�[������A�喼�A�R�c�ȂǁB
struct NB6GUNDAN_HEX_INFO {
	int _undef;			// �s��
	int daimyo;			// ���݃^�[���̑喼�ԍ�
	int gundan;			// ���݃^�[���̌R�c�ԍ�
	int seiryoku;		// ���݃^�[���̐��́B����U���̃w�b�N�X�}�b�v���ɂ����āA���ǂ���̃^�[�����Ȃ̂��A1=�󂯎�A2=�U�ߎ�
						// ���炭�A1���󂯂āA�Q���U�߂āA�R�������A�S������
};

// �w�b�N�X�}�b�v�ɂ����āA���̐푈�Ɋւ���Ă���u�喼�E�R�c�E���叫�E[�U�ߎ�E�󂯎�E����]�v���
struct NB6WAR_JOINT_DAIMYO_HEX_GROUP_INFO {
	WORD daimyo;		// �喼�ԍ�
	WORD gundan;		// �R�c�ԍ�
	WORD soudaisho;		// ���叫�̕����ԍ�
	WORD group;			// ���Ԃ��U�����A�󑤂��A�Ȃǂ́A�s��B�����܂ł��A�퓬�J�n���̍U�ߑ��喼�Ɠ����O���[�v���U�ߑ��̉��R�A�󑤂̑喼�Ɠ����O���[�v���󑤁A����ȊO�������ł���B
	WORD _undef;		// ���ɂȂɂ��Ȃ��Bmust 0000
};


NB6CASTLE_HEX_ROLE	*const _nb6castle_hex_role = (NB6CASTLE_HEX_ROLE *)GAMEDATASTRUCT_CASTLE_HEX_ROLE_ADDRESS;
NB6CASTLE_HEX_HIGH	*const _nb6castle_hex_high = (NB6CASTLE_HEX_HIGH *)GAMEDATASTRUCT_CASTLE_HEX_HIGH_ADDRESS;

NB6CASTLE_HEX_ROLE *const _nb6fire_hex_role = (NB6CASTLE_HEX_ROLE *)GAMEDATASTRUCT_CASTLE_HEX_FIRE_ROLE_ADDRESS;

NB6FIELD_HEX_ROLE  *const _nb6field_hex_role = (NB6FIELD_HEX_ROLE *)GAMEDATASTRUCT_FIELD_HEX_ROLE_ADDRESS;


NB6CASTLE_HEX_UNIT_POS *const _nb6castle_hex_unit_pos = (NB6CASTLE_HEX_UNIT_POS *)GAMEDATASTRUCT_CASTLE_HEX_UNIT_POS_ADDRESS;
NB6FIELD_HEX_UNIT_POS  *const _nb6field_hex_unit_pos  = (NB6FIELD_HEX_UNIT_POS *)GAMEDATASTRUCT_FIELD_HEX_UNIT_POS_ADDRESS;

NB6BUSHOU_HEX_UNIT_INFO *const nb6bushou_hex_unit_info = (NB6BUSHOU_HEX_UNIT_INFO *)GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_ADDRESS; // ���ɂ�����e�����̏��

NB6WAR_JOINT_DAIMYO_HEX_GROUP_INFO *const nb6war_joint_daimyo_hex_group_info = (NB6WAR_JOINT_DAIMYO_HEX_GROUP_INFO *)GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_ADDRESS; // ���ɎQ�������喼�⑍�叫�̏��

extern NB6FIELD_HEX_ROLE *const _nb6field_hex_role;
extern NB6CASTLE_HEX_ROLE *const _nb6castle_hex_role;
#define							  nb6castle_hex_role		_nb6castle_hex_role[0]
extern NB6CASTLE_HEX_HIGH *const _nb6castle_hex_high;
#define							  nb6castle_hex_high		_nb6castle_hex_high[0]

extern NB6FIELD_HEX_ROLE *const _nb6field_hex_role;
#define							 nb6field_hex_role			_nb6field_hex_role[0]

extern NB6CASTLE_HEX_ROLE *const _nb6fire_hex_role;
#define							  nb6fire_hex_role			_nb6fire_hex_role[0]

extern NB6CASTLE_HEX_UNIT_POS *const _nb6castle_hex_unit_pos;
#define							      nb6castle_hex_unit_pos		_nb6castle_hex_unit_pos[0]
extern NB6FIELD_HEX_UNIT_POS *const  _nb6field_hex_unit_pos;
#define							      nb6field_hex_unit_pos			_nb6field_hex_unit_pos[0]

extern NB6BUSHOU_HEX_UNIT_INFO *const nb6bushou_hex_unit_info;
extern NB6GUNDAN_HEX_INFO	   *const _nb6gundan_hex_info;
#define							      nb6gundan_hex_info		_nb6gundan_hex_info[0]

extern �푈�J�n�p�����^�^ �J�n�p�����^;
//------------------------------------------------�ȏ� HEX�֌W�̒�`


namespace �֐� {

	// ���ݐi�s���̐푈�Ɋւ���Ă���iDaimyoID�̃��X�g�B(�o�w���Ă��邩�ǂ����͊֌W�Ȃ�)
	�ԍ����X�g�^ Get_�Q��̑喼�ԍ����X�g�y�z��p�z() {
		vector<int> list;
		if ( Is_��풆() || Is_�U��풆() ) {
			// �Q���喼�ԍ����������āA
			for ( int ix=0; ix < GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_NUM; ix++ ) {

				int iDaimyoID = (int)nb6war_joint_daimyo_hex_group_info[ix].daimyo - 1;
				// �͈͓��ł���΁A���X�g�ɒǉ�
				if ( 0 <= iDaimyoID && iDaimyoID < �ő吔::�喼���::�z�� ) {
					// �Y���̒l�����ł�list���ɂ��邩
					vector<int>::iterator  iter = std::find( list.begin(), list.end() , iDaimyoID );
					// ���݂��Ȃ���΁c
					if ( iter == list.end() ) {
						// �ǉ�
						list.push_back( iDaimyoID );
					}
				}
			}
		}
		
		return list;
	}

	// ���ݐi�s���̐푈�Ɋւ���Ă���iGundanID�̃��X�g�B(�o�w���Ă��邩�ǂ����͊֌W�Ȃ�)
	�ԍ����X�g�^ Get_�Q��̌R�c�ԍ����X�g�y�z��p�z() {
		vector<int> list;
		if ( Is_��풆() || Is_�U��풆() ) {
			// �Q���喼�ԍ����������āA
			for ( int ix=0; ix < GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_NUM; ix++ ) {

				int iGundanID = (int)nb6war_joint_daimyo_hex_group_info[ix].gundan - 1;
				// �͈͓��ł���΁A���X�g�ɒǉ�
				if ( 0 <= iGundanID && iGundanID < �ő吔::�R�c���::�z�� ) {
					list.push_back( iGundanID );
				}
			}
		}

		return list;
	}


	// �Y���̌R�c�̐��ɂ����闧���Ԃ�(�s��=0, ���ڍU�߂鑤=1, ���ڎ�鑤=2, �U�߂鑤�̉��R=3, ��鑤�̉��R=4, �����R=5)
	int Get_�R�c�̎Q�헧��(int �R�c�ԍ��y�z��p�z) {

		int iGundanID = �R�c�ԍ��y�z��p�z;

		if ( !(0 <= iGundanID && iGundanID < �ő吔::�R�c���::�z�� ) ) {
			return �Q�헧��::�s��;
		}

		if ( Is_��풆() || Is_�U��풆() ) {

			//----------���ڍU���A�������͒��ڎ���̏ꍇ

			// �w��̌R�c�̑喼ID
			int iDaimyoID = p�R�c���[iGundanID].�����喼�y�喼�ԍ��z-1;

			// �U�����̌R�c�̑喼ID
			int iAttackDaimyoID = -1; 
			if ( 0 <= �J�n�p�����^.�U�����R�c�y�R�c�ԍ��z-1 && �J�n�p�����^.�U�����R�c�y�R�c�ԍ��z-1 < �ő吔::�R�c���::�z�� ) {
				iAttackDaimyoID = p�R�c���[�J�n�p�����^.�U�����R�c�y�R�c�ԍ��z-1].�����喼�y�喼�ԍ��z-1;
			}

			// ������̌R�c�̑喼ID
			int iDefendDaimyoID = -1; 
			if ( 0 <= �J�n�p�����^.������R�c�y�R�c�ԍ��z-1 && �J�n�p�����^.������R�c�y�R�c�ԍ��z-1 < �ő吔::�R�c���::�z�� ) {
				iDefendDaimyoID = p�R�c���[�J�n�p�����^.������R�c�y�R�c�ԍ��z-1].�����喼�y�喼�ԍ��z-1;
			}

			// �w��̌R�c�̑喼�͒��ڍU���̑喼
			if ( iDaimyoID == iAttackDaimyoID ) {
				return �Q�헧��::�U���R; // ���ڍU����
			}
			// �w��̌R�c�̑喼�͒��ڎ���̑喼
			else if ( iDaimyoID == iDefendDaimyoID ) {
				return �Q�헧��::����R; // ���ږh�䑤
			}


			// �Q���喼�ԍ����������āA�U�����̃O���[�vID�A������̃O���[�vID���o���B
			for ( int ix=0; ix < GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_NUM; ix++ ) {

				// ���R�⒆���R���`�F�b�N
				int JoinGundanID = (int)nb6war_joint_daimyo_hex_group_info[ix].gundan - 1; // �Q���R�cID
				int JoinDaimyoID = (int)nb6war_joint_daimyo_hex_group_info[ix].daimyo - 1; // �Q���喼ID

				// �w��̌R�c�Ɠ����R�cID�ł���ꍇ�̂ݒl��Ԃ��B
				if (iGundanID == JoinGundanID) {

					// �w��̌R�c�̑喼�͒��ڍU���̑喼
					if (JoinDaimyoID == iAttackDaimyoID) {
						return �Q�헧��::�U���R; // ���ڍU����
					}
					// �w��̌R�c�̑喼�͒��ڎ���̑喼
					else if (JoinDaimyoID == iDefendDaimyoID) {
						return �Q�헧��::����R; // ���ږh�䑤
					}

					// 2��6�Ȃ璆���R�B2�������̐e�R�ŁA6�������̎q�R
					else if (nb6war_joint_daimyo_hex_group_info[ix].group == 2 || nb6war_joint_daimyo_hex_group_info[ix].group == 6) {
						// �����R
						return �Q�헧��::�����R; // �����R
					}
					// 1��5�Ȃ片�R�̍U���R�B1�����R�̐e�R�ŁA5�����R�̎q�R
					else if (nb6war_joint_daimyo_hex_group_info[ix].group == 1 || nb6war_joint_daimyo_hex_group_info[ix].group == 5) {
						// �U���̉��R
						return �Q�헧��::�U���̉��R; // �U���̉��R
					}
					// 0��4�Ȃ片�R�̎���R�B0�����R�̐e�R�ŁA4�����R�̎q�R
					else if (nb6war_joint_daimyo_hex_group_info[ix].group == 0 || nb6war_joint_daimyo_hex_group_info[ix].group == 4) {
						// ����̉��R
						return �Q�헧��::����̉��R; // �h��̉��R
					}

				}
			}
		}

		return �Q�헧��::�s��; // �s��
	}

	// �Y���̕����̐��ɂ����闧���Ԃ�(�s��=0, ���ڍU�߂鑤=1, ���ڎ�鑤=2, �U�߂鑤�̉��R=3, ��鑤�̉��R=4, �����R=5)
	int Get_�����̎Q�헧��(int �����ԍ��y�z��p�z) {
		int iBushouID = �����ԍ��y�z��p�z;

		// �͈̓`�F�b�N
		if ( !(0 <= iBushouID && iBushouID < �ő吔::�������::�z��) ) {
			return �Q�헧��::�s��;
		}

		// �Y�������̌R�cID����
		int iGundanID = p�������[iBushouID].�����R�c�y�R�c�ԍ��z-1;
		if ( 0 <= iGundanID && iGundanID < �ő吔::�R�c���::�z�� ) {
			return Get_�R�c�̎Q�헧��(iGundanID);
		}

		return �Q�헧��::�s��;
	}

	// ���݂̐�ɂ����āA�w��R�c�̑叫(�R�c����喼�̂��Ƃł͂Ȃ��A���ɂ����Ă̌R�c��\��)
	int Get_�Q��R�c�̎w����(int �R�c�ԍ��y�z��p�z) {
		int iGundanID = �R�c�ԍ��y�z��p�z;
		if ( !(0 <= iGundanID && iGundanID < �ő吔::�R�c���::�z�� ) ) {
			return 0xFFFF;
		}

		if ( Is_��풆() || Is_�U��풆() ) {
			// �Q���喼�ԍ����������āA�U�����̃O���[�vID�A������̃O���[�vID���o���B
			for ( int ix=0; ix < GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_NUM; ix++ ) {

				int iJointGundanID = (int)nb6war_joint_daimyo_hex_group_info[ix].gundan-1;

				// �w��̌R�c���������B
				if ( iGundanID == iJointGundanID ) {
					// �����ԍ�(+1�̕�)�͈̔͂Ɏ��܂��Ă���B
					if ( 0 < nb6war_joint_daimyo_hex_group_info[ix].soudaisho && nb6war_joint_daimyo_hex_group_info[ix].soudaisho <= �ő吔::�������::�z�� ) {
						return nb6war_joint_daimyo_hex_group_info[ix].soudaisho-1;
					// �����ԍ��͈̔͂Ɏ��܂��Ă��Ȃ��Ƃ������Ƃ́A�喼��R�c�͌��܂��Ă��邪�A���叫�����܂��Ă��Ȃ��B���j�b�g�z�u�O���Ƒ��叫�����܂�Ȃ��̂ŁA���̂悤�Ȓl�ƂȂ�B
					} else {
						return 0xFFFF;
					}
				}
			}
		}

		return 0xFFFF;
	}

}



 // ���݉�ʂɏo�ĂčU�钆�̏�ԍ��B0xFFFF�Ȃ����U�钆�ł͂Ȃ��A��풆�B
int _���ݍU�钆�̏�ԍ� = 0xFFFF;


namespace �֐� {

	int Get_�푈�c��^�[����() {
		if ( p_GetRemainTurnInBattle ) {
			return p_GetRemainTurnInBattle();
		} else {
			return -1;
		}
	}

	int Get_�U���^�[����() {
		if ( p_GetCastleTurnInBattle ) {
			return p_GetCastleTurnInBattle();
		} else {
			return -1;
		}
	}

	WORD Get_�U��풆�̏�ԍ�() {
		if ( p_IsBattleMode && p_GetCurIncrementTurnInBattle ) {
			if ( p_IsBattleMode() && (p_GetCurIncrementTurnInBattle()>=0) ) {
				return _���ݍU�钆�̏�ԍ�;
			}
		}
		return 0xFFFF;
	}

	// ���݉�ʂɏo�Ă���́A���
	bool Is_��풆() {
		if ( p_IsBattleMode && p_GetCurIncrementTurnInBattle ) {
			return _���ݍU�钆�̏�ԍ� == 0xFFFF && p_IsBattleMode() && (p_GetCurIncrementTurnInBattle()>=0);
		} else {
			return _���ݍU�钆�̏�ԍ� == 0xFFFF;
		}			
	}

	// ���݉�ʂɏo�Ă���́A�U���
	bool Is_�U��풆() {
		if ( p_IsBattleMode && p_GetCurIncrementTurnInBattle ) {
			return ( 0 <= _���ݍU�钆�̏�ԍ�-1 && _���ݍU�钆�̏�ԍ�-1 < �ő吔::����::�z�� ) && p_IsBattleMode() && (p_GetCurIncrementTurnInBattle()>=0);
		} else {
			return ( 0 <= _���ݍU�钆�̏�ԍ�-1 && _���ݍU�钆�̏�ԍ�-1 < �ő吔::����::�z�� ); 
		}
	}
}


namespace �֐� {

	// ���ɂ����āA�Y���̕����ԍ��y�z��p�z�̕����́A���ɍs���ς݂ł���B
	// �s���ς݂Ȃ�TRUE���A���s���Ȃ�FALSE���Ԃ��Ă���B
	bool Is_�����s���ρs�푈��ʁt(int �����ԍ��y�z��p�z) {
		for ( int i=0; i < GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++ ) {
			if ( nb6bushou_hex_unit_info[i].bushou == �����ԍ��y�z��p�z+1 ) {
				if ( nb6bushou_hex_unit_info[i].bEnd == 0x2 ) { // �s���ςł���B
					return TRUE;
				} else {
					return FALSE;
				}
				break;
			}
		}
		return FALSE;
	}

	// ���ɂ����āA�Y���̕����ԍ��y�z��p�z�̕����͍������Ă���B
	int Get_�����������(int �����ԍ��y�z��p�z) {
		for ( int i=0; i < GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++ ) {
			if ( nb6bushou_hex_unit_info[i].bushou == �����ԍ��y�z��p�z+1 ) {
				return nb6bushou_hex_unit_info[i].konran; // �����E�����E�卬��
			}
		}
		return �������::����;
	}

	// ���ɂ����āA�Y���̕����ԍ��y�z��p�z�̕���������������B
	bool Set_�����������(int �����ԍ��y�z��p�z, int i�������) {
		for ( int i=0; i < GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++ ) {
			if ( nb6bushou_hex_unit_info[i].bushou == �����ԍ��y�z��p�z+1 ) {
				nb6bushou_hex_unit_info[i].konran = i�������; // �����E�����E�卬��
				if ( i������� > 0 ) {
					nb6bushou_hex_unit_info[i].bEnd = 0x2; // �s���ρB
				}
				�������j�b�g��ԕ`��X�V�s�푈��ʁt(�����ԍ��y�z��p�z);
				return TRUE;
			}
		}
		return FALSE;
	}

	int Set_�����ړ��͎c��(int �����ԍ��y�z��p�z, int �ړ��͎c��) {
		int iBushouID = �����ԍ��y�z��p�z;

		// �ړ��͂��኱��
		for ( int i=0; i < GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++ ) {
			if ( nb6bushou_hex_unit_info[i].bushou == iBushouID+1 ) {
				nb6bushou_hex_unit_info[i].movepower = �ړ��͎c��;  // �s���p���[�ݒ�
				break;
			}
		}
		return 0xFFFF;
	}

	int Get_�����ړ��͎c��(int �����ԍ��y�z��p�z) {

		int iBushouID = �����ԍ��y�z��p�z;

		// �ړ��͂��኱��
		for ( int i=0; i < GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++ ) {
			if ( nb6bushou_hex_unit_info[i].bushou == iBushouID+1 ) {
				return nb6bushou_hex_unit_info[i].movepower;
			}
		}
		return -1;
	}
}


/*
�퓬��ʁA���j�b�g�̍�����卬���ȂǁA�A�C�R����ԍX�V
/*
00430619  |. 56             PUSH    ESI                              ; /Arg1
0043061A  |. E8 EB9A0600    CALL    TENSHOU.0049A10A                 ; \TENSHOU.0049A10A
0043061F  |. 83C4 04        ADD     ESP, 4
*/
int pfuncAddress = 0x49A10A;
int pCallFromFuncBattleUnitStatusRepaint = 0x49A10A; //
int iBushouIDOfBattleUnitStatusRepaint = -1;

void FuncBattleUnitStatusRepaintAsm() {
	__asm {
		push iBushouIDOfBattleUnitStatusRepaint
		call pCallFromFuncBattleUnitStatusRepaint
		add esp, 4
	}
}

namespace �֐� {
	void �������j�b�g��ԕ`��X�V�s�푈��ʁt(int �����ԍ��y�z��p�z) {

		int iBushouID = �����ԍ��y�z��p�z;

		if ( !(0 <= iBushouID && iBushouID < �ő吔::�������::�z��) ) {
			return;
		}

		iBushouIDOfBattleUnitStatusRepaint = iBushouID+1;

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
		FuncBattleUnitStatusRepaintAsm();

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}
	}
}

/*
�퓬��ʁA���j�b�g�̕����`��B
*
/*
00433F8C  |. 56             PUSH    ESI
00433F8D  |. E8 FE6E0600    CALL    TENSHOU.0049AE90
00433F92  |. 83C4 04        ADD     ESP, 4
*/

int pCallFromFuncBattleUnitNumRepaint = 0x49AE90; //
int iBushouIDOfBattleUnitNumRepaint = -1;

void FuncBattleUnitNumRepaintAsm() {
	__asm {
		PUSH    iBushouIDOfBattleUnitNumRepaint
		CALL    pCallFromFuncBattleUnitNumRepaint
		ADD     ESP, 4
	}
}


namespace �֐� {
	// 
	void �������j�b�g�����`��X�V�s�푈��ʁt(int �����ԍ��y�z��p�z) {

		int iBushouID = �����ԍ��y�z��p�z;

		if ( !(0 <= iBushouID && iBushouID < �ő吔::�������::�z��) ) {
			return;
		}

		iBushouIDOfBattleUnitNumRepaint = iBushouID+1;

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
		FuncBattleUnitNumRepaintAsm();

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}
	}
}



namespace �֐� {
	// ������w�b�N�X�ꏊ�̃`�b�v�̖���(�U���w�b�N�X����)�𓾂�
	int Get_���w�b�N�X����(double x, double y) {
		// ���W�l�͑Ó��Ȕ͈͂��H
		if ( 0<=x && x<= GAMEDATASTRUCT_FIELD_HEX_COLS && 0<=y && y<=GAMEDATASTRUCT_FIELD_HEX_ROWS) {
			// y�����W���l�ɂ��āA������
			int _y = round�s�������t(y);
			// ���̋����s�ڂ���s�ڂ��ŁA���g���炷�B�����s�Ȃ�A"��HEX"�����l��x�ɓ����Ă��邽�߁B
			if (_y % 2==1) {
				x = x - 0.5;
			}
			// x���ł��߂��l�̐�����
			int _x = round�s�������t(x);
			// �O��菬�����Ȃ邱�Ƃ�����̂łO��
			if ( _x < 0 ) { _x = 0; }
			if ( _x >= GAMEDATASTRUCT_FIELD_HEX_COLS ) { _x = GAMEDATASTRUCT_FIELD_HEX_COLS-1; }
			if ( _y >= GAMEDATASTRUCT_FIELD_HEX_ROWS ) { _y = GAMEDATASTRUCT_FIELD_HEX_ROWS-1; }
			// �Y���̏ꏊ�ɂ���`�b�v�̖����ԍ�(�U���w�b�N�X����)��Ԃ�
			return nb6field_hex_role.pos_y[_y].pos_x[_x];
		} else {
			return -1;
		}
	}

	int Get_���w�b�N�X����(�w�b�N�X�ʒu�^ p) {
		return Get_���w�b�N�X����(p.�w, p.�x);
	}


	�w�b�N�X�ʒu���X�g�^ Get_����̖����̖��w�b�N�X�ʒu���X�g(int ���w�b�N�X����) {
		�w�b�N�X�ʒu���X�g�^ vec;
		for (int x = 0; x < GAMEDATASTRUCT_FIELD_HEX_COLS; x++) {
			for (int y = 0; y < GAMEDATASTRUCT_FIELD_HEX_ROWS; y++) {
				if (nb6field_hex_role.pos_y[y].pos_x[x] == ���w�b�N�X����) {

					�w�b�N�X�ʒu�^ pos;
					if (y % 2 == 1) {
						pos.�w = (double)x + 0.5;
						pos.�x  = y;
					}
					else {
						pos.�w = x;
						pos.�x = y;
					}

					vec.push_back(pos);
				}
			}
		}

		return vec;
	}


	// �����w�b�N�X�ꏊ�̃`�b�v�̖���(���w�b�N�X����)�𓾂�
	int Get_�U���w�b�N�X����(double x, double y) {
		// ���W�l�͑Ó��Ȕ͈͂��H
		if ( 0<=x && x< GAMEDATASTRUCT_CASTLE_HEX_COLS && 0<=y && y< GAMEDATASTRUCT_CASTLE_HEX_ROWS) {
			// y�����W���l�ɂ��āA������
			int _y = round�s�������t(y);
			// ���̋����s�ڂ���s�ڂ��ŁA���g���炷�B�����s�Ȃ�A"��HEX"�����l��x�ɓ����Ă��邽�߁B
			if (_y % 2==1) {
				x = x - 0.5;
			}
			// x���ł��߂��l�̐�����
			int _x = round�s�������t(x);
			// �O��菬�����Ȃ邱�Ƃ�����̂łO��
			if ( _x < 0 ) { _x = 0; }
			if ( _x >= GAMEDATASTRUCT_CASTLE_HEX_COLS ) { _x = GAMEDATASTRUCT_CASTLE_HEX_COLS-1; }
			if ( _y >= GAMEDATASTRUCT_CASTLE_HEX_ROWS ) { _y = GAMEDATASTRUCT_CASTLE_HEX_ROWS-1; }
			// �Y���̏ꏊ�ɂ���`�b�v�̖����ԍ�(���w�b�N�X����)��Ԃ�
			return nb6castle_hex_role.pos_y[_y].pos_x[_x];
		} else {
			return -1;
		}
	}

	int Get_�U���w�b�N�X����(�w�b�N�X�ʒu�^ p) {
		return Get_�U���w�b�N�X����(p.�w, p.�x);
	}

	�w�b�N�X�ʒu���X�g�^ Get_����̖����̍U���w�b�N�X�ʒu���X�g(int �U���w�b�N�X����) {
		�w�b�N�X�ʒu���X�g�^ vec;
		for (int x = 0; x < GAMEDATASTRUCT_CASTLE_HEX_COLS; x++) {
			for (int y = 0; y < GAMEDATASTRUCT_CASTLE_HEX_ROWS; y++) {
				if (nb6castle_hex_role.pos_y[y].pos_x[x] == �U���w�b�N�X����) {

					�w�b�N�X�ʒu�^ pos;
					if (y % 2 == 1) {
						pos.�w = (double)x + 0.5;
						pos.�x = y;
					}
					else {
						pos.�w = x;
						pos.�x = y;
					}

					vec.push_back(pos);
				}
			}
		}

		return vec;
	}

	// �����w�b�N�X�ꏊ�̃`�b�v�̍����𓾂�
	int Get_�U���w�b�N�X����(double x, double y) {
		// ���W�l�͑Ó��Ȕ͈͂��H
		if ( 0<=x && x< GAMEDATASTRUCT_CASTLE_HEX_COLS && 0<=y && y< GAMEDATASTRUCT_CASTLE_HEX_ROWS) {
			// y�����W���l�ɂ��āA������
			int _y = round�s�������t(y);
			// ���̋����s�ڂ���s�ڂ��ŁA���g���炷�B�����s�Ȃ�A"��HEX"�����l��x�ɓ����Ă��邽�߁B
			if (_y % 2==1) {
				x = x - 0.5;
			}
			// x���ł��߂��l�̐�����
			int _x = round�s�������t(x);
			// �O��菬�����Ȃ邱�Ƃ�����̂łO��
			if ( _x < 0 ) { _x = 0; }
			if ( _x >= GAMEDATASTRUCT_CASTLE_HEX_COLS ) { _x = GAMEDATASTRUCT_CASTLE_HEX_COLS-1; }
			if ( _y >= GAMEDATASTRUCT_CASTLE_HEX_ROWS ) { _y = GAMEDATASTRUCT_CASTLE_HEX_ROWS-1; }
			// �Y���̏ꏊ�ɂ���`�b�v�̖����ԍ�(���w�b�N�X����)��Ԃ�
			return nb6castle_hex_high.pos_y[_y].pos_x[_x];
		} else {
			return -1;
		}
	}

	int Get_�U���w�b�N�X����(�w�b�N�X�ʒu�^ p) {
		return Get_�U���w�b�N�X����(p.�w, p.�x);
	}


	// ����w�b�N�X�ꏊ�̃`�b�v�̉��̖���(CASTLE_HEX_ROLE)�𓾂�
	// �����t���Ă��鏊�́A�E�̂P�o�C�g��1�ɂȂ�B
	int Get_�U���w�b�N�X����(double x, double y) {
		// ���W�l�͑Ó��Ȕ͈͂��H
		if ( 0<=x && x< GAMEDATASTRUCT_CASTLE_HEX_COLS && 0<=y && y< GAMEDATASTRUCT_CASTLE_HEX_ROWS) {
			// y�����W���l�ɂ��āA������
			int _y = round�s�������t(y);
			// ���̋����s�ڂ���s�ڂ��ŁA���g���炷�B�����s�Ȃ�A"��HEX"�����l��x�ɓ����Ă��邽�߁B
			if (_y % 2==1) {
				x = x - 0.5;
			}
			// x���ł��߂��l�̐�����
			int _x = round�s�������t(x);
			// �O��菬�����Ȃ邱�Ƃ�����̂łO��
			if ( _x < 0 ) { _x = 0; }
			if ( _x >= GAMEDATASTRUCT_CASTLE_HEX_COLS ) { _x = GAMEDATASTRUCT_CASTLE_HEX_COLS-1; }
			if ( _y >= GAMEDATASTRUCT_CASTLE_HEX_ROWS ) { _y = GAMEDATASTRUCT_CASTLE_HEX_ROWS-1; }
			// �Y���̏ꏊ�ɂ���`�b�v�̖����ԍ�(���w�b�N�X����)��Ԃ�
			return (nb6fire_hex_role.pos_y[_y].pos_x[_x] & 0xF) == 1;
		} else {
			return -1;
		}
	}


	int Get_�U���w�b�N�X����(�w�b�N�X�ʒu�^ p) {
		return Get_�U���w�b�N�X����(p.�w, p.�x);
	}

	�w�b�N�X�ʒu���X�g�^ Get_����̍U���w�b�N�X�ʒu���X�g(int �U���w�b�N�X����) {
		�w�b�N�X�ʒu���X�g�^ vec;
		for (int x = 0; x < GAMEDATASTRUCT_CASTLE_HEX_COLS; x++) {
			for (int y = 0; y < GAMEDATASTRUCT_CASTLE_HEX_ROWS; y++) {
				if ((nb6fire_hex_role.pos_y[y].pos_x[x] & 0xF) == �U���w�b�N�X����) {

					�w�b�N�X�ʒu�^ pos;
					if (y % 2 == 1) {
						pos.�w = (double)x + 0.5;
						pos.�x = y;
					}
					else {
						pos.�w = x;
						pos.�x = y;
					}

					vec.push_back(pos);
				}
			}
		}

		return vec;
	}

	// �w�b�N�X�Ԋu�̎擾�Bp1��p2�܂ŉ��e�ړ�����K�v������̂�(�S�Ă̞e�͍s������̂Ɖ��肷��)
	int Get_�w�b�N�X�Ԋu( �w�b�N�X�ʒu�^ p1, �w�b�N�X�ʒu�^ p2 ) {
		double ax = double(abs(p1.�w-p2.�w));
		double ay = double(abs(p1.�x-p2.�x));
		if ( p1.�x == p2.�x ) { // �����s�ɋ���Ȃ�΁c
			return round�s�������t(ax);
		} else if ( ax*2 <= ay ) { // 2�_�Ԃ�X���W�̍���2�_�Ԃ�Y���W�̍��̔����ȉ��̏ꍇ�AY���W�̈ړ������ŊY���|�C���g�܂œ��B�ł���B
			return round�s�������t(ay);
		} else {
			// X�̍� + Y�̍� - Y�̍��̔���
			return round�s�������t( ax + ay - 0.5*ay );
		}
	}

	�ԍ����X�g�^ Get_�o�w���̕����ԍ����X�g�y�z��p�z() {
		vector<int> bArray;

		// ���ɂ��镐����������𖞂������̂̈ړ��c�ʂ𑝂₷�B
		for ( int i=0; i<GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++ ) {
			if ( nb6bushou_hex_unit_info[i].bushou == 0xFFFF ) { continue; } // 0xFFFF���Ƃ��̃X���b�g�ɕ����͋��Ȃ��B���̐l
			if ( nb6bushou_hex_unit_info[i].bushou > �ő吔::�������::�z�� ) { continue; } // �����Ŕ͈͕ۏႵ�Ă����Ă�����B���̐l
			
			int iBushouID = nb6bushou_hex_unit_info[i].bushou - 1;

			if ( 0 <= iBushouID && iBushouID < �ő吔::�������::�z�� ) {
				if ( p�����ːЏ��[iBushouID].�펀 == 0 && p�����ːЏ��[iBushouID].�ދp == 0 ) {
					bArray.push_back( iBushouID );
				}
			}
		}

		return bArray;
	}


	�ԍ����X�g�^ Get_�o�w���̕����ԍ����X�g�y�z��p�z�s�\�����}�b�v�t() {

		vector<int> bArray;

		if ( Is_�U��풆() ) {
			for ( int i=0; i<GAMEDATASTRUCT_CASTLE_HEX_COLS * GAMEDATASTRUCT_CASTLE_HEX_ROWS; i++ ) {
				int iBango = nb6castle_hex_unit_pos.index[i];
				if ( 1 <= iBango && iBango <= GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM ) {
					if ( nb6bushou_hex_unit_info[iBango-1].bushou != 0xFFFF ) {
						int iBushouID = nb6bushou_hex_unit_info[iBango-1].bushou-1;
						if ( 0 <= iBushouID && iBushouID < �ő吔::�������::�z�� ) {
							if ( p�����ːЏ��[iBushouID].�펀 == 0 && p�����ːЏ��[iBushouID].�ދp == 0 ) {
								bArray.push_back( iBushouID );
							}
						}
					}
				}
			}
		}
		if ( Is_��풆() ) {
			for ( int i=0; i<GAMEDATASTRUCT_FIELD_HEX_COLS * GAMEDATASTRUCT_FIELD_HEX_ROWS; i++ ) {
				int iBango = nb6field_hex_unit_pos.index[i];
				if ( 1 <= iBango && iBango <= GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM ) {
					if ( nb6bushou_hex_unit_info[iBango-1].bushou != 0xFFFF ) {
						int iBushouID = nb6bushou_hex_unit_info[iBango-1].bushou-1;
						if ( 0 <= iBushouID && iBushouID < �ő吔::�������::�z�� ) {
							if ( p�����ːЏ��[iBushouID].�펀 == 0 && p�����ːЏ��[iBushouID].�ދp == 0 ) {
								bArray.push_back( iBushouID );
							}
						}
					}
				}
			}
		}
		return bArray;
	}

	// �w��̕����h�c�̕������ǂ��ɂ���̂��H ���Ȃ��ꍇ�Ap(x=0xFFFF, y=0xFFFF) ���Ԃ��Ă���B
	�w�b�N�X�ʒu�^ Get_�����̖��w�b�N�X�ʒu(int �����ԍ��y�z��p�z) {

		�w�b�N�X�ʒu�^ pos( 0xFFFF, 0xFFFF );

		if ( !(0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z��) ) {
			return pos;
		}
		if ( !Is_��풆() ) {
			return pos;
		}

		// ���ɂ��镐����������𖞂������̂̈ړ��c�ʂ𑝂₷�B
		for ( int i=0; i<GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++ ) {
			if ( nb6bushou_hex_unit_info[i].bushou == 0xFFFF ) { continue; } // 0xFFFF���Ƃ��̃X���b�g�ɕ����͋��Ȃ��B���̐l
			if ( nb6bushou_hex_unit_info[i].bushou > �ő吔::�������::�z�� ) { continue; } // �����Ŕ͈͕ۏႵ�Ă����Ă�����B���̐l

			// �T���Ă镐�����A�\�����̖��ɋ���!!
			if ( �����ԍ��y�z��p�z == nb6bushou_hex_unit_info[i].bushou - 1 ) {
				int x = nb6bushou_hex_unit_info[i].pos_x;
				int y = nb6bushou_hex_unit_info[i].pos_y;

				if ( x==0xFFFF ) {
					return pos;
				}

				// y�����W���l�ɂ��āA������
				pos.�x = y;

				// ���̋����s�ڂ���s�ڂ��ŁA���g���炷�B�����s�Ȃ�A"���W��0.5���E�ɂ��炷�B
				if (y % 2==1) {
					pos.�w = x + 0.5;
				} else {
					pos.�w = x;
				}

				return pos;
			}
		}

		return pos;
	}



	// �w��̕����h�c�̕������ǂ��ɂ���̂��H ���Ȃ��ꍇ�Ap(x=0xFFFF, y=0xFFFF) ���Ԃ��Ă���B
	�w�b�N�X�ʒu�^ Get_�����̍U���w�b�N�X�ʒu(int �����ԍ��y�z��p�z) {
		�w�b�N�X�ʒu�^ pos( 0xFFFF, 0xFFFF );

		if ( !(0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z��) ) {
			return pos;
		}
		if ( !Is_�U��풆() ) {
			return pos;
		}

		// ���ɂ��镐����������𖞂������̂̈ړ��c�ʂ𑝂₷�B
		for ( int i=0; i<GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++ ) {
			if ( nb6bushou_hex_unit_info[i].bushou == 0xFFFF ) { continue; } // 0xFFFF���Ƃ��̃X���b�g�ɕ����͋��Ȃ��B���̐l
			if ( nb6bushou_hex_unit_info[i].bushou > �ő吔::�������::�z�� ) { continue; } // �����Ŕ͈͕ۏႵ�Ă����Ă�����B���̐l

			// �T���Ă镐�����A�\�����̍U��퓬�ɋ���!!
			if ( �����ԍ��y�z��p�z == nb6bushou_hex_unit_info[i].bushou - 1 ) {
				int x = nb6bushou_hex_unit_info[i].pos_x;
				int y = nb6bushou_hex_unit_info[i].pos_y;

				if ( x==0xFFFF ) {
					return pos;
				}

				// y�����W���l�ɂ��āA������
				pos.�x = y;

				// ���̋����s�ڂ���s�ڂ��ŁA���g���炷�B�����s�Ȃ�A"���W��0.5���E�ɂ��炷�B
				if (y % 2==1) {
					pos.�w = x + 0.5;
				} else {
					pos.�w = x;
				}

				return pos;
			}
		}

		return pos;
	}


	// �t�B�[���h�w�b�N�X�̍��W�����ʂ̂R�������W(����f�J���g�E���Ɠ�����)
	�R�c�ʒu�^ ���w�b�N�X�ʒu���R�c�ʒu(�w�b�N�X�ʒu�^ p) {
		�R�c�ʒu�^ p_real;
		p_real.�w = p.�w - ���w�b�N�X::���S�w;
		p_real.�y = (p.�x - ���w�b�N�X::���S�x) * ( sqrt(3.0f) / 2.0f ) * -1; // sin60��
		if ( p_real.�y == 0 ) { p_real.�y = 0; } // �A�z�݂��������A"-0"�ƂȂ�Ȃ��悤�ɂ���B

		// y�̍��������߂�ɂ������āA��R�Ȃ�1, ���R�Ȃ�2, ���R�Ȃ�3�Ƃ���B
		int iHexRole = Get_���w�b�N�X����( p.�w, p.�x );

		if ( iHexRole == ���w�b�N�X����::���R ) {
			p_real.�x = 3;
		} else if ( iHexRole == ���w�b�N�X����::���R ) {
			p_real.�x = 2;
		} else if ( iHexRole == ���w�b�N�X����::��R ) {
			p_real.�x = 1;
		} else {
			p_real.�x = 0;
		}
		return p_real;
	}

	// ���ʂ̂R�������W(����f�J���g)���t�B�[���h�w�b�N�X�̍��W��
	�w�b�N�X�ʒu�^ �R�c�ʒu�����w�b�N�X�ʒu(�R�c�ʒu�^ p) {
		�w�b�N�X�ʒu�^ p_hex;
		p_hex.�w = round�s�������t(p.�w + ���w�b�N�X::���S�w);
		p_hex.�x = round�s�񕪂̈�z�����t((2.0f / sqrt(3.0f) ) * (p.�y) * -1 + ���w�b�N�X::���S�x);
		return p_hex;
	}

	// ��w�b�N�X�̍��W�����ʂ̂R�������W(����f�J���g�E���Ɠ�����)
	�R�c�ʒu�^ �U���w�b�N�X�ʒu���R�c�ʒu(�w�b�N�X�ʒu�^ p) {
		�R�c�ʒu�^ p_real;
		p_real.�w = p.�w - ���w�b�N�X::���S�w;
		p_real.�y = (p.�x - ���w�b�N�X::���S�x) * ( sqrt(3.0f) / 2.0f ) * -1; // sin60��
		if ( p_real.�y == 0 ) { p_real.�y = 0; } // �A�z�݂��������A"-0"�ƂȂ�Ȃ��悤�ɂ���B

		// y�̍��������߂�ɂ������ď�̍������𓖂Ă͂߂�B
		int iHexHigh = Get_�U���w�b�N�X����( p.�w, p.�x );
		p_real.�x = iHexHigh;
		return p_real;
	}

	// ���ʂ̂R�������W(����f�J���g)����w�b�N�X�̍��W��
	�w�b�N�X�ʒu�^ �R�c�ʒu���U���w�b�N�X�ʒu(�R�c�ʒu�^ p) {
		�w�b�N�X�ʒu�^ p_hex;
		p_hex.�w = round�s�������t(p.�w + ���w�b�N�X::���S�w);
		p_hex.�x = round�s�񕪂̈�z�����t((2.0f / sqrt(3.0f) ) * (p.�y) * -1 + ���w�b�N�X::���S�x);
		return p_hex;
	}

	// �Q�_�ԍ��W�̍�
	�w�b�N�X�x�N�g���^ operator-(�w�b�N�X�ʒu�^ &p1, �w�b�N�X�ʒu�^ &p2) {
		�w�b�N�X�x�N�g���^ v;
		v.�w = p1.�w - p2.�w;
		v.�x = p1.�x - p2.�x;
		return v;
	}

}