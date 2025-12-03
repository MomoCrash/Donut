#include "Mesh.h"
#include "Screen.h"
#include "Settings.h"

int main(int argc, char* argv[])
{
    Settings settings(argc, argv);

    Mesh mesh(settings);
    mesh.GenerateTorus(5, 2);
    
    Screen screen(settings);
    screen.display(mesh);
    screen.display();
    
    mesh.Debug();

    while (true){}
    
    return 0;
}