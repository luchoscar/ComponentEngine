#pragma once

#include "GameObject.h"
#include "VertexFormat.h"

#include <vector>

using namespace ModelData;

class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase();

	void AddGameObejct(GameObject * gameObject);

	void Awake();
	void Start();
	void Update(float delta);
	void Draw();

private:
	std::vector<GameObject*> _objectsList;
};

