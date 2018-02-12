#pragma once

#include "quadrat.h"
#include <memory>

class Zeichnung
{

    std::shared_ptr<Quadrat> mQuadrat;


public:
    Zeichnung(std::shared_ptr<Quadrat> quadrat = std::make_shared<Quadrat>());
    ~Zeichnung();

    Zeichnung& setQuadrat(std::shared_ptr<Quadrat> quadrat);
};

