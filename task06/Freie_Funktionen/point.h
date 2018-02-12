#pragma once


class Point
{

    int x,y;

public:
    Point(int x = 0, int y = 0);

    int getX() const;
    int getY() const;


};

//HIER ÖFFENTLICHE SCHNITTSTELLE:
    //freie Funktionen hier deklarieren:

Point add (const Point& a, const Point& b);


