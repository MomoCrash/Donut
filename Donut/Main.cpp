#include "Mesh.h"
#include "Screen.h"
#include "Settings.h"

int main(int argc, char* argv[])
{
    Settings settings(argc, argv);

    Mesh mesh(settings.getResolution());
    mesh.GenerateSquare(2);
    
    Screen screen(settings.getWidth(), settings.getHeight());
    screen.display(mesh);
    screen.display();
    
    mesh.Debug();
    
    return 0;
}