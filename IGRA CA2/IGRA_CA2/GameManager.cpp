#include "GameManager.h"

#include "Program.h"
#include "GameObject.h"
#include "Scene.h"
#include "LilypadMesh.h"

#include <vector>
#include <time.h>
#include <functional>


void GameManager::Start()
{
	/*GameObject &instance{ GameObject::Create("test", Vector3f{ 1, 0, 0 }, Vector3f{ 0, 0, 0 }, Vector3f::one) };
	LilypadMesh* lilypadMesh{ new LilypadMesh{} };
	instance.mesh = lilypadMesh;*/

	srand(time(0));

	//Generate Map
	for (int i = 0; i < 100; i++) {
		map.push_back(rand() % 4);
	}

	lilyPads.push_back(&gameObject);
	currentLilyPad = &gameObject;
	latestLilyPad = &gameObject;

	for (int i = 0; i < 100; i++) {
		CreateNextLilyPad();
	}
}

void GameManager::CreateNextLilyPad()
{
	Vector3f nextPos = latestLilyPad->position;
	//0 = left, 1  right, 2 = left + obstacle, 3 = right + obstacle
	switch (map.at(latestMap)) {
		case 0:
			nextPos += Vector3f{ 0, 0, 2 };
			break;
		case 1:
			nextPos += Vector3f{ 2, 0, 0 };
			break;
		case 2:
			nextPos += Vector3f{ 0, 0, 2 };
			break;
		case 3:
			nextPos += Vector3f{ 2, 0, 0 };
			break;
	}

	GameObject &instance{ GameObject::Create("lily", nextPos, Vector3f{ 0, (float)(rand() % 360), 0 }, Vector3f::one) };
	LilypadMesh* lilypadMesh{ new LilypadMesh{} };
	instance.mesh = lilypadMesh;

	lilyPads.push_back(&instance);
	latestLilyPad = &instance;
	latestMap++;
}

void GameManager::Update()
{

}

GameManager::GameManager(GameObject &go) : Component(go)
{
	currentMap = 0;
	latestMap = 0;
}

GameManager::~GameManager()
{
}
