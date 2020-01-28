#include "Input.h"

void Input::SendKeyDown(const WPARAM &wParam)
{
    KeyStatus &keyStatus{inputKeys.at(wParam)};

    keyStatus.isDown = true;
    keyStatus.isHeldDown = true;

    keyStatusesToReset.push_back(&keyStatus);
}

void Input::SendKeyUp(const WPARAM &wParam)
{
    KeyStatus &keyStatus{inputKeys.at(wParam)};

    keyStatus.isUp = true;
    keyStatus.isHeldDown = false;

    keyStatusesToReset.push_back(&keyStatus);
}

