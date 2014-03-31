#include "agent.hpp"
#include <limits>
#include <math.h>
#include <GL/glut.h>  

/*** Constructors ***/

Agent::Agent()
	: position(0.0, 0.0)
	, velocity(0.0, 0.0)
	, desiredVelocity(1.0, 0.0)
	, gazing(1.0, 0.0)
	, bodyRay(0.5)
	, safetyDistance(0.2)
	, angleVision(1.7)
	, forces(0.0, 0.0)
{
}

Agent::~Agent()
{
}


/*** Methods ***/

void Agent::drivingForce()
{
	forces += (desiredVelocity - velocity) / 0.5;
}


void Agent::obstaclesForce(const std::vector<Obstacle> &obstacles)
{
	// Compute repulsion force for each obstacle
	std::vector<Obstacle>::const_iterator it;
	for (it = obstacles.begin(); it != obstacles.end(); it++)
	{
		// Compute the distance to the wall and the repulsion direction
		double dist = std::numeric_limits<double>::max();
		Vector direction;
		std::vector<Vector>::const_iterator itCorner1, itCorner2;
		for (itCorner1 = it->corners.begin(); itCorner1 != it->corners.end(); itCorner1++)
		{
			// [itCorner1, itCorner2] represents a segment of the obstacle
			if (itCorner1 != it->corners.end() - 1)
				itCorner2 = itCorner1 + 1;
			else if (it->loop)
				itCorner2 = it->corners.begin();
			else
				break;
			
			// Find the projection of the agent on this segment
			double l2 = squared_length((*itCorner2) - (*itCorner1));
			double r = dot(position - (*itCorner1), (*itCorner2) - (*itCorner1)) / l2;
			Vector projection;
			
			if (r < 0.0)		// Case where projection falls beyond the first point
				projection = (*itCorner1);
			else if (r > 1.0)	// Case where projection falls beyond the second point
				projection = (*itCorner2);
			else				// Case where projection falls on the segment
				projection = (*itCorner2) + r * ((*itCorner2) - (*itCorner1));
			
			double distCour = length(position - projection);
			if (distCour < dist)
			{
				dist = distCour;
				direction = normalize(position - projection);
			}
		}
		
		// Compute force
		forces += 10.0 * exp(-dist/0.1) * direction;
	}
}


Vector Agent::interactionForce(const Agent &agent)
{
	// Constants
	const double A = 4.5;
	const double gamma = 0.35;
	const double n1 = 2.0;
	const double n2 = 3.0;
	const double lambda = 2.0;
	
	// Variables
	Vector dij = agent.position - position;
	double dist = length(dij);
	Vector eij = dij / dist;
	Vector Dij = lambda * (velocity - agent.velocity) + eij;
	double Dij_norm = length(Dij);
	Vector T = Dij / Dij_norm;
	double B = gamma * Dij_norm;
	Vector N(-T.y, T.x);
	double theta = fabs(acos(dot(T, eij)));
	
	// Compute force
	return -A * exp(-dist / B) * (exp(-(n2 * B * theta) * (n2 * B * theta)) * T + exp(-(n1 * B * theta) * (n1 * B * theta)) * N);
}


//Draw a disk
#define DISK_PRECISION 20
void disk(double x, double y, double r)
{
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int n = 0; n <= DISK_PRECISION; ++n)
		{
			double const t = 2*M_PI*(double)n/(double)DISK_PRECISION;
			glVertex2f(x + sin(t)*r, y + cos(t)*r);
		}
	glEnd();
}


//Draw an agent
void Agent::draw()
{
	disk(position.x, position.y, bodyRay);
    //TODO : gazing direction
}
