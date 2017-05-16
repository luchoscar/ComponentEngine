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
	void SetCameraObject(
		GameObject * camera,
		Vector3D defaultPosition = Vector3D(0.0f, 5.0f, -10.0f),
		Vector3D lookAt = Vector3D(0.0f, 0.0f, 0.0f)
	);
	GameObject * GetCameraObject();

	void Awake();
	void Start();
	void Update(float delta);
	void Draw();

	void SetCameraDirty(bool dirty);

private:
	GameObject * _cameraObject;
	std::vector<GameObject*> _objectsList;
};

