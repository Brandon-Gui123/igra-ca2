// Component.h
// Done by Brandon Gui (1828865) and Ryan Tan (1829105) from DIT/FT/2B/05

#include "Component.h"

#include "GameObject.h"     // for GameObject class

Component::Component(GameObject &go) : gameObject{go}
{}

Component::~Component()
{}

void Component::Start()
{}

void Component::Update()
{}

void Component::OnGameObjectSelected()
{}
