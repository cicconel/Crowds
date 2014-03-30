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
	Vector gazing;			// Gazing direction
	float bodyDiameter;		// Size of the agent
	float safetyDistance;	// Safety distance
	float angleVision;		// Angle of visibility around gazing direction (in degree)
	Vector forces;			// Forces applied on the agent
	
	
	/*** Constructors ***/
	Agent();
	~Agent();
	
	
	/*** Methods ***/
	// Draw an agent
	void draw();
	
	// Compute the driving force and add it to the vector forces
	void drivingForce();
	// Compute the repulsive effect of obstacles and add it to the vector forces
	void obstaclesForce(const std::vector<Obstacle> &obstacles);
	// Compute the interaction force with other pedestrians and add it to the vector forces
	void interactionForce(const std::vector<Agent *> &agents, std::vector<Agent *>::iterator itMe);
	// Update position and velocity (once forces is computed)
	void update(double dt);
};


#endif
