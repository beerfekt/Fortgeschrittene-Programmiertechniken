#include "point.h"
#include <sstream>

Point::Point(int x, int y): x(x),y(y)
{}


int Point::getX() const{
    return x;
}

int Point::getY() const{
    return y;
}

//Freie Funktion
Point add(const Point& a,const Point& b){
    return Point(a.x + b.x, a.y+b.y);     //Funktion hat dank friend deklaration direkten zugriff auf private
}



