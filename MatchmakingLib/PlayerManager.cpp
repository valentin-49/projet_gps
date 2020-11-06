#include "pch.h"
#include "PlayerManager.h"

std::vector<tw::Player*> tw::PlayerManager::loadPlayer()
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