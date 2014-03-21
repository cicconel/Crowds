#include "scene.hpp"
#include <GL/glut.h>  

void Scene::display()
{
    //Scene initialization
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //Obstacle rendering

    //Agent rendering

    glFlush();

}

//Trick to handle the fact that display belongs to a class (scene).
//http://stackoverflow.com/questions/5008266/callback-function-in-freeglut-from-object
Scene * ptr_global_instance = NULL;
extern "C"
void display_callback(){
    ptr_global_instance->display();
}

//Initializes the window for the display
void Scene::init_window(){
     int height = 720;
     float ratio_f = (map.yMax - map.yMin)/(map.xMax - map.xMin);
     int ratio_i = int(ratio_f + 0.5);
     glutInitWindowSize(height*ratio_i,height);
     glutInitWindowPosition(0,0);
     glutCreateWindow("Crowd Simulator V0");
     ::ptr_global_instance = this;
     ::glutDisplayFunc(::display_callback);
     glutMainLoop(); 
}



