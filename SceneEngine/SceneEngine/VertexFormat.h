#pragma once

#include "Vector3D.h"

struct VertexFormat
{
public:
	VertexFormat();
	VertexFormat(const VertexFormat &vert);

	VertexFormat(Vector3D pos);

	void SetPosition(Vector3D vectPos);
	Vector3D GetPosition() const;

private:
	Vector3D _position;
};
