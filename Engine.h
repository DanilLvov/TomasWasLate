#pragma once
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"
#include "LevelManager.h"

#include <SFML/Graphics.hpp>

using namespace sf;

class Engine
{
// private class objects
private:
	TextureHolder holder;
	RenderWindow m_Window;

	// Thomas and his friend, Bob
	Thomas m_Thomas;
	Bob m_Bob;

	// Main views
	View m_MainView;
	View m_LeftView;
	View m_RightView;

	// views for background
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;

	View m_HudView;

	// sprite and texture for the background
	Sprite m_BGSprite;
	Texture m_BGTexture;

	// level manager
	LevelManager m_LvlM;

	// private vertex array
	VertexArray m_VALevel;

	// Texture for our level
	Texture m_TextureTiles;

// private variables
private:
	// a double pointer for double array
	int** m_ArrayLevel = NULL;

	// vars for vertexes
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	
	// The force pushing the characters down
	const int GRAVITY = 300;

	// Bool variables
	// is game playeed
	bool m_Playing = false;

	// wich charachter is in focus
	bool m_Char_1 = true;

	// Start in full screen (not split) mode
	bool m_SplitScreen = false;

	// is it time to launch a new level
	bool m_NewLvl = true;

	// Time left in the current level (seconds)
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

// private functions
private:
	void m_input();
	void m_update(float dtAsSeconds);
	void m_draw();

	// level loading func
	void m_loadLevel();

// public functions
public:
	Engine();

	// run will call all private functions
	void run();
};

