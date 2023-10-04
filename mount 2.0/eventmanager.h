#pragma once
#include "std.h"
#include "inputmanager.h"
#include "graphicmanager.h"

namespace Managers
{
	class EventManager
	{
	private:
		
		GraphicManager* pGraphicManager;
		InputManager* pInputManager;
		sf::RenderWindow* pWindow;
		static Managers::EventManager* instance;
		EventManager();

	public:
		~EventManager();
		static EventManager* getInstance();
		void pollEvents();

	};
}
