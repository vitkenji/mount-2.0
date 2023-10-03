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
			//body->setFillColor(sf::Color(12, 120, 12));
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

		void Player::walk(bool right)
		{
			isWalking = true;
			velocity.x = 0.20;
			if (!right){ velocity.x *= -1; }

		}

		void Player::sprint()
		{
			isSprinting = true;
			velocity.x *= 2;

		}

		void Player::update(const float dt) 
		{
			position.x += velocity.x * dt;
			sprite.update(GraphicalElements::Animation_ID::attack, false, position, dt);

		}

		void Player::initialize()
		{
			sprite.addNewAnimation(GraphicalElements::Animation_ID::idle, PLAYER_IDLE_PATH, 8, 0.2);
			sprite.addNewAnimation(GraphicalElements::Animation_ID::run, PLAYER_RUN_PATH, 8, 0.2);
			sprite.addNewAnimation(GraphicalElements::Animation_ID::attack, PLAYER_ATTACK_PATH, 6, 0.2);
			sprite.addNewAnimation(GraphicalElements::Animation_ID::jump, PLAYER_JUMP_PATH, 2, 0.2);
		}
		
		void Player::collide(Entity* other, Math::CoordinateF intersection){}
		
		void Player::updateSprite(const float dt){}
	}
}