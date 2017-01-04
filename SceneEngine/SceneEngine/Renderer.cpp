#include "Renderer.h"

#include "ShaderLoader.h"
#include "GraphicAPI.h"

#include "../Dependencies/glew/glew.h"
#include "../Dependencies/freeglut/freeglut.h"

#include "ModelManager.h"

#include <iostream>

Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::Awake()
{
	ShaderLoader::GetInstance()->LoadShader(
		ShaderType::VERTEX, 
		_vertexFileName.c_str(), 
		_vertexName.c_str()
	);

	ShaderLoader::GetInstance()->LoadShader(
		ShaderType::FRAGMENT, 
		_fragmentFileName.c_str(),
		_fragmentName.c_str()
	);


	_shaderId = ShaderLoader::GetInstance()->CreateProgram();

	std::vector<VertexFormat> vertices;
	vertices.push_back(VertexFormat(Vector3D(0.5f, -0.5f, 0.0f)));
	vertices.push_back(VertexFormat(Vector3D(-0.5f, -0.5f, 0.0f)));
	vertices.push_back(VertexFormat(Vector3D(0.5f, 0.5f, 0.0f)));
	LoadVerticesData("TRIANGLE_1", vertices);
}

void Renderer::Display()
{
	Model* model = ModelManager::GetInstance()->GetModel(_name);
	glBindVertexArray(model->vao);

	GLint current_vao;
	glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &current_vao);
	std::cout << "Current vao => " << current_vao << "\n";

	ShaderLoader::GetInstance()->LoadShaderById(model->shaderId);
	GraphicAPI::GetInstance()->DrawTriangles(GraphicAPI::DrawType::TRIANGLE, 0, 3);
}

void Renderer::SetVertexData(std::string name, std::string file)
{
	_vertexFileName = file;
	_vertexName = name;
}

void Renderer::SetFragmentData(std::string name, std::string file)
{
	_fragmentFileName = file;
	_fragmentName = name;
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
	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// VBO
	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * _vertices.size(), &_vertices[0], GL_STATIC_DRAW);

	// binding data
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);

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
