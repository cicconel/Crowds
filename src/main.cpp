#include "scene.hpp"

int main(int argc, char* argv[])
{
	Scene scene;
	while (true)
	{
		scene.update();
		scene.display();
	}
	
	return 0;
}
