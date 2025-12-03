#include "Screen.h"

#include "defines.h"
#include "Mesh.h"

#include "math.h"

Screen::Screen(int width, int height)
{
    if (width <= 0 || height <= 0) {
        std::cout << "Invalid width/height using default" << std::endl;
        width   = DEFAULT_WIDTH;
        height  = DEFAULT_HEIGHT;
    }
    m_size      = width * height;
    m_pixels    = new char[m_size];
    m_oozBuffer = new float[m_size];
    m_width     = width;
    m_height    = height;

    m_backgroundChar = '.';
    m_meshChar = 'x';

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

    m_backgroundChar = settings.getScreenBackground();
    m_meshChar = settings.getScreenMeshProjection();
    
    m_size      = m_width * m_height;
    m_pixels    = new char[m_size];
    m_oozBuffer = new float[m_size];

    m_positionX = m_width / 2;
    m_positionY = m_height / 2;

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
        m_pixels[i] = m_backgroundChar;
        m_oozBuffer[i] = -FLT_MAX;
    }
}

void Screen::setPosition(int x, int y)
{
    m_positionX = x;
    m_positionY = y;
}

void Screen::display(Mesh const& mesh)
{

    float meshPositonZ      = 5;
    float viewPositionZ     = 3.33f;

    for (Mesh::Vertex vertex : mesh.GetVertices())
    {


        float y_prime = (vertex.y  * viewPositionZ) / meshPositonZ;
        float x_prime = (vertex.x  * viewPositionZ) / meshPositonZ;

        x_prime += m_positionX;
        y_prime += m_positionY;

        int u = round(x_prime);
        int v = round(y_prime);

        int index = m_width * v + u;

        float ooz = 1.f / vertex.z;

        if (ooz < m_oozBuffer[index]) continue;
        if (index < 0 || index >= m_size) continue;

        m_pixels[index] = m_meshChar;
        m_oozBuffer[index] = ooz;
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
