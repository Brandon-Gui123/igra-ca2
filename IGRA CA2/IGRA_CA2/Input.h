// Done by Brandon Gui (1828865) and Ryan Tan (1829105) from DIT/FT/2B/05

#pragma once

#include "KeyCode.h"            // for KeyCode enum class
#include "MouseButton.h"        // for MouseButton enum class
#include "Program.h"            // for Program class
#include "Vector2f.h"           // for Vector2f class

#include "framework.h"          // for WPARAM, which contains the hex code of the key of interest

#include <unordered_map>        // for std::unordered_map, similar to a C# dictionary
#include <vector>               // for std::vector

// A class that interfaces into your device's input system and allows easy access
// to the status of keys, such as whether a certain is pressed down.
class Input
{
private:

#pragma region Structs

    struct KeyStatus
    {
        bool isHeldDown{false};
        bool isDown{false};
        bool isUp{false};
    };

    struct MouseButtonStatus
    {
        bool isHeldDown{false};
        bool isDown{false};
        bool isUp{false};
    };

	struct InputAxis {
		KeyCode positive;
		KeyCode negative;
		float value;
	};

#pragma endregion

    static Vector2f windowsMousePosition;

    static MouseButtonStatus leftMouseButtonStatus;
    static MouseButtonStatus middleMouseButtonStatus;
    static MouseButtonStatus rightMouseButtonStatus;

    // Sends the key down event to the mapped input keys, affecting the state of the key that is pressed down.
    static void SendKeyDown(const WPARAM &wParam);

    // Sends the key up event to the mapped input keys, affecting the state of the key that is lifted up.
    static void SendKeyUp(const WPARAM &wParam);

    // Resets the statuses of the keys that have been altered.
    // Only resets statuses that should only last for the current frame.
    static void ResetKeyDownUp();

    // Sends the mouse button down event to the mapped mouse button keys, affecting the state of the mouse button that is pressed down.
    static void SendMouseButtonDown(MouseButton mouseButton);

    // Sends the mouse button up event to the mapped mouse button keys, affecting the state of the mouse button that is pressed down.
    static void SendMouseButtonUp(MouseButton mouseButton);

    // Resets the statuses of all mouse buttons.
    static void ResetMouseButtonDownUp();

public:

	static InputAxis x;
	static InputAxis y;

	static float GetAxis(InputAxis axis);

    // Returns true if the key identified by the given key code is held down.
    // Otherwise, it returns false.
    static bool GetKey(KeyCode keyCode);

    // Returns true if the key identified by the given key code is held down on this current frame.
    // Otherwise, it returns false.
    static bool GetKeyDown(KeyCode keyCode);

    // Returns true if the key identified by the given key code is lifted up on this current frame.
    // Otherwise, it returns false.
    static bool GetKeyUp(KeyCode keyCode);

    // Gets the position of the mouse cursor in window coordinates.
    static const Vector2f& GetWindowsMousePosition();

    // Returns true if the mouse button is held down.
    // Otherwise, it returns false.
    static bool GetMouseButton(MouseButton mouseButton);

    // Returns true if the mouse button is held down on this current frame.
    // Otherwise, it returns false.
    static bool GetMouseButtonDown(MouseButton mouseButton);

    // Returns true if the mouse button is lifted up on this current frame.
    // Otherwise, it returns false.
    static bool GetMouseButtonUp(MouseButton mouseButton);

    Input();
    ~Input();

private:
    static std::unordered_map<int, KeyStatus> inputKeys;
    static std::vector<KeyStatus*> keyStatusesToReset;

    // For the Program class to call the send input methods (SendKeyDown, SendKeyUp etc.)
    // so that the Input class can update the statuses of the keys it is keeping
    // track of.
    friend class Program;
};

