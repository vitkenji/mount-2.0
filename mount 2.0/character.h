#pragma once
#include "movingentity.h"

namespace Entities
{
	namespace Characters
	{
		class Character : public MovingEntity
		{
		protected:
			int life;

		public:
			Character();
			~Character();

		};
	}
}