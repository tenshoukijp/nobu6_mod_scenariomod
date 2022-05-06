#include <cassert>
#include "ゲームデータ構造.h"

#include <windows.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <map>

// こっちはn6pwav.dllもしくはn6pwav1.dll
HMODULE hModuleResourceN6PWav;
extern HMODULE hModuleTSMod;

// ユーザ追加型のDLL。「DLL名とDLLハンドル」のハッシュ。
map<string, HMODULE> mapHResistModuleHandle;

using SOUNDHANDLE = int;

using PFNPLAYSOUND2DSTR		= SOUNDHANDLE (WINAPI *)(char *szFileName, BOOL isLoop);
using PFNPLAYSOUND2DRESID	= SOUNDHANDLE (WINAPI *)(int iResID, HMODULE hModule, BOOL isLoop);
using PFNPLAYSOUND3DSTR		= SOUNDHANDLE (WINAPI *)(char *szFileName, BOOL isLoop, double px, double py, double pz, double vx, double vy, double vz);
using PFNPLAYSOUND3DRESID	= SOUNDHANDLE (WINAPI *)(int iResID, HMODULE hModule, BOOL isLoop, double px, double py, double pz, double vx, double vy, double vz);
using PFNSTOPSOUND			= void (WINAPI *)(SOUNDHANDLE hSound);
using PFNSTOPALLSOUND		= void (WINAPI *)();

PFNPLAYSOUND2DSTR p_PlaySound2DStr = NULL;
PFNPLAYSOUND2DRESID p_PlaySound2DResID = NULL;
PFNPLAYSOUND3DSTR p_PlaySound3DStr = NULL;
PFNPLAYSOUND3DRESID p_PlaySound3DResID = NULL;
PFNSTOPSOUND p_StopSound = NULL;
PFNSTOPALLSOUND p_StopAllSound = NULL;

using PFNCHANGEMIDIMAPPER	= void(WINAPI *)(char *szMidiMapperName);
PFNCHANGEMIDIMAPPER p_ChangeMidiMapper = NULL;


	// TSModにしかない動画再生関数のポインタの登録
	void _効果音関数登録() {
		// シナリオデータの引き出し用メソッドのポインタ確保
		p_PlaySound2DStr = (PFNPLAYSOUND2DSTR)GetProcAddress( hModuleTSMod, "Extern_PlaySound2DStr" );
		p_PlaySound2DResID = (PFNPLAYSOUND2DRESID)GetProcAddress( hModuleTSMod, "Extern_PlaySound2DResID" );
		p_PlaySound3DStr = (PFNPLAYSOUND3DSTR)GetProcAddress( hModuleTSMod, "Extern_PlaySound3DStr" );
		p_PlaySound3DResID = (PFNPLAYSOUND3DRESID)GetProcAddress( hModuleTSMod, "Extern_PlaySound3DResID" );
		p_StopSound = (PFNSTOPSOUND)GetProcAddress( hModuleTSMod, "Extern_StopSound" );
		p_StopAllSound = (PFNSTOPALLSOUND)GetProcAddress( hModuleTSMod, "Extern_StopAllSound" );

		p_ChangeMidiMapper = (PFNCHANGEMIDIMAPPER)GetProcAddress( hModuleTSMod, "Extern_ChangeMidiMapper" );
	}


string getModuleResourceN6PWave() {
	// 音源リソース関連登録
	struct stat  st;

	// フル効果音キットを導入していれば…
	if (stat("n6pwav1.dll", &st) == 0) {
		return "n6pwav1.dll";

	// 通常定番シリーズであれば…
	} else {
		return "n6pwav.dll";
	}

}

void _音源モジュール登録() {

	string modulename = getModuleResourceN6PWave();

	// すでに読み込まれているので、ハンドルを得るのみ。
	hModuleResourceN6PWav=GetModuleHandle(modulename.c_str());
}



void _音源モジュール解除() {
	// ユーザー登録の効果音用ＤＬＬを全て解放
	for ( map<string, HMODULE>::iterator it = mapHResistModuleHandle.begin(); it != mapHResistModuleHandle.end(); it++ ) {
		// 順次HMODULEを解放
		  FreeLibrary(it->second);
	}
}


namespace 関数 {


	BOOL Set_効果音ＤＬＬ追加(string 効果音ＤＬＬ名) {
		// 文字列がわたってないぞ。
		if (効果音ＤＬＬ名.empty()) {
			return FALSE;
		}

		HMODULE hModule = NULL;

		// 該当のＤＬＬを読み込み
		hModule = LoadLibrary(効果音ＤＬＬ名.c_str());

		if (!hModule) {
			string エラーメッセージ = "指定の効果音用のDLL:"+効果音ＤＬＬ名+"が読み込めない";
			MessageBox(NULL, エラーメッセージ.c_str(), エラーメッセージ.c_str(), NULL);
			return FALSE;
		}
		// ハッシュに登録
		mapHResistModuleHandle.insert( map<string, HMODULE>::value_type(効果音ＤＬＬ名, hModule) );
		return TRUE;
	}


	// 普通に２Ｄでの音の再生(リソース番号を指定するタイプ)
	音ハンドル型 効果音再生( int 効果音音源, string 効果音ＤＬＬ名, BOOL ループ ) {
		// 環境音の設定が有効であれば…
		if ( p環境設定情報.効果音 == 効果音::ＯＦＦ ) {
			return 0;
		}

		// デフォルトはこっち
		if (効果音ＤＬＬ名.empty()) {

			if ( p_PlaySound2DResID ) {
				return p_PlaySound2DResID( 効果音音源, hModuleResourceN6PWav, ループ );
			// 音を鳴らす。															┌音は非同期  ┌リソースより
			}
			return 0;

		// 今回の効果音再生は、ユーザーによってＤＬＬが指定されている。
		} else {
			HMODULE hModule = mapHResistModuleHandle[効果音ＤＬＬ名];

			if ( p_PlaySound2DResID ) {
				return p_PlaySound2DResID( 効果音音源, hModule, ループ );
			}
			return 0;
		}
	}

	// 普通に２Ｄでの音の再生(ファイル名を指定するタイプ)
	音ハンドル型 効果音再生( string 音源ファイル名, BOOL ループ ) {

		// 環境音の設定が有効であれば…
		if ( p環境設定情報.効果音 == 効果音::ＯＦＦ ) {
			return 0;
		}

		if ( p_PlaySound2DStr ) {
			return p_PlaySound2DStr( (char *)音源ファイル名.c_str(), ループ );
		}
		return 0;
	}

	// ３Ｄでの音の再生(リソース番号を指定するタイプ)
	音ハンドル型 ３Ｄ効果音再生( int 効果音音源, string 効果音ＤＬＬ名, BOOL ループ, ３Ｄ位置型 位置, ３Ｄベクトル型 移動／毎秒) {
		// 環境音の設定が有効であれば…
		if ( p環境設定情報.効果音 == 効果音::ＯＦＦ ) {
			return 0;
		}

		// デフォルトはこっち
		if (効果音ＤＬＬ名.empty()) {

			if ( p_PlaySound3DResID ) {
				return p_PlaySound3DResID( 効果音音源, hModuleResourceN6PWav, ループ, 位置.Ｘ, 位置.Ｙ, 位置.Ｚ,  移動／毎秒.Ｘ, 移動／毎秒.Ｙ, 移動／毎秒.Ｚ );
			// 音を鳴らす。															
			}
			return 0;

		// 今回の効果音再生は、ユーザーによってＤＬＬが指定されている。
		} else {
			HMODULE hModule = mapHResistModuleHandle[効果音ＤＬＬ名];

			if ( p_PlaySound3DResID ) {
				return p_PlaySound3DResID( 効果音音源, hModule, ループ, 位置.Ｘ, 位置.Ｙ, 位置.Ｚ,  移動／毎秒.Ｘ, 移動／毎秒.Ｙ, 移動／毎秒.Ｚ );
			}
			return 0;
		}
	}

	// ３Ｄでの音の再生(ファイル名を指定するタイプ)
	音ハンドル型 ３Ｄ効果音再生( string 音源ファイル名, BOOL ループ, ３Ｄ位置型 位置, ３Ｄベクトル型 移動／毎秒) {
		// 環境音の設定が有効であれば…
		if ( p環境設定情報.効果音 == 効果音::ＯＦＦ ) {
			return 0;
		}

		if ( p_PlaySound3DStr ) {
			return p_PlaySound3DStr( (char *)音源ファイル名.c_str(), ループ, 位置.Ｘ, 位置.Ｙ, 位置.Ｚ,  移動／毎秒.Ｘ, 移動／毎秒.Ｙ, 移動／毎秒.Ｚ );
		}
		return 0;
	}

	// ScenarioModから再生した、１つの効果音を停止する。
	void 効果音停止(音ハンドル型 音ハンドル) {
		if ( p_StopSound ) {
			p_StopSound(音ハンドル);
		}
	}

	// ScenarioModから再生した全効果音の停止
	void 全ての効果音停止() {
		if ( p_StopAllSound ) {
			return p_StopAllSound();
		}
	}

	void Set_ＭＩＤＩデバイス(string デバイス名) {
		if ( p_ChangeMidiMapper ) {
			p_ChangeMidiMapper( (char *)デバイス名.c_str() );
		}
	}

}




