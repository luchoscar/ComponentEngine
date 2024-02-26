#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <type_traits>

template <class T>
concept TStreamNumber =
requires(T value)
{
	{ value + value };
	{ value += value };
	{ value - value };
	{ value -= value };
} && requires(std::ostream& os, T value) {
	{ os << value } -> std::convertible_to<std::ostream&>;
};

template<TStreamNumber TValue>
class BaseVector
{
public:
	std::shared_ptr<TValue[]> GetCoordinates() { return this->_coordinates; }

	template<class TVector, TStreamNumber TValue> requires std::is_base_of<BaseVector<TValue>, TVector>::value
	TVector& operator+(const TVector& vect) {
		TVector *out = new TVector();
		for (int idx = 0; idx < this->SIZE; idx++) {
			out->_coordinates[idx] = this->_coordinates[idx] + vect._coordinates[idx];
		}

		return *out;
	}
	
	template<class TVector, TStreamNumber TValue> requires std::is_base_of<BaseVector<TValue>, TVector>::value
	TVector& operator-(const TVector& vect) {
		TVector *out = new TVector();
		for (int idx = 0; idx < this->SIZE; idx++) {
			out->_coordinates[idx] = this->_coordinates[idx] - vect._coordinates[idx];
		}

		return *out;
	}

	template<class TVector, TStreamNumber TValue> requires std::is_base_of<BaseVector<TValue>, TVector>::value
	TVector& operator+=(const TVector& vect) {
		for (int idx = 0; idx < this->SIZE; idx++) {
			this->_coordinates[idx] += vect._coordinates[idx];
		}

		return *dynamic_cast<TVector*>(this);
	}

	template<class TVector, TStreamNumber TValue> requires std::is_base_of<BaseVector<TValue>, TVector>::value
	TVector& operator-=(const TVector& vect) {
		for (int idx = 0; idx < this->SIZE; idx++) {
			this->_coordinates[idx] -= vect._coordinates[idx];
		}

		return *dynamic_cast<TVector*>(this);
	}

	template<class TVector, TStreamNumber TValue> requires std::is_base_of<BaseVector<TValue>, TVector>::value
	TVector& operator=(const TVector& vect) {
		this->_coordinates.clear();
		for (int idx = 0; idx < this->SIZE; idx++) {
			this->_coordinates.push_back(vect._coordinates[idx]);
		}

		return *dynamic_cast<TVector*>(this);
	}

	template<class TVector, TStreamNumber TValue> requires std::is_base_of<BaseVector<TValue>, TVector>::value
	TValue operator[](const int& index) const {
		return this->_coordinates[index];
	}

	template<class TVector, TStreamNumber TValue> requires std::is_base_of<BaseVector<TValue>, TVector>::value
	TValue& operator[](const int& index) {
		return this->_coordinates[index];
	}

	void Print()
	{
		std::cout << "(" << this->_coordinates[0];
		for (int idx = 1; idx < this->SIZE; idx++) {
			std::cout << ", " << this->_coordinates[idx];
		}
		std::cout << ")" << std::endl;
	}

protected:
	const int SIZE;
	std::vector<TValue> _coordinates;

	BaseVector<TValue>(int size) : SIZE(size) {
		_coordinates.clear();
	}

	BaseVector<TValue>(const BaseVector& vect) : SIZE(vect.SIZE) {
		_coordinates.clear();
		for (int idx = 0; idx < SIZE; idx++) {
			_coordinates.push_back(vect._coordinates[idx]);
		}
	}

	virtual ~BaseVector() {}

private:
	BaseVector<TValue>() : SIZE(0) {}

};
