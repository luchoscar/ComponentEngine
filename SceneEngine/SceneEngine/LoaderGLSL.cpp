#include "LoaderGLSL.h"

#include <iostream>
#include <fstream>
#include <vector>

#include "ShaderUtils.h"

LoaderGLSL::~LoaderGLSL()
{
	for (ProgramMap::iterator it = _programMap.begin(); it != _programMap.end(); it++)
	{
		glDeleteProgram(it->second);
	}

	_programMap.clear();
}

ShaderLoader* LoaderGLSL::CreateInstance()
{
	if (instance == nullptr)
	{
		instance = new LoaderGLSL();
	}

	return instance;
}

void LoaderGLSL::LoadShader(ShaderType type, const char * fileName, const char * name)
{
	GLenum shaderType = _getShaderType(type);
	string source = ShaderUtils::ReadShaderFile(fileName);

	switch (type)
	{
	case ShaderType::VERTEX:
		_vertexShader = _createShader(shaderType, source, name);
		break;
	case ShaderType::FRAGMENT:
		_fragmentShader = _createShader(shaderType, source, name);
		break;
	default:
		std::cout << "ERR: Unsupported shader type (" << type
			<< ") Refer ShaderLoader::Type\n";

		throw std::invalid_argument("ERR: Unsupported shader type");
	}
}

int LoaderGLSL::CreateProgram()
{
	if (_programMap.find(currentId) != _programMap.end())
	{
		std::cout << "ERR: Shader Program ID already exists\n";
		throw std::invalid_argument("ERR: Shader Program ID already exists");
	}

	_programMap[currentId] = _linkProgram();

	currentId++;

	return currentId - 1;
}

unsigned int LoaderGLSL::CreateVertexArrayObject(unsigned int amount)
{
	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	return vao;
}

unsigned int LoaderGLSL::CreateVertexArrayBuffer(unsigned int amount, std::vector<VertexFormat> vertices, BufferDrawType bufferDrawType)
{
	GLenum drawType = _getDrawType(bufferDrawType);

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * vertices.size(), &vertices[0], drawType);

	return vbo;
}

void LoaderGLSL::BindVertexAttributes(unsigned int index, int size)
{
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
}

void LoaderGLSL::BindVertexData(unsigned int vao)
{
	glBindVertexArray(vao);
}

void LoaderGLSL::DeleteVertexArrayObject(int amount, unsigned int* vaoAddress)
{
	glDeleteVertexArrays(amount, vaoAddress);
}

void LoaderGLSL::DeleteVertexBufferObject(int amount, unsigned int* vbosAddress)
{
	glDeleteBuffers(amount, vbosAddress);
}

void LoaderGLSL::PrintCurrentVertexArrayObject()
{
	GLint current_vao;
	glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &current_vao);
	std::cout << "Current vao => " << current_vao << "\n";
}

//--- Private Implementation --------------------------------------------------

GLuint LoaderGLSL::_createShader(GLenum shaderType, string source, const char * name)
{
	int compileResult = 0;

	const char* codePointer = source.c_str();
	const int codeSize = source.size();

	GLuint shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &codePointer, &codeSize);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compileResult);

	if (compileResult == GL_FALSE)
	{
		int logLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> shaderLog(logLength);
		glGetShaderInfoLog(shader, logLength, NULL, &shaderLog[0]);

		std::cout << "ERR: Compiling shader: " 
			<< name << "\n" 
			<< &shaderLog[0] << "\n";

		throw std::invalid_argument("ERR: Compiling shader");
	}

	return shader;
}

GLenum LoaderGLSL::_getShaderType(ShaderType type)
{
	switch (type)
	{
	case ShaderType::VERTEX:
		return GL_VERTEX_SHADER;

	case ShaderType::FRAGMENT:
		return GL_FRAGMENT_SHADER;
	default:
		std::cout << "ERR: Unsupported shader type (" << type
			<< ") Refer ShaderLoader::Type\n";

		throw std::invalid_argument("ERR: Unsupported shader type");
	}
}

GLuint LoaderGLSL::_linkProgram()
{
	int linkResult = 0;

	GLuint program = glCreateProgram();
	glAttachShader(program, _vertexShader);
	glAttachShader(program, _fragmentShader);

	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &linkResult);

	if (linkResult == GL_FALSE)
	{
		int logLength = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> log(logLength);
		glGetProgramInfoLog(program, logLength, NULL, &log[0]);
		std::cout << "ERR: Shader Loader : LINK ERROR\n" << &log[0] << "\n";

		throw std::invalid_argument("ERR: Shader Loader : LINK ERROR");
	}

	if (_programMap.find(currentId) != _programMap.end())
	{
		std::cout << "ERR: Shader Program ID already exists\n";
		throw std::invalid_argument("ERR: Shader Program ID already exists");
	}

	return program;
}

void LoaderGLSL::_loadShaderById(int id)
{
	glUseProgram(_programMap.at(id));
}

GLenum LoaderGLSL::_getDrawType(BufferDrawType drawType)
{
	switch (drawType)
	{
	case BufferDrawType::STATIC_DRAW:	return GL_STATIC_DRAW;
	case BufferDrawType::DYNAMIC_DRAW:	return GL_DYNAMIC_DRAW;
	default:							throw std::invalid_argument("Buffer Draw Type not supported");
	}
}
