#include "SceneBase.h"

SceneBase::SceneBase()
{
	_objectsList.push_back(new GameObject());
}

SceneBase::~SceneBase()
{
	for (unsigned int i = 0; i < _objectsList.size(); i++)
	{
		delete _objectsList[i];
	}

	_objectsList.clear();
}

void SceneBase::Draw()
{
	for (ObjectsList::iterator it = _objectsList.begin(); it != _objectsList.end(); it++)
	{
		(*it)->Display();
	}
}
