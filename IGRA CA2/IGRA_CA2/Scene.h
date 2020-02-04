#pragma once

#include "GameObject.h"
#include "Program.h"
#include "GameManager.h"

#include <vector>

// To break circular dependency between Scene and Program
class Program;

class Scene
{
private:
	std::vector<GameObject*> gameObjects;

public:

	Scene();
	virtual ~Scene();

	void Start();
	void Update();
	void Draw();

	friend class Program;
	friend class GameObject;
	friend class GameManager;
};

