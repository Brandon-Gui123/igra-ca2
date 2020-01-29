#pragma once

#include "Scene.h"
#include "Time.h"

#include "framework.h"
#include <gl/GL.h>  // OpenGL 32-bit library

#include <vector>

class Program
{
private:
public:

	std::vector<Scene*> scenes;
	Scene *selectedScene;
	static void CreateCheckerBoardTexture();
	static GLubyte placeholderTexture[64][64][3];

	Program();
	~Program();

	void InitializeScenes();

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

