#pragma once
#include "std.h"
#include "enemy.h"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			class Skeleton : public Enemy
			{
			private:

			public:
				Skeleton(Math::CoordinateF position);
				~Skeleton();
				
				void walk(bool left);
				void initialize();
				void update(const float dt);
				void updateSprite(const float dt);
			};
		}
	}
}