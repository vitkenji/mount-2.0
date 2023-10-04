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
			bool isAttacking;

		public:
			Character(Math::CoordinateF position, Math::CoordinateF size, ID id, Math::CoordinateF velocity, int life);
			~Character();
			void setLife(int life);
			int getLife();
			void setIsAttacking(bool flag);
		    bool getIsAttacking();

			virtual void initialize() = 0;
			virtual void update(const float dt) = 0;
			virtual void collide(Entity* other, Math::CoordinateF intersection) = 0;
			virtual void updateSprite(const float dt) = 0;
		};
	}
}