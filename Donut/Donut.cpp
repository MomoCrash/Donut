
#include <windows.h>

#include <iostream>

#define CONSOLE_CLEAR "\033[2J"
#define CONSOLE_RESET "\033c"
#define CONSOLE_BEGIN "\033[H"
#define CURSOR_HIDE   "\033[?25l"

static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

void setupConsole()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
    DWORD mode; 
    GetConsoleMode(hConsole, &mode); 
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

// https://stackoverflow.com/a/67693748/31649484
void showConsoleCursor(const bool show) {
#if defined(_WIN32)
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(handle, &cci);
    cci.bVisible = show; // show/hide cursor
    SetConsoleCursorInfo(handle, &cci);
#elif defined(__linux__)
    cout << (show ? "\033[?25h" : "\033[?25l"); // show/hide cursor
#endif // Windows/Linux
}

int main(int argc, char* argv[])
{

    setupConsole();
    
    printf(CURSOR_HIDE);
    
    std::cout << "Hello world " << std::endl;

    printf(CONSOLE_RESET);
    
    std::cout << "Hello world " << std::endl;


    while (true)
    {
    }
    return 0;
}