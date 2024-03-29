#ifndef _MODEL_MANAGER_H_
#define _MODEL_MANAGER_H_

#pragma once

#include <map>
#include <vector>
#include <string>

#include "VertexFormat.h"
#include "Model.h"

using namespace ModelData;

namespace CoreManagers
{
	typedef std::vector<VertexFormat> VertexData;

	class ModelManager
	{
	public:
		~ModelManager();

		static ModelManager *  GetInstance();

		Model * CreateModel(
			std::string name, 
			VertexData vertices,
			unsigned int shaderId
		);
		void AddModel(std::string name, Model* model);
		Model* GetModel(std::string name);

		void DeleteModel(std::string name);
		bool ModelExists(std::string name);

	private:
		void _deleteModel(Model* model);

		ModelManager() {}
		ModelManager(const ModelManager&) {}

		static ModelManager * _instance;

		std::map <std::string, Model*> _modelMap;
	};
}
#endif;
