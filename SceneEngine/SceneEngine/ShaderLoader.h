#pragma once

#include <map>

#include "GraphicAPI.h"

typedef GraphicAPI::ShaderType ShaderType;

class ShaderLoader
{
public:
	virtual ~ShaderLoader();

	virtual void LoadShader(ShaderType type, const char* fileName, const char* name) = 0;
	virtual int CreateProgram() = 0;

	static ShaderLoader* GetInstance();

	void LoadShaderById(int id);

protected:
	ShaderLoader() {}
	ShaderLoader(ShaderLoader&) {}

	virtual void _loadShaderById(int id) = 0;

	static ShaderLoader* instance;

	unsigned int currentId = 0;
};

