#pragma once

#include <string>
#include <iosfwd>

class Point
{

    friend std::ostream& operator<<(std::ostream& out, const Point& p);
    friend Point operator+(const Point& a, const Point& b);
    friend bool operator==(const Point& a, const Point b);

    int mx, my;
    std::string mColor;

    const int serial;
    static int counter;
    Point(int x, int y, const std::string& color);

public:
    Point(int x = 0, int y = 0);
    Point(const Point& other);
 //getter
    int getX() const;
    int getY() const;
 //setter
    Point& setX(const int& x);
    Point& setY(const int& y);
 //Operatoren
    Point& operator=(const Point& other);
 //Vertauschen
    void swap(Point& other);

};

std::ostream& operator<<(std::ostream& out, const Point& p);
Point operator+(const Point& a, const Point& b);
bool operator==(const Point& a, const Point& b);


