#pragma once
#include "std.h"
#include "graphicmanager.h"

namespace GraphicalElements
{
	class SingleAnimation
	{
	private:
		const unsigned int imageCount;
		unsigned int currentImage;
		sf::Texture* texture;
		float totalTime;
		sf::IntRect rectangleSize;
		const float switchTime;

	public:
		SingleAnimation(const char* path, const unsigned int imageCount, const float switchTime);
		~SingleAnimation();
		void update(const float dt, bool facingLeft);
		void reset();
		sf::IntRect getSize() const;
		sf::Texture* getTexture() const;
	};
}