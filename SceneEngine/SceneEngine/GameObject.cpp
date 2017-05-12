
#include "GameObject.h"

typedef ComponentList::iterator CompListIt;

unsigned int GameObject::ID = 0;

GameObject::GameObject(std::string name)
{
	ID++;
	_name = name;
	_id = ID;

	_renderer = nullptr;
	_transformation = new Transformation();

	AddComponent(_transformation);

}

GameObject::GameObject(const GameObject & obj)
{
	ID++;
	_name = obj._name;
	_id = ID;
	_transformation = obj._transformation;

	for (ComponentList::const_iterator it = obj._components.begin(); it != obj._components.end(); it++)
	{
		AddComponent(*it);
	}
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

	if (!_renderer)
	{
		_renderer = dynamic_cast<Renderer*>(component);
	}
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

void GameObject::PostUpdate()
{
	for (CompListIt it = _components.begin(); it != _components.end(); it++)
	{
		(*it)->PostUpdate();
	}
}

void GameObject::PreDisplay()
{
	for (CompListIt it = _components.begin(); it != _components.end(); it++)
	{
		(*it)->PreDisplay();
	}
}

void GameObject::Display(Matrix3D viewProjMatrix)
{
	if (_renderer)
	{
		Matrix3D modelMatrix = _transformation->GetModelMatrix();
		printf("Model matrix:\n");
		modelMatrix.ToString();

		Matrix3D mvpMatrix = viewProjMatrix * modelMatrix;
		printf("MVP matrix:\n");
		mvpMatrix.ToString();

		_renderer->Display(mvpMatrix);
	}
}

void GameObject::PostDisplay()
{
	for (CompListIt it = _components.begin(); it != _components.end(); it++)
	{
		(*it)->PostDisplay();
	}
}
