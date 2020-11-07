#pragma once

#include "Player.h"
#include <vector>
#include "Match.h"

namespace tw
{
	class PlayerManager
	{
		static Match * testMatch;
	public:
		static std::vector<Player*> loadPlayers();
		static Match * getCurrentOrNextMatchForPlayer(Player * p);
	};
}
