#include "group.hpp"


/*** Constructors ***/

Group::Group()
	: agents(NULL)
	, desiredPosition(1.0, 0.0)
	, center()
	, b1(4.0)
	, b2(1.0)
	, b3(1.0)
	, threshold(0.2)
	, colorR(1.0)
	, colorG(1.0)
	, colorB(1.0)
{
}

Group::~Group()
{
}


/*** Methods ***/

