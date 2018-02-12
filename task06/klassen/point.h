#pragma once
//C++
#include <string>
#include <iosfwd>

class Point
{
//private


    // normale member
    int x,y;
    std::string color{"black"};
    //zähler -> seriennummer erzeugung aus diesem
    static int anzahl;
    const int serienNr;

    //friends bekanntmachungen der freien Funktionen:
    friend std::ostream& operator <<(std::ostream& outputStream, Point& point);
    friend Point operator+(const Point& a, const Point& b);

    //Konstruktor - Initialisierung der Datenelemente
    Point(int x, int y , const std::string& color);



public:
    //Konstruktor -> delegiert an privaten Konstruktor der alles initialisiert
    Point(int x = 0, int y = 0);
    Point(const Point& p);

    Point& operator=(const Point& other);

    //getter
    int getX() const;  //kein const oder referenz da hier kopie bearbeitet werden soll
    int getY() const;
    const std::string& getColor() const;
    const int& getSerialNr() const;

    //setter
    Point& setX(const int& xIn );
    Point& setY(const int& yIn);
    // void setColor(const std::string& colorIn);
    std::string toSVG() const;

};

//Öffentliche Schnittstelle
std::ostream& operator<<(std::ostream& outputStream,const Point& point);
Point  operator+(const Point& a,const Point& b);


