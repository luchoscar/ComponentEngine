
#include "Transformation.h"
#include "MatrixUtils.h"

Transformation::Transformation()
{
	_position = Vector3D(0.0f, 0.0f, 0.0f);
	_scale = Vector3D(1.0f, 1.0f, 1.0f);
	_rotation = Vector3D(0.0f, 0.0f, 0.0f);
}


Transformation::~Transformation()
{
}

Vector3D Transformation::GetPosition()
{
	return _position;
}

Vector3D Transformation::GetScale()
{
	return _scale;
}

Vector3D Transformation::GetRotation()
{
	return _rotation;
}

void Transformation::SetPosition(Vector3D position)
{
	_dirty = true;
	_position = position;
}

void Transformation::SetScale(Vector3D scale)
{
	_dirty = true;
	_scale = scale;
}

void Transformation::SetRotation(Vector3D rotation)
{
	_dirty = true;
	_rotation = rotation;
}

Matrix3D Transformation::GetModelMatrix()
{
	if (!_dirty)
		return _modelMatrix;

	_dirty = false;

	Matrix3D posMatrix = MatrixUtils::BuildTranslationMatrix(_position);
	Matrix3D scaleMatrix = MatrixUtils::BuildScaleMatrix(_scale);
	Matrix3D rotationMatrix = MatrixUtils::BuildRotationMatrix(_rotation);

	_modelMatrix = posMatrix * scaleMatrix * rotationMatrix;
	
	return _modelMatrix;
}
