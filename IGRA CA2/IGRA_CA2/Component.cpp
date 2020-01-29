#include "Component.h"

#include "GameObject.h"

Component::Component(GameObject &go) : gameObject(go)
{}

Component::~Component()
{}

void Component::Start()
{}

void Component::Update()
{}
