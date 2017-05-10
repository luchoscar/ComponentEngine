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

	void SetPosition(Vector3D position);
	void SetScale(Vector3D scale);
	void SetRotation(Vector3D rotation);

	Matrix3D GetModelMatrix();

private:
	Vector3D _position;
	Vector3D _scale;
	Vector3D _rotation;
};

