#include "Mesh.h"
#include "Screen.h"
#include "Settings.h"

int main(int argc, char* argv[])
{
    Settings settings(argc, argv);

    Mesh mesh(settings);
    mesh.GenerateSquare(20);
    mesh.Rotate(1.5708f / 2.0f, Mesh::Axis::Z);
    
    Screen screen(settings);
    screen.display(mesh);
    screen.display();

    while (true){}
    
    return 0;
}