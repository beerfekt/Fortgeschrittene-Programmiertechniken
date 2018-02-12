#pragma once
#include <string>
#include <svg.h>

class Punkt : public SVG //interface hier reinscheppern
{
    int x,y;
    std::string stroke, fill;

public:
    Punkt(int x = 0, int y = 0, std::string fill = "black");
    Punkt& setFill(std::string color);
    int getX() const;
    int getY() const;
    std::string getFill() const;
    virtual std::string toSVG() const override; //für interface
};




