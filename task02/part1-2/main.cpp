#include <iostream>
#include<complexnumber.h>

using namespace std;

int main()
{



    cout << endl << "Task02 - Konstruktoren/Initialisierer:" << endl << endl
         << " -- Part 1-1!" << endl
         << __cplusplus << endl;

    ComplexNumber c1;
    ComplexNumber c2(2.2,3.3);




    // Ausgabe c1

    //Standart - Zufällig
    cout << endl
         << "standartx: " << c1.standart << endl;        //Standart initialisierung
                                                       //Inhalt erscheint zufällig da nicht defniiert
    //Allgemein objekt(typ x, typ y):mx(x),..{}
    cout << endl
         << "Allgemein x: " << c2.allgemeinx << endl        //Standart initialisierung
         << "Allgemein y: " << c2.allgemeiny << endl;          //Inhalt erscheint zufällig da nicht defniiert

    //In Class
    cout << endl
         << "InClass x: " << c1.inclassx << endl        //Standart initialisierung
         << "InClass y: " << c1.inclassy << endl;          //Inhalt erscheint zufällig da nicht defniiert

    return 0;
}

