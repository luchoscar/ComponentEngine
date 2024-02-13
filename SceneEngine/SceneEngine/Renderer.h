#ifndef _RENDERER_H_
#define _RENDERER_H_

#pragma once

#include <vector>
#include <map>
#include <string>

#include "Component.h"
#include "VertexFormat.h"
#include "Matrix3D.h"

using namespace ModelData;

typedef std::vector<VertexFormat> VertexDataVect;

class Renderer final :
	public Component
{
public:
	Renderer();
	virtual ~Renderer() {}

	void Display(Matrix3D mvpMatrix);

	void SetVertexData(std::string name, std::string file);
	void SetFragmentData(std::string name, std::string file);
	void SetShaderProgram();

	std::vector<VertexFormat> GetVerticesData();
	void CreateVerticesData(std::string name, VertexDataVect vertices);

private:
	void _setVertices(std::vector<VertexFormat> vertices);

	std::vector<VertexFormat> _vertices;
	unsigned int _shaderId;
	unsigned int _vbo;	// vertex buffer object
	unsigned int _vao;	// vertex array object

	std::string _vertexName;
	std::string _vertexFileName;
	std::string _fragmentName;
	std::string _fragmentFileName;

	std::string _name;
};

#endif;