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

#ifndef _MSC_VER
# pragma GCC diagnostic ignored "-Wunused-variable"
#endif

#include <vector>
#include <array>
#include <algorithm>
#include <limits>
#include <cassert>

//[max1
template<typename T, typename... P> 
T maximum(P... vs) { 
    T max = std::numeric_limits<T>::min();  
    for(int v : {vs...}) {
        if (v > max) {
            max = v;
        }
    }
    return max;
}
//]
int main() {
    //[main
    auto max = maximum<int>(1, 3, 5);
    assert(max == 5);
    //]
}
