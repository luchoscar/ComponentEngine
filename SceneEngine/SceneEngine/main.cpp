//#include "../Dependencies/glew/glew.h"
//#include "../Dependencies/freeglut/freeglut.h"

#include "Engine.h"
#include "GLUTFrameBufferInfo.h"
#include "main.h"

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
	
	InitData initData = InitData(
		WindowInfo("Component Base Engine", size, position, true),
		ContextInfo(),
		GLUTFrameBufferInfo()
	);

	engine.InitDependencies(&argc, argv, initData);
	engine.InitializeGame();

	engine.Run();

	return 0;
}