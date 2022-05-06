#include <windows.h>

//------------------------------------------------
// プロセスID ⇒ HWND への変換
// 引数:プロセスID
// 戻り値: HWND もしくは NULL
//------------------------------------------------
HWND GetWindowHandleFromProcessId( const DWORD TargetID) {
	HWND hWnd = GetTopWindow(NULL);
	do {
		if(GetWindowLong( hWnd, GWL_HWNDPARENT) != 0 || !IsWindowVisible(hWnd)) {
			continue;
		}
		DWORD ProcessID;
		GetWindowThreadProcessId( hWnd, &ProcessID);
		if(TargetID == ProcessID) {
			return hWnd;
		}
	} while((hWnd = GetNextWindow( hWnd, GW_HWNDNEXT)) != NULL);

	return NULL;
}


//------------------------------------------------
// 現在のウィンドウハンドルを得る
//------------------------------------------------
HWND GetCurrentWindowHandle() {
	// 実行中のプロセスIDを得る
	DWORD pID = GetCurrentProcessId();
	// プロセスID⇒ウィンドウハンドル
	HWND hWnd = GetWindowHandleFromProcessId(pID);
	return hWnd;
}
