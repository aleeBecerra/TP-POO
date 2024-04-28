#include "pch.h"
#include "Monigote.h"

Monigote::Monigote(int x, float y, int dx, int height, int width, int lives)
	: Entity(x, y, dx, height, width)
{
	this->dy = 2;
	this->lives = lives;
	this->trebolsCollected = 0;
	this->heartsCollected = 0;
}

Monigote::~Monigote() {

}

void Monigote::setY(float y) {
	this->y = y;
}

float Monigote::getX() {
	return this->x;
}

void Monigote::setX(int x) {
	this->x = x;
}

void Monigote::setLives(int lives) {
	this->lives = lives;
}

void Monigote::setTrebolsCollected(int trebolsCollected) {
	this->trebolsCollected = trebolsCollected;
}

void Monigote::setHeartsCollected(int heartsCollected) {
	this->heartsCollected = heartsCollected;
}

int Monigote::getLives() {
	return this->lives;
}

int Monigote::getTrebolsCollected() {
	return this->trebolsCollected;
}

int Monigote::getHeartsCollected() {
	return this->heartsCollected;
}

void Monigote::substractLive() {
	this->lives--;
}

void Monigote::addLives() {
	this->lives++;
}

void Monigote::collectedTrebols() {
	this->trebolsCollected++;
}

void Monigote::collectedsHearts() {
	this->heartsCollected++;
}

void Monigote::erase() {
	Console::SetCursorPosition(x, int(y)); cout << "        ";
	Console::SetCursorPosition(x, int(y) + 1); cout << "     ";
	Console::SetCursorPosition(x, int(y) + 2); cout << "     ";
}

void Monigote::move(char key) {
	switch (key) {
	case 75:
		if (x > Console::WindowLeft + 2)
			x -= dx;
		break;
	case 80:
		if (y + height < Console::WindowHeight)
			y += dy;
		break;
	case 77:
		if (x + width < Console::WindowWidth)
			x += dx;
		break;
	case 72:
		if (y > Console::WindowTop)
			y -= dy;
		break;
	}
}

void Monigote::draw() {
	Console::ForegroundColor = ConsoleColor::Green;
	Console::SetCursorPosition(x, int(y)); cout << " O    ";
	Console::SetCursorPosition(x, int(y) + 1); cout << " | " ;
	Console::SetCursorPosition(x, int(y) + 2); cout << " -- ";
}