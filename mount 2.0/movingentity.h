#pragma once
#include "std.h"
#include "entity.h"
#include "multiframeanimation.h"

namespace Entities
{
	class MovingEntity : public Entity
	{
	protected:
		Math::CoordinateF velocity;
		bool active;
		bool facingLeft;
		unsigned int damage;
		GraphicalElements::MultiFrameAnimation sprite;

	public:
		MovingEntity(Math::CoordinateF position, Math::CoordinateF size, ID id, Math::CoordinateF velocity);
		~MovingEntity();
		void setVelocity(Math::CoordinateF velocity);
		Math::CoordinateF getVelocity() const;
		void setActive(const bool active);
		const bool isActive() const;
		void setFacingLeft(const bool facingLeft);
		const bool isFacingLeft() const;
		void setDamage(unsigned int damage);
		unsigned int getDamage() const;
		//void moveOnCollision(Entity* other, Math::CoordinateF intersection);

		virtual void render();
		virtual void initialize() = 0;
		virtual void update(const float dt) = 0;
		virtual void collide(Entity* other, Math::CoordinateF intersection) = 0;
		virtual void updateSprite(const float dt) = 0;

	};
}