// Done by Ryan Tan (1829105) from DIT/FT/2B/05

#pragma once

#include "Mesh.h";
#include "Color4.h";
#include "Material.h"

class TimerBarMesh : public Mesh
{
private:
	Material TimerBarMaterial{ Color4f{1.f, 0.f, 0.f, 1.f}, Color4f{1.f, 0.f, 0.f, 1.f}, Color4f{1.f, 1.f, 1.f, 1.f}, 32 };

public:
	void DrawShape() override;
	TimerBarMesh();
	~TimerBarMesh();
};

