#pragma once

#include "Vector3f.h";
class Mesh
{
public:
	Mesh();
	~Mesh();
	void Draw(Vector3f, Vector3f, Vector3f); //override this function
};

