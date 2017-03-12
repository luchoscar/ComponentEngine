#include "Managers.h"
#include "GraphicOpenGL.h"
#include "LoaderGLSL.h"

using namespace CoreManagers;

Managers * Managers::_instance = nullptr;

Managers::~Managers()
{
	delete _shaderManager;
	_shaderManager = nullptr;
	
	delete _modelManager;
	_modelManager = nullptr;
	
	delete _graphicsManager;
	_graphicsManager = nullptr;
	
	delete _sceneManager;
	_sceneManager = nullptr;
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

SceneManager * CoreManagers::Managers::GetScenesManager()
{
	return _sceneManager;
}

//--- Private Functionality ---------------------------------------------------

Managers::Managers()
{
	_graphicsManager	= GraphicOpenGL::CreateInstance();
	_shaderManager		= LoaderGLSL::CreateInstance();
	_modelManager		= ModelManager::GetInstance();
	_sceneManager		= SceneManager::GetInstance();
}
