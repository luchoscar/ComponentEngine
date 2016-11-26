#ifndef _RENDERER_H_
#define _RENDERER_H_

#pragma once

#include <vector>

#include "Component.h"
#include "VertexFormat.h"

class Renderer :
	public Component
{
public:
	Renderer();
	~Renderer();

	void Awake() override;
	void Display() override;

	void SetVertexData(std::string name, std::string file);
	void SetFragmentData(std::string name, std::string file);

private:
	void _setVertices(std::vector<VertexFormat> vertices);

	std::vector<VertexFormat> _vertices;
	unsigned int _shaderId;

	std::string _vertexName;
	std::string _vertexFileName;
	std::string _fragmentName;
	std::string _fragmentFileName;
};

#endif;