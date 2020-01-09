#pragma once

#include "PlayableCharachter.h"

class Bob : public PlayableCharachter
{

public:
	// A constructor specific to Bob
	Bob::Bob();

	// The overriden input handler for Bob
	bool virtual handleInput();
};
