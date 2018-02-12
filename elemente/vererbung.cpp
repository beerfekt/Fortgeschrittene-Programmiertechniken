#include <iostream>
using namespace std;






//-------------------  Person (base)  --------------------



class Person
{
    string name;

public:
    Person(string name = "max muster");
    string getName() const;

};



                   //......................

Person::Person(string name)
    : name(name)
{}

string Person::getName()const{
    return name;
}





//-------------------  Mitarbeiter (derived)  --------------------


class Mitarbeiter : public Person  //erbt von Person
{
    long sozialNr;

public:
    Mitarbeiter(long sozialNr = 0);
    long getSozialNr() const;
};

                   //......................

Mitarbeiter::Mitarbeiter(long sozialNr): sozialNr(sozialNr)
{}


long Mitarbeiter::getSozialNr() const {
    return sozialNr;
}






//-------------------- Main ---------------------------------

int main()
{
    cout << "LE09 - Vererbung " << endl;




    //*************************************
    //Vererbung - Basic

    Person p;
    cout << "Person: " << p.getName() << endl;

    Mitarbeiter m;
    cout << "Mitarbeiter: " << endl
         << "sozNr: " << m.getSozialNr() << endl
         << "name: "  << m.getName()     << endl;





    //*************************************
    //Dynamic Cast  x <-erbt- von

       // Person <- Mitarbeiter
       // Person <- Kunde
       // Teilnehmer <- Mitarbeiter und Kunde (Mehrfachvererbung)


    Mitarbeiter meier;
    Person *pperson = &meier;   //Bei anderen Datentypen geht das nicht
                                //NUR!! bei vererbungen

    cout << pperson->getName() << endl;


    Mitarbeiter *mmeier = dynamic_cast<Mitarbeiter*> (pperson); //Geht nicht -> nicht jede person ist mitarbeiter



    //Virtuelle Vererbung

    class Person {
      string name;
      // ...
    };

    class Mitarbeiter : public virtual Person { /* ... */ };
    class Kunde       : public virtual Person { /* ... */ };

    //weil beide virtaul -> werden hier teilobjekte verschmolzen
    class MitarbeiterUndKunde : public Mitarbeiter, public Kunde { /* ... */ };


    //[...]
}

