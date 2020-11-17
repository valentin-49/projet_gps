#include <PlayerManager.h>
#include <iostream>

using namespace tw;

int main(int argc, char ** argv)
{
	std::vector<tw::Player*> players = PlayerManager::loadPlayers();

	for (int i = 0; i < players.size(); i++)
	{
		std::cout << players[i]->getPseudo() << std::endl;
	}

	return 0;
}