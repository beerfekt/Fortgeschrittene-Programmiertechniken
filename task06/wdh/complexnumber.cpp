#include <complexnumber.h>
#include <sstream>



ComplexNumber::ComplexNumber(double img, double real):img(img),real(real) {
}

double ComplexNumber::getImg() const{
    return img;
}

double ComplexNumber::getReal()const{
 return real;
}



//public ohne Namensraum ComplexNumber::

std::ostream& operator<<(std::ostream& outputStream,const ComplexNumber& c){
    outputStream << "ComplexNumber: [" << c.img << ", " << c.real << " ] \n";
    return outputStream;
}






