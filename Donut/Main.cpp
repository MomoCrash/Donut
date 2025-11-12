#include "Mesh.h"
#include "Screen.h"
#include "Settings.h"

int main(int argc, char* argv[])
{
    Settings settings(argc, argv);

    Mesh mesh(settings.getResolution());
    mesh.AddVertex({-1, -1, 0});
    mesh.AddVertex({-1, 1, 0});
    mesh.AddVertex({1, -1, 0});
    mesh.AddVertex({1, 1, 0});

    
    Screen screen(settings.getWidth(), settings.getHeight());
    screen.display();
    
    mesh.Debug();
    
    return 0;
}