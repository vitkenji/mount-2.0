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
#include "singleframeanimation.h"
#include "collisionmanager.h"

namespace States
{
	class Game
	{
	private:
		Managers::GraphicManager* pGraphic;
		Managers::EventManager* pEvent;
		Managers::CollisionManager CollisionManager;
		List::EntityList movingEntitiesList;
		List::EntityList staticEntitiesList;

		Control::PlayerControl* pControl;
		Entities::Characters::Player* player;
		Entities::Characters::Enemies::Skeleton* skeleton;
		Entities::Characters::Enemies::Goblin* goblin;
		Entities::Obstacles::Fire* fire;
		GraphicalElements::SingleFrameAnimation background;
		
	public:
		Game();
		~Game();
		void execute();
		
	};
}