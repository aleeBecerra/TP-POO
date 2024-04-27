#pragma once
#include "Entity.h"
#include "Murcielago.h"
#include "Monigote.h"
#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

class GameService
{
private:
	Monigote* monigote;
	Murcielago* murcielago;
	vector<Entity*> entities;

	time_t timeT;

public:
	GameService();
	~GameService();

	void addEntities();
	void deleteEntities();

	void eraseEntities();
	void moveEntities();
	void drawEntities();

	void resetGame();
	void endGame();



	void checkGameResult();
	void detectCollisions();


	Monigote* getMonigote();

};

