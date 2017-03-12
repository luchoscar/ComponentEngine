#include <stdexcept>

#include "GraphicAPI.h"
#include "GraphicOpenGL.h"

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
