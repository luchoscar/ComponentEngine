#include "Camera.h"

Vector3D Camera::GetLookAtPoint()
{
	return _lookAtPoint;
}

void Camera::SetLookAtVect(Vector3D lookAt)
{
	_dirty = true;
	_lookAtPoint = lookAt;
}

Matrix3D Camera::GetViewMatrix()
{
	if (!_dirty)
		return _viewMatrix;

	return _viewMatrix;
}
