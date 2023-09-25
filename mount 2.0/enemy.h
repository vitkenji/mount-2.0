#pragma once
#include "std.h"
#include "character.h"

class Enemy
{
private:
	Math::CoordinateF position;
	Math::CoordinateF size;
public:
	sf::RectangleShape* body;

	Enemy();
	~Enemy() { body = nullptr; }
	void setPosition(Math::CoordinateF position);
	void setSize(Math::CoordinateF size);
	Math::CoordinateF getSize();
	Math::CoordinateF getPosition();

};

Enemy::Enemy()
{
	body = new sf::RectangleShape();
	this->position = Math::CoordinateF(80,80);
	this->size = Math::CoordinateF(80, 80);
	body->setPosition(sf::Vector2f(position.x, position.y));
	body->setSize(sf::Vector2f(position.x, position.y));
	body->setFillColor(sf::Color(12, 120, 12));
}


void Enemy::setPosition(Math::CoordinateF position) { this->position = position; }
void Enemy::setSize(Math::CoordinateF size) { this->size = size; }
Math::CoordinateF Enemy::getSize() { return size; }
Math::CoordinateF Enemy::getPosition() { return position; }

