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


