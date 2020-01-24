#include "GameObject.h"

#include "Component.h"      // for Component class

GameObject::GameObject()
{}

GameObject::~GameObject()
{}

int GameObject::GetComponentCount()
{
    return components.size();
}

void GameObject::Draw()
{}

void GameObject::Update()
{}