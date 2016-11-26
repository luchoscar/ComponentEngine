//#include "../Dependencies/glew/glew.h"
//#include "../Dependencies/freeglut/freeglut.h"

#include "Engine.h"
#include "Vector3D.h"

int main(int argc, char **argv)
{
	Engine engine;
	engine.SetGraphicAPI(GraphicType::OPEN_GL);
	engine.InitDependencies(&argc, argv, 500, 500, 800, 600);
	engine.Initialize();

	engine.Run();

	return 0;
}