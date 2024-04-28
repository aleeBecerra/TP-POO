#pragma once
#include "Entity.h"

class Murcielago : public Entity
{
private:
	char direction;
public:
	Murcielago(int x, float y, int dx, int height, int width);
	~Murcielago();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	char getDirection();
	void erase() override;
	void move();
	void draw() override;
};

