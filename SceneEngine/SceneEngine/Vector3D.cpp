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


Vector3D::~Vector3D()
{
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

void Vector3D::Print()
{
	std::cout << "(" << GetX() << ", " << GetY() << ", " << GetZ() << ")\n";
}

