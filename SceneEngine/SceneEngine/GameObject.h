#pragma once

#include <list>
#include <string>
#include <stdexcept>

#include "Renderer.h"
#include "Transformation.h"

typedef std::list<Component*> ComponentList;

class GameObject
{
public:
	GameObject(std::string name);
	GameObject(const GameObject& obj);

	~GameObject();

	void AddComponent(Component* component);

	template<typename T>
	T* GetComponent();

	int GetId();
	std::string GetName();

	void Awake();
	void Start();

	void Update(float delta);
	void PostUpdate();
	
	void PreDisplay();
	void Display(Matrix3D viewProjMatrix);
	void PostDisplay();

	Transformation * GetTransformation();

private:
	
	GameObject() {}	

	ComponentList _components;

	// Mapping values used by the managers
	std::string _name;
	unsigned int _shaderId;
	unsigned int _id;

	static unsigned int ID;

	Renderer * _renderer;
	Transformation * _transformation;
};

template<typename T>
inline T * GameObject::GetComponent()
{
	if (!std::is_base_of<Component, T>::value)
		throw std::invalid_argument(
			"Class is not a derived component"
		);

	for (ComponentList::iterator it = _components.begin(); it != _components.end(); it++)
	{
		T* outComp = dynamic_cast<T*>(*it);
		if (outComp)
		{
			return outComp;
		}
	}

	printf("Component object could not be located");

	return nullptr;
}
