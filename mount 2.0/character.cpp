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

		void Character::setIsAttacking(bool flag)
		{
			this->isAttacking = flag;

		}

		bool Character::getIsAttacking()
		{
			return isAttacking;

		}


	}
}