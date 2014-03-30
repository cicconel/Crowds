#ifndef _AGENT_HPP_
#define _AGENT_HPP_

#include "vector.hpp"
#include "map.hpp"


class Agent
{
public:
	/*** Attributes ***/
	Vector position;		// Current position
	Vector velocity;		// Current velocity
	Vector desiredVelocity;	// Desired velocity
	Vector gazing;			// Gazing direction (must be unitary)
	double bodyRay;			// Size of the agent
	double safetyDistance;	// Safety distance
	double angleVision;		// Angle of visibility around gazing direction (in degree)
	Vector forces;			// Forces applied on the agent
	
	
	/*** Constructors ***/
	Agent();
	~Agent();
	
	
	/*** Methods ***/
	// Compute the driving force and add it to the vector forces
	void drivingForce();
	// Compute the repulsive effect of obstacles and add it to the vector forces
	void obstaclesForce(const std::vector<Obstacle> &obstacles);
	// Compute the interaction force another pedestrian
	Vector interactionForce(const Agent &agent);
	
	// Draw an agent
	void draw();
};


#endif
