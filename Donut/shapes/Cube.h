#pragma once
#include "Prism.h"

class Cube : public Prism
{
public:
    Cube(float side, Settings const& settings)
        : Prism(side, side, side, settings)
    {
    }
};
