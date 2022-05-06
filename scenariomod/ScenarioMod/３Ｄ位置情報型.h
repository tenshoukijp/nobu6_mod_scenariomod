
// 普通の３Ｄベクトル型。
#pragma once

#include "補助ライブラリ.h"


/// <summary>
/// ３Ｄ位置（いわゆる3DPositionといった概念)のクラス。
/// <para>等価比較演算子としては、 「==」と「!=」</para>
/// <para>又、
/// <code>
/// ３Ｄベクトル型 v = p2 - p1
/// </code>
/// </para>
/// <para>というように、Ａ地点からＢ地点を引くことで、１つの方向ベクトルとなります。</para>
/// </summary>
struct ３Ｄ位置型 {

	double Ｘ;  // Ｘ位置
	double Ｙ;  // Ｙ位置
	double Ｚ;  // Ｚ位置

	/// <summary>
	/// Ｘ位置、Ｙ位置、Ｚ位置を指定するコンストラクタ
	/// </summary>
	/// <param name="Ｘ位置">Ｘ位置</param>
	/// <param name="Ｙ位置">Ｙ位置</param>
	/// <param name="Ｚ位置">Ｚ位置</param>
	３Ｄ位置型(double Ｘ位置, double Ｙ位置, double Ｚ位置) : Ｘ(Ｘ位置), Ｙ(Ｙ位置), Ｚ(Ｚ位置) {}

	/// <summary>
	/// 原点位置のコンストラクタ。
	/// </summary>
	３Ｄ位置型() : Ｘ(0), Ｙ(0), Ｚ(0) {}

	/// <summary>
	/// コピーコンストラクタ相当。
	/// </summary>
	３Ｄ位置型& operator=(const ３Ｄ位置型& v);

	bool operator==(const ３Ｄ位置型& v) const; // == 比較演算子
	bool operator!=(const ３Ｄ位置型& v) const; // != 比較演算子
};


/// <summary>
/// ３Ｄベクトルのクラス。
/// <para>等価比較演算子としては、 「==」と「!=」</para>
/// </summary>
class ３Ｄベクトル型 {
public:
	
	double Ｘ;  // Ｘ成分
	double Ｙ;  // Ｙ成分
	double Ｚ;  // Ｚ成分

	/// <summary>
	/// 全ての成分が０のコンストラクタ。
	/// </summary>
	３Ｄベクトル型();

	/// <summary>
	/// Ｘ成分、Ｙ成分、Ｚ成分を指定するコンストラクタ
	/// </summary>
	/// <param name="Ｘ成分">Ｘ成分</param>
	/// <param name="Ｙ成分">Ｙ成分</param>
	/// <param name="Ｚ成分">Ｚ成分</param>
	３Ｄベクトル型(double Ｘ成分, double Ｙ成分, double Ｚ成分);

	/// <summary>
	/// 位置型要素をそのままベクトルへ
	/// </summary>
	３Ｄベクトル型(３Ｄ位置型 pos);
	
	/// <summary>
	/// コピーコンストラクタ相当。
	/// </summary>
	３Ｄベクトル型& ３Ｄベクトル型::operator=(const ３Ｄベクトル型& v);
	
	/// <summary>
	/// ベクトル加算
	/// </summary>
	３Ｄベクトル型& operator+=(const ３Ｄベクトル型& v);

	/// <summary>
	/// ベクトル減算
	/// </summary>
	３Ｄベクトル型& operator-=(const ３Ｄベクトル型& v);

	/// <summary>
	/// ベクトルをk倍に
	/// </summary>
	３Ｄベクトル型& operator*=(double k);

	/// <summary>
	/// ベクトルをk分の一に
	/// </summary>
	３Ｄベクトル型& operator/=(double k);

	/// <summary>
	/// 単項の+(プラス)
	/// </summary>
	３Ｄベクトル型 operator+()const;

	/// <summary>
	/// 単項の+(マイナス)
	/// </summary>
	３Ｄベクトル型 operator-()const;
	
	/// <summary>
	/// 添え字演算子。0==Ｘ成分、1==Ｙ成分、2==Ｚ成分 のこと。
	/// </summary>
	double& operator[](int i);
    
	bool operator==(const ３Ｄベクトル型& v ) const; // == 比較演算子
	bool operator!=(const ３Ｄベクトル型& v ) const; // != 比較演算子
	
	/// <summary>
	/// べクトルの長さ
	/// </summary>
	double 長さ() const;
	
	/// <summary>
	/// 単位ベクトルへの正規化。
	/// <para>長さ０だと単位ベクトルに出来ないので注意</para>
	/// </summary>
	void 正規化();
};

/// <summary>
/// ベクトル加算
/// </summary>
３Ｄベクトル型 operator+(const ３Ｄベクトル型& u, const ３Ｄベクトル型& v);

/// <summary>
/// ベクトル減算
/// </summary>
３Ｄベクトル型 operator-(const ３Ｄベクトル型& u, const ３Ｄベクトル型& v);

/// <summary>
/// ベクトルをk倍に
/// </summary>
３Ｄベクトル型 operator*(double k, const ３Ｄベクトル型& v);

/// <summary>
/// ベクトルをk倍に
/// </summary>
３Ｄベクトル型 operator*(const ３Ｄベクトル型& v, double k);

/// <summary>
/// ベクトルをk分の一に
/// </summary>
３Ｄベクトル型 operator/(const ３Ｄベクトル型& v, double k);

/// <summary>
/// ２つのベクトルのなす内積
/// </summary>
double operator*(const ３Ｄベクトル型& u, const ３Ｄベクトル型& v);

/// <summary>
/// ２つのベクトルのなす外積
/// </summary>
３Ｄベクトル型 operator%(const ３Ｄベクトル型& u, const ３Ｄベクトル型& v);

/// <summary>
/// ２つのベクトルのなす角度
/// </summary>
double 角度(const ３Ｄベクトル型& u, const ３Ｄベクトル型& v);

/// <summary>
/// ２点間座標の差
/// </summary>
３Ｄベクトル型 operator-(３Ｄ位置型 &p1, ３Ｄ位置型 &p2);

