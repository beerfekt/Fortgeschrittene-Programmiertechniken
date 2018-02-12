#include <iostream>

#include "point.h"
#include "svg.h"
#include "complexnumber.h"

using namespace std;

int main()
{
    cout << "Klassen - Compiler-Version:  " << __cplusplus << endl << endl;

//Points

    //Points via Ausgabeoperator
    Point p0;
    Point p1(20,30);
          //p1.setColor("yellow");
    Point p2 (2,3);
          //p2.setColor("green");
    Point p4 = p1+p2;

    cout << p0 << p1 << p2 << p4 << endl;
    cout << endl << p1.toSVG() << endl;

    SVG ("test.svg", p2.toSVG());

//ComplexNumbers

   //Complex versuche/tests
    ComplexNumber c1;
    ComplexNumber c2(1.1);
    double y = 2.2;
    double& x = y;
    //wird y rückwirkend verändert (referenz)?
    c1.setReal(5.5);
    c2.setImg(x);
    c2.setReal(3.2);
    c1.setReal(x = 7.7+3.3);
    y =0;
    x = 3.3;

    cout << c1 << c2 << endl;
    cout << c1+c2 << endl;
    //addieren


   return 0;
}
