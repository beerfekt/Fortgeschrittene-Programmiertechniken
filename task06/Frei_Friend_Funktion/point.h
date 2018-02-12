#pragma once
#include <iosfwd>

class Point
{
    //Hier als friend bekanntgemacht. -Friend heißt: zugriff auf Private elemente
    friend Point add (const Point& a, const Point& b);

    int x,y;

public:
    Point(int x = 0, int y = 0);

    int getX() const;
    int getY() const;


};

//ÖFFENTLICHE SCHNITTSTELLE:
    //freie Funktionen

Point add (const Point& a, const Point& b);



