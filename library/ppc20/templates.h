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

#pragma once

#if __has_include("../ppc.h")
# include "../ppc.h"
#endif

#include <iostream>

#ifndef _MSC_VER
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

//[max
template<typename T>
const T& maximum(const T& a, const T& b) {
    if (a > b) {
        return a;
    }
    return b;
}
//]
//[min
template<typename T>
const T& minimum(const T& a, const T& b) {
    if (a <= b) {
        return a;
    }
    return b;
}
//]
//[foo
template<typename T, typename U>
void foo(T a, U b)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl; //-
}
//]
//[bar
template<typename T>
void bar(T a, T b)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl; //-
}
//]

//[convert
template<typename To, typename From>
To convert(const From &v) {
    std::cout << __PRETTY_FUNCTION__ << std::endl; //-
    return static_cast<To>(v);
}
//]

#ifndef _MSC_VER
# pragma GCC diagnostic pop
#endif
