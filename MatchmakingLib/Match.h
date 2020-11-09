#pragma once
#include <string>
#include <vector>
#include "Player.h"

namespace tw
{
	enum MatchStatus
	{
		NOT_STARTED,
		STARTED,
		FINISHED
	};

	class Match
	{
	private:
		std::string name;
		std::vector<Player*> team1;
		//Player * team1PlayerTakeInit;
		std::vector<Player*> team2;
		//Player * team2PlayerTakeInit;

		MatchStatus status;
		int winnerTeam;

		void * battlePayload;

		bool playerIsInTeam(Player * p, std::vector<Player*> & team)
		{
			return std::find(team.begin(), team.end(), p) != team.end();
		}


	public:
		Match(std::string name)
		{
			this->name = name;
			status = MatchStatus::NOT_STARTED;
			winnerTeam = 0;
			battlePayload = NULL;
		}

		void setTeam1Players(Player * p1, Player * p2)
		{
			team1.clear();
			team1.push_back(p1);
			team1.push_back(p2);
		}

		void setTeam2Players(Player * p1, Player * p2)
		{
			team2.clear();
			team2.push_back(p1);
			team2.push_back(p2);
		}


		std::vector<Player*> & getTeam1() {
			return team1;
		}

		std::vector<Player*> & getTeam2() {
			return team2;
		}

		

		bool playerIsInTeam1(Player * p)
		{
			return playerIsInTeam(p, team1);
		}

		bool playerIsInTeam2(Player * p)
		{
			return playerIsInTeam(p, team2);
		}

		bool playerIsInThisMatch(Player * p)
		{
			return playerIsInTeam1(p) || playerIsInTeam2(p);
		}

		MatchStatus getStatus()
		{
			return status;
		}

		std::vector<Player*> * getWinnerTeam()
		{
			if (status == MatchStatus::FINISHED)
			{
				if (winnerTeam == 1)
				{
					return &team1;
				}
				else
				{
					return &team2;
				}
			}

			return NULL;
		}

		void * getBattlePayload()
		{
			return battlePayload;
		}

		void setBattlePayload(void * obj)
		{
			battlePayload = obj;
		}
	};
}