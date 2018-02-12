#pragma once
#include "svg.h"
#include <punkt.h>
#include <rechteck.h>
#include <fstream>

class SVGFile
{
    std::ofstream svgfile;
    std::string svgElement;
    int width, height;


public:
    SVGFile(std::string filename = "test", int width = 500, int height = 500);
    ~SVGFile();
    SVGFile& addElement(const SVG& svgElement);
};

