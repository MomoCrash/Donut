#include "Screen.h"

#include "defines.h"

Screen::Screen(int width, int height)
{
    if (width <= 0 || height <= 0) {
        std::cout << "Invalid width/height using default" << std::endl;
        width   = DEFAULT_WIDTH;
        height  = DEFAULT_HEIGHT;
    }
    m_pixels    = new char[width * height];
    m_size      = width * height;
    m_width     = width;
    m_height    = height;
}
void Screen::display()
{
    for (int i = 0; i < m_height; i++)
    {
            
        for (int j = 0; j < m_width; j++)
        {
            std::cout << "." ;
                
        }
        std::cout << std::endl;
    }
}
