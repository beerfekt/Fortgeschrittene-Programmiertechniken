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

#if __has_include("../ppc.h")  //-
# include "../ppc.h" //-
#endif //-

# include <string>

#ifndef _MSC_VER
# pragma GCC diagnostic ignored "-Wunused-variable"
#endif

//[template
template<typename T> // <> Diese sog. Template-Präambel erklärt das folgende Konstrukt zum Template mit dem Template-Typ-Parameter `T`.
const T& maximum(const T& a, const T& b) { // <> Weil `T` ein _beliebiger_ DT sein kann, folgen wir der allgemeinen Regel zur Übernahme von _Input_-Parametern per _const reference_.
    if (a > b) {
        return a; // <> Hier wurde die Regel _reference-in / reference-out_ angewendet.
    }
    return b; // <> Ebenso
}
//]
int main()
{
    int x = maximum(1, 2); // <> Der Compiler generiert hier eine Templatefunktion für der DT `int` ...
    double y = maximum(1.1, 2.2); // <> ... und hier für den DT `double`.

    //[string
    std::string z = maximum(std::string("abc"), std::string("def")); // <> Hier wird eine Templatefunktion für `T` als `std::string` erzeugt,
    //]
}
