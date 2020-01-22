#include "GameObject.h"
#include "Component.h"

void GameObject::Draw()
{
}

void GameObject::Update()
{
}

void GameObject::AddComponent(Component &co)
{
	components.push_back(&co);
}

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}
