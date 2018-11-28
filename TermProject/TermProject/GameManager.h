#pragma once
#include "Map.h"
#include "Character.h"
#include "Obstacle.h"
#include <time.h>
#include "EnemyController.h"

class GameManager
{
public:
	GameManager(Map* gotMap);		// Sets default values
	void StartGame();	// Start the game
	~GameManager();
	Map* GetMap() const;
	static GameManager* instance;//Singleton
	Node* GetCharacterNode() const;
	void DecreaseLife();
	void GameWin();
	void GameOver();
	void ResetPosition();

private:
	// Data Declaration
	EnemyController* ec;
	bool bIsEnded;
	bool bWin;	// 0 : lose, 1 : win
	Map* map;
	Character* character;
	//Obstacle* obstacleList;
	clock_t previousTime, currentTime;
	void MakeEnemies();
};