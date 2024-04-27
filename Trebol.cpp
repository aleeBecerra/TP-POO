#include "pch.h"
#include "Trebol.h"


Trebol::Trebol(int x, float y, int height, int width)
	: Entity(x, y, dx, height, width) {
}

Trebol::~Trebol() {}

void Trebol::erase() {}

void Trebol::move() {}

void Trebol::draw() {
	Console::SetCursorPosition(x, int(y));
	cout << "@";
}