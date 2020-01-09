#pragma once

#include "PlayableCharachter.h"

class Thomas : public PlayableCharachter
{
public:
	Thomas::Thomas();

	bool virtual handleInput();
};