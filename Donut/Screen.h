#pragma once

#include "framework.h"
#include "Settings.h"

class Mesh;

class Screen
{
public:
    Screen(int width, int height);
    Screen(Settings& settings);
    ~Screen();

    void display(Mesh const& mesh);
    void display();
    void initialize();
    
    void setPosition(int x, int y);

private:
    void setupConsole();
    
    char*  m_pixels ;
    int    m_size   ;
    int    m_width, m_height ;
    int    m_positionX, m_positionY ;
};
