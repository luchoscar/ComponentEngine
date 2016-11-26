#pragma once

#include <list>

#include "Component.h"

typedef std::list<Component*> ComponentList;

class GameObject
{
public:
	GameObject();
	~GameObject();

	void Awake();
	void Start();
	void Update(float delta);
	void Display();

private:
	ComponentList _components;
	unsigned int _shaderId;
};

