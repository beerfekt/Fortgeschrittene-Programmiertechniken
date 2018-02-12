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
#include "point41.h"

int main()
{
    //[points
    Point p1{1.0, 1.0};
    Point p2{2.0, 2.0};

    std::cout << "Distanz p1-p2: " << distance(p1, p2) << std::endl;
    //]
    //[other
    double d1 = distance(0.0, p1);
    std::cout << "Distanz d1: " << d1 << std::endl;
    double d2 = distance(p2, 1.0);
    std::cout << "Distanz d2: " << d2 << std::endl;
    double d3 = distance(0.0, 1.0);
    std::cout << "Distanz d3: " << d3 << std::endl;
    //]
    //[conversion
    Point p3 = 3.0; // <> _implizite_ Konvertierung `double` -> `Point` wie oben
    std::cout << "p3 = [" << p3.getX() << "," << p3.getY() << "]" << std::endl;
    //]
}
