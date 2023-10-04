#include "platform.h"

namespace Entities
{
	namespace Obstacles
	{
		Platform::Platform(Math::CoordinateF position) : StaticEntity(position, Math::CoordinateF(PLATFORM_WIDTH, PLATFORM_HEIGHT), Entities::ID::platform)
		{
			initialize();
		}
	
		Platform::~Platform(){}

		void Platform::initialize()
		{
			sprite.initialize(PLATFORM_PATH, position, size);

		}

		void Platform::collide(Entity* other, Math::CoordinateF intersection){}
	}
		
}