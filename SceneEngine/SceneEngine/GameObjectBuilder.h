#pragma once

#include "GameObject.h"

namespace CoreManagers
{
	class GameObjectBuilder
	{
	public:

		~GameObjectBuilder();

		static GameObjectBuilder * GetInstance();

		void LoadGameObject(std::string name);
		GameObject * GetGameObject();
		void UnloadGameObject();

		void AddCamera();
		void AddRenderer(
			std::vector<VertexFormat> vertexData,
			std::string vertexShaderName,
			std::string vertexShaderFile,
			std::string fragmentShaderName,
			std::string fragmentShaderFile
		);

		template<typename T>
		void AddGenericComponent(T * component);

	private:
		GameObjectBuilder() { _gameObject = nullptr; }
		GameObjectBuilder(const GameObjectBuilder &) {}

		static GameObjectBuilder * _instance;
		GameObject * _gameObject;

		bool _dirty = false;
	};

	template<typename T>
	inline void GameObjectBuilder::AddGenericComponent(T * component)
	{
		_gameObject->AddComponent(component);
	}
}