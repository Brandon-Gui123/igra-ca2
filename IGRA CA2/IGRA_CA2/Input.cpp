#include "Input.h"

void Input::SendKeyDown(const WPARAM &wParam)
{
    KeyStatus &keyStatus{inputKeys.at(wParam)};

    // check if the key is already held down to prevent keyboard repeating from happening
    if (keyStatus.isHeldDown)
    {
        return;
    }

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

void Input::ResetKeyDownUp()
{
    for (KeyStatus *&keyStatusPtr : keyStatusesToReset)
    {
        keyStatusPtr->isDown = false;
        keyStatusPtr->isUp = false;
    }
}

std::vector<Input::KeyStatus*> Input::keyStatusesToReset{};