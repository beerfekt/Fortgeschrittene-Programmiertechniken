#include <complexnumber.h>


ComplexNumber::ComplexNumber(){}

ComplexNumber::ComplexNumber(double img, double real):real(real),img(img){
}

double ComplexNumber::getImg() const{
    return img;
}

double ComplexNumber::getReal()const{
 return real;
}




