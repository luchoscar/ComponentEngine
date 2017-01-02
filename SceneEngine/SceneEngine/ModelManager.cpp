#include "ModelManager.h"

#include "../Dependencies/glew/glew.h"

#include <iostream>

ModelManager * ModelManager::_instance = nullptr;

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
