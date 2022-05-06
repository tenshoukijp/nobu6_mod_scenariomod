#include "�Q�[���f�[�^�\��.h"


//��r���Z�q
bool �R�c�ʒu�^::operator==(const �R�c�ʒu�^& v ) const{
    return (�w == v.�w) && (�x == v.�x) && (�y == v.�y);
}
bool �R�c�ʒu�^::operator!=(const �R�c�ʒu�^& v ) const{
    return !(*this == v);
}
//������Z�q
�R�c�ʒu�^& �R�c�ʒu�^::operator=(const �R�c�ʒu�^& v){
	this->�w=v.�w;
	this->�x=v.�x;
	this->�y=v.�y;
	return *this;
}



//*----------------------�����o�֐��̎���--------------------------*//
�R�c�x�N�g���^::�R�c�x�N�g���^(){ �w = �x = �y = 0; }
�R�c�x�N�g���^::�R�c�x�N�g���^(double �w����, double �x����, double �y����){
	this->�w=�w����;
	this->�x=�x����;
	this->�y=�y����;
}
�R�c�x�N�g���^::�R�c�x�N�g���^(�R�c�ʒu�^ pos){
	this->�w=pos.�w;
	this->�x=pos.�x;
	this->�y=pos.�y;
}
//������Z�q
�R�c�x�N�g���^& �R�c�x�N�g���^::operator=(const �R�c�x�N�g���^& v){
	this->�w=v.�w;
	this->�x=v.�x;
	this->�y=v.�y;
	return *this;
}
//�P�����Z�q
�R�c�x�N�g���^& �R�c�x�N�g���^::operator+=(const �R�c�x�N�g���^& v){
	 this->�w += v.�w;
	 this->�x += v.�x;
	 this->�y += v.�y;
	 return *this;
}
�R�c�x�N�g���^& �R�c�x�N�g���^::operator-=(const �R�c�x�N�g���^& v){
	 this->�w -= v.�w;
	 this->�x -= v.�x;
	 this->�y -= v.�y;
	 return *this;
}
�R�c�x�N�g���^& �R�c�x�N�g���^::operator*=(double k){
	 this->�w *= k;
	 this->�x *= k;
	 this->�y *= k;
	 return *this;
}
�R�c�x�N�g���^& �R�c�x�N�g���^::operator/=(double k){
	this->�w /= k;
	this->�x /= k;
	this->�y /= k;
	return *this;
}
�R�c�x�N�g���^ �R�c�x�N�g���^::operator+()const{		//+�R�c�x�N�g���^
	return *this;
}
�R�c�x�N�g���^ �R�c�x�N�g���^::operator-()const{		//-�R�c�x�N�g���^
	return �R�c�x�N�g���^(-�w,-�x,-�y);
}
//�Y�������Z�q
double& �R�c�x�N�g���^::operator[](int i){
	if(i == 0){
		return �w;
	}
	else if(i == 1){
		return �x;
	}
	else if(i == 2){
		return �y;
	}
	else{
		return �w;
	}
}
//��r���Z�q
bool �R�c�x�N�g���^::operator==(const �R�c�x�N�g���^& v ) const {
    return (�w == v.�w) && (�x == v.�x) && (�y == v.�y);
}
bool �R�c�x�N�g���^::operator!=(const �R�c�x�N�g���^& v ) const {
    return !(*this == v);
}
//�׃N�g���̒���
double �R�c�x�N�g���^::����() const {
	return pow((double)(�w*�w+�x*�x+�y*�y),(double)0.5f);
}
//���K��(�P�ʃx�N�g����)
void �R�c�x�N�g���^::���K��(){
	if ( ����() == 0 ) {
		MessageBox(NULL, "�������O�̃x�N�g��(=�����������x�N�g��)��P�ʃx�N�g�������悤�Ƃ��܂����B�����O���Z�ŃG���[�ƂȂ�܂��B","�������O�̃x�N�g��(=�����������x�N�g��)��P�ʃx�N�g�������悤�Ƃ��܂����B�����O���Z�ŃG���[�ƂȂ�܂��B", NULL);
	}

	*this /= ����();
}
//*----------------------�O���[�o���֐��̎���--------------------------*//
//�񍀉��Z�q�̒�`
//�R�c�x�N�g���^+�R�c�x�N�g���^
�R�c�x�N�g���^ operator+(const �R�c�x�N�g���^& u,const �R�c�x�N�g���^& v){
	�R�c�x�N�g���^ w;
	w.�w=u.�w+v.�w;
	w.�x=u.�x+v.�x;
	w.�y=u.�y+v.�y;
	return w;
}
//�R�c�x�N�g���^-�R�c�x�N�g���^
�R�c�x�N�g���^ operator-(const �R�c�x�N�g���^& u,const �R�c�x�N�g���^& v){
	�R�c�x�N�g���^ w;
	w.�w=u.�w-v.�w;
	w.�x=u.�x-v.�x;
	w.�y=u.�y-v.�y;
	return w;
}
//double*�R�c�x�N�g���^
�R�c�x�N�g���^ operator*(double k,const  �R�c�x�N�g���^& v){
	return �R�c�x�N�g���^(k*v.�w,k*v.�x,k*v.�y);
}
//�R�c�x�N�g���^*double
�R�c�x�N�g���^ operator*(const �R�c�x�N�g���^& v,double k){
	return �R�c�x�N�g���^(v.�w*k,v.�x*k,v.�y*k);
}
//�R�c�x�N�g���^/double
�R�c�x�N�g���^ operator/(const �R�c�x�N�g���^& v,double k){
	return �R�c�x�N�g���^(v.�w/k,v.�x/k,v.�y/k);
}
//���� �R�c�x�N�g���^*�R�c�x�N�g���^
double operator*(const �R�c�x�N�g���^& u,const �R�c�x�N�g���^& v){
	return u.�w*v.�w+u.�x*v.�x+u.�y*v.�y;
}
//�O�� �R�c�x�N�g���^%�R�c�x�N�g���^
�R�c�x�N�g���^ operator%(const �R�c�x�N�g���^& u,const �R�c�x�N�g���^& v){
	�R�c�x�N�g���^ w;
	w.�w=u.�x*v.�y-u.�y*v.�x;
	w.�x=u.�y*v.�w-u.�w*v.�y;
	w.�y=u.�w*v.�x-u.�x*v.�w;
	return w;
}

//�Q�̃x�N�g���̂Ȃ��p
double �p�x(const �R�c�x�N�g���^& u,const �R�c�x�N�g���^& v){

	if (u.����() == 0 || v.����() == 0) {
		return 0;
	}

	double cos =u*v/(u.����()*v.����());
	return double(acos(cos)/M_PI*180);
}

//�Q�_�ԍ��W�̍�
�R�c�x�N�g���^ operator-(�R�c�ʒu�^ &p1, �R�c�ʒu�^ &p2) {
	�R�c�x�N�g���^ v;
	v.�w = p1.�w - p2.�w;
	v.�x = p1.�x - p2.�x;
	v.�y = p1.�y - p2.�y;
	return v;
}
