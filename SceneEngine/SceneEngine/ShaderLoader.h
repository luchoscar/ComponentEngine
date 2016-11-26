#pragma once

#include <map>

class ShaderLoader
{
public:
	enum Type { VERTEX, FRAGMENT };
	typedef ShaderLoader::Type ShaderType;

	virtual ~ShaderLoader();

	virtual void LoadShader(ShaderType type, char* fileName, char* name) = 0;
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

