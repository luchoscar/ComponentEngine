#include "ModelManager.h"

#include "../Dependencies/glew/glew.h"

#include <iostream>

ModelManager * ModelManager::_instance = nullptr;

ModelManager::~ModelManager()
{
	std::map<std::string, Model>::iterator it;
	for (it = _modelMap.begin(); it != _modelMap.end(); it++)
	{
		unsigned int* vao = &it->second.vao;	
		glDeleteVertexArrays(1, vao);
		glDeleteBuffers(it->second.vbos.size(), &it->second.vbos[0]);
		it->second.vbos.clear();
	}

	_modelMap.clear();
}

ModelManager * ModelManager::GetInstance()
{
	if (_instance == nullptr) {
		_instance = new ModelManager();
	}

	return _instance;
}

void ModelManager::AddModel(std::string name, Model model)
{
	_modelMap.insert(std::pair<std::string, Model>(name, model));
}

Model ModelManager::GetModel(std::string name)
{
	return _modelMap.at(name);
}
