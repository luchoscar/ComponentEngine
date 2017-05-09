#include "FrameBufferInfo.h"

Core::FrameBufferInfo::FrameBufferInfo(const FrameBufferInfo & buffer)
{
	_flags = buffer._flags;
}

unsigned int Core::FrameBufferInfo::GetFlags()
{
	return _flags;
}

bool Core::FrameBufferInfo::HasMSAA()
{
	return _msaa;
}
