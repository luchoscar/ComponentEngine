#pragma once

#include "Component.h"
#include "Vector3D.h"
#include "Matrix3D.h"

class Camera final :
	public Component
{
public:
	enum CameraType
	{
		LOOK_AT
	};

	Camera(CameraType cameraType) { _cameraType = cameraType; }
	~Camera() {}

	Vector3D GetLookAtPoint();
	void SetLookAtVect(Vector3D lookAt);
	Matrix3D GetViewMatrix();

private:
	Vector3D _lookAtPoint;
	bool _dirty = true;
	Matrix3D _viewMatrix;
	CameraType _cameraType;
};

