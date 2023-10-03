#include "character.h"

namespace Entities
{
	namespace Characters
	{
		Character::Character(Math::CoordinateF position, Math::CoordinateF size, ID id, Math::CoordinateF velocity, int life): 
			MovingEntity(position, size, id, velocity), life(life)
		{}

		Character::~Character(){}

		void Character::setLife(int life)
		{
			this->life = life;

		}

		int Character::getLife()
		{
			return this->life;

		}

		const bool Character::getIsAttacking() const
		{
			return isAttacking;

		}


	}
}