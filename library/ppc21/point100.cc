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

#include "point100.h"

#include "../lib/simpletest.h"
#include "math.h"

#include <cassert>
#include <cmath>
#include <sstream>

bool operator==(const Point& p1, const Point& p2)
{
    return (Math::equal(p1.mX, p2.mX) && Math::equal(p1.mY, p2.mY));
}
bool operator!=(const Point& p1, const Point& p2)
{
    return !(p1 == p2);
}

std::ostream& operator<<(std::ostream& outputStream, const Point& p)
{
    outputStream << "Point[" << p.mSNR << "," << p.mX << "," << p.mY << "," << p.mColor << "]";
    return outputStream;
}

double operator-(const Point& a, const Point& b)
{
    return std::hypot(a.mX - b.mX, a.mY - b.mY);
}

double distance(const Point& a, const Point& b)
{
    double dx = a.x() - b.x();
    double dy = a.y() - b.y();

    return std::hypot(dx, dy);
}

Point::Point(double x, double y, const std::string& color) : ExtendedSVGShape(color), mX(x), mY(y)
{
}

Point::Point(Cartesian::X x, Cartesian::Y y) : Point(x.mValue, y.mValue)
{
}

Point::Point(Polar::Radius r, Polar::Angle phi) : Point(r.mValue * std::cos(phi.mRadiant), r.mValue * std::sin(phi.mRadiant))
{
}

Point::Point(const Point& other) : Point(other.mX, other.mY, other.mColor)
{
}

Point::~Point()
{
}

Point& Point::operator=(const Point& rhs)
{
    Point copy(rhs);
    swap(copy);
    return *this;
}

void Point::swap(Point& other)
{
    using std::swap;
    ExtendedSVGShape::swap(other);
    swap(mX, other.mX);
    swap(mY, other.mY);
}

double Point::x() const
{
    return mX;
}

double Point::y() const
{
    return mY;
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
    return svgString;
}

DRect Point::svgArea() const
{
    return DRect{DPoint{Math::toInt(mX) - mSVGRadius, Math::toInt(mY) + mSVGRadius}, DPoint{Math::toInt(mX) + mSVGRadius, Math::toInt(mY) - mSVGRadius}};
}

int Point::svgRadius()
{
    return mSVGRadius;
}

Point& Point::x(double x)
{
    mX = x;
    return *this;
}

Point& Point::y(double y)
{
    mY = y;
    return *this;
}

Point& Point::move(double dx, double dy)
{
    mX += dx;
    mY += dy;
    return *this;
}


SIMPLETEST("Point ctor1") {
    Point p;

    if (!Math::equal(p.x(), 0.0)) return false;
    if (!Math::equal(p.y(), 0.0)) return false;

    return true;
};

SIMPLETEST("Point ctor2") {
    Point p{Cartesian::X{1.0}, Cartesian::Y{2.0}};

    if (!Math::equal(p.x(), 1.0)) return false;
    if (!Math::equal(p.y(), 2.0)) return false;

    return true;
};

SIMPLETEST("Point ctor3") {
    Point p{Cartesian::X{1.0}};

    if (!Math::equal(p.x(), 1.0)) return false;
    if (!Math::equal(p.y(), 0.0)) return false;

    return true;
};

SIMPLETEST("Point setX") {
    Point p;

    p.x(1.0);
    if (!Math::equal(p.x(), 1.0)) return false;
    if (!Math::equal(p.y(), 0.0)) return false;

    return true;
};

SIMPLETEST("Point setY") {
    Point p;

    p.y(1.0);
    if (!Math::equal(p.x(), 0.0)) return false;
    if (!Math::equal(p.y(), 1.0)) return false;

    return true;
};

SIMPLETEST("Point move") {
    Point p;

    p.move(1.1, 2.2);
    if (!Math::equal(p.x(), 1.1)) return false;
    if (!Math::equal(p.y(), 2.2)) return false;

    return true;
};

SIMPLETEST("Point color") {
    Point p;

    if (p.color() != "black") return false;

    p.color("red");
    if (p.color() != "red") return false;

    return true;
};

SIMPLETEST("Point color2") {
    Point p;

    if (p.color() != "black") return false;

    p.color(100, 101, 102);
    if (p.color() != "rgb(100,101,102)") return false;

    return true;
};

SIMPLETEST("Point toSVG") {
    Point p;
    if (p.toSVG() != "<circle cx=\"0\" cy=\"0\" r=\"10\" stroke=\"black\" fill=\"black\" />") return false;
    return true;
};

SIMPLETEST("Point toSVG2") {
    Point p = {Cartesian::X{1.1}, Cartesian::Y{2.9}};
    p.color("red");
    if (p.toSVG() != "<circle cx=\"1\" cy=\"3\" r=\"10\" stroke=\"red\" fill=\"red\" />") return false;
    return true;
};

SIMPLETEST("Point distance") {
    Point p1;
    Point p2 = {Cartesian::X{1.0}, Cartesian::Y{1.0}};

    if (!Math::equal(distance(p1, p1), 0.0)) return false;
    if (!Math::equal(distance(p2, p2), 0.0)) return false;
    if (!Math::equal(distance(p1, p2), std::sqrt(2.0))) return false;
    return true;
};

SIMPLETEST("Point <<") {
    Point p1;
    std::stringstream ss;

    ss << p1;

    std::string expected = "Point[" + std::to_string(p1.SNR()) + ",0,0,black]";

    if (ss.str() != expected) return false;
    return true;
};

SIMPLETEST("Point op-") {
    Point p1;
    Point p2 = {Cartesian::X{1.0}, Cartesian::Y{1.0}};

    if (!Math::equal(p1 - p1, 0.0)) return false;
    if (!Math::equal(p2 - p2, 0.0)) return false;
    if (!Math::equal(p1 - p2, std::sqrt(2.0))) return false;
    return true;
};

SIMPLETEST("Point op==") {
    Point p1;
    Point p2 = {Cartesian::X{1.0}, Cartesian::Y{1.0}};

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

SIMPLETEST("Point ctor4") {
    Point p = {Polar::Radius{1.0}, Polar::Angle{0.0}};

    if (!Math::equal(p.x(), 1.0)) return false;
    if (!Math::equal(p.y(), 0.0)) return false;
    return true;
};

SIMPLETEST("Point ctor5") {
    Point p = {Polar::Radius{1.0}, Polar::Angle{Math::pi() / 2.0}};

    if (!Math::equal(p.x(), 0.0)) return false;
    if (!Math::equal(p.y(), 1.0)) return false;
    return true;
};

SIMPLETEST("Point area") {
    Point p;

    DRect r = p.svgArea();
    int d = 2 * p.svgRadius();
    if (r.area() != (d * d)) return false;
    return true;
};

SIMPLETEST("Point cctor") {
    Point p = {Polar::Radius{1.0}, Polar::Angle{Math::pi() / 2.0}};

    if (!Math::equal(p.x(), 0.0)) return false;
    if (!Math::equal(p.y(), 1.0)) return false;

    Point p2 = p;
    if (!Math::equal(p2.x(), 0.0)) return false;
    if (!Math::equal(p2.y(), 1.0)) return false;

    if (p2.SNR() == p.SNR()) return false;
    return true;
};

SIMPLETEST("Point assignment") {
    Point p1 = {Polar::Radius{1.0}, Polar::Angle{Math::pi() / 2.0}};
    p1.color("red");

    Point p2;

    p1 = p2;

    if (p1.color() != p2.color()) return false;
    if (p1.y() != p2.x()) return false;
    if (p1.y() != p2.y()) return false;

    if (p1.SNR() == p2.SNR()) return false;

    return true;
};

SIMPLETEST("Point assignment2") {
    Point p1 = {Polar::Radius{1.0}, Polar::Angle{Math::pi() / 2.0}};
    p1.color("red");
    Point p2;
    Point p3;

    p3 = p2 = p1;

    if (p1.color() != p3.color()) return false;
    if (p1.x() != p3.x()) return false;
    if (p1.y() != p3.y()) return false;

    if (p1.SNR() == p3.SNR()) return false;

    return true;
};

