#include "uvector.h"

uvector::Vector::Vector()
{
	size = 0;
	vec = new int[1];
	vec[1] = 0;
}

uvector::Vector::Vector(const Vector &_vector)
{
	size = _vector.size;
	vec = new int[size];
	for (int i = 0; i < size; ++i) {
		vec[i] = _vector.vec[i];
	}
}

uvector::Vector::Vector(const unsigned &_size)
{
	size = _size;
	vec = new int[_size];
	for (int i = 0; i < size; ++i) {
		vec[i] = 0;
	}
}

uvector::Vector::Vector(const unsigned &_size, const int &_def)
{
	size = _size;
	vec = new int[_size];
	for (int i = 0; i < size; ++i) {
		vec[i] = _def;
	}
}

uvector::Vector::~Vector()
{
	delete[] vec;
}

std::ostream &uvector::operator<<(std::ostream &stream, const Vector &_vector)
{
	for (int i = 0; i < _vector.size; ++i) {
		stream << _vector.vec[i] << std::endl;
	}
	return stream;
}

int &uvector::Vector::operator[](const int &_index)
{
	return this->vec[_index - 1];
}

uvector::Vector uvector::Vector::operator+(Vector _vector)
{
	int		min		= 0;
	bool	b		= false;
	Vector	sum;

	if (this->size > _vector.size) {
		sum = *this;
		min = _vector.size;
		b = true;
	} else {
		sum = _vector;
		min = size;
		b = false;
	}

	for (int i = 0; i < min; ++i) {
		int s = 0;
		if (b) {
			s = _vector.vec[i];
		} else {
			s = vec[i];
		}
		sum.vec[i] += s;
	}

	return sum;
}

uvector::Vector uvector::Vector::operator-(const Vector &_vector)
{
	Vector l(_vector.size);
	Vector r(*this);

	for (int i = 0; i < _vector.size; ++i) {
		l.vec[i] = (-1) * _vector.vec[i];
	}
	Vector dif = l + r;
	return dif;
}

uvector::Vector uvector::Vector::operator*(const Vector &_vector)
{
	int		min		= 0;
	bool	b		= false;
	Vector	mul;

	if (this->size > _vector.size) {
		mul = *this;
		min = _vector.size;
		b = true;
	} else {
		mul = _vector;
		min = size;
		b = false;
	}

	for (int i = 0; i < min; ++i) {
		int s = 0;
		if (b) {
			s = _vector.vec[i];
		} else {
			s = vec[i];
		}
		mul.vec[i] *= s;
	}

	return mul;
}

uvector::Vector &uvector::Vector::operator=(const Vector &_vector)
{
	if (&_vector != this) {
		size = _vector.size;
		//delete[] vec;
		vec = new int[this->size];
		for (int i = 0; i < size; ++i) {
			vec[i] = _vector.vec[i];
		}
	}
	return *this;
}

bool uvector::Vector::operator>(const Vector &_vector)
{
	for (int i = 0; vec[i], _vector.vec[i]; ++i) {
		if (vec[i] > _vector.vec[i]) {
			return true;
		}
	}
	return false;
}

bool uvector::Vector::operator<(const Vector &_vector)
{
	for (int i = 0; vec[i], _vector.vec[i]; ++i) {
		if (vec[i] < _vector.vec[i]) {
			return true;
		}
	}
	return false;
}
