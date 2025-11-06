#pragma once

#include "framework.h"

class Screen
{
public:
    Screen(int width, int height);
    ~Screen();
    
    void display();

private:
    void setupConsole();
    
    char*  m_pixels ;
    int    m_size   ;
    int    m_width, m_height ;
};
