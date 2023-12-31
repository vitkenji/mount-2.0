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
				
				void walk(bool left);
				void initialize();
				void update(const float dt);
				void updateSprite(const float dt);
			};
		}
	}
}