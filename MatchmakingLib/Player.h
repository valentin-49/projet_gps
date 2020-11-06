#pragma once
#include <string>

namespace tw
{
	class Player
	{
	private:
		std::string pseudo;
		std::string password;
		int teamId;

	public:
		Player(std::string pseudo, std::string password, int teamId);

		inline std::string getPseudo()
		{
			return pseudo;
		}

		inline std::string getPassword()
		{
			return password;
		}

		inline int getTeamId()
		{
			return teamId;
		}
	};
}