#pragma once

#include <map>
#include <string>

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
		int SetPropertyId(std::string name);
		std::map<std::string, int> GetUniforms();

		void Print();
	private:

		unsigned int _programId;
		std::map<std::string, int> _uniformsMap;
	};
}
