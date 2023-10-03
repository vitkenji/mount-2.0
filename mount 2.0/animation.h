#pragma once
#include "std.h"
#include "graphicmanager.h"

namespace GraphicalElements
{
	class Animation
	{
	protected:
		sf::RectangleShape body;
		static Managers::GraphicManager* pGraphic;

	public:
		Animation();
		virtual ~Animation();
		virtual void render();

	};
}