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

	static Matrix3D BuildTranslationMatrix(Vector3D point);

private:
	MatrixUtils() {}
	MatrixUtils(const MatrixUtils&) {}
};

