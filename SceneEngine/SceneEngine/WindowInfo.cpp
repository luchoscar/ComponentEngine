#include "WindowInfo.h"

using namespace Core;

WindowInfo::WindowInfo()
{
	_name = "Component Engine";
	_size.SetX(800);
	_size.SetY(600);

	_position.SetX(300);
	_position.SetY(300);

	_resizable = true;
}

WindowInfo::WindowInfo(
	std::string name,
	Vector2D<int> size,
	Vector2D<int> position,
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

std::string Core::WindowInfo::GetName()
{
	return _name;
}

Vector2D<int> Core::WindowInfo::GetSize()
{
	return _size;
}

Vector2D<int> Core::WindowInfo::GetPosition()
{
	return _position;
}

bool Core::WindowInfo::CanResize()
{
	return _resizable;
}
