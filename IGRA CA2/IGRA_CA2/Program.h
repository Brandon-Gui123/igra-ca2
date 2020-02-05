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

	static inline constexpr int initialWindowWidth{800};	// The initial width of the window, in pixels.
	static inline constexpr int initialWindowHeight{600};	// The initial height of the window, in pixels.

	// An enumeration of phases that the program can be in, such as
	// when it is initializing objects or running.
	enum class Phase
	{
		Initializing,	// The program is initializing GameObjects and their components and meshes.
		Running			// The program is currently running the game.
	};

private:

	Phase currentPhase{Phase::Initializing};

	GameObject *camera;

	// A dynamically-allocated three-dimensional array (height, row and color channel values) that
	// stores the colour values of what is shown on screen in the program.
	//
	// The reason it is dynamically-allocated is because storing this on the stack will cause a stack overflow
	// since the array is too huge for the stack to handle.
	GLubyte (*backBufferImage)[initialWindowWidth][3];

public:

	static Program *program;

	std::vector<Scene*> scenes;
	Scene *selectedScene;

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

	
	// TODO Replace with Texture class
	static void CreateCheckerBoardTexture();
	static GLubyte placeholderTexture[64][64][3];
};

