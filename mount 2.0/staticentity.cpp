#include "staticentity.h"

namespace Entities
{
	StaticEntity::StaticEntity(Math::CoordinateF position, Math::CoordinateF size, ID id) : Entity(position, size, id), sprite(){}

	StaticEntity::~StaticEntity(){}

	void StaticEntity::render()
	{
		sprite.render();
	}


}