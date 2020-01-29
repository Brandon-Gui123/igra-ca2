#include "Input.h"

#include <stdexcept>    // for std::out_of_range exception

void Input::SendKeyDown(const WPARAM &wParam)
{
    try
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
    catch (std::out_of_range ex)
    {
        // TODO Make it throw out a warning or something instead of being completely silent about it
        // looks like we've not updated our key mappings in the inputKeys unordered_map
        return;
    }
}

void Input::SendKeyUp(const WPARAM &wParam)
{
    try
    {
        KeyStatus &keyStatus{inputKeys.at(wParam)};

        keyStatus.isUp = true;
        keyStatus.isHeldDown = false;

        keyStatusesToReset.push_back(&keyStatus);
    }
    catch (std::out_of_range ex)
    {
        // TODO Make it throw out a warning or something instead of being completely silent about it
        // looks like we've not updated our key mappings in the inputKeys unordered_map
        return;
    }
}

void Input::ResetKeyDownUp()
{
    for (KeyStatus *&keyStatusPtr : keyStatusesToReset)
    {
        keyStatusPtr->isDown = false;
        keyStatusPtr->isUp = false;
    }
}

bool Input::GetKey(KeyCode keyCode)
{
    return inputKeys.at(static_cast<int>(keyCode)).isHeldDown;
}

bool Input::GetKeyDown(KeyCode keyCode)
{
    return inputKeys.at(static_cast<int>(keyCode)).isDown;
}

bool Input::GetKeyUp(KeyCode keyCode)
{
    return inputKeys.at(static_cast<int>(keyCode)).isUp;
}

Input::Input()
{}

Input::~Input()
{}

std::unordered_map<int, Input::KeyStatus> Input::inputKeys
{
    { static_cast<int>(KeyCode::A), KeyStatus{} },
    { static_cast<int>(KeyCode::B), KeyStatus{} },
    { static_cast<int>(KeyCode::C), KeyStatus{} },
    { static_cast<int>(KeyCode::D), KeyStatus{} },
    { static_cast<int>(KeyCode::E), KeyStatus{} },
    { static_cast<int>(KeyCode::F), KeyStatus{} },
    { static_cast<int>(KeyCode::G), KeyStatus{} },
    { static_cast<int>(KeyCode::H), KeyStatus{} },
    { static_cast<int>(KeyCode::I), KeyStatus{} },
    { static_cast<int>(KeyCode::J), KeyStatus{} },
    { static_cast<int>(KeyCode::K), KeyStatus{} },
    { static_cast<int>(KeyCode::L), KeyStatus{} },
    { static_cast<int>(KeyCode::M), KeyStatus{} },
    { static_cast<int>(KeyCode::N), KeyStatus{} },
    { static_cast<int>(KeyCode::O), KeyStatus{} },
    { static_cast<int>(KeyCode::P), KeyStatus{} },
    { static_cast<int>(KeyCode::Q), KeyStatus{} },
    { static_cast<int>(KeyCode::R), KeyStatus{} },
    { static_cast<int>(KeyCode::S), KeyStatus{} },
    { static_cast<int>(KeyCode::T), KeyStatus{} },
    { static_cast<int>(KeyCode::U), KeyStatus{} },
    { static_cast<int>(KeyCode::V), KeyStatus{} },
    { static_cast<int>(KeyCode::W), KeyStatus{} },
    { static_cast<int>(KeyCode::X), KeyStatus{} },
    { static_cast<int>(KeyCode::Y), KeyStatus{} },
    { static_cast<int>(KeyCode::Z), KeyStatus{} },
};

std::vector<Input::KeyStatus*> Input::keyStatusesToReset{};