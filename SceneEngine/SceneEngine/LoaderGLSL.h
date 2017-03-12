#pragma once

#include "../Dependencies/glew/glew.h"
#include "../Dependencies/freeglut/freeglut.h"

#include "ShaderLoader.h"

namespace CoreManagers
{
	typedef std::string string;

	class LoaderGLSL :
		public ShaderLoader
	{
	public:
		~LoaderGLSL();

		static ShaderLoader* CreateInstance();

		void LoadShader(ShaderType type, const char* fileName, const char* name);
		int CreateOrGetProgram();
		unsigned int CreateVertexArrayObject(unsigned int amount);
		unsigned int CreateVertexArrayBuffer(
			unsigned int amount, 
			VertexDataVector vertices, 
			BufferDrawType bufferDrawType
		);
		void BindVertexAttributes(
			unsigned int location, 
			int size, 
			bool normalized, 
			unsigned int offset
		);

		void BindVertexData(unsigned int vao);

		void DeleteVertexArrayObject(int amount, unsigned int* vaoAddress);
		void DeleteVertexBufferObject(int amount, unsigned int* vbosAddress);

		// Debug Functions
		void PrintCurrentVertexArrayObject();

	private:
		LoaderGLSL() {}
		LoaderGLSL(LoaderGLSL&) {}

		GLuint _createOrGetShader(GLenum shaderType, string source, const char* name);
		GLenum _getShaderType(ShaderType type);
		GLuint _linkProgram();

		void _loadShaderById(int id);

		GLenum _getDrawType(BufferDrawType drawType);

		GLuint _vertexShader = 0;
		GLuint _fragmentShader = 0;
	};
}
