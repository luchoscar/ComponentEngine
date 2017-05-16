#pragma once

#include "Component.h"
#include "Vector3D.h"
#include "Matrix3D.h"

class Camera final :
	public Component
{
public:
	Camera();
	~Camera() {}

	Vector3D GetLookAtPoint();
	void SetLookAtVect(Vector3D lookAt);
	Matrix3D GetViewMatrix(Vector3D camPos, Vector3D vectUp);

	void SetDirty(bool dirty);
	bool IsDirt();

	void Print();

private:
	Vector3D _lookAtPoint;
	bool _dirty;
	Matrix3D _viewMatrix;
};

