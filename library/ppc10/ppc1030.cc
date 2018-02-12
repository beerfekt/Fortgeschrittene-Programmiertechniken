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

#if __has_include("../ppc.h") //-
# include "../ppc.h" //-
#endif //-

#include <iostream>
#include <array> // <> Notwendiges `include` für den Typ `std::array<T, size>` (s.u.)
#include <utility>
#include <cassert>

int absoluteSum(const std::array<int,5>& array) // <> Auch die Dimensionierung muss in die Parameterdeklaration übernommen werden!
{
    int sum = 0;
    for(const int& x: array) { // <> Vorteil gegenüber _rohen_ Arrays: die Dimensionierungsinformation ist verfügbar, so dass diese Form der `for`-Schleife angewendet werden kann.
        sum += std::abs(x);
    }
    return sum;
}

int main()
{
    std::array<int, 5> array = {{1, 2, -3, -4, 5}}; // <> Definition eines statischen Arrays.

    std::cout << absoluteSum(array) << std::endl;
}
