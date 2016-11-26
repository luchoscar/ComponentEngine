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

void Renderer::SetVertices(std::vector<VertexFormat> vertices)
{
	_vertices = vertices;
}

void Renderer::SetVertexShader(std::string fileName, std::string shaderName)
{
	ShaderLoader::GetInstance()->LoadShader(ShaderType::VERTEX, "vertexShader.glsl", "vertShad");
}

void Renderer::SetFragmentShader(std::string fileName, std::string shaderName)
{
	ShaderLoader::GetInstance()->LoadShader(ShaderType::FRAGMENT, "fragmentShader.glsl", "fragShad");
}

void Renderer::CreateProgram()
{
	_shaderId = ShaderLoader::GetInstance()->CreateProgram();
}
