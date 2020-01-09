#include "stdafx.h"
#include "Engine.h"

#include <sstream>

using namespace sf;

void Engine::m_update(float dtAsSeconds)
{
	if (m_NewLvl)
	{
		// These calls to spawn will be moved to a new
		// loadLevel() function soon
		// Spawn Thomas and Bob
		m_Thomas.spawn(Vector2f(0, 0), GRAVITY);
		m_Bob.spawn(Vector2f(100, 0), GRAVITY);
		// Make sure spawn is called only once
		m_TimeRemaining = 10;
		m_NewLvl = false;
	}

	if (m_Playing)
	{
		// Count down the time the player has left
		m_TimeRemaining -= dtAsSeconds;

		// Update Thomas
		m_Thomas.update(dtAsSeconds);

		// Update Bob
		m_Bob.update(dtAsSeconds);

		// Have Thomas and Bob run out of time?
		if (m_TimeRemaining <= 0)
		{
			m_NewLvl = true;
		}
	}// End if playing

	// Set the appropriate view around the appropriate character
	if (m_SplitScreen)
	{
		m_LeftView.setCenter(m_Thomas.getCenter());
		m_RightView.setCenter(m_Bob.getCenter());
	}
	else
	{
		// Centre full screen around appropriate character
		if (m_Char_1)
		{
			m_MainView.setCenter(m_Thomas.getCenter());
		}
		else
		{
			m_MainView.setCenter(m_Bob.getCenter());
		}
	}
}