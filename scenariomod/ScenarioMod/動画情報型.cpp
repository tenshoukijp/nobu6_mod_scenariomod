#include <cassert>
#include "ゲームデータ構造.h"
#include "メッセージ関連情報型.h"

using namespace 関数;

extern HMODULE hModuleTSMod;

using PFNFUNCPLAYMOVIE = void (WINAPI *)(char *szMovieName, BOOL isWithBlackBack);
PFNFUNCPLAYMOVIE p_FuncPlayMovie = NULL;

	// TSModにしかない動画再生関数のポインタの登録
	void _動画関数登録() {
		// シナリオデータの引き出し用メソッドのポインタ確保
		p_FuncPlayMovie = (PFNFUNCPLAYMOVIE)GetProcAddress( hModuleTSMod, "Extern_FuncPlayMovie" );
	}


namespace 関数 {

	// 指定のムービー再生する
	void 動画再生(string 動画名, int オプション) {

		if ( p_FuncPlayMovie ) {
			p_FuncPlayMovie((char *)動画名.c_str(), オプション );
		}
	}
}

