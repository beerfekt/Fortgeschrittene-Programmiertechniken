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
#include <string>
#include <algorithm>

#include "heaparray32.h"
#include "list12.h"

//[main1 -list
int main()
{
    HeapArray<double> ha(3);

    std::fill(std::begin(ha), std::end(ha), 42.0); // <> Mit Hilfe des einfachen Iterators möglich (ggf. plattform-abhängig)

    for(const auto& e: ha) { // <> dies auch
        std::cout << e << std::endl;
    }

    //[list
    List<std::string> l = {"eins", "zwei"}; // <> Initialisierung mit _braced-initializer-list_
    l += "drei";

    for(const auto& s: l) { // <> Die _range-for_-Schleife benötigt die Elementfunktionen `begin()`, `end()` und Inkrement sowie Indirektion
        std::cout << s << std::endl;
    }

    List<std::string>::ListIterator it = std::find(std::begin(l), std::end(l), "eins"); // <> Das Ergebnis von {stdfind} ist ein Iterator des Containers: entweder verweist der Iterator auf die erste, gefundene Element oder es ist der Ende-Iterator.
    if (it != std::end(l)) {
        std::cout << *it << " found!" << std::endl;
    }
    //]
}
//]
