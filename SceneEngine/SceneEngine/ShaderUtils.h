#pragma once

#include <string>

class ShaderUtils
{
	typedef std::string string;

public:
	static string ReadShaderFile(const char * fileName);
};
