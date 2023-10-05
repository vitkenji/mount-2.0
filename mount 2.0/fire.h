#pragma once
#include "std.h"
#include "movingentity.h"

namespace Entities
{
	namespace Obstacles
	{
		class Fire : public MovingEntity
		{
		private:
		public:
			Fire(Math::CoordinateF position);
			~Fire();
			
			void initialize();
			void update(const float dt);
			void collide(Entity* other, Math::CoordinateF intersection);
			void updateSprite(const float dt);
		};
	}
}

