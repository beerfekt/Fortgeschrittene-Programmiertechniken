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

template<typename T, int L>
void f(const T (&a)[L]) {
    std::cout << __PRETTY_FUNCTION__ << '\n';    
    std::cout << a << '\n';
}

template<typename T>
void f(const T* a) {
    std::cout << __PRETTY_FUNCTION__ << '\n';    
    std::cout << a << '\n';
}

#include <vector>

using std::vector;

struct MyClass {
    void f() const {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }
};

enum A {a, b, c} x;
//enum B {a, b, c};

enum class A1 {a, b, c};
enum class B1 {a, b, c};

typedef struct _signalsystem
{
  enum _states2
  {
    stop2,
    go2
  };
  
  uint8_t state;
  enum _states2 state2;
} signalsystem_t;

signalsystem_t signal;

enum  States {
    stop,
    go,
    slow1,
    slow2,
    ks1,
    ks2,
    ks3
};

States state = States::slow1;

enum States1 {
//    stop
};

int main() {
    signal.state = signalsystem_t::go2;
    
    char s1[] = "abc";
    auto s2 = s1;
    
    f(s1);
    f(s2);
    
    
    void* x = nullptr; // mod
    
    vector<MyClass*> myClassList;
    myClassList.push_back(new MyClass()); // leak
    
    vector<void*> myList;
    myList.push_back(&myClassList);
    
    x = &myList; // x : vector<void*>*
    
    vector<void*> cast1 = *reinterpret_cast<vector<void*>*>(x); // cast1 == myList
    
//    vector<MyClass*> cast2 = reinterpret_cast<vector<MyClass*>*>(cast1[0]); // Fehler 
    
    // cast1[0] : void* (-> myClassList) : *vector<MyClass*>
    
    vector<MyClass*>* cast2 = reinterpret_cast<vector<MyClass*>*>(cast1[0]); 
    
    (*cast2)[0]->f();
    
//    cout << cast2.size(); // falsch
    std::cout << cast1.size() << '\n'; 
    
    A1 a1 = A1::a;
//    B1 b1 = A1::a;
    
    uint8_t y = stop;
//    uint8_t z = A1::a;
}
