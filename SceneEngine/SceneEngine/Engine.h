#pragma once

#include "GraphicOpenGL.h"
#include "SceneBase.h"
#include "Managers.h"

using namespace CoreManagers;

class Engine
{
public:
	static float deltaTime;

	Engine() {}
	~Engine() {}

	void InitDependencies(int* argc, char* argv[], InitData initData);

	void InitializeGame();

	void Run();

	/* Forward declared GLUT callbacks registered by main. */
	static void Display();
	static void Update();
	static void Keyboard(unsigned char c, int x, int y) {}
	static void Resize(int width, int height) {}
	static void Close();

private:

	static GraphicAPI * _getGraphicAPI();

	static float _previousTime;
	static SceneBase* _currentScene;

	void _addScenes();
};