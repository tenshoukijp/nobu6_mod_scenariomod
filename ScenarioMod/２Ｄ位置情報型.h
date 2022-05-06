
// 普通の２Ｄベクトル型。
#pragma once

#include <string>
#include "補助ライブラリ.h"

using namespace std;



/// <summary>
/// ２Ｄ位置（いわゆるPositionやPointといった概念)のクラス。
/// <para>等価比較演算子としては、 「==」と「!=」。</para>
/// <para>又、
/// <code>
/// ２Ｄベクトル型 v = p2 - p1
/// </code>
/// </para>
/// <para>というように、Ａ地点からＢ地点を引くことで、１つの方向ベクトルとなります。</para>
/// </summary>
struct ２Ｄ位置型 {

	double Ｘ;  // Ｘ位置
	double Ｙ;  // Ｙ位置

	/// <summary>
	/// Ｘ位置、Ｙ位置を指定するコンストラクタ
	/// </summary>
	/// <param name="Ｘ位置">Ｘ位置</param>
	/// <param name="Ｙ位置">Ｙ位置</param>
	２Ｄ位置型(double Ｘ位置, double Ｙ位置) : Ｘ(Ｘ位置), Ｙ(Ｙ位置) {}

	/// <summary>
	/// 原点位置のコンストラクタ。
	/// </summary>
	２Ｄ位置型() : Ｘ(0), Ｙ(0) {}

	/// <summary>
	/// コピーコンストラクタ相当。
	/// </summary>
	２Ｄ位置型& operator=(const ２Ｄ位置型& v);

	bool operator==(const ２Ｄ位置型& v) const; // == 比較演算子
	bool operator!=(const ２Ｄ位置型& v) const; // != 比較演算子
};


/// <summary>
/// ２Ｄベクトルのクラス。
/// <para>等価比較演算子としては、 「==」と「!=」</para>
/// </summary>
class ２Ｄベクトル型 {
public:

	double Ｘ;  // Ｘ成分
	double Ｙ;  // Ｙ成分

	/// <summary>
	/// 全ての成分が０のコンストラクタ。
	/// </summary>
	２Ｄベクトル型();


	/// <summary>
	/// Ｘ成分、Ｙ成分、Ｚ成分を指定するコンストラクタ
	/// </summary>
	/// <param name="Ｘ成分">Ｘ成分</param>
	/// <param name="Ｙ成分">Ｙ成分</param>
	２Ｄベクトル型(double Ｘ成分, double Ｙ成分);

	/// <summary>
	/// 位置型要素をそのままベクトルへ
	/// </summary>
	２Ｄベクトル型(２Ｄ位置型 pos);

	/// <summary>
	/// コピーコンストラクタ相当。
	/// </summary>
	２Ｄベクトル型& ２Ｄベクトル型::operator=(const ２Ｄベクトル型& v);

	/// <summary>
	/// ベクトル加算
	/// </summary>
	２Ｄベクトル型& operator+=(const ２Ｄベクトル型& v);

	/// <summary>
	/// ベクトル減算
	/// </summary>
	２Ｄベクトル型& operator-=(const ２Ｄベクトル型& v);

	/// <summary>
	/// ベクトルをk倍に
	/// </summary>
	２Ｄベクトル型& operator*=(double k);

	/// <summary>
	/// ベクトルをk分の一に
	/// </summary>
	２Ｄベクトル型& operator/=(double k);

	/// <summary>
	/// 単項の+(プラス)
	/// </summary>
	２Ｄベクトル型 operator+()const;

	/// <summary>
	/// 単項の+(マイナス)
	/// </summary>
	２Ｄベクトル型 operator-()const;

	/// <summary>
	/// 添え字演算子。0==Ｘ成分、1==Ｙ成分 のこと。
	/// </summary>
	double& operator[](int i);

	bool operator==(const ２Ｄベクトル型& v ) const; // == 比較演算子
	bool operator!=(const ２Ｄベクトル型& v ) const; // != 比較演算子

	/// <summary>
	/// べクトルの長さ
	/// </summary>
	double 長さ()const;

	/// <summary>
	/// 単位ベクトルへの正規化。
	/// <para>長さ０だと単位ベクトルに出来ないので注意</para>
	/// </summary>
	void 正規化();
};

/// <summary>
/// ベクトル加算
/// </summary>
２Ｄベクトル型 operator+(const ２Ｄベクトル型& u, const ２Ｄベクトル型& v);

/// <summary>
/// ベクトル減算
/// </summary>
２Ｄベクトル型 operator-(const ２Ｄベクトル型& u, const ２Ｄベクトル型& v);

/// <summary>
/// ベクトルをk倍に
/// </summary>
２Ｄベクトル型 operator*(double k, const ２Ｄベクトル型& v);

/// <summary>
/// ベクトルをk倍に
/// </summary>
２Ｄベクトル型 operator*(const ２Ｄベクトル型& v, double k);

/// <summary>
/// ベクトルをk分の一に
/// </summary>
２Ｄベクトル型 operator/(const ２Ｄベクトル型& v, double k);

/// <summary>
/// ２つのベクトルのなす内積
/// </summary>
double operator*(const ２Ｄベクトル型& u, const ２Ｄベクトル型& v);

/// <summary>
/// ２つのベクトルのなす外積
/// </summary>
double operator%(const ２Ｄベクトル型& u, const ２Ｄベクトル型& v);

/// <summary>
/// ２つのベクトルのなす角度
/// </summary>
double 角度(const ２Ｄベクトル型& u, const ２Ｄベクトル型& v);

/// <summary>
/// ２点間座標の差
/// </summary>
２Ｄベクトル型 operator-(２Ｄ位置型 &p1, ２Ｄ位置型 &p2);

/// <summary>
/// <para>ベクトルを「東」「西」「南」「北」「北東」「南東」「北西」「南西」の８方位で文字列化。</para>
/// <para>最も近いものが選ばれる</para>
/// </summary>
string Get_８方位文字列(２Ｄベクトル型 v);

/// <summary>
/// <para>ベクトルを「東」「西」「南」「北」の４方位で文字列化。</para>
/// <para>最も近いものが選ばれる</para>
/// </summary>
string Get_４方位文字列(２Ｄベクトル型 v);

