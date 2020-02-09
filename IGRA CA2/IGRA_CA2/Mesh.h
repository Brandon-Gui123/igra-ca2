// Done by Ryan Tan (1829105) from DIT/FT/2B/05

#pragma once

#include "Vector3f.h"	// for Vector3f class

class Mesh
{
public:

	Mesh();
	~Mesh();

	void Draw(const Vector3f &pos, const Vector3f &rot, const Vector3f &sca);

	virtual void DrawShape();
};

