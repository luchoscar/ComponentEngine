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

	float GetMagnitud();
	Vector3D GetNormalized();

	~Vector3D();

	Vector3D & operator*(const int& value);
	Vector3D & operator*(const float& value);

	Vector3D & operator+(const Vector3D& vect);
	Vector3D & operator-(const Vector3D& vect);
	Vector3D & operator+=(const Vector3D& vect);
	Vector3D & operator-=(const Vector3D& vect);

	static float DotProduct(Vector3D vect1, Vector3D vect2);
	static Vector3D & CrossProduct(Vector3D vect1, Vector3D vect2);

	void Print();

protected:
	float _coordinates[3];

	template<typename T>
	Vector3D & _multiplyBy(T value);
};

template<typename T>
inline Vector3D & Vector3D::_multiplyBy(T value)
{
	Vector3D out;
	out.SetX(this->GetX() * value);
	out.SetY(this->GetY() * value);
	out.SetZ(this->GetZ() * value);

	return out;
}
