#pragma once

#include <vector>
#include <Player.h>
#include <Match.h>
#include <Environment.h>
#include <EnvironmentManager.h>

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

	tw::Environment * environment;

public:
	// Server side constructor :
	Battle(tw::Match * m)
	{
		std::vector<tw::Player*> & t1 = m->getTeam1();
		std::vector<tw::Player*> & t2 = m->getTeam2();

		for (int i = 0; i < t1.size(); i++)
		{
			team1.push_back(t1[i]);
		}

		for (int i = 0; i < t2.size(); i++)
		{
			team2.push_back(t2[i]);
		}

		environment = tw::EnvironmentManager::getInstance()->getRandomEnvironment();

		state = BattleState::WAITING_PLAYER_PHASE;
		
		m->setBattlePayload(this);
		m->setMatchStatus(tw::MatchStatus::STARTED);
	}

	inline bool isPreparationPhase()
	{
		return state == BattleState::PREPARATION_PHASE;
	}
};