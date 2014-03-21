#include "group.hpp"
#include <GL/glut.h>  

/*** Constructors ***/

Group::Group()
	: agents(NULL)
	, desiredPosition(1.0, 0.0)
	, center()
	, b1(4.0)
	, b2(1.0)
	, b3(1.0)
	, threshold(0.2)
	, colorR(1.0)
	, colorG(1.0)
	, colorB(1.0)
{
}

Group::~Group()
{
}


/*** Methods ***/

//draw a group
void Group::draw() 
{   
    glColor3f(colorR,colorG,colorB);
    
    std::vector<Agent>::iterator it;
    for (it = agents.begin() ; it != agents.end(); ++it) {
        (*it).draw();
    }

}

