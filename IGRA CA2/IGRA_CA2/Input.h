#pragma once

#include "KeyCode.h"            // for KeyCode enum class
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

    static Vector2f windowsMousePosition;

    struct KeyStatus
    {
        bool isHeldDown{false};
        bool isDown{false};
        bool isUp{false};
    };

    // Sends the key down event to the mapped input keys, affecting the state of the key that is pressed down.
    static void SendKeyDown(const WPARAM &wParam);

    // Sends the key up event to the mapped input keys, affecting the state of the key that is lifted up.
    static void SendKeyUp(const WPARAM &wParam);

    // Resets the statuses of the keys that have been altered.
    // Only resets statuses that should only last for the current frame.
    static void ResetKeyDownUp();

public:

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
    static Vector2f& GetWindowsMousePosition();

    Input();
    ~Input();

private:
    static std::unordered_map<int, KeyStatus> inputKeys;
    static std::vector<KeyStatus*> keyStatusesToReset;

    friend class Program;
};

