#include "animation.h"

namespace GraphicalElements
{
	Managers::GraphicManager* Animation::pGraphic = Managers::GraphicManager::getInstance();
	Animation::Animation(): body(){}

	Animation::~Animation(){}

	void Animation::render()
	{
		pGraphic->render(&body);

	}
}