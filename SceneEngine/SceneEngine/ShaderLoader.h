#pragma once

#include <map>
#include <vector>

#include "GraphicAPI.h"
#include "VertexFormat.h"

typedef GraphicAPI::ShaderType ShaderType;

class ShaderLoader
{
public:
	enum BufferDrawType
	{
		STATIC_DRAW
	};

	virtual ~ShaderLoader();

	virtual void LoadShader(ShaderType type, const char* fileName, const char* name) = 0;
	virtual int CreateProgram() = 0;
	virtual unsigned int CreateVertexArrayObject(unsigned int amount) = 0;
	virtual unsigned int CreateVertexArrayBuffer(unsigned int amount, std::vector<VertexFormat> vertices, BufferDrawType bufferDrawType) = 0;
	virtual void BindVertexAttributes(unsigned int index, int size) = 0;

	virtual void BindVertexData(unsigned int vao) = 0;
	
	static ShaderLoader* GetInstance();

	void LoadShaderById(int id);

	// Debug Functions
	virtual void PrintCurrentVertexArrayObject() = 0;

protected:
	ShaderLoader() {}
	ShaderLoader(ShaderLoader&) {}

	virtual void _loadShaderById(int id) = 0;

	static ShaderLoader* instance;

	unsigned int currentId = 0;
};

