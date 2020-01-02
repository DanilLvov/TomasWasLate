// Include important C++ libraries here
#include "stdafx.h"

int main()
{
	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	sf::VideoMode vm(resolution.x, resolution.y);
	sf::RenderWindow window(vm, "TWL", sf::Style::Fullscreen);
	return 0;
}

