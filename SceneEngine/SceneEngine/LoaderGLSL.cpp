#include "LoaderGLSL.h"

#include <iostream>
#include <fstream>
#include <vector>

#include "ShaderUtils.h"

using namespace ModelData;
using namespace CoreManagers;

LoaderGLSL::~LoaderGLSL()
{
	typedef ProgramMap::iterator ProgramIt;

	for (ProgramIt it = _programMap.begin(); it != _programMap.end(); it++)
	{
		glDeleteProgram(it->second.GetProgramId());
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

void LoaderGLSL::LoadShader(
	ShaderType type, 
	const char * fileName, 
	const char * name
)
{
	GLenum shaderType = _getShaderType(type);
	string source = ShaderUtils::ReadShaderFile(fileName);

	switch (type)
	{
	case ShaderType::VERTEX:
		_vertexShader = _createOrGetShader(shaderType, source, name);
		break;
	case ShaderType::FRAGMENT:
		_fragmentShader = _createOrGetShader(shaderType, source, name);
		break;
	default:
		std::cout << "ERR: Unsupported shader type (" << type
			<< ") Refer ShaderLoader::Type\n";

		throw std::invalid_argument("ERR: Unsupported shader type");
	}
}

int LoaderGLSL::CreateOrGetProgram()
{
	std::string name = _getCurrentName();
	if (_programExists(name.c_str()))
	{
		return _programNameMap[name.c_str()];
	}

	if (_programMap.find(currentId) != _programMap.end())
	{
		printf("ERR: Shader Program ID already exists\n");
		throw std::invalid_argument("ERR: Shader Program ID already exists");
	}

	unsigned int programId = _linkProgram();
	ShaderInfo shaderInfo(programId);
	_programMap[currentId] = shaderInfo;
	_programNameMap[name] = currentId;

	currentId++;

	return currentId - 1;
}

int LoaderGLSL::SetPropertyId(unsigned int shaderId, std::string uniformName)
{
	unsigned int programId = _programMap[shaderId].GetProgramId();
	int location = glGetUniformLocation(programId, uniformName.c_str());
	_programMap[shaderId].AddUniform(uniformName, location);

	return location;
}

void CoreManagers::LoaderGLSL::BindUniformMatrix(int shaderId, std::string name, Matrix3D matrix)
{
	ShaderInfo shaderInfo = _programMap[shaderId];
	int location = shaderInfo.SetPropertyId(name);

	float * data = matrix.getData();
	glUniformMatrix4fv(location, 1, GL_TRUE, data);
}

unsigned int LoaderGLSL::CreateVertexArrayObject(unsigned int amount)
{
	unsigned int vao;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	return vao;
}

unsigned int LoaderGLSL::CreateVertexArrayBuffer(
	unsigned int amount, 
	VertexDataVector vertices, 
	BufferDrawType bufferDrawType
)
{
	GLenum drawType = _getDrawType(bufferDrawType);

	unsigned int vbo;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(
		GL_ARRAY_BUFFER, 
		sizeof(VertexFormat) * vertices.size(), 
		&vertices[0], 
		drawType
	);

	return vbo;
}

void LoaderGLSL::BindVertexAttributes(
	unsigned int location, 
	int size, 
	bool normalized, 
	unsigned int offset
)
{
	glEnableVertexAttribArray(location);
	glVertexAttribPointer(
		location, 
		size, 
		GL_FLOAT, 
		normalized, 
		sizeof(VertexFormat), 
		(void*)offset
	);
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
	//printf("Current vao => %d\n", current_vao);
}

//--- Private Implementation --------------------------------------------------

GLuint LoaderGLSL::_createOrGetShader(
	GLenum shaderType, 
	string source, 
	const char * name
)
{
	_shaderNames.push_back(name);

	if (_shaderExists(name))
	{
		return _shaderMap[name];
	}

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

	_shaderMap[name] = shader;

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
		printf("ERR: Shader Program ID already exists\n");
		throw std::invalid_argument("ERR: Shader Program ID already exists");
	}

	return program;
}

void LoaderGLSL::_loadShaderById(int id)
{
	ShaderInfo shaderInfo = _programMap.at(id);

	glUseProgram(shaderInfo.GetProgramId());
	//shaderInfo.Print();
}

GLenum LoaderGLSL::_getDrawType(BufferDrawType drawType)
{
	switch (drawType)
	{
	case BufferDrawType::STATIC_DRAW:	return GL_STATIC_DRAW;
	case BufferDrawType::DYNAMIC_DRAW:	return GL_DYNAMIC_DRAW;
	default:							
		throw std::invalid_argument("Buffer Draw Type not supported");
	}
}
