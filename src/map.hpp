#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <vector>
#include "vector.hpp"


struct Obstacle
{
	bool loop;						// True if the shape is closed
	std::vector<Vector> corners;	// List of the obstacle's corners
};


class Map
{
public:
	/*** Attributes ***/
	double xMin, xMax, yMin, yMax;		// Size of the map ((yMax-yMin)/(xMax-xMin) is fixed)
	std::vector<Obstacle> obstacles;	// Walls and obstacles present in the environment
	
	
	/*** Constructors ***/
	Map();
	~Map();
	
	
	/*** Methods ***/
	// Zoom in the camera
	void zoomIn();
	// Zoom out the camera
	void zoomOut();
	// Translate the camera in the direction "direction"
	void move(Vector &direction);
    // Draws the map
    void draw();
};


#endif
