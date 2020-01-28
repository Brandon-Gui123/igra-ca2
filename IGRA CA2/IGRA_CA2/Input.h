#pragma once

#include "KeyCode.h"            // for KeyCode enum class

#include <unordered_map>        // for std::unordered_map, similar to a C# dictionary

class Input
{
private:

    struct KeyStatus
    {
        bool isHeldDown{false};
        bool isDown{false};
        bool isUp{false};
    };

private:
    static std::unordered_map<int, KeyStatus> inputKeys;
};

