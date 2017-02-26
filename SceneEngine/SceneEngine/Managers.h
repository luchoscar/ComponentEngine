
#pragma once

#include "ShaderLoader.h"
#include "ModelManager.h"
#include "GraphicAPI.h"
	
namespace CoreManagers
{
	class Managers
	{
	public:
		~Managers();

		static Managers * GetInstance();

		ShaderLoader * GetShaderManager();
		ModelManager * GetModelManager();
		GraphicAPI * GetGraphicsManager();

	private:
		Managers();
		Managers(const Managers&) {}

		static Managers * _instance;

		// managers
		ShaderLoader * _shaderManager = nullptr;
		ModelManager * _modelManager = nullptr;
		GraphicAPI * _graphicsManager = nullptr;
	};
}

