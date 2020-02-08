#pragma once
#include "Component.h"
#include "Player.h"

#include <vector>

enum LilyMap {
	left,
	right
};

class GameManager : public Component
{
private:
	std::vector<GameObject*> lilyPads;
	//Lilypad Player is currently on
	GameObject * currentLilyPad;
	//Latest Lilypad Drawn to Screen
	GameObject * latestLilyPad;
	GameObject * player;
	int currentMap;
	int latestMap;
	std::vector<LilyMap> map;
	//The next move the player should take
	bool nextMove;
	void CreateNextLilyPad();
public:
	void Update() override;
	void Start() override;
	void PlayerLand(bool left);
	GameManager(GameObject &go);
	~GameManager();

	friend class Player;
};

