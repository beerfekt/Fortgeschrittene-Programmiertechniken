#include<complexnumber.h>

ComplexNumber::ComplexNumber(double img, double real):img(img), real(real) {};

//Getter
double ComplexNumber::getImg() const {
    return img;
}

double ComplexNumber::getReal() const {
    return real;
}
