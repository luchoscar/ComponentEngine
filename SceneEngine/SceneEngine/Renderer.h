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

	void SetVertices(std::vector<VertexFormat> vertices);
	void SetVertexShader(std::string fileName, std::string shaderName);
	void SetFragmentShader(std::string fileName, std::string shaderName);
	void CreateProgram();

private:
	std::vector<VertexFormat> _vertices;
	unsigned int _shaderId;
};

#endif;