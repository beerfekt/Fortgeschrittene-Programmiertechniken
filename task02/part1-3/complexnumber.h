#pragma once

class ComplexNumber {

public:

   //Allgemeiner Konstruktor ermöglicht Erstellung mit beliebigen Real- und Imaginärwerten
   ComplexNumber(double img, double real);

   //public getter Setter ermöglichen Ausgabe der private Elementattribute

   double getReal() const;
   double getImg() const;

//Zugriffsspezifizierer wurde auf private gesetzt

private:
       double img{0.0};
       double real=0.0;

};
