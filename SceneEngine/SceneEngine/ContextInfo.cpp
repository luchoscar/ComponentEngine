#include "ContextInfo.h"

using namespace Core;

ContextInfo::ContextInfo()
{
	_majorVersion = 0;
	_minorVersion = 0;
	_core = false;
}

ContextInfo::ContextInfo(int majorVersion, int minorVersion, bool core)
{
	_minorVersion = minorVersion;
	_majorVersion = majorVersion;
	_core = core;
}