#include "pch.h"
#include "Entity.h"

Entity::Entity(int x, float y, int dx, int height, int width) {
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->height = height;
	this->width = width;
}

Entity::~Entity() {

}

Rectangle Entity::getRectangle() {
	return Rectangle(x, y, width, height);
}