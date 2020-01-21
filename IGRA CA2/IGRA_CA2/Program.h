#pragma once
#include <vector>
#include "Scene.h"

class Program
{
private:
	void Draw();
	std::vector<Scene> scenes;
	Scene *selectedScene;
public:
	Program();
	~Program();

	void Update();
};

