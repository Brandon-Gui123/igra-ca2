// Done Ryan Tan (1829105) from DIT/FT/2B/05

#include "TestComponent.h"

#include "GameObject.h"
#include "Time.h"
#include "Vector3f.h"

TestComponent::TestComponent(GameObject &go) : Component(go)
{
}

void TestComponent::Update()
{
	Vector3f newRot(0, gameObject.rotation.y + Time::GetDeltaTime() * 5, 0);
	gameObject.rotation = newRot;

	Vector3f newPos(0, 0, gameObject.position.z + Time::GetDeltaTime() * 0.5);
	gameObject.position = newPos;
}

void TestComponent::Start()
{
	Vector3f newSca(0.1, 1, 1);
	gameObject.scale = newSca;
}

TestComponent::~TestComponent()
{
}
