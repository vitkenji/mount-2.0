#include "enemy.h"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			Enemy::Enemy(Math::CoordinateF position, Math::CoordinateF size, ID id, Math::CoordinateF velocity, int life) : Character(position, size, id, velocity, life), pPlayer(pPlayer)
			{

			}

			Enemy::~Enemy()
			{

			}

			void Enemy::collide(Entity* other, Math::CoordinateF intersection)
			{
				if (other->getId() == player)
				{
					if (intersection.x <= 0)
					{
						velocity.x = 0;
						this->life -= 1;

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
		
			void Enemy::setPlayer(Player* pPlayer)
			{
				this->pPlayer = pPlayer;

			}
		}
	}
}