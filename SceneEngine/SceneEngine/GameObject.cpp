
#include "GameObject.h"
#include "Transformation.h"

typedef ComponentList::iterator CompListIt;

unsigned int GameObject::ID = 0;

GameObject::GameObject(std::string name)
{
	ID++;
	_name = name;
	_id = ID;

	AddComponent(new Transformation());
}

GameObject::GameObject(const GameObject & obj)
{
	ID++;
	_name = obj._name;
	_id = ID;
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

	ID--;
}

void GameObject::AddComponent(Component * component)
{
	component->SetGameObject(this);
	_components.push_back(component);
}

int GameObject::GetId()
{
	return _id;
}

std::string GameObject::GetName()
{
	return _name;
}

void GameObject::Awake()
{
	for (CompListIt it = _components.begin(); it != _components.end(); it++)
	{
		(*it)->Awake();
	}
}

void GameObject::Start()
{
	for (CompListIt it = _components.begin(); it != _components.end(); it++)
	{
		(*it)->Start();
	}
}

void GameObject::Update(float delta)
{
	for (CompListIt it = _components.begin(); it != _components.end(); it++)
	{
		(*it)->Update(delta);
	}
}

void GameObject::PostUpdate(float delta)
{
	for (CompListIt it = _components.begin(); it != _components.end(); it++)
	{
		(*it)->PostUpdate(delta);
	}
}

void GameObject::PreDisplay()
{
	for (CompListIt it = _components.begin(); it != _components.end(); it++)
	{
		(*it)->PreDisplay();
	}
}

void GameObject::Display()
{
	for (CompListIt it = _components.begin(); it != _components.end(); it++)
	{
		(*it)->Display();
	}
}

void GameObject::PostDisplay()
{
	for (CompListIt it = _components.begin(); it != _components.end(); it++)
	{
		(*it)->PostDisplay();
	}
}
