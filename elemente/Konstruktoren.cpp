


//Header


#pragma once       

class Point       
{

                   
public:               
    int mX;        
    int mY; 

    Point();       //standart
    Point(double x, double y); //allgemeiner version 1
 
    //allgemeiner v2 : Vorgabewerte für Funktionsparameter und Funktionsüberladung
    Point (double x, double y = 9.9);  //wenn  Point c1(1.1) dann wird 2. wert auto. eingesetzt: ->  Point: 1.1, 9.9 weitere werte nach rechts benötigen vorgabwerte

};




//Klasse

#include <point.h>


   Point(){};                                //standart eigen
   Point(double x, double y):mX(x),mY(y){};  //allgemeiner k.


//Main

  Point p1;           // Standartkonstruktor
  Point p2(2.2,3.1);  //allgemeiner Konstruktor


