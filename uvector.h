#pragma once
#include <iostream>

namespace uvector
{
	class Vector
	{
	public:
		typedef int* iterator;
		Vector();
		Vector(const Vector &_vector);
		Vector(const unsigned &_size);
		Vector(const unsigned &_size, const int &_def);
		~Vector();
		Vector operator+(Vector _vector);
		Vector operator-(const Vector &_vector);
		Vector operator*(const Vector &_vector);
		Vector &operator=(const Vector &_vector);

		bool operator>(const Vector &_vector);
		bool operator<(const Vector &_vector);

		int &operator[](const int &_index);
		friend std::ostream &operator<<(std::ostream &stream, const Vector &_vector);
	private:
		iterator	vec;
		int			size;
	};
}
