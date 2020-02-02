#pragma once
#include "Mesh.h"
class PlayerMesh : public Mesh
{
public:		
	void DrawShape() override;
	PlayerMesh();
	~PlayerMesh();
};

