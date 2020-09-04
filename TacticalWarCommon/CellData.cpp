#include "CellData.h"

CellData::CellData(int x, int y, bool isWalkable, bool isObstacle)
{
	this->x = x;
	this->y = y;
	this->isWalkable = isWalkable;
	this->isObstacle = isObstacle;
}