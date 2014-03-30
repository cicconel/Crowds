#include "scene.hpp"

/*** Constructors ***/

Scene::Scene()
	: agents()
	, groups()
	, map()
	, timestep(0.01)
{
}

Scene::~Scene()
{
	agents.clear();
	groups.clear();
}


/*** Methods ***/

// In scene_update and scene_display
