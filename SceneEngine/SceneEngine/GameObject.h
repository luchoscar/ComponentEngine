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

	void Awake();
	void Start();
	void Update(float delta);
	void Display();

private:
	// GameObject must always have a name used to map to graphics data
	GameObject() {}	

	ComponentList _components;
	std::string _name;
	unsigned int _shaderId;
	unsigned int _id;

	static unsigned int ID;
};
