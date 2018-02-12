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
#include "math.h"
#include "double.h"

#include "../lib/simpletest.h"

//[tests1
SIMPLETEST("ctor1") {
    Point<double> p1(1.0, 1.1);

    if (!Math::equal(p1.getX(), 1.0)) return false;
    if (!Math::equal(p1.getY(), 1.1)) return false;

    return true;
};
//]
//[tests2
SIMPLETEST("ctor2") {
    Point<long double> p1(1.0L, 1.001L);

    if (!Math::equal(p1.getX(), 1.0L)) return false;
    if (!Math::equal(p1.getY(), 1.001L)) return false;

    return true;
};

SIMPLETEST("ctor3") {
    Point<int> p1(1, 2);

    if (!Math::equal(p1.getX(), 1)) return false;
    if (!Math::equal(p1.getY(), 2)) return false;

    return true;
};

SIMPLETEST("ctor4") {
    Point<Double> p1(1.0, 2.0);

    if (!Math::equal(p1.getX(), Double(1))) return false;
    if (!Math::equal(p1.getY(), Double(2))) return false;

    return true;
};
//]
