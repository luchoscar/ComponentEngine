#include <stdexcept>
#include <iostream>

#include "Engine.h"
#include "VertexFormat.h"

using namespace Core;
using namespace CoreManagers;

const float FPS = 30.0f;
int _currentFPS = 0;

SceneBase* Engine::_currentScene = nullptr;
float Engine::deltaTime; 
float Engine::_previousTime;
float Engine::_frameDelay;
float Engine::_currentFrameDelay;

Engine::Engine() {
	_frameDelay = 1.0f/ FPS;
	_currentFrameDelay = _frameDelay;
}

void Engine::InitDependencies(int* argc, char* argv[], InitData initData)
{
	GraphicAPI * graphics = _getGraphicAPI();
	graphics->Init(argc, argv, initData);

	graphics->SetUpdateCallBack(Update);
	graphics->SetIdleCallBack(Update);
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
	if (_currentFrameDelay < _frameDelay) {
		return;
	}

	GraphicAPI * graphics = _getGraphicAPI();
	graphics->ClearScreen();
	
	_currentScene->Draw();

	graphics->SwapBuffers();
	
	int currentFPS = 1.0f / _currentFrameDelay;
	if (currentFPS != _currentFPS) {
		std::cout << "_currentFrameDelay : " << _currentFrameDelay << std::endl;
		std::cout << "currentFPS : " << currentFPS << std::endl;

		_currentFPS = currentFPS;
		
		std::cout << "_currentFPS : " << _currentFPS << std::endl;
	}

	_currentFrameDelay = 0.0f;
}

void Engine::Update()
{
	float currentTime = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = (currentTime - _previousTime) * 0.001;

	_currentScene->Update(deltaTime);

	_previousTime = currentTime;
	_currentFrameDelay += deltaTime;

	Display();
}

void Engine::Resize(int width, int height)
{
	float aspectRatio = (float)width / (float)height;
	printf(
		"\n---------------\nAspect ration %f / %f = %f\n---------------\n\n", 
		(float)width, 
		(float)height, 
		aspectRatio
	);

	GraphicAPI * graphics = _getGraphicAPI();
	graphics->SetPerspectiveMatrix(60, aspectRatio, 1.0, 1000.0);
	_currentScene->SetCameraDirty(true);

	_currentFrameDelay = _frameDelay;

	Display();
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
	GameObject * gameObject = nullptr;

	GameObjectBuilder * objectBuilder = 
		Managers::GetInstance()->GetGameObjectBuilder();

	SceneBase * scene = new SceneBase();

	objectBuilder->LoadGameObject("MainCamera");
	objectBuilder->AddCamera();

	gameObject = objectBuilder->GetGameObject();
	scene->SetCameraObject(gameObject);
	scene->AddGameObejct(gameObject);
	objectBuilder->UnloadGameObject();
	gameObject = nullptr;

	objectBuilder->LoadGameObject("Object_1");

	std::vector<VertexFormat> vertices;
	vertices.push_back(VertexFormat(
		Vector3D(0.5f, -0.5f, 0.0f),
		Vector4D(1, 0, 0, 1)
	));
	
	vertices.push_back(VertexFormat(
		Vector3D(0.0f, 0.5f, 0.0f),
		Vector4D(0, 0, 1, 1)
	));
	
	vertices.push_back(VertexFormat(
		Vector3D(-0.5, -0.5f, 0.0f),
		Vector4D(0, 1, 0, 1)
	)); 

	objectBuilder->AddRenderer(
		vertices,
		"vertShad", 
		"vertexShader.glsl",
		"fragShad", 
		"fragmentShader.glsl"
	);

	gameObject = objectBuilder->GetGameObject();
	objectBuilder->UnloadGameObject();
	
	scene->AddGameObejct(gameObject);

	SceneManager * sceneMng = Managers::GetInstance()->GetScenesManager();
	sceneMng->PushSceneFront(scene);

	gameObject = nullptr;
}


