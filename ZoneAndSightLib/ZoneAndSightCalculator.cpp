#include "pch.h"
#include "ZoneAndSightCalculator.h"
#include <iostream>

using namespace tw;

ZoneAndSightCalculator * ZoneAndSightCalculator::instance = NULL;

ZoneAndSightCalculator::ZoneAndSightCalculator()
{
}


ZoneAndSightCalculator::~ZoneAndSightCalculator()
{
}

ZoneAndSightCalculator * ZoneAndSightCalculator::getInstance()
{
	if (instance == NULL)
		instance = new ZoneAndSightCalculator();

	return instance;
}


std::vector<Point2D> ZoneAndSightCalculator::generateZone(int x, int y, int minPO, int maxPO, TypeZoneLaunch type)
{
	std::vector<Point2D> targettableCells;


	return targettableCells;
}

std::vector<Point2D> processLineOfSight(int launcherX, int launcherY, std::vector<Point2D> cellsToTest, std::vector<Obstacle*> obstacles)
{
	std::vector<Point2D> targettableCells;


	return targettableCells;
}