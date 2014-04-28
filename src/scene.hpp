#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include "map.hpp"
#include "agent.hpp"
#include "group.hpp"
#include "imageio.hpp"
#include <iostream>
#include <cstring>
#include <QKeyEvent>

class Scene
{
public:
	/*** Attributes ***/
	std::vector<Agent *> agents;	// List of people in the group
	std::vector<Group *> groups;	// All the groups in the scene
	Map map;						// Environment of the scene
	double timestep;				// Timestep for forces computation

    unsigned int step;              // step in the running time
    bool pause;						// True if simulation is paused, false otherwise
	bool record;				    // True if simulation is recorded, false otherwise

	
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
