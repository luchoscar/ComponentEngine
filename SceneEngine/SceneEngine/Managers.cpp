#include "Managers.h"
#include "GraphicOpenGL.h"
#include "LoaderGLSL.h"

using namespace CoreManagers;

Managers * Managers::_instance = nullptr;

Managers::~Managers()
{
	delete _shaderManager;
	delete _modelManager;
	delete _graphicsManager;
}

Managers * Managers::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Managers();
	}

	return _instance;
}

ShaderLoader * Managers::GetShaderManager()
{
	return _shaderManager;
}

ModelManager * Managers::GetModelManager()
{
	return _modelManager;
}

GraphicAPI * Managers::GetGraphicsManager()
{
	return _graphicsManager;
}

//--- Private Functionality ---------------------------------------------------

Managers::Managers()
{
	_graphicsManager = GraphicOpenGL::CreateInstance();
	_shaderManager = LoaderGLSL::CreateInstance();
	_modelManager = ModelManager::GetInstance();
}
