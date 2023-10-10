#pragma once
#include "std.h"
#include "movingentity.h"
#include "staticentity.h"
#include "entitylist.h"

namespace Managers
{
	class CollisionManager
	{
	private:
		List::EntityList* movingEntities;
		List::EntityList* staticEntities;

	public:
		CollisionManager(List::EntityList* movingEntities, List::EntityList* staticEntities);
		~CollisionManager();
		void collide();
		void clear();
	};
}