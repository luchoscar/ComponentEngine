#include "ModelManager.h"

#include "../Dependencies/glew/glew.h"

#include <iostream>

ModelManager * ModelManager::_instance = nullptr;

ModelManager * ModelManager::GetInstance()
{
	if (_instance == nullptr) {
		_instance = new ModelManager();
	}

	return _instance;
}
