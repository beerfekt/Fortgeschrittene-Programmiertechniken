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

//[class

class Point; // <> Für die folgende `friend`-Deklaration notwendig;

namespace Geometry { // <> Definition des Namensraumes `Geometry`
    
    class Polar final
    {
    public:
        Polar() = delete; // <> Die Klasse ist nicht _instanziierbar_.
        
        class Radius {
            friend class ::Point; // <> Hier ist die Klasse `Point` im _globalen_ Namensraum gemeint.
            friend Radius operator*(Radius a, Radius b);
            friend Radius operator*(double a, Radius b);
            friend Radius operator*(Radius a, double b);
        public:
            explicit Radius(double r);
        private:
            double mValue{0.0};
        };
        
        class Angle
        {
            friend Angle operator+(Angle a, Angle b);
        public:
#ifdef _MSC_VER //-
            Angle(double r) : mRadiant{r} {} //-
#endif //-
            double mRadiant{0.0};
        };
    };
    
    Polar::Radius operator*(Polar::Radius a, Polar::Radius b);
    Polar::Radius operator*(double a, Polar::Radius b);
    Polar::Radius operator*(Polar::Radius a, double b);
    
    Polar::Angle operator+(Polar::Angle a, Polar::Angle b);
    
}
//]
