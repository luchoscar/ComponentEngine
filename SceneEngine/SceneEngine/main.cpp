#define OPEN_GL_BUFFER

#include "Engine.h"
#include "main.h"

#ifdef OPEN_GL_BUFFER
#include "GLUTFrameBufferInfo.h"
#endif // OPEN_GL

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
	
	FrameBufferInfo * frameBuffer = nullptr;

#ifdef OPEN_GL_BUFFER
	frameBuffer = new GLUTFrameBufferInfo(true, false, false, false);
#endif

	InitData initData = InitData(
		WindowInfo("Component Base Engine", size, position, true),
		ContextInfo(),
		frameBuffer
	);

	engine.InitDependencies(&argc, argv, initData);
	engine.InitializeGame();

	engine.Run();

	delete frameBuffer;
	frameBuffer = nullptr;

	return 0;
}