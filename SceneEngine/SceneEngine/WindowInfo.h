#pragma once

#include <string>
#include "Vector2DNew.h"

namespace Core
{
	class WindowInfo
	{
	public:
		WindowInfo();
		WindowInfo(
			std::string name, 
			Vector2DNew<int> size,
			Vector2DNew<int> position,
			bool resizable
		);
		WindowInfo(const WindowInfo& window);
		
		std::string GetName();
		Vector2DNew<int> GetSize();
		Vector2DNew<int> GetPosition();
		bool CanResize();

	private:
		std::string _name;
		Vector2DNew<int> _size;
		Vector2DNew<int> _position;
		bool _resizable;
	};
}
