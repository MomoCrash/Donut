#pragma once
#include "Rectangle.h"

class Square : public Rectangle
{
public:
    Square(float size, Settings const& settings)
        : Rectangle(size, size, settings){}
};
