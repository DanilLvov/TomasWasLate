#include "stdafx.h"
#include "LevelManager.h"


LevelManager::LevelManager()
{
}

int ** LevelManager::nextLevel(VertexArray & rVaLevel)
{
	m_LevelSize.x = 0;
	m_LevelSize.y = 0;

	m_CurrentLevel++;

	if (m_CurrentLevel > 4)
	{
		m_CurrentLevel = 1;
		m_TimeModifier -= .1f;
	}

	string level;
	switch (m_CurrentLevel)
	{
	case 1:
		level = "levels/level1.txt";
		m_StartPosition.x = 100;
		m_StartPosition.y = 100;
		m_BaseTimeLimit = 30.0f;
		break;
	case 2:
		level = "levels/level2.txt";
		m_StartPosition.x = 100;
		m_StartPosition.y = 3600;
		m_BaseTimeLimit = 100.0f;
		break;
	case 3:
		level = "levels/level3.txt";
		m_StartPosition.x = 1250;
		m_StartPosition.y = 0;
		m_BaseTimeLimit = 30.0f;
		break;
	case 4:
		level = "levels/level4.txt";
		m_StartPosition.x = 50;
		m_StartPosition.y = 200;
		m_BaseTimeLimit = 50.0f;
		break;
	} // end switch

	ifstream inputFile(level);
	string s;

	// Count the number of rows in the file
	while (getline(inputFile, s))
	{
		++m_LevelSize.y;
	}
	// Store the length of the rows
	m_LevelSize.x = s.length();

	// Go back to the start of the file
	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	// Prepare the 2D array to hold the int values from the file
	int** arrayLevel = new int*[m_LevelSize.y];
	for (int i = 0; i < m_LevelSize.y; ++i)
	{
		// Add a new array into each array element
		arrayLevel[i] = new int[m_LevelSize.x];
	}

	// Loop through the file and store all
	// the values in the 2d array
	string row;
	int y = 0;
	while (inputFile >> row)
	{
		for (int x = 0; x < row.length(); x++)
		{
			const char val = row[x];
			arrayLevel[y][x] = atoi(&val);
		}
		y++;
	}

	inputFile.close();

	// Now we are adding lvl graphics
	// Initialization of vertex array
	rVaLevel.setPrimitiveType(Quads);

	// setting size
	rVaLevel.resize(m_LevelSize.x * m_LevelSize.y * VERTS_IN_QUAD);

	int currentVertex = 0;

	for (int x = 0; x < m_LevelSize.x; x++)
	{
		for (int y = 0; y < m_LevelSize.y; y++)
		{
			rVaLevel[currentVertex + 0].position = Vector2f(x * TILE_SIZE, y * TILE_SIZE);
			rVaLevel[currentVertex + 1].position = Vector2f(x * TILE_SIZE + TILE_SIZE, y * TILE_SIZE);
			rVaLevel[currentVertex + 2].position = Vector2f(x * TILE_SIZE + TILE_SIZE, y * TILE_SIZE + TILE_SIZE);
			rVaLevel[currentVertex + 3].position = Vector2f(x * TILE_SIZE, y * TILE_SIZE + TILE_SIZE);

			// Chosing wich tile should we use
			int verticalOffset = arrayLevel[y][x] * TILE_SIZE;

			// Asociating textures
			rVaLevel[currentVertex + 0].texCoords = Vector2f(0, verticalOffset + 0);
			rVaLevel[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, verticalOffset + 0);
			rVaLevel[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, verticalOffset + TILE_SIZE);
			rVaLevel[currentVertex + 3].texCoords = Vector2f(0, verticalOffset + TILE_SIZE);

			// moving to the next vertex
			currentVertex += VERTS_IN_QUAD;
		}
	}

	return arrayLevel;
} // end of NextLevel function

Vector2i LevelManager::getLevelSize()
{
	return m_LevelSize;
}

int LevelManager::getCurrentLevel()
{
	return m_CurrentLevel;
}

float LevelManager::getTimeLimit()
{
	return m_BaseTimeLimit * m_TimeModifier;
}

Vector2f LevelManager::getStartPosition()
{
	return m_StartPosition;
}


