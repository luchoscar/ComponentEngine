#include "Models.h"

#include "../Dependencies/glew/glew.h"

Models::Models()
{
}


Models::~Models()
{
	for (std::map<std::string, Model>::iterator it = _gameModelList.begin(); it != _gameModelList.end(); it++) {
		unsigned int * vao = &it->second.vao;
		glDeleteVertexArrays(1, vao);
		glDeleteBuffers(it->second.vbos.size(), &it->second.vbos[0]);
	}

	_gameModelList.clear();
}

void Models::CreateTriangleModel(const std::string & modelName)
{
	std::vector<VertexFormat> vertices = _loadVertices();

	unsigned int vao = _setVertexArrayObject();
	unsigned int vbo = _setVertexBufferObject(vertices);

	_createModel(modelName, vao, vbo);
}

void Models::DeleteModel(const std::string & modelName)
{
	Model model = _gameModelList[modelName];
	unsigned int vao = model.vao;

	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(model.vbos.size(), &model.vbos[0]);
	model.vbos.clear();

	_gameModelList.erase(modelName);
}

unsigned int Models::GetModel(const std::string & modelName)
{
	return _gameModelList[modelName].vao;
}

//--- Private Implementation --------------------------------------------------

std::vector<VertexFormat> Models::_loadVertices()
{
	std::vector<VertexFormat> vertices;
	vertices.push_back(VertexFormat(Vector3D(-0.5, -0.5, 0.0)));
	vertices.push_back(VertexFormat(Vector3D(0.0, 0.5, 0.0)));
	vertices.push_back(VertexFormat(Vector3D(0.5, -0.5, 0.0)));

	return vertices;
}

unsigned int Models::_setVertexArrayObject()
{
	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	return vao;
}

unsigned int Models::_setVertexBufferObject(std::vector<VertexFormat> vertices)
{
	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER,
		sizeof(VertexFormat) * vertices.size(),
		&vertices[0],
		GL_STATIC_DRAW
	);

	return vbo;
}

void Models::_bindAttributes()
{
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
}

void Models::_createModel(std::string name, unsigned int vao, unsigned int vbo)
{
	Model model;
	model.vao = vao;
	model.vbos.push_back(vbo);

	if (_gameModelList.find(name) != _gameModelList.end()) {
		std::string msg = "Model " + name + " already exists";
		throw std::invalid_argument(msg.c_str());
	}

	_gameModelList[name] = model;
}
