#pragma once

#include <vector>

#include "GameObject.h"

typedef std::vector<GameObject*> ObjectsList;

class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase();

	void AddGameObejct(GameObject * gameObj);

	void Awake();
	void Start();
	void Update(float delta);
	void Draw();

private:
	ObjectsList _objectsList;
};

