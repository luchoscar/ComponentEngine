#pragma once

#include <string>

namespace CoreManagers
{
	class ShaderUtils
	{
		typedef std::string string;

	public:
		static string ReadShaderFile(const char * fileName);
		static unsigned int GetVertexFormatPostionOffset();
		static unsigned int GetVertexFormatColorOffset();
	};
}
