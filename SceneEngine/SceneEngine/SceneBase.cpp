#include "SceneBase.h"

#include "Renderer.h"
#include "Managers.h"
#include "Camera.h"
#include "MatrixUtils.h"

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

	delete _cameraObject;
}

void SceneBase::AddGameObejct(GameObject * gameObject)
{
	_objectsList.push_back(gameObject);
}

void SceneBase::SetCameraObject(GameObject * camera, Vector3D position, Vector3D lookAt)
{
	camera->GetTransformation()->SetPosition(position);
	camera->GetComponent<Camera>()->SetLookAtVect(lookAt);

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
	Transformation * transComp = _cameraObject->GetTransformation();

	Camera * cameraComp = _cameraObject->GetComponent<Camera>();
	Matrix3D viewMatrix = cameraComp->GetViewMatrix(
		transComp->GetPosition(),
		Vector3D(0.0f, 1.0f, 0.0f)
	);
	//transComp->Print();
	//cameraComp->Print();
	//viewMatrix.ToString();

	GraphicAPI * graphics = Managers::GetInstance()->GetGraphicsManager();
	Matrix3D projectionMatrix = graphics->GetPerspectiveMatrix();

	Matrix3D viewProjMatrix = projectionMatrix * viewMatrix;

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

void SceneBase::SetCameraDirty(bool dirty)
{
	_cameraObject->GetComponent<Camera>()->SetDirty(dirty);
}
