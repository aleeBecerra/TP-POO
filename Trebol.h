#pragma once
#include "Entity.h"
class Trebol : public Entity
{
private:
	int dy;
public:
	Trebol(int x, float y, int height, int width);
	~Trebol();
	void erase() override;
	void move();
	void draw() override;
};

