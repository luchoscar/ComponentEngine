#pragma once

#include "Component.h"

class BehaviorComponent :
	public Component
{
public:
	virtual ~BehaviorComponent() {}

protected:
	BehaviorComponent() {}
	BehaviorComponent(BehaviorComponent&) {}
};

