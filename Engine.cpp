#include "stdafx.h"
#include "Engine.h"

Engine::Engine()
{
	// creating window and views
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	VideoMode vm(resolution.x, resolution.y);
	m_Window.create(vm, "TWL", Style::Default);

	// Initialize the main view
	m_MainView.setSize(resolution);
	m_HudView.reset(
		FloatRect(0, 0, resolution.x, resolution.y));

	// Initialize the split-screen Views
	m_LeftView.setViewport(
		FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_RightView.setViewport(
		FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
	m_BGLeftView.setViewport(
		FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_BGRightView.setViewport(
		FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	// load BG texture
	m_BGTexture = TextureHolder::GetTexture("graphics/background.png");

	// Associate the sprite with the texture
	m_BGSprite.setTexture(m_BGTexture);
}

void Engine::run()
{
	Clock clock;

	while (m_Window.isOpen())
	{
		Time dt = clock.restart();

		// Update the total game time
		m_GameTimeTotal += dt;

		// Make a decimal fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		m_input();
		m_update(dtAsSeconds);
		m_draw();
	}
}

