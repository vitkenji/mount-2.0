#pragma once
#include "std.h"
#include "enemy.h"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			class Goblin : public Enemy
			{
			private:

			public:
				Goblin(Math::CoordinateF position);
				~Goblin();

				void initialize();
				void update(const float dt);
				void collide(Entity* other, Math::CoordinateF intersection);
				void updateSprite(const float dt);
			};
		}
	}
}