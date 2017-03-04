#pragma once

#include <string>

#include "Vector2D.h"

namespace Core
{
	class WindowInfo
	{
	public:
		WindowInfo();
		WindowInfo(
			std::string name, 
			Vector2D<int> size, 
			Vector2D<int> position, 
			bool resizable
		);
		WindowInfo(const WindowInfo& window);

		~WindowInfo();

		std::string GetName();
		Vector2D<int> GetSize(); 
		Vector2D<int> GetPosition();
		bool CanResize();

	private:
		std::string _name;
		Vector2D<int> _size;
		Vector2D<int> _position;
		bool _resizable;
	};
}
