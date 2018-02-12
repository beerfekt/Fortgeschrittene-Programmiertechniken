#pragma once
#include <string>
#include <fstream>

class SVG
{ 
    std::ofstream file;
    const std::string element;
    std::string url;
    static const std::string header;
    static const std::string footer;
public:
    SVG( const std::string& fileName, const std::string element);  //Valider Zustand geprüft (beim öffnen)
    ~SVG();  //Beim Schließen wird file erstellt
};


