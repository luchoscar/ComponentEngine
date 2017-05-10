
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

void Transformation::SetPosition(Vector3D position)
{
	_position = position;
}

void Transformation::SetScale(Vector3D scale)
{
	_scale = scale;
}

void Transformation::SetRotation(Vector3D rotation)
{
	_rotation = rotation;
}

Matrix3D Transformation::GetModelMatrix()
{
	Matrix3D posMatrix = MatrixUtils::BuildTranslationMatrix(_position);
	Matrix3D scaleMatrix = MatrixUtils::BuildScaleMatrix(_scale);
	Matrix3D rotationMatrix = MatrixUtils::BuildRotationMatrix(_rotation);

	return posMatrix * scaleMatrix * rotationMatrix;
}
