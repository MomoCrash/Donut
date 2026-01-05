#include <process.h>
#include <signal.h>

#include "Light.h"
#include "Mesh.h"
#include "Screen.h"
#include "Settings.h"
#include "shapes/Prism.h"
#include "shapes/Torus.h"

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
    
    Prism mesh(40, 40, 40, settings);
    mesh.setPosition(0, 0, -5);
    Torus torus(10, 5, settings);
    torus.setPosition(0, 0, -10);

    Light light(settings);
    
    Screen screen(settings);
    while (end == 0)
    {
        screen.clear();

        mesh.Rotate(settings.getMeshRotationXPerFrame(), Mesh::Axis::X);
        mesh.Rotate(settings.getMeshRotationYPerFrame(), Mesh::Axis::Y);
        mesh.Rotate(settings.getMeshRotationZPerFrame(), Mesh::Axis::Z);

        torus.Rotate(settings.getMeshRotationXPerFrame(), Mesh::Axis::X);
        torus.Rotate(settings.getMeshRotationYPerFrame(), Mesh::Axis::Y);

        screen.display(torus, light);
        screen.display(mesh, light);
        screen.display();

        Sleep(settings.getFrameDuration());

    }
    
    printf(CONSOLE_CLEAR);
    printf(CONSOLE_BEGIN);
    
    return EXIT_SUCCESS;
}