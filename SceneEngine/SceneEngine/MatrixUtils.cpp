#include "MatrixUtils.h"

#include "MathUtils.h"

Matrix3D MatrixUtils::BuildPerspectiveMatrix(
	double fieldOfView, 
	double aspectRatio, 
	double zNear, 
	double zFar
)
{
	Matrix3D outMatrix;

	double sine, cotangent, deltaZ;
	double radians = fieldOfView / 2.0 * MathUtils::PI / 180.0;

	deltaZ = zFar - zNear;
	sine = MathUtils::sine(radians);

	/* Should be non-zero to avoid division by zero. */
	//assert(deltaZ);
	//assert(sine);
	//assert(aspectRatio);

	cotangent = MathUtils::cosine(radians) / sine;

	outMatrix[0 * 4 + 0] = (cotangent / aspectRatio);
	outMatrix[0 * 4 + 1] = 0.0;
	outMatrix[0 * 4 + 2] = 0.0;
	outMatrix[0 * 4 + 3] = 0.0;

	outMatrix[1 * 4 + 0] = 0.0;
	outMatrix[1 * 4 + 1] = cotangent;
	outMatrix[1 * 4 + 2] = 0.0;
	outMatrix[1 * 4 + 3] = 0.0;

	outMatrix[2 * 4 + 0] = 0.0;
	outMatrix[2 * 4 + 1] = 0.0;
	outMatrix[2 * 4 + 2] = (-(zFar + zNear) / deltaZ);
	outMatrix[2 * 4 + 3] = (-2 * zNear * zFar / deltaZ);

	outMatrix[3 * 4 + 0] = 0.0;
	outMatrix[3 * 4 + 1] = 0.0;
	outMatrix[3 * 4 + 2] = -1;
	outMatrix[3 * 4 + 3] = 0;

	return outMatrix;
}

Matrix3D MatrixUtils::BuildTranslationMatrix(Vector3D point)
{
	Matrix3D matrix = Matrix3D::Identity();
	matrix[3]	= point.GetX();
	matrix[7]	= point.GetY();
	matrix[11]	= point.GetZ();

	return matrix;
}
