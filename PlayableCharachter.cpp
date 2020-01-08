#include "stdafx.h"
#include "PlayableCharachter.h"

void PlayableCharachter::spawn(Vector2f startPosition, float gravity)
{
	m_Position = startPosition;
	m_Gravity = gravity;
	m_Sprite.setPosition(m_Position);
}

FloatRect PlayableCharachter::getHead()
{
	return m_Head;
}

FloatRect PlayableCharachter::getFeet()
{
	return m_Feet;
}

FloatRect PlayableCharachter::getLeft()
{
	return m_Left;
}

FloatRect PlayableCharachter::getRight()
{
	return m_Right;
}

Sprite PlayableCharachter::getSprite()
{
	return m_Sprite;
}

FloatRect PlayableCharachter::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Vector2f PlayableCharachter::getCenter()
{
	return m_Position;
}

void PlayableCharachter::stopLeft(float position)
{
	m_LeftPressed = false;
}

void PlayableCharachter::stopRight(float position)
{
	m_RightPressed = false;
}

void PlayableCharachter::stopFalling(float position)
{
	m_Position.y = position - getPosition().height;
	m_Sprite.setPosition(m_Position);
	m_IsFalling = false;
}

void PlayableCharachter::stopJump()
{
	m_IsJumping = false;
	m_IsFalling = true;
}

void PlayableCharachter::update(float elapsedTime)
{
	if (m_LeftPressed)
	{
		m_Position.x -= m_Speed * elapsedTime;
	}

	if (m_RightPressed)
	{
		m_Position.x += m_Speed * elapsedTime;
	}

	// Jumping
	if (m_IsJumping)
	{
		// Update how long the jump has been going
		m_TimeThisJump += elapsedTime;

		// Is the jump going upwards
		if (m_TimeThisJump < m_JumpDuration)
		{
			// Move up at twice gravity
			m_Position.y -= m_Gravity * 2 * elapsedTime;
		}
		else
		{
			m_IsJumping = false;
			m_IsFalling = true;
		}

		// Apply gravity
		if (m_IsFalling)
		{
			m_Position.y += m_Gravity * elapsedTime;
		}

		// Update the rect for all body parts
		FloatRect r = getPosition();

		// Feet
		m_Feet.left = r.left + 3;
		m_Feet.top = r.top + r.height - 1;
		m_Feet.width = r.width - 6;
		m_Feet.height = 1;

		// Head
		m_Head.left = r.left;
		m_Head.top = r.top + (r.height * .3);
		m_Head.width = r.width;
		m_Head.height = 1;

		// Right
		m_Right.left = r.left + r.width - 2;
		m_Right.top = r.top + r.height * .35;
		m_Right.width = 1;
		m_Right.height = r.height * .3;

		// Left
		m_Left.left = r.left;
		m_Left.top = r.top + r.height * .5;
		m_Left.width = 1;
		m_Left.height = r.height * .3;

		// Move the sprite into position
		m_Sprite.setPosition(m_Position);
	}
}
