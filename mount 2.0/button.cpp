#include "button.h"

namespace GraphicalElements
{
	Button::Button(Math::CoordinateF position, std::string info) : Animation(), defaultTexture(nullptr), selectedTexture(nullptr), text(position, info, FONT_PATH)
	{
		defaultTexture = pGraphic->loadTexture(DEFAULT_BUTTON_PATH);
		selectedTexture = pGraphic->loadTexture(SELECTED_BUTTON_PATH);

		body.setSize(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
		body.setPosition(sf::Vector2f(position.x, position.y));
		body.setOrigin(sf::Vector2f(BUTTON_WIDTH/2, BUTTON_HEIGHT / 2));
		body.setTexture(defaultTexture);
		text.setFontSize(FONT_SIZE);
		text.setTextAlignment(Text_Alignment::center);
		text.setTextColor(BUTTON_TEXT_COLOR);

	}

	Button::~Button()
	{
		defaultTexture = nullptr;
		selectedTexture = nullptr;

	}

	void Button::select(const bool isSelected)
	{
		if (isSelected)
		{
			body.setTexture(selectedTexture);

		}
		else
		{
			body.setTexture(defaultTexture);
		}
	}

	void Button::render()
	{
		pGraphic->render(&body);
		text.render();
	}
}