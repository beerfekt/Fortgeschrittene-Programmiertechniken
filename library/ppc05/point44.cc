/*
 * ++C - C++ introduction
 * Copyright (C) 2013, 2014, 2015, 2016, 2017 Wilhelm Meier <wilhelm.meier@hs-kl.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "point44.h"

#include "../lib/simpletest.h"
#include "math.h"

#include <cassert>
#include <cmath>
#include <sstream>

//[opcomp
bool operator==(const Point& p1, const Point& p2)
{
    return (Math::equal(p1.mX, p2.mX) && Math::equal(p1.mY, p2.mY));
}
bool operator!=(const Point& p1, const Point& p2)
{
    return !(p1 == p2);
}
//]
//[out
std::ostream& operator<<(std::ostream& outputStream, const Point& p)
{
    outputStream << "Point[" << p.mX << "," << p.mY << "," << p.mColor << "]";
    return outputStream; // <> Nach der Regel _reference-in / reference-out_ darf `outputStream` als Referenz zurückgegeben werden.
}
//]
double operator-(const Point& a, const Point& b)
{
    return std::hypot(a.mX - b.mX, a.mY - b.mY); // <> Auch hier ist der Zugriff auf die _privaten_ Elemente möglich
}

double distance(const Point& a, const Point& b)
{
    double dx = a.getX() - b.getX();
    double dy = a.getY() - b.getY();

    return std::hypot(dx, dy);
}

//[cartesian
Point::Point(XCoor x, YCoor y) : mX(x.mValue), mY(y.mValue)
{
}
//]
//[polar
Point::Point(Radius r, Angle phi) :
    mX(r.mValue * std::cos(phi.mRadiant)), // <> Berechnung der kartesichen Koordinaten aus den Polarkoordinaten
    mY(r.mValue * std::sin(phi.mRadiant))
{
}
//]
double Point::getX() const
{
    return mX;
}

double Point::getY() const
{
    return mY;
}

const std::string& Point::getColor() const
{
    return mColor;
}

std::string Point::toSVG() const
{
    std::string svgString = "<circle ";
    svgString += "cx=\"" + std::to_string(Math::toInt(mX)) + "\" ";
    svgString += "cy=\"" + std::to_string(Math::toInt(mY)) + "\" ";
    svgString += "r=\"" + std::to_string(mSVGRadius) + "\" ";
    svgString += "stroke=\"" + mColor + "\" ";
    svgString += "fill=\"" + mColor + "\" ";
    svgString +=  "/>";
    return svgString; // <> Ergebnisrückgabe als Wertkopie *notwendig*
}

int Point::svgRadius()
{
    return mSVGRadius;
}

void Point::setX(double x)
{
    mX = x;
}

void Point::setY(double y)
{
    mY = y;
}

void Point::move(double dx, double dy)
{
    mX += dx;
    mY += dy;
}

void Point::setColor(const std::string& color)
{
    mColor = color;
}

void Point::setColor(unsigned char r, unsigned char g, unsigned char b)
{
    mColor = "rgb(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + ")";
}

//[polar
Radius operator*(Radius a, Radius b)
{
    return Radius{a.mValue * b.mValue};
}

Radius operator*(double a, Radius b)
{
    return Radius{a * b.mValue};
}

Radius operator*(Radius a, double b)
{
    return Radius{a.mValue * b};
}

Radius::Radius(double r) : mValue(r)
{
    assert(r >= 0.0); // <> Sicherstellen eines validen Zustands im Konstruktor
}

Angle operator+(Angle a, Angle b)
{
    return {a.mRadiant + b.mRadiant};
}
//]


SIMPLETEST("Point ctor1") {
    Point p;

    if (!Math::equal(p.getX(), 0.0)) return false;
    if (!Math::equal(p.getY(), 0.0)) return false;

    return true;
};

SIMPLETEST("Point ctor2") {
    Point p{XCoor{1.0}, YCoor{2.0}};

    if (!Math::equal(p.getX(), 1.0)) return false;
    if (!Math::equal(p.getY(), 2.0)) return false;

    return true;
};

SIMPLETEST("Point ctor3") {
    Point p{XCoor{1.0}};

    if (!Math::equal(p.getX(), 1.0)) return false;
    if (!Math::equal(p.getY(), 0.0)) return false;

    return true;
};

SIMPLETEST("Point setX") {
    Point p;

    p.setX(1.0);
    if (!Math::equal(p.getX(), 1.0)) return false;
    if (!Math::equal(p.getY(), 0.0)) return false;

    return true;
};

SIMPLETEST("Point setY") {
    Point p;

    p.setY(1.0);
    if (!Math::equal(p.getX(), 0.0)) return false;
    if (!Math::equal(p.getY(), 1.0)) return false;

    return true;
};

SIMPLETEST("Point move") {
    Point p;

    p.move(1.1, 2.2);
    if (!Math::equal(p.getX(), 1.1)) return false;
    if (!Math::equal(p.getY(), 2.2)) return false;

    return true;
};

SIMPLETEST("Point color") {
    Point p;

    if (p.getColor() != "black") return false;

    p.setColor("red");
    if (p.getColor() != "red") return false;

    return true;
};

SIMPLETEST("Point color2") {
    Point p;

    if (p.getColor() != "black") return false;

    p.setColor(100, 101, 102);
    if (p.getColor() != "rgb(100,101,102)") return false;

    return true;
};

SIMPLETEST("Point toSVG") {
    Point p;
    if (p.toSVG() != "<circle cx=\"0\" cy=\"0\" r=\"10\" stroke=\"black\" fill=\"black\" />") return false;
    return true;
};

SIMPLETEST("Point toSVG2") {
    Point p = {XCoor{1.1}, YCoor{2.9}};
    p.setColor("red");
    if (p.toSVG() != "<circle cx=\"1\" cy=\"3\" r=\"10\" stroke=\"red\" fill=\"red\" />") return false;
    return true;
};

SIMPLETEST("Point distance") {
    Point p1;
    Point p2 = {XCoor{1.0}, YCoor{1.0}};

    if (!Math::equal(distance(p1, p1), 0.0)) return false;
    if (!Math::equal(distance(p2, p2), 0.0)) return false;
    if (!Math::equal(distance(p1, p2), std::sqrt(2.0))) return false;
    return true;
};

//[opcomp
SIMPLETEST("Point op==") {
    Point p1;
    Point p2 = {XCoor{1.0}, YCoor{1.0}};

    if (p1 == p2) return false;
    if (!(p1 != p2)) return false;
    return true;
};

SIMPLETEST("Point op== 2") {
    Point p1;
    Point p2 = p1;

    if (!(p1 == p2)) return false;
    if (p1 != p2) return false;

    return true;
};
//]

SIMPLETEST("Point <<") {
    Point p1;
    std::stringstream ss;

    ss << p1;

    if (ss.str() != "Point[0,0,black]") return false;
    return true;
};

SIMPLETEST("Point op-") {
    Point p1;
    Point p2 = {XCoor{1.0}, YCoor{1.0}};

    if (!Math::equal(p1 - p1, 0.0)) return false;
    if (!Math::equal(p2 - p2, 0.0)) return false;
    if (!Math::equal(p1 - p2, std::sqrt(2.0))) return false;
    return true;
};

SIMPLETEST("Point ctor4") {
    Point p = {Radius{1.0}, Angle{0.0}};

    if (!Math::equal(p.getX(), 1.0)) return false;
    if (!Math::equal(p.getY(), 0.0)) return false;
    return true;
};

SIMPLETEST("Point ctor5") {
    Point p = {Radius{1.0}, Angle{Math::pi() / 2.0}};

    if (!Math::equal(p.getX(), 0.0)) return false;
    if (!Math::equal(p.getY(), 1.0)) return false;
    return true;
};


