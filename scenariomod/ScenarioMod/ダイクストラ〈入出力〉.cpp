
#include "�Q�[���f�[�^�\��.h"
#include "�_�C�N�X�g��.h"
#include "�_�C�N�X�g���q��r.h"



//�t�@�C���ǂݍ���
bool Dijkstra::Inport()
{
	Clear();

	// �G�b�W�̃X�^�[�g�n�_�������́A�S�[���n�_�Ɏ��g��iCastleID������B
	for ( int iCastleID=0; iCastleID<�ő吔::����::�z��; iCastleID++ ) {
		// ��̍��W�����̂܂܃m�[�h�̍��W�Ƃ��Ċi�[�B
		AddNode( iCastleID, p��t�����[iCastleID].�w�ʒu, p��t�����[iCastleID].�x�ʒu );
	}

	// �G�b�W�̃X�^�[�g�n�_�������́A�S�[���n�_�Ɏ��g��iCastleID������B
	for ( int iEdgeID=0; iEdgeID<N6PCASTLE_EDGE_NUM; iEdgeID++ ) {
		Node* n1 = QueryFromIdx(nb6castle_edges[iEdgeID].e1);
		Node* n2 = QueryFromIdx(nb6castle_edges[iEdgeID].e2);
			
		ConnectNode( n1, n2 );
	}

	return true;

}

