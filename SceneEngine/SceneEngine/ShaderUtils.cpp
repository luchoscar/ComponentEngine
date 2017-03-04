#include "ShaderUtils.h"

#include <iostream>
#include <fstream>

#include "VertexFormat.h"

using namespace ModelData;
using namespace CoreManagers;

std::string ShaderUtils::ReadShaderFile(const char * fileName)
{
	string shaderCode;

	std::ifstream file(fileName, std::ios::in);

	if (!file.good())
	{
		std::cout << "Shader file " << fileName << " cannot be read\n";
		std::terminate();

		throw std::invalid_argument("Shader file cannot be read");
	}

	file.seekg(0, std::ios::end);
	shaderCode.resize(static_cast<unsigned int>(file.tellg()));

	file.seekg(0, std::ios::beg);
	file.read(&shaderCode[0], shaderCode.size());

	file.close();

	return shaderCode;
}

unsigned int ShaderUtils::GetVertexFormatPostionOffset()
{
	return offsetof(VertexFormat, VertexFormat::position);
}

unsigned int ShaderUtils::GetVertexFormatColorOffset()
{
	return offsetof(VertexFormat, VertexFormat::color);
}
