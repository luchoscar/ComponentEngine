
#include "GraphicOpenGL.h"

#include <iostream>

using namespace CoreManagers;

GraphicAPI* GraphicOpenGL::CreateInstance()
{
	if (_instance == nullptr)
	{
		_instance = new GraphicOpenGL();
	}

	return _instance;
}

void GraphicOpenGL::Init(int *argc, char **argv, InitData initData)
{
	glutInit(argc, argv);

	_initContext(initData.GetContext());

	_initFramBuffer(initData.GetFrameBuffer());

	_initWindow(initData.GetWindow());

	glEnable(GL_DEPTH_TEST);

	glewExperimental = GL_TRUE;
	glutSetOption(
		GLUT_ACTION_ON_WINDOW_CLOSE,
		GLUT_ACTION_GLUTMAINLOOP_RETURNS
	);

	if (glewInit() == GLEW_OK)
	{
		_printOpenGLInfo();
	}

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_FRONT);
	//glFrontFace(GL_CCW);
}

void GraphicOpenGL::ClearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void GraphicOpenGL::SwapBuffers()
{
	glutSwapBuffers();
}

void GraphicOpenGL::Run()
{
	glutMainLoop();
}

void GraphicOpenGL::DrawTriangles(DrawingType drawType, int from, int to)
{
	glDrawArrays(_getDrawType(drawType), from, to);
}

void GraphicOpenGL::ExitLoop()
{
	printf("GLUT:\t Finished\n");
	glutLeaveMainLoop();
}

//--- Callback Implementation -------------------------------------------------

void GraphicOpenGL::SetUpdateCallBack(void(*callBack)(void))
{
	glutIdleFunc(callBack);
}

void GraphicOpenGL::SetKeyboardCallBack(
	void(*callBack)(unsigned char c, int x, int y)
)
{
	glutKeyboardFunc(callBack);
}

void GraphicOpenGL::SetIdleCallBack(void(*callBack)(void)) {
	glutIdleFunc(callBack);
}

void GraphicOpenGL::SetDisplayCallBack(void (*callBack)(void))
{
	glutDisplayFunc(callBack);
}

void GraphicOpenGL::SetResizeCallBack(void(*callBack)(int width, int height))
{
	glutReshapeFunc(callBack);
}

void GraphicOpenGL::SetCloseCallBack(void(*callBack)(void))
{
	glutCloseFunc(callBack);
}

//-- Private Implementation ---------------------------------------------------
GLenum GraphicOpenGL::_getDrawType(DrawingType drawType)
{
	switch (drawType) 
	{
	case DrawingType::POINT:					return GL_POINTS;
	case DrawingType::LINE:						return GL_LINES;
	case DrawingType::LINE_STRIP:				return GL_LINE_STRIP;
	case DrawingType::LINE_LOOP:				return GL_LINE_LOOP;
	case DrawingType::LINE_STRIP_ADJACENCY:		return GL_LINE_STRIP_ADJACENCY;
	case DrawingType::LINE_ADJACENCY:			return GL_LINES_ADJACENCY;
	case DrawingType::TRIANGLE:					return GL_TRIANGLES;
	case DrawingType::TRIANGLE_STRIP:			return GL_TRIANGLE_STRIP;
	case DrawingType::TRIANGLE_FAN:				return GL_TRIANGLE_FAN;
	case DrawingType::TRIANGLE_STRIP_ADJACENCY:	return GL_TRIANGLE_STRIP_ADJACENCY;
	case DrawingType::TRIANGLE_ADJACENCY:		return GL_TRIANGLES_ADJACENCY;
	case DrawingType::PATCH:					return GL_PATCHES;
	default:									
		throw std::invalid_argument("Draw type not supported");
	}
}

void CoreManagers::GraphicOpenGL::_initContext(ContextInfo context)
{
	if (context.IsCore())
	{
		glutInitContextVersion(
			context.GetMajorVersion(),
			context.GetMinorVersion()
		);

		glutInitContextProfile(GLUT_CORE_PROFILE);
	}
	else
	{
		glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	}
}

void CoreManagers::GraphicOpenGL::_initWindow(WindowInfo window)
{
	Vector2D<int> position = window.GetPosition();
	glutInitWindowPosition(position.GetX(), position.GetY());

	Vector2D<int> size = window.GetSize();
	glutInitWindowSize(size.GetX(), size.GetY());

	std::string name = window.GetName();
	glutCreateWindow(name.c_str());
}

void CoreManagers::GraphicOpenGL::_initFramBuffer(FrameBufferInfo frameBufer)
{
	unsigned int flags = frameBufer.GetFlags();
	glutInitDisplayMode(flags);
}

void CoreManagers::GraphicOpenGL::_printOpenGLInfo()
{
	std::cout << "GLUT Initialized\n"
		<< "\tVendor   : " << glGetString(GL_VENDOR) << "\n"
		<< "\tRenderer : " << glGetString(GL_RENDERER) << "\n"
		<< "\tOpenGL   : " << glGetString(GL_VERSION) << std::endl;
}
