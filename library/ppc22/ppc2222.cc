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
#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>

//[functor
class Equals
{
public:
    explicit Equals(double v) : mValue(v) {}

    bool operator()(double v) { // <> Definition der _Aufruf_-Elementfunktion des Funktors
        if (std::fabs(v - mValue) < mThreshold) {
            return true;
        }
        return false;
    }
    //[setter
    Equals& threshold(double t) { // <> Der _setter_  im _named-parameter_-Idiom
        mThreshold = t;
        return *this;
    }
    //]
private:
    double mValue{0};
    double mThreshold{1E-10};
};
//]
int main()
{
    //[double
    std::vector<double> v{1.0, 2.0, 3.0, 1.0};
    auto n = std::count_if(std::begin(v), std::end(v), Equals(1.0).threshold(0.001)); // <> `Equals()` erzeugt ein Funktor-Objekt mit dem Vergleichswert `1.0`. Mit dem _setter_  wird dann noch die Schwelle gesetzt.
    std::cout << n << std::endl;
    //]
}
