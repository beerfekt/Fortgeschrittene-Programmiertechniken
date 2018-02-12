#pragma once
#include <iosfwd>    //vorraussetzung für ostream

class Point
{
    //friend deklaration der <<Operator Überladung
    friend std::ostream& operator<<(std::ostream& outputStream, const Point& p);
    int x,y;

public:
    Point(int x = 0, int y = 0);
    int getX() const;
    int getY() const;
};

//<< Operator Überladung in öffentlicher Schnittstelle
std::ostream& operator<<(std::ostream& outputStream, const Point& p);




