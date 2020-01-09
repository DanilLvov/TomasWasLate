#include "stdafx.h"
#include "Engine.h"

using namespace sf;

void Engine::m_draw()
{
	// clear previous frame
	m_Window.clear(Color::White);

	if (!m_SplitScreen)
	{
		// Switch to background view
		m_Window.setView(m_BGMainView);

		// Draw the background
		m_Window.draw(m_BGSprite);

		// Switch to m_MainView
		m_Window.setView(m_MainView);

		// Draw chars
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());

	}
	else
	{
		// split screen is activated
		// drawing left side of the screen

		// Switch to background view
		m_Window.setView(m_BGLeftView);

		// Draw the background
		m_Window.draw(m_BGSprite);

		// Switch to m_MainView
		m_Window.setView(m_LeftView);

		// Draw chars
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());

		// drawing right side of the screen

		// Switch to background view
		m_Window.setView(m_BGRightView);

		// Draw the background
		m_Window.draw(m_BGSprite);

		// Switch to m_MainView
		m_Window.setView(m_RightView);

		// Draw chars
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());
	}

	// switching to Hud
	m_Window.setView(m_HudView);

	m_Window.display();
}