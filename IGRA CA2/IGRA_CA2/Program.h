#pragma once

#include "GameObject.h"		// to friend the GameObject class
#include "MouseButton.h"
#include "Time.h"

#include "framework.h"
#include <gl/GL.h>  // OpenGL 32-bit library

#include <vector>

// To break circular dependency between Scene and Program
class Scene;

class Program
{
public:

	static constexpr int initialWindowWidth{800};	// The initial width of the window, in pixels.
	static constexpr int initialWindowHeight{600};	// The initial height of the window, in pixels.

	enum class Phase
	{
		Initializing,
		Running
	};

private:

	Phase currentPhase{Phase::Initializing};
	GameObject * camera;

public:

	static Program *program;

	GLubyte (*backBufferImage)[initialWindowWidth][3];

	std::vector<Scene*> scenes;
	Scene *selectedScene;
	static void CreateCheckerBoardTexture();
	static GLubyte placeholderTexture[64][64][3];

	Program();
	~Program();

	void InitializeScenes();

	void DoDestroyCycle();
	void DoStartOnAddedComponents();	// Tells the currently loaded scene to tell its GameObjects to call Start on all newly-added components.
	void MoveNewGOsToMain();	// Moves the newly-created GameObjects in the scene to the standard GameObjects vector.
	void QueryDeltaTime();
	void ResetInputKeyUpDownStatus();
	void ResetMouseButtonUpDownStatus();
	void StartInternalTimer();
	void SendKeyDown(const WPARAM &wParam);
	void SendKeyUp(const WPARAM &wParam);
	void SendMouseButtonDown(MouseButton mouseButton);
	void SendMouseButtonUp(MouseButton mouseButton);
	void SendMousePosition(int x, int y);
	void SetupLight();

	void DrawPickableMeshes();

	void Start();
	void Update();
	void Draw();

	const Phase& GetCurrentPhase();
};

