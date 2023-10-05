#include "enemy.h"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			Enemy::Enemy(Math::CoordinateF position, Math::CoordinateF size, ID id, Math::CoordinateF velocity, int life) : Character(position, size, id, velocity, life)
			{

			}

			Enemy::~Enemy()
			{

			}

			
		}
	}
}