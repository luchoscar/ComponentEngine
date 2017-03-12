#include <stdexcept>

#include "Engine.h"

using namespace Core;
using namespace CoreManagers;

SceneBase* Engine::_currentScene = nullptr;

void Engine::InitDependencies(int* argc, char* argv[], InitData initData)
{
	GraphicAPI * graphics = _getGraphicAPI();
	graphics->Init(argc, argv, initData);

	graphics->SetUpdateCallBack(Update);
	graphics->SetDisplayCallBack(Display);
	graphics->SetCloseCallBack(Close);
}

void Engine::InitializeGame()
{
	_currentScene = new SceneBase();
	_currentScene->AddGameObejct(new GameObject("Object_1"));
	_currentScene->Awake();
	_currentScene->Start();
}

void Engine::Run()
{
	GraphicAPI * graphics = _getGraphicAPI();
	graphics->Run();
}

void Engine::Display()
{
	GraphicAPI * graphics = _getGraphicAPI();
	graphics->ClearScreen();
	
	_currentScene->Draw();

	graphics->SwapBuffers();
}

void Engine::Update()
{
	
}

void Engine::Close()
{
	GraphicAPI * graphics = _getGraphicAPI();
	graphics->ExitLoop();
}

//--- Private Implementation --------------------------------------------------

GraphicAPI * Engine::_getGraphicAPI()
{
	return Managers::GetInstance()->GetGraphicsManager();
}


