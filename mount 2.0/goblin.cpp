#include "goblin.h"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			Goblin::Goblin(Math::CoordinateF position) : Enemy(position, Math::CoordinateF(GOBLIN_SIZE_X, GOBLIN_SIZE_Y), goblin, Math::CoordinateF(0,0), 1000)
			{
				initialize();
			}

			Goblin::~Goblin()
			{

			}

			void Goblin::walk(bool left)
			{
				setIsWalking(true);
				velocity.x = -40;
				if (!left)
				{
					velocity.x *= -1;
					setFacingLeft(false);

				}
			}

			void Goblin::initialize()
			{
				sprite.addNewAnimation(GraphicalElements::Animation_ID::idle, GOBLIN_IDLE_PATH, 4, 0.3);
				sprite.addNewAnimation(GraphicalElements::Animation_ID::run, GOBLIN_RUN_PATH, 8, 0.3);
				sprite.addNewAnimation(GraphicalElements::Animation_ID::attack, GOBLIN_ATTACK_PATH, 12, 0.3);	
				sprite.addNewAnimation(GraphicalElements::Animation_ID::death, GOBLIN_DEATH_PATH, 4, 0.4);
				sprite.addNewAnimation(GraphicalElements::Animation_ID::takeHit, GOBLIN_TAKEHIT_PATH, 4, 0.3);

			}

			void Goblin::update(const float dt)
			{
				updateSprite(dt);

			}

			void Goblin::updateSprite(const float dt)
			{
				sprite.update(GraphicalElements::Animation_ID::idle, isFacingLeft(), position, dt);

			}

			void Goblin::collide(Entity* other, Math::CoordinateF intersection) {}

		}
	}
}