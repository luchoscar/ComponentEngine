#pragma once

#include "GraphicAPI.h"

class GraphicOpenGL :
	public GraphicAPI
{
public:
	~GraphicOpenGL() {}

	static GraphicAPI* CreateInstance();
	
	void Init(int *argc, char **argv, int xWinPos, int yWinPos, int winWidth, int winHieght);
	void ClearScreen();
	void SwapBuffers();
	void Run();
	void DrawTriangles();
	void ExitLoop();

	void SetUpdateCallBack(void(*callBack)(void));
	void SetKeyboardCallBack(void(*callBack)(unsigned char c, int x, int y));
	void SetDisplayCallBack(void(*callBack)(void));
	void SetResizeCallBack(void(*callBack)(int width, int height));
	void SetCloseCallBack(void(*callBack)(void));

private:
	GraphicOpenGL() {}
	GraphicOpenGL(GraphicOpenGL&) {}
};

