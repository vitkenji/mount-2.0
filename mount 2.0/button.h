#pragma once
#include "std.h"
#include "text.h"
#include "animation.h"

namespace GraphicalElements
{
	class Button : public Animation
	{
	private:
		Text text;
		sf::Texture* defaultTexture;
		sf::Texture* selectedTexture;

	public:
		Button(Math::CoordinateF position, std::string info);
		~Button();
		void select(const bool isSelected);
		void render();
	};
}
