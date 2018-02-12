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

#include <iostream>
#include <memory>

int main()
{
    const size_t length = 5;

    std::unique_ptr<double[]> up1{new double[length]}; // <> Wie schon bei singulären Objekten sollte auch bei rohen Arrays im Freispeicher diese explizite Erzeugung mit dem `new`-Operator nur in *Ausnahmefällen* verwendet werden.

    std::unique_ptr<double[]> up2 = std::make_unique<double[]>(length); // <> Dies ist die _präferierte_ Variante gegenüber oben.

    auto up3 = std::make_unique<double[]>(length); // <> Die automatische _Typinferenz_ spart die redundate Typangabe.

    up3[0] = 42.0; // <> Der *UP* für Arrays besitzt auch einen _Subscript_-Operator.

    for(size_t i = 0; i < length; ++i) {
        std::cout << up3[i] << std::endl;
    }
}
