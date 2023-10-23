#pragma once
#include "character.h"
#include "playercontrol.h"

namespace Entities
{
	namespace Characters
	{
		class Player : public Character
		{
		private:
			int coins;
			int points;
			bool isWalking;
			bool isSprinting;
			bool isJumping;
			bool canJump;

		public:
			Player(Math::CoordinateF position);
			~Player();
			void setCoins(int coins);
			int getCoins();
			void setPoints(int points);
			int getPoints();
			void attack();
			void jump();
			void sprint();
			void setIsSprinting(bool flag);
			bool getIsSprinting();

			void walk(bool left);
		    void initialize();
			void update(const float dt);
		    void collide(Entity* other, Math::CoordinateF intersection);
			void updateSprite(const float dt);

		};
	}
}