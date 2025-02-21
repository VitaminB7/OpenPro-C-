# OpenPro-C-
รายงานตัว01

double ComplexNumber::abs(){
    return sqrt(real*real+imag*imag);
}
		
double ComplexNumber::angle(){
    return atan2(imag,real)* 180 / M_PI;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	double r,i;
	r = real*c.real + imag * -c.imag ;
	i = real*c.imag +imag*c.real ;
	return ComplexNumber(r,i);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	double r,i;
	r = (real*c.real + imag * c.imag)/(c.real*c.real + c.imag*c.imag);
	i = (imag*c.real - real*c.imag)/(c.real*c.real + c.imag*c.imag);
	return ComplexNumber(r,i);
}

ostream & operator<<(ostream &os,const ComplexNumber &c){
    if(c.real == 0 && c.imag != 0) return os<<c.imag<<"i";
    else if(c.real != 0 && c.imag == 0) return os<<c.real;
    else if(c.real == 0 && c.imag == 0) return os<<"0";
    if(c.imag>=0)return os<<c.real<<"+"<<c.imag<<"i";
    return os<<c.real<<c.imag<<"i";
}

ComplexNumber operator+(double d,const ComplexNumber &c){
	return ComplexNumber(d+c.real,c.imag);
}

ComplexNumber operator-(double d,const ComplexNumber &c){
	return ComplexNumber(d-c.real,0-c.imag);
}

ComplexNumber operator*(double d,const ComplexNumber &c){
	return ComplexNumber(d*c.real,d*c.imag);
}

ComplexNumber operator/(double d,const ComplexNumber &c){
	ComplexNumber a(d,0);
	return a/c;
}

bool ComplexNumber::operator==(const ComplexNumber &c){
	if(real==c.real && imag==c.imag)return 1;
	return 0;
}	

bool operator==(double d,const ComplexNumber &c){
	if(d==c.real && 0==c.imag) return 1;
	return 0;
}
