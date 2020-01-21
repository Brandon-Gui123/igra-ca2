#pragma once

#include "Time.h"
#include <vector>
#include "Scene.h"

class Program
{
private:
	void Draw();
public:

	std::vector<Scene> scenes;
	Scene *selectedScene;

	void StartInternalTimer();
	void QueryDeltaTime();

	Program();
	~Program();

	void Update();
};

