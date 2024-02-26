#pragma once
#include "BaseVector.h"

template <TStreamNumber TValue>
class Vector2DNew : public BaseVector<TValue>
{
public:
	Vector2DNew() : BaseVector<TValue>(2) {
		this->_coordinates.push_back(TValue());
		this->_coordinates.push_back(TValue());
	}

	Vector2DNew(TValue x, TValue y) : BaseVector<TValue>(2) { 
		this->_coordinates.push_back(x);
		this->_coordinates.push_back(y);
	}

	Vector2DNew(const Vector2DNew& other) : BaseVector<TValue>(other) {
	}
	
	Vector2DNew& operator+(const Vector2DNew& vect) {
		return BaseVector<TValue>::template operator+<Vector2DNew, TValue>(vect);
	}

	Vector2DNew& operator-(const Vector2DNew& vect) {
		return BaseVector<TValue>::template operator-<Vector2DNew, TValue>(vect);
	}

	Vector2DNew& operator+=(const Vector2DNew& vect) {
		return BaseVector<TValue>::template operator+=<Vector2DNew, TValue>(vect);
	}

	Vector2DNew& operator-=(const Vector2DNew& vect) {
		return BaseVector<TValue>::template operator-=<Vector2DNew, TValue>(vect);
	}

	Vector2DNew& operator=(const Vector2DNew& vect) {
		return BaseVector<TValue>::template operator=<Vector2DNew, TValue>(vect);
	}

	TValue operator[](const int& index) const {
		return BaseVector<TValue>::template operator[]<Vector2DNew, TValue>(index);
	}

	TValue& operator[](const int& index) {
		return BaseVector<TValue>::template operator[]<Vector2DNew, TValue>(index);
	}

private:
	Vector2DNew(int size) : BaseVector<TValue>(size) {
	}
};

