#pragma once
#include "std.h"
#include "ent.h"

namespace Entities
{
	enum ID
	{
		empty = 0,
		player = 1,
		goblin = 2,
		skeleton = 3,
		boss = 4,
		platform = 5,
		fire = 6,
	};

	class Entity : public Ent
	{

	protected:
		sf::RectangleShape* body;
		sf::Texture* texture;
		ID id;

	public:
		Entity(Math::CoordinateF position, Math::CoordinateF size, ID id);
		virtual ~Entity();
		ID getId() const;

		virtual void render() = 0;
		virtual void initialize() = 0;
		virtual void update(const float dt) = 0;
		virtual void collide(Entity* other, Math::CoordinateF intersection) = 0;

	};
}