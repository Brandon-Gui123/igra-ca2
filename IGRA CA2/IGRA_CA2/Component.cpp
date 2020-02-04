#include "Component.h"

#include "GameObject.h"     // for GameObject class

Component::Component(GameObject &go) : gameObject(go)
{}

Component::~Component()
{}

void Component::Start()
{}

void Component::Update()
{}

void Component::OnGameObjectSelected()
{}
