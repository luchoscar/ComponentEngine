#include "Renderer.h"

#include "Managers.h"

#include <iostream>

using namespace CoreManagers;

Renderer::Renderer()
{ }


Renderer::~Renderer()
{ }

void Renderer::Display()
{
	ModelManager * modelManager = Managers::GetInstance()->GetModelManager();
	Model* model = modelManager->GetModel(_name);

	ShaderLoader* shaderLoader = Managers::GetInstance()->GetShaderManager();
	shaderLoader->BindVertexData(model->vao);
	shaderLoader->LoadShaderById(model->shaderId);

	shaderLoader->PrintCurrentVertexArrayObject();

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

	ShaderLoader* shaderLoader = Managers::GetInstance()->GetShaderManager();
	unsigned int vao = shaderLoader->CreateVertexArrayObject(1);
	unsigned int vbo = shaderLoader->CreateVertexArrayBuffer(
		1, 
		_vertices,
		ShaderLoader::BufferDrawType::STATIC_DRAW
	);
	
	unsigned int positonOffset = shaderLoader->GetVertexPositionOffset();
	shaderLoader->BindVertexAttributes(0, 3, false, positonOffset);

	unsigned int colorOffset = shaderLoader->GetVertexColorOffset();
	shaderLoader->BindVertexAttributes(1, 4, false, colorOffset);

	Model* model = new Model();
	model->vao = vao;
	model->vbos.push_back(vbo);
	model->shaderId = _shaderId;
	model->vertices = _vertices;

	ModelManager * modelManager = Managers::GetInstance()->GetModelManager();
	modelManager->AddModel(_name, model);
}

void Renderer::_setVertices(std::vector<VertexFormat> vertices)
{
	_vertices = vertices;
}
