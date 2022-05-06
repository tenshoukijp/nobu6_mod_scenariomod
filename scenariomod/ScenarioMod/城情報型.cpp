#include <cassert>
#include "�Q�[���f�[�^�\��.h"
#include "�_�C�N�X�g���q��r.h"


namespace �֐� {



// �閼���擾����
string Get_�閼( int ��ԍ��y�z��p�z) {

	// �͈̓`�F�b�N
	if ( 0 <= ��ԍ��y�z��p�z && ��ԍ��y�z��p�z < �ő吔::����::�z�� ) { 

		return string( p����[��ԍ��y�z��p�z]._�閼 );
	} else {
		�f�o�b�O�o��("��ԍ��y�z��p�z�͔͈͊O");
		return string("");
	}
}


// �閼��ݒ肷��
void   Set_�閼( int ��ԍ��y�z��p�z, string �閼 ) {

	// �͈̓`�F�b�N
	if ( 0 <= ��ԍ��y�z��p�z && ��ԍ��y�z��p�z < �ő吔::����::�z�� ) { 

		strncpy_s( p����[��ԍ��y�z��p�z]._�閼, �閼.c_str(), 8 );
		p����[��ԍ��y�z��p�z]._�閼[8] = NULL;
		p����[��ԍ��y�z��p�z]._�閼�ύX�� = true;
	} else {
		�f�o�b�O�o��("��ԍ��y�z��p�z�͔͈͊O");
	}
}

}

// ����ɕ���������߂��������ɁATENSHOU.EXE���̃|�C���^�z�񂩂��������悤�ɂ��������A���҂̉����ւ̑ϋv�͂����������B
char nb6CastleTypeName[�ő吔::����::�z��][5] = {
	"��",
	"��V",
	"��",
	"�䏊",
	"��",
	"", // ��
	"��"
};

// ��̃^�C�vID�����̓I�ȕ�����𓾂�
char *getCastleTypeName(int iCastleType) {
	if ( iCastleType == 0x00 ) {
		return nb6CastleTypeName[0];
	}
	else if (iCastleType == 0x01 ) {
		return nb6CastleTypeName[1];
	}
	else if (iCastleType == 0x02 ) {
		return nb6CastleTypeName[2];
	}
	else if (iCastleType == 0x04 ) {
		return nb6CastleTypeName[3];
	}
	else if (iCastleType == 0x08 ) {
		return nb6CastleTypeName[4];
	}
	else if (iCastleType == 0x10 ) {
		return nb6CastleTypeName[5];
	}
	else if (iCastleType == 0x20 ) {
		return nb6CastleTypeName[6];
	}
	return "";
}


namespace �֐� {

string Get_���(int ��ԍ��y�z��p�z) {
	if ( 0 <= ��ԍ��y�z��p�z && ��ԍ��y�z��p�z < �ő吔::����::�z�� ) {
		string ��� = getCastleTypeName( p����[��ԍ��y�z��p�z]._���);
		return ���;
	}
	else {
		�f�o�b�O�o��("��ԍ��y�z��p�z�͔͈͊O");
	}
	return "";
}

void Set_���(int ��ԍ��y�z��p�z, string ���) {
	int iCastleType = 0x10; // �����t���Ȃ�

	if (��� == "��") {
		iCastleType = 0x20;
	}
	else if (��� == "��V") {
		iCastleType = 0x01;
	}
	else if (��� == "��") {
		iCastleType = 0x02;
	}
	else if (��� == "�䏊") {
		iCastleType = 0x04;
	}
	else if (��� == "��") {
		iCastleType = 0x08;
	}
	else if (��� == "" || ��� == "��") {
		iCastleType = 0x10;
	}

	p����[��ԍ��y�z��p�z]._��� = iCastleType;
	p����[��ԍ��y�z��p�z]._�閼�ύX�� = true;
}

/* 
 * �����̐������畐���ԍ����擾����B���݂��Ȃ��ꍇ�́A�0xFFFF����Ԃ��Ă���B
 */
int Get_��ԍ��y�z��p�z(string �閼) {

	for (int ��ԍ��y�z��p�z=0; ��ԍ��y�z��p�z < �ő吔::����::�z��; ��ԍ��y�z��p�z++ ) {
		if ( �閼 == Get_�閼(��ԍ��y�z��p�z) || �閼 == Get_�閼(��ԍ��y�z��p�z)+Get_���(��ԍ��y�z��p�z) ) {
			return ��ԍ��y�z��p�z;
		}
	}

	return 0xFFFF;
}

// �w��̌R�c���������Ă����̐��B
int Get_�R�c�����鐔(int �R�c�ԍ��y�z��p�z) {
	int iGundanID = �R�c�ԍ��y�z��p�z;

	int iHasCastleCnt = 0;
	if ( 0 <= iGundanID && iGundanID < �ő吔::�R�c���::�z�� ) {
		for ( int iCastleID=0; iCastleID < �ő吔::����::�z��; iCastleID++ ) {
			// �R�c�ԍ�����v������̂��J�E���g
			if ( iGundanID == p����[iCastleID].�����R�c�y�R�c�ԍ��z-1 ) {
				iHasCastleCnt++;
			}
		}
	} else {
		�f�o�b�O�o��("�R�c�ԍ��y�z��p�z�͔͈͊O");
	}
	return iHasCastleCnt;
}

// �w��̑喼���������Ă����̐��B
int Get_�喼�����鐔(int �喼�ԍ��y�z��p�z) {
	int iDaimyoID = �喼�ԍ��y�z��p�z;
	int iHasCastleCnt = 0;
	
	if ( 0 <= iDaimyoID && iDaimyoID < �ő吔::�喼���::�z�� ) {
		for ( int iCastleID=0; iCastleID < �ő吔::����::�z��; iCastleID++ ) {
			int iGundanID = p����[iCastleID].�����R�c�y�R�c�ԍ��z-1;

			if ( 0 <= iGundanID && iGundanID < �ő吔::�R�c���::�z�� ) {
				// �喼�ԍ�����v������̂��J�E���g
				if ( iDaimyoID == p�R�c���[iGundanID].�����喼�y�喼�ԍ��z-1 ) {
					iHasCastleCnt++;
				}
			}
		}
	} else {
		�f�o�b�O�o��("�喼�ԍ��y�z��p�z�͔͈͊O");
	}
	return iHasCastleCnt;
}


// �w��̌R�c���������Ă����̔ԍ����X�g
�ԍ����X�g�^ Get_�R�c������ԍ����X�g�y�z��p�z(int �R�c�ԍ��y�z��p�z) {
	int iGundanID = �R�c�ԍ��y�z��p�z;

	�ԍ����X�g�^ r;

	if (0 <= iGundanID && iGundanID < �ő吔::�R�c���::�z��) {
		for (int iCastleID = 0; iCastleID < �ő吔::����::�z��; iCastleID++) {

			// �R�c�ԍ�����v������̂�����
			if (iGundanID == p����[iCastleID].�����R�c�y�R�c�ԍ��z - 1) {
				r.push_back(iCastleID);
			}
		}
	}
	else {
		�f�o�b�O�o��("�R�c�ԍ��y�z��p�z�͔͈͊O");
	}
	return r;
}

// �w��̑喼���������Ă����̔ԍ����X�g
�ԍ����X�g�^ Get_�喼������ԍ����X�g�y�z��p�z(int �喼�ԍ��y�z��p�z) {
	int iDaimyoID = �喼�ԍ��y�z��p�z;
	
	�ԍ����X�g�^ r;

	if (0 <= iDaimyoID && iDaimyoID < �ő吔::�喼���::�z��) {
		for (int iCastleID = 0; iCastleID < �ő吔::����::�z��; iCastleID++) {
			int iGundanID = p����[iCastleID].�����R�c�y�R�c�ԍ��z - 1;

			if (0 <= iGundanID && iGundanID < �ő吔::�R�c���::�z��) {
				// �喼�ԍ�����v������̂��J�E���g
				if (iDaimyoID == p�R�c���[iGundanID].�����喼�y�喼�ԍ��z - 1) {
					r.push_back(iCastleID);
				}
			}
		}
	}
	else {
		�f�o�b�O�o��("�喼�ԍ��y�z��p�z�͔͈͊O");
	}
	return r;

}


// ����ړ�����B
void Set_��ʒu(int ��ԍ��y�z��p�z, int �w�ʒu, int �x�ʒu) {
	// �͈̓`�F�b�N
	if ( 0 <= ��ԍ��y�z��p�z && ��ԍ��y�z��p�z < �ő吔::����::�z�� ) { 

		p��t�����[��ԍ��y�z��p�z].�w�ʒu = �w�ʒu;
		p��t�����[��ԍ��y�z��p�z].�x�ʒu = �x�ʒu;
	} else {
		�f�o�b�O�o��("��ԍ��y�z��p�z�͔͈͊O");
	}
}


}


// �ȉ��A���C���}�b�v�̃O���b�h���ŋ�؂�ꂽ��O���b�h�̈ʒu�̌v�Z

// �O���b�h���W���u�̌��Z�B���W�`�����W�a�̃x�N�g�������߂�̂ɁA�ʏ�A�a�|�`�����邾�낤����B
��O���b�h�x�N�g���^ operator-(��O���b�h�ʒu�^ &p1, ��O���b�h�ʒu�^ &p2);


// �O���b�h�|�W�V�����N���X
��O���b�h�ʒu�^::��O���b�h�ʒu�^(int _�w, int _�x) {
	�w = _�w,
	�x = _�x;

	�k���y��ԍ��z= 0xFFFF;
	�k�y��ԍ��z  = 0xFFFF;
	�k���y��ԍ��z= 0xFFFF;
	���y��ԍ��z  = 0xFFFF;
	���y��ԍ��z  = 0xFFFF;
	�쐼�y��ԍ��z= 0xFFFF;
	��y��ԍ��z  = 0xFFFF;
	�쓌�y��ԍ��z= 0xFFFF;
}

namespace �֐� {

// �O���b�h���W���u�̌��Z�B���W�`�����W�a�̃x�N�g�������߂�̂ɁA�ʏ�A�a�|�`�����邾�낤����B
��O���b�h�x�N�g���^ operator-(��O���b�h�ʒu�^ &�ʒu�P, ��O���b�h�ʒu�^ &�ʒu�Q) {
	��O���b�h�x�N�g���^ �u;
	�u.�w = �ʒu�P.�w - �ʒu�Q.�w;
	�u.�x = �ʒu�P.�x - �ʒu�Q.�x;
	return �u;
}


// ��h�c����A���C���O���b�h��̃|�W�V�����𓾂�B����O���b�h��0,0�Bmapdataobgk�̃O���b�h������΂킩��₷���B
// �P�̃O���b�h�ɂ́A�P�̏邵���Ȃ��B
��O���b�h�ʒu�^ Get_��O���b�h�ʒu(int ��ԍ��y�z��p�z) {
	��O���b�h�ʒu�^ �ʒu(0, 0);

	if ( 0 <= ��ԍ��y�z��p�z && ��ԍ��y�z��p�z < �ő吔::����::�z�� ) {
		// �܂��́A�Ώۈʒu�̃O���b�h�ʒu�����߂�B
		int iGridX = (p��t�����[��ԍ��y�z��p�z].�w�ʒu + 1) / 5; // �O�I���W���Ȃ̂Ł{�P���ĂT�Ŋ���B�w�����͂P�̃O���b�h�̒��ɂT�̏ꏊ������B
		int iGridY = (p��t�����[��ԍ��y�z��p�z].�x�ʒu + 1) / 3; // �O�I���W���Ȃ̂Ł{�P���ĂR�Ŋ���B�x�����͂P�̃O���b�h�̒��ɂR�̏ꏊ������B

		�ʒu.�w = iGridX;
		�ʒu.�x = iGridY;

		// �אڂ����̂h�c������Ă����B
		for (int iCastleID = 0; iCastleID < �ő吔::����::�z��; iCastleID++) {
			int iFX = (p��t�����[iCastleID].�w�ʒu + 1) / 5; // �O�I���W���Ȃ̂Ł{�P���ĂT�Ŋ���B�w�����͂P�̃O���b�h�̒��ɂT�̏ꏊ������B
			int iFY = (p��t�����[iCastleID].�x�ʒu + 1) / 3; // �O�I���W���Ȃ̂Ł{�P���ĂR�Ŋ���B�x�����͂P�̃O���b�h�̒��ɂR�̏ꏊ������B

			if ( iFX - �ʒu.�w == -1 && iFY - �ʒu.�x == -1 ) { // �k��
				�ʒu.�k���y��ԍ��z = iCastleID + 1;
			} else if ( iFX - �ʒu.�w == 0 && iFY - �ʒu.�x == -1 ) { // �k
				�ʒu.�k�y��ԍ��z = iCastleID + 1;
			} else if ( iFX - �ʒu.�w == 1 && iFY - �ʒu.�x == -1 ) { // �k��
				�ʒu.�k���y��ԍ��z = iCastleID + 1;
			} else if ( iFX - �ʒu.�w == -1 && iFY - �ʒu.�x == 0 ) { // ��
				�ʒu.���y��ԍ��z = iCastleID + 1;
			} else if ( iFX - �ʒu.�w == 1 && iFY - �ʒu.�x == 0 ) { // ��
				�ʒu.���y��ԍ��z = iCastleID + 1;
			} else if ( iFX - �ʒu.�w == -1 && iFY - �ʒu.�x == 1 ) { // �쐼
				�ʒu.�쐼�y��ԍ��z = iCastleID + 1;
			} else if ( iFX - �ʒu.�w == 0 && iFY - �ʒu.�x == 1 ) { // ��
				�ʒu.��y��ԍ��z = iCastleID + 1;
			} else if ( iFX - �ʒu.�w == 1 && iFY - �ʒu.�x == 1 ) { // �쓌
				�ʒu.�쓌�y��ԍ��z = iCastleID + 1;
			}
		}

		return �ʒu;
	}
	return �ʒu;
}

// �Q�̏�̃O���b�h�ʒu���A�אڈʒu���ǂ����B
bool Is_�אڏ�( ��O���b�h�ʒu�^ &�ʒu�P, ��O���b�h�ʒu�^ &�ʒu�Q) {
	��O���b�h�x�N�g���^ v;
	v.�w = �ʒu�P.�w - �ʒu�Q.�w;
	v.�x = �ʒu�P.�x - �ʒu�Q.�x;
	if ( v.�w == 0 && v.�x == 0 ) { return false; } // ������
	return ( abs( v.�w ) <= 1 && abs( v.�x) <= 1);
}

bool Is_�אڏ�( int ��`�ԍ��y�z��p�z, int ��a�ԍ��y�z��p�z) {
	if ( (0 <= ��`�ԍ��y�z��p�z&& ��`�ԍ��y�z��p�z< �ő吔::����::�z�� ) &&
		 (0 <= ��a�ԍ��y�z��p�z&& ��a�ԍ��y�z��p�z< �ő吔::����::�z�� ) ) {
		��O���b�h�ʒu�^ posA = Get_��O���b�h�ʒu( ��`�ԍ��y�z��p�z);
		��O���b�h�ʒu�^ posB = Get_��O���b�h�ʒu( ��a�ԍ��y�z��p�z);
		return Is_�אڏ�( posA, posB );
	}
	return false;
}



// �w��̏邩�瓹���q�����Ă���אڏ�̃��X�g�𓾂�B
�ԍ����X�g�^ Get_�o�H�A���̗אڏ�ԍ����X�g�y�z��p�z(int ��ԍ��y�z��p�z) {
	int iCastleID = ��ԍ��y�z��p�z;
	�ԍ����X�g�^ connect_castle_list;

	// �G�b�W�̃X�^�[�g�n�_�������́A�S�[���n�_�Ɏ��g��iCastleID������B
	for ( int iEdgeID=0; iEdgeID<N6PCASTLE_EDGE_NUM; iEdgeID++ ) {
		// ��ԍ���e1�ƈ�v������Ae2���A����
		if ( iCastleID == nb6castle_edges[iEdgeID].e1 ) {
			connect_castle_list.push_back( nb6castle_edges[iEdgeID].e2 );
		}
		// �t��e2�ƈ�v������Ae1���A����
		else if ( iCastleID == nb6castle_edges[iEdgeID].e2 ) {
			connect_castle_list.push_back( nb6castle_edges[iEdgeID].e1 );
		}
	}

	return connect_castle_list;
}



// �ŏ��̃m�[�h��G�b�W�̏������B�Q�[���N�����̃��C����ʊJ�n�̂Q��s����B
void Set_��o�H�O���t������() {
	
	InitCastleNodeAndEdge();
}

void Set_��o�H�O���t�����폜(int i��ԍ��y�z��p�z) {

	RemoveCastleNode( i��ԍ��y�z��p�z);
}


�ԍ����X�g�^ Get_�o�H��̏�ԍ����X�g�y�z��p�z(int i�J�n��ԍ��y�z��p�z, int i�ړI��ԍ��y�z��p�z) {
	�ԍ����X�g�^ �󃊃X�g; // �G���[�p

	if (! (0 <= i�J�n��ԍ��y�z��p�z && i�J�n��ԍ��y�z��p�z < �ő吔::����::�z��) ) {
		return �󃊃X�g;
	}
	if (! (0 <= i�ړI��ԍ��y�z��p�z && i�ړI��ԍ��y�z��p�z < �ő吔::����::�z��) ) {
		return �󃊃X�g;
	}

	// �X�^�[�g�m�[�h�̐ݒ�
	SetStartCastleNode(i�J�n��ԍ��y�z��p�z);

	// �S�[���m�[�h�̐ݒ�
	SetGoalCastleNode(i�ړI��ԍ��y�z��p�z);

	// �X�^�[�g���S�[���ւ̃��[�g���v�Z���A�o�H�ƂȂ�����ID�̃��X�g��Ԃ��B
	return SearchCastleWayRoot();
}





}


