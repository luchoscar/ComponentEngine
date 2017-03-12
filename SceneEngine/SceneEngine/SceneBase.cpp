#include "SceneBase.h"

#include "Renderer.h"

typedef ObjectsList::iterator ObjListIt;

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

void SceneBase::AddGameObejct(GameObject * gameObj)
{
	Renderer* renderer = new Renderer();
	renderer->SetVertexData("vertShad", "vertexShader.glsl");
	renderer->SetFragmentData("fragShad", "fragmentShader.glsl");
	renderer->CreateShaderProgram();

	std::vector<VertexFormat> vertices;
	vertices.push_back(VertexFormat(
		Vector3D(0.5f, -0.5f, 0.0f),
		Vector4D(1, 0, 0, 1)
	));
	vertices.push_back(VertexFormat(
		Vector3D(-0.5f, -0.5f, 0.0f),
		Vector4D(0, 1, 0, 1)
	));
	vertices.push_back(VertexFormat(
		Vector3D(0.5f, 0.5f, 0.0f),
		Vector4D(0, 0, 1, 1)
	));
	renderer->LoadVerticesData(gameObj->GetName(), vertices);

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
		(*it)->PostUpdate(delta);
	}
}

void SceneBase::Draw()
{
	for (ObjListIt it = _objectsList.begin(); it != _objectsList.end(); it++)
	{
		(*it)->PreDisplay();
	}

	for (ObjListIt it = _objectsList.begin(); it != _objectsList.end(); it++)
	{
		(*it)->Display();
	}

	for (ObjListIt it = _objectsList.begin(); it != _objectsList.end(); it++)
	{
		(*it)->PostDisplay();
	}
}
