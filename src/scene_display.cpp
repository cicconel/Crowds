#include "scene.hpp"
#include <GL/glut.h>  
#include <math.h>



void Scene::display()
{
	// Scene initialization
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Preliminary scaling : t
	// frame [xmin,xmax]*[ymin,ymax]
	double x_min = map.xMin;
	double x_max = map.xMax;
	double y_min = map.yMin;
	double y_max = map.yMax;
	
	glLoadIdentity();
	glTranslatef((x_max+x_min)/(x_min-x_max), (y_max+y_min)/(y_min-y_max), 0.0);
	glScalef(2.0/(x_max-x_min), 2.0/(y_max-y_min), 0.0);
   
	//Obstacle rendering
	map.draw(); 
	
	//Groups (Agents) rendering
	std::vector<Group *>::iterator it;
	for (it = groups.begin(); it != groups.end(); ++it)
	{
		(*it)->draw();
	}

	glFlush();
}

// Trick to handle the fact that display belongs to a class (scene).
// http://stackoverflow.com/questions/5008266/callback-function-in-freeglut-from-object
Scene * ptr_global_instance = NULL;
extern "C"
void display_callback()
{
	if (!ptr_global_instance->pause) {
		ptr_global_instance->update();
	}
	ptr_global_instance->display();
	glutPostRedisplay();
}

void keyboard_basic(unsigned char key, int x, int y)  
{
	 switch (key) 
	{
		//Play/Pause
		case 'p' : 
			ptr_global_instance->pause = !ptr_global_instance->pause;
			break;
	
		//Zoom in
		case 'i' : 
			ptr_global_instance->map.zoomIn();
			break;
		
		//Zoom out
		case 'o' :
			ptr_global_instance->map.zoomOut();
			break;

		//Translate left
		case 'q' :
			ptr_global_instance->map.move(Vector(-1,0));
			break;

		//Translate right
		case 'd' :
			ptr_global_instance->map.move(Vector(1,0));
			break;

		//Translate up
		case 'z' : 
			ptr_global_instance->map.move(Vector(0,1));
			break;

		//Translate down 
		case 's' : 
			ptr_global_instance->map.move(Vector(0,-1));
			break;
	}
}

//Initializes the window for the display
void Scene::init_window()
{
	 int height = 720;
	 double ratio_f = (map.yMax - map.yMin)/(map.xMax - map.xMin);
	 int ratio_i = int(ratio_f + 0.5);
	 glutInitWindowSize(height*ratio_i,height);
	 glutInitWindowPosition(0,0);
	 glutCreateWindow("Crowd Simulator V0");
	 ::ptr_global_instance = this;
	 ::glutKeyboardUpFunc(::keyboard_basic); 
	 ::glutDisplayFunc(::display_callback);
}


