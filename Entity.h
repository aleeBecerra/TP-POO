#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;
using namespace System::Drawing;

class Entity
{
protected:
	int x;
	int dx;
	int height;
	int width;
	float y;
	float dy;

public:
	Entity(int x, float y, int dx, int height, int width);
	~Entity();

	virtual void erase() = 0;
	virtual void draw() = 0;

	Rectangle getRectangle();
};

