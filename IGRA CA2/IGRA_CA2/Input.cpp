#include "Input.h"

#include "Vector2f.h"   // for Vector2f class

#include <stdexcept>    // for std::out_of_range exception

Vector2f Input::windowsMousePosition{0, 0};

Input::MouseButtonStatus Input::leftMouseButtonStatus{};
Input::MouseButtonStatus Input::middleMouseButtonStatus{};
Input::MouseButtonStatus Input::rightMouseButtonStatus{};

Input::InputAxis Input::x{ KeyCode::A, KeyCode::D, 0 };
Input::InputAxis Input::y{ KeyCode::W, KeyCode::S, 0 };

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

void Input::SendMouseButtonDown(MouseButton mouseButton)
{
    switch (mouseButton)
    {
        case MouseButton::Left:
            leftMouseButtonStatus.isDown = true;
            leftMouseButtonStatus.isHeldDown = true;
            break;

        case MouseButton::Middle:
            middleMouseButtonStatus.isDown = true;
            middleMouseButtonStatus.isHeldDown = true;
            break;

        case MouseButton::Right:
            rightMouseButtonStatus.isDown = true;
            rightMouseButtonStatus.isHeldDown = true;
            break;
    }
}

void Input::SendMouseButtonUp(MouseButton mouseButton)
{
    switch (mouseButton)
    {
        case MouseButton::Left:
            leftMouseButtonStatus.isUp = true;
            leftMouseButtonStatus.isHeldDown = false;
            break;

        case MouseButton::Middle:
            middleMouseButtonStatus.isUp = true;
            middleMouseButtonStatus.isHeldDown = false;
            break;

        case MouseButton::Right:
            rightMouseButtonStatus.isUp = true;
            rightMouseButtonStatus.isHeldDown = false;
            break;
    }
}

void Input::ResetMouseButtonDownUp()
{
    leftMouseButtonStatus.isDown = false;
    leftMouseButtonStatus.isUp = false;

    middleMouseButtonStatus.isDown = false;
    middleMouseButtonStatus.isUp = false;

    rightMouseButtonStatus.isDown = false;
    rightMouseButtonStatus.isUp = false;
}

float Input::GetAxis(InputAxis axis)
{
	axis.value = 0;
	if (GetKey(axis.positive)) axis.value = 1;
	if (GetKey(axis.negative)) axis.value = -1;
	if (GetKey(axis.positive) && GetKey(axis.negative)) axis.value = 0;
	return axis.value;
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

const Vector2f& Input::GetWindowsMousePosition()
{
    return windowsMousePosition;
}

bool Input::GetMouseButton(MouseButton mouseButton)
{
    switch (mouseButton)
    {
        case MouseButton::Left:
            return leftMouseButtonStatus.isHeldDown;

        case MouseButton::Middle:
            return middleMouseButtonStatus.isHeldDown;

        case MouseButton::Right:
            return rightMouseButtonStatus.isHeldDown;

        default:
            // Unknown mouse button, so return false
            return false;
    }
}

bool Input::GetMouseButtonDown(MouseButton mouseButton)
{
    switch (mouseButton)
    {
        case MouseButton::Left:
            return leftMouseButtonStatus.isDown;

        case MouseButton::Middle:
            return middleMouseButtonStatus.isDown;

        case MouseButton::Right:
            return rightMouseButtonStatus.isDown;

        default:
            // Unknown mouse button, so return false
            return false;
    }
}

bool Input::GetMouseButtonUp(MouseButton mouseButton)
{
    switch (mouseButton)
    {
        case MouseButton::Left:
            return leftMouseButtonStatus.isUp;

        case MouseButton::Middle:
            return middleMouseButtonStatus.isUp;

        case MouseButton::Right:
            return rightMouseButtonStatus.isUp;

        default:
            // Unknown mouse button, so return false
            return false;
    }
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