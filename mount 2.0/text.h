#pragma once
#include "std.h"
#include "graphicmanager.h"

namespace GraphicalElements
{
	enum Text_Alignment
	{
		left,
		center,
		right
	};

	class Text
	{
	private:
		std::string info;
		sf::Text text;
		static Managers::GraphicManager* pGraphic;

	public:
		Text(Math::CoordinateF position, std::string info, const char* path);
		~Text();
		void setTextInfo(std::string info);
		void setPosition(Math::CoordinateF position);
		void setTextColor(int r, int g, int b);
		void setFontSize(const unsigned int size);
		void setTextAlignment(Text_Alignment option);
		Math::CoordinateF getSize();
		void render();
		std::string getInfo();
		Math::CoordinateF getPosition();

	};
}