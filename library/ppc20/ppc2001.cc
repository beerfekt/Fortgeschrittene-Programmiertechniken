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

class Base {
public:
    virtual void f() const {std::cout << __PRETTY_FUNCTION__ << std::endl;}
};

class Derived : public Base {
public:
    virtual void f() const override {std::cout << __PRETTY_FUNCTION__ << std::endl;}
};

void foo(const Base& x) {
    x.f(); // <> Dynamisches Binden erfolgt für _virtuelle_ Elementfunktionen.
}

int main() {
    Base b;
    foo(b);
    Derived d;
    foo(d);
}
