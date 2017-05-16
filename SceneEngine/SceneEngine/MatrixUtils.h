#pragma once

#include "Matrix3D.h"
#include "Vector3D.h"

class MatrixUtils
{
public:
	~MatrixUtils() {}

	static Matrix3D BuildPerspectiveMatrix(
		double fieldOfView, 
		double aspectRatio, 
		double zNear, 
		double zFar
	);

	static Matrix3D BuildLookAtMatrix(
		Vector3D cameraPosition,
		Vector3D lookAtPosition,
		Vector3D vectorUp
	);

	static Matrix3D BuildTranslationMatrix(Vector3D position);
	static Matrix3D BuildScaleMatrix(Vector3D scale);
	static Matrix3D BuildRotationMatrix(Vector3D rotation);

private:
	MatrixUtils() {}
	MatrixUtils(const MatrixUtils&) {}
};

