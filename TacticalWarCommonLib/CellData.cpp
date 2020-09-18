#include "pch.h"
#include "CellData.h"

using namespace tw;

CellData::CellData(int x, int y, bool isWalkable, bool isObstacle)
	: 
	Point2D(x, y)
{
	this->isWalkable = isWalkable;
	this->isObstacle = isObstacle;
}