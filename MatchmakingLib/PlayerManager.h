#pragma once

#include "Player.h"
#include <vector>

namespace tw
{
	class PlayerManager
	{
	public:
		static std::vector<Player*> loadPlayer();
	};
}
