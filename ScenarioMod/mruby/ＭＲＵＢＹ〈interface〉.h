#ifdef USE_MRUBY_INTERPRETER

#pragma pack(1)

#pragma once

#include "mruby.h"
#include "mruby/array.h"
#include "mruby/class.h"
#include "mruby/compile.h"
#include "mruby/data.h"
#include "mruby/debug.h"
#include "mruby/dump.h"
#include "mruby/error.h"
#include "mruby/gc.h"
#include "mruby/hash.h"
#include "mruby/irep.h"
#include "mruby/khash.h"
#include "mruby/numeric.h"
#include "mruby/object.h"
#include "mruby/opcode.h"
#include "mruby/proc.h"
#include "mruby/range.h"
#include "mruby/re.h"
#include "mruby/string.h"
#include "mruby/value.h"
#include "mruby/variable.h"
#include "mruby/version.h"


extern mrb_state *mrb;


void mruby_dostring(mrb_state *mrb, const char* str);
void mruby_dofile(mrb_state *mrb, const char* filename);
void dofuncall(mrb_state *mrb, const char* funcname);
double mruby_getglobal_numtype(mrb_state *mrg, const char *szvarname);
char* mruby_getglobal_strtype(mrb_state *mrg, const char *szvarname);


#endif

// luaインタプリタロード
void LoadMRubyInterpreter();
// luaインタプリタ解放
void FreeMRubyInterpreter();


