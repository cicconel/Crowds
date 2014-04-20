#include "group.hpp"
#include <math.h>
#include <GL/glut.h>  

/*** Constructors ***/

Group::Group()
	: agents()
	, desiredPosition(0.0, 0.0)
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

void Group::groupForce()
{
	std::vector<Agent *>::iterator it;
	for (it = agents.begin(); it != agents.end(); it++)
	{
		Vector posCenter = center - (*it)->position;
		Vector posCenter_norm = normalize(posCenter);
		Vector velocity_norm = normalize((*it)->velocity);
		
		// Compute vision force (if necessary), and update gazing vector
		double angleCenter = fabs(acos(dot(velocity_norm, posCenter_norm)));
		if (angleCenter > (*it)->angleVision)
		{
			double alpha = angleCenter - (*it)->angleVision;
			(*it)->forces -= b1 * alpha * (*it)->velocity;
			(*it)->gazing = Vector(-posCenter_norm.y, posCenter_norm.x);
			if (dot((*it)->gazing, velocity_norm) < 0.0)
				(*it)->gazing = -(*it)->gazing;
		}
		else
		{
			(*it)->gazing = velocity_norm;
		}
		
		// Compute attraction force
		if (length(posCenter) > threshold)
		{
			(*it)->forces += b2 * posCenter_norm;
		}
		
		// Compute repulsion force
		std::vector<Agent *>::iterator it2;
		for (it2 = it + 1; it2 != agents.end(); it2++)
		{
			Vector wik = (*it2)->position - (*it)->position;
			if (length(wik) < (*it)->bodyRay + (*it)->safetyDistance + (*it2)->bodyRay + (*it2)->safetyDistance)
			{
				Vector force = -b3 * normalize(wik);
				(*it)->forces += force;
				(*it2)->forces += force;
			}
		}
	}
}


void Group::update(double dt)
{
	center = Vector(0.0, 0.0);	
	std::vector<Agent *>::iterator it;
	for (it = agents.begin(); it != agents.end(); it++)
	{
		// Update velocity
		(*it)->velocity += dt * (*it)->forces;
		
		// Update position
		(*it)->position += dt * (*it)->velocity;
		
		// Update desired velocity
		(*it)->desiredVelocity = length((*it)->desiredVelocity) * normalize(desiredPosition - (*it)->position);
		
		// Set forces to 0 for next loop
		(*it)->forces = Vector(0.0, 0.0);
		
		// Prepare update center of mass
		center += (*it)->position;
	}
	
	// Update center of mass
	center /= agents.size();
}


void Group::draw() 
{  
	std::vector<Agent *>::iterator it;
	for (it = agents.begin(); it != agents.end(); ++it)
	{
		glColor3f(colorR, colorG, colorB);
		(*it)->draw();
	}
}

