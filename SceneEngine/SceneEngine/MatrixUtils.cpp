
#include "MatrixUtils.h"
#include "MathUtils.h"

#include <cmath>

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

Matrix3D MatrixUtils::BuildLookAtMatrix(
	Vector3D cameraPosition,
	Vector3D lookAtPosition,
	Vector3D vectorUp
)
{
	Vector3D zAxis = cameraPosition - lookAtPosition;
	zAxis = zAxis.GetNormalized();

	Vector3D xAxis = Vector3D::CrossProduct(vectorUp, zAxis);
	xAxis = xAxis.GetNormalized();

	Vector3D yAxis = Vector3D::CrossProduct(zAxis, xAxis);
	yAxis = yAxis.GetNormalized();

	/* Build resulting view matrix. */
	Matrix3D outMat;

	float axisDotProd = -xAxis.GetX() * cameraPosition.GetX() + -xAxis.GetY() * cameraPosition.GetY() + -xAxis.GetZ() * cameraPosition.GetZ();
	outMat[0] = xAxis.GetX();  outMat[1] = xAxis.GetY(); outMat[2] = xAxis.GetZ();  outMat[3] = axisDotProd;

	axisDotProd = -yAxis.GetX() * cameraPosition.GetX() + -yAxis.GetY() * cameraPosition.GetY() + -yAxis.GetZ() * cameraPosition.GetZ();
	outMat[4] = yAxis.GetX();  outMat[5] = yAxis.GetY(); outMat[6] = yAxis.GetZ();  outMat[7] = axisDotProd;

	axisDotProd = -zAxis.GetX() * cameraPosition.GetX() + -zAxis.GetY() * cameraPosition.GetY() + -zAxis.GetZ() * cameraPosition.GetZ();
	outMat[8] = zAxis.GetX();  outMat[9] = zAxis.GetY(); outMat[10] = zAxis.GetZ();  outMat[11] = axisDotProd;

	outMat[12] = 0.0f;   outMat[13] = 0.0f;  outMat[14] = 0.0f;   outMat[15] = 1.0f;

	return outMat;
}

Matrix3D MatrixUtils::BuildTranslationMatrix(Vector3D position)
{
	Matrix3D matrix;
	matrix[3]	= position.GetX();
	matrix[7]	= position.GetY();
	matrix[11]	= position.GetZ();

	return matrix;
}

Matrix3D MatrixUtils::BuildScaleMatrix(Vector3D scale)
{
	Matrix3D matrix;
	matrix[0]	= scale.GetX();
	matrix[5]	= scale.GetY();
	matrix[10]	= scale.GetZ();

	return matrix;
}

Matrix3D MatrixUtils::BuildRotationMatrix(Vector3D rotation)
{
	return Matrix3D();
}