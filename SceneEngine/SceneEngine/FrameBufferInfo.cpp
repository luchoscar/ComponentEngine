#include "FrameBufferInfo.h"

unsigned int Core::FrameBufferInfo::GetFlags()
{
	return _flags;
}

bool Core::FrameBufferInfo::HasMSAA()
{
	return _msaa;
}
