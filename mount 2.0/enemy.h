#pragma once
#include "std.h"
#include "character.h"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			class Enemy : public Character
			{
			protected:
				
			public:
				Enemy(Math::CoordinateF position, Math::CoordinateF size, ID id, Math::CoordinateF velocity, int life);
				~Enemy();

				virtual void initialize() = 0;
				virtual void update(const float dt) = 0;
				virtual void collide(Entity* other, Math::CoordinateF intersection) = 0;
				virtual void updateSprite(const float dt) = 0;

			};
		}
	}
}
