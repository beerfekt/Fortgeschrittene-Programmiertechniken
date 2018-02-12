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

#include <utility>

//[ListError -b
//[List -a
class List
{
public:
    //[a
    List();
#ifdef WITH_ERROR
    ~List();
#else
    //]
    virtual ~List(); // <> *Wichtig*: als _Schnittstellenklasse_ (Basistyp) muss `List` einen *virtuellen* Destruktor besitzen.
    //[a
#endif
    //]
    //[b
    virtual std::size_t size() const = 0; // <> Die Schnittstelle besitzt nur _rein-virtuelle_ Elementfunktionen.
    virtual bool empty() const = 0;
    virtual void clear() = 0;
    //]
};
//]
//]
