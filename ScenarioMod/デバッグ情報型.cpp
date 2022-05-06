#define _CRT_SECURE_NO_WARNINGS

#include "ゲームデータ構造.h"


// OutputDebugStringへとフォーマット(printf)形式を利用して出力する。
char szBufOutputDebugStream[4096];



//------------------------------------------------------


namespace 関数 {

	デバッグストリーム型 デバッグ出力;

	// String^ 型をOutputDebugStreamに対応させる。
	デバッグストリーム型& operator << (デバッグストリーム型& os, System::String^ str) {
		string msg = string←String(str);
		os << msg;
		return os;
	}

}


