#pragma once
#include "std.h"
#include "inputmanager.h"

namespace Control
{
	class Observer
	{
	protected:
		Managers::InputManager* pInput;

	public:
		Observer();
		virtual ~Observer();
		virtual void notifyPressed(std::string key)= 0;
		virtual void notifyReleased(std::string key) = 0;


	};
}