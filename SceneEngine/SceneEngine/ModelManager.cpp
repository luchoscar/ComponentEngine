#include "ModelManager.h"

#include "../Dependencies/glew/glew.h"

#include <iostream>

#include "ShaderLoader.h"

ModelManager * ModelManager::_instance = nullptr;

ModelManager::~ModelManager()
{
	ShaderLoader* shaderLoader = ShaderLoader::GetInstance();

	std::map<std::string, Model*>::iterator it;
	for (it = _modelMap.begin(); it != _modelMap.end(); it++)
	{
		_deleteModel(it->second);
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

void ModelManager::AddModel(std::string name, Model* model)
{
	_modelMap.insert(std::pair<std::string, Model*>(name, model));
}

Model* ModelManager::GetModel(std::string name)
{
	if (_modelMap.find(name) != _modelMap.end())
	{
		return _modelMap.at(name);
	}

	return nullptr;
}

void ModelManager::DeleteModel(std::string name)
{
	if (_modelMap.find(name) == _modelMap.end())
	{
		return;
	}

	Model* model = _modelMap[name];
	_deleteModel(model);
	
	_modelMap.erase(name);
}

//-- Private Implementation ---------------------------------------------------

void ModelManager::_deleteModel(Model* model)
{
	ShaderLoader* shaderLoader = ShaderLoader::GetInstance();

	shaderLoader->DeleteVertexArrayObject(1, &model->vao);
	shaderLoader->DeleteVertexBufferObject(
		model->vbos.size(),
		&model->vbos[0]
	);

	delete model;
}
