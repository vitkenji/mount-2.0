#pragma once
#include "std.h"
#include "graphicmanager.h"
#include "player.h"
#include "control.h"
#include "eventmanager.h"
#include "platform.h"
#include "skeleton.h"
#include "goblin.h"
#include "fire.h"
#include "entitylist.h"

namespace States
{
	class Game
	{
	private:
		Managers::GraphicManager* pGraphic;
		Managers::EventManager* pEvent;
		Control::PlayerControl* pControl;
		Entities::Characters::Player* player;
		Entities::Characters::Enemies::Skeleton* skeleton;
		Entities::Characters::Enemies::Goblin* goblin;
		Entities::Obstacles::Fire* fire;
		List::EntityList entitiesList;

	public:
		Game();
		~Game();
		void execute();
		
	};
}