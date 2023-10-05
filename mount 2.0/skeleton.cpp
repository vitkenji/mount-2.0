#include "skeleton.h"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			Skeleton::Skeleton(Math::CoordinateF position) : Enemy(position, Math::CoordinateF(SKELETON_SIZE_X, SKELETON_SIZE_Y), Entities::ID::skeleton, Math::CoordinateF(0,0), 1000)
			{
				initialize();
				walk(false);
				setFacingLeft(true);
			}

			Skeleton::~Skeleton()
			{

			}

			void Skeleton::walk(bool left)
			{
				setIsWalking(true);
				velocity.x = -10;
				if (!left)
				{
					velocity.x *= -1;
					setFacingLeft(false);

				}
			}

			void Skeleton::initialize()
			{
				sprite.addNewAnimation(GraphicalElements::Animation_ID::idle, SKELETON_IDLE_PATH, 4, 0.3);
				sprite.addNewAnimation(GraphicalElements::Animation_ID::run, SKELETON_RUN_PATH, 4, 0.3);
				sprite.addNewAnimation(GraphicalElements::Animation_ID::attack, SKELETON_ATTACK_PATH, 8, 0.3);
				sprite.addNewAnimation(GraphicalElements::Animation_ID::death, SKELETON_DEATH_PATH, 4, 0.3);
				sprite.addNewAnimation(GraphicalElements::Animation_ID::takeHit, SKELETON_TAKEHIT_PATH, 4, 0.3);
				
			}

			void Skeleton::update(const float dt)
			{
				if (getIsWalking())
				{
					position.x += velocity.x * dt;
					if (position.x >= 850) { velocity.x = 0; setIsWalking(false); }
				}

				updateSprite(dt);

			}

			void Skeleton::collide(Entity* other, Math::CoordinateF intersection){}
			
			void Skeleton::updateSprite(const float dt)
			{
				if(getIsWalking())
				{
					if (isFacingLeft()) { sprite.update(GraphicalElements::Animation_ID::run, isFacingLeft(), position, dt); }
					else { sprite.update(GraphicalElements::Animation_ID::run, isFacingLeft(), position, dt); }

				}

				if (isAttacking)
				{
					sprite.update(GraphicalElements::Animation_ID::attack, isFacingLeft(), position, dt);

				}

				else if (!getIsWalking()) { sprite.update(GraphicalElements::Animation_ID::idle, isFacingLeft(), position, dt); }
				
			}
		}
	}
}