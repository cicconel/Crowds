#ifndef _AGENT_HPP_
#define _AGENT_HPP_

#include "vector.hpp"


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
	
	
	/*** Constructors ***/
	Agent();
	~Agent();
	
	
	/*** Methods ***/
	// Draw an agent
	void draw();
	
};


#endif
