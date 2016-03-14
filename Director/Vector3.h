#ifndef VECTOR3_H
#define VECTOR3_H

#include <ostream>

// defines a vector in 3D Cartesian space.
struct Vector3
{
	Vector3(float x, float y, float z)
		: x(x),
		  y(y),
		  z(z)
	{
	}

	float x;
	float y;
	float z;

	
};

inline std::ostream& operator<<(std::ostream& out, Vector3& vec)
{
		out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
		return out;
}

#endif
