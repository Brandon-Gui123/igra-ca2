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

