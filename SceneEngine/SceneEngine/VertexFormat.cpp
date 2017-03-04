#include "VertexFormat.h"

using namespace ModelData;

VertexFormat::VertexFormat()
{
	position = Vector3D();
	color = Vector4D();
}

VertexFormat::VertexFormat(const VertexFormat &vert)
{
	position = vert.position;
	color = vert.color;
}

VertexFormat::VertexFormat(Vector3D pos, Vector4D col)
{
	position = pos;
	color = col;
}

