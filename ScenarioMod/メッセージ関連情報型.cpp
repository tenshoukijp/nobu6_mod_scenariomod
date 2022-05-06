#define  _CRT_SECURE_NO_WARNINGS

#include <string>
#include <map>

#include "メッセージ関連情報型.h"
#include "デバッグ情報型.h"

using namespace std;
using namespace 関数;


extern HMODULE hModuleTSMod;

using PFNONIGMATCHALLOC = int (WINAPI *)(char *対象文字列, char *正規表現文字列, int *正規表現マッチ結果);
PFNONIGMATCHALLOC p_OnigMatchAlloc = NULL;

using PFNONIGMATCHFREE	= int (WINAPI *)(int *正規表現マッチ結果);
PFNONIGMATCHFREE p_OnigMatchFree = NULL;

// TSModにしかない正規表現関連ののポインタの登録
void _正規表現関数登録() {
	p_OnigMatchAlloc = (PFNONIGMATCHALLOC)GetProcAddress( hModuleTSMod, "Extern_OnigMatchAlloc" );
	p_OnigMatchFree = (PFNONIGMATCHFREE)GetProcAddress( hModuleTSMod, "Extern_OnigMatchFree" );
}


// 正規表現マッチング用の関数

namespace 関数 {

	BOOL Is_文字列マッチ(  string 対象文字列, string 部分文字列 ) {
		return 対象文字列.find(部分文字列) != string::npos;
	}


	BOOL Is_正規表現マッチ(  string 対象文字列, string 正規表現文字列, 正規表現マッチ結果型* 正規表現マッチ結果 ) {

		// まず、検索結果は削除
		if ( 正規表現マッチ結果 ) {
			正規表現マッチ結果->clear();
		}

		// どちらかが中身からなら、falseを返す。
		if ( 対象文字列.length() == 0 || 正規表現文字列.length() == 0 ) {
			return false;
		}

		if ( p_OnigMatchAlloc ) {

			int matches[100] = {0};

			int ret = false;

			// 正規表現マッチ結果が不要ならば、NULLにしておく。
			if ( 正規表現マッチ結果 ) {
				ret = p_OnigMatchAlloc( (char *)対象文字列.c_str(), (char *)正規表現文字列.c_str(), matches );
			} else {
				ret = p_OnigMatchAlloc( (char *)対象文字列.c_str(), (char *)正規表現文字列.c_str(), 0 );
			}

			// 結果が格納されている。
			if ( matches ) {
				// 暴走防止のため。いくらなんでも100個カッコとかないでしょ。
				for (int i=0; i<sizeof(matches)/sizeof(matches[0]); i++) {
					int address = matches[i];
					if (address == 0xFFFF) { // 終了の番兵。コピー終了
						break;
					}
					// 有効なアドレスであれば、文字列を指示している。
					if (address) {
						string cp = string((char *)address); // 文字列としてコピー
						正規表現マッチ結果->insert( 正規表現マッチ結果型::value_type( i, cp ) );
					}
				}
			}


			// この解放は必須
			if ( p_OnigMatchFree ) {
				p_OnigMatchFree(matches);
			}

			return ret;
		}

		return false; // 関数がない
	}

} // namespace