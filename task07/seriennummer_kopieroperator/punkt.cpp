#include "punkt.h"
#include <sstream>

//statische initialisierung
int Punkt::zaehler = 0;





//-------------------- Seriennummer ---------------------------

//Konstruktor
Punkt::Punkt(int x, int y, std::string color):mx(x),
                                              my(y),
                                              color(color),
                                              serienNr(++zaehler)
{}



//------------- Überschreiben des Operators -------------------

//Wichtig für Überschreiben des Operators (für neue seriennummer)
Punkt::Punkt(const Punkt& other): Punkt(other.mx,other.my, other.color){} //WICHTIG FÜR SNR


// Überschreiben des operators =
Punkt& Punkt::operator=(const Punkt& p){ //eigenes Objekt wird als non-const referenz zurückgegeben
    if (&p != this){
       mx = p.mx;
       my = p.my;
       color = p.color;
    }
    return *this;
}

//----------------------------------------------------------------







//Getter

int Punkt::getX() const{
   return mx;
};

int Punkt::getY() const{
  return my;
};

int Punkt::getSerie()const{
    return serienNr;
}

//Setter

Punkt& Punkt::setX(const int& x){
    mx = x;
    return *this;
};



//ÖFFENTLICHE Schnittstelle
std::ostream& operator<<(std::ostream& outputStream, const Punkt& p){
    outputStream << "\n Punkt: [ " << p.mx << ", " << p.my << "] serienNr [" << p.serienNr << "]";
    return outputStream;
}
