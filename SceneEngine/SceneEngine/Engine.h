#pragma once

#include "GraphicOpenGL.h"
#include "SceneBase.h"

typedef GraphicAPI::Type GraphicType;

class Engine
{
public:
	static float deltaTime;

	~Engine();

	void SetGraphicAPI(GraphicType apiType);
	void InitDependencies(
		int* argc, 
		char* argv[], 
		int xWinPos, 
		int yWinPos, 
		int winWidth, 
		int winHieght
	);

	void Initialize();

	void Run();

	/* Forward declared GLUT callbacks registered by main. */
	static void Display();
	static void Update();
	static void Keyboard(unsigned char c, int x, int y) {}
	static void Resize(int width, int height) {}
	static void Close();

private:

	static GraphicAPI* graphics;
	
	static float previousTime;

	static SceneBase* currentScene;
};