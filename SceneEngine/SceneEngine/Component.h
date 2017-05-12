#pragma once

class GameObject;

class Component
{
public:
	void SetGameObject(GameObject * gameObject);

	virtual ~Component() {}

	virtual void Awake() {}
	virtual void Start() {}
	
	virtual void Update(float delta) {}
	virtual void PostUpdate() {}

	virtual void PreDisplay() {}
	virtual void PostDisplay() {}

protected:
	Component() {}
	Component(Component&) {}

	GameObject * _gameObject;
};

