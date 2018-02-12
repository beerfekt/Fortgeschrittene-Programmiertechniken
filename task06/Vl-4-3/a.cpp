#include "a.h"
#include <iostream>

A::A(){}


int A::getX() const {
    return x;
}

void A::setX(const int& y) {
    this->x = y;
}

void A::test(const A& a3){
    std::cout << a3.getX() << std::endl; //Nur beobachten der Referenz a3 möglich
}


