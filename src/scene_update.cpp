#include "scene.hpp"


void Scene::update()
{
	// Compute forces applied on each agent
	std::vector<Agent *>::iterator itA;
	for (itA = agents.begin(); itA != agents.end(); itA++)
	{
		// Driving force
		(*itA)->drivingForce();
		
		// Obstacles and walls force
		(*itA)->obstaclesForce(map.obstacles);
		
		// Interaction force
		std::vector<Agent *>::iterator itA2;
		for (itA2 = itA + 1; itA2 != agents.end(); itA2++)
		{
			Vector force = (*itA)->interactionForce(**itA2);
			(*itA)->forces += force;
			(*itA2)->forces -= force;
		}
	}
	
	// Compute forces of group interactions
	std::vector<Group *>::iterator itG;
	for (itG = groups.begin(); itG != groups.end(); itG++)
	{
		(*itG)->groupForce();
	}
	
	// Update all data of agents and groups
	for (itG = groups.begin(); itG != groups.end(); itG++)
	{
		(*itG)->update(timestep);
	}
}
