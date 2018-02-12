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

//[ctors -x
//[class
template<typename ValueType>
class HeapArray final
{
public:
    explicit HeapArray(size_t size) :
        mSize(size),
        mData(std::make_unique<ValueType[]>(size)) // <> Erzeugen eines dynamischen Arrays der Größe `size`. Das Funktionstemplate {stdmake_unique} führt auch eine _value-initialization_ durch.
    {
        assert(mData);
    }
    //[x
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
    std::unique_ptr<ValueType[]> mData; // <> Der *UP* drückt die alleinige Eigentümerschaft aus.
};
//]
//]
//[swap
template<typename T>
void swap(HeapArray<T>& a, HeapArray<T>& b) {
    a.swap(b);
}
//]
