#include "point.h"
#include <sstream>
#include <memory>

int Point::counter = 0;

//Konstruktoren
//Haupt/private
Point::Point(int x, int y,const std::string& color)
        : mx(x),
          my(y),
          mColor(color),
          serial(++counter)
{}

//delegiert an haupt
Point::Point(int x, int y)
    : Point(x,y,"schwarz")  //wichtig schwarz dazu, sonst redef.
{}

//Kopiekonstruktor
Point::Point(const Point& other)
  : Point(other.mx,other.my,"schwarz")
{}



//Getter (passed by value)

int Point::getX() const{
    return mx;
};

int Point::getY() const{
    return my;
};


//

Point& Point::setX(const int& x){
    mx = x;
    return *this;
}





//------- Operatoren

Point& Point::operator=(const Point& other){
/*
 //Version 1 ohne unique_ptr

    if (this != &other) {
        mx = other.mx;
        my = other.my;
        mColor = other.mColor;
    }
*/

    //besser mit swap

    Point copy(other);  //Kopie
    swap(copy);         //durch swappen obsolet
    return *this;       //lebensdauer ende der copy
}



//------ vertauschen

void Point::swap(Point& other){
  using std::swap;
  swap(mx,other.mx);
  swap(my,other.my);
}




// ------- Freie

std::ostream& operator<<(std::ostream& out, const Point& p){
    out << "Point #" << p.serial << " [" << p.mx << ", " << p.my << "] \n";
    return out;
}


Point operator+(const Point& a, const Point& b){
    return Point( (a.mx + b.mx), (a.my + b.my) );
}

bool operator==(const Point& a, const Point b){
     if (   a.mx == b.mx
         && a.my == b.my
         && a.serial == b.serial
         && a.mColor == b.mColor) return true;
     return false;
}
