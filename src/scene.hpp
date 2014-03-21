#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include "map.hpp"
#include "agent.hpp"
#include "group.hpp"


class Scene
{
public:
	/*** Attributes ***/
	std::vector<Group> groups;	// All the groups in the scene
	Map map;					// Environment of the scene
	
	
	/*** Constructors ***/
	Scene();
	~Scene();
	
	
	/*** Methods ***/
	// Updates the position of all agents
	void update();
	// Displays the map and the agents
	void display();
    // Initializes the display window (glut)
    void init_window();
};


#endif
