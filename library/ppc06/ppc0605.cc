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

#include <iostream>

#include "point50.h"

void foo(const Point* point)
{
    std::cout << "SVG: " << point->toSVG() << std::endl; // <> Zeiger-Element-Zugriff-Operator
    std::cout << "Farbe: " << (*point).getColor() << std::endl; // <> Indirektions- und Element-Zugriff-Operator
}

int main()
{
    Point p{XCoor{1.0}, YCoor{1.0}};
    p.move(2.0, 2.0); // <> Element-Zugriff-Operator
    Point* pPtr = &p; // <> Adressoperator
    pPtr->setColor("red"); // <> Zeiger-Element-Zugriff-Operator
    foo(pPtr);
}
