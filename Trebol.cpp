#include "pch.h"
#include "Trebol.h"


Trebol::Trebol(int x, float y, int height, int width)
	: Entity(x, y, 0, height, width) {
	dy = 1;
}

Trebol::~Trebol() {}



void Trebol::erase() {
	Console::SetCursorPosition(x, int(y));

	cout << " ";
}

void Trebol::move() {
	if (y + height < Console::WindowHeight) {
		y += dy;

	}


}
void Trebol::draw() {
	Console::SetCursorPosition(x, int(y));
	cout << "@";
}