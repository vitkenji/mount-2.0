#pragma once
#include "std.h"

namespace Control
{
	class Observer;

}

namespace Managers
{
	class InputManager
	{
	private:
		std::list<Control::Observer*> objectObserving;
		std::list<Control::Observer*>::iterator i;
		std::map<sf::Keyboard::Key, std::string> keyMap;

		InputManager();
		static Managers::InputManager* instance;

	public:
		~InputManager();
		static InputManager* getInstance();
		void attach(Control::Observer* pObserver);
		void detach(Control::Observer* pObserver);
		void handleKeyPressed(sf::Keyboard::Key key);
		void handleKeyReleased(sf::Keyboard::Key key);
		std::string getKeyAsString(sf::Keyboard::Key key);
			
	};
}