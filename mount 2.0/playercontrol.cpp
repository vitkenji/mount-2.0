#include "playercontrol.h"

namespace Control
{
	PlayerControl::PlayerControl(Entities::Characters::Player* pPlayer): pPlayer(pPlayer)
	{
		jump = "W"; right = "D"; left = "A"; attack = "Space"; sprint = "Shift";
		keysPressed.insert(std::pair<std::string, bool>(jump,false));
		keysPressed.insert(std::pair<std::string, bool>(right, false));
		keysPressed.insert(std::pair<std::string, bool>(left, false));
		keysPressed.insert(std::pair<std::string, bool>(attack, false));
		keysPressed.insert(std::pair<std::string, bool>(sprint, false));

	}

	PlayerControl::~PlayerControl()
	{
		pPlayer = nullptr;

	}

	void PlayerControl::notifyPressed(std::string key)
	{
		keysPressed[key] == true;

		if (key == "Space") { pPlayer->attack(); }
		else if (key == "W") { pPlayer->jump(); }
		else if (key == "D") { pPlayer->walk(false); pPlayer->setFacingLeft(true); }
		else if (key == "A") { pPlayer->walk(true); pPlayer->setFacingLeft(false); }
		else if (key == "Shift") { pPlayer->sprint(); }
	

	}

	void PlayerControl::notifyReleased(std::string key)
	{
		keysPressed[key] = false;
		if (key == "Space") { pPlayer->setIsAttacking(false); }
		else if (key == "W") { pPlayer->jump(); }
		else if (key == "D") { pPlayer->setIsWalking(false); }
		else if (key == "A") { pPlayer->setIsWalking(false); }
		else if (key == "Shift") { pPlayer->setIsSprinting(false); }


	}

	void PlayerControl::setPlayer(Entities::Characters::Player* pPlayer)
	{
		this->pPlayer = pPlayer;

	}

	void PlayerControl::setKeys(std::string jump, std::string right, std::string left, std::string attack, std::string sprint)
	{
		this->jump = jump;
		this->attack = attack;
		this->right = right;
		this->left = left;
		this->sprint = sprint;

	}
}