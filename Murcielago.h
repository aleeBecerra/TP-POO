#pragma once
#include "Entity.h"

class Murcielago : public Entity
{
private:
	
public:
	Murcielago(int x, float y, int dx, int height, int width);
	~Murcielago();

	void erase() override;
	void move();
	void draw() override;
};

