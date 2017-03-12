#pragma once

#include "WindowInfo.h"
#include "FrameBufferInfo.h"
#include "ContextInfo.h"

namespace Core
{
	class InitData
	{
	public:
		InitData();
		InitData(WindowInfo wi, ContextInfo ci, FrameBufferInfo fbi);
		
		~InitData();

		WindowInfo GetWindow() { return _window; }
		ContextInfo GetContext() { return _context; }
		FrameBufferInfo GetFrameBuffer() { return _frameBuffer; }
	private:
		WindowInfo _window;
		ContextInfo _context;
		FrameBufferInfo _frameBuffer;
	};
}
