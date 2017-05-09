#include "Vector4D.h"

#include <iostream> 

Vector4D::Vector4D()
{
	_coordinates[0] = 0.0f;
	_coordinates[1] = 0.0f;
	_coordinates[2] = 0.0f;
	_coordinates[3] = 0.0f;
}

Vector4D::Vector4D(float x, float y, float z, float w)
{
	_coordinates[0] = x;
	_coordinates[1] = y;
	_coordinates[2] = z;
	_coordinates[3] = w;
}

Vector4D::Vector4D(const Vector4D & vect)
{
	_coordinates[0] = vect.GetX();
	_coordinates[1] = vect.GetY();
	_coordinates[2] = vect.GetZ();
	_coordinates[3] = vect.GetW();
}


Vector4D::~Vector4D()
{
}

Vector4D Vector4D::operator+(const Vector4D & vect)
{
	Vector4D out;
	out.SetX(this->GetX() + vect.GetX());
	out.SetY(this->GetY() + vect.GetY());
	out.SetZ(this->GetZ() + vect.GetZ());
	out.SetW(this->GetW() + vect.GetW());

	return out;
}

Vector4D  Vector4D::operator-(const Vector4D & vect)
{
	Vector4D out;
	out.SetX(this->GetX() - vect.GetX());
	out.SetY(this->GetY() - vect.GetY());
	out.SetZ(this->GetZ() - vect.GetZ());
	out.SetW(this->GetW() - vect.GetW());

	return out;
}

Vector4D Vector4D::operator+=(const Vector4D & vect)
{
	this->_coordinates[0] += vect.GetX();
	this->_coordinates[1] += vect.GetY();
	this->_coordinates[2] += vect.GetZ();
	this->_coordinates[3] += vect.GetW();

	return *this;
}

Vector4D Vector4D::operator-=(const Vector4D & vect)
{
	this->_coordinates[0] -= vect.GetX();
	this->_coordinates[1] -= vect.GetY();
	this->_coordinates[2] -= vect.GetZ();
	this->_coordinates[3] -= vect.GetW();

	return *this;
}

void Vector4D::Print()
{
	printf("(%f, %f, %f, %f)\n", 
		GetX(),  
		GetY(), 
		GetZ(), 
		GetW()
	);
}

