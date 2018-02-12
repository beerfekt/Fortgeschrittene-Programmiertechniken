#include "svg.h"
#include <cassert>


const std::string SVG::header = R"(<svg  width="500" height="500">)";
const std::string SVG::footer = R"(</svg>)";

                                                            //File wird hier geöffnet
SVG::SVG(const std::string& fileName,const std::string element) :file("/home/beer/Schreibtisch/"+fileName),
                                                            element(element)
{
    assert(file.is_open()); //prüfung valide?
}

SVG::~SVG(){
   assert(file.is_open());  //prüfung valide?
   file << SVG::header << element << SVG::footer << std::endl ;  //füllen des Files
   file.close();
}
