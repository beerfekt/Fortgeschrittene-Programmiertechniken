#include "point.h"
#include <sstream>                //vorraussetzung

Point::Point(int x, int y): x(x),y(y)
{}


int Point::getX() const{
    return x;
}

int Point::getY() const{
    return y;
}

//mein
std::ostream& operator<<(std::ostream& outputStream, const Point& p){
    outputStream << "Point: [" << p.getX() << ", " << p.getY() << "]" ;
    return outputStream;
}




