#include "pch.h"
#include "PlayerManager.h"

tw::Match * tw::PlayerManager::testMatch = NULL;

std::vector<tw::Player*> tw::PlayerManager::loadPlayers()
{
	std::vector<tw::Player*> result;

	// Vous devrez remplacer les données de test par des 
	// données chargées depuis un fichier.

	result.push_back(new Player("J1", "P1", 1));
	result.push_back(new Player("J2", "P2", 1));
	result.push_back(new Player("J3", "P3", 2));
	result.push_back(new Player("J4", "P4", 2));

	return result;
}

tw::Match * tw::PlayerManager::getCurrentOrNextMatchForPlayer(tw::Player * p)
{
	if (testMatch == NULL)
	{
		testMatch = new tw::Match("Tour 1 - Eq 1 VS Eq 2");
		std::vector<tw::Player*> players = loadPlayers();
		testMatch->setTeam1Players(players[0], players[1]);
		testMatch->setTeam2Players(players[2], players[3]);
	}

	// TODO : Rechercher le match courant ou le prochain pour le joueur p 
	// et le retourner. Si aucun match à venir, retourner NULL.

	if (testMatch->getStatus() != FINISHED)
	{
		return testMatch;
	}

	return NULL;
}