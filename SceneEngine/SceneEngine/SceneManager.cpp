#include "SceneManager.h"

using namespace CoreManagers;

SceneManager * SceneManager::_instance = nullptr;

void CoreManagers::SceneManager::PushSceneFront(SceneBase * scene)
{
	_insertSceneAt(scene, 0);
}

void CoreManagers::SceneManager::PushSceneEnd(SceneBase * scene)
{
	_scenes.push_back(scene);
}

void CoreManagers::SceneManager::InsertceneAt(SceneBase * scene, int idx)
{
	_insertSceneAt(scene, idx);
}

void CoreManagers::SceneManager::SetCurrenSceneIndexToNext()
{
	_setCurrentSceneIndex(_currenSceneId + 1);
}

void CoreManagers::SceneManager::SetCurrentSceneIndex(int idx)
{
	_setCurrentSceneIndex(idx);
}

SceneBase * CoreManagers::SceneManager::GetCurrentScene()
{
	return _scenes[_currenSceneId];
}

SceneManager * CoreManagers::SceneManager::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new SceneManager();
	}

	return _instance;
}

CoreManagers::SceneManager::SceneManager()
{
	_scenes = SceneVector();
	_currenSceneId = -1;
}

void CoreManagers::SceneManager::_insertSceneAt(SceneBase * scene, int idx)
{
	SceneVector::iterator it = _scenes.begin();
	_scenes.insert(it + idx, scene);
}

void CoreManagers::SceneManager::_setCurrentSceneIndex(int idx)
{
	_currenSceneId = idx;
}
