
//###################### SVG (Interface ) ####################

#pragma once
#include <string>

//Vergleichbar mit interface aus java.

class SVG
{
public:

    virtual std::string toSVG() const = 0;
    virtual ~SVG();
};

//--------------------------------------------------

#include "svg.h"

SVG::~SVG(){}


//###################     SVG FILE    ##########################


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

//----------------------------------------------------------------

#include "svgfile.h"
#include <cassert>

SVGFile::SVGFile( std::string filename, int width, int height):
   svgfile("/home/beer/Schreibtisch/"+filename+".svg"),
   width(width),
   height(height)
{}

SVGFile::~SVGFile(){
    assert(svgfile.is_open() && (&svgElement));
    svgfile << "<svg width=\"" + std::to_string(width) + "\" height=\"" + std::to_string(height) + "\"> \n" ;
    svgfile << " " << svgElement << "\n";
    svgfile << "</svg> \n";
    svgfile.close();
}

SVGFile& SVGFile::addElement(const SVG& element) {
    svgElement = element.toSVG();
    return *this;
}

