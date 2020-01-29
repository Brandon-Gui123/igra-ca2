#pragma once

#include "Scene.h"
#include "Time.h"

#include "framework.h"

#include <vector>

class Program
{
private:
public:

	std::vector<Scene*> scenes;
	Scene *selectedScene;

	Program();
	~Program();

	void QueryDeltaTime();
	void ResetInputKeyUpDownStatus();
	void StartInternalTimer();
	void SendKeyDown(const WPARAM &wParam);
	void SendKeyUp(const WPARAM &wParam);
	void SetupLight();

	void Start();
	void Update();
	void Draw();
};

