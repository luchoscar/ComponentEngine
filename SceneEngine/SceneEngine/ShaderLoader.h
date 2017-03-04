#pragma once

#include <map>
#include <vector>

#include "GraphicAPI.h"
#include "VertexFormat.h"

using namespace ModelData;

namespace CoreManagers
{
	typedef GraphicAPI::ShaderType ShaderType;
	typedef std::vector<VertexFormat> VertexDataVector;

	class ShaderLoader
	{
	public:
		enum BufferDrawType
		{
			DYNAMIC_DRAW,
			STATIC_DRAW
		};

		virtual ~ShaderLoader();

		virtual void LoadShader(
			ShaderType type, 
			const char* fileName, 
			const char* name
		) = 0;
		virtual int CreateProgram() = 0;
		virtual unsigned int CreateVertexArrayObject(unsigned int amount) = 0;
		virtual unsigned int CreateVertexArrayBuffer(
			unsigned int amount, 
			VertexDataVector vertices,
			BufferDrawType bufferDrawType
		) = 0;
		virtual void BindVertexAttributes(
			unsigned int location, int size, bool normalized, unsigned int offset) = 0;

		virtual void BindVertexData(unsigned int vao) = 0;

		virtual void DeleteVertexArrayObject(int amount, unsigned int* vaoAddress) = 0;
		virtual void DeleteVertexBufferObject(int amount, unsigned int* vbosAddress) = 0;

		static ShaderLoader* GetInstance();

		void LoadShaderById(int id);

		unsigned int GetVertexPositionOffset();
		unsigned int GetVertexColorOffset();

		// Debug Functions
		virtual void PrintCurrentVertexArrayObject() = 0;

	protected:
		ShaderLoader() {}
		ShaderLoader(ShaderLoader&) {}

		virtual void _loadShaderById(int id) = 0;

		static ShaderLoader* instance;

		unsigned int currentId = 0;
	};
}
