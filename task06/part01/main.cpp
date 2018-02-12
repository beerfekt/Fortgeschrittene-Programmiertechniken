#include <iostream>
#include <complexnumber.h>
#include <cmath>

using namespace std;


//FREIFE FUNKTION - Deklaration (wichtig)
double distance (const ComplexNumber& a,const ComplexNumber& b); //Freie Funktion, siehe cpp


int main()
{
    cout << "Hello World!" << __cplusplus << endl;

    ComplexNumber c1{1.1,1.2};
    ComplexNumber c2{2.1,2.2};

    cout << distance(c1,c2) << endl;

    return 0;
}

//FREIE FUNKTION - muss vorher über main deklariert sein!!!
double distance (const ComplexNumber& a,const ComplexNumber& b){
    double img = a.getImg() - b.getImg();
    double real= a.getReal() - b.getReal();
    return std::hypot(img, real); //gibt hypothenusenlänge aus
}
