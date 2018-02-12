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

#include "heaparray40.h"

#include "../lib/simpletest.h"

#include "math.h"
#include "inserter.h"

#include <type_traits>
#include <algorithm>
#include <numeric>

static_assert(std::is_default_constructible<HeapArray<int>>::value, "HeapArray<T> must not be default-constructible");

static_assert(std::is_copy_constructible<HeapArray<int>>::value, "HeapArray<T> should be copy-constructible");
static_assert(std::is_copy_assignable<HeapArray<int>>::value, "HeapArray<T> should be copy-assignable");

static_assert(std::is_move_constructible<HeapArray<int>>::value, "HeapArray<T> should be move-constructible");
static_assert(std::is_move_assignable<HeapArray<int>>::value, "HeapArray<T> should be move-assignable");

//[tests
SIMPLETEST("ctor1") {
    const int size = 100;
    HeapArray<int> ha(size);

    if (ha.size() != size) return false;
    return true;
};

SIMPLETEST("ctor2") {
    const int size = 100;
    HeapArray<int> ha(size);

    for(size_t i = 0; i < ha.size(); ++i) {
        if (ha[i] != 0) return false;
    }
    return true;
};

SIMPLETEST("ctor3") {
    const int size = 100;
    HeapArray<int> ha(size);

    for(size_t i = 0; i < ha.size(); ++i) {
        ha[i] = 42;
    }
    const HeapArray<int>& ha2 = ha;
    for(size_t i = 0; i < ha.size(); ++i) {
        if (ha2[i] != 42) return false;
    }

    return true;
};

SIMPLETEST("ctor4") {
    const int size = 100;
    HeapArray<long double> ha(size);

    for(size_t i = 0; i < ha.size(); ++i) {
        if (!Math::equal(ha[i], 0.0L)) return false;
    }
    return true;
};

SIMPLETEST("ctor5") {
    const int size = 100;
    const long double value = 1.0;
    HeapArray<long double> ha(size, value);

    for(size_t i = 0; i < ha.size(); ++i) {
        if (!Math::equal(ha[i], 1.0L)) return false;
    }
    return true;
};

SIMPLETEST("move assign") {
    HeapArray<int> ha(100);

    ha = HeapArray<int>(2);

    if (ha.size() != 2) return false;

    return true;
};

SIMPLETEST("move construct") {
    HeapArray<int> ha = HeapArray<int>(2);

    if (ha.size() != 2) return false;

    return true;
};

SIMPLETEST("move construct2") {
    HeapArray<int> hx = HeapArray<int>(2);
    hx[1] = 42;

    HeapArray<int> ha = std::move(hx);

    if (ha.size() != 2) return false;
    if (ha[1] != 42) return false;

    if (hx.size() != 0) return false; // <> Dadurch kein Blackboxtest mehr!

    return true;
};

SIMPLETEST("move assign2") {
    HeapArray<int> hx = HeapArray<int>(2);
    hx[1] = 42;

    HeapArray<int> ha = HeapArray<int>(10);
    ha = std::move(hx);

    if (ha.size() != 2) return false;
    if (ha[1] != 42) return false;

    if (hx.size() != 10) return false; // <> Dadurch kein Blackboxtest mehr!

    return true;
};

SIMPLETEST("copy construct") {
    HeapArray<int> ha1(100);

    ha1[42] = 42;

    HeapArray<int> ha2 = ha1;

    if (ha2.size() != 100) return false;
    if (ha2[42] != 42) return false;

    return true;
};

SIMPLETEST("copy assign") {
    HeapArray<int> ha1(100);
    ha1[42] = 42;

    HeapArray<int> ha2(200);
    ha2[42] = 43;

    ha1 = ha2;

    if (ha2.size() != 200) return false;
    if (ha2[42] != 43) return false;

    return true;

    return true;
};

SIMPLETEST("swap1") {
    HeapArray<long double> ha1(10);
    HeapArray<long double> ha2(20);

    ha1.swap(ha2);

    if (ha1.size() != 20) return false;
    if (ha2.size() != 10) return false;

    return true;
};

SIMPLETEST("initializer_list") {
    HeapArray<int> ha{1, 2, 3, 4, 5};

    if (ha[0] != 1) return false;
    if (ha[1] != 2) return false;
    if (ha[2] != 3) return false;
    if (ha[3] != 4) return false;

    return true;
};

SIMPLETEST("iterator1") {
    HeapArray<int> ha(10);

    for(auto it = ha.begin();
        it != ha.end();
        ++it) {
        if (*it != 0) {
            return false;
        }
    }
    return true;
};

SIMPLETEST("iterator2") {
    HeapArray<int> ha(10);

    std::fill(std::begin(ha), std::end(ha), 1);

    for(auto& v : ha) {
        if (v != 1) {
            return false;
        }
    }

    return true;
};

SIMPLETEST("iterator3") {
    HeapArray<int> ha(10);

    std::fill(std::begin(ha), std::end(ha), 1);

    HeapArray<int> ha2(10);

    std::copy(std::begin(ha), std::end(ha), std::begin(ha2));

    for(auto& v : ha) {
        if (v != 1) {
            return false;
        }
    }

    return true;
};

SIMPLETEST("iterator4") {
    HeapArray<int> ha = {5, 4, 3, 2, 1};

    std::sort(std::begin(ha), std::end(ha));

    if (ha[0] != 1) return false;
    if (ha[4] != 5) return false;

    return true;
};

SIMPLETEST("remove") {
    HeapArray<int> ha = {5, 4, 3, 2, 1};

    int value = 3;

    auto end = std::remove_if(std::begin(ha), std::end(ha), [&](int x){return x <= value;});

    for(auto it = std::begin(ha); it < end; ++it) {
        if (*it <= value) return false;
    }

    return true;
};

SIMPLETEST("reverse") {
    HeapArray<int> ha = {5, 4, 3, 2, 1};

    std::reverse(std::begin(ha), std::end(ha));

    if (ha[0] != 1) return false;
    if (ha[4] != 5) return false;

    return true;
};

SIMPLETEST("iota") {
    HeapArray<int> ha(10);

    std::iota(std::begin(ha), std::end(ha), 1);

    if (ha[0] != 1) return false;
    if (ha[9] != 10) return false;

    return true;
};

SIMPLETEST("capacity") {
    HeapArray<int> ha(10);

    if (ha.size() != 10) return false;
    if (ha.capacity() != 10) return false;

    HeapArray<int> ha2 = ha;
    if (ha2.size() != 10) return false;
    if (ha2.capacity() != 10) return false;

    return true;
};

SIMPLETEST("push_back") {
    HeapArray<int> ha;

    if (ha.size() != 0) return false;
    if (ha.capacity() != 0) return false;

    ha.push_back(1);
    if (ha.size() != 1) return false;
    if (ha.capacity() != 2) return false;

    ha.push_back(2);
    if (ha.size() != 2) return false;
    if (ha.capacity() != 2) return false;

    ha.push_back(3);
    if (ha.size() != 3) return false;
    if (ha.capacity() != 6) return false;
    return true;
};

SIMPLETEST("push_back2") {
    HeapArray<int> ha;

    ha.push_back(1);
    ha.push_back(2);
    ha.push_back(3);

    if (ha[0] != 1) return false;
    if (ha[1] != 2) return false;
    if (ha[2] != 3) return false;

    return true;
};

SIMPLETEST("back insert") {
    HeapArray<int> ha{1, 2, 3};
    HeapArray<int> ha2;

    std::copy(std::begin(ha), std::end(ha), std::back_inserter(ha2));

    if (ha2[0] != 1) return false;
    if (ha2[1] != 2) return false;
    if (ha2[2] != 3) return false;

    return true;
};

SIMPLETEST("inserter1")
{
    HeapArray<int> ha1{1, 2, 3};
    HeapArray<int> ha2;

    std::copy(std::begin(ha1), std::end(ha1), Inserter<HeapArray<int>>(ha2));

    if (!std::equal(std::begin(ha1), std::end(ha1), std::begin(ha2))) return false;

    return true;
};

SIMPLETEST("inserter2")
{
    HeapArray<int> ha1{1, 2, 3};
    HeapArray<int> ha2;

    std::copy(std::begin(ha1), std::end(ha1), make_inserter(ha2));

    if (!std::equal(std::begin(ha1), std::end(ha1), std::begin(ha2))) return false;

    return true;
};
