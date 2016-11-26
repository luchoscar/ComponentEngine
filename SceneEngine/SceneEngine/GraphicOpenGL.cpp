#include "../Dependencies/glew/glew.h"
#include "../Dependencies/freeglut/freeglut.h"

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

void GraphicOpenGL::DrawTriangles()
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
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
