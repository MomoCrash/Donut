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
    m_size      = width * height;
    m_pixels    = new char[m_size];
    m_width     = width;
    m_height    = height;

    setupConsole();
    initialize();
}

Screen::Screen(Settings& settings)
{
    m_width     = settings.getWidth();
    m_height    = settings.getHeight();

    if (m_width <= 0 || m_height <= 0) {
        std::cout << "Invalid width/height using default" << std::endl;
        m_width   = DEFAULT_WIDTH;
        m_height  = DEFAULT_HEIGHT;
    }

    m_size      = m_width * m_height;
    m_pixels    = new char[m_size];

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

void Screen::setPosition(int x, int y)
{
    m_positionX = x;
    m_positionY = y;
}

void Screen::display(Mesh const& mesh)
{
    for (auto const& vertex : mesh.GetVertices())
    {
        int index = (float)m_width * (float)vertex.y +(float) vertex.x;
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
