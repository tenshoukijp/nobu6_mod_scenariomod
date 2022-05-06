#include <cassert>
#include "ゲームデータ構造.h"


extern HMODULE hModuleTSMod;

using PFNRESERVEWEATHER = void (WINAPI *)(int eTenki, int iContinueTurn);
PFNRESERVEWEATHER p_FuncReserveWeather = NULL;

	// TSModにしかない天気予約関数のポインタの登録

	void _天気関数登録() {
		// シナリオデータの引き出し用メソッドのポインタ確保
		p_FuncReserveWeather = (PFNRESERVEWEATHER)GetProcAddress( hModuleTSMod, "Extern_reserveWeather" );
	}



namespace 関数 {


// 天気情報を得る 0:晴れ 1:曇り 2:雨 3:雪
byte Get_天気() {

	return p天気情報._天気;
}

}





/*
00436101  |> 56             PUSH    ESI						← 天気番号
00436102  |. E8 29020600    CALL    TENSHOU.00496330		← 天気を変更して、描画も更新の関数
00436107  |. 83C4 04        ADD     ESP, 4
*/

int pCallFromFuncSetWeather = 0x496330; // 元々TENSHOU.EXE内にあったCALL先。天気値と天気グラフィックを変更

int iWeatherIDInFuncSetWeather = 1L;    // 死亡武将ID

// 天気の変更
void FuncSetWeatherAsm() {
	__asm {
		push iWeatherIDInFuncSetWeather
		call pCallFromFuncSetWeather
		add esp, 0x4
	}
}



namespace 関数 {



// 天気の変更のラッパー
void Set_天気(int i天気) {

	// 関数用のやつは、1つ多いので、足しこみ
	iWeatherIDInFuncSetWeather = i天気;

	__asm {
		push eax
		push ebx
		push ecx
		push edx
		push esp
		push esi
		push edi
	}
	// TENSHOU.EXE内の関数呼び出し
	FuncSetWeatherAsm();

	__asm {
		pop edi
		pop esi
		pop esp
		pop edx
		pop ecx
		pop ebx
		pop eax
	}
}

// 次のターンの天気を予約する
void Set_天気予約(int 予約天気, int 継続ターン) {

	if ( p_FuncReserveWeather ) {
		p_FuncReserveWeather(予約天気, 継続ターン);
	}
}


}




