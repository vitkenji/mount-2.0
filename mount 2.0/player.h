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
			bool canJump;
			bool isAttacking;

		public:
			Player(Math::CoordinateF position);
			~Player();
			void setCoins(int coins);
			int getCoins();
			void setPoints(int points);
			int getPoints();
			void attack();
			void walk(bool right);
			void jump();
			void sprint();

		    void initialize();
			void update(const float dt);
		    void collide(Entity* other, Math::CoordinateF intersection);
			void updateSprite(const float dt);

		};
	}
}