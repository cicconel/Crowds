#include "scene.hpp"
#include <GL/glut.h> 

int main(int argc, char* argv[])
{
    //Initalizing glut
    glutInit(&argc, argv);   
    
    Scene scene;
    scene.init_window();

    while (true)
	{
		scene.update();
        
        //TODO : useful since glutDisplayFunc(display)?
		//scene.display();
	}
	
	return 0;
}
