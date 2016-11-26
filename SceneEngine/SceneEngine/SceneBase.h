#pragma once

#include <vector>

#include "GameObject.h"

typedef std::vector<GameObject*> ObjectsList;

class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase();

	void Draw();

private:
	ObjectsList _objectsList;
};

