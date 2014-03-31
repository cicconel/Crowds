#include "scene.hpp"
#include "tinyxml/tinyxml.h"

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

bool Scene::initialize(const char* filename)
{
	// Load the document
	TiXmlDocument doc(filename);
	if (!doc.LoadFile()) {
		std::cout << "ERROR, " << doc.ErrorRow() << ":" << doc.ErrorCol() << "; "
			<< "parse error: " << doc.ErrorDesc() << "\n";
		return false;
	}
	
	// Check for root element
	TiXmlElement *root = doc.RootElement();
	if (!root) {
		std::cout << "No root element.\n";
		return false;
	}
	
	
	/** Loading attributes **/
	
	root->QueryDoubleAttribute("timestep", &timestep);
	
		
	/** Loading the map **/
	
	// Set map attributes
	TiXmlElement* mapXml = root->FirstChildElement("map");
	mapXml->QueryDoubleAttribute("xMin", &map.xMin);
	mapXml->QueryDoubleAttribute("xMax", &map.xMax);
	mapXml->QueryDoubleAttribute("yMin", &map.yMin);
	mapXml->QueryDoubleAttribute("yMax", &map.yMax);
	
	// Set obstacles
	TiXmlElement* obsXml = mapXml->FirstChildElement("obstacle");
	while (obsXml)
	{
		Obstacle new_obstacle;
		
		int loop;
		obsXml->QueryIntAttribute("loop", &loop);
		new_obstacle.loop = (loop != 0) ? true : false;
		
		TiXmlElement* cornerXml = obsXml->FirstChildElement("corner");
		while (cornerXml)
		{
			Vector corner;
			cornerXml->QueryDoubleAttribute("x", &corner.x);
			cornerXml->QueryDoubleAttribute("y", &corner.y);
			new_obstacle.corners.push_back(corner);
			cornerXml = cornerXml->NextSiblingElement("corner");
		}
		
		map.obstacles.push_back(new_obstacle);
		
		obsXml = obsXml->NextSiblingElement("obstacle");
	}
	
	
	/** Loading the groups and agents **/
	
	TiXmlElement* groupsXml = root->FirstChildElement("groups");
	TiXmlElement* groupXml = groupsXml->FirstChildElement("group");
	while (groupXml)
	{
		Group *new_Group = new Group();
		
		// Set group's attributes
		TiXmlElement* destXml = groupXml->FirstChildElement("target");
		destXml->QueryDoubleAttribute("x", &new_Group->desiredPosition.x);
		destXml->QueryDoubleAttribute("y", &new_Group->desiredPosition.y);
		groupXml->QueryDoubleAttribute("b1", &new_Group->b1);
		groupXml->QueryDoubleAttribute("b2", &new_Group->b2);
		groupXml->QueryDoubleAttribute("b3", &new_Group->b3);
		groupXml->QueryDoubleAttribute("b3", &new_Group->b3);
		groupXml->QueryDoubleAttribute("threshold", &new_Group->threshold);
		groupXml->QueryDoubleAttribute("ColorR", &new_Group->colorR);
		groupXml->QueryDoubleAttribute("ColorG", &new_Group->colorG);
		groupXml->QueryDoubleAttribute("ColorB", &new_Group->colorB);
		Vector center(0.0, 0.0);
		
		// Set list of agents
		TiXmlElement* agentXml = groupXml->FirstChildElement("agent");
		while (agentXml)
		{
			Agent *new_Agent = new Agent();
			
			// Set agent's attributes
			TiXmlElement* posXml = agentXml->FirstChildElement("position");
			posXml->QueryDoubleAttribute("x", &new_Agent->position.x);
			posXml->QueryDoubleAttribute("y", &new_Agent->position.y);
			center += new_Agent->position;
			
			double speed;
			agentXml->QueryDoubleAttribute("speed", &speed);
			new_Agent->gazing = normalize(new_Group->desiredPosition - new_Agent->position);
			new_Agent->desiredVelocity = speed * new_Agent->gazing;
			
			agentXml->QueryDoubleAttribute("bodyRay", &new_Agent->bodyRay);
			agentXml->QueryDoubleAttribute("safetyDistance", &new_Agent->safetyDistance);
			agentXml->QueryDoubleAttribute("angleVision", &new_Agent->angleVision);
			
			// Add agent to group and to scene
			new_Group->agents.push_back(new_Agent);
			agents.push_back(new_Agent);
			agentXml = agentXml->NextSiblingElement("agent");
		}
		
		// Compute center
		new_Group->center = center / new_Group->agents.size();
		
		// Add group to scene
		groups.push_back(new_Group);
		groupXml = groupXml->NextSiblingElement("group");
	}
	
	return true;
}
