#pragma once

#include "GameObject.h"		// to friend the GameObject class
#include "MouseButton.h"	// for MouseButton enum class
#include "Time.h"			// for Time class

#include "framework.h"		// to define the Windows stuff inside gl/GL.h
#include <gl/GL.h>			// for OpenGL 32-bit library

#include <vector>			// for std::vector

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
	bool willRestart{false};
	double timeLeft{0.0};

	Program();
	~Program();

	// Gets the current phase of the program.
	// Note that the returned value of this method cannot be modified.
	const Phase& GetCurrentPhase();

#pragma region Initialization - stuff done during initialization

	// Sets up lighting to be used for all scenes.
	void SetupLight();

	// Initializes all scenes and their GameObjects, Components, Meshes and everything else that are
	// placed inside the method.
	void InitializeScenes();

	// Starts the program's internal timer where timed operations frequently request from.
	void StartInternalTimer();

#pragma endregion

#pragma region Input Handling - dealing with inputs to Input class

	// Sends the key down event to the Input class for it to handle.
	// This method serves as an abstraction between the Input class and the WndProc method.
	void SendKeyDown(const WPARAM &wParam);

	// Sends the key up event to the Input class for it to handle.
	// This method serves as an abstraction between the Input class and the WndProc method.
	void SendKeyUp(const WPARAM &wParam);

	// Sends the mouse button down event to the Input class for it to handle.
	// This method serves as an abstraction between the Input class and the WndProc method.
	void SendMouseButtonDown(MouseButton mouseButton);

	// Sends the mouse button up event to the Input class for it to handle.
	// This method serves as an abstraction between the Input class and the WndProc method.
	void SendMouseButtonUp(MouseButton mouseButton);

	// Sends the mouse position coordinates to the Input class for it to store.
	// This method serves as an abstraction between the Input class and the WndProc method.
	void SendMousePosition(int x, int y);

	// Resets the statuses of all keys in the Input class, so that it no longer is down or up for the next frame.
	// This method serves as an abstraction between the Input class and the WndProc method.
	void ResetInputKeyUpDownStatus();

	// Resets the statuses of all mouse buttons in the Input class, so that it is no longer down or up for the next frame.
	// This method serves as an abstraction between the Input class and the WndProc method.
	void ResetMouseButtonUpDownStatus();

#pragma endregion

#pragma region Messages - calls corresponding methods in GameObjects

	// Called once right after all scenes, GameObjects and their components have been initialized.
	// This method is intended to call Start on all GameObjects in the currently loaded scene.
	void Start();

	// Called once per frame.
	// This method is intended to call Update on all GameObjects in the currently loaded scene.
	void Update();

	// Called once per frame, after the Update method. This draws all meshes onto the screen.
	// This method is intended to call Draw on all GameObjects in the currently loaded scene
	// so that the GameObjects get to draw their meshes.
	void Draw();

#pragma endregion

#pragma region Post-Update - stuff done after the Update loops

	// Moves the newly-created GameObjects in the currently active scene to the standard GameObjects vector.
	void MoveNewGOsToMain();

	// Tells the currently loaded scene to tell its GameObjects to call Start on all newly-added components.
	void DoStartOnAddedComponents();
	
	// Removes all PickableMeshes from GameObjects that are going to be destroyed.
	void DoDestroyCycleForPickableMeshes();

	// Removes all GameObjects that are marked for destruction in the currently active scene.
	void DoDestroyCycle();

	// Queries the time passed since the last Update loop from the internal timer.
	void QueryDeltaTime();

#pragma endregion

#pragma region Back buffer - methods that utilize the back buffer for various purposes

	// Draws all pickable meshes into the back buffer, then checks to see which mesh is the one that is selected by the mouse.
	// Upon selection, the mesh tells its GameObject that is has been selected.
	// The GameObject will then tell all of its components that it has been selected.
	// You can listen in on this event by overriding the OnGameObjectSelected method.
	void DrawPickableMeshes();

#pragma endregion

	// Restarts the program.
	void RestartProgram();

	// TODO Replace with Texture class
	static void CreateWoodTexture();
	static GLubyte woodTexture[64][64][3];
};

