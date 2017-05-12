#pragma once

#include "GameObject.h"

class GameObjectBuilder
{
public:
	
	~GameObjectBuilder();

	static GameObjectBuilder * GetInstance();

	void LoadGameObject(std::string name);
	GameObject * GetGameObject();
	void UnloadGameObject();

	void AddRenderer(
		std::vector<VertexFormat> vertexData,
		std::string vertexShaderName,
		std::string vertexShaderFile,
		std::string fragmentShaderName,
		std::string fragmentShaderFile
	);

	template<typename T>
	void AddBehaviorComponent(T * component);

private:
	GameObjectBuilder() { _gameObject = nullptr; }
	GameObjectBuilder(const GameObjectBuilder &) {}

	static GameObjectBuilder * _instance;
	GameObject * _gameObject;

	bool _dirty = false;
};

template<typename T>
inline void GameObjectBuilder::AddBehaviorComponent(T * component)
{
	if (!std::is_base_of<BehaviorComponent, T>::value)
		throw std::invalid_argument(
			"Class object cannot be added as a behavior component"
		);

	_gameObject->AddComponent(component);
}
