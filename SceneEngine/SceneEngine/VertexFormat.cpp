#include "VertexFormat.h"

VertexFormat::VertexFormat()
{
	_position = Vector3D();
}

VertexFormat::VertexFormat(const VertexFormat &vert)
{
	_position = vert.GetPosition();
}

VertexFormat::VertexFormat(Vector3D pos)
{
	_position = pos;
}

void VertexFormat::SetPosition(Vector3D vectPos)
{
	_position = vectPos;
}

Vector3D VertexFormat::GetPosition() const
{
	return _position;
}

