#pragma once

#include "../Dependencies/glew/glew.h"
#include "../Dependencies/freeglut/freeglut.h"

#include "ShaderLoader.h"

typedef std::string string;
typedef std::map<int, GLuint> ProgramMap;

class LoaderGLSL :
	public ShaderLoader
{
public:
	~LoaderGLSL();

	static ShaderLoader* CreateInstance();

	void LoadShader(ShaderType type, const char* fileName, const char* name);
	int CreateProgram();
	unsigned int CreateVertexArrayObject(unsigned int amount);
	unsigned int CreateVertexArrayBuffer(unsigned int amount, std::vector<VertexFormat> vertices, BufferDrawType bufferDrawType);
	void BindVertexAttributes(unsigned int index, int size);

	void BindVertexData(unsigned int vao);

	// Debug Functions
	void PrintCurrentVertexArrayObject();

private:
	LoaderGLSL() {}
	LoaderGLSL(LoaderGLSL&) {}

	GLuint _createShader(GLenum shaderType, string source, const char* name);
	GLenum _getShaderType(ShaderType type);
	GLuint _linkProgram();

	void _loadShaderById(int id);

	GLenum _getDrawType(BufferDrawType drawType);

	GLuint _vertexShader = 0;
	GLuint _fragmentShader = 0;
	ProgramMap _programMap;
};

