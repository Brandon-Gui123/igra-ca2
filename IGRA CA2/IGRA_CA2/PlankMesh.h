// Done by Ryan Tan (1829105) from DIT/FT/2B/05

#pragma once

#include "Color4.h"		// for Color4f, a type alias of Color4 using GLfloat
#include "Material.h"	// for Material class
#include "Mesh.h"

class PlankMesh : public Mesh
{
private:
	Material plankMaterial{Color4f{1.f, 1.f, 1.f, 1.f}, Color4f{1.f, 1.f, 1.f, 1.f}, Color4f{1.f, 1.f, 1.f, 1.f}, 32 };

public:
	void DrawShape() override;
	PlankMesh();
	~PlankMesh();
};

