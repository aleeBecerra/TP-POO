#pragma once
#include "Entity.h"
class Heart : public Entity
{
private:

public:
	Heart(int x, float y, int height, int width);
	~Heart();

	void erase() override;
	void move();
	void draw() override;
};

