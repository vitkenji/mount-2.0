#include "fire.h"

namespace Entities
{
	namespace Obstacles
	{
		Fire::Fire(Math::CoordinateF position) : MovingEntity(position, Math::CoordinateF(FIRE_WIDTH, FIRE_HEIGHT), Entities::ID::fire, Math::CoordinateF(0,0))
		{
			initialize();

		}
	
		Fire::~Fire(){}

		void Fire::initialize()
		{
			sprite.addNewAnimation(GraphicalElements::Animation_ID::idle, FIRE_LOOP_PATH, 8, 0.2);

		}

		void Fire::update(const float dt)
		{
			sprite.update(GraphicalElements::Animation_ID::idle, isFacingLeft(), position, dt);

		}

		void Fire::collide(Entity* other, Math::CoordinateF intersection)
		{

		}

		void Fire::updateSprite(const float dt)
		{

		}
	}
}