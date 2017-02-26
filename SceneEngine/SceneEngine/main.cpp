//#include "../Dependencies/glew/glew.h"
//#include "../Dependencies/freeglut/freeglut.h"

#include "Engine.h"
#include "Vector3D.h"

int main(int argc, char **argv)
{
	Engine engine;
	engine.InitDependencies(&argc, argv, 600, 200, 800, 600);
	engine.Initialize();

	engine.Run();

	return 0;
}