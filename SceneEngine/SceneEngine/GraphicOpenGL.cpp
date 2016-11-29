
#include "GraphicOpenGL.h"

#include <iostream>

GraphicAPI* GraphicOpenGL::CreateInstance()
{
	if (instance == nullptr)
	{
		instance = new GraphicOpenGL();
	}

	return instance;
}

void GraphicOpenGL::Init(int *argc, char **argv, int xWinPos, int yWinPos, int winWidth, int winHieght)
{
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(xWinPos, yWinPos);//optional
	glutInitWindowSize(winWidth, winHieght); //optional
	glutCreateWindow("OpenGL First Window");

	glEnable(GL_DEPTH_TEST);

	glewInit();

	if (glewIsSupported("GL_VERSION_3_3"))
	{
		std::cout << "MSG: GLEW Version is 3.3\n";
	}
	else
	{
		std::cout << "WRN: GLEW 3.3 not supported\n";
	}
}

void GraphicOpenGL::ClearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
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
	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}

//--- Callback Implementation -------------------------------------------------

void GraphicOpenGL::SetUpdateCallBack(void(*callBack)(void))
{
	glutIdleFunc(callBack);
}

void GraphicOpenGL::SetKeyboardCallBack(void(*callBack)(unsigned char c, int x, int y))
{
	glutKeyboardFunc(callBack);
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

GLenum GraphicOpenGL::_getDrawType(DrawingType drawType)
{
	switch (drawType) {
	case DrawingType::POINT:
		return GL_POINTS;
	case DrawingType::LINE:
		return GL_LINES;
	case DrawingType::LINE_STRIP:
		return GL_LINE_STRIP;
	case DrawingType::LINE_LOOP:
		return GL_LINE_LOOP;
	case DrawingType::LINE_STRIP_ADJACENCY:
		return GL_LINE_STRIP_ADJACENCY;
	case DrawingType::LINE_ADJACENCY:
		return GL_LINES_ADJACENCY;
	case DrawingType::TRIANGLE:
		return GL_TRIANGLES;
	case DrawingType::TRIANGLE_STRIP:
		return GL_TRIANGLE_STRIP;
	case DrawingType::TRIANGLE_FAN:
		return GL_TRIANGLE_FAN;
	case DrawingType::TRIANGLE_STRIP_ADJACENCY:
		return GL_TRIANGLE_STRIP_ADJACENCY;
	case DrawingType::TRIANGLE_ADJACENCY:
		return GL_TRIANGLES_ADJACENCY;
	case DrawingType::PATCH:
		return GL_PATCHES;
	default:
		throw std::invalid_argument("Draw type not supported");
	}
}
