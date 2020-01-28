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

	void StartInternalTimer();
	void QueryDeltaTime();
	void SetupLight();
	void SendKeyDown(const WPARAM &wParam);
	void SendKeyUp(const WPARAM &wParam);
	void ResetInputKeyUpDownStatus();

	Program();
	~Program();

	void Draw();
	void Update();
	void Start();
};

