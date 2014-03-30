#include "map.hpp"


/*** Constructors ***/

Map::Map()
	: xMin(-10.0)
	, xMax(10.0)
	, yMin(-10.0)
	, yMax(10.0)
	, obstacles()
{
}

Map::~Map()
{
}


/*** Methods ***/

void Map::zoomIn()
{
	float factor = 1.0/1.2;
	xMin *= factor;
	xMax *= factor;
	yMin *= factor;
	yMax *= factor;
}

void Map::zoomOut()
{
	float factor = 1.2;
	xMin *= factor;
	xMax *= factor;
	yMin *= factor;
	yMax *= factor;
}

void Map::move(Vector &direction)
{
	Vector dir_factor = normalize(direction) * (yMax-yMin) * 0.01;
	xMin += dir_factor.x;
	xMax += dir_factor.x;
	yMin += dir_factor.y;
	yMax += dir_factor.y;
}

