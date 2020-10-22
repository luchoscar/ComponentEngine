#include "InitData.h"

Core::InitData::InitData()
{

}

Core::InitData::InitData(WindowInfo wi, ContextInfo ci, FrameBufferInfo * fbi)
{
	_window = wi;
	_context = ci;
	_frameBuffer = fbi;
}

Core::InitData::~InitData()
{
	_frameBuffer = nullptr;
}
