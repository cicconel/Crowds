#ifndef _GROUP_HPP_
#define _GROUP_HPP_

#include <vector>
#include "vector.hpp"
#include "agent.hpp"


class Group
{
public:
	/*** Attributes ***/
	std::vector<Agent *> agents;	   	// List of people in the group
	Vector desiredPosition;				// Target position
	Vector center;						// Center of mass
	double b1;							// Strength of social interaction
	double b2;							// Strength of attraction effect
	double b3;							// Repulsion strength
	double threshold;					// Threshold for attraction effect
	double colorR, colorG, colorB;		// Color of the group
	
	
	/*** Constructors ***/
	Group();
	~Group();
	
	
	/*** Methods ***/
	// Compute the force of interaction with other group members for each agent
	void groupForce();
	// Update data of this class and of every agent of the group
	void update(double dt);
	
	// Draw a group
	void draw();
};


#endif
