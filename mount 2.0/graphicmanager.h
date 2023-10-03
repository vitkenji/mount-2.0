#pragma once
#include "std.h"

namespace Managers
{
	class GraphicManager //singleton
	{
	private:
		sf::RenderWindow* window;
		sf::View view;
		std::map<const char*, sf::Texture*> textureMap;
		std::map<const char*, sf::Font*> fontMap;
		static Managers::GraphicManager* instance;
		GraphicManager();

	public:
		~GraphicManager();
		static GraphicManager* getInstance();
		void render(sf::RectangleShape* body);
		void render(sf::Text* text);
		void display();
		void clear();
		bool isWindowOpen() const;
		void closeWindow();
		void setWindowSize(Math::CoordinateU size);
		Math::CoordinateU getWindowSize() const;
		Math::CoordinateF getTopLeftPosition() const;
		void centerView(Math::CoordinateF position);
		sf::Texture* loadTexture(const char* path);
		sf::Font* loadFont(const char* path);
		sf::RenderWindow* getWindow() const;

	};
}