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

#include <string>
#include "dgeometry.h"

class SVGShape // <> Diese Klasse enthält nur *rein-virtuelle* Elementfunktionen und stellt damit eine *Schnittstelle* dar.
{
public:
    virtual std::string toSVG() const = 0; // <> Die Qualifizierungen `virtual` und `= 0` deklarieren diese Elementfunktion als *rein-virtuell*.
    virtual DRect svgArea() const = 0; // <> Diese Elementfunktion ist ebenfalls *rein-virtuell*.

    virtual ~SVGShape(); // <> Der Destruktor *muss* hier *virtuell* deklariert werden.
};

