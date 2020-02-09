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
	for (int i = 0; i < 20; i++) {
		if (rand() % 2 == 1) {
			map.push_back(left);
		}
		else {
			map.push_back(right);
		}
	}

	lilyPads.push_back(&gameObject);
	currentLilyPad = &gameObject;
	latestLilyPad = &gameObject;

	for (int i = 0; i < 20; i++) {
		Lily &lily{CreateNextLilyPad()};

		// last lily
		if (i == 19)
		{
			lily.isGoal = true;
		}
	}
}

//Called when player makes a jump
void GameManager::PlayerLand(bool mleft)
{
	int landedLily = map.at(currentMap);
	bool landed;

	if (landedLily == left) {
		landed = mleft;
	} else{
		landed = !mleft;
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
	
	if (currentLilyPad->GetComponent<Lily>()->hasObstacle)
	{
		player->GetComponent<Player>()->Die();
	}
}

Lily& GameManager::CreateNextLilyPad()
{
	Vector3f nextPos = latestLilyPad->position;
	//0 = left, 1  right, 2 = left + obstacle, 3 = right + obstacle
	switch (map.at(latestMap)) {
		case left:
			nextPos += Vector3f{ 0, 0, 2 };
			break;
		case right:
			nextPos += Vector3f{ 2, 0, 0 };
			break;
	}

	GameObject &instance{ GameObject::Create("lily", nextPos, Vector3f{ 0, (float)(rand() % 360), 0 }, Vector3f::one) };
	LilypadMesh* lilypadMesh{ new LilypadMesh{} };
	instance.mesh = lilypadMesh;
	instance.AddComponent<Lily>();

	if ((static_cast<float>(rand()) / RAND_MAX) > 0.8f)
	{
		instance.GetComponent<Lily>()->hasObstacle = true;
		GameObject &obstacle{GameObject::Create("Obstacle", nextPos, Vector3f{-90.f, 0.f, 0.f}, Vector3f::one)};
		obstacle.mesh = new ObstacleMesh{obstacle};
		obstacle.AddComponent<Obstacle>().lily = instance.GetComponent<Lily>();
	}

	lilyPads.push_back(&instance);
	latestLilyPad = &instance;
	latestMap++;
	return *(instance.GetComponent<Lily>());
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
