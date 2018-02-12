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

#ifndef _MSC_VER
# pragma GCC diagnostic ignored "-Wunused-variable"
# pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

//[example
template<typename T>
void f(T* x) {
    std::cout << __PRETTY_FUNCTION__ << std::endl; //-
}

int main()
{
    int* e1 = 0;
    const int* e2 = 0;
    int*& e3 = e1;
    const int*& e4 = e2;

    f(e1); // <> `E'` -> `int*`; `P` -> `T*`; daraus folgt: `T` -> `int`
    f(e2); // <> `E'` -> `const int*`; `P` -> `T*`; daraus folgt: `T` -> `const int`
    f(e3); // <> `E'` -> `int*`; `P` -> `T*`; daraus folgt: `T` -> `int`
    f(e4); // <> `E'` -> `const int*`; `P` -> `T*`; daraus folgt: `T` -> `const int`
}
//]
