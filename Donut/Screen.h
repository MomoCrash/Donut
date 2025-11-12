#pragma once

#include "framework.h"

class Mesh;

class Screen
{
public:
    Screen(int width, int height);
    ~Screen();

    void display(Mesh& mesh);
    void display();
    void initialize();

private:
    void setupConsole();
    
    char*  m_pixels ;
    int    m_size   ;
    int    m_width, m_height ;
};
