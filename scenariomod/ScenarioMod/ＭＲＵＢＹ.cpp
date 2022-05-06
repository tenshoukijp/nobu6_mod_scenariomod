#ifdef USE_MRUBY_INTERPRETER


#include <string>
#include "mruby/ＭＲＵＢＹ〈interface〉.h"

#include "ゲームデータ構造.h"

using namespace std;

namespace 関数 {
	namespace MRUBY {

		double Get_グローバル数値(string 変数名) {
			try {
				double ret = mruby_getglobal_numtype(mrb, (char *)変数名.c_str());
				return ret;
			}
			catch (...) {
				throw MRUBY::例外型("MRUBY::Get_グローバル数値エラー");
			}
		}

		string Get_グローバル文字列(string 変数名) {
			try {
				string ret = mruby_getglobal_strtype(mrb, (char *)変数名.c_str());
				return ret;
			}
			catch (...) {
				throw MRUBY::例外型("MRUBY::Get_グローバル文字列エラー");
			}
		}


		int Do_コマンド(string コマンド文字列) {
			try {
				mruby_dostring(mrb, コマンド文字列.c_str());
				return 0;
			}
			catch (...) {
				throw MRUBY::例外型("MRUBY::Do_コマンドエラー");
			}
		}

		int Do_ファイル(string ファイル名) {
			try {
				mruby_dofile(mrb, ファイル名.c_str());
				return 0;
			}
			catch (...) {
				throw MRUBY::例外型("MRUBY::Do_ファイルエラー");
			}
		}
	}

	std::ostream& operator<<(std::ostream& os, 関数::MRUBY::例外型& e)
	{
		os << e.what();
		return os;
	}
}





#endif