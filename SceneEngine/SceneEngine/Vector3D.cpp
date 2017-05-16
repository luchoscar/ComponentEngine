#include "Vector3D.h"

#include <iostream> 

Vector3D::Vector3D()
{
	_coordinates[0] = 0.0f;
	_coordinates[1] = 0.0f;
	_coordinates[2] = 0.0f;
}

Vector3D::Vector3D(float x, float y, float z)
{
	_coordinates[0] = x;
	_coordinates[1] = y;
	_coordinates[2] = z;
}

Vector3D::Vector3D(const Vector3D & vect)
{
	_coordinates[0] = vect.GetX();
	_coordinates[1] = vect.GetY();
	_coordinates[2] = vect.GetZ();
}


float Vector3D::GetMagnitud()
{
	return sqrt(
		GetX() * GetX() +
		GetY() * GetY() + 
		GetZ() * GetZ()
	);
}

Vector3D Vector3D::GetNormalized()
{
	float magnitude = GetMagnitud();
	return Vector3D(
		GetX() / magnitude,
		GetY() / magnitude,
		GetZ() / magnitude
	);
}

Vector3D::~Vector3D()
{
}

Vector3D Vector3D::operator*(const int & value)
{
	return _multiplyBy(value);
}

Vector3D Vector3D::operator*(const float & value)
{
	return _multiplyBy(value);
}

Vector3D Vector3D::operator+(const Vector3D & vect)
{
	Vector3D out;
	out.SetX(this->GetX() + vect.GetX());
	out.SetY(this->GetY() + vect.GetY());
	out.SetZ(this->GetZ() + vect.GetZ());

	return out;
}

Vector3D  Vector3D::operator-(const Vector3D & vect)
{
	Vector3D out;
	out.SetX(this->GetX() - vect.GetX());
	out.SetY(this->GetY() - vect.GetY());
	out.SetZ(this->GetZ() - vect.GetZ());

	return out;
}

Vector3D Vector3D::operator+=(const Vector3D & vect)
{
	this->_coordinates[0] += vect.GetX();
	this->_coordinates[1] += vect.GetY();
	this->_coordinates[2] += vect.GetZ();

	return *this;
}

Vector3D Vector3D::operator-=(const Vector3D & vect)
{
	this->_coordinates[0] -= vect.GetX();
	this->_coordinates[1] -= vect.GetY();
	this->_coordinates[2] -= vect.GetZ();

	return *this;
}

float Vector3D::DotProduct(Vector3D vect1, Vector3D vect2)
{
	return vect1.GetX() * vect2.GetX() +
		vect1.GetY() * vect2.GetY() +
		vect1.GetZ() * vect2.GetZ();
}

Vector3D Vector3D::CrossProduct(Vector3D vect1, Vector3D vect2)
{
	float xComp = vect1.GetY() * vect2.GetZ() -
		vect1.GetZ() * vect2.GetY();

	float yComp = vect1.GetZ() * vect2.GetX() -
		vect1.GetX() * vect2.GetZ();

	float zComp = vect1.GetX() * vect2.GetY() -
		vect1.GetY() * vect2.GetX();

	return Vector3D(xComp, yComp, zComp);
}

void Vector3D::Print()
{
	printf("Vector3D (%f, %f, %f)\n",
		GetX(),
		GetY(),
		GetZ()
	);
}

