// This file is used in a unit testing project which tests the classes and ensures that
// everything runs as intended.
//
// Done by Brandon Gui (p1828865) from DIT/FT/2B/05.

#pragma once

#include "CanSpeak.h"               // for abstract class CanSpeak

#include "../IGRA_CA2/Component.h"  // for base class Component in IGRA CA2 project
#include "../IGRA_CA2/GameObject.h" // for class GameObject in IGRA CA2 project

class SpeakerComponent : public Component, public CanSpeak
{
public:
    SpeakerComponent(GameObject &go);
    ~SpeakerComponent();

    void Speak();
};
