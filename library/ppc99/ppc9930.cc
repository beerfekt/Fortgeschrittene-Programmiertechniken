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

#include <malloc.h>

#include <iostream>
#include <chrono>
#include <vector>
#include <memory>

constexpr auto size = 1024 * 1024 * 16;
//constexpr auto size = 1024 * 128 + 512;
constexpr auto iterations = 1024;

int main() {
    mallopt(M_CHECK_ACTION, 0);
    
    using time_type = std::chrono::nanoseconds;
    std::vector<time_type> t;
    
    for(size_t i = 0; i < iterations; ++i) {
        auto a = std::make_unique<char[]>(size);
        auto start = std::chrono::steady_clock::now();
        a.reset();
        auto duration = std::chrono::duration_cast<time_type>(std::chrono::steady_clock::now() - start);
        t.push_back(duration);
    }

    time_type min{t[0]};
    time_type max{t[0]};
    time_type mean{0};
    for(auto& d: t) {
        min = std::min(min, d);
        max = std::max(max, d);
        mean += d;
    }
    mean /= iterations;
    
    std::cout << "min: " << min.count() << '\n';
    std::cout << "max: " << max.count() << '\n';
    std::cout << "mean: " << mean.count() << '\n';
}