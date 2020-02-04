#include "GameManager.h"

#include "Program.h"
#include "GameObject.h"
#include "Scene.h"

void GameManager::Update()
{
}

void GameManager::Start()
{
	GameObject &instance{ GameObject::Create("test", Vector3f::zero, Vector3f{ 1, 0, 0 }, Vector3f::one) };
}

GameManager::GameManager(GameObject &go) : Component(go)
{
}

GameManager::~GameManager()
{
}
