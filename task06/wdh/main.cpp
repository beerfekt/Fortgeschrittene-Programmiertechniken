#include <iostream>
#include <complexnumber.h>

using namespace std;

int main()
{



    cout << "WDH - Operator-ÜBerladung und friend funktion!" << __cplusplus << endl;

    ComplexNumber c1;
    ComplexNumber c2(1.1);
    ComplexNumber c3(2.2,3.3);

    cout << c1 << c2 << c3 << endl;
    return 0;


}
