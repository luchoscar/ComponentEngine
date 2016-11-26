#pragma once

class GraphicAPI
{
public:
	enum  Type
	{
		OPEN_GL = 0,
		DIRECT_X
	};

	virtual ~GraphicAPI();
	
	static GraphicAPI* GetInstance();
	
	virtual void Init(int *argc, char **argv, int xWinPos, int yWinPos, int winWidth, int winHieght) = 0;

	virtual void Run() = 0;
	virtual void ClearScreen() = 0;
	virtual void SwapBuffers() = 0;
	virtual void DrawTriangles() = 0;
	virtual void ExitLoop() = 0;

	virtual void SetUpdateCallBack(void (*callBack)(void)) = 0;
	virtual void SetDisplayCallBack(void(*callBack)(void)) = 0;
	virtual void SetKeyboardCallBack(void(*callBack)(unsigned char c, int x, int y)) = 0;
	virtual void SetResizeCallBack(void(*callBack)(int width, int height)) = 0;
	virtual void SetCloseCallBack(void(*callBack)(void)) = 0;

protected:
	GraphicAPI() {}
	GraphicAPI(GraphicAPI&) {}

	static GraphicAPI * instance;
};
