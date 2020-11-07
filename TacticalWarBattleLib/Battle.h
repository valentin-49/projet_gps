#pragma once

#include <vector>
#include <Player.h>

enum BattleState {
	WAITING_PLAYER_PHASE,
	PREPARATION_PHASE,
	BATTLE_PHASE
};

class Battle
{
	BattleState state;

	std::vector<tw::Player*> team1;
	std::vector<tw::Player*> team2;


	std::vector<tw::Player*> timeline;

public:
	
	Battle()
	{
		state = BattleState::WAITING_PLAYER_PHASE;
	}

	inline bool isPreparationPhase()
	{
		return state == BattleState::PREPARATION_PHASE;
	}
};

