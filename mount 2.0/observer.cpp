#include "observer.h"
#include "inputmanager.h"

namespace Control
{
	Observer::Observer()
	{
		this->pInput = pInput->getInstance();
		pInput->attach(this);

	}

	Observer::~Observer()
	{
		pInput->detach(this);

	}


}