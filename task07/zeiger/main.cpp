#include <iostream>
#include <string>
#include "/home/beer/workspace/progII/task06/klassen/point.h"

using namespace std;



//freie Funktion - Deklaration

int* copyValue(int* zeiger);
int*& passReference(int*& zeiger);
void print(const string& name, int*& zeiger) ;
void print(const string& name,const int*const* zeiger) ;
void test1(const int* zeiger){};
void test2(int ** ){};




//Testfunktion
int multiplikation(int a, int b){
    return a*b;
}


//Checked Pointer Idiom, zeigt Pointer auf nullptr oder ist er gültig?
bool pointerIdiom(Point* point){
   if (point) return true;
   return false;
}








int main()
{
    cout << "Zeiger!" << __cplusplus << endl;



    //Grundlegendes:

    int x = 4;    //alle zeiger werden auf diesen int zeigen (direkt oder über zwischenzeiger)
    int *z = &x;  //zeiger y zeigt auf typ int mit dem inhalt 4
    int *z2 = z;   //zeiger z zeigt auf gleiche int wie zeiger y
    int& xReferenz = *z;  //dereferenzierter Pointer kann wieder referenziert werden


    cout << "int x : " << x << endl
         << " zeigerwert z : " << z << endl
         << " zeigerwert z2 : " << z2 << endl
         << "  Dereferenzierter Wert  "<< *z <<endl;







    //inhalte ändern: ---------------------------------------------
    z2 = & (++ *z2); //inhalt x +1
    print("z2 increment" , z2);






    //konstanten --------------------------------------------------


    int test = 3;

    //ziel      | zeiger                          ziel        |    zeiger
      int         *          cz  = &x;      //  veränderbar   |  veränderbar
      int         *  const   cz1 = &x;      //  veränderbar   |  konstant
      int const   *          cz2 = &test;      //  konstant      |  veränderbar
      int const   *  const   cz3 = &x;      //  kontsant      |  konstant

    //zeiger
    cz = cz1;     //   ja
    //cz1 = cz2 ;  //   nein
    print("test1",&cz1);
    *cz1 = *cz2;    // nein  -> gleiche adresse , anderer wert
    print("test1",&cz1);
    cz2 = cz1;    // ja

    cout << cz1 << endl;

    //inhalte
    int x2 = 6;
    //*cz1 = &x2; //zeiger-ändern nein
    *cz1 = x2;   //wert-ändern   ja
    cz2 = &x2;
    // cz3 = cz1; //nein, einmal zugewiesen, danach geht nix mehr








    //Uebung

    int               Wert1;           // eine int-Variable
    int               Wert2;           // noch eine int-Variable
    int const *       p1Wert = &Wert1; // Zeiger auf konstanten int
    int * const       p2Wert = &Wert1; // konstanter Zeiger auf int
    int const * const p3Wert = &Wert1; // konstanter Zeiger auf konstanten int



/*
    p1Wert  = &Wert2; // geht
    *p1Wert = Wert2;  // geht nicht, int konstant

    p2Wert  = &Wert2; // geht nicht, Zeiger konstant
    *p2Wert = Wert2;  // geht

    p3Wert  = &Wert2; // geht nicht, Zeiger konstant
    *p3Wert = Wert2;  // geht nicht, int konstant
*/



    //Zeigerwerte als Parameter:  ---------------------------------

    //allgemein:
    int* kopie = copyValue(z); //passed by value  (Wertkopie rein, wertkopie raus
    int* referenz = passReference(kopie);
    print("kopie", kopie);
    print("referenz", referenz);


    //non const zeiger auf funktion(const<zeiger>)
    int* z4 = &x;
    test1(z4);  //geht (aber würde man in die funktion eine referenz legen würde die funktion x zu const machen


    //zeiger auf zeiger
    int xc = 1;
    int * a = &xc;  // a -> x
    int **zeiger  = &a;  // b -> a -> x


    //zeiger auf zeiger auf konstante
    test2(zeiger);
    print( "b->a->x ", *zeiger);




    //UDT und Elementzugriff

    //Point zeiger
    Point p(50,40);                   //Point erstellen
    Point * point = &p;               //Zeiger setzen auf Point





    //Zugriff
    cout << point->toSVG() << endl;   //point->element
    cout << (*point).getX() << endl;  // =   (*point).element
    cout << *point << endl;           // ergibt dank überladener point << operator funktion die pretty ausgabe
    cout << pointerIdiom(point) << endl;  //Prüfung ob pointer auf null (nullptr) zeigt


// ANDERES (KEINE ZEIGER)

    //Delegation an privaten Konstruktor,
    //Erstellung eines Zählers samt seriennummer
    Point p2;
   // p2 = p;                         //kopieren ist dank const seriennummer nicht mehr drin


    //Verkettung von Mutatoren:
    p2.setX(2).setY(20);
    point->setX(80);








    print("ursprung" , z);
    return 0;
}















//Freie Funktionen - definitionen



// Passed By Value
int* copyValue(int* zeiger) { //WertKopie rein
    return zeiger;                   //Wertkopie raus
}


//Passed By Reference
//Referenz zu Pointer      int*&  pointer
int*& passReference(int*& zeiger) {
    return zeiger;
}


void print(const string& name, int*& zeiger) {
    cout << endl
         << "Zeiger: " << name << endl
         << "- Adresse: " << zeiger << endl
         << "- Dereferenzierter Wert  "<< *zeiger << endl
         << endl;
}


void print(const string& name,const int*const* zeiger) {
    cout << endl
         << "Zeiger: " << name << endl
         << "- Adresse: " << *zeiger << endl
         << "- Dereferenzierter Wert  "<< **zeiger << endl
         << endl;
}


