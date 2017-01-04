#ifndef _MODEL_MANAGER_H_
#define _MODEL_MANAGER_H_

#pragma once

#include <map>
#include <vector>

#include "VertexFormat.h"
#include "Model.h"

typedef std::vector<VertexFormat> VertexData;

class ModelManager
{
public:
	~ModelManager();
	
	static ModelManager *  GetInstance();

	void AddModel(std::string name, Model* model);
	Model* GetModel(std::string name);

private:
	

	ModelManager() {}
	ModelManager(const ModelManager&) {}
	
	static ModelManager * _instance;

	std::map <std::string, Model*> _modelMap;
};

#endif;