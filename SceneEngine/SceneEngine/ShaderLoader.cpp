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
