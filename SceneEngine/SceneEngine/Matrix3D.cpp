#include "Matrix3D.h"
#include <iostream>

Matrix3D::Matrix3D()
{
	_matrix = new float[SIZE];
}

Matrix3D::Matrix3D(const Matrix3D & other)
{
	_matrix = new float[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		_matrix[i] = other._matrix[i];
	}
}

Matrix3D::~Matrix3D()
{
	delete[] _matrix;
}

float & Matrix3D::operator[](int index)
{
	return _matrix[index];
}

Matrix3D & Matrix3D::operator*(Matrix3D other)
{
	Matrix3D & out = *(new Matrix3D());

	for (int row = 0; row < 4; row++)
	{
		int rowIdx = row * 4;
		for (int col = 0; col < 4; col++)
		{
			out[rowIdx + col] =
				_matrix[rowIdx + 0] * other[col] +
				_matrix[rowIdx + 1] * other[col + 4] +
				_matrix[rowIdx + 2] * other[col + 8] +
				_matrix[rowIdx + 3] * other[col + 12];
		}
	}

	return out;
}

Matrix3D & Matrix3D::operator=(Matrix3D other)
{
	_matrix = new float[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		_matrix[i] = other[i];
	}

	return *this;
}

void Matrix3D::ToString()
{
	if (_matrix == nullptr)
	{
		printf("Matrix not initialized\n");
		return;
	}

	std::string message = "";
	for (int i = 0; i < SIZE; i++)
	{
		if ((i % 4) == 0 && i > 0)
			std::cout << "\n";

		std::cout << _matrix[i] << " ";
	}

	std::cout << "\n\n";
}

Matrix3D Matrix3D::Identity()
{
	Matrix3D matrix;
	
	for (int i = 0; i < matrix.SIZE; i++)
	{
		bool setValue = (i % 5) == 0;
		matrix[i] = setValue ? 1 : 0;
	}

	return matrix;
}
