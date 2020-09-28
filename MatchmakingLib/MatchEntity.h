#pragma once
#include <string>

namespace tw
{

	class MatchEntity
	{
	private:
		std::string pseudo;

	public:
		MatchEntity(std::string pseudo)
		{
			this->pseudo = pseudo;
		}
	};

}