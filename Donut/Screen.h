#pragma once
#include <iostream>

class Screen
{
public:
    Screen(int width, int height);

    ~Screen()
    {
        delete[] m_pixels;
    }

    void display();

private:
    char*  m_pixels ;
    int    m_size   ;
    int    m_width, m_height ;
};
