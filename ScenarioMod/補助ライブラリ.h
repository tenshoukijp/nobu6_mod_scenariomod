#pragma once

#include <cmath>
#include <vector>

using namespace std;

using 番号リスト型 = vector<int>;

/// <summary>
/// 対象の値を四捨五入して、整数とする。
/// </summary>
/// <param name="value">対象の浮動小数値</param>
/// <returns>四捨五入された整数値</returns>
int round《整数化》(double value);


/// <summary>
/// 全ての数値が0.5単位の目盛りであると仮定して、そこへと数値を丸める。
/// </summary>
/// <param name="value">対象の浮動小数値</param>
/// <returns>0.5刻みへと吸着(四捨五入的な感覚)された整数値</returns>
double round《二分の一吸着化》(double value);

