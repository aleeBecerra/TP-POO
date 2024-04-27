#include "pch.h"
#include "Heart.h"


Heart::Heart(int x, float y, int height, int width)
	: Entity(x, y, dx, height, width) {
}

Heart::~Heart() {}

void Heart::erase() {}

void Heart::move() {}

void Heart::draw() {
	Console::SetCursorPosition(x, int(y));
	cout << "&";
}