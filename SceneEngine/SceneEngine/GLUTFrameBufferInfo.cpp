#include "GLUTFrameBufferInfo.h"

#include "../Dependencies/freeglut/freeglut.h"

using namespace Core;

GLUTFrameBufferInfo::GLUTFrameBufferInfo() : FrameBufferInfo()
{
	_flags = GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH;
	_msaa = false;
}

GLUTFrameBufferInfo::GLUTFrameBufferInfo(
	bool color, 
	bool depth, 
	bool stencil, 
	bool msaa
) : FrameBufferInfo()
{
	_flags = GLUT_DOUBLE;

	if (color)
	{
		_flags |= GLUT_RGBA | GLUT_ALPHA;
	}
	
	if (depth)
	{
		_flags |= GLUT_DEPTH;
	}

	if (stencil)
	{
		_flags |= GLUT_STENCIL;
	}

	if (msaa)
	{
		_flags |= GLUT_MULTISAMPLE;
	}

	_msaa = msaa;
}
