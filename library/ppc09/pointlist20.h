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

#include "list00.h"
#include "point80.h"

class PointListNode;

//[PointList -a
class PointList : public List
{
public:
    //[a
    PointList();
    //]
    virtual ~PointList(); // <> Der Destruktor erzeugt zu Demonstrationszwecken eine Ausgabe.
    //[a
    PointList(const PointList& other);
    PointList& operator=(const PointList& rhs);
    PointList(PointList&& other);
    PointList& operator=(PointList&& rhs);

    PointList& operator+=(const Point& point);
    //]
    virtual size_t size() const override; // <> Hier werden die rein-virtuellen Elementfunktionen der Schnittstelle `List` realisiert.
    virtual bool empty() const override;
    virtual void clear() override;
    //[a
    const Point& front() const;
    void  pop_front();
    void swap(PointList& other);
private:
    std::unique_ptr<PointListNode> mHead;
    PointListNode* mTail = nullptr;
    size_t mSize = 0;
    //]
};
//]
void swap(PointList& a, PointList& b);

