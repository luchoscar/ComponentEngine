#include "Renderer.h"

#include "ShaderLoader.h"
#include "GraphicAPI.h"

#include "ModelManager.h"

#include <iostream>

Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::Display()
{
	Model* model = ModelManager::GetInstance()->GetModel(_name);
	ShaderLoader::GetInstance()->BindVertexData(model->vao);

	ShaderLoader::GetInstance()->PrintCurrentVertexArrayObject();

	ShaderLoader::GetInstance()->LoadShaderById(model->shaderId);
	GraphicAPI::GetInstance()->DrawTriangles(GraphicAPI::DrawType::TRIANGLE, 0, 3);
}

void Renderer::SetVertexData(std::string name, std::string file)
{
	_vertexFileName = file;
	_vertexName = name;

	ShaderLoader::GetInstance()->LoadShader(
		ShaderType::VERTEX,
		_vertexFileName.c_str(),
		_vertexName.c_str()
	);
}

void Renderer::SetFragmentData(std::string name, std::string file)
{
	_fragmentFileName = file;
	_fragmentName = name;

	ShaderLoader::GetInstance()->LoadShader(
		ShaderType::FRAGMENT,
		_fragmentFileName.c_str(),
		_fragmentName.c_str()
	);
}

void Renderer::CreateShaderProgram()
{
	_shaderId = ShaderLoader::GetInstance()->CreateProgram();
}

std::vector<VertexFormat> Renderer::GetVerticesData()
{
	return _vertices;
}

void Renderer::LoadVerticesData(std::string name, std::vector<VertexFormat> vertices)
{
	_vertices = vertices;
	_name = name;

	// VAO
	unsigned int vao = ShaderLoader::GetInstance()->CreateVertexArrayObject(1);

	// VBO
	unsigned int vbo = ShaderLoader::GetInstance()->CreateVertexArrayBuffer(
		1, 
		_vertices,
		ShaderLoader::BufferDrawType::STATIC_DRAW
	);

	// binding data
	ShaderLoader::GetInstance()->BindVertexAttributes(0, 3);

	Model* model = new Model();
	model->vao = vao;
	model->vbos.push_back(vbo);
	model->shaderId = _shaderId;
	model->vertices = _vertices;
	ModelManager::GetInstance()->AddModel(_name, model);
}

void Renderer::_setVertices(std::vector<VertexFormat> vertices)
{
	_vertices = vertices;
}
