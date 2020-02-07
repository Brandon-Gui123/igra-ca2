#include "GameManager.h"

#include "Program.h"
#include "GameObject.h"
#include "Scene.h"
#include "LilypadMesh.h"
#include "Player.h"
#include "Lily.h"
#include "Obstacle.h"		// for Obstacle component class
#include "ObstacleMesh.h"	// for Obstacle mesh class

#include <vector>
#include <time.h>
#include <functional>

void GameManager::Start()
{
	/*GameObject &instance{ GameObject::Create("test", Vector3f{ 1, 0, 0 }, Vector3f{ 0, 0, 0 }, Vector3f::one) };
	LilypadMesh* lilypadMesh{ new LilypadMesh{} };
	instance.mesh = lilypadMesh;*/
	currentMap = 0;
	latestMap = 0;

	player = GameObject::Find("Player");

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

//Called when player makes a jump
void GameManager::PlayerLand(bool left)
{
	int landedLily = map.at(currentMap);
	bool landed;

	if (landedLily == 0 || landedLily == 2) {
		landed = left;
	} else{
		landed = !left;
	}

	if (!landed) {
		player->GetComponent<Player>()->Die();
	}
	Lily * dLily = currentLilyPad->GetComponent<Lily>();
	if (dLily) {
		dLily->Drop();
	}
	currentMap++;
	currentLilyPad = lilyPads.at(currentMap);
	map.push_back(rand() % 4);
	CreateNextLilyPad();
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
	instance.AddComponent<Lily>();

	if ((static_cast<float>(rand()) / RAND_MAX) > 0.5f)
	{
		instance.GetComponent<Lily>()->hasObstacle = true;
		GameObject &obstacle{GameObject::Create("Obstacle", nextPos, Vector3f{-90.f, 0.f, 0.f}, Vector3f::one)};
		obstacle.mesh = new ObstacleMesh{obstacle};
		obstacle.AddComponent<Obstacle>();
	}

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
