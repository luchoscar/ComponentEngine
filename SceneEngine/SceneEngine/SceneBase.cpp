#include "SceneBase.h"

#include "Renderer.h"

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
	vertices.push_back(VertexFormat(Vector3D(0.5f, -0.5f, 0.0f)));
	vertices.push_back(VertexFormat(Vector3D(-0.5f, -0.5f, 0.0f)));
	vertices.push_back(VertexFormat(Vector3D(0.5f, 0.5f, 0.0f)));
	renderer->LoadVerticesData(gameObj->GetName(), vertices);

	gameObj->AddComponent(renderer);

	_objectsList.push_back(gameObj);
}

void SceneBase::Awake()
{
	for (ObjectsList::iterator it = _objectsList.begin(); it != _objectsList.end(); it++)
	{
		(*it)->Awake();
	}
}

void SceneBase::Start()
{
	for (ObjectsList::iterator it = _objectsList.begin(); it != _objectsList.end(); it++)
	{
		(*it)->Start();
	}
}

void SceneBase::Update(float delta)
{
	for (ObjectsList::iterator it = _objectsList.begin(); it != _objectsList.end(); it++)
	{
		(*it)->Update(delta);
	}
}

void SceneBase::Draw()
{
	for (ObjectsList::iterator it = _objectsList.begin(); it != _objectsList.end(); it++)
	{
		(*it)->Display();
	}
}
