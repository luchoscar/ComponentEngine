#pragma once

namespace Core
{
	class FrameBufferInfo
	{
	public:
		FrameBufferInfo() { _flags = 0; }
		FrameBufferInfo(const FrameBufferInfo& buffer);

		virtual ~FrameBufferInfo() {}

		unsigned int GetFlags();
		bool HasMSAA();

	protected:

		unsigned int _flags;
		bool _msaa;
	};
}
