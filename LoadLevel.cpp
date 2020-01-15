#include "stdafx.h"
#include "Engine.h"

void Engine::m_loadLevel()
{
	m_Playing = false;

	// delete previous allocated memory
	for (int i = 0; i < m_LvlM.getLevelSize().y; ++i)
	{
		delete[] m_ArrayLevel[i];
	}
	delete[] m_ArrayLevel;

	// Load the next 2d array with the map for the level
	// And repopulate the vertex array as well
	m_ArrayLevel = m_LvlM.nextLevel(m_VALevel);

	// How long is this new time limit
	m_TimeRemaining = m_LvlM.getTimeLimit();

	// Spawn Thomas and Bob
	m_Thomas.spawn(m_LvlM.getStartPosition(), GRAVITY);
	m_Bob.spawn(m_LvlM.getStartPosition(), GRAVITY);

	// Make sure this code isn't run again
	m_NewLvl = false;
}