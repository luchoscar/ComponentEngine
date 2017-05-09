#include <stdexcept>

#include "Engine.h"
#include "VertexFormat.h"

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
	graphics->SetResizeCallBack(Resize);
}

void Engine::InitializeGame()
{
	_addScenes();

	SceneManager * sceneMng = Managers::GetInstance()->GetScenesManager();
	sceneMng->SetCurrentSceneIndex(0);

	_currentScene = sceneMng->GetCurrentScene();
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

void Engine::Resize(int width, int height)
{
	float aspectRatio = (float)width / (float)height;

	GraphicAPI * graphics = _getGraphicAPI();
	graphics->SetPerspectiveMatrix(65, aspectRatio, 1.0, 1000.0);
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

	std::vector<VertexFormat> vertices;
	vertices.push_back(VertexFormat(
		Vector3D(0.5f, -0.5f, 0.0f),
		Vector4D(1, 0, 0, 1)
	));
	
	vertices.push_back(VertexFormat(
		Vector3D(0.5f, 0.5f, 0.0f),
		Vector4D(0, 0, 1, 1)
	));
	
	vertices.push_back(VertexFormat(
		Vector3D(-0.5f, -0.5f, 0.0f),
		Vector4D(0, 1, 0, 1)
	)); 
	
	scene->AddGameObejct("Object_1", vertices);
	
	/*
	std::vector<VertexFormat> vertices_2;
	vertices_2.push_back(VertexFormat(
		Vector3D(-1.0f, -1.0f, 0.0f),
		Vector4D(1, 0, 0, 1)
	));
	vertices_2.push_back(VertexFormat(
		Vector3D(-0.5f, -1.0f, 0.0f),
		Vector4D(0, 1, 0, 1)
	));
	vertices_2.push_back(VertexFormat(
		Vector3D(-0.5f, -0.5f, 0.0f),
		Vector4D(0, 0, 1, 1)
	));
	scene->AddGameObejct("Object_2", vertices_2);
	*/

	SceneManager * sceneMng = Managers::GetInstance()->GetScenesManager();
	sceneMng->PushSceneFront(scene);
}


