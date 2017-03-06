//#include "../Dependencies/glew/glew.h"
//#include "../Dependencies/freeglut/freeglut.h"

#include "Engine.h"
#include "Vector3D.h"
#include "WindowInfo.h"

using namespace Core;

int main(int argc, char **argv)
{
	Engine engine;

	Vector2D<int> position;

	position.SetX(600);
	position.SetY(200);

	Vector2D<int> size;
	size.SetX(800);
	size.SetY(600);
	
	WindowInfo window("Component Base Engine", size, position, true);

	engine.InitDependencies(&argc, argv, window);
	engine.InitializeGame();

	engine.Run();

	return 0;
}