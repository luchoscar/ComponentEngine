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
	printf("\nAspect ration %f\n", aspectRatio);
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
	GameObjectBuilder * objectBuilder = 
		Managers::GetInstance()->GetGameObjectBuilder();

	SceneBase * scene = new SceneBase();

	objectBuilder->LoadGameObject("Object_1");
	GameObject * _gameObject = nullptr;

	std::vector<VertexFormat> vertices;
	vertices.push_back(VertexFormat(
		Vector3D(1.0f, -1.0f, 0.0f),
		Vector4D(1, 0, 0, 1)
	));
	
	vertices.push_back(VertexFormat(
		Vector3D(1.0f, 1.0f, 0.0f),
		Vector4D(0, 0, 1, 1)
	));
	
	vertices.push_back(VertexFormat(
		Vector3D(-1.0, -1.0f, 0.0f),
		Vector4D(0, 1, 0, 1)
	)); 

	objectBuilder->AddRenderer(
		vertices,
		"vertShad", 
		"vertexShader.glsl",
		"fragShad", 
		"fragmentShader.glsl"
	);

	_gameObject = objectBuilder->GetGameObject();
	objectBuilder->UnloadGameObject();
	
	scene->AddGameObejct(_gameObject);

	SceneManager * sceneMng = Managers::GetInstance()->GetScenesManager();
	sceneMng->PushSceneFront(scene);

	_gameObject = nullptr;
}


