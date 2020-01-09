#pragma once

#include <SFML\Graphics.hpp>

using namespace sf;

class PlayableCharachter
{
protected:
	Sprite m_Sprite;

	float m_JumpDuration;

	// Current state of charachter
	bool m_IsFalling;
	bool m_IsJumping;

	// Direction, in which our charachter moves
	bool m_LeftPressed;
	bool m_RightPressed;

	// Duration of current jump
	float m_TimeThisJump;

	// Has our player just jumped
	bool m_JustJumped = false;

private:
	float m_Gravity;

	float m_Speed = 400;

	// position of a player
	Vector2f m_Position;

	// positions of body parts
	FloatRect m_Head;
	FloatRect m_Feet;
	FloatRect m_Left;
	FloatRect m_Right;

	Texture m_Texture;

public:
	void spawn(Vector2f startPosition, float gravity);

	// virtual input function
	bool virtual handleInput() = 0;

	

	// getters
	Sprite getSprite();

	FloatRect getPosition();

	FloatRect getHead();
	FloatRect getFeet();
	FloatRect getLeft();
	FloatRect getRight();

	Vector2f getCenter();

	// Stopper funcs
	void stopLeft(float position);
	void stopRight(float position);
	void stopFalling(float position);
	void stopJump();

	void update(float elapsedTime);
};

