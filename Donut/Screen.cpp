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

    m_positionX = settings.getScreenPosition();
    m_positionY = settings.getScreenPosition()/2;

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

void Screen::display(Mesh const& mesh, Light const& light)
{

    for (int i = 0; i < mesh.GetVertices().size(); ++i)
    {

        Vertex newVertex = mesh.GetVertices()[i];

        _ProjectInCenterScreenSpace(mesh.getPositionZ(), newVertex);
        _ProjectInTopLeftScreenSpace(newVertex);
        
        newVertex.x += mesh.getPositionX();
        newVertex.y += mesh.getPositionY();
        
        int u = static_cast<int>(round(newVertex.x));
        int v = static_cast<int>(round(newVertex.y));

        if (u < 0 || v < 0 || u >= m_width || v >= m_height) continue;

        int index = m_width * v + u;
        
        if (index < 0 || index >= m_size) continue;
        
        float L = newVertex.ComputeIllumination(light);
        float ooz = 1.f / newVertex.z;

        if (ooz <= m_oozBuffer[index]) continue;

        if (L < 0)
        {
            m_oozBuffer[index] = ooz;
            m_pixels[index] = '.';
        } else
        {
            int luminance_index = static_cast<int>(L * 11.f);

            m_oozBuffer[index] = ooz;
            m_pixels[index] = ".,-~:;=!X#$@"[luminance_index];
        }
        
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

void Screen::clear()
{
    std::cout << CONSOLE_BEGIN << std::endl;
    for (int i = 0; i < m_size; ++i)
    {
        m_pixels[i]     = m_backgroundChar;
        m_oozBuffer[i]  = -FLT_MAX;
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
}

void Screen::_ProjectInCenterScreenSpace(float const& z, Vertex& vertex)
{
    vertex.x = (vertex.x * m_viewPositionZ) / z;
    vertex.y = (vertex.y * m_viewPositionZ) / z / 2.0f;
    vertex.z += z;
}

void Screen::_ProjectInTopLeftScreenSpace(Vertex& vertex)
{
    vertex.x += m_width / 2;
    vertex.y += m_height / 2;
}

bool Screen::_IsVertexInScreen(int u, int v)
{
    return u >= 0 && u < m_width && v >= 0 && v < m_height;
}