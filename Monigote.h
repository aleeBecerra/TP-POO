#pragma once
#include "Entity.h"

class Monigote : public Entity
{
private:
	int lives;
	int trebolsCollected;
	int heartsCollected;
public:
	Monigote(int x, float y, int dx, int height, int width, int lives);
	~Monigote();

	void setY(float y);
	float getX();
	void setX(int x);
	int getLives();
	int getTrebolsCollected();
	int getHeartsCollected();
	void setLives(int lives);
	void setTrebolsCollected(int trebolCollected);
	void setHeartsCollected(int heartsCollected);
	void addLives();
	void substractLive();
	void collectedTrebols();
	void collectedsHearts();
	void erase() override;
	void move(char key);
	void draw() override;
};


