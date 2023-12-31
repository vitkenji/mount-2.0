#include "movingentity.h"

namespace Entities
{

	MovingEntity::MovingEntity(Math::CoordinateF position, Math::CoordinateF size, ID id, Math::CoordinateF velocity): Entity(position, size, id), 
		velocity(velocity), facingLeft(false), active(false), damage(0), sprite(){}

	MovingEntity::~MovingEntity(){}

	void MovingEntity::setVelocity(Math::CoordinateF velocity)
	{
		this->velocity = velocity;

	}

	Math::CoordinateF MovingEntity::getVelocity() const
	{
		return this->velocity;

	}

	void MovingEntity::setActive(const bool active)
	{
		this->active = active;

	}

	const bool MovingEntity::isActive() const
	{
		return this->active;

	}

	void MovingEntity::setFacingLeft( bool facingLeft)
	{
		this->facingLeft = facingLeft;

	}

	bool MovingEntity::isFacingLeft()
	{
		return this->facingLeft;

	}

	void MovingEntity::setDamage(unsigned int damage)
	{
		this->damage = damage;

	}

	unsigned int MovingEntity::getDamage() const
	{
		return damage;

	}

	void MovingEntity::render()
	{
		sprite.render();

	}
}