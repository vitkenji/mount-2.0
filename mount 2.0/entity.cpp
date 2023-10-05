#include "entity.h"

namespace Entities
{
	Entity::Entity(Math::CoordinateF position, Math::CoordinateF size, ID id): Ent(position, size), id(id)
	{
		body = new sf::RectangleShape;
		body->setPosition(sf::Vector2f(position.x, position.y));

	}

	ID Entity::getId() const
	{
		return this->id;

	}

	Entity::~Entity(){}

	
}