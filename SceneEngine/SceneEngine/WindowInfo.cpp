#include "WindowInfo.h"

using namespace Core;

WindowInfo::WindowInfo()
{
	_name = "Component Engine";
	_size = Vector2DNew<int>(800, 600);

	_position = Vector2DNew<int>(300, 300);

	_resizable = true;
}

WindowInfo::WindowInfo(
	std::string name,
	Vector2DNew<int> size,
	Vector2DNew<int> position,
	bool resizable
)
{
	_name = name;
	_size = size;
	_position = position;
	_resizable = resizable;
}

WindowInfo::WindowInfo(const WindowInfo& window)
{
	_name = window._name;
	_size = window._size;
	_position = window._position;
	_resizable = window._resizable;
}

std::string WindowInfo::GetName()
{
	return _name;
}

Vector2DNew<int> WindowInfo::GetSize()
{
	return _size;
}

Vector2DNew<int> Core::WindowInfo::GetPosition()
{
	return _position;
}

bool WindowInfo::CanResize()
{
	return _resizable;
}
