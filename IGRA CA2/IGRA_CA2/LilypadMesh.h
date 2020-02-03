#pragma once

#include "Mesh.h"

class LilypadMesh : public Mesh
{
public:
	void DrawShape() override;
	LilypadMesh();
	~LilypadMesh();
};

