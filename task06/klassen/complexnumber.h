#pragma once
#include <string>
#include <iosfwd>

class ComplexNumber
{
    double img,real;
    std::string color;

    friend std::ostream& operator<<(std::ostream& outputStream, const ComplexNumber& c);
    friend ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b);

public:
    ComplexNumber(double img = 0.0, double real = 0.0, std::string color = "black");
    ~ComplexNumber();

    void setImg(const double& imgIn);
    void setReal(const double& realIn);

    double getImg()const;
    double getReal() const;
    std::string getColor() const;

};
//öffentliche Schnittstelle
//friend funktion:
std::ostream& operator<<(std::ostream& outputStream, const ComplexNumber& c);
ComplexNumber operator+(const ComplexNumber& a,const ComplexNumber& b);

