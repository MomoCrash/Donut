#include <process.h>
#include <signal.h>

#include "Mesh.h"
#include "Screen.h"
#include "Settings.h"

// Indicateur de fin de programme
int end = 0;
void OnKill(sig_atomic_t sig) {
    end = 1;
    printf("\nSIGINT attrapé, on stop le programme %i\n", _getpid());
}

int main(int argc, char* argv[])
{

    if(signal(SIGINT, OnKill) == SIG_ERR){
        std::cout << "Erreur à l'enregistrement du gestionnaire de signaux !\n";
    }
    
    Settings settings(argc, argv);
    
    Mesh mesh(settings);
    mesh.GenerateTorus(10, 2);
    
    Screen screen(settings);

    while (end == 0)
    {
        screen.clear();

        mesh.Rotate(settings.getMeshRotationXPerFrame(), Mesh::Axis::X);
        mesh.Rotate(settings.getMeshRotationYPerFrame(), Mesh::Axis::Y);
        mesh.Rotate(settings.getMeshRotationZPerFrame(), Mesh::Axis::Z);
        
        screen.display(mesh);
        screen.display();

        Sleep(settings.getFrameDuration());

    }
    
    printf(CONSOLE_CLEAR);
    printf(CONSOLE_BEGIN);
    
    return EXIT_SUCCESS;
}