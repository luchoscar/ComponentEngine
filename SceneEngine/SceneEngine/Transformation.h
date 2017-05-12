#pragma once

#include "Component.h"
#include "Vector3D.h"
#include "Matrix3D.h"

class Transformation final :
	public Component
{
public:
	Transformation();
	virtual ~Transformation();

	Vector3D GetPosition();
	Vector3D GetScale();
	Vector3D GetRotation();

	void SetPosition(Vector3D position);
	void SetScale(Vector3D scale);
	void SetRotation(Vector3D rotation);

	Matrix3D GetModelMatrix();

private:
	Vector3D _position;
	Vector3D _scale;
	Vector3D _rotation;

	bool _dirty = true;
	Matrix3D _modelMatrix;
};

