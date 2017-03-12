#pragma once

#include "FrameBufferInfo.h"

namespace Core
{
	class GLUTFrameBufferInfo : public FrameBufferInfo
	{
	public:
		GLUTFrameBufferInfo();
		GLUTFrameBufferInfo(bool color, bool depth, bool stencil, bool msaa);

		~GLUTFrameBufferInfo() {}
	};
}
