#include "�Q�c�ʒu���^.h"

#include <windows.h>

//��r���Z�q
bool �Q�c�ʒu�^::operator==(const �Q�c�ʒu�^& v ) const{
    return (�w == v.�w) && (�x == v.�x);
}
bool �Q�c�ʒu�^::operator!=(const �Q�c�ʒu�^& v ) const{
    return !(*this == v);
}
//������Z�q
�Q�c�ʒu�^& �Q�c�ʒu�^::operator=(const �Q�c�ʒu�^& v){
	this->�w=v.�w;
	this->�x=v.�x;
	return *this;
}

//*----------------------�����o�֐��̎���--------------------------*//
�Q�c�x�N�g���^::�Q�c�x�N�g���^(){ �w = �x = 0; }
�Q�c�x�N�g���^::�Q�c�x�N�g���^(double �w����, double �x����){
	this->�w=�w����;
	this->�x=�x����;
}
�Q�c�x�N�g���^::�Q�c�x�N�g���^(�Q�c�ʒu�^ pos){
	this->�w=pos.�w;
	this->�x=pos.�x;
}

//������Z�q
�Q�c�x�N�g���^& �Q�c�x�N�g���^::operator=(const �Q�c�x�N�g���^& v){
	this->�w=v.�w;
	this->�x=v.�x;
	return *this;
}
//�P�����Z�q
�Q�c�x�N�g���^& �Q�c�x�N�g���^::operator+=(const �Q�c�x�N�g���^& v){
	 this->�w += v.�w;
	 this->�x += v.�x;
	 return *this;
}
�Q�c�x�N�g���^& �Q�c�x�N�g���^::operator-=(const �Q�c�x�N�g���^& v){
	 this->�w -= v.�w;
	 this->�x -= v.�x;
	 return *this;
}
�Q�c�x�N�g���^& �Q�c�x�N�g���^::operator*=(double k){
	 this->�w *= k;
	 this->�x *= k;
	 return *this;
}
�Q�c�x�N�g���^& �Q�c�x�N�g���^::operator/=(double k){
	this->�w /= k;
	this->�x /= k;
	return *this;
}
�Q�c�x�N�g���^ �Q�c�x�N�g���^::operator+()const{		//+�Q�c�x�N�g���^
	return *this;
}
�Q�c�x�N�g���^ �Q�c�x�N�g���^::operator-()const{		//-�Q�c�x�N�g���^
	return �Q�c�x�N�g���^(-�w,-�x);
}
//�Y�������Z�q
double& �Q�c�x�N�g���^::operator[](int i){
	if(i == 0){
		return �w;
	}
	else if(i == 1){
		return �x;
	}
	else{
		return �w;
	}
}
//��r���Z�q
bool �Q�c�x�N�g���^::operator==(const �Q�c�x�N�g���^& v ) const {
    return (�w == v.�w) && (�x == v.�x);
}
bool �Q�c�x�N�g���^::operator!=(const �Q�c�x�N�g���^& v ) const {
    return !(*this == v);
}
//�׃N�g���̒���
double �Q�c�x�N�g���^::����() const {
	return pow((double)(�w*�w+�x*�x),(double)0.5f);
}
//���K��(�P�ʃx�N�g����)
void �Q�c�x�N�g���^::���K��(){
	if ( ����() == 0 ) {
		MessageBox(NULL, "�������O�̃x�N�g��(=�����������x�N�g��)��P�ʃx�N�g�������悤�Ƃ��܂����B�����O���Z�ŃG���[�ƂȂ�܂��B","�������O�̃x�N�g��(=�����������x�N�g��)��P�ʃx�N�g�������悤�Ƃ��܂����B�����O���Z�ŃG���[�ƂȂ�܂��B", NULL);
	}

	*this /= ����();
}
//*----------------------�O���[�o���֐��̎���--------------------------*//
//�񍀉��Z�q�̒�`
//�Q�c�x�N�g���^+�Q�c�x�N�g���^
�Q�c�x�N�g���^ operator+(const �Q�c�x�N�g���^& u,const �Q�c�x�N�g���^& v){
	�Q�c�x�N�g���^ w;
	w.�w=u.�w+v.�w;
	w.�x=u.�x+v.�x;
	return w;
}
//�Q�c�x�N�g���^-�Q�c�x�N�g���^
�Q�c�x�N�g���^ operator-(const �Q�c�x�N�g���^& u,const �Q�c�x�N�g���^& v){
	�Q�c�x�N�g���^ w;
	w.�w=u.�w-v.�w;
	w.�x=u.�x-v.�x;
	return w;
}
//double*�Q�c�x�N�g���^
�Q�c�x�N�g���^ operator*(double k,const  �Q�c�x�N�g���^& v){
	return �Q�c�x�N�g���^(k*v.�w,k*v.�x);
}
//�Q�c�x�N�g���^*double
�Q�c�x�N�g���^ operator*(const �Q�c�x�N�g���^& v,double k){
	return �Q�c�x�N�g���^(v.�w*k,v.�x*k);
}
//�Q�c�x�N�g���^/double
�Q�c�x�N�g���^ operator/(const �Q�c�x�N�g���^& v,double k){
	return �Q�c�x�N�g���^(v.�w/k,v.�x/k);
}
//���� �Q�c�x�N�g���^*�Q�c�x�N�g���^
double operator*(const �Q�c�x�N�g���^& u,const �Q�c�x�N�g���^& v){
	return u.�w*v.�w+u.�x*v.�x;
}

//�O�� �Q�c�x�N�g���^%�Q�c�x�N�g���^
double operator%(const �Q�c�x�N�g���^& u,const �Q�c�x�N�g���^& v){
	�Q�c�x�N�g���^ w;
	return u.�w*v.�x-u.�x*v.�w;
}

//�Q�̃x�N�g���̂Ȃ��p
double �p�x(const �Q�c�x�N�g���^& u,const �Q�c�x�N�g���^& v){

	if (u.����() == 0 || v.����() == 0) {
		return 0;
	}

	double cos =u*v/(u.����()*v.����());
	return double(acos(cos)/M_PI*180);
}

//�Q�_�ԍ��W�̍�
�Q�c�x�N�g���^ operator-(�Q�c�ʒu�^ &p1, �Q�c�ʒu�^ &p2) {
	�Q�c�x�N�g���^ v;
	v.�w = p1.�w - p2.�w;
	v.�x = p1.�x - p2.�x;
	return v;
}


// �x�N�g���𕶎��񉻂��邪�A������k�n�i�W���ʁj�ŕ����񉻁B
string Get_�W���ʕ�����(�Q�c�x�N�g���^ v) {

	if ( v.����() == 0 ) {
		return "������";
	}

	double ���ς̍ő� = -1; // �^�t����̃X�^�[�g
	string ������ = "";

	//�@�W�̕����́u�P�ʃx�N�g���v��p�ӂ��āA�u�Ŋ��邩��̃x�N�g���v�Ƃ̓��ς��ő�̂��̂����̗p����B
	// �P�ʃx�N�g�����u�̓��ς��P�ɋ߂��قǁi���Ȃ킿�傫���قǁj�Ƃ������Ƃ́A�Q�̃x�N�g���̕����͓��������ł���B
	// �t�Ɍ����ΐ^�t�ł���قǍŏ��i���Ȃ킿-1)�ɋ߂Â��B
	�Q�c�x�N�g���^ i(0,-1); // �k�Ɣ�r
	if ( i * v > ���ς̍ő�) {
		���ς̍ő� = i * v;
		������ = "�k";
	}

	i = �Q�c�x�N�g���^(0,1); // ��Ɣ�r
	if ( i * v > ���ς̍ő�) {
		���ς̍ő� = i * v;
		������ = "��";
	}

	i = �Q�c�x�N�g���^(1,0); // ���Ɣ�r
	if ( i * v > ���ς̍ő�) {
		���ς̍ő� = i * v;
		������ = "��";
	}

	i = �Q�c�x�N�g���^(-1,0); // ���Ɣ�r
	if ( i * v > ���ς̍ő�) {
		���ς̍ő� = i * v;
		������ = "��";
	}

	i = �Q�c�x�N�g���^(1,-1); // ���k�Ɣ�r
	i.���K��(); // �P�ʃx�N�g����
	if ( i * v > ���ς̍ő�) {
		���ς̍ő� = i * v;
		������ = "�k��";
	}

	i = �Q�c�x�N�g���^(-1,-1); // ���k�Ɣ�r
	i.���K��(); // �P�ʃx�N�g����
	if ( i * v > ���ς̍ő�) {
		���ς̍ő� = i * v;
		������ = "�k��";
	}

	i = �Q�c�x�N�g���^(1,1); // ����Ɣ�r
	i.���K��(); // �P�ʃx�N�g����
	if ( i * v > ���ς̍ő�) {
		���ς̍ő� = i * v;
		������ = "�쓌";
	}

	i = �Q�c�x�N�g���^(-1,1); // ����Ɣ�r
	i.���K��(); // �P�ʃx�N�g����
	if ( i * v > ���ς̍ő�) {
		���ς̍ő� = i * v;
		������ = "�쐼";
	}

	return ������;
}



// �x�N�g���𕶎��񉻂��邪�A������k�n�i�S���ʁj�ŕ����񉻁B
string Get_�S���ʕ�����(�Q�c�x�N�g���^ v) {

	if ( v.����() == 0 ) {
		return "������";
	}

	double ���ς̍ő� = -1; // �^�t����̃X�^�[�g
	string ������ = "";

	//�@�S�̕����́u�P�ʃx�N�g���v��p�ӂ��āA�u�Ŋ��邩��̃x�N�g���v�Ƃ̓��ς��ő�̂��̂����̗p����B
	// �P�ʃx�N�g�����u�̓��ς��P�ɋ߂��قǁi���Ȃ킿�傫���قǁj�Ƃ������Ƃ́A�Q�̃x�N�g���̕����͓��������ł���B
	// �t�Ɍ����ΐ^�t�ł���قǍŏ��i���Ȃ킿-1)�ɋ߂Â��B
	�Q�c�x�N�g���^ i(0,-1); // �k�Ɣ�r
	if ( i * v > ���ς̍ő�) {
		���ς̍ő� = i * v;
		������ = "�k";
	}

	i = �Q�c�x�N�g���^(0,1); // ��Ɣ�r
	if ( i * v > ���ς̍ő�) {
		���ς̍ő� = i * v;
		������ = "��";
	}

	i = �Q�c�x�N�g���^(1,0); // ���Ɣ�r
	if ( i * v > ���ς̍ő�) {
		���ς̍ő� = i * v;
		������ = "��";
	}

	i = �Q�c�x�N�g���^(-1,0); // ���Ɣ�r
	if ( i * v > ���ς̍ő�) {
		���ς̍ő� = i * v;
		������ = "��";
	}

	return ������;
}
