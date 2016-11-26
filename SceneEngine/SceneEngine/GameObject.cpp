#include "GameObject.h"

#include "ShaderLoader.h"
#include "GraphicAPI.h"

typedef ShaderLoader::Type ShaderType;
int GameObject::ID = 0;

GameObject::GameObject(std::string name)
{
	_name = name;
	_id = ID++;
}

GameObject::GameObject(const GameObject & obj)
{
	_name = obj._name;
	_id = ID++;
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

void GameObject::AddComponent(Component * component)
{
	_components.push_back(component);
}

template<class T>
T * GameObject::GetComponent()
{
	for (ComponentList::iterator it = _components.begin(); it != _components.end(); it++)
	{
		if (dynamic_cast<T*>(it) != NULL)
		{
			return *it;
		}
	}

	return nullptr
}

int GameObject::GetId()
{
	return _id;
}

void GameObject::Awake()
{
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
}
