#include <stdexcept>

#include "ShaderLoader.h"
#include "ShaderUtils.h"

using namespace CoreManagers;

ShaderLoader* ShaderLoader::instance = nullptr;

ShaderLoader::~ShaderLoader()
{
	currentId = 0;
}

ShaderLoader * ShaderLoader::GetInstance()
{
	if (instance == nullptr)
	{
		throw std::invalid_argument(
			"ShaderLoader instance has not been initialized"
		);
	}

	return instance;
}

void ShaderLoader::LoadShaderById(int id)
{
	_loadShaderById(id);
}

unsigned int ShaderLoader::GetVertexPositionOffset()
{
	return ShaderUtils::GetVertexFormatPostionOffset();
}

unsigned int ShaderLoader::GetVertexColorOffset()
{
	return ShaderUtils::GetVertexFormatColorOffset();
}


std::string ShaderLoader::_getCurrentName()
{
	std::string name = "";

	typedef ShaderNames::iterator iterator;
	for (iterator it = _shaderNames.begin(); it != _shaderNames.end(); it++)
	{
		name = name + "_" + *it;
	}

	_shaderNames.clear();

	return name;
}

bool ShaderLoader::_shaderExists(const char * name)
{
	return _shaderMap.find(name) != _shaderMap.end();
}

bool CoreManagers::ShaderLoader::_programExists(const char * name)
{
	return _programNameMap.find(name) != _programNameMap.end();
}
