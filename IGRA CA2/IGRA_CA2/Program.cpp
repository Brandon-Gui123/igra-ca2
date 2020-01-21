#include "Program.h"
#include "framework.h"

#include <gl/GL.h>  // OpenGL 32-bit library
#include <gl/GLU.h> // OpenGL Utilities 32-bit library


#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <vector>

void Program::StartInternalTimer()
{
	Time::internalTimer.StartTimer();
}

void Program::QueryDeltaTime()
{
	Time::m_deltaTime = Time::internalTimer.GetTimePassedSinceLastTime();
}

Program::Program()
{
}

void Program::Update() {
	if (selectedScene) selectedScene->Update();
	Draw();
}

void Program::Draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.5f, 0.f, 0.8f, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// we need to do this because our camera is originally positioned at the origin so we won't see anything
	// position the camera at (1, 1, 1), then look at the origin
	gluLookAt(
		5, 4, 5, // Camera's position (we move the camera further down the z-axis to see our cube)
		0, 0, 0,    // Camera's target to look at
		0, 1, 0     // Orientation of the camera
	);

	if (selectedScene) selectedScene->Draw();
}

Program::~Program()
{
}
