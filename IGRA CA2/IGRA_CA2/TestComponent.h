// Done Ryan Tan (1829105) from DIT/FT/2B/05

#pragma once

#include "Component.h"

class TestComponent : public Component
{
public:
	TestComponent(GameObject &go);
	void Update() override;
	void Start() override;
	~TestComponent();
};

