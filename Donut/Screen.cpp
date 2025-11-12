#include "Screen.h"

#include "defines.h"
#include "Mesh.h"

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

    setupConsole();
    initialize();
}

Screen::~Screen()
{
    delete[] m_pixels;
}

void Screen::initialize()
{
    for (int i = 0; i < m_size; ++i)
    {
        m_pixels[i] = '.';
    }
}

void Screen::display(Mesh& mesh)
{
    for (auto vertex : mesh.GetVertices())
    {
        int index = m_width * vertex.y + vertex.x;
        m_pixels[index] = 'x';
    }
}

void Screen::display()
{
    for (int i = 0; i < m_size; ++i)
    {
        std::cout << m_pixels[i];

        if ((i+1) % m_width == 0)
            std::cout << std::endl;
    }
}

void Screen::setupConsole()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
    DWORD mode; 
    GetConsoleMode(hConsole, &mode); 
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    std::cout << CONSOLE_RESET << CURSOR_HIDE << std::endl;
    std::cout << CURSOR_SHOW << std::endl;
}
