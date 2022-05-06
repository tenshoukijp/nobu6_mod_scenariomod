#pragma once

#pragma pack(1)

#pragma warning ( error : 4706 ) // 条件式の比較値が、代入の結果になっているのはアウトとする。 (if文などで比較ではなく代入だけしてると思しきモノをエラー扱いとする)

#include <windows.h>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <shlwapi.h>
#include <cctype>

using namespace std;

#include "最大数.h"
#include "情報メモリアドレス.h"

#include "補助ライブラリ.h"

#include "メッセージ関連情報型.h"
#include "カスタム条件情報型.h"

#include "ターン情報型.h"
#include "地域情報型.h"
#include "城情報型.h"
#include "天気情報型.h"
#include "大名情報型.h"
#include "官位情報型.h"
#include "家宝情報型.h"
#include "暦情報型.h"
#include "武将情報型.h"
#include "待機武将情報型.h"
#include "相場情報型.h"
#include "軍団情報型.h"
#include "役職情報型.h"
#include "戦場情報型.h"
#include "環境設定情報型.h"
#include "効果音情報型.h"
#include "音楽情報型.h"
#include "動画情報型.h"
#include "画面演出情報型.h"
#include "コマンド情報型.h"
#include "ダイアログ情報型.h"
#include "部隊名情報型.h"
#include "シナリオ情報型.h"
#include "エンディング情報型.h"
#include "２Ｄ位置情報型.h"
#include "３Ｄ位置情報型.h"
#include "フラグ情報型.h"
#include "言葉遣い情報型.h"
#include "デバッグ情報型.h"
#include "デバッグ画像情報型.h"
#include "アプリケーション情報型.h"
#include "ＬＵＡ.h"
#include "ＭＲＵＢＹ.h"

#include "拡張セーブデータ情報.h"
#include "マネージドライブラリ.h"


using namespace 関数;


#define p年情報					d年情報[0]
#define pターン情報				dターン情報[0]
#define p相場情報				d相場情報[0]
#define p天気情報				d天気情報[0]
#define p環境設定情報			d環境設定情報[0]
#define p環境設定拡張情報		d環境設定拡張情報[0]


extern	年情報型				*const d年情報;
extern	ターン情報型			*const dターン情報;
extern	相場情報型				*const d相場情報;
extern	天気情報型				*const d天気情報;

extern	武将情報型				*const p武将情報;

extern	武将戸籍情報型			*const p武将戸籍情報;

extern	軍団情報型				*const p軍団情報;
extern	プレイヤ担当軍団情報型	*const pプレイヤ担当軍団情報;

extern	大名情報型				*const p大名情報;

extern	城情報型				*const p城情報;
extern	城付加情報型			*const p城付加情報;

extern	地域情報型				*const p地域情報;

extern	官位情報型				*const p官位情報;
extern	家宝情報型				*const p家宝情報;

extern	環境設定情報型			*const d環境設定情報;
extern	環境設定拡張情報型		*const d環境設定拡張情報;

