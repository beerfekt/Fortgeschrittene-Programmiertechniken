#pragma once


class ComplexNumber {

    double img;
    double real{0.0};

public:

    ComplexNumber();
    ComplexNumber(double img, double real = 0.0);

    double getImg() const;
    double getReal() const;

    void setImg(double img);
    void setReal(double real);

};
