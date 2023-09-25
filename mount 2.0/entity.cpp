#include "entity.h"

namespace Entities
{
	Entity::Entity(Math::CoordinateF position, Math::CoordinateF size, ID id): Ent(position, size), id(id){}

	ID Entity::getId() const
	{
		return this->id;

	}

	Entity::~Entity(){}

	
}