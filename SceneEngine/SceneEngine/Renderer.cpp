#include "Renderer.h"

#include "ShaderLoader.h"
#include "GraphicAPI.h"

typedef ShaderLoader::Type ShaderType;

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
}

void Renderer::Display()
{
	ShaderLoader::GetInstance()->LoadShaderById(_shaderId);
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

void Renderer::_setVertices(std::vector<VertexFormat> vertices)
{
	_vertices = vertices;
}
