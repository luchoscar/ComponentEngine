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

		char* GetVersion() override;
		void LoadShader(ShaderType type, const char* fileName, const char* name) override;
		int CreateOrGetProgram() override;
		int SetPropertyId(unsigned int shaderId, std::string uniformName) override;
		void BindUniformMatrix(int shaderId, std::string name, Matrix3D matrix) override;

		unsigned int CreateVertexArrayObject(unsigned int amount) override;
		unsigned int CreateVertexArrayBuffer(
			unsigned int amount, 
			VertexDataVector vertices, 
			BufferDrawType bufferDrawType
		) override;
		void BindVertexAttributes(
			unsigned int location, 
			int size, 
			bool normalized, 
			unsigned int offset
		) override;

		void BindVertexData(unsigned int vao) override;

		void DeleteVertexArrayObject(int amount, unsigned int* vaoAddress) override;
		void DeleteVertexBufferObject(int amount, unsigned int* vbosAddress) override;

		// Debug Functions
		void PrintCurrentVertexArrayObject() override;

	private:
		LoaderGLSL() {}
		LoaderGLSL(LoaderGLSL&) { }

		GLuint _createOrGetShader(GLenum shaderType, string source, const char* name);
		GLenum _getShaderType(ShaderType type);
		GLuint _linkProgram();

		void _loadShaderById(int id);

		GLenum _getDrawType(BufferDrawType drawType);

		GLuint _vertexShader = 0;
		GLuint _fragmentShader = 0;
	};
}
