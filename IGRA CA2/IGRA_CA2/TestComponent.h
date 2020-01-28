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

