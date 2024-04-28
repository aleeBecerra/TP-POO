#include "pch.h"
#include "Murcielago.h"


Murcielago::Murcielago(int x, float y, int dx, int height, int width)
	: Entity(x, y, dx, height, width) {
	dy = 0.1 + (float(rand() % 10001 + 10000) / RAND_MAX);

}

Murcielago::~Murcielago() {

}
int Murcielago::getX() {
	return x;
}
int Murcielago::getY() {
	return y;
}
int Murcielago::getWidth() {
	return x + width * 0.05;
}
int Murcielago::getHeight() {
	return y + height * 0.05;
}

char Murcielago::getDirection() {
	return this->direction;

}


void Murcielago::erase() {
	Console::SetCursorPosition(x, int(y)); cout << "                 ";
	Console::SetCursorPosition(x, int(y) + 1); cout << "                  ";
	Console::SetCursorPosition(x, int(y) + 2); cout << "                   ";
	Console::SetCursorPosition(x, int(y) + 3); cout << "                      ";

}

void Murcielago::move() {
	if (x < Console::WindowLeft+1  || x + width > Console::WindowWidth*0.7) {
		dx *= -1;
		direction == 80;
	}
	x += dx;
}

void Murcielago::draw() {
	Console::SetCursorPosition(x, int(y)); cout << "=,    (\\_/)   ,=" ;
	Console::SetCursorPosition(x, int(y) + 1); cout << " /'-'--('')--'-'\\";
	Console::SetCursorPosition(x, int(y) + 2); cout << " /     (___)     \\";
	Console::SetCursorPosition(x, int(y) + 3); cout << "/.-.-./ ' ' \\.-.-.\\";

}