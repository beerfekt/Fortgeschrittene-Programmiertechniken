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
#include <vector> // <> Diese `include`-Datei ist für die Verwendung von `std::vector` notwendig.
#include "point60.h"

int main()
{
    Point p;
    std::cout << p << std::endl;

    std::vector<Point> points;

    std::cout << "size: " << points.size() << " capacity: " << points.capacity() << std::endl;
    points.push_back(p);
    std::cout << "size: " << points.size() << " capacity: " << points.capacity() << std::endl;
    points.push_back(p);
    std::cout << "size: " << points.size() << " capacity: " << points.capacity() << std::endl;
    points.push_back(p);
    std::cout << "size: " << points.size() << " capacity: " << points.capacity() << std::endl;
    points.push_back(p);
    std::cout << "size: " << points.size() << " capacity: " << points.capacity() << std::endl;
    points.push_back(p);
    std::cout << "size: " << points.size() << " capacity: " << points.capacity() << std::endl;

    for(const Point& e: points) {
        std::cout << e << std::endl;
    }
}
