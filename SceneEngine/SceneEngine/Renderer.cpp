#include "Renderer.h"

#include "Managers.h"

#include <iostream>

using namespace CoreManagers;

typedef GraphicAPI::DrawType DrawType;

Renderer::Renderer() : Component()
{ }

void Renderer::Display()
{
	ModelManager * modelManager = Managers::GetInstance()->GetModelManager();
	Model* model = modelManager->GetModel(_name);

	ShaderLoader* shaderLoader = Managers::GetInstance()->GetShaderManager();
	shaderLoader->BindVertexData(model->vao);
	shaderLoader->LoadShaderById(model->shaderId);

	shaderLoader->PrintCurrentVertexArrayObject();

	GraphicAPI::GetInstance()->DrawTriangles(DrawType::TRIANGLE, 0, 3);
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

void Renderer::SetShaderProgram()
{
	_shaderId = ShaderLoader::GetInstance()->CreateOrGetProgram();
}

std::vector<VertexFormat> Renderer::GetVerticesData()
{
	return _vertices;
}

void Renderer::CreateVerticesData(std::string name, VertexDataVect vertices)
{
	ModelManager * modelManager = Managers::GetInstance()->GetModelManager();

	if (modelManager->ModelExists(name))
	{
		Model * model = modelManager->GetModel(name);
		_name = name;
		_vertices = model->vertices;
		_shaderId = model->shaderId;
	}
	else
	{
		_vertices = vertices;
		_name = name;

		modelManager->CreateModel(name, vertices, _shaderId);
	}
}

void Renderer::_setVertices(std::vector<VertexFormat> vertices)
{
	_vertices = vertices;
}
