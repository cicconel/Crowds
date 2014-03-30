#include "map.hpp"


/*** Constructors ***/

Map::Map()
	: xMin(-1000.0)
	, xMax(1000.0)
	, yMin(-1000.0)
	, yMax(1000.0)
	, obstacles()
{
}

Map::~Map()
{
}


/*** Methods ***/

void Map::zoomIn()
{
	double factor = 1.0/1.2;
	xMin *= factor;
	xMax *= factor;
	yMin *= factor;
	yMax *= factor;
}

void Map::zoomOut()
{
	double factor = 1.2;
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

