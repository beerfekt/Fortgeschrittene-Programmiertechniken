#pragma once
#include <string>

//Vergleichbar mit interface aus java.

class SVG
{
public:

    virtual std::string toSVG() const = 0;
    virtual ~SVG();
};

