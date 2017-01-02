#ifndef _MODEL_MANAGER_H_
#define _MODEL_MANAGER_H_

#pragma once

#include <map>
#include <vector>

#include "VertexFormat.h"

typedef std::vector<VertexFormat> VertexData;

struct Model {
	VertexData vertices;
	unsigned int vao;
	std::vector<unsigned int> vbos;
	unsigned int shaderId;

	Model() {}
};

class ModelManager
{
public:
	~ModelManager();
	
	static ModelManager *  GetInstance();

	void AddModel(std::string name, Model model);
	Model GetModel(std::string name);

private:
	

	ModelManager() {}
	ModelManager(const ModelManager&) {}
	
	static ModelManager * _instance;

	std::map <std::string, Model> _modelMap;
};

#endif;