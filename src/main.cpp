#include "scene.hpp"
#include <GL/glut.h> 

int main(int argc, char* argv[])
{
	// Initialize glut
	glutInit(&argc, argv);   
	
	// Initialize scene
	Scene scene;
	if (argc > 1 && !scene.initialize(argv[1]))
		return 1;
	scene.init_window();

	while (true)
	{
//std::cout<<scene.agents[0]->position.x<<" "<<scene.agents[0]->position.y<<std::endl;
		scene.update();
		
		//TODO : useful since glutDisplayFunc(display)?
		scene.display();
	}
	
	return 0;
}
