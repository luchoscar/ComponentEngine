#pragma once

#include "Vector3D.h"
#include "Vector4D.h"

namespace ModelData
{
	struct VertexFormat
	{
	public:
		Vector3D position;
		Vector4D color;

		VertexFormat();
		VertexFormat(const VertexFormat &vert);

		VertexFormat(Vector3D pos, Vector4D col);
	};
}
