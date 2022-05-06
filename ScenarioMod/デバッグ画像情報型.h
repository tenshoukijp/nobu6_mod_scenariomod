#pragma once
#pragma pack(1)

#include <windows.h>
#include "デバッグクラス.h"

namespace 関数 {

	/// <summary>
	/// デバッグ用途でゲーム画面をファイルに保存する。
	/// </summary>
	/// <param name="ファイル名">保存するファイル名。png、jpg、bmpのいずれかの形式で保存可能である。</param>
	void デバッグ画像出力(string ファイル名);
}

