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

//[meta
template<typename T>
struct toPointer { // <> Meta-Funktion: `T` -> `T*` 
    typedef T* type;  // <> Üblicherweise ist das Ergebnis ein geschachtelter Typalias
};
//]
//[foo
template<typename T>
void foo() {
    std::cout << __PRETTY_FUNCTION__ << '\n';
}
//]
int main() {
    //[main
    toPointer<int>::type ptr = nullptr; // <> Hier wird aus dem Typ `int` der Typ `int*`
    foo<decltype(ptr)>();
    //]
}