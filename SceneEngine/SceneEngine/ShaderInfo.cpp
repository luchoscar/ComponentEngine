#include "ShaderInfo.h"
#include <sstream>

using namespace CoreManagers;

ShaderInfo::ShaderInfo(unsigned int id)
{
	_programId = id;
}

ShaderInfo::ShaderInfo(const ShaderInfo & info)
{
	_programId = info._programId;

	std::map<std::string, int> infoMap = info._uniformsMap;
	for (std::map<std::string, int>::iterator it = infoMap.begin(); it != infoMap.end(); it++)
	{
		std::pair<std::string, int> infoPair((*it).first, (*it).second);
		_uniformsMap.insert(infoPair);
	}
}

ShaderInfo::~ShaderInfo()
{
	_uniformsMap.clear();
}

void ShaderInfo::SetProgramId(unsigned int id)
{
	_programId = id;
}

unsigned int ShaderInfo::GetProgramId()
{
	return _programId;
}

void ShaderInfo::AddUniform(std::string name, int id)
{
	std::pair<std::string, int> uniformData(name, id);
	_uniformsMap.insert(uniformData);
}

int ShaderInfo::SetPropertyId(std::string name)
{
	return _uniformsMap.at(name);
}

std::map<std::string, int> CoreManagers::ShaderInfo::GetUniforms()
{
	return _uniformsMap;
}

void CoreManagers::ShaderInfo::Print()
{
	std::string uniforms = "";
	for (std::map<std::string, int>::iterator it = _uniformsMap.begin(); it != _uniformsMap.end(); it++)
	{
		std::ostringstream streamer;
		streamer << (*it).first.c_str() << ":" << (*it).second << " ";

		uniforms += streamer.str();
	}

	printf("Program Id %d\nuniforms: %s\n", _programId, uniforms.c_str());
}
