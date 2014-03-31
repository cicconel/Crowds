#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include "map.hpp"
#include "agent.hpp"
#include "group.hpp"
#include <iostream>
#include <cstring>


class Scene
{
public:
	/*** Attributes ***/
	std::vector<Agent *> agents;	// List of people in the group
	std::vector<Group *> groups;	// All the groups in the scene
	Map map;						// Environment of the scene
	double timestep;				// Timestep for forces computation
	
	
	/*** Constructors ***/
	Scene();
	~Scene();
	
	
	/*** Methods ***/
	// Initializes the scene by parsing a xml document
	bool initialize(const char* filename);
	// Updates the position of all agents
	void update();
	// Displays the map and the agents
	void display();
	// Initializes the display window (glut)
	void init_window();
};


#endif
