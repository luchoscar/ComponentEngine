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

private:
	LoaderGLSL() {}
	LoaderGLSL(LoaderGLSL&) {}

	string _readShaderFile(const char * fileName);
	GLuint _createShader(GLenum shaderType, string source, const char* name);
	GLenum _getShaderType(ShaderType type);
	bool _buildProgram();
	GLuint _linkProgram();

	void _loadShaderById(int id);

	GLuint _vertexShader = 0;
	GLuint _fragmentShader = 0;
	ProgramMap _programMap;
};

