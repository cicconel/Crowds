#include "agent.hpp"


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

