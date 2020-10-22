#ifndef _GRAPHICS_OPENGL_H_
#define _GRAPHICS_OPENGL_H_

#pragma once

#include "../Dependencies/glew/glew.h"
#include "../Dependencies/freeglut/freeglut.h"

#include "GraphicAPI.h"

namespace CoreManagers
{
	class GraphicOpenGL :
		public GraphicAPI
	{
	public:
		~GraphicOpenGL() {}

		static GraphicAPI* CreateInstance();

		void Init(int *argc, char **argv, InitData initData);

		void ClearScreen();
		void SwapBuffers();
		void Run();
		void DrawTriangles(DrawingType drawType, int from, int to);
		void ExitLoop();

		void SetUpdateCallBack(void(*callBack)(void));
		void SetKeyboardCallBack(void(*callBack)(unsigned char c, int x, int y));
		void SetIdleCallBack(void(*callBack)(void));
		void SetDisplayCallBack(void(*callBack)(void));
		void SetResizeCallBack(void(*callBack)(int width, int height));
		void SetCloseCallBack(void(*callBack)(void));
		
	private:
		GraphicOpenGL() {}
		GraphicOpenGL(GraphicOpenGL&) {}

		GLenum _getDrawType(DrawingType drawType);
		void _initContext(ContextInfo contextInfo);
		void _initWindow(WindowInfo window);
		void _initFramBuffer(FrameBufferInfo * frameBufer);

		void _printOpenGLInfo();
	};
}
#endif;