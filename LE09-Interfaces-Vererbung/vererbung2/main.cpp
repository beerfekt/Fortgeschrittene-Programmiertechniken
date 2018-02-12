#include <iostream>

using namespace std;




//-------------------  Person (base)  --------------------



class Person
{

protected:
    string name;

public:
    Person(string name = "max muster");
    void statisch() const;
    virtual void dynamisch() const; //Überschrieben
};



                   //......................

Person::Person(string name)
    : name(name)
{}

void Person::statisch()const{
    cout << name << endl;
}

void Person::dynamisch()const{
   cout << name << endl;
}



//-------------------  Mitarbeiter (derived)  --------------------


class Mitarbeiter : public Person  //erbt von Person
{
    long sozialNr;

public:
    Mitarbeiter(long sozialNr = 0);
    void statisch() const;
    virtual void dynamisch() const override;
};

                   //......................

Mitarbeiter::Mitarbeiter(long sozialNr): sozialNr(sozialNr)
{}


void Mitarbeiter::statisch() const {
    Person::statisch();
    cout << sozialNr << endl;
}

void Mitarbeiter::dynamisch()const{
   cout << name    << endl;
   cout << sozialNr << endl;
}








int main()
{
    cout << "Hello World!" << endl;

    //static
    Mitarbeiter m;
   // m.statisch();  //statische typen bestimmen welche funktion genommen wird

    m.dynamisch();



    return 0;
}
