#pragma once

namespace Core
{
	class FrameBufferInfo
	{
	public:
		FrameBufferInfo() {}
		FrameBufferInfo(const FrameBufferInfo&) {}

		virtual ~FrameBufferInfo() {}

		unsigned int GetFlags();
		bool HasMSAA();

	protected:

		unsigned int _flags;
		bool _msaa;
	};
}
