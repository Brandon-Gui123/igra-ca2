// Done by Ryan Tan (1829105) from DIT/FT/2B/05

#pragma once

#include "Color4.h"		// for Color4f, a type alias of Color4 using GLfloat
#include "Material.h"	// for Material class
#include "Mesh.h"

class PlayerMesh : public Mesh
{
private:

	// duck's body (yellow)
	Material bodyMaterial{Color4f{1.f, 1.f, 0.f, 1.f}, Color4f{1.f, 1.f, 0.f, 1.f}, Color4f{1.f, 1.f, 1.f, 1.f}, 32};

	// duck's bill (orange)
	Material billMaterial{Color4f{1.f, 0.5f, 0.f, 1.f}, Color4f{1.f, 0.5f, 0.f, 1.f}, Color4f{1.f, 1.f, 1.f, 1.f}, 32};

	// duck's legs (orange)
	Material legsMaterial{Color4f{1.f, 0.5f, 0.f, 1.f}, Color4f{1.f, 0.5f, 0.f, 1.f}, Color4f{1.f, 1.f, 1.f, 1.f}, 32};

	// duck's eye
	Material eyeMaterial{Color4f{0.f, 0.f, 0.f, 1.f}, Color4f{0.f, 0.f, 0.f, 1.f}, Color4f{1.f, 1.f, 1.f, 1.f}, 32};

public:		
	void DrawShape() override;
	PlayerMesh();
	~PlayerMesh();
};

