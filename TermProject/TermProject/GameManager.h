#pragma once
#include "Map.h"
#include "Character.h"
#include "Obstacle.h"
#include <time.h>
#include "EnemyController.h"

class GameManager
{
public:
	GameManager();		// Sets default values
	void StartGame();	// Start the game
	~GameManager();
	Map* GetMap() const;
	static GameManager* instance;//Singleton
	Node* GetCharacterNode();

private:
	// Data Declaration
	EnemyController* ec;
	bool bIsEnded;
	Map* map;
	Character* character;
	Obstacle* obstacleList;
	clock_t previousTime, currentTime;
	void MakeEnemies();
};