#pragma once

namespace Core
{
	class FrameBufferInfo
	{
	public:
		~FrameBufferInfo() {}

		unsigned int GetFlags() { return _flags; }
		bool HasMSAA() { return _msaa; }

	protected:
		FrameBufferInfo() {}
		FrameBufferInfo(const FrameBufferInfo&) {}

		unsigned int _flags;
		bool _msaa;
	};
}
