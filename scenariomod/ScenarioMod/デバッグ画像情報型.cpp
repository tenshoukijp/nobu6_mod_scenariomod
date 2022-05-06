#include "ゲームデータ構造.h"



using namespace System;
using namespace System::Drawing;

extern HWND tenshouWND;

//------------------------------------------------------


namespace 関数 {

	// クライアント矩形のbmpへの保存
	void デバッグ画像出力(string ファイル名) {

		RECT rect;
		// キャプチャするためにはアクティブにする必要がある(他のウィンドウで隠れていても問題はないが、アクティブである必要はある)
		::SetForegroundWindow(tenshouWND);

		// ウィンドウ枠
		::GetWindowRect(tenshouWND, &rect);
		System::Drawing::Bitmap^ img = gcnew System::Drawing::Bitmap(rect.right - rect.left, rect.bottom - rect.top);
		// イメージオブジェクトへのリファレンスをコンテナとして持つグラフィックオブジェクトを確保
		Graphics^ memg = Graphics::FromImage(img);
		// グラフィックス機能にデバイスコンテキストをアタッチ
		IntPtr dc = memg->GetHdc();
		// win32形式使うので変換だけ
		HDC bmpDC = (HDC)dc.ToPointer();
		// ウィンドウハンドルのデバイスコンテキスト
		HDC winDC = ::GetWindowDC(tenshouWND);
		// ウィンドウハンドルのデバイスコンテキストのイメージをそっくりそのまま、グラフィックスオブジェクトのデバイスコンテキストへとコピー
		::BitBlt(bmpDC, 0, 0, img->Width, img->Height, winDC, 0, 0, SRCCOPY);
		// グラフィックス機能の方にアタッチしていたデバイスコンテキストを破棄
		memg->ReleaseHdc(dc);
		// ウィンドウハンドルのアタッチに使っていたデバイスコンテキストも破棄
		::ReleaseDC(tenshouWND, bmpDC);

		String^ filename = String←string(ファイル名);
		if (Is_正規表現マッチ(ファイル名, "\\.bmp$")) {
			img->Save(filename, System::Drawing::Imaging::ImageFormat::Bmp);
		}
		else if (Is_正規表現マッチ(ファイル名, "\\.jpe?g$")) {
			img->Save(filename, System::Drawing::Imaging::ImageFormat::Jpeg);
		}
		else if (Is_正規表現マッチ(ファイル名, "\\.png$")) {
			img->Save(filename, System::Drawing::Imaging::ImageFormat::Png);
		}
	}
}
