#include "ModelManager.h"

#include "../Dependencies/glew/glew.h"

#include <iostream>

#include "ShaderLoader.h"
#include "Managers.h"

using namespace CoreManagers;

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

Model * ModelManager::CreateModel(
	std::string name, 
	VertexData vertices, 
	unsigned int shaderId
)
{
	ShaderLoader* shaderLoader = Managers::GetInstance()->GetShaderManager();
	unsigned int vao = shaderLoader->CreateVertexArrayObject(1);
	unsigned int vbo = shaderLoader->CreateVertexArrayBuffer(
		1,
		vertices,
		ShaderLoader::BufferDrawType::STATIC_DRAW
	);

	unsigned int positonOffset = shaderLoader->GetVertexPositionOffset();
	shaderLoader->BindVertexAttributes(0, 3, false, positonOffset);

	unsigned int colorOffset = shaderLoader->GetVertexColorOffset();
	shaderLoader->BindVertexAttributes(1, 4, false, colorOffset);

	Model* model = new Model();
	model->vao = vao;
	model->vbos.push_back(vbo);
	model->shaderId = shaderId;
	model->vertices = vertices;

	ModelManager * modelManager = Managers::GetInstance()->GetModelManager();
	modelManager->AddModel(name, model);

	return model;
}

void ModelManager::AddModel(std::string name, Model* model)
{
	_modelMap.insert(std::pair<std::string, Model*>(name, model));
}

Model* ModelManager::GetModel(std::string name)
{
	if (ModelExists(name))
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

bool ModelManager::ModelExists(std::string name)
{
	return _modelMap.find(name) != _modelMap.end();
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
