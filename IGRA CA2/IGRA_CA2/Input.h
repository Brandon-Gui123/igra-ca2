#pragma once

#include "KeyCode.h"            // for KeyCode enum class
#include "Program.h"            // for Program class

#include "framework.h"          // for WPARAM, which contains the hex code of the key of interest

#include <unordered_map>        // for std::unordered_map, similar to a C# dictionary
#include <vector>               // for std::vector

class Input
{
private:

    struct KeyStatus
    {
        bool isHeldDown{false};
        bool isDown{false};
        bool isUp{false};
    };

    static void SendKeyDown(const WPARAM &wParam);
    static void SendKeyUp(const WPARAM &wParam);
    static void ResetKeyDownUp();

public:

    static bool GetKey(KeyCode keyCode);
    static bool GetKeyDown(KeyCode keyCode);
    static bool GetKeyUp(KeyCode keyCode);

    Input();
    ~Input();

private:
    static std::unordered_map<int, KeyStatus> inputKeys;
    static std::vector<KeyStatus*> keyStatusesToReset;
};

