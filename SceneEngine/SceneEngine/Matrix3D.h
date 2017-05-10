#pragma once

class Matrix3D
{
public:
	Matrix3D();
	Matrix3D(const Matrix3D& other);
	~Matrix3D();

	float& operator [] (int index);
	float * getData() { return _matrix; }
	Matrix3D& operator * (Matrix3D other);
	Matrix3D& operator = (Matrix3D other);

	const int GetSize();

	void ToString();

private:
	const int SIZE = 16;
	float* _matrix;
};

