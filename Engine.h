#pragma once

#include "TextureHolder.h"

class Engine
{
// private class objects
private:
	TextureHolder holder;
	sf::RenderWindow m_Window;

	// Main views
	sf::View m_MainView;
	sf::View m_LeftView;
	sf::View m_RightView;

	// views for background
	sf::View m_BGMainView;
	sf::View m_BGLeftView;
	sf::View m_BGRightView;

	sf::View m_HudView;


// private variables
private:

	// vars for vertexes
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	
	// The force pushing the characters down
	const int GRAVITY = 300;

// private functions

// public functions
public:
	Engine();

};

