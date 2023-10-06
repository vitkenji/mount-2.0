#include "collisionmanager.h"

namespace Managers
{
	CollisionManager::CollisionManager()
	{

	}

	CollisionManager::~CollisionManager()
	{

	}

	void CollisionManager::collide()
	{

		//static-moving
		for (int i = 0; i < staticEntities.getSize(); i++)
		{
			Math::CoordinateF distance; Math::CoordinateF intersection; Math::CoordinateF length;

			for (int j = 0; j < movingEntities.getSize(); j++)
			{
			
				distance.x = fabs(staticEntities[i]->getPosition().x - movingEntities[j]->getPosition().x);
				distance.y = fabs(staticEntities[i]->getPosition().y - movingEntities[j]->getPosition().y);

				length.x = (staticEntities[i]->getSize().x / 2) + (movingEntities[j]->getSize().x / 2);
				length.y = (staticEntities[i]->getSize().y / 2) + (movingEntities[j]->getSize().y / 2);

				if (length.x >= distance.x && length.y >= distance.y)
				{
					intersection = Math::CoordinateF(distance.x - length.x, distance.y - length.y);
					movingEntities[j]->collide(movingEntities[j], intersection);

				}
			}
		}

		//moving-moving
		for (int i = 0; i < movingEntities.getSize(); i++)
		{
			Math::CoordinateF distance; Math::CoordinateF intersection; Math::CoordinateF length;

			for (int j = 0; j < movingEntities.getSize(); j++)
			{

				distance.x = fabs(movingEntities[i]->getPosition().x - movingEntities[j]->getPosition().x);
				distance.y = fabs(movingEntities[i]->getPosition().y - movingEntities[j]->getPosition().y);

				length.x = (movingEntities[i]->getSize().x / 2) + (movingEntities[j]->getSize().x / 2);
				length.y = (movingEntities[i]->getSize().y / 2) + (movingEntities[j]->getSize().y / 2);

				if (length.x >= distance.x && length.y >= distance.y)
				{
					intersection = Math::CoordinateF(distance.x - length.x, distance.y - length.y);
					movingEntities[i]->collide(movingEntities[j], intersection);
					movingEntities[j]->collide(movingEntities[j], intersection);

				}
			}
		}

	}
}