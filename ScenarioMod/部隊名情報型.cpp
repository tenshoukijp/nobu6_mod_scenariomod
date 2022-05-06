#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <cassert>
#include "ゲームデータ構造.h"
#include <string>


extern char g部隊名語尾書式[11];

namespace 関数 {
	void Set_部隊名書式(部隊名リスト型＆ 部隊名リスト変数, char *sprintf書式) {
		strncpy(g部隊名語尾書式, sprintf書式, 10);
		g部隊名語尾書式[10] = NULL;
	}
}