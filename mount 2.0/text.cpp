#include "text.h"

namespace GraphicalElements
{
	Managers::GraphicManager* Text::pGraphic = Managers::GraphicManager::getInstance();

	Text::Text(Math::CoordinateF position, std::string info, const char* path) : info(info)
	{
		text.setString(info);
		text.setPosition(sf::Vector2f(position.x, position.y));
		text.setFont(*pGraphic->loadFont(path));
		text.setCharacterSize(TEXT_SIZE);
		setTextAlignment(Text_Alignment::left);
		text.setFillColor(sf::Color::White);

	}

	Text::~Text(){}

	void Text::setTextInfo(std::string info)
	{
		this->info = info;
		text.setString(this->info);

	}

	void Text::setPosition(Math::CoordinateF position)
	{
		text.setPosition(sf::Vector2f(position.x, position.y));

	}

	void Text::setTextAlignment(Text_Alignment option)
	{
		if (option == left)
		{
			text.setOrigin(0, 0);

		}

		else if (option == center)
		{
			text.setOrigin(getSize().x /2, getSize().y);

		}

		else if (option == right)
		{
			text.setOrigin(getSize().x, getSize().y);

		}

	}

	void Text::setTextColor(int r, int g, int b)
	{
		text.setFillColor(sf::Color(r, g, b));

	}

	void Text::setFontSize(const unsigned int size)
	{
		text.setCharacterSize(size);
	
	}

	Math::CoordinateF Text::getSize()
	{
		sf::FloatRect textRect = text.getLocalBounds();
		return Math::CoordinateF(textRect.width, textRect.height);

	}

	Math::CoordinateF Text::getPosition()
	{
		return Math::CoordinateF(text.getPosition().x, text.getPosition().y);

	}

	std::string Text::getInfo()
	{
		return info;

	}

	void Text::render()
	{
		pGraphic->render(&text);
	}

}