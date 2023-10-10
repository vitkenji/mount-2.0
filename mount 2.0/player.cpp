#include "player.h"

namespace Entities
{
	namespace Characters
	{
		Player::Player(Math::CoordinateF position) :
			Character(position, Math::CoordinateF(PLAYER_SIZE_X, PLAYER_SIZE_Y), player, Math::CoordinateF(0,0), 1000)
		{
			initialize();
			coins = 0;
			points = 0;
			body->setPosition(sf::Vector2f(position.x, position.y));
			body->setSize(sf::Vector2f(size.x, size.y));
			
		}

		Player::~Player(){}

		void Player::setCoins(int coins) 
		{
			this->coins = coins;

		}

		int Player::getCoins()
		{
			return this->coins;

		}

		void Player::setPoints(int points)
		{
			this->points = points;

		}

		int Player::getPoints()
		{
			return this->points;

		}

		void Player::attack()
		{
			isAttacking = true;

		}

		void Player::jump()
		{
			if (canJump)
			{
				canJump = false;

			}
		}

		void Player::walk(bool left)
		{
			setIsWalking(true);
			velocity.x = -80;
			if (!left)
			{
				velocity.x *= -1;
				setFacingLeft(false);

			}
		}

		void Player::sprint()
		{
			isSprinting = true;
			velocity.x *= 2;

		}


		void Player::setIsSprinting(bool flag)
		{
			this->isSprinting = flag;

		}

		bool Player::getIsSprinting()
		{
			return isSprinting;

		}

		void Player::update(const float dt) 
		{
			if (getIsWalking())
			{
				position.x += velocity.x * dt;
				if (getIsSprinting()) { position.x += 0.1 * velocity.x * dt; }

			}
			
			position.y += velocity.y + (GRAVITY * dt * dt / 2.0f);
			velocity.y += GRAVITY * dt;

			updateSprite(dt);
		
		
		}

		void Player::initialize()
		{
			sprite.addNewAnimation(GraphicalElements::Animation_ID::idle, PLAYER_IDLE_PATH, 8, 0.2);
			sprite.addNewAnimation(GraphicalElements::Animation_ID::run, PLAYER_RUN_PATH, 8, 0.2);
			sprite.addNewAnimation(GraphicalElements::Animation_ID::attack, PLAYER_ATTACK_PATH, 6, 0.2);
			sprite.addNewAnimation(GraphicalElements::Animation_ID::jump, PLAYER_JUMP_PATH, 2, 0.2);
			sprite.addNewAnimation(GraphicalElements::Animation_ID::takeHit, PLAYER_TAKEHIT_PATH, 4, 0.4);

		}
		
		void Player::collide(Entity* other, Math::CoordinateF intersection)
		{
			//std::cout << "collided " << other->getId() << std::endl;
			if (other->getId() == skeleton || other->getId() == goblin)
			{
				if (intersection.x <= 0)
				{
					this->velocity.x = 0;
					this->life -= 10;
				}

				if (intersection.y <= 0)
				{
					this->velocity.y = 0;
				}

			}
			if (other->getId() == platform)
			{
				velocity.y = 0;
			}

			else if (other->getId() == fire)
			{
				this->velocity.x = 0;
				this->life -= 10;
				std::cout << getLife() << std::endl;
			}

		}
		
		void Player::updateSprite(const float dt)
		{
			if (getIsWalking()){ sprite.update(GraphicalElements::Animation_ID::run, isFacingLeft(), position, dt); }
			
			if (isAttacking) { sprite.update(GraphicalElements::Animation_ID::attack, isFacingLeft(), position, dt); }

			else if(!getIsWalking()) { sprite.update(GraphicalElements::Animation_ID::idle, isFacingLeft(), position, dt); }

		}
	}
}