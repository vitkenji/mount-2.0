#pragma once
#include "std.h"
#include "character.h"

namespace Entities
{
	namespace Characters
	{
		class Player;

		namespace Enemies
		{
			class Enemy : public Character
			{
			protected:
				Player* pPlayer;

			public:
				Enemy(Math::CoordinateF position, Math::CoordinateF size, ID id, Math::CoordinateF velocity, int life);
				~Enemy();
				void setPlayer(Player* pPlayer);
				
				virtual void initialize() = 0;
				virtual void update(const float dt) = 0;
				virtual void collide(Entity* other, Math::CoordinateF intersection);
				virtual void updateSprite(const float dt) = 0;

			};
		}
	}
}
