#pragma once

#include "Color4.h"		// for Color4f, a type alias of Color4 that uses GLfloat
#include "Material.h"	// for Material class
#include "Mesh.h"

class LilypadMesh : public Mesh
{
private:

	Material lilypadMaterial{Color4f{0.f, 1.f, 0.4f, 1.f}, Color4f{0.f, 1.f, 0.4f, 1.f}, Color4f{1.f, 1.f, 1.f, 1.f}, 32};

public:
	void DrawShape() override;
	LilypadMesh();
	~LilypadMesh();
};

