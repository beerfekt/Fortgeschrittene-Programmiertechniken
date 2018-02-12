#include <iostream>

using namespace std;




//-------------------  Person (base)  --------------------


class Person
{
    string name;

    //[...]

    void ausgabe() const;

};



 //[...]

void Person::ausgabe()const{
    cout << name << endl;
}



//-------------------  Mitarbeiter (derived)  --------------------


class Mitarbeiter : public Person  //erbt von Person
{
    long sozialNr;

    //[...]

    void ausgabe() const;
};





void Mitarbeiter::ausgabe() const {
    Person::ausgabe();           //Oberfunktion basis wird aufgerufen
    cout << sozialNr << endl;
}






int main()
{
    cout << "Hello World!" << endl;

    Mitarbeiter m;
    m.ausgabe();  //beies basis und erbende klasse wird ausgegeben

    return 0;
}

