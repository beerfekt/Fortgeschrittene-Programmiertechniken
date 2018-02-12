#include "complexnumber.h"
#include <sstream>



ComplexNumber::ComplexNumber(double img, double real, std::string color): img(img), real(real), color(color){}
ComplexNumber::~ComplexNumber(){};

void ComplexNumber::setImg(const double& imgIn){
    img = imgIn;
}

void ComplexNumber::setReal(const double& realIn){
    real = realIn;
}

double ComplexNumber::getImg()const{
    return img;
}

double ComplexNumber::getReal()const{
    return real;
}


std::string ComplexNumber::getColor()const{
    return color;
}


std::ostream& operator<<(std::ostream& outputStream,const ComplexNumber& c){
    outputStream <<"ComplexNumber: ["<< c.img << ", " << c.real << "]\n";
    return outputStream;
}

ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b){
    return ComplexNumber(a.img+b.img, a.real+b.real, b.color);
}
