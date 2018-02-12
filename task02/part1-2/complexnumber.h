#pragma


class ComplexNumber
{

public:

    // Standartinitialisierung: zufallswerte werden gesetzt
    double allgemeinx,allgemeiny;
    double standart;

    // In Class Initialisierer
    double inclassx{5.5};
    double inclassy= 3.3;

    //Konstruktoren
    //default eigen
    ComplexNumber();
    //allgemein
    ComplexNumber(double x, double y);
};


