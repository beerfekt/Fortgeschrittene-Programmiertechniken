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
#include <vector>
#include <memory> // <> Header-Datei für `std::unique_ptr` und `std::make_unique`
#include "point60.h"

std::vector<std::unique_ptr<Point>> createPoints()
{
    std::vector<std::unique_ptr<Point>> points;

    points.push_back(std::make_unique<Point>(XCoor{0.0}, YCoor{0.0}));
    points.push_back(std::make_unique<Point>(XCoor{10.0}, YCoor{10.0}));
    points.push_back(std::make_unique<Point>(XCoor{20.0}, YCoor{20.0}));

    return points;
}

int main()
{
    auto points = createPoints();

    for(const auto& p: points) {
        if (p) {
            std::cout << *p << std::endl;
        }
    }
}
