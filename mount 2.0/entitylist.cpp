#include "entitylist.h"

namespace List
{
	EntityList::EntityList() : entitiesList(){}

	EntityList::~EntityList()
	{
		entitiesList.clear();

	}

	void EntityList::addEntity(Entities::Entity* pEntity)
	{
		entitiesList.push(pEntity);

	}

	Entities::Entity* EntityList::removeEntity(Entities::Entity* pEntity)
	{
		return entitiesList.pop(pEntity);

	}

	Entities::Entity* EntityList::removeEntity(unsigned int index)
	{
		return entitiesList.pop(index);

	}

	void EntityList::deleteEntity(Entities::Entity* pEntity)
	{
		Entities::Entity* ptr = entitiesList.pop(pEntity);
	
		if (pEntity) { delete pEntity; }
		if (ptr) { delete ptr; }

	}
	void EntityList::deleteEntity(unsigned int index)
	{
		Entities::Entity* ptr = entitiesList.pop(index);
		if (ptr) { delete ptr; }

	}

	unsigned int EntityList::getSize()
	{
		return entitiesList.getSize();

	}

	Entities::Entity* EntityList::operator[](int index)
	{
		return entitiesList[index];

	}

	void EntityList::clearList()
	{
		entitiesList.clear();

	}
}