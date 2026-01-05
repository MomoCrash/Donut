#pragma once

#include "framework.h"
#include "Mesh.h"
#include "Settings.h"

class Light;
class Mesh;

class Screen
{
public:
    Screen(int width, int height);
    Screen(Settings& settings);
    ~Screen();

    void display(Mesh const& mesh, Light const& light);
    void display();
    void clear();
    void initialize();
    
    void setPosition(int x, int y);

    void _ProjectInCenterScreenSpace(float const& z, Vertex& vertex);
    void _ProjectInTopLeftScreenSpace(Vertex& vertex);
    bool _IsVertexInScreen(int u, int v);

private:
    void setupConsole();
    
    char*  m_pixels ;
    float* m_oozBuffer ;
    
    int    m_size   ;
    int    m_width, m_height ;
    int    m_positionX, m_positionY ;
    float  m_viewPositionZ     = 3.33f;

    char m_backgroundChar;
    char m_meshChar;
};
