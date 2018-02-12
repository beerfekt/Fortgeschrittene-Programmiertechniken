#include "zeichnung.h"

Zeichnung::Zeichnung(std::shared_ptr<Quadrat> quadrat)  //Bei unique_ptr<Quadr..>  würde die Eigentümerschaft vom aufrufer an Zeichnung gehen
    : mQuadrat(std::move(quadrat))
{
    if (mQuadrat) {}
}


Zeichnung::~Zeichnung(){
    if (mQuadrat){}
}


Zeichnung& Zeichnung::setQuadrat(std::shared_ptr<Quadrat> quadrat){  //Hier ebenso
      if (quadrat){
        mQuadrat = std::move(quadrat);
        return *this;
      }
}
