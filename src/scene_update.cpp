#include "scene.hpp"

#define TIMESTEP 0.001


void Scene::update()
{
	// Compute forces applied on each agent
	std::vector<Agent *>::iterator itA;
	for (itA = agents.begin(); itA != agents.end(); itA++)
	{
		(*itA)->forces = Vector(0.0, 0.0);
		(*itA)->drivingForce();
		(*itA)->obstaclesForce(map.obstacles);
		(*itA)->interactionForce(agents, itA);
	}
	
	// Compute forces of group interactions
	std::vector<Group *>::iterator itG;
	for (itG = groups.begin(); itG != groups.end(); itG++)
	{
		(*itG)->groupForce();
	}
	
	// Update agents position and velocity
	for (itA = agents.begin(); itA != agents.end(); itA++)
	{
		(*itA)->update(TIMESTEP);
	}
}
