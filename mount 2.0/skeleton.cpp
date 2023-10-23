#include "skeleton.h"
#include "player.h"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			Skeleton::Skeleton(Math::CoordinateF position) : Enemy(position, Math::CoordinateF(SKELETON_SIZE_X, SKELETON_SIZE_Y), Entities::ID::skeleton, Math::CoordinateF(0,0), 1000)
			{
				initialize();
				walk(true);
				setFacingLeft(false);
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
				sprite.addNewAnimation(GraphicalElements::Animation_ID::death, SKELETON_DEATH_PATH, 4, 0.5);
				sprite.addNewAnimation(GraphicalElements::Animation_ID::takeHit, SKELETON_TAKEHIT_PATH, 4, 0.3);
				
			}

			void Skeleton::update(const float dt)
			{
				if (getIsWalking())
				{
					position.x += velocity.x * dt;
				}

				position.y += velocity.y + (GRAVITY * dt * dt / 2.0f);
				velocity.y += GRAVITY * dt;

				updateSprite(dt);

			}

			void Skeleton::collide(Entity* other, Math::CoordinateF intersection)
			{
				if (other->getId() == player)
				{
					setIsWalking(false);
					setIsAttacking(true);
					if (intersection.x <= 0)
					{
						velocity.x = 0;
						if (this->pPlayer->getIsAttacking()) { this->life -= 1; }
					}
				}

				if (intersection.y <= 0)
				{
					this->velocity.y = 0;
				}

				if (this->life <= 0)
				{
					setActive(false);

				}

			}
			
			void Skeleton::updateSprite(const float dt)
			{
				if (getActive())
				{
						if (getWasAttacked() && !getIsAttacking()) { sprite.update(GraphicalElements::Animation_ID::takeHit, isFacingLeft(), position, dt); }
						if (getIsWalking() && !getIsAttacking()) { sprite.update(GraphicalElements::Animation_ID::run, isFacingLeft(), position, dt); }


						if (getIsAttacking()) { sprite.update(GraphicalElements::Animation_ID::attack, isFacingLeft(), position, dt); }

						if (!getIsWalking() && !getIsAttacking() && !getWasAttacked()) { sprite.update(GraphicalElements::Animation_ID::idle, isFacingLeft(), position, dt); }
				}
				else
				{
					sprite.update(GraphicalElements::Animation_ID::death, isFacingLeft(), position, dt);

				}

			}
		}
	}
}