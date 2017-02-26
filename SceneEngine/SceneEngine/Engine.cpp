#include <stdexcept>

#include "Engine.h"
#include "LoaderGLSL.h"

using namespace CoreManagers;

SceneBase* Engine::_currentScene = nullptr;

Engine::Engine()
{ 
	
}

Engine::~Engine()
{ }

void Engine::InitDependencies(
	int * argc, 
	char * argv[], 
	int xWinPos, 
	int yWinPos, 
	int winWidth, 
	int winHieght
)
{
	GraphicAPI * graphics = _getGraohicAPI();
	graphics->Init(argc, argv, xWinPos, yWinPos, winWidth, winHieght);

	graphics->SetUpdateCallBack(Update);
	graphics->SetDisplayCallBack(Display);
	graphics->SetCloseCallBack(Close);
}

void Engine::Initialize()
{
	_currentScene = new SceneBase();
	_currentScene->AddGameObejct(new GameObject("Object_1"));
	_currentScene->Awake();
	_currentScene->Start();
}

void Engine::Run()
{
	GraphicAPI * graphics = _getGraohicAPI();
	graphics->Run();
}

void Engine::Display()
{
	GraphicAPI * graphics = _getGraohicAPI();
	graphics->ClearScreen();
	
	_currentScene->Draw();

	graphics->SwapBuffers();
}

void Engine::Update()
{
	
}

void Engine::Close()
{
	GraphicAPI * graphics = _getGraohicAPI();
	graphics->ExitLoop();
}

//--- Private Implementation --------------------------------------------------

GraphicAPI * Engine::_getGraohicAPI()
{
	return Managers::GetInstance()->GetGraphicsManager();
}


