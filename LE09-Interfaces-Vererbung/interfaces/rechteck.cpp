#include "rechteck.h"

Rechteck::Rechteck(int width, int height):
    width(width),
    height(height)
{}

int Rechteck::getWidth()const {
    return width;
}

int Rechteck::getHeight()const {
    return height;
}

std::string Rechteck::toSVG() const {
    return                "<rect width=\"" + std::to_string(width)
                        + "\" height=\"" + std::to_string(height)
                        + "\" style=\"fill:rgb(0,0,255);stroke-width:10;stroke:rgb(0,0,0)\" />";
}


