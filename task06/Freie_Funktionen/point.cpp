#include "point.h"

Point::Point(int x, int y): x(x),y(y)
{}


int Point::getX() const{
    return x;
}

int Point::getY() const{
    return y;
}

//Freie Funktion ohne Point::add -> kann ohne Bezug aufgerufen werden -> Kein Point.add(...) nötig
Point add(const Point& a,const Point& b){
    return Point(a.getX() + b.getX(), a.getY()+b.getY());
}
