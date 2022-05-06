/*
 * 音楽情報、いわゆるＢＧＭ関連
 */
#pragma once
#pragma pack(1)

#include <windows.h>



// 指定の音楽(ＢＧＭ)を再生する(この音楽番号は、神パッチで指定する番号と合致してると考えて良い)
namespace 関数 {

	/// <summary>
	/// 再生中のBGMの番号を得る。
	/// <para>トラック番号と同じであり、神パッチやTSMod.iniに記載されている番号と同じである。</para>
	/// <para>返り値：1以上の値が返ってくる。0xFFFFだと何も再生していない。</para>
	/// <para>環境設定の｢音楽｣の項目がＯＦＦの時も、0xFFFFが返ってくることとなる。</para>
	/// </summary>
	/// <returns>1以上の値が返ってくる。0xFFFFだと何も再生していない。環境設定の｢音楽｣の項目がＯＦＦの時も、0xFFFFが返ってくることとなる。</returns>
	int Get_再生音楽番号();


	/// <summary>
	///  _INMMを利用して再生しているかどうかを判定する。
	/// <para>返り値：_INMMを利用していたら真、利用していないなら偽</para>
	/// </summary>
	bool Is_INMMモード();


	/// <summary>
	/// 指定の番号のBGMを再生する。
	/// </summary>
	/// <param name="音楽番号">再生したい音楽番号
	/// <para>トラック番号と同じであり、神パッチやTSMod.iniに記載されている番号と同じである。</para>
	/// </param>
	void 音楽再生(int 音楽番号);


	/// <summary>
	/// 再生中のBGMを停止する。
	/// </summary>
	void 音楽停止();
}

