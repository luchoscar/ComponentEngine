#pragma once
class Vector4D
{
public:
	Vector4D();
	Vector4D(float x, float y, float z, float w);
	Vector4D(const Vector4D& vect);

	void SetX(float x) { _coordinates[0] = x; }
	void SetY(float y) { _coordinates[1] = y; }
	void SetZ(float z) { _coordinates[2] = z; }
	void SetW(float w) { _coordinates[3] = w; }

	float * GetCoordinates() { return _coordinates; }

	float GetX() const { return _coordinates[0]; }
	float GetY() const { return _coordinates[1]; }
	float GetZ() const { return _coordinates[2]; }
	float GetW() const { return _coordinates[3]; }

	~Vector4D();

	Vector4D operator+(const Vector4D& vect);
	Vector4D operator-(const Vector4D& vect);
	Vector4D operator+=(const Vector4D& vect);
	Vector4D operator-=(const Vector4D& vect);

	void Print();

protected:
	float _coordinates[4];
};

