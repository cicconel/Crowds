#ifndef _GROUP_HPP_
#define _GROUP_HPP_

#include <vector>
#include "vector.hpp"
#include "agent.hpp"


class Group
{
public:
	/*** Attributes ***/
	std::vector< Agent > agents;	    // List of people in the group
	Vector desiredPosition;				// Target position
	Vector center;						// Center of mass
	float b1;							// Strength of social interaction
	float b2;							// Strength of attraction effect
	float b3;							// Repulsion strength
	float threshold;					// Threshold for attraction effect
	float colorR, colorG, colorB;		// Color of the group
	
	
	/*** Constructors ***/
	Group();
	~Group();
	
	
	/*** Methods ***/
	// Draw a group
	void draw();
	
};


#endif
