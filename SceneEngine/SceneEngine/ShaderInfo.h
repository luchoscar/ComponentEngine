#pragma once

#include <map>

namespace CoreManagers
{
	class ShaderInfo
	{
	public:
		ShaderInfo() {}
		ShaderInfo(unsigned int id);
		ShaderInfo(const ShaderInfo& info);

		~ShaderInfo();

		void SetProgramId(unsigned int id);
		unsigned int GetProgramId();
		void AddUniform(std::string name, int id);
		int GetUniformId(std::string name);
		std::map<std::string, int> GetUniforms();

		void Print();
	private:

		unsigned int _programId;
		std::map<std::string, int> _uniformsMap;
	};
}
