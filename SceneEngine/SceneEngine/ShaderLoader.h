#pragma once

#include <map>
#include <vector>
#include <list>

#include "GraphicAPI.h"
#include "VertexFormat.h"
#include "ShaderInfo.h"

using namespace ModelData;

namespace CoreManagers
{
	typedef GraphicAPI::ShaderType ShaderType;
	typedef std::vector<VertexFormat> VertexDataVector;
	typedef std::list<std::string> ShaderNames;

	typedef std::map<int, ShaderInfo> ProgramMap;
	typedef std::map<std::string, unsigned int> ShaderMap;
	typedef std::map<std::string, unsigned int> ProgramNameMap;

	class ShaderLoader
	{
	public:
		enum BufferDrawType
		{
			DYNAMIC_DRAW,
			STATIC_DRAW
		};

		virtual ~ShaderLoader();

		virtual char* GetVersion() = 0;
		virtual void LoadShader(
			ShaderType type, 
			const char* fileName, 
			const char* name
		) = 0;
		virtual int CreateOrGetProgram() = 0;
		virtual int SetPropertyId(unsigned int shaderId, std::string uniformName) = 0;
		
		virtual unsigned int CreateVertexArrayObject(unsigned int amount) = 0;
		virtual unsigned int CreateVertexArrayBuffer(
			unsigned int amount, 
			VertexDataVector vertices,
			BufferDrawType bufferDrawType
		) = 0;
		virtual void BindVertexAttributes(
			unsigned int location, 
			int size, 
			bool normalized, 
			unsigned int offset
		) = 0;

		virtual void BindVertexData(unsigned int vao) = 0;

		virtual void DeleteVertexArrayObject(int amount, unsigned int* vaoAddress) = 0;
		virtual void DeleteVertexBufferObject(int amount, unsigned int* vbosAddress) = 0;

		static ShaderLoader* GetInstance();

		void LoadShaderById(int id);

		unsigned int GetVertexPositionOffset();
		unsigned int GetVertexColorOffset();

		virtual void BindUniformMatrix(int shaderId, std::string name, Matrix3D matrix) = 0;

		// Debug Functions
		virtual void PrintCurrentVertexArrayObject() = 0;

	protected:
		ShaderLoader() {}
		ShaderLoader(ShaderLoader&) {}

		virtual void _loadShaderById(int id) = 0;

		std::string _getCurrentName();
		bool _shaderExists(const char * name);
		bool _programExists(const char * name);

		static ShaderLoader* instance;

		ShaderNames _shaderNames;
		const char* currentName;
		unsigned int currentId = 0;

		ProgramMap _programMap;
		ShaderMap _shaderMap;
		ProgramNameMap _programNameMap;
	};
}
