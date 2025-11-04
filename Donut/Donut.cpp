
#include <windows.h>

#include <iostream>

#define CONSOLE_CLEAR "\033[2J"
#define CONSOLE_RESET "\033c"
#define CONSOLE_BEGIN "\033[H"

#define CURSOR_HIDE   "\033[?25l"
#define CURSOR_SHOW   "\033[?25m"

static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

void setupConsole()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
    DWORD mode; 
    GetConsoleMode(hConsole, &mode); 
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

class Display
{
public:
    Display(int width, int height)
    {
        m_pixels    = new char[width * height];
        m_size      = width * height;
        m_width     = width;
        m_height    = height;
    }
    ~Display()
    {
        delete[] m_pixels;
    }

    void show()
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

private:
    char*  m_pixels ;
    int    m_size   ;
    int    m_width, m_height ;
};

int main(int argc, char* argv[])
{

    setupConsole();
    
    //printf(CURSOR_HIDE);
    
    Display dispay(100, 20);

    std::cout << CONSOLE_RESET << CURSOR_HIDE << std::endl;
    dispay.show();
    std::cout << CURSOR_SHOW << std::endl;
    
    return 0;
}