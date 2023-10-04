#include "eventmanager.h"

namespace Managers
{
	EventManager* EventManager::instance = 0;
	
	EventManager* EventManager::getInstance()
	{
		if (instance == nullptr) { EventManager::instance = new EventManager(); }
		return instance;

	}

	EventManager::EventManager() : pGraphicManager(Managers::GraphicManager::getInstance()), pInputManager(Managers::InputManager::getInstance()),pWindow(nullptr)
	{
		EventManager::pWindow = pGraphicManager->getWindow();

	}

	EventManager::~EventManager()
	{
		pGraphicManager = nullptr;
		pInputManager = nullptr;
		pWindow = nullptr;

	}

	void EventManager::pollEvents()
	{
		sf::Event event;
		
		while (pWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) { pGraphicManager->closeWindow(); }
			else if (event.type == sf::Event::KeyPressed) { pInputManager->handleKeyPressed(event.key.code); }
			else if (event.type == sf::Event::KeyReleased) { pInputManager->handleKeyReleased(event.key.code); }
		}
	}
}