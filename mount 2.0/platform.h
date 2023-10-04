#pragma once
#include "std.h"
#include "staticentity.h"

namespace Entities
{
	namespace Obstacles
	{
		class Platform : public StaticEntity
		{
		private:

		public:
			Platform(Math::CoordinateF position);
			~Platform();
			void initialize();
			void collide(Entity* other, Math::CoordinateF intersection);
		};
	}
}
