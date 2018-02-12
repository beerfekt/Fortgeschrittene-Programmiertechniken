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

#include <cmath>
#include <random>

#include "point30.h"
#include "svgfile.h"
#include "math.h"

int main()
{
#ifdef _MSC_VER
    std::linear_congruential_engine<unsigned int, 31, 0, 255> generator; // <> Die Variable `generator` ist ein Zufallszahlengenerator für Werte im Bereich [0,255].
#else
    std::linear_congruential_engine<unsigned char, 31, 0, 255> generator; // <> Die Variable `generator` ist ein Zufallszahlengenerator für Werte im Bereich [0,255].
#endif
    int numberOfPoints = 10;
    double scale = 30.0;
    Point origin{1.0 * Point::svgRadius(), scale + Point::svgRadius()};
    double delta = 2.0 * Math::mPi / numberOfPoints;

    SVGFile file("line.svg",
                 Math::toInt(2 * Math::mPi * scale) + 2 * Point::svgRadius(), // <> Angabe der Ausdehnung der `SVG`-Zeichenebene
                 Math::toInt(2 * scale) + 2 * Point::svgRadius());

    for(int i = 0; i < numberOfPoints; i += 1) {
        double x = delta * i;
        double y = std::sin(x);
        Point p{x * scale + origin.getX(), y * scale + origin.getY()};
        p.setColor(generator(), generator(), generator()); // <> Jeder Punkt bekommt einen zufälligen Farbwert.
        file.add(p.toSVG());
    }
}
