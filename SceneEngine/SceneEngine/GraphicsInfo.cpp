#include "GraphicsInfo.h"

using namespace Core;

GraphicsInfo::GraphicsInfo()
{
	_majorVersion = 3;
	_minorVersion = 3;
	_core = true;
}

GraphicsInfo::GraphicsInfo(int majorVersion, int minorVersion, bool core)
{
	_minorVersion = minorVersion;
	_majorVersion = majorVersion;
	_core = core;
}