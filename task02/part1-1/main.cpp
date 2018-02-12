#include <iostream>
#include<complexnumber.h>

using namespace std;

int main()
{
    cout << "Task02" << endl
         << " -- Part 1-1!" << endl
         << __cplusplus << endl;

    ComplexNumber complex1;
    ComplexNumber complex2();

    cout << endl
         << "Imaginärteil: " << complex1.img << endl        //Standart initialisierung
         << "Realteil: " << complex1.real << endl;          //Inhalt erscheint zufällig da nicht defniiert

    return 0;
}

