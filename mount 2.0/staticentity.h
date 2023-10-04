#pragma once
#include "entity.h"
#include "singleframeanimation.h"

namespace Entities
{
	class StaticEntity : public Entity
	{
	protected:
		GraphicalElements::SingleFrameAnimation sprite;

	public:
		StaticEntity(Math::CoordinateF position, Math::CoordinateF size, ID id);
		virtual ~StaticEntity();

		void render();
		virtual void initialize() = 0;
		virtual void update(const float dt){}
		virtual void collide(Entity* other, Math::CoordinateF intersection) {};
	};
}