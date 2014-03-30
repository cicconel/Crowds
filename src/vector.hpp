#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <cmath>
#include <iostream>


class Vector
{
public:
	/*** Attributes ***/
	double x, y;	// Coordinates


	/*** Constructors ***/
	Vector() : x(0.0), y(0.0) {}
	Vector(double x, double y) : x(x), y(y) {}
	~Vector() {}


	/*** Operators ***/
	inline Vector operator+(const Vector& rhs) const {
		return Vector(x + rhs.x, y + rhs.y);
	}

	inline Vector& operator+=(const Vector& rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	inline Vector operator-(const Vector& rhs) const {
		return Vector(x - rhs.x, y - rhs.y);
	}

	inline Vector& operator-=(const Vector& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	inline Vector operator*(double s) const {
		return Vector(x * s, y * s);
	}

	inline Vector& operator*=(double s) {
		x *= s;
		y *= s;
		return *this;
	}

	inline Vector operator/(double s) const {
		double inv = 1.0 / s;
		return Vector(x * inv, y * inv);
	}

	inline Vector& operator/=(double s) {
		double inv = 1.0 / s;
		x *= inv;
		y *= inv;
		return *this;
	}

	inline Vector operator-() const {
		return Vector(-x, -y);
	}

	inline bool operator==(const Vector& rhs) const {
		double epsilon = 0.001;
		return (fabs(x - rhs.x) < epsilon && fabs(y - rhs.y) < epsilon);
	}

	inline bool operator!=(const Vector& rhs) const {
		return !operator==(rhs);
	}
};


// Multiplication with a scalar
inline Vector operator*(double s, const Vector& rhs) {
	return rhs * s;
}

// Outputs a vector text formatted as "(x,y)"
inline std::ostream& operator<<(std::ostream& os, const Vector& v) {
	return os << '(' << v.x << ',' << v.y << ')';
}

// Returns the dot product of two vectors
inline double dot(const Vector& lhs, const Vector& rhs) {
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

// Efficiency function: does not require square root operation
inline double squared_length(const Vector& v) {
	return v.x * v.x + v.y * v.y;
}

// Returns the length of a vector
inline double length(const Vector& v) {
	return sqrt(squared_length(v));
}

// Calculate the positive distance between two vectors
inline double distance(const Vector& lhs, const Vector& rhs) {
	return length(lhs - rhs);
}

// Efficiency function: does not require square root operation
inline double squared_distance(const Vector& lhs, const Vector& rhs) {
	return squared_length(lhs - rhs);
}

// Returns the unit vector pointing in the same direction as this vector
inline Vector normalize(const Vector& v) {
	return v / length(v);
}

// Returns a vector whose elements are the absolute values of all the elements of this vector
inline Vector vabs(const Vector& v) {
	return Vector(fabs(v.x), fabs(v.y));
}

// Returns the element-wise maximum of the two vectors
inline Vector vmax(const Vector& lhs, const Vector& rhs) {
	return Vector(std::max(lhs.x, rhs.x), std::max(lhs.y, rhs.y));
}

// Returns the element-wise minimum of the two vectors
inline Vector vmin(const Vector& lhs, const Vector& rhs) {
	return Vector(std::min(lhs.x, rhs.x), std::min(lhs.y, rhs.y));
}


#endif
