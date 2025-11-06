
#include <windows.h>

#include <iostream>

#include "Screen.h"
#include "Settings.h"

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

int main(int argc, char* argv[])
{

    Settings settings(argc, argv);

    setupConsole();
    
    //printf(CURSOR_HIDE);
    
    Screen dispay(settings.getWidth(), settings.getHeight());

    std::cout << CONSOLE_RESET << CURSOR_HIDE << std::endl;
    dispay.display();
    std::cout << CURSOR_SHOW << std::endl;
    
    return 0;
}