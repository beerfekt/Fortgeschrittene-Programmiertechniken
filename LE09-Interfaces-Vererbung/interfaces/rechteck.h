#pragma once
#include <string>
#include <svg.h>

class Rechteck : public SVG  //(implementiert interface SVG)
{
    int width, height;

public:
    Rechteck(int width = 0, int height = 0);
    int getWidth()const;
    int getHeight()const;
    virtual std::string toSVG() const override;
};


