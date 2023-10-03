#include "multiframeanimation.h"

namespace GraphicalElements
{
	MultiFrameAnimation::MultiFrameAnimation() : animationMap(), currentID(Animation_ID::idle){}

	MultiFrameAnimation::~MultiFrameAnimation()
	{
		std::map<Animation_ID, SingleAnimation*>::iterator i;
		for (i = animationMap.begin(); i != animationMap.end(); i++)
		{
			delete i->second;
		}
		animationMap.clear();

	}

	void MultiFrameAnimation::addNewAnimation(Animation_ID id, const char* path, unsigned int imageCount, const float switchTime)
	{
		SingleAnimation* ptr = new SingleAnimation(path, imageCount, switchTime);

		if (ptr == nullptr)
		{
			std::cout << "error : singleanimation pointer is null" << std::endl;
			exit(1);

		}

		animationMap.insert(std::pair<Animation_ID, SingleAnimation*>(id, ptr));
		sf::IntRect rectangleSize = ptr->getSize();

		body.setSize(sf::Vector2f(rectangleSize.width, rectangleSize.height));
		body.setOrigin(sf::Vector2f(rectangleSize.width, rectangleSize.height) / 2.0f);

	}

	void MultiFrameAnimation::update(Animation_ID id, bool facingLeft, Math::CoordinateF position, const float dt)
	{
		if(currentID != id)
		{
			currentID = id;
			animationMap[currentID]->reset();

		}

		animationMap[currentID]->update(dt, facingLeft);
		body.setPosition(sf::Vector2f(position.x, position.y));
		body.setTextureRect(animationMap[currentID]->getSize());
		body.setTexture(animationMap[currentID]->getTexture());

	}
}