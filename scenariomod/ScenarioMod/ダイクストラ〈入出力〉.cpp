
#include "ゲームデータ構造.h"
#include "ダイクストラ.h"
#include "ダイクストラ〈城〉.h"



//ファイル読み込み
bool Dijkstra::Inport()
{
	Clear();

	// エッジのスタート地点もしくは、ゴール地点に自身のiCastleIDがある。
	for ( int iCastleID=0; iCastleID<最大数::城情報::配列数; iCastleID++ ) {
		// 城の座標をそのままノードの座標として格納。
		AddNode( iCastleID, p城付加情報[iCastleID].Ｘ位置, p城付加情報[iCastleID].Ｙ位置 );
	}

	// エッジのスタート地点もしくは、ゴール地点に自身のiCastleIDがある。
	for ( int iEdgeID=0; iEdgeID<N6PCASTLE_EDGE_NUM; iEdgeID++ ) {
		Node* n1 = QueryFromIdx(nb6castle_edges[iEdgeID].e1);
		Node* n2 = QueryFromIdx(nb6castle_edges[iEdgeID].e2);
			
		ConnectNode( n1, n2 );
	}

	return true;

}

