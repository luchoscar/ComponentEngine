#include <stdexcept>

#include "GraphicAPI.h"
#include "GraphicOpenGL.h"

GraphicAPI* GraphicAPI::instance = nullptr;

GraphicAPI::~GraphicAPI()
{
	delete instance;
}

GraphicAPI * GraphicAPI::GetInstance()
{
	if (instance == nullptr)
	{
		throw std::invalid_argument(
			"GraphicAPI instance has not been initialized"
		);
	}

	return instance;
}
