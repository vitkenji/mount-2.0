#pragma once
#include "movingentity.h"

namespace Entities
{
	namespace Characters
	{
		class Character : public MovingEntity
		{
		protected:
			int life;
			float attackCooldown;
			float attackedCooldown;
			bool isAttacking;
			bool wasAttacked;
			bool isWalking;
			bool active;

		public:
			Character(Math::CoordinateF position, Math::CoordinateF size, ID id, Math::CoordinateF velocity, int life);
			~Character();

			void setLife(int life);
			int getLife();
			
			void setIsAttacking(bool flag);
		    bool getIsAttacking();
			
			void setIsWalking(bool flag);
			bool getIsWalking();
			
			void setWasAttacked(bool flag);
			bool getWasAttacked();
			
			void setActive(bool flag);
			bool getActive();

			void restartSprite(const float dt, float animationTime);

			virtual void walk(bool left) = 0;
			virtual void initialize() = 0;
			virtual void update(const float dt) = 0;
			virtual void collide(Entity* other, Math::CoordinateF intersection) = 0;
			virtual void updateSprite(const float dt) = 0;

		};
	}
}