
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
        m_pixels = new char[width * height];
        m_size   = width * height;
    }

private:
    char*  m_pixels ;
    int    m_size   ;
};

int main(int argc, char* argv[])
{

    setupConsole();
    
    //printf(CURSOR_HIDE);
    
    std::cout << "Hello world " << std::endl;

    printf(CONSOLE_RESET);
    printf(CURSOR_HIDE);
    
    std::cout << "Hello world " << std::endl;

    printf(CURSOR_SHOW);
    
    return 0;
}