#ifndef _MODEL_MANAGER_H_
#define _MODEL_MANAGER_H_

#pragma once

#include <map>
#include <vector>

#include "VertexFormat.h"

typedef std::vector<VertexFormat> VertexData;

class ModelManager
{
public:
	~ModelManager();
	
	static ModelManager *  GetInstance();

private:
	struct Model {
		VertexData vertices;
		unsigned int vao;
		std::vector<unsigned int> vbos;
		unsigned int shaderId;

		Model() {}
	};

	ModelManager() {}
	ModelManager(const ModelManager&) {}
	
	static ModelManager * _instance;
};

#endif;