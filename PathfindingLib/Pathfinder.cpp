#include "pch.h"
#include "Pathfinder.h"
#include <cstdlib>


using namespace tw;

Pathfinder * Pathfinder::instance = NULL;

Pathfinder * Pathfinder::getInstance()
{
	if (instance == NULL)
		instance = new Pathfinder();

	return instance;
}

Pathfinder::Pathfinder()
{
}


Pathfinder::~Pathfinder()
{
}


Orientation Pathfinder::getOrientationFromPosition(Position p1, Position p2)
{
	// TODO : Implémenter le calcul de l'orientation du personnage à partir des positions passées en paramètres.
	// Les positions passées en paramètre représentent le mouvement du personnage de p1 vers p2.
	// A partir de ces deux positions, vous devez déterminer l'orientation résultante du mouvement.
	return Orientation::BOTTOM_RIGHT;
}

std::vector<Position> getPath(Position startPosition, Position endPosition, Environment * environment, std::vector<Obstacle*> obstacles)
{
	std::vector<Position> path;

	// TODO : Implémenter un algorithme de recherche de plus court chemin entre startPosition et endPosition
	// qui tient compte de la topologie de l'environnement (environment : case "non marchable"; obstacles, etc...)
	// et des obstacles "dynamique" (les personnages, etc...)
	// Vous représenterez le résultat de votre calcul sous forme d'une liste de position 
	// s'enchainant de la position de départ à la position d'arrivée.

	return path;
}