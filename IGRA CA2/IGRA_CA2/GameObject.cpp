#include "GameObject.h"
#include "Component.h"

GameObject::GameObject()
{}

GameObject::~GameObject()
{}

void GameObject::Draw()
{}

void GameObject::Update()
{}

void GameObject::AddComponent(Component &co)
{
    components.push_back(&co);
}