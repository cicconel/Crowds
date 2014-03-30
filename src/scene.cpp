#include "scene.hpp"

/*** Constructors ***/

Scene::Scene()
	: agents()
	, groups()
	, map()
{
}

Scene::~Scene()
{
	agents.clear();
	groups.clear();
}


/*** Methods ***/

// In scene_update and scene_display
