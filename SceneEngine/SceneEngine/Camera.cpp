
#include <iostream>

#include "Camera.h"
#include "MatrixUtils.h"
#include "Transformation.h"

Camera::Camera()
{
	_dirty = true;
}

Vector3D Camera::GetLookAtPoint()
{
	return _lookAtPoint;
}

void Camera::SetLookAtVect(Vector3D lookAt)
{
	_dirty = true;
	_lookAtPoint = lookAt;
}

Matrix3D Camera::GetViewMatrix(Vector3D camPos, Vector3D vectUp)
{
	if (!_dirty)
		return _viewMatrix;

	_dirty = false;

	
	_viewMatrix = MatrixUtils::BuildLookAtMatrix(
		camPos,
		_lookAtPoint,
		vectUp
	);

	return _viewMatrix;
}

void Camera::SetDirty(bool dirty)
{
	_dirty = dirty;
}

bool Camera::IsDirt()
{
	return _dirty;;
}

void Camera::Print()
{
	std::cout << "Camera component\n\tLook At = ("
		<< _lookAtPoint.GetX() << ", " << _lookAtPoint.GetY() << ", "
		<< _lookAtPoint.GetZ() << ")\n";
}
