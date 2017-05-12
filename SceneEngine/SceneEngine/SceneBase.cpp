#include "SceneBase.h"

#include "Renderer.h"
#include "Managers.h"

using namespace CoreManagers;

typedef std::vector<GameObject*>::iterator ObjListIt;

SceneBase::SceneBase()
{
	_cameraObject = nullptr;
}

SceneBase::~SceneBase()
{
	for (unsigned int i = 0; i < _objectsList.size(); i++)
	{
		delete _objectsList[i];
	}

	_objectsList.clear();
}

void SceneBase::AddGameObejct(GameObject * gameObject)
{
	_objectsList.push_back(gameObject);
}

void SceneBase::SetCameraObject(GameObject * camera, Vector3D defaultPosition)
{
	camera->GetTransformation()->SetPosition(defaultPosition);
	_cameraObject = camera;
}

GameObject * SceneBase::GetCameraObject()
{
	return _cameraObject;
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

	Matrix3D cameraPositions = _cameraObject->GetTransformation()->GetModelMatrix();
	cameraPositions.ToString();

	GraphicAPI * graphics = Managers::GetInstance()->GetGraphicsManager();
	Matrix3D projectionMatrix = graphics->GetPerspectiveMatrix();
	printf("Projection matrix:\n");
	projectionMatrix.ToString();

	Matrix3D viewProjMatrix = projectionMatrix * cameraPositions;
	printf("View Projection matrix:\n"); 
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
