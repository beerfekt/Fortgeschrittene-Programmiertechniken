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

#include <iostream>

class UP {
public:
    UP() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    UP(const UP&) = delete;
    UP& operator=(const UP&) = delete;
    
    UP(UP&&) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    
    UP& operator=(UP&&) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return *this;
    }
    ~UP() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

void f(UP&&) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

UP g() {
    return UP();
}

int main() {
    UP up;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    
    f(std::move(up));
    
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    
    f(g());
    
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
