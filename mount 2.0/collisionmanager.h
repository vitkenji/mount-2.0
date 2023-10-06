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
		List::EntityList movingEntities;
		List::EntityList staticEntities;

	public:
		CollisionManager();
		~CollisionManager();
		void collide();
		void clear();
	};
}