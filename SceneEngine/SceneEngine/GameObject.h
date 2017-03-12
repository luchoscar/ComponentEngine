#pragma once

#include <list>

#include "Component.h"

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
	void PostUpdate(float delta);
	
	void PreDisplay();
	void Display();
	void PostDisplay();

private:
	
	GameObject() {}	

	ComponentList _components;

	// Mapping values used by the managers
	std::string _name;
	unsigned int _shaderId;
	unsigned int _id;

	static unsigned int ID;
};

template<typename T>
inline T * GameObject::GetComponent()
{
	for (ComponentList::iterator it = _components.begin(); it != _components.end(); it++)
	{
		T* outComp = dynamic_cast<T*>(*it);
		if (outComp != NULL)
		{
			return outComp;
		}
	}

	return nullptr;
}
