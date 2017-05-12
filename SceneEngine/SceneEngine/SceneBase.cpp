#include "SceneBase.h"

#include "Renderer.h"
#include "Managers.h"

using namespace CoreManagers;

typedef std::vector<GameObject*>::iterator ObjListIt;

SceneBase::SceneBase()
{

}

SceneBase::~SceneBase()
{
	for (unsigned int i = 0; i < _objectsList.size(); i++)
	{
		delete _objectsList[i];
	}

	_objectsList.clear();
}

void SceneBase::AddGameObejct(std::string name, std::vector<VertexFormat> verticesData)
{
	GameObject * gameObj = new GameObject(name);

	Renderer* renderer = new Renderer();
	renderer->SetVertexData("vertShad", "vertexShader.glsl");
	renderer->SetFragmentData("fragShad", "fragmentShader.glsl");
	renderer->SetShaderProgram();

	renderer->CreateVerticesData(gameObj->GetName(), verticesData);

	gameObj->AddComponent(renderer);


	_objectsList.push_back(gameObj);
}

void SceneBase::Awake()
{
	for (ObjListIt it = _objectsList.begin(); it != _objectsList.end(); it++)
	{
		(*it)->Awake();
	}
}

void SceneBase::Start()
{
	for (ObjListIt it = _objectsList.begin(); it != _objectsList.end(); it++)
	{
		(*it)->Start();
	}
}

void SceneBase::Update(float delta)
{
	for (ObjListIt it = _objectsList.begin(); it != _objectsList.end(); it++)
	{
		(*it)->Update(delta);
	}

	for (ObjListIt it = _objectsList.begin(); it != _objectsList.end(); it++)
	{
		(*it)->PostUpdate();
	}
}

void SceneBase::Draw()
{
	// TODO: 
	// 1. Create and use camera component to build and store view matrix
	// 2. Add camera component to camera object to be placed in scene

	Matrix3D cameraPositions;
	cameraPositions[11] = -2.5f;
	cameraPositions.ToString();

	GraphicAPI * graphics = Managers::GetInstance()->GetGraphicsManager();
	Matrix3D viewProjMatrix = graphics->GetPerspectiveMatrix() * 
		cameraPositions;
	viewProjMatrix.ToString();

	for (ObjListIt it = _objectsList.begin(); it != _objectsList.end(); it++)
	{
		(*it)->PreDisplay();
	}

	for (ObjListIt it = _objectsList.begin(); it != _objectsList.end(); it++)
	{
		(*it)->Display(viewProjMatrix);
	}

	for (ObjListIt it = _objectsList.begin(); it != _objectsList.end(); it++)
	{
		(*it)->PostDisplay();
	}
}
