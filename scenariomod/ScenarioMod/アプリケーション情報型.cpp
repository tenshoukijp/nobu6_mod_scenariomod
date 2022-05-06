
#include <string>

#include "ゲームデータ構造.h"

using namespace std;
using namespace 関数;

extern HMODULE hModuleTSMod;

using PFNADDMENUITEM = void (WINAPI *)(char *menuname, int position, int wID);
PFNADDMENUITEM p_AddMenuItem = NULL;

// アプリケーション情報型
void _アプリケーション関数登録() {
	// メニューアイテム追加。
	p_AddMenuItem = (PFNADDMENUITEM)GetProcAddress( hModuleTSMod, "Extern_AddMenuItem" );
}


static int _メニュースタート番号 = 59000; // 59000番号からのスタート

namespace 関数 {

	namespace アプリケーション {

		// 返り値がメニューアイテムに割り当てられ場番号
		// この番号をどこかに保存しておき、、「On_アプリケーションのメニューアイテムのクリック時」に判定用として利用する。
		int メニューアイテム追加( string メニュー文字列 ) {
			if (p_AddMenuItem) {
				p_AddMenuItem((char *)メニュー文字列.c_str(), NULL, _メニュースタート番号);
				return _メニュースタート番号++;
			}
			return -1;
		}
	}
}