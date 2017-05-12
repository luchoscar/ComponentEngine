
#pragma once

#include "ShaderLoader.h"
#include "ModelManager.h"
#include "GraphicAPI.h"
#include "SceneManager.h"
#include "GameObjectBuilder.h"

namespace CoreManagers
{
	class Managers
	{
	public:
		~Managers();

		static Managers * GetInstance();

		ShaderLoader		* GetShaderManager();
		ModelManager		* GetModelManager();
		GraphicAPI			* GetGraphicsManager();
		SceneManager		* GetScenesManager();
		GameObjectBuilder	* GetGameObjectBuilder();

	private:
		Managers();
		Managers(const Managers&) {}

		static Managers * _instance;

		// managers
		ShaderLoader		* _shaderManager = nullptr;
		ModelManager		* _modelManager = nullptr;
		GraphicAPI			* _graphicsManager = nullptr;
		SceneManager		* _sceneManager = nullptr;
		GameObjectBuilder	* _gameObjectBuilder = nullptr;
	};
}

