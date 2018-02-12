#include "punkt.h"

Punkt::Punkt(int x, int y, std::string fill)
    : x(x),
      y(y),
      fill(fill)
{}

//Setter

Punkt& Punkt::setFill(std::string color ){
     fill = color;
     return *this;
}


//GETTER

int Punkt::getX()const {
    return x;
}

int Punkt::getY()const{
    return x;
}


std::string Punkt::getFill()const{
    return fill;
}

//Methoden

std::string Punkt::toSVG()const{
    return              "<circle cx=\"" + std::to_string(x)
                        + "\" cy=\"" + std::to_string(y)
                        + "\" r=\"" + std::to_string(40)
                        + "\" stroke=\"" + "black"
                        + "\"  stroke-width=\"" + std::to_string(2)
                        + "\" fill=\"" + fill
                        + "\" />";
}
