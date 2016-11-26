#include <stdexcept>

#include "Engine.h"
#include "LoaderGLSL.h"

GraphicAPI* Engine::graphics = nullptr;
SceneBase* Engine::currentScene = nullptr;

Engine::~Engine()
{
	delete graphics;
}


void Engine::SetGraphicAPI(GraphicType apiType)
{
	switch (apiType)
	{
	case GraphicAPI::OPEN_GL:
		graphics = GraphicOpenGL::CreateInstance();
		LoaderGLSL::CreateInstance();
		break;
	default:
		throw std::invalid_argument("Graphic API not supported");
		break;
	}
}

void Engine::InitDependencies(
	int * argc, 
	char * argv[], 
	int xWinPos, 
	int yWinPos, 
	int winWidth, 
	int winHieght
)
{
	graphics->Init(argc, argv, xWinPos, yWinPos, winWidth, winHieght);

	graphics->SetUpdateCallBack(Update);
	graphics->SetDisplayCallBack(Display);
	graphics->SetCloseCallBack(Close);
}

void Engine::Initialize()
{
	currentScene = new SceneBase();
	currentScene->AddGameObejct(new GameObject("Object_1"));
	currentScene->Awake();
	currentScene->Start();
}

void Engine::Run()
{
	graphics->Run();
}

void Engine::Display()
{
	graphics->ClearScreen();
	
	currentScene->Draw();

	graphics->SwapBuffers();
}

void Engine::Update()
{
	
}

void Engine::Close()
{
	graphics->ExitLoop();
}


