#pragma once
#include "Component.h"

#include <vector>

class GameManager : public Component
{
private:
	std::vector<GameObject*> lilyPads;
	//Lilypad Player is currently on
	GameObject * currentLilyPad;
	//Latest Lilypad Drawn to Screen
	GameObject * latestLilyPad;
	int currentMap;
	int latestMap;
	//Stores future map data
	//0 = left, 1  right, 2 = left + obstacle, 3 = right + obstacle
	std::vector<int> map;
	//The next move the player should take
	bool nextMove;
	void CreateNextLilyPad();
public:
	void Update() override;
	void Start() override;
	GameManager(GameObject &go);
	~GameManager();
};

