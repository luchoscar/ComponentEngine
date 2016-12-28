#pragma once

class Vector3D
{
public:
	Vector3D();
	Vector3D(float x, float y, float z);
	Vector3D(const Vector3D& vect);

	void SetX(float x) { _coordinates[0] = x; }
	void SetY(float y) { _coordinates[1] = y; }
	void SetZ(float z) { _coordinates[2] = z; }

	float * GetCoordinates() { return _coordinates; }

	float GetX() const { return _coordinates[0]; }
	float GetY() const { return _coordinates[1]; }
	float GetZ() const { return _coordinates[2]; }

	~Vector3D();

	Vector3D operator+(const Vector3D& vect);
	Vector3D operator-(const Vector3D& vect);
	Vector3D operator+=(const Vector3D& vect);
	Vector3D operator-=(const Vector3D& vect);

	void Print();

protected:
	float _coordinates[3];
};

