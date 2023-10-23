#include "character.h"

namespace Entities
{
	namespace Characters
	{
		Character::Character(Math::CoordinateF position, Math::CoordinateF size, ID id, Math::CoordinateF velocity, int life) :
			MovingEntity(position, size, id, velocity), life(life), attackCooldown(0), attackedCooldown(0), active(true)
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

		void Character::setIsWalking(bool flag)
		{
			this->isWalking = flag;

		}


		bool Character::getIsWalking()
		{
			return isWalking;

		}

		void Character::setWasAttacked(bool flag)
		{
			this->wasAttacked = flag;

		}

		bool Character::getWasAttacked()
		{
			return wasAttacked;
		}

		void Character::restartSprite(const float dt, float animationTime)
		{
			if (getWasAttacked())
			{
				attackedCooldown += dt;
				if (attackedCooldown >= animationTime)
				{
					attackedCooldown = 0;
					setWasAttacked(false);
				}
			}
		}

		void Character::setActive(bool flag)
		{
			this->active = flag;

		}

		bool Character::getActive()
		{
			return active;

		}
	}
}