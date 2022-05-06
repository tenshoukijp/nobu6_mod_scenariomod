#include "ƒQ[ƒ€ƒf[ƒ^\‘¢.h"


//”äŠr‰‰Zq
bool ‚R‚cˆÊ’uŒ^::operator==(const ‚R‚cˆÊ’uŒ^& v ) const{
    return (‚w == v.‚w) && (‚x == v.‚x) && (‚y == v.‚y);
}
bool ‚R‚cˆÊ’uŒ^::operator!=(const ‚R‚cˆÊ’uŒ^& v ) const{
    return !(*this == v);
}
//‘ã“ü‰‰Zq
‚R‚cˆÊ’uŒ^& ‚R‚cˆÊ’uŒ^::operator=(const ‚R‚cˆÊ’uŒ^& v){
	this->‚w=v.‚w;
	this->‚x=v.‚x;
	this->‚y=v.‚y;
	return *this;
}



//*----------------------ƒƒ“ƒoŠÖ”‚ÌÀ‘•--------------------------*//
‚R‚cƒxƒNƒgƒ‹Œ^::‚R‚cƒxƒNƒgƒ‹Œ^(){ ‚w = ‚x = ‚y = 0; }
‚R‚cƒxƒNƒgƒ‹Œ^::‚R‚cƒxƒNƒgƒ‹Œ^(double ‚w¬•ª, double ‚x¬•ª, double ‚y¬•ª){
	this->‚w=‚w¬•ª;
	this->‚x=‚x¬•ª;
	this->‚y=‚y¬•ª;
}
‚R‚cƒxƒNƒgƒ‹Œ^::‚R‚cƒxƒNƒgƒ‹Œ^(‚R‚cˆÊ’uŒ^ pos){
	this->‚w=pos.‚w;
	this->‚x=pos.‚x;
	this->‚y=pos.‚y;
}
//‘ã“ü‰‰Zq
‚R‚cƒxƒNƒgƒ‹Œ^& ‚R‚cƒxƒNƒgƒ‹Œ^::operator=(const ‚R‚cƒxƒNƒgƒ‹Œ^& v){
	this->‚w=v.‚w;
	this->‚x=v.‚x;
	this->‚y=v.‚y;
	return *this;
}
//’P€‰‰Zq
‚R‚cƒxƒNƒgƒ‹Œ^& ‚R‚cƒxƒNƒgƒ‹Œ^::operator+=(const ‚R‚cƒxƒNƒgƒ‹Œ^& v){
	 this->‚w += v.‚w;
	 this->‚x += v.‚x;
	 this->‚y += v.‚y;
	 return *this;
}
‚R‚cƒxƒNƒgƒ‹Œ^& ‚R‚cƒxƒNƒgƒ‹Œ^::operator-=(const ‚R‚cƒxƒNƒgƒ‹Œ^& v){
	 this->‚w -= v.‚w;
	 this->‚x -= v.‚x;
	 this->‚y -= v.‚y;
	 return *this;
}
‚R‚cƒxƒNƒgƒ‹Œ^& ‚R‚cƒxƒNƒgƒ‹Œ^::operator*=(double k){
	 this->‚w *= k;
	 this->‚x *= k;
	 this->‚y *= k;
	 return *this;
}
‚R‚cƒxƒNƒgƒ‹Œ^& ‚R‚cƒxƒNƒgƒ‹Œ^::operator/=(double k){
	this->‚w /= k;
	this->‚x /= k;
	this->‚y /= k;
	return *this;
}
‚R‚cƒxƒNƒgƒ‹Œ^ ‚R‚cƒxƒNƒgƒ‹Œ^::operator+()const{		//+‚R‚cƒxƒNƒgƒ‹Œ^
	return *this;
}
‚R‚cƒxƒNƒgƒ‹Œ^ ‚R‚cƒxƒNƒgƒ‹Œ^::operator-()const{		//-‚R‚cƒxƒNƒgƒ‹Œ^
	return ‚R‚cƒxƒNƒgƒ‹Œ^(-‚w,-‚x,-‚y);
}
//“Y‚¦š‰‰Zq
double& ‚R‚cƒxƒNƒgƒ‹Œ^::operator[](int i){
	if(i == 0){
		return ‚w;
	}
	else if(i == 1){
		return ‚x;
	}
	else if(i == 2){
		return ‚y;
	}
	else{
		return ‚w;
	}
}
//”äŠr‰‰Zq
bool ‚R‚cƒxƒNƒgƒ‹Œ^::operator==(const ‚R‚cƒxƒNƒgƒ‹Œ^& v ) const {
    return (‚w == v.‚w) && (‚x == v.‚x) && (‚y == v.‚y);
}
bool ‚R‚cƒxƒNƒgƒ‹Œ^::operator!=(const ‚R‚cƒxƒNƒgƒ‹Œ^& v ) const {
    return !(*this == v);
}
//‚×ƒNƒgƒ‹‚Ì’·‚³
double ‚R‚cƒxƒNƒgƒ‹Œ^::’·‚³() const {
	return pow((double)(‚w*‚w+‚x*‚x+‚y*‚y),(double)0.5f);
}
//³‹K‰»(’PˆÊƒxƒNƒgƒ‹‰»)
void ‚R‚cƒxƒNƒgƒ‹Œ^::³‹K‰»(){
	if ( ’·‚³() == 0 ) {
		MessageBox(NULL, "’·‚³‚ª‚O‚ÌƒxƒNƒgƒ‹(=•ûŒü‚ª–³‚¢ƒxƒNƒgƒ‹)‚ğ’PˆÊƒxƒNƒgƒ‹‰»‚µ‚æ‚¤‚Æ‚µ‚Ü‚µ‚½B–³ŒÀ‚OœZ‚ÅƒGƒ‰[‚Æ‚È‚è‚Ü‚·B","’·‚³‚ª‚O‚ÌƒxƒNƒgƒ‹(=•ûŒü‚ª–³‚¢ƒxƒNƒgƒ‹)‚ğ’PˆÊƒxƒNƒgƒ‹‰»‚µ‚æ‚¤‚Æ‚µ‚Ü‚µ‚½B–³ŒÀ‚OœZ‚ÅƒGƒ‰[‚Æ‚È‚è‚Ü‚·B", NULL);
	}

	*this /= ’·‚³();
}
//*----------------------ƒOƒ[ƒoƒ‹ŠÖ”‚ÌÀ‘•--------------------------*//
//“ñ€‰‰Zq‚Ì’è‹`
//‚R‚cƒxƒNƒgƒ‹Œ^+‚R‚cƒxƒNƒgƒ‹Œ^
‚R‚cƒxƒNƒgƒ‹Œ^ operator+(const ‚R‚cƒxƒNƒgƒ‹Œ^& u,const ‚R‚cƒxƒNƒgƒ‹Œ^& v){
	‚R‚cƒxƒNƒgƒ‹Œ^ w;
	w.‚w=u.‚w+v.‚w;
	w.‚x=u.‚x+v.‚x;
	w.‚y=u.‚y+v.‚y;
	return w;
}
//‚R‚cƒxƒNƒgƒ‹Œ^-‚R‚cƒxƒNƒgƒ‹Œ^
‚R‚cƒxƒNƒgƒ‹Œ^ operator-(const ‚R‚cƒxƒNƒgƒ‹Œ^& u,const ‚R‚cƒxƒNƒgƒ‹Œ^& v){
	‚R‚cƒxƒNƒgƒ‹Œ^ w;
	w.‚w=u.‚w-v.‚w;
	w.‚x=u.‚x-v.‚x;
	w.‚y=u.‚y-v.‚y;
	return w;
}
//double*‚R‚cƒxƒNƒgƒ‹Œ^
‚R‚cƒxƒNƒgƒ‹Œ^ operator*(double k,const  ‚R‚cƒxƒNƒgƒ‹Œ^& v){
	return ‚R‚cƒxƒNƒgƒ‹Œ^(k*v.‚w,k*v.‚x,k*v.‚y);
}
//‚R‚cƒxƒNƒgƒ‹Œ^*double
‚R‚cƒxƒNƒgƒ‹Œ^ operator*(const ‚R‚cƒxƒNƒgƒ‹Œ^& v,double k){
	return ‚R‚cƒxƒNƒgƒ‹Œ^(v.‚w*k,v.‚x*k,v.‚y*k);
}
//‚R‚cƒxƒNƒgƒ‹Œ^/double
‚R‚cƒxƒNƒgƒ‹Œ^ operator/(const ‚R‚cƒxƒNƒgƒ‹Œ^& v,double k){
	return ‚R‚cƒxƒNƒgƒ‹Œ^(v.‚w/k,v.‚x/k,v.‚y/k);
}
//“àÏ ‚R‚cƒxƒNƒgƒ‹Œ^*‚R‚cƒxƒNƒgƒ‹Œ^
double operator*(const ‚R‚cƒxƒNƒgƒ‹Œ^& u,const ‚R‚cƒxƒNƒgƒ‹Œ^& v){
	return u.‚w*v.‚w+u.‚x*v.‚x+u.‚y*v.‚y;
}
//ŠOÏ ‚R‚cƒxƒNƒgƒ‹Œ^%‚R‚cƒxƒNƒgƒ‹Œ^
‚R‚cƒxƒNƒgƒ‹Œ^ operator%(const ‚R‚cƒxƒNƒgƒ‹Œ^& u,const ‚R‚cƒxƒNƒgƒ‹Œ^& v){
	‚R‚cƒxƒNƒgƒ‹Œ^ w;
	w.‚w=u.‚x*v.‚y-u.‚y*v.‚x;
	w.‚x=u.‚y*v.‚w-u.‚w*v.‚y;
	w.‚y=u.‚w*v.‚x-u.‚x*v.‚w;
	return w;
}

//‚Q‚Â‚ÌƒxƒNƒgƒ‹‚Ì‚È‚·Šp
double Šp“x(const ‚R‚cƒxƒNƒgƒ‹Œ^& u,const ‚R‚cƒxƒNƒgƒ‹Œ^& v){

	if (u.’·‚³() == 0 || v.’·‚³() == 0) {
		return 0;
	}

	double cos =u*v/(u.’·‚³()*v.’·‚³());
	return double(acos(cos)/M_PI*180);
}

//‚Q“_ŠÔÀ•W‚Ì·
‚R‚cƒxƒNƒgƒ‹Œ^ operator-(‚R‚cˆÊ’uŒ^ &p1, ‚R‚cˆÊ’uŒ^ &p2) {
	‚R‚cƒxƒNƒgƒ‹Œ^ v;
	v.‚w = p1.‚w - p2.‚w;
	v.‚x = p1.‚x - p2.‚x;
	v.‚y = p1.‚y - p2.‚y;
	return v;
}
