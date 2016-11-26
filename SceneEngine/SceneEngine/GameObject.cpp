#include "GameObject.h"

#include "ShaderLoader.h"
#include "GraphicAPI.h"

typedef ShaderLoader::Type ShaderType;

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
	_components.remove_if(
		[&](Component* cmp) -> bool
		{
			delete cmp;
			return true;
		}
	);

	_components.clear();
}

void GameObject::Awake()
{
	ShaderLoader::GetInstance()->LoadShader(ShaderType::VERTEX, "vertexShader.glsl", "vertShad");
	ShaderLoader::GetInstance()->LoadShader(ShaderType::FRAGMENT, "fragmentShader.glsl", "fragShad");
	_shaderId = ShaderLoader::GetInstance()->CreateProgram();

	for (ComponentList::iterator it = _components.begin(); it != _components.end(); it++)
	{
		(*it)->Awake();
	}
}

void GameObject::Start()
{
	for (ComponentList::iterator it = _components.begin(); it != _components.end(); it++)
	{
		(*it)->Start();
	}
}

void GameObject::Update(float delta)
{
	for (ComponentList::iterator it = _components.begin(); it != _components.end(); it++)
	{
		(*it)->Update(delta);
	}
}

void GameObject::Display()
{
	for (ComponentList::iterator it = _components.begin(); it != _components.end(); it++)
	{
		(*it)->Display();
	}

	ShaderLoader::GetInstance()->LoadShaderById(0);
	GraphicAPI::GetInstance()->DrawTriangles();
}
