#pragma once

#include "FrameBufferInfo.h"

namespace Core
{
	class GLUTFrameBufferInfo : FrameBufferInfo
	{
	public:
		GLUTFrameBufferInfo();
		GLUTFrameBufferInfo(bool color, bool depth, bool stencil, bool msaa);

		~GLUTFrameBufferInfo() {}

		unsigned int GetFlags() { return _flags; }
		bool HasMSAA() { return _msaa; }

	private:
		unsigned int _flags;
		bool _msaa;
	};
}
