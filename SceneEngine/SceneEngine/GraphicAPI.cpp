#include <stdexcept>

#include "GraphicAPI.h"
#include "GraphicOpenGL.h"
#include "MatrixUtils.h"

using namespace CoreManagers;

GraphicAPI* GraphicAPI::_instance = nullptr;

GraphicAPI * GraphicAPI::GetInstance()
{
	if (_instance == nullptr)
	{
		throw std::invalid_argument(
			"GraphicAPI instance has not been initialized"
		);
	}

	return _instance;
}

void GraphicAPI::SetPerspectiveMatrix(double fieldOfView, double aspectRatio, double zNear, double zFar)
{
	_perspectiveMatrix = MatrixUtils::BuildPerspectiveMatrix(fieldOfView, aspectRatio, zNear, zFar);
}

Matrix3D GraphicAPI::GetPerspectiveMatrix()
{
	return _perspectiveMatrix;
}
