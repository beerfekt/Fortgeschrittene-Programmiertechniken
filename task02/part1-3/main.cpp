#include <iostream>
#include <complexnumber.h>

using namespace std;

int main()
{
    cout << endl
         << "Task02 - Part1.3 - Zugriffsspezifizierer" << endl
         << endl;

    ComplexNumber c2(1.1,2.2);

    //In Class
    cout << endl
         << "InClass x: " << c2.getImg() << endl        //Standart initialisierung
         << "InClass y: " << c2.getReal() << endl;          //Inhalt erscheint zufällig da nicht defniiert

    return 0;
}
