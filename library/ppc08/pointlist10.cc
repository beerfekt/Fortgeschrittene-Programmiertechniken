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

#include "pointlist10.h"

#include <algorithm>
#include <cassert>

#include "../lib/simpletest.h"

//[tests
SIMPLETEST("PointList ctor1"){
    PointList pl;
    if (pl.size() != 0) return false;
    return true;
};

SIMPLETEST("PointList insert1"){
    PointList pl;
    pl += Point();
    if (pl.size() != 1) return false;
    pl += Point();
    if (pl.size() != 2) return false;
    return true;
};
//]
//[dtor
PointList::~PointList()
{
    const PointListNode* node = mHead;
    while(node) { // <> Traversieren der Knoten
        const PointListNode* next = node->mNext;
        delete node; // <> Löschen jedes Knotens
        node = next;
    }
}
//]
//[add
PointList& PointList::operator+=(const Point& point)
{
    PointListNode* node = new PointListNode(point);

    if (mHead) {
        PointListNode* n = mHead;
        assert(n);
        while(n->mNext) { // <> Bestimmen des _letzten_ Knotens in der Liste
            n = n->mNext;
        }
        assert(!n->mNext);
        n->mNext = node; // <> Einfügen des neuen Knotens ans Ende
    }
    else { // <> Spezialfall: leere Liste
        mHead = node;
    }
    return *this;
}
//]
//[size
size_t PointList::size() const
{
    size_t size = 0;
    const PointListNode* node = mHead;
    while(node) {
        size += 1;
        node = node->mNext;
    }
    return size;
}
//]
//[ctor1
PointListNode::PointListNode(const Point& point) :
    mValue(point)
{
}
//]
