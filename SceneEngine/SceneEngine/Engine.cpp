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
	_addScenes();

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

void Engine::_addScenes()
{
	SceneBase * scene = new SceneBase();
	scene->AddGameObejct(new GameObject("Object_1"));

	SceneManager * sceneMng = Managers::GetInstance()->GetScenesManager();
	sceneMng->PushSceneFront(scene);
}


