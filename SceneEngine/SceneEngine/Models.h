#ifndef _MODELS_H_
#define _MODELS_H_

#pragma once

#include <map>
#include <vector>

#include "VertexFormat.h"

struct Model
{
	unsigned int vao;
	std::vector<unsigned int> vbos;

	Model() {}
};

class Models
{
public:
	Models();
	~Models();
	
	void CreateTriangleModel(const std::string& modelName);
	void DeleteModel(const std::string& modelName);
	unsigned int GetModel(const std::string& modelName);

private:
	std::vector<VertexFormat> _loadVertices();
	unsigned int _setVertexArrayObject();
	unsigned int _setVertexBufferObject(std::vector<VertexFormat> vertices);
	void _bindAttributes();
	void _createModel(std::string name, unsigned int vao, unsigned int vbo);

	std::map<std::string, Model> _gameModelList;
};

#endif;