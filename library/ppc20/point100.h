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

#pragma once

#if __has_include("../ppc.h")
# include "../ppc.h"
#endif

#include <limits>
#include <type_traits>
//[extra
#include <iostream> // <> Statt `<iosfwd>` ist hier `<iostream>` erforderlich (s.a. Ausgabeoperator)

template<typename T> class Point; // <> _Deklaration_ des Klassentemplates `Point<T>`

template<typename T>
std::ostream& operator<<(std::ostream& out, const Point<T>& p); // <> _Deklaration_ des Funktionstemplates `operator<<<T>()`; hierfür ist auch die Deklaration des Klassentemplates `Point<T>` erforderlich.
//]
//[point
template<typename T>
class Point { // <> _Definition_ des Klassentemplates `Point<T>`
    friend std::ostream& operator<< <>(std::ostream& out, const Point& p); // <> Friend-Deklaration für die Templatefunktion
    
    static_assert(std::is_arithmetic<T>::value, "type T must be an arithmetic type");
public:
    Point(const T& x, const T& y) : mX(x), mY(y) {}

    const T& getX() const {return mX;}
    const T& getY() const {return mY;} //-

    Point& setX(const T& x) {mX = x; return *this;}
    Point& setY(const T& y) {mY = y; return *this;} //-
private:
    T mX = 0;
    T mY = 0;
};
//]
//[extra
template<typename T>
std::ostream& operator<<(std::ostream& out, const Point<T>& p) { // <> _Definition_ des Funktionstemplates
    out << "Point[" << p.mX << ',' << p.mY << ']';
    return out;
}
//]
