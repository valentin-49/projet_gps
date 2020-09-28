#pragma once
#include <string>
#include <vector>
#include "MatchEntity.h"

namespace tw
{
	class Match
	{
	private:
		std::string name;
		std::vector<MatchEntity*> team1;
		std::vector<MatchEntity*> team2;

	public:
		Match(std::string name)
		{
			this->name = name;
		}


		std::vector<MatchEntity*> & getTeam1() {
			return team1;
		}

		std::vector<MatchEntity*> & getTeam2() {
			return team2;
		}
	};
}