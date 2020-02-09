// This file is used in a unit testing project which tests the classes and ensures that
// everything runs as intended.
//
// Done by Brandon Gui (p1828865) from DIT/FT/2B/05.

#include "pch.h"
#include "FooComponent.h"

FooComponent::FooComponent(GameObject &go) : Component{go}
{}

FooComponent::~FooComponent()
{}
