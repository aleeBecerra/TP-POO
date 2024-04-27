#pragma once
#include "Entity.h"

class Monigote : public Entity
{
private:
	int lives;
	int heartCollected;
public:
	Monigote(int x, float y, int dx, int height, int width, int lives);
	~Monigote();

	void setY(float y);
	float getX();
	void setX(int x);
	int getLives();
	int getHeartsCollected();
	void setLives(int lives);
	void setHeartsCollected(int heartCollected);
	void substractLive();
	void collectedHearts();
	void erase() override;
	void move(char key);
	void draw() override;
};


