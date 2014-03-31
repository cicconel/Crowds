#include "map.hpp"
#include <GL/glut.h>  


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

void Map::draw()
{
    
	std::vector<Obstacle>::iterator it_obs;
	std::vector<Vector>::iterator it_corn;
    glColor3f(1.0,1.0,1.0); //White for all obstacles
    
    for (it_obs = obstacles.begin() ; it_obs != obstacles.end() ; it_obs++) {
    
        if (it_obs->loop) {
            //Closed polygon
            glBegin(GL_LINE_LOOP);
            for (it_corn = it_obs->corners.begin() ; it_corn != it_obs->corners.end() ; it_corn++) {
                glVertex2f(it_corn->x,it_corn->y); 
            }
            glEnd();
        } else {
            glBegin(GL_LINE_STRIP);
            //Open polygon
            for (it_corn = it_obs->corners.begin() ; it_corn != it_obs->corners.end() ; it_corn++) {
                glVertex2f(it_corn->x,it_corn->y); 
            }
            glEnd();
        
        }

    }

}
