#pragma once

#include <vector>

#include "VertexFormat.h"

class Model
{
public:
	std::vector<VertexFormat> vertices;

	unsigned int vao;
	std::vector<unsigned int> vbos;
	
	unsigned int shaderId;

	Model() {}
	~Model() {}
};

