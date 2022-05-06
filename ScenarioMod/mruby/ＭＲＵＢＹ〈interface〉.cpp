#ifdef USE_MRUBY_INTERPRETER


#pragma pack(1)

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <stdarg.h>
#include <tchar.h>
#include <assert.h>
#include <iostream>

#include "ＭＲＵＢＹ〈interface〉.h"

#pragma comment (lib, "mruby/lib/libmruby.lib")
#pragma comment (lib, "mruby/lib/libmruby_core.lib")

using namespace std;

mrb_state *mrb = NULL;


static void RUBY_OutputDebugString(char *format, ...) {
    char szBufDebug[4096] = "";
    int length = sizeof(szBufDebug);

    va_list arg;

    va_start(arg, format);
	vprintf(format, arg);
	_vsnprintf_s(szBufDebug, length, _TRUNCATE, format, arg);
    va_end(arg);

	szBufDebug[length - 1] = '\0'; // 番兵
    OutputDebugString( szBufDebug );
}


/*
void show_backtrace(mrb_state *mrb) {
	mrb_value exc = mrb_obj_value(mrb->exc);
	mrb_value backtrace = mrb_get_backtrace(mrb);
	mrb_value s = mrb_funcall(mrb, exc, "inspect", 0);
	RUBY_OutputDebugString("%s\n", RSTRING_PTR(s));
	for (mrb_int n = mrb_ary_len(mrb, backtrace), i = 0; i < n; ++i) {
		mrb_value v = mrb_ary_ref(mrb, backtrace, i);
		RUBY_OutputDebugString("\t%s\n", RSTRING_PTR(v));
	}
}
*/

// ダウプエラー
void dump_error(mrb_state *mrb) {
	mrb_print_error(mrb);
	mrb->exc = 0;
}

// 文字列の実行
void mruby_dostring(mrb_state *mrb, const char* str) {
	int arena = mrb_gc_arena_save(mrb);
	mrbc_context *cxt = mrbc_context_new(mrb);
	mrbc_filename(mrb, cxt, "*interactive*");
	mrb_load_string_cxt(mrb, str, cxt);
	mrbc_context_free(mrb, cxt);
	if (mrb->exc) {
		dump_error(mrb);
		mrb_gc_arena_restore(mrb, arena);
		throw -1;
	}
	mrb_gc_arena_restore(mrb, arena);
}

// ファイルの実行
void mruby_dofile(mrb_state *mrb, const char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		RUBY_OutputDebugString("Cannot open program file. (%s)\n", filename);
		throw -1;
	}

	int arena = mrb_gc_arena_save(mrb);
	mrbc_context *cxt = mrbc_context_new(mrb);
	mrbc_filename(mrb, cxt, filename);
	mrb_load_file_cxt(mrb, fp, cxt);
	mrbc_context_free(mrb, cxt);
	fclose(fp);
	if (mrb->exc) {
		dump_error(mrb);
		mrb_gc_arena_restore(mrb, arena);
		throw - 1;
	}
	mrb_gc_arena_restore(mrb, arena);
}

// 関数のコール
void mruby_dofuncall(mrb_state *mrb, const char* funcname) {
	int arena = mrb_gc_arena_save(mrb);
	mrb_funcall(mrb, mrb_top_self(mrb), funcname, 0);
	if (mrb->exc) {
		dump_error(mrb);
		mrb_gc_arena_restore(mrb, arena);
		throw - 1;
	}
	mrb_gc_arena_restore(mrb, arena);
}

// 番号型のグローバル変数取得
double mruby_getglobal_numtype(mrb_state *mrg, const char *szvarname) {
	mrb_sym msym = mrb_intern_static(mrb, szvarname, strlen(szvarname) );
	mrb_value global_num = mrb_gv_get(mrb, msym); // グローバル変数取得
	if (mrb_type(global_num) == MRB_TT_FIXNUM ) {
		return (double)mrb_fixnum(global_num);
	}
	else if (mrb_type(global_num) == MRB_TT_FLOAT) {
		return (double)mrb_float(global_num);
	}
	else {
		throw mrb_type(global_num);
	}
}

char* mruby_getglobal_strtype(mrb_state *mrg, const char *szvarname) {
	mrb_sym msym = mrb_intern_static(mrb, szvarname, strlen(szvarname)); // mrb_gv_getの2番目の引数に渡すため、変数名をシンボル型変数に直す。
	mrb_value global_szbuf = mrb_gv_get(mrb, msym); // グローバル変数取得
	// 文字列型がったら･･･
	if (mrb_type(global_szbuf) == MRB_TT_STRING) {
		// String型のオブジェクトのポインタを得る
		char *p = mrb_str_to_cstr(mrb, mrb_value(global_szbuf));
		// 引数のバッファにコピー
		return p;
	}
	else {
		throw mrb_type(global_szbuf);
	}
}

// luaインタプリタロード
void LoadMRubyInterpreter() {
	mrb = mrb_open();
}

// luaインタプリタ解放
void FreeMRubyInterpreter() {
	mrb_close(mrb);
}



#else


// mrubyインタプリタロード
void LoadMRubyInterpreter() {
}
// mrubyインタプリタ解放
void FreeMRubyInterpreter() {
}


#endif



