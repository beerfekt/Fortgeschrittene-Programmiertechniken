#pragma once
#include <iosfwd>


class ComplexNumber {

    double img;
    double real;
    friend std::ostream& operator<<(std::ostream& outputStream, const ComplexNumber& c);

public:

    ComplexNumber(double img = 0.0, double real = 0.0);

    double getImg() const;
    double getReal() const;

    void setImg(double img);
    void setReal(double real);

};

std::ostream& operator<<(std::ostream& outputStream,const ComplexNumber& c);
