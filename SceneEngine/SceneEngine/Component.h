#pragma once

class Component
{
public:
	virtual ~Component() {}

	virtual void Awake() {}
	virtual void Start() {}
	
	virtual void Update(float delta) {}
	virtual void PostUpdate(float delta) {}

	virtual void PreDisplay() {}
	virtual void Display() {}
	virtual void PostDisplay() {}

protected:
	Component() {}
	Component(Component&) {}
};

