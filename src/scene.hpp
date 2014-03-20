#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include "map.hpp"
#include "agent.hpp"
#include "group.hpp"


class Scene
{
public:
	/*** Attributes ***/
	std::vector<Agent> agents;	// All the agents in the scene
	std::vector<Group> groups;	// All the groups in the scene
	Map map;					// Environment of the scene
	
	
	/*** Constructors ***/
	Scene();
	~Scene();
	
	
	/*** Methods ***/
	// Update the position of all agents
	void update();
	// Display the map and the agents
	void display();
};


#endif
