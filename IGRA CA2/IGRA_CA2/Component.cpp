#include "Component.h"

#include "GameObject.h"

Component::Component(GameObject &go) : gameObject(go)
{}

void Component::Update()
{
}

void Component::Start()
{
}

Component::~Component()
{}
