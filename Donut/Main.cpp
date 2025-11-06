#include "Screen.h"
#include "Settings.h"

int main(int argc, char* argv[])
{
    Settings settings(argc, argv);
    
    Screen screen(settings.getWidth(), settings.getHeight());
    screen.display();
    
    return 0;
}