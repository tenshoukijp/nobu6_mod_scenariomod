#include "ゲームデータ構造.h"


//比較演算子
bool ３Ｄ位置型::operator==(const ３Ｄ位置型& v ) const{
    return (Ｘ == v.Ｘ) && (Ｙ == v.Ｙ) && (Ｚ == v.Ｚ);
}
bool ３Ｄ位置型::operator!=(const ３Ｄ位置型& v ) const{
    return !(*this == v);
}
//代入演算子
３Ｄ位置型& ３Ｄ位置型::operator=(const ３Ｄ位置型& v){
	this->Ｘ=v.Ｘ;
	this->Ｙ=v.Ｙ;
	this->Ｚ=v.Ｚ;
	return *this;
}



//*----------------------メンバ関数の実装--------------------------*//
３Ｄベクトル型::３Ｄベクトル型(){ Ｘ = Ｙ = Ｚ = 0; }
３Ｄベクトル型::３Ｄベクトル型(double Ｘ成分, double Ｙ成分, double Ｚ成分){
	this->Ｘ=Ｘ成分;
	this->Ｙ=Ｙ成分;
	this->Ｚ=Ｚ成分;
}
３Ｄベクトル型::３Ｄベクトル型(３Ｄ位置型 pos){
	this->Ｘ=pos.Ｘ;
	this->Ｙ=pos.Ｙ;
	this->Ｚ=pos.Ｚ;
}
//代入演算子
３Ｄベクトル型& ３Ｄベクトル型::operator=(const ３Ｄベクトル型& v){
	this->Ｘ=v.Ｘ;
	this->Ｙ=v.Ｙ;
	this->Ｚ=v.Ｚ;
	return *this;
}
//単項演算子
３Ｄベクトル型& ３Ｄベクトル型::operator+=(const ３Ｄベクトル型& v){
	 this->Ｘ += v.Ｘ;
	 this->Ｙ += v.Ｙ;
	 this->Ｚ += v.Ｚ;
	 return *this;
}
３Ｄベクトル型& ３Ｄベクトル型::operator-=(const ３Ｄベクトル型& v){
	 this->Ｘ -= v.Ｘ;
	 this->Ｙ -= v.Ｙ;
	 this->Ｚ -= v.Ｚ;
	 return *this;
}
３Ｄベクトル型& ３Ｄベクトル型::operator*=(double k){
	 this->Ｘ *= k;
	 this->Ｙ *= k;
	 this->Ｚ *= k;
	 return *this;
}
３Ｄベクトル型& ３Ｄベクトル型::operator/=(double k){
	this->Ｘ /= k;
	this->Ｙ /= k;
	this->Ｚ /= k;
	return *this;
}
３Ｄベクトル型 ３Ｄベクトル型::operator+()const{		//+３Ｄベクトル型
	return *this;
}
３Ｄベクトル型 ３Ｄベクトル型::operator-()const{		//-３Ｄベクトル型
	return ３Ｄベクトル型(-Ｘ,-Ｙ,-Ｚ);
}
//添え字演算子
double& ３Ｄベクトル型::operator[](int i){
	if(i == 0){
		return Ｘ;
	}
	else if(i == 1){
		return Ｙ;
	}
	else if(i == 2){
		return Ｚ;
	}
	else{
		return Ｘ;
	}
}
//比較演算子
bool ３Ｄベクトル型::operator==(const ３Ｄベクトル型& v ) const {
    return (Ｘ == v.Ｘ) && (Ｙ == v.Ｙ) && (Ｚ == v.Ｚ);
}
bool ３Ｄベクトル型::operator!=(const ３Ｄベクトル型& v ) const {
    return !(*this == v);
}
//べクトルの長さ
double ３Ｄベクトル型::長さ() const {
	return pow((double)(Ｘ*Ｘ+Ｙ*Ｙ+Ｚ*Ｚ),(double)0.5f);
}
//正規化(単位ベクトル化)
void ３Ｄベクトル型::正規化(){
	if ( 長さ() == 0 ) {
		MessageBox(NULL, "長さが０のベクトル(=方向が無いベクトル)を単位ベクトル化しようとしました。無限０除算でエラーとなります。","長さが０のベクトル(=方向が無いベクトル)を単位ベクトル化しようとしました。無限０除算でエラーとなります。", NULL);
	}

	*this /= 長さ();
}
//*----------------------グローバル関数の実装--------------------------*//
//二項演算子の定義
//３Ｄベクトル型+３Ｄベクトル型
３Ｄベクトル型 operator+(const ３Ｄベクトル型& u,const ３Ｄベクトル型& v){
	３Ｄベクトル型 w;
	w.Ｘ=u.Ｘ+v.Ｘ;
	w.Ｙ=u.Ｙ+v.Ｙ;
	w.Ｚ=u.Ｚ+v.Ｚ;
	return w;
}
//３Ｄベクトル型-３Ｄベクトル型
３Ｄベクトル型 operator-(const ３Ｄベクトル型& u,const ３Ｄベクトル型& v){
	３Ｄベクトル型 w;
	w.Ｘ=u.Ｘ-v.Ｘ;
	w.Ｙ=u.Ｙ-v.Ｙ;
	w.Ｚ=u.Ｚ-v.Ｚ;
	return w;
}
//double*３Ｄベクトル型
３Ｄベクトル型 operator*(double k,const  ３Ｄベクトル型& v){
	return ３Ｄベクトル型(k*v.Ｘ,k*v.Ｙ,k*v.Ｚ);
}
//３Ｄベクトル型*double
３Ｄベクトル型 operator*(const ３Ｄベクトル型& v,double k){
	return ３Ｄベクトル型(v.Ｘ*k,v.Ｙ*k,v.Ｚ*k);
}
//３Ｄベクトル型/double
３Ｄベクトル型 operator/(const ３Ｄベクトル型& v,double k){
	return ３Ｄベクトル型(v.Ｘ/k,v.Ｙ/k,v.Ｚ/k);
}
//内積 ３Ｄベクトル型*３Ｄベクトル型
double operator*(const ３Ｄベクトル型& u,const ３Ｄベクトル型& v){
	return u.Ｘ*v.Ｘ+u.Ｙ*v.Ｙ+u.Ｚ*v.Ｚ;
}
//外積 ３Ｄベクトル型%３Ｄベクトル型
３Ｄベクトル型 operator%(const ３Ｄベクトル型& u,const ３Ｄベクトル型& v){
	３Ｄベクトル型 w;
	w.Ｘ=u.Ｙ*v.Ｚ-u.Ｚ*v.Ｙ;
	w.Ｙ=u.Ｚ*v.Ｘ-u.Ｘ*v.Ｚ;
	w.Ｚ=u.Ｘ*v.Ｙ-u.Ｙ*v.Ｘ;
	return w;
}

//２つのベクトルのなす角
double 角度(const ３Ｄベクトル型& u,const ３Ｄベクトル型& v){

	if (u.長さ() == 0 || v.長さ() == 0) {
		return 0;
	}

	double cos =u*v/(u.長さ()*v.長さ());
	return double(acos(cos)/M_PI*180);
}

//２点間座標の差
３Ｄベクトル型 operator-(３Ｄ位置型 &p1, ３Ｄ位置型 &p2) {
	３Ｄベクトル型 v;
	v.Ｘ = p1.Ｘ - p2.Ｘ;
	v.Ｙ = p1.Ｙ - p2.Ｙ;
	v.Ｚ = p1.Ｚ - p2.Ｚ;
	return v;
}
