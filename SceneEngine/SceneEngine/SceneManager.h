#pragma once

#include "SceneBase.h"
#include <vector>

namespace CoreManagers
{
	typedef std::vector<SceneBase*> SceneVector;

	class SceneManager
	{
	public:
		~SceneManager() {}

		void PushSceneFront(SceneBase * scene);
		void PushSceneEnd(SceneBase * scene);
		void InsertceneAt(SceneBase * scene, int idx);

		void SetCurrenSceneIndexToNext();
		void SetCurrentSceneIndex(int idx);

		SceneBase * GetCurrentScene();

		static SceneManager * GetInstance();

	private:
		SceneManager();
		SceneManager(const SceneManager&) {}

		static SceneManager * _instance;

		void _insertSceneAt(SceneBase * scene, int idx);
		void _setCurrentSceneIndex(int idx);

		SceneVector _scenes;
		int _currenSceneId = 0;
	};
}
