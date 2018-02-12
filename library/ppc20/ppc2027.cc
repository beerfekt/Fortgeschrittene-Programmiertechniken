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
#include <string>
#include <functional>

#ifndef _MSC_VER
# pragma GCC diagnostic ignored "-Wunused-variable"
#endif

//[cp
template<typename T>
class LengthComparator
{
public:
    bool operator()(const T& lhs, const T& rhs) {
        return lhs.length() > rhs.length();
    }
};
//]
//[at
template<typename T, typename C = std::greater<T>>
const T& maximum(const T& a, const T& b) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (C()(a, b)) {
        return a;
    }
    return b;
}
//]
//[main
int main()
{
    std::cout << maximum(std::string("abcd"), std::string("efg")) << std::endl;;
    std::cout << maximum<std::string, LengthComparator<std::string>>(std::string("abcd"), std::string("efg")) << std::endl;;
}
//]
