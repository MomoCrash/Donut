#pragma once
#include "Circle.h"

class HalfCircle : public Circle
{
public:
    HalfCircle(float radius, Settings const& settings)
        : Circle(radius, PI, settings)
    {
        
    }
};
