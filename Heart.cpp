#include "pch.h"
#include "Heart.h"


Heart::Heart(int x, float y, int height, int width)
	: Entity(x, y, 0, height, width) {
	dy = 1;
}

Heart::~Heart() {}


void Heart::erase() {
	Console::SetCursorPosition(x, int(y));
	cout << " ";
}


void Heart::move() {
	if (y + height < Console::WindowHeight) {
		y += dy;

	}
	if (y + height*0.5 >= Console::WindowHeight) {
		erase();
	}
	
}

void Heart::draw() {
	Console::SetCursorPosition(x, int(y));
	cout << "&";
}