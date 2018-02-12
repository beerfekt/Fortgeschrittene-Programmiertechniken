#include "point.h"
#include <sstream>


int Point::anzahl = 0;


//private Konstruktor
Point::Point(int x, int y, const std::string& color ):
                            x(x),
                            y(y),
                            color(color),
                            serienNr(++anzahl)
{};


//Öffentlicher Konstruktor -> delegiert an Privaten
Point::Point(int x, int y): Point(x,y, "black")
{}

Point::Point(const Point& p): Point(p.x, p.y, p.color){}




//GETTERS

int Point::getX() const{
    return x;
};

int Point::getY() const{
    return y;
};

const std::string& Point::getColor() const{
    return color;
};


const int& Point::getSerialNr() const {
    return serienNr;
}



//SETTERS

Point& Point::setX(const int& xIn){
    x = xIn;
    return *this; //this ist ein pointer der vorher dereferenziert werden muss,
}                 //Um dann als Referenz weitergegeben werden kann


Point& Point::setY(const int& yIn){
    y = yIn;
    return *this;  //spuckt sich selbst wieder aus zwecks verkettung von mutatoren
}




std::string Point::toSVG() const{
    std::string svg ="<circle cx =\"" + std::to_string(x)  + "\" " +
                     "cy =\"" +std::to_string(y) + "\" " +
                     "r =\"" + std::to_string(20) + "\" " +
                     "stroke =\"" + color +  "\" " +
                     "fill =\"" + color +  "\" " +
                     "/>" ;
    return svg; //Kopie notwendig!
}


//kopie mit neuer seriennummer (Verknüpft mit konstruktor Point(const Point& p)
Point& Point::operator=(const Point& other)  {
    if ( &other != this) {
        x = other.x;
        y = other.y;
        color = other.color;
    }
    return *this;
}






//Öffentliche Schnittstelle:

std::ostream& operator<<(std::ostream& outputStream, Point& point){
  outputStream << "Point: seriennr(" << point.serienNr  <<  ")  [" << point.x << ", " << point.y << "] " << "(" << point.color << ")\n";
  return outputStream;
}


Point operator+(const Point& a,const Point& b) {
    return Point(a.x+b.x,a.y+b.y);
}





