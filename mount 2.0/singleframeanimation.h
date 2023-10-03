#pragma once
#include "std.h"
#include "animation.h"

namespace GraphicalElements
{
	class SingleFrameAnimation : public Animation
	{
	private:
		sf::Texture* texture;

	public:
		SingleFrameAnimation();
		virtual ~SingleFrameAnimation();
		void initialize(const char* path, Math::CoordinateF position, Math::CoordinateF size);
		void update(Math::CoordinateF position);

	};
}