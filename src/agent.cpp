#include "agent.hpp"
#include <GL/glut.h>  

/*** Constructors ***/

Agent::Agent()
	: position()
	, velocity()
	, desiredVelocity(1.0, 0.0)
	, gazing(1.0, 0.0)
	, bodyDiameter(0.5)
	, safetyDistance(0.2)
	, angleVision(90.0)
{
}

Agent::~Agent()
{
}


/*** Methods ***/

void Agent::draw()
{
	//disk(position.x, position.y, bodyDiameter);
}


//Draw a disk
//TODO : change position (drawing_tools file?)
#define DISK_PRECISION 20
void disk(float x, float y, float r)
{
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int n = 0; n <= DISK_PRECISION; ++n)
		{
			float const t = 2*M_PI*(float)n/(float)DISK_PRECISION;
			glVertex2f(x + sin(t)*r, y + cos(t)*r);
		}
	glEnd();
}

