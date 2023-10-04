#pragma once
#include "std.h"
#include "observer.h"
#include "player.h"

namespace Entities {
	namespace Characters {
		class Player;

	}
}

namespace Control
{
	class PlayerControl : public Observer
	{
	private:
		Entities::Characters::Player* pPlayer;
		std::map<std::string, bool> keysPressed;
		std::string jump;
		std::string right;
		std::string left;
		std::string attack;
		std::string sprint;

	public:
		PlayerControl(Entities::Characters::Player* pPlayer);
		~PlayerControl();
		void notifyPressed(std::string key);
		void notifyReleased(std::string key);
		void setPlayer(Entities::Characters::Player* pPlayer);
		void setKeys(std::string jump, std::string right, std::string left, std::string attack, std::string sprint);

	};
}
