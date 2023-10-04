#include "inputmanager.h"
#include "observer.h"

namespace Managers
{
	InputManager* InputManager::instance = 0;

	InputManager* InputManager::getInstance()
	{

		if (instance == nullptr)
		{
			InputManager::instance = new InputManager();

		}
		return instance;

	}

	InputManager::InputManager()
	{
        keyMap[sf::Keyboard::A] = "A";
        keyMap[sf::Keyboard::B] = "B";
        keyMap[sf::Keyboard::C] = "C";
        keyMap[sf::Keyboard::D] = "D";
        keyMap[sf::Keyboard::E] = "E";
        keyMap[sf::Keyboard::F] = "F";
        keyMap[sf::Keyboard::G] = "G";
        keyMap[sf::Keyboard::H] = "H";
        keyMap[sf::Keyboard::I] = "I";
        keyMap[sf::Keyboard::J] = "J";
        keyMap[sf::Keyboard::K] = "K";
        keyMap[sf::Keyboard::L] = "L";
        keyMap[sf::Keyboard::M] = "M";
        keyMap[sf::Keyboard::N] = "N";
        keyMap[sf::Keyboard::O] = "O";
        keyMap[sf::Keyboard::P] = "P";
        keyMap[sf::Keyboard::Q] = "Q";
        keyMap[sf::Keyboard::R] = "R";
        keyMap[sf::Keyboard::S] = "S";
        keyMap[sf::Keyboard::T] = "T";
        keyMap[sf::Keyboard::U] = "U";
        keyMap[sf::Keyboard::V] = "V";
        keyMap[sf::Keyboard::W] = "W";
        keyMap[sf::Keyboard::X] = "X";
        keyMap[sf::Keyboard::Y] = "Y";
        keyMap[sf::Keyboard::Z] = "Z";
        keyMap[sf::Keyboard::Num1] = "1";
        keyMap[sf::Keyboard::Num2] = "2";
        keyMap[sf::Keyboard::Num3] = "3";
        keyMap[sf::Keyboard::Num4] = "4";
        keyMap[sf::Keyboard::Num5] = "5";
        keyMap[sf::Keyboard::Num6] = "6";
        keyMap[sf::Keyboard::Num7] = "7";
        keyMap[sf::Keyboard::Num8] = "8";
        keyMap[sf::Keyboard::Num9] = "9";
        keyMap[sf::Keyboard::Num0] = "0";
        keyMap[sf::Keyboard::Numpad0] = "0";
        keyMap[sf::Keyboard::Numpad1] = "1";
        keyMap[sf::Keyboard::Numpad2] = "2";
        keyMap[sf::Keyboard::Numpad3] = "3";
        keyMap[sf::Keyboard::Numpad4] = "4";
        keyMap[sf::Keyboard::Numpad5] = "5";
        keyMap[sf::Keyboard::Numpad6] = "6";
        keyMap[sf::Keyboard::Numpad7] = "7";
        keyMap[sf::Keyboard::Numpad8] = "8";
        keyMap[sf::Keyboard::Numpad9] = "9";
        keyMap[sf::Keyboard::Space] = "Space";
        keyMap[sf::Keyboard::Enter] = "Enter";
        keyMap[sf::Keyboard::Escape] = "Escape";
        keyMap[sf::Keyboard::BackSpace] = "BackSpace";
        keyMap[sf::Keyboard::Right] = "Right";
        keyMap[sf::Keyboard::Left] = "Left";
        keyMap[sf::Keyboard::Up] = "Up";
        keyMap[sf::Keyboard::Down] = "Down";
        keyMap[sf::Keyboard::LControl] = "Control";
        keyMap[sf::Keyboard::LShift] = "Shift";
        keyMap[sf::Keyboard::RControl] = "RControl";
        keyMap[sf::Keyboard::RShift] = "RShift";
        keyMap[sf::Keyboard::Hyphen] = "-";
        keyMap[sf::Keyboard::Tab] = "Tab";

	}

    InputManager::~InputManager()
    {
        objectObserving.clear();
        keyMap.clear();

    }

    void InputManager::attach(Control::Observer* pObserver)
    {
        objectObserving.push_back(pObserver);

    }

    void InputManager::detach(Control::Observer* pObserver)
    {
        objectObserving.remove(pObserver);

    }

    void InputManager::handleKeyPressed(sf::Keyboard::Key key)
    {
        for (i = objectObserving.begin(); i != objectObserving.end(); i++)
        {
            (*i)->notifyPressed(getKeyAsString(key));

        }
    }

    void InputManager::handleKeyReleased(sf::Keyboard::Key key)
    {
        for (i = objectObserving.begin(); i != objectObserving.end(); i++)
        {
            (*i)->notifyReleased(getKeyAsString(key));

        }
    }

    std::string InputManager::getKeyAsString(sf::Keyboard::Key key)
    {
        return keyMap[key] == "" ? "unknown" : keyMap[key];

    }


}