#pragma once
#include <vector>
#include "Scene.h"

class Program
{
private:
	void Draw();
public:

	std::vector<Scene> scenes;
	Scene *selectedScene;
	Program();
	~Program();

	void Update();
};

