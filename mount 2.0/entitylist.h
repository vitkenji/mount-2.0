#pragma once
#include "std.h"
#include "list.h"
#include "entity.h"

namespace List
{
	class EntityList
	{
	private:
		List<Entities::Entity> entitiesList;

	public:
		EntityList();
		~EntityList();
		void addEntity(Entities::Entity* pEntity);
		Entities::Entity* removeEntity(Entities::Entity* pEntity);
		Entities::Entity* removeEntity(unsigned int index);
		void deleteEntity(Entities::Entity* pENtity);
		void deleteEntity(unsigned int index);
		unsigned int getSize();
		Entities::Entity* operator[](int index);
		void clearList();

	};
}