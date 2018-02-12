#include <iostream>
#include <point.h>                 //Nur header point.h includieren
using namespace std;

int main()
{
    Point p(1,2);

    cout << "Ausgabe-Operator_Ueberladen" << __cplusplus
         << endl
         << p << endl;           //Operator kann verwendet werden

    return 0;
}
