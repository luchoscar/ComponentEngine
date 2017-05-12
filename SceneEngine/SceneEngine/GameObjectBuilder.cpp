#include "GameObjectBuilder.h"

using namespace CoreManagers;

GameObjectBuilder * GameObjectBuilder::_instance = nullptr;

GameObjectBuilder::~GameObjectBuilder()
{
	if (_gameObject)
	{
		delete _gameObject;
	}

	_gameObject = nullptr;
}

GameObjectBuilder * GameObjectBuilder::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new GameObjectBuilder();
	}

	return _instance;
}

void GameObjectBuilder::LoadGameObject(std::string name)
{
	if (_dirty)
	{
		_gameObject = nullptr;
		return;
	}

	_dirty = true;
	_gameObject = new GameObject(name);
}

GameObject * GameObjectBuilder::GetGameObject()
{
	return _gameObject;
}

void GameObjectBuilder::UnloadGameObject()
{
	_dirty = false;
	_gameObject = nullptr;
}

void GameObjectBuilder::AddRenderer(
	std::vector<VertexFormat> vertexData, 
	std::string vertexShaderName, 
	std::string vertexShaderFile, 
	std::string fragmentShaderName, 
	std::string fragmentShaderFile
)
{
	Renderer* renderer = new Renderer();
	renderer->SetVertexData("vertShad", "vertexShader.glsl");
	renderer->SetFragmentData("fragShad", "fragmentShader.glsl");
	renderer->SetShaderProgram();

	renderer->CreateVerticesData(_gameObject->GetName(), vertexData);

	AddGenericComponent(renderer);

	renderer = nullptr;
}
