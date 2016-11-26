#pragma once

class Component
{
public:
	virtual ~Component() {}

	virtual void Awake() {}
	virtual void Start() {}
	virtual void Update(float delta) {}
	virtual void Display() {}

protected:
	Component() {}
	Component(Component&) {}
};

