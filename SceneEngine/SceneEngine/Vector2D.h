#pragma once
#include <iostream>

template <class T>
class Vector2D
{
public:
	Vector2D() {}
	Vector2D(T x, T y);
	Vector2D(const Vector2D& vect);

	void SetX(T x) { _coordinates[0] = x; }
	void SetY(T y) { _coordinates[1] = y; }

	T * GetCoordinates() { return _coordinates; }

	T GetX() const { return _coordinates[0]; }
	T GetY() const { return _coordinates[1]; }

	~Vector2D() {}

	Vector2D & operator+(const Vector2D& vect);
	Vector2D & operator-(const Vector2D& vect);
	Vector2D & operator+=(const Vector2D& vect);
	Vector2D & operator-=(const Vector2D& vect);

	void Print();

protected:
	T _coordinates[2];
};

template <class T>
Vector2D<T>::Vector2D(T x, T y)
{
	_coordinates[0] = x;
	_coordinates[1] = y;
}
template<class T>
Vector2D<T>::Vector2D(const Vector2D & vect)
{
	_coordinates[0] = vect.GetX();
	_coordinates[1] = vect.GetY();
}

template <class T>
Vector2D<T> & Vector2D<T>::operator+(const Vector2D<T> & vect)
{
	Vector2D out;
	out.SetX(this->GetX() + vect.GetX());
	out.SetY(this->GetY() + vect.GetY());

	return out;
}

template <class T>
Vector2D<T>& Vector2D<T>::operator-(const Vector2D<T> & vect)
{
	Vector2D out;
	out.SetX(this->GetX() - vect.GetX());
	out.SetY(this->GetY() - vect.GetY());

	return out;
}

template <class T>
Vector2D<T>& Vector2D<T>::operator+=(const Vector2D<T> & vect)
{
	this->_coordinates[0] += vect.GetX();
	this->_coordinates[1] += vect.GetY();

	return *this;
}

template <class T>
Vector2D<T>& Vector2D<T>::operator-=(const Vector2D<T> & vect)
{
	this->_coordinates[0] -= vect.GetX();
	this->_coordinates[1] -= vect.GetY();

	return *this;
}

template <class T>
void Vector2D<T>::Print()
{
	std::cout << "(" << GetX() << ", " << GetY() << ")\n";
}