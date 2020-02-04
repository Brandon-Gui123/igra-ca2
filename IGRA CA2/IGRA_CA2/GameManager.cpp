#include "GameManager.h"

#include "Program.h"
#include "GameObject.h"
#include "Scene.h"

void GameManager::Update()
{
}

void GameManager::Start()
{
	Program::program->Instantiate("Lilypad", Vector3f::zero, Vector3f{ 0, 0, 0 }, Vector3f::one);
}

GameManager::GameManager(GameObject &go) : Component(go)
{
}

GameManager::~GameManager()
{
}
