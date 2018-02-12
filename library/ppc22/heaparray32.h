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

#include <memory>
#include <cassert>
#include <iostream>

//[class -a -b
template<typename ValueType>
class HeapArray final
{
public:
    class HeapArrayIterator final
    {
    public:
        HeapArrayIterator(ValueType* p = nullptr) : mPtr(p) {}
        //[b
        HeapArrayIterator& operator++() {
            ++mPtr; return *this;
        }
        HeapArrayIterator operator++(int) {
            HeapArrayIterator copy = *this;
            ++mPtr;
            return copy;
        }
        ValueType& operator*() {return *mPtr;}
        //]
        bool operator!=(const typename HeapArray<ValueType>::HeapArrayIterator& rhs) { // <> Wegen des _non-deducible_-Kontextes der _freien_ Operatorfunktion muss dieser Operator als _Elementfunktion_ realisiert werden.
            return mPtr != rhs.mPtr;
        }
    private:
        ValueType* mPtr = nullptr;
    };

    explicit HeapArray(size_t size) : mSize(size), mData(std::make_unique<ValueType[]>(size)) {
        assert(mData);
    }
    //[a
    explicit HeapArray(size_t size, const ValueType& value) : mSize(size), mData(std::make_unique<ValueType[]>(size)) {
        assert(mData);
        std::fill(mData.get(), mData.get() + mSize, value);
    }

    explicit HeapArray(const std::initializer_list<ValueType>& ilist) :
        mSize(ilist.size()), mData(std::make_unique<ValueType[]>(ilist.size())) {
        assert(mData);
        std::copy(std::begin(ilist), std::end(ilist), mData.get());
    }

    HeapArray(const HeapArray& other) : mSize(other.mSize), mData(std::make_unique<ValueType[]>(other.mSize)) {
        std::copy(other.mData.get(), other.mData.get() + other.mSize, mData.get());
    }

    HeapArray& operator=(const HeapArray& rhs) {
        HeapArray<ValueType> copy = rhs;
        swap(copy);
        return *this;
    }

    HeapArray(HeapArray&& other) {
        swap(other);
    }

    HeapArray& operator=(HeapArray&& rhs) {
        swap(rhs);
        return *this;
    }

    HeapArray() = delete;
    ~HeapArray() = default;

    HeapArrayIterator begin() const {
        return HeapArrayIterator(&mData[0]);
    }

    HeapArrayIterator end() const {
        return HeapArrayIterator(&mData[mSize - 1] + 1);
    }

    size_t size() const {return mSize;}

    ValueType& operator[](size_t index) {assert(mData); return mData[index];}
    const ValueType& operator[](size_t index) const {assert(mData); return mData[index];}

    void swap(HeapArray& other) {
        using std::swap;
        swap(mSize, other.mSize);
        swap(mData, other.mData);
    }
    //]
private:
    size_t mSize{0};
    std::unique_ptr<ValueType[]> mData;
};
//]
/*+
//[deduc
template<typename ValueType>
bool operator!=(const typename HeapArray<ValueType>::HeapArrayIterator& lhs, // <> Dies ist ein sog. _non-deducible_ Kontext, d.h. der Typ `ValueType` kann nicht ermittelt werden.
                const typename HeapArray<ValueType>::HeapArrayIterator& rhs) {
    return lhs.mPtr != rhs.mPtr;
}
//]
*/

template<typename T>
void swap(HeapArray<T>& a, HeapArray<T>& b) {
    a.swap(b);
}
